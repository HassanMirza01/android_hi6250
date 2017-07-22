/**
    @copyright: Huawei Technologies Co., Ltd. 2016-xxxx. All rights reserved.

    @file: bfmr_common.c

    @brief: define the common interface for BFMR (Boot Fail Monitor and Recovery)

    @version: 2.0

    @author: QiDechun ID: 216641

    @date: 2016-08-17

    @history:
*/

/*----includes-----------------------------------------------------------------------*/

#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/fs.h>
#include <linux/time.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <linux/rtc.h>
#include <linux/statfs.h>
#include <chipset_common/bfmr/public/bfmr_public.h>
#include <chipset_common/bfmr/common/bfmr_common.h>


/*----local macroes------------------------------------------------------------------*/

#define BFMR_CRC32_TABLE_ELEMENT_COUNT (256)
#define BFMR_CRC32_MULTINOMIAL_VALUE (0xedb88320)
#define BFM_PROC_MOUNTS_PATH "/proc/mounts"
#define BFM_RW_FLAGS "rw,"


/*----local prototypes----------------------------------------------------------------*/


/*----local variables-----------------------------------------------------------------*/

static unsigned int s_crc32_table[BFMR_CRC32_TABLE_ELEMENT_COUNT] = {0};
static int s_crc32_table_created = 0;


/*----global variables-----------------------------------------------------------------*/


/*----global function prototypes--------------------------------------------------------*/


/*----local function prototypes---------------------------------------------------------*/


/*----function definitions--------------------------------------------------------------*/

void bfmr_create_crc32_table(void)
{
    int i = 0;
    unsigned int value = 0;

    for (i = 0; i < BFMR_CRC32_TABLE_ELEMENT_COUNT; i++)
    {
        int j = 0;

        value = i;
        for (j = 0; j < 8; j++)
        {
            if (value & 1)
            {
                value = (value >> 1) ^ BFMR_CRC32_MULTINOMIAL_VALUE;
            }
            else
            {
                value >>= 1;
            }
        }

        s_crc32_table[i] = value;
    }
}


unsigned int bfmr_get_crc32(unsigned char *pbuf, unsigned int data_len)
{
    unsigned int crc32 = 0UL;
    unsigned int i = 0UL;

    if (NULL == pbuf)
    {
        return (unsigned int)0xFFFFFFFF;
    }

    if (0 == s_crc32_table_created)
    {
        bfmr_create_crc32_table();
        s_crc32_table_created = 1;
    }

    crc32 = (unsigned int)0xFFFFFFFF;
    for (i = 0; i < data_len; i++)
    {
        crc32 = (crc32 >> 8) ^ s_crc32_table[(crc32 & 0xFF) ^ pbuf[i]];
    }

    return crc32 ^= (unsigned int)0xFFFFFFFF;
}


void bfmr_change_own_mode(char *path, int uid, int gid, int mode)
{
    mm_segment_t old_fs;
    int ret = -1;

    if (unlikely(NULL == path))
    {
        BFMR_PRINT_INVALID_PARAMS("path: %p\n", path);
        return;
    }

    old_fs = get_fs();
    set_fs(KERNEL_DS);

    ret = sys_chown(path, uid, gid);
    if (0 != ret)
    {
        BFMR_PRINT_ERR("sys_chown [%s] failed, ret: %d\n", path, ret);
        goto __out;
    }

    ret = sys_chmod(path, mode);
    if (0 != ret)
    {
        BFMR_PRINT_ERR("sys_chmod [%s] failed, ret: %d\n", path, ret);
        goto __out;
    }

__out:
    set_fs(old_fs);
}


