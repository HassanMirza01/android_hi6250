/* lint -save -e801 */

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#include <linux/init.h>
#include <linux/module.h>
#include <linux/debugfs.h>
#include <linux/string.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <asm-generic/uaccess.h>
#include <bsp_slice.h>
#include <bsp_fault_inflood.h>


typedef enum _fault_inflood_timestamp_e
{
    TESTCASE_WR_START = 0,
    AUTOTEST_ICC_SEND,
    TESTCASE_WR_END,
    TESTCASE_RD_START,
    TESTCASE_RD_END,
    TESTRSLT_WR_START,
    AUTOTEST_ICC_RECV,
    TESTRSLT_WR_END,
    TESTRSLT_RD_START,
    TESTRSLT_RD_END,
    AUTOTEAST_MAX
} FAULT_INFLOOD_TIMESTAMP;


typedef struct __fault_inflood_acore_ctrl__
{
    spinlock_t  list_spinlock;
    u32        *p_fault_inflood_status;
    u32         delay_time;
    u32         check_count;
    u64         node_addr;
    s32         node_rslt;
    osl_sem_id  case_mutex;
    osl_sem_id  rslt_mutex;
} fault_inflood_acore_ctrl;


typedef struct __fault_inflood_acore_req__
{
    struct list_head list;
    u32              status;
    s32              result;
    fault_inflood_req      msg;
} fault_inflood_acore_req;


static u32                g_log_switch = 0;
static u32                g_timestamp[AUTOTEAST_MAX];
static fault_inflood_acore_ctrl g_fault_inflood_acore_ctrl;
static fault_inflood_debug      g_fault_inflood_debug = {0, 0, 0, 0};
static struct dentry      *root_entry, *case_entry, *rslt_entry;
static LIST_HEAD(g_fault_inflood_list);


void display_timestamp(void)
{
    if(g_log_switch)
    {
        fault_inflood_printf("TESTCASE_WR_START == 0x%x\n", g_timestamp[TESTCASE_WR_START]);
        fault_inflood_printf("AUTOTEST_ICC_SEND == 0x%x\n", g_timestamp[AUTOTEST_ICC_SEND]);
        fault_inflood_printf("TESTCASE_WR_END   == 0x%x\n", g_timestamp[TESTCASE_WR_END]);
        fault_inflood_printf("TESTCASE_RD_START == 0x%x\n", g_timestamp[TESTCASE_RD_START]);
        fault_inflood_printf("TESTCASE_RD_END   == 0x%x\n", g_timestamp[TESTCASE_RD_END]);
        fault_inflood_printf("TESTRSLT_WR_START == 0x%x\n", g_timestamp[TESTRSLT_WR_START]);
        fault_inflood_printf("AUTOTEST_ICC_RECV == 0x%x\n", g_timestamp[AUTOTEST_ICC_RECV]);
        fault_inflood_printf("TESTRSLT_WR_END   == 0x%x\n", g_timestamp[TESTRSLT_WR_END]);
        fault_inflood_printf("TESTRSLT_RD_START == 0x%x\n", g_timestamp[TESTRSLT_RD_START]);
        fault_inflood_printf("TESTRSLT_RD_END   == 0x%x\n", g_timestamp[TESTRSLT_RD_END]);
    }

    return;
}


void record_timestamp(FAULT_INFLOOD_TIMESTAMP ts)
{
    if(g_log_switch)
    {
        g_timestamp[ts] = bsp_get_slice_value();
    }

    return;
}


u32 llt_mdrv_log(u32 value)
{
    g_log_switch = value;
    return value;
}


void reset_timestamp(void)
{
    int i = 0;

    if(g_log_switch)
    {
        for(i = 0; i < AUTOTEAST_MAX; i++)
        {
            g_timestamp[i] = 0;
        }
    }

    return;
}


int fault_inflood_open(struct inode *inode, struct file *filp)
{
    filp->private_data = inode->i_private;
    return 0;
}


void fault_inflood_setnode(fault_inflood_acore_req *node, spinlock_t *spinlock,
    u32 status, s32 result)
{
    unsigned long flags;

    spin_lock_irqsave(spinlock, flags);
    node->status = status;
    node->result = result;
    spin_unlock_irqrestore(spinlock, flags);
}


