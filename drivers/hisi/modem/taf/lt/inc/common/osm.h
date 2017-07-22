

#ifndef __OSM_H__
#define __OSM_H__

#include "vos.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef struct
{
    VOS_UINT32 ulMsgId;
    VOS_UINT32 ulParam2;            /* 记录ulLen信息 */
    /* Added by w00316404 for 双L后邮箱机制修改, 2016-09-30, begin */
    VOS_UINT32 ulParam3;            /* 记录RcvPid信息 */
    /* Added by w00316404 for 双L后邮箱机制修改, 2016-09-30, begin */
    VOS_UINT8 *ulParam1;
} OS_MSG_STRU;

typedef struct
{
    VOS_UINT32 ulTimeId;
    VOS_UINT32 ulPara;    /* 对应原来的ulParam2*/
} OSM_MSG_TIMER_STRU;


#define HAL_SDMLOG  (VOS_VOID)vos_printf
#define MSP_MEMCPY(dst, dst_size, src, count)   VOS_MemCpy_s(dst, dst_size, src, count)
#define MSP_MEMSET(dst, dst_size, val, count) VOS_MemSet_s(dst, dst_size, val, count)

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* __OSM_H__*/