int bfmr_read_emmc_raw_part(const char *dev_path,
    unsigned long long offset,
    char *buf,
    unsigned long long buf_size)
{
    int fd = -1;
    int ret = -1;
    long bytes_read = 0L;
    long seek_result = 0L;
    mm_segment_t fs = 0;

    if (unlikely(NULL == dev_path) || unlikely(NULL == buf))
    {
        BFMR_PRINT_INVALID_PARAMS("dev_path:%p, buf: %p\n", dev_path, buf);
        return -1;
    }

    fs = get_fs();
    set_fs(KERNEL_DS);

    /* 1. open file for reading */
    fd = sys_open(dev_path, O_RDONLY, 0);
    if (fd < 0)
    {
        BFMR_PRINT_ERR("Open file [%s] failed!\n", dev_path);
        goto __out;
    }

    /* 2. seek file to the valid position */
    seek_result = sys_lseek(fd, (off_t)offset, SEEK_SET);
    if ((off_t)offset != seek_result)
    {
        BFMR_PRINT_ERR("lseek file [%s] failed! seek_result: %ld it should be: %ld\n",
            dev_path, (long)seek_result, (long)offset);
        goto __out;
    }

    /* 3. read data from file */
    bytes_read = sys_read(fd, buf, buf_size);
    if ((long long)buf_size != bytes_read)
    {
        BFMR_PRINT_ERR("read file [%s] failed!bytes_read: %ld, it should be: %lld]\n",
            dev_path, bytes_read, (long long)buf_size);
        goto __out;
    }

    /* 4. read successfully, modify the value of ret */
    ret = 0;

__out:
    if (fd > 0)
    {
        sys_close(fd);
    }

    set_fs(fs);

    return ret;
}


int bfmr_write_emmc_raw_part(const char *dev_path,
    unsigned long long offset,
    char *buf,
    unsigned long long buf_size)
{
    int fd = -1;
    int ret = -1;
    off_t seek_result = (off_t)0;
    long bytes_written = 0L;
    mm_segment_t fs = 0;

    if (unlikely(NULL == dev_path) || unlikely(NULL == buf))
    {
        BFMR_PRINT_INVALID_PARAMS("dev_path: %p buf: %p\n", dev_path, buf);
        return -1;
    }

    fs = get_fs();
    set_fs(KERNEL_DS);

    /* 1. open file for writing */
    fd = sys_open(dev_path, O_WRONLY, 0);
    if (fd < 0)
    {
        BFMR_PRINT_ERR("Open file [%s] failed!fd: %d\n", dev_path, fd);
        goto __out;
    }

    /* 2. seek file to the valid position */
    seek_result = sys_lseek(fd, (off_t)offset, SEEK_SET);
    if ((off_t)offset != seek_result)
    {
        BFMR_PRINT_ERR("lseek file [%s] offset failed!seek_result: %ld, it should be: %ld\n",
            dev_path, (long)seek_result, (long)offset);
        goto __out;
    }

    /* 3. write data to file */
    bytes_written = sys_write(fd, buf, buf_size);
    if ((long)buf_size != bytes_written)
    {
        BFMR_PRINT_ERR("write file [%s] failed!bytes_written: %ld, it shoule be: %ld\n",
            dev_path, (long)bytes_written, (long)buf_size);
        goto __out;
    }

    /* 4. write successfully, modify the value of ret */
    ret = 0;

__out:
    if (fd > 0)
    {
        sys_fsync(fd);
        sys_close(fd);
    }

    set_fs(fs);

    return ret;
}


bool bfmr_is_file_existed(char *pfile_path)
{
    mm_segment_t old_fs;
    struct stat st;
    int ret = -1;

    if (unlikely(NULL == pfile_path))
    {
        BFMR_PRINT_INVALID_PARAMS("pfile_path: %p\n", pfile_path);
        return false;
    }

    old_fs = get_fs();
    set_fs(KERNEL_DS);
    ret = sys_newlstat(pfile_path, &st);
    set_fs(old_fs);

    return (0 == ret) ? (true) : (false);
}


bool bfmr_is_dir_existed(char *pdir_path)
{
    return bfmr_is_file_existed(pdir_path);
}


