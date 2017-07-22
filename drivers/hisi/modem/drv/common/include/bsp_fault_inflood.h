
#ifndef __BSP_FAULT_INFLOOD_H__
#define __BSP_FAULT_INFLOOD_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#ifdef __KERNEL__
#include <linux/kernel.h>
#endif

#include <osl_malloc.h>
#include <osl_spinlock.h>
#include <osl_list.h>
#include <osl_malloc.h>
#include <osl_types.h>
#include <osl_sem.h>
#include <bsp_shared_ddr.h>
#include <bsp_icc.h>
#include <bsp_dump.h>
#include <bsp_om_enum.h>


#if defined(__OS_RTOSCK__) || defined(__OS_RTOSCK_SMP__)
#include <bsp_trace.h>
#endif

#define BSP_MODU_FAULT_INFLOOD   BSP_MODU_PAN_RPC
#define DRV_ERRNO_FAULT_INFLOOD  DRV_ERRNO_PAN_RPC
#define SHM_OFFSET_FAULT_INFLOOD SHM_OFFSET_PAN_RPC

#define FAULT_INFLOOD_STATUS_SHMADDR  ((unsigned long)SHM_BASE_ADDR + SHM_OFFSET_FAULT_INFLOOD)
#define FAULT_INFLOOD_STATUS_SHMADDRH ((unsigned long)FAULT_INFLOOD_STATUS_SHMADDR)
#define FAULT_INFLOOD_STATUS_SHMADDRL ((unsigned long)FAULT_INFLOOD_STATUS_SHMADDR + 0x4)

#define FAULT_INFLOOD_ICC_CHN_ID       (ICC_CHN_AC_PANRPC << 16 | AC_PANRPC_ID)
#define FAULT_INFLOOD_FUNC_NAME_LENGTH (64)

#ifndef FAULT_INFLOOD_OK
#define FAULT_INFLOOD_OK               (0)
#endif

#ifndef FAULT_INFLOOD_ERROR
#define FAULT_INFLOOD_ERROR            (-1)
#endif

#ifndef FAULT_INFLOOD_NOSYMBOL
#define FAULT_INFLOOD_NOSYMBOL         (0xc0)
#endif

#ifndef FAULT_INFLOOD_TIMEOUT
#define FAULT_INFLOOD_TIMEOUT          (0xc1)
#endif

#ifdef __KERNEL__
#define fault_inflood_error_printf(fmt, ...) \
    printk(KERN_ERR"[FAULT_INFLOOD]: <%s> line = %d  "fmt, __FUNCTION__,__LINE__, ##__VA_ARGS__)
#define fault_inflood_debug_printf(fmt, ...) \
    printk(KERN_DEBUG"[FAULT_INFLOOD]: <%s> line = %d  "fmt, __FUNCTION__,__LINE__, ##__VA_ARGS__)
#define fault_inflood_printf(fmt, ...) \
        printk(KERN_EMERG"[FAULT_INFLOOD]: <%s> line = %d  "fmt, __FUNCTION__,__LINE__, ##__VA_ARGS__)
#endif

#if defined(__OS_RTOSCK__) || defined(__OS_RTOSCK_SMP__)
#define fault_inflood_error_printf(fmt, ...) \
    bsp_trace(BSP_LOG_LEVEL_ERROR,BSP_MODU_FAULT_INFLOOD,"[FAULT_INFLOOD]: <%s> line = %d  "fmt, __FUNCTION__,__LINE__, ##__VA_ARGS__);
#define fault_inflood_debug_printf(fmt, ...) \
    bsp_trace(BSP_LOG_LEVEL_DEBUG,BSP_MODU_FAULT_INFLOOD,"[FAULT_INFLOOD]: <%s> line = %d  "fmt, __FUNCTION__,__LINE__, ##__VA_ARGS__);
#define fault_inflood_printf(fmt, ...) \
    bsp_trace(BSP_LOG_LEVEL_ALERT,BSP_MODU_FAULT_INFLOOD,"[FAULT_INFLOOD]: <%s> line = %d  "fmt, __FUNCTION__,__LINE__, ##__VA_ARGS__);
#endif

#pragma pack (4)
typedef struct __fault_inflood_req__
{
    u64 node_addr;
    u8  func_name[FAULT_INFLOOD_FUNC_NAME_LENGTH];
} fault_inflood_req;

typedef struct __fault_inflood_ack__
{
    u64 node_addr;
    s32 result;
} fault_inflood_ack;

typedef struct __fault_inflood_debug_
{
    /* ACORE COUNTER */
    u32 send_cnt;
    u32 rslt_cnt;

    /* CCORE COUNTER */
    u32 recv_cnt;
    u32 exec_cnt;
} fault_inflood_debug;
#pragma pack ()

typedef enum
{
    WAIT,   /* µÈ´ý */
    DONE,   /* ½áÊø */
    MAX
}FAULT_INFLOOD_STAT_ENUM;


static inline void fault_inflood_addnode(struct list_head *new, struct list_head *head,
    spinlock_t *spinlock)
{
    unsigned long flags;

    spin_lock_irqsave(spinlock, flags); /*lint !e123 */
    list_add_tail(new, head);
    spin_unlock_irqrestore(spinlock, flags); /*lint !e123 */
}


static inline void fault_inflood_delnode(struct list_head *node, spinlock_t *spinlock)
{
    unsigned long flags;

    spin_lock_irqsave(spinlock, flags); /*lint !e123 */
    list_del(node);
    spin_unlock_irqrestore(spinlock, flags); /*lint !e123 */
}


#if defined(__OS_RTOSCK__) || defined(__OS_RTOSCK_SMP__)
int fault_inflood_ccore_init(void);
#endif


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* __BSP_FAULT_INFLOOD_H__ */