void fault_inflood_getnode(fault_inflood_acore_req *node, spinlock_t *spinlock,
    u32* status, s32* result)
{
    unsigned long flags;

    spin_lock_irqsave(spinlock, flags);
    *status = node->status;
    *result = node->result;
    spin_unlock_irqrestore(spinlock, flags);
}


ssize_t testcase_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
    u64 node_addr = g_fault_inflood_acore_ctrl.node_addr;
    u32 index     = 17;
    u8  str[19]   = {
        '0','x',
        '0','0','0','0','0','0','0','0',
        '0','0','0','0','0','0','0','0',
        '\n'};
    record_timestamp(TESTCASE_RD_START);
    while(node_addr)
    {
        if(node_addr % 16 >= 10)
        {
            str[index] = node_addr % 16 - 10 + 'a';
        }
        else
        {
            str[index] = node_addr % 16 + '0';
        }
        node_addr >>= 4;
        index--;
    }

    ssize_t ret = simple_read_from_buffer(buf, count, f_pos, str, 19);

    g_fault_inflood_acore_ctrl.node_addr = 0x0;

    osl_sem_up(&(g_fault_inflood_acore_ctrl.case_mutex));
    record_timestamp(TESTCASE_RD_END);
    return ret;
}


ssize_t testcase_write(struct file *filp, const char __user *buf, size_t count,
    loff_t *f_pos)
{
    fault_inflood_acore_req *acore_msg = NULL;
    s32                result = 0;

    osl_sem_down(&(g_fault_inflood_acore_ctrl.case_mutex));

    reset_timestamp();
    record_timestamp(TESTCASE_WR_START);

    if (count > FAULT_INFLOOD_FUNC_NAME_LENGTH)
    {
        fault_inflood_error_printf("testcase function name is %d, longer then 63!\n", count - 1);
        osl_sem_up(&(g_fault_inflood_acore_ctrl.case_mutex));
        return FAULT_INFLOOD_ERROR;
    }

    acore_msg = osl_malloc(sizeof(*acore_msg));
    if(NULL == acore_msg)
    {
        fault_inflood_error_printf("osl_malloc failed to malloc mem for acore_msg!\n");
        osl_sem_up(&(g_fault_inflood_acore_ctrl.case_mutex));
        return FAULT_INFLOOD_ERROR;
    }

    (void)memset(acore_msg, 0, sizeof(*acore_msg));
    if(copy_from_user(acore_msg->msg.func_name, buf, count - 1))
    {
        fault_inflood_error_printf("copy_from_user failed!\n");
        osl_free(acore_msg);
        osl_sem_up(&(g_fault_inflood_acore_ctrl.case_mutex));
        return FAULT_INFLOOD_ERROR;
    }

    acore_msg->status        = WAIT;
    acore_msg->result        = FAULT_INFLOOD_TIMEOUT;
    acore_msg->msg.node_addr =
        (sizeof(acore_msg) == 8) ? ((u64)acore_msg) : (((u64)acore_msg << 32) >> 32);
    g_fault_inflood_acore_ctrl.node_addr = acore_msg->msg.node_addr;

    fault_inflood_addnode(&(acore_msg->list), &g_fault_inflood_list,
        &(g_fault_inflood_acore_ctrl.list_spinlock));

    result = bsp_icc_send(ICC_CPU_MODEM, FAULT_INFLOOD_ICC_CHN_ID, (u8*)&(acore_msg->msg),
            sizeof(acore_msg->msg));
    if(result != sizeof(acore_msg->msg))
    {
        fault_inflood_error_printf("bsp_icc_send fail to send req_msg!\n");
        fault_inflood_delnode(&(acore_msg->list), &(g_fault_inflood_acore_ctrl.list_spinlock));
        osl_free(acore_msg);
        osl_sem_up(&(g_fault_inflood_acore_ctrl.case_mutex));
        return FAULT_INFLOOD_ERROR;
    }

    record_timestamp(AUTOTEST_ICC_SEND);

    g_fault_inflood_debug.send_cnt++;

    fault_inflood_debug_printf("func_name = %s\n", acore_msg->msg.func_name);
    fault_inflood_debug_printf("node_addr = 0x%llx\n", acore_msg->msg.node_addr);

    record_timestamp(TESTCASE_WR_END);

    return count;
}