int bfmr_save_log(char *logpath, char *filename, void *buf, unsigned int len, unsigned int is_append)
{
    int ret = -1;
    int fd = -1;
    int flags = 0;
    mm_segment_t old_fs;
    char *path = NULL;
    long bytes_write = 0L;

    BFMR_PRINT_ENTER();
    if (logpath == NULL || filename == NULL || buf == NULL || len <= 0)
    {
        BFMR_PRINT_INVALID_PARAMS("logpath:%p, filename:%p buf:%p len:%u\n",
            logpath, filename, buf, len);
        return -1;
    }

    old_fs = get_fs();
    set_fs(KERNEL_DS);

    path = (char *)bfmr_malloc(BFMR_TEMP_BUF_LEN);
    if (NULL == path)
    {
        BFMR_PRINT_ERR("bfmr_malloc failed!\n");
        goto __out;
    }
    memset(path, 0, BFMR_TEMP_BUF_LEN);
    snprintf(path, BFMR_TEMP_BUF_LEN - 1, "%s/%s", logpath, filename);
    flags = O_CREAT | O_WRONLY | (is_append ? O_APPEND : O_TRUNC);

    /* 1. open file for writing */
    fd = sys_open(path, flags, BFMR_FILE_LIMIT);
    if (fd < 0)
    {
        BFMR_PRINT_ERR("Open file [%s] failed!fd: %d\n", path, fd);
        goto __out;
    }

    /* 2. seek file to the valid position */
    sys_lseek(fd, 0, (0 != is_append) ? SEEK_END : SEEK_SET);

    /* 3. write data to file */
    bytes_write = sys_write(fd, buf, len);
    if ((long)len != bytes_write)
    {
        BFMR_PRINT_ERR("write file [%s] failed!bytes_write: %ld, it shoule be: %ld\n",
            path, (long)bytes_write, (long)len);
        goto __out;
    }

    /* 4. write successfully, modify the value of ret */
    ret = 0;

__out:

    if (fd >= 0)
    {
        sys_sync();
        sys_close(fd);
    }

    set_fs(old_fs);

    bfmr_change_own_mode(path, BFMR_AID_ROOT, BFMR_AID_SYSTEM, BFMR_FILE_LIMIT);

    if (NULL != path)
    {
        bfmr_free(path);
    }

    BFMR_PRINT_EXIT();

    return ret;
}


long bfmr_get_proc_file_length(const char *pfile_path)
{
    char c;
    mm_segment_t old_fs;
    int fd = -1;
    long file_size = 0;

    if (unlikely(NULL == pfile_path))
    {
        BFMR_PRINT_INVALID_PARAMS("pfile_path: %p\n", pfile_path);
        return 0;
    }

    old_fs = get_fs();
    set_fs(KERNEL_DS);

    fd = sys_open(pfile_path, O_RDONLY, 0);
    if (fd < 0)
    {
        goto __out;
    }

    while (0 != sys_read(fd, (char *)&c, sizeof(char)))
    {
        file_size++;
    }

__out:
    if (fd > 0)
    {
        sys_close(fd);
    }

    set_fs(old_fs);

    return file_size;
}


