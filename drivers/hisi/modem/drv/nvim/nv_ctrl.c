

#include <product_config.h>
#include <ptable_com.h>
#include "mdrv_rfile_common.h"
#include <bsp_blk.h>
#include <bsp_slice.h>
#include "bsp_rfile.h"
#include "nv_comm.h"
#include "nv_debug.h"
#include "nv_ctrl.h"

struct file_ops_table_stru  g_nv_ops = {
    .fo = nv_emmc_open,
    .fc = nv_emmc_close,
    .frm= nv_emmc_remove,
    .fr = nv_emmc_read,
    .fw = nv_emmc_write,
    .fs = nv_emmc_seek,
    .ff = nv_emmc_ftell,
    .fa = nv_emmc_access,
    .fu = nv_emmc_update_info,
};



/*
 * Function:    nv_file_init
 * Discription: global info init,flash: get mtd device
 */
u32 nv_file_init(void)
{
    u32 ret;

    ret = nv_emmc_init();
    if(ret)
    {
        return ret;
    }
    return NV_OK;

}

int nv_file_getmode(const char *mode, int *flag)
{
    int ret;
    u32 m;
    u32 o;

    switch (*mode++)
    {
    case 'r':               /* open for reading */
        ret = 0x0004;
        m = RFILE_RDONLY;
        o = 0;
        break;

    case 'w':               /* open for writing */
        ret = 0x0008;
        m = RFILE_WRONLY;
        o = RFILE_CREAT | RFILE_TRUNC;
        break;

    case 'a':               /* open for appending */
        ret = 0x0008;
        m = RFILE_WRONLY;
        o = RFILE_CREAT | RFILE_APPEND;
        break;

    default:                /* illegal mode */

        return (0);
    }

    /* [rwa]\+ or [rwa]b\+ means read and write */

    if ((*mode == '+') || (*mode == 'b' && mode[1] == '+'))
    {
        ret = 0x0010;
        m = RFILE_RDWR;
    }

    *flag = (int)(m | o);

    /* check for garbage in second character */
    if ((*mode != '+') && (*mode != 'b') && (*mode != '\0'))
    {
        nv_printf("1. mode:%c.\n",*mode);
        return (0);
    }

    /* check for garbage in third character */
    if (*mode++ == '\0')
    {
        return (ret);           /* no third char */
    }

    if ((*mode != '+') && (*mode != 'b') && (*mode != '\0'))
    {
        nv_printf("3. mode:%c.\n", *mode);
        return (0);
    }

    /* check for garbage in fourth character */
    if (*mode++ == '\0')
    {
        return (ret);           /* no fourth char */
    }

    if (*mode != '\0')
    {
        nv_printf("5. mode:%c.\n", *mode);
        return (0);
    }
    else
    {
        return (ret);
    }
}

/*
 * Function: nv_file_open
 * Discription: open file
 * Parameter:   path  :  file path
 *              mode  :  file ops type etc:"r+","rb+","w+","wb+"
 * Output   :   file pointer
 */
FILE* nv_file_open(const s8* path,const s8* mode)
{
    struct nv_file_p* fp;
    s32 ret = 0;
    int oflags = 0;
    int flag = 0;

    fp = (struct nv_file_p*)nv_malloc(sizeof(struct nv_file_p));
    if(!fp)
    {
        return NULL;
    }
    if(0 == strcmp((char*)path,(char*)NV_IMG_PATH))
    {
        flag = nv_file_getmode((const char*)mode, &oflags);
        if (0 == flag)
        {
            nv_printf("nv file getmode fail!flag=%d\n",flag);
            nv_free(fp);
            return NULL;
        }
        ret = bsp_open(path,oflags, 0660);
        if(ret < 0)
        {
            nv_printf("nv file open fail!ret=%d\n",ret);
            nv_free(fp);
            return NULL;
        }
        else
        {
            fp->fd = (void*)(unsigned long)(long)ret;
        }
        fp->stor_type = NV_FILE_STOR_FS;
    }
    else
    {
        fp->fd = g_nv_ops.fo(path,mode);
        fp->stor_type = NV_FILE_STOR_NON_FS;
    }

    return fp;
}

 
u32 nv_file_read(u8* ptr,u32 size,u32 count,FILE* fp)
{
    struct nv_file_p* fd = (struct nv_file_p*)fp;

    if(fd->stor_type == NV_FILE_STOR_FS)
    {
        return (u32)bsp_read((u32)(unsigned long)(fd->fd), (s8*)ptr, (size*count));
    }
    else if(fd->stor_type == NV_FILE_STOR_NON_FS)
    {
        return g_nv_ops.fr(ptr,size,count,fd->fd);
    }
    else
    {
        return NV_ERROR;
    }
}
 