static const struct file_operations testcase_operations = {
    .owner  = THIS_MODULE,
    .read   = testcase_read,
    .write  = testcase_write,
    .open   = fault_inflood_open,
};


s32 testrslt_read(void)
{
    record_timestamp(TESTRSLT_RD_START);
    s32 result = g_fault_inflood_acore_ctrl.node_rslt;

    g_fault_inflood_acore_ctrl.node_rslt = FAULT_INFLOOD_TIMEOUT;

    osl_sem_up(&(g_fault_inflood_acore_ctrl.rslt_mutex));

    record_timestamp(TESTRSLT_RD_END);
    display_timestamp();

    return result;
}


ssize_t testrslt_write(struct file *filp, const char __user *buf, size_t count,
    loff_t *f_pos)
{
    unsigned long node_addr = 0;
    fault_inflood_acore_req *node = 0;
    s32 result = 0;
    u32 node_status, node_result;
    u32 cnt = 0;

    osl_sem_down(&(g_fault_inflood_acore_ctrl.rslt_mutex));
    record_timestamp(TESTRSLT_WR_START);
    result = kstrtoul_from_user(buf, count - 1, 0, &node_addr);
    if(result)
    {
        fault_inflood_error_printf("kstrtoul_from_user failed!\n");
        osl_sem_up(&(g_fault_inflood_acore_ctrl.rslt_mutex));
        return FAULT_INFLOOD_ERROR;
    }

    node = (fault_inflood_acore_req*)node_addr;
    fault_inflood_getnode(node, &(g_fault_inflood_acore_ctrl.list_spinlock),
        &node_status, &node_result);

    while((node_status != DONE) && (cnt < g_fault_inflood_acore_ctrl.check_count))
    {
        udelay(g_fault_inflood_acore_ctrl.delay_time);
        fault_inflood_getnode(node, &(g_fault_inflood_acore_ctrl.list_spinlock),
            &node_status, &node_result);
        cnt++;
    }

    fault_inflood_delnode(&(node->list), &(g_fault_inflood_acore_ctrl.list_spinlock));
    memset(node, 0, sizeof(*node));
    osl_free(node);

    if(node_status != DONE)
    {
        fault_inflood_error_printf("testcase timeout 10s!\n");
    }

    g_fault_inflood_acore_ctrl.node_rslt = node_result;

    record_timestamp(TESTRSLT_WR_END);
    return count;
}


static const struct file_operations testrslt_operations = {
    .owner  = THIS_MODULE,
    .read   = NULL,
    .write  = testrslt_write,
    .open   = fault_inflood_open,
};


s32 fault_inflood_init_check(void)
{
    u32 acore_status;
    u32 ccore_status;
    if(0xaaaacccc == *(g_fault_inflood_acore_ctrl.p_fault_inflood_status))
    {
        return FAULT_INFLOOD_OK;
    }

    fault_inflood_error_printf("fault_inflood fail to init!\n");

    acore_status = (*(g_fault_inflood_acore_ctrl.p_fault_inflood_status)) >> 16;
    ccore_status = *(g_fault_inflood_acore_ctrl.p_fault_inflood_status);

    fault_inflood_error_printf("ERROR!\n");

    return FAULT_INFLOOD_ERROR;
}


s32 fault_inflood_delaytime(u32 time)
{
    if(time > 0)
    {
        g_fault_inflood_acore_ctrl.delay_time = time;
    }
    return g_fault_inflood_acore_ctrl.delay_time;
}


s32 fault_inflood_checkcount(u32 count)
{
    if(count > 0)
    {
        g_fault_inflood_acore_ctrl.check_count = count;
    }
    return g_fault_inflood_acore_ctrl.check_count;
}