bool bfmr_is_part_mounted_rw(const char *pmount_point)
{
    mm_segment_t old_fs;
    int fd = -1;
    char *data_buf = NULL;
    char *log_part_mount_info = NULL;
    char *pstart = NULL;
    char *pend = NULL;
    bool part_mounted_rw = false;
    long file_size = 0;
    long bytes_read = 0;
    long log_part_mount_info_len = 0L;

    if (unlikely(NULL == pmount_point))
    {
        BFMR_PRINT_INVALID_PARAMS("pmount_point: %p\n", pmount_point);
        return false;
    }

    old_fs = get_fs();
    set_fs(KERNEL_DS);

    /* 1. get file length */
    file_size = bfmr_get_proc_file_length(BFM_PROC_MOUNTS_PATH);
    if (file_size <= 0)
    {
        goto __out;
    }

    /* 2. open file for read */
    fd = sys_open(BFM_PROC_MOUNTS_PATH, O_RDONLY, 0);
    if (fd < 0)
    {
        goto __out;
    }

    data_buf = (char *)bfmr_malloc(file_size + 1);
    if (NULL == data_buf)
    {
        BFMR_PRINT_ERR("bfmr_malloc failed!\n");
        goto __out;
    }
    memset(data_buf, 0, file_size + 1);

    log_part_mount_info = (char *)bfmr_malloc(BFMR_MAX_PATH + 1);
    if (NULL == log_part_mount_info)
    {
        BFMR_PRINT_ERR("bfmr_malloc failed!\n");
        goto __out;
    }
    memset(log_part_mount_info, 0, BFMR_MAX_PATH + 1);

    bytes_read = sys_read(fd, data_buf, file_size);
    if (bytes_read != file_size)
    {
        BFMR_PRINT_ERR("read [%s] failed, bytes read: %ld it should be: %ld\n",
            BFM_PROC_MOUNTS_PATH, bytes_read, file_size);
        goto __out;
    }

    pstart = strstr(data_buf, pmount_point);
    if (NULL == pstart)
    {
        goto __out;
    }

    pend = strstr(pstart, "\n");
    if (NULL != pend)
    {
        log_part_mount_info_len = pend - pstart + 1;
        memcpy((void *)log_part_mount_info, (void *)pstart, (log_part_mount_info_len >= BFMR_MAX_PATH)
            ? (BFMR_MAX_PATH) : (log_part_mount_info_len));
        pstart = log_part_mount_info;
    }

    pend = strstr(pstart, BFM_RW_FLAGS);
    if (NULL != pend)
    {
        part_mounted_rw = true;
    }
    else
    {
        part_mounted_rw = false;
    }

__out:
    if (fd > 0)
    {
        sys_close(fd);
    }

    if (NULL != data_buf)
    {
        bfmr_free(data_buf);
    }

    if (NULL != log_part_mount_info)
    {
        bfmr_free(log_part_mount_info);
    }

    set_fs(old_fs);

    return part_mounted_rw;
}


long bfmr_get_file_length(const char *pfile_path)
{
    mm_segment_t old_fs;
    struct stat st;
    int ret = -1;

    if (unlikely(NULL == pfile_path))
    {
        BFMR_PRINT_INVALID_PARAMS("pfile_path: %p\n", pfile_path);
        return 0L;
    }

    old_fs = get_fs();
    set_fs(KERNEL_DS);
    memset((void *)&st, 0, sizeof(st));
    ret = sys_newlstat(pfile_path, &st);
    if (0 != ret)
    {
        BFMR_PRINT_ERR("sys_newlstat [%s] failed![ret = %d]\n", pfile_path, ret);
        set_fs(old_fs);
        return 0L;
    }

    set_fs(old_fs);

    return (long)st.st_size;
}


long long bfmr_get_fs_available_space(const char *pmount_point)
{
    int ret = -1;
    struct statfs statfs_buf;
    long long bytes_avail = 0LL;
    mm_segment_t old_fs;

    if (unlikely(NULL == pmount_point))
    {
        BFMR_PRINT_INVALID_PARAMS("pmount_point: %p\n", pmount_point);
        return 0LL;
    }

    old_fs = get_fs();
    set_fs(KERNEL_DS);

    memset((void *)&statfs_buf, 0, sizeof(statfs_buf));
    ret = sys_statfs(pmount_point, &statfs_buf);
    if (0 != ret)
    {
        BFMR_PRINT_ERR("sys_statfs [%s] failed!\n", pmount_point);
        goto __out;
    }

    bytes_avail = (long long)statfs_buf.f_bavail * (long long)statfs_buf.f_bsize;

__out:
    set_fs(old_fs);

    return bytes_avail;
}


int bfmr_wait_for_part_mount_without_timeout(const char *pmount_point)
{
    bool part_mounted_rw = false;

    if (unlikely(NULL == pmount_point))
    {
        BFMR_PRINT_INVALID_PARAMS("pmount_point:%p\n", pmount_point);
        return -1;
    }

    part_mounted_rw = bfmr_is_part_mounted_rw(pmount_point);
    if (part_mounted_rw)
    {
        BFMR_PRINT_KEY_INFO("Line: %d [%s] has been mounted rw!\n", __LINE__, pmount_point);
    }
    else
    {
        BFMR_PRINT_KEY_INFO("Line: %d [%s] has not been mounted rw!\n", __LINE__, pmount_point);
    }

    return (part_mounted_rw) ? (0) : (-1);
}