u32 nv_file_write(u8* ptr,u32 size,u32 count,FILE* fp)
{
    struct nv_file_p* fd = (struct nv_file_p*)fp;
    u32 ret = 0;
    u32 start = 0;
    u32 end = 0;

    if(fd->stor_type == NV_FILE_STOR_FS)
    {
        start = bsp_get_slice_value();
        ret = (u32)bsp_write_sync((u32)(unsigned long)(fd->fd), (s8*)ptr, (size*count));
        end = bsp_get_slice_value();
        nv_debug_record_delta_time(NV_DEBUG_DELTA_WRITE_FILE, start, end);
        return ret;
    }
    else if(fd->stor_type == NV_FILE_STOR_NON_FS)
    {
        return g_nv_ops.fw(ptr,size,count,fd->fd);
    }
    else
    {
        return NV_ERROR;
    }
}

 
u32 nv_file_seek(FILE* fp,u32 offset,s32 whence)
{
    struct nv_file_p* fd = (struct nv_file_p*)fp;
    s32 ret = 0;

    if(fd->stor_type == NV_FILE_STOR_FS)
    {
        ret = bsp_lseek((u32)(unsigned long)(fd->fd), (long)offset, whence);
        if(ret < 0)
        {
            nv_printf("seek file fail, fp:0x%x\n", fd->fd);
            return NV_ERROR;
        }
        return NV_OK;
    }
    else if(fd->stor_type == NV_FILE_STOR_NON_FS)
    {
        return g_nv_ops.fs(fd->fd,offset,whence);
    }
    else
    {
        return NV_ERROR;
    }
}


u32 nv_file_close(FILE* fp)
{
    struct nv_file_p* fd = (struct nv_file_p*)fp;
    u32 ret = 0;

    if(fd->stor_type == NV_FILE_STOR_FS)
    {
        ret = (u32)bsp_close((u32)(unsigned long)(fd->fd));
    }
    else if(fd->stor_type == NV_FILE_STOR_NON_FS)
    {
        ret= g_nv_ops.fc(fd->fd);
    }
    else
    {
        return NV_ERROR;
    }
    nv_free(fp);
    return ret;
}
 
u32 nv_file_remove(const s8* path)
{
    if(0 == strcmp((char*)path,(char*)NV_IMG_PATH))
    {
        return (u32)bsp_remove(path);
    }
    else
    {
        return g_nv_ops.frm(path);
    }
}

 
u32 nv_file_ftell(FILE* fp)
{
    struct nv_file_p* fd = (struct nv_file_p*)fp;
    if(fd->stor_type == NV_FILE_STOR_FS)
    {
        return (u32)bsp_tell((u32)(unsigned long)(fd->fd));
    }
    else if(fd->stor_type == NV_FILE_STOR_NON_FS)
    {
        return g_nv_ops.ff(fd->fd);
    }
    else
    {
        return NV_ERROR;
    }
}

 /*
  * Function   : nv_file_access
  * Discription: check the file is exist?
  * Parameter  : fp:   file pointer
  * Output     :
  * return     : 0:表示有文件 其他没文件
  * History    : yuyangyang  00228784  create
  */
u32 nv_file_access(const s8* path,s32 mode)
{

    if(0 == strcmp((char*)path,(char*)NV_IMG_PATH))
    {
        return (u32)bsp_access((s8*)path, mode);
    }
    else
    {
        return g_nv_ops.fa(path,mode);
    }
}

 /*
  * Function   : nv_file_update
  * Discription: update the file info?
  * Parameter  : fp:   file pointer
  * Output     :
  * return     : 0:刷新信息成功 其他失败
  * History    :
  */
u32 nv_file_update(const s8* path)
{

    if(0 == strcmp((char*)path,(char*)NV_IMG_PATH))
    {
        return (u32)NV_ERROR;
    }
    else
    {
        return g_nv_ops.fu(path);
    }
}

/*copy img to backup*/
#define NV_FILE_COPY_UNIT_SIZE      (16*1024)