s32 fault_inflood_acore_callback(u32 channel_id , u32 len, void* context)
{
    s32 result = 0;
    fault_inflood_acore_req *node;
    fault_inflood_ack msg = {0, 0};

    if(channel_id != FAULT_INFLOOD_ICC_CHN_ID)
    {
        fault_inflood_error_printf("channel_id != FAULT_INFLOOD_ICC_CHN_ID!\n");
        return FAULT_INFLOOD_ERROR;
    }

    result = bsp_icc_read(FAULT_INFLOOD_ICC_CHN_ID, (u8*)&msg, sizeof(msg));
    if(result != sizeof(msg))
    {
        fault_inflood_error_printf("bsp_icc_read fail to read ack_msg!\n");
        return FAULT_INFLOOD_ERROR;
    }
    record_timestamp(AUTOTEST_ICC_RECV);

    node = (fault_inflood_acore_req*)(msg.node_addr);
    if(node != node->msg.node_addr)
    {
        fault_inflood_error_printf("node_addr ERROR!\n");
        return FAULT_INFLOOD_ERROR;
    }

    /* ¸üÐÂÁ´±í×´Ì¬ */
    fault_inflood_setnode(node, &(g_fault_inflood_acore_ctrl.list_spinlock), DONE, msg.result);

    g_fault_inflood_debug.rslt_cnt++;
    fault_inflood_debug_printf("fault_inflood_acore_callback SUCCESS!\n");

    return FAULT_INFLOOD_OK;
}


void fault_inflood_acore_debug(void)
{
    fault_inflood_printf("******send_cnt = %d******\n", g_fault_inflood_debug.send_cnt);
    fault_inflood_printf("******rslt_cnt = %d******\n", g_fault_inflood_debug.rslt_cnt);
}


s32 fault_inflood_acore_init(void)
{
    s32 result = 0;
    u32 status = 0;

    spin_lock_init(&(g_fault_inflood_acore_ctrl.list_spinlock));

    g_fault_inflood_acore_ctrl.p_fault_inflood_status     = (u32*)FAULT_INFLOOD_STATUS_SHMADDR;
    *(g_fault_inflood_acore_ctrl.p_fault_inflood_status) &= 0x0000ffff;
    g_fault_inflood_acore_ctrl.delay_time           = 1000;
    g_fault_inflood_acore_ctrl.check_count          = 10000;
    g_fault_inflood_acore_ctrl.node_addr            = 0x0;
    osl_sem_init(1, &(g_fault_inflood_acore_ctrl.case_mutex));
    osl_sem_init(1, &(g_fault_inflood_acore_ctrl.rslt_mutex));

    root_entry = debugfs_create_dir("fault_inflood", NULL);
    if(!root_entry)
    {
        status = 0xaaaa0000;
        fault_inflood_error_printf("debugfs_create_dir: root_entry fault_inflood ERROR!\n");
        goto ret_error;
    }

    case_entry = debugfs_create_file("test_case", 0644, root_entry, NULL,
        &testcase_operations);
    if(!case_entry)
    {
        status = 0xaaaa0001;
        fault_inflood_error_printf("debugfs_create_file: case_entry test_case ERROR!\n");
        goto ret_rmdbgfs;
    }

    rslt_entry = debugfs_create_file("test_rslt", 0644, root_entry, NULL,
        &testrslt_operations);
    if(!case_entry)
    {
        status = 0xaaaa0002;
        fault_inflood_error_printf("debugfs_create_file: case_entry test_case ERROR!\n");
        goto ret_rmdbgfs;
    }

    result = bsp_icc_event_register(FAULT_INFLOOD_ICC_CHN_ID, fault_inflood_acore_callback,
        NULL, NULL, NULL);
    if(ICC_OK != result)
    {
        status = 0xaaaa0003;
        fault_inflood_error_printf("register icc channel failed!\n");
        goto ret_rmdbgfs;
    }

    *(g_fault_inflood_acore_ctrl.p_fault_inflood_status) |= 0xaaaa0000;

    fault_inflood_printf("fault_inflood_acore_init SUCCESS!\n");

    return FAULT_INFLOOD_OK;

ret_rmdbgfs:
    debugfs_remove_recursive(root_entry);

ret_error:
    osl_sema_delete(&(g_fault_inflood_acore_ctrl.case_mutex));
    osl_sema_delete(&(g_fault_inflood_acore_ctrl.rslt_mutex));
    fault_inflood_error_printf("ERROR!\n");
    return FAULT_INFLOOD_ERROR;
}


module_init(fault_inflood_acore_init);

MODULE_LICENSE("GPL");


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

/* lint -restore */