int bfmr_wait_for_part_mount_with_timeout(const char *pmount_point, int timeouts)
{
    bool part_mounted_rw = false;

    if (unlikely(NULL == pmount_point))
    {
        BFMR_PRINT_INVALID_PARAMS("pmount_point: %p\n", pmount_point);
        return -1;
    }

    while (timeouts > 0)
    {
        part_mounted_rw = bfmr_is_part_mounted_rw(pmount_point);
        if (part_mounted_rw)
        {
            BFMR_PRINT_ERR("Line: %d [%s] has been mounted rw!\n", __LINE__, pmount_point);
            break;
        }

        current->state = TASK_INTERRUPTIBLE;
        (void)schedule_timeout(HZ); /*wait for 1 second */
        timeouts--;
    }

    if (!part_mounted_rw)
    {
        BFMR_PRINT_ERR("failed to check if [%s] has been mounted rw or not!\n", pmount_point);
    }

    return (part_mounted_rw) ? (0) : (-1);
}


static int __bfmr_create_dir(char *path)
{
    int fd = -1;
    mm_segment_t old_fs;

    if (unlikely(path == NULL))
    {
        BFMR_PRINT_INVALID_PARAMS("path: %p\n", path);
        return -1;
    }

    old_fs = get_fs();
    set_fs(KERNEL_DS);

    fd = sys_access(path, 0);
    if (0 != fd)
    {
        fd = sys_mkdir(path, BFMR_DIR_LIMIT);
        if (fd < 0)
        {
            BFMR_PRINT_ERR("create dir [%s] failed! [ret = %d]\n", path, fd);
            set_fs(old_fs);
            return fd;
        }
    }

    set_fs(old_fs);

    return 0;
}


static int bfmr_create_dir(const char *path)
{
    char *cur_path = NULL;
    int index = 0;

    if (unlikely(path == NULL))
    {
        BFMR_PRINT_INVALID_PARAMS("path: %p\n", path);
        return -1;
    }

    if (*path != '/')
    {
        return -1;
    }

    cur_path = (char *)bfmr_malloc(BFMR_MAX_PATH + 1);
    if (NULL == cur_path)
    {
        BFMR_PRINT_ERR("bfmr_malloc failed!\n");
        return -1;
    }
    memset(cur_path, 0, BFMR_MAX_PATH + 1);

    cur_path[index++] = *path++;
    while (*path != '\0')
    {
        if (*path == '/')
        {
            __bfmr_create_dir(cur_path);
        }
        cur_path[index] = *path;
        path++;
        index++;
    }

    __bfmr_create_dir(cur_path);
    bfmr_free(cur_path);

    return 0;
}


int bfmr_create_log_path(char *path)
{
    int ret = -1;

    if (unlikely(NULL == path))
    {
        BFMR_PRINT_INVALID_PARAMS("path: %p\n", path);
        return -1;
    }

    if (bfmr_is_dir_existed(path))
    {
        bfmr_change_own_mode(path, BFMR_AID_ROOT, BFMR_AID_SYSTEM, BFMR_DIR_LIMIT);
        return 0;
    }

    ret = bfmr_create_dir(path);
    if (0 == ret)
    {
        bfmr_change_own_mode(path, BFMR_AID_ROOT, BFMR_AID_SYSTEM, BFMR_DIR_LIMIT);
    }

    BFMR_PRINT_KEY_INFO("Create dir [%s] %s!\n", path, (0 != ret) ? ("failed") : ("successfully"));

    return ret;
}


char* bfmr_convert_rtc_time_to_asctime(unsigned long long rtc_time)
{
    struct rtc_time tm;
    static char asctime[32];

    memset((void *)asctime, 0, sizeof(asctime));
    memset((void *)&tm, 0, sizeof(struct rtc_time));
    rtc_time_to_tm(rtc_time, &tm);
    snprintf(asctime, sizeof(asctime) - 1, "%04d%02d%02d%02d%02d%02d",
        tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
        tm.tm_hour, tm.tm_min, tm.tm_sec);

    return asctime;
}


int bfmr_common_init(void)
{
    bfmr_create_crc32_table();

    return 0;
}