u32 nv_copy_img2backup(void)
{
    s32 ret;
    FILE* fp;
    u32 total_len;
    u32 phy_off = 0;
    u32 unit_len;
    void* pdata;
    int flag;
    int oflags= 0;

    flag = nv_file_getmode("rb", &oflags);
    if (0 == flag)
    {
        nv_printf("nv getmode fail!\n");
        return BSP_ERR_NV_FILE_ERROR;
    }

    ret = bsp_open((const s8 *)NV_IMG_PATH, oflags, 0660);
    if(ret < 0)
    {
        return BSP_ERR_NV_NO_FILE;
    }
    fp = (FILE*)(unsigned long)(long)ret;

    (void)bsp_lseek((u32)(unsigned long)fp, (long)0, SEEK_END);
    total_len = (u32)bsp_tell((u32)(unsigned long)fp);
    (void)bsp_lseek((u32)(unsigned long)fp, (long)0, SEEK_SET);

    pdata = (void*)nv_malloc((unsigned long)NV_FILE_COPY_UNIT_SIZE);
    if(!pdata)
    {
        (void)bsp_close((u32)(unsigned long)fp);
        return BSP_ERR_NV_MALLOC_FAIL;
    }

    nv_create_flag_file((s8*)NV_BACK_FLAG_PATH);
    while(total_len)
    {
        unit_len = (total_len >= NV_FILE_COPY_UNIT_SIZE)?NV_FILE_COPY_UNIT_SIZE : total_len;

        ret = bsp_read((u32)(unsigned long)fp, (s8*)pdata, unit_len);
        if(ret != (s32)unit_len)
        {
            nv_free(pdata);
            (void)bsp_close((u32)(unsigned long)fp);
            return BSP_ERR_NV_READ_FILE_FAIL;
        }

        ret = (s32)bsp_blk_write((char*)NV_BACK_SEC_NAME,(loff_t)phy_off,pdata, (size_t)unit_len);
        if(ret)
        {
            nv_free(pdata);
            (void)bsp_close((u32)(unsigned long)fp);
            return BSP_ERR_NV_WRITE_FILE_FAIL;
        }

        phy_off += unit_len;
        total_len -= unit_len;
    }

    nv_free(pdata);
    (void)bsp_close((u32)(unsigned long)fp);
    nv_delete_flag_file((s8*)NV_BACK_FLAG_PATH);

    return NV_OK;

}


/*修改升级包标志
 *true :有效   false :无效
 */

u32 nv_modify_upgrade_flag(bool flag)
{
    struct nv_dload_packet_head_stru nv_dload;
    s32 ret;
    u32 old_magic;
    u32 new_magic;

    ret = bsp_blk_read((char*)NV_DLOAD_SEC_NAME,(loff_t)0,&nv_dload,sizeof(nv_dload),NULL);
    if(ret)
    {
        return (u32)ret;
    }
    if(flag)
    {
        old_magic = NV_DLOAD_INVALID_FLAG;
        new_magic = NV_FILE_EXIST;
    }
    else
    {
        new_magic = NV_DLOAD_INVALID_FLAG;
        old_magic = NV_FILE_EXIST;
    }
    nv_dload.nv_bin.magic_num = (nv_dload.nv_bin.magic_num == old_magic) ? new_magic : nv_dload.nv_bin.magic_num;
    ret = bsp_blk_write((char*)NV_DLOAD_SEC_NAME,(loff_t)0,&nv_dload,sizeof(nv_dload));
    if(ret)
    {
        return (u32)ret;
    }
    return 0;

}

/*获取升级包数据有效性
 *true :有效 false: 无效
 */
bool nv_get_upgrade_flag(void)
{
    struct nv_dload_packet_head_stru nv_dload;
    s32 ret;

    ret = bsp_blk_read((char*)NV_DLOAD_SEC_NAME,(loff_t)0,&nv_dload,sizeof(nv_dload),NULL);
    if(ret)
    {
        return false;
    }

    if(nv_dload.nv_bin.magic_num == NV_FILE_EXIST)
    {
        return true;
    }
    return false;
}




EXPORT_SYMBOL(nv_file_close);
EXPORT_SYMBOL(nv_file_open);
EXPORT_SYMBOL(nv_file_seek);
EXPORT_SYMBOL(nv_file_write);
EXPORT_SYMBOL(nv_file_read);
EXPORT_SYMBOL(nv_file_remove);
EXPORT_SYMBOL(nv_file_access);



