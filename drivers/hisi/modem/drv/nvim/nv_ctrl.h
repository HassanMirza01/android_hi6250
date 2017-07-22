

#ifndef _NV_CTRL_H_
#define _NV_CTRL_H_


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#include "nv_comm.h"
#include "nv_file.h"

extern s32 bsp_open(const s8 *path, s32 flags, s32 mode);
extern s32 bsp_read(u32 fd, s8 *ptr, u32 size);
extern s32 bsp_write_sync(u32 fd, const s8 *ptr, u32 size);
extern s32 bsp_lseek(u32 fd, long offset, s32 whence);
extern long bsp_tell(u32 fd);
extern s32 bsp_remove(const s8 *pathname);
extern s32 bsp_access(s8 *path, s32 mode);
extern s32 bsp_close(u32 fp);

#ifdef CONFIG_MULTI_CARRIER
#define MTCA_ROUTINE_MAX_LENGTH   (64)

#define NV_MTCARRIER_USR_BIN_MAGIC  (0xa55af00f)

struct nv_mtcarrier_userlist_bin_stru
{
    u32 magic_head;
    u32 nvid_num;
};


#endif


typedef enum
{
    NV_FILE_STOR_FS     = 0,
    NV_FILE_STOR_NON_FS,
    NV_FILE_STOR_BUTT
}NV_FILE_STOR_TYPE_ENUM;

struct nv_file_p
{
    NV_FILE_STOR_TYPE_ENUM stor_type;
    void* fd;
};


typedef FILE* (*file_open)(const s8 * path,const s8* mode);
typedef u32  (*file_close)(FILE* fp);
typedef u32  (*file_read)(u8* ptr,u32 size,u32 count,FILE* fp);
typedef u32  (*file_write)(u8* ptr,u32 size,u32 count,FILE* fp);
typedef u32  (*file_remove)(const s8* path);
typedef u32  (*file_seek)(FILE* fp,u32 offset,s32 whence);
typedef u32  (*file_ftell)(FILE* fp);
typedef u32  (*file_access)(const s8* path,s32 mode);
typedef u32  (*file_mkdir)(const s8* path);
typedef u32  (*file_update)(const s8* path);
struct file_ops_table_stru
{
    file_open   fo;
    file_read   fr;
    file_write  fw;
    file_close  fc;
    file_remove frm;
    file_seek   fs;
    file_ftell  ff;
    file_access fa;
    file_update fu;
};


u32 nv_file_init(void);
FILE* nv_file_open(const s8 * path,const s8* mode);
u32 nv_file_read(u8 * ptr, u32 size, u32 count, FILE * fp);
u32 nv_file_write(u8 * ptr, u32 size, u32 count, FILE * fp);
u32 nv_file_close(FILE * fp);
u32 nv_file_seek(FILE * fp, u32 offset, s32 whence);
u32 nv_file_remove(const s8 * path);
u32 nv_file_ftell(FILE * fp);
u32 nv_file_access(const s8* path,s32 mode);
u32 nv_copy_img2backup(void);
u32 nv_modify_upgrade_flag(bool flag);
bool nv_get_upgrade_flag(void);
u32 nv_file_update(const s8* path);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /*_NV_CTRL_H_*/


