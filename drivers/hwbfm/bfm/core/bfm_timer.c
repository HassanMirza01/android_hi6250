/**
    @copyright: Huawei Technologies Co., Ltd. 2016-xxxx. All rights reserved.

    @file: bfm_timer.c

    @brief: define the basic external enum/macros/interface for BFM (Boot Fail Monitor)

    @version: 2.0

    @author: QiDechun ID: 216641

    @date: 2016-08-17

    @history:
*/

/*----includes-----------------------------------------------------------------------*/

#include <linux/kernel.h>
#include <linux/export.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/stat.h>
#include <linux/io.h>
#include <asm/uaccess.h>
#include <linux/of_fdt.h>
#include <linux/list.h>
#include <linux/of_address.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/jiffies.h>
#include <linux/kthread.h>
#include <chipset_common/bfmr/public/bfmr_public.h>
#include <chipset_common/bfmr/common/bfmr_common.h>
#include <chipset_common/bfmr/bfm/core/bfm_timer.h>
#include <chipset_common/bfmr/bfm/core/bfm_core.h>


/*----local macroes-----------------------------------------------------------------*/

#define BOOT_TIMER_COUNT_STEP ((unsigned int)10000) /* unit: msec */
#define BFMR_TIMEOUT_VALUE_FOR_SHORT_TIMER ((u32)(1000 * 60 * 30)) /* unit: msec */
#define BFMR_TIMEOUT_VALUE_FOR_LONG_TIMER ((u32)(1000 * 60 * 30)) /* unit: msec */


/*----local prototypes---------------------------------------------------------------*/

struct bfm_boot_timer_info
{
    unsigned int count_step_value;
    struct task_struct *boot_time_task;
    struct timer_list boot_timer;
    struct completion boot_complete;
    bool boot_timer_count_enable;
    bool boot_timer_count_task_should_run;
    u32 long_timer_timeout_value;
    u32 short_timer_timeout_value;
};


/*----local variables------------------------------------------------------------------*/

static struct bfm_boot_timer_info *s_boot_timer_info = NULL;
static struct mutex s_boot_timer_mutex;


/*----global variables-----------------------------------------------------------------*/


/*----global function prototypes---------------------------------------------------------*/


/*----local function prototypes---------------------------------------------------------*/

static void bfm_check_boot_time(struct bfm_boot_timer_info *boot_timer_info);
static void bfm_wakeup_boot_timer_count_task(unsigned long data);
static __ref int bfm_boot_timer_count_kthread(void *arg);


/*----function definitions--------------------------------------------------------------*/

static void bfm_check_boot_time(struct bfm_boot_timer_info *boot_timer_info)
{
    static u32 long_timer_timing_count = 0U;
    static u32 short_timer_timing_count = 0U;

    long_timer_timing_count += boot_timer_info->count_step_value;
    if (boot_timer_info->boot_timer_count_enable)
    {
        BFMR_PRINT_SIMPLE_INFO("hwboot_timer:update timer [long and short]!\n");
        short_timer_timing_count += boot_timer_info->count_step_value;
    }
    else
    {
        BFMR_PRINT_SIMPLE_INFO("hwboot_timer:update timer [only long]!\n");
    }

    if ((short_timer_timing_count >= boot_timer_info->short_timer_timeout_value)
        || (long_timer_timing_count >= boot_timer_info->long_timer_timeout_value))
    {
        BFMR_PRINT_SIMPLE_INFO("hwboot_timer: %s timer expired! boot fail!\n",
            (long_timer_timing_count >= boot_timer_info->long_timer_timeout_value)
            ? ("30 minutes") : ("3 minutes"));
        boot_timer_info->boot_timer_count_task_should_run = false;
        boot_fail_err(KERNEL_BOOT_TIMEOUT, NO_SUGGESTION, NULL);
    }
}


static void bfm_wakeup_boot_timer_count_task(unsigned long data)
{
    struct bfm_boot_timer_info *boot_timer_info = (struct bfm_boot_timer_info *)data;
    complete(&boot_timer_info->boot_complete);
}


static __ref int bfm_boot_timer_count_kthread(void *arg)
{
    struct bfm_boot_timer_info *boot_timer_info = (struct bfm_boot_timer_info *)arg;
    unsigned long delay_time = 0;
    struct sched_param param = {.sched_priority = MAX_RT_PRIO - 1};

    sched_setscheduler(current, SCHED_FIFO, &param);
    while (!kthread_should_stop())
    {
        while (wait_for_completion_interruptible(&boot_timer_info->boot_complete) != 0)
        {
            ;
        }
        reinit_completion(&boot_timer_info->boot_complete);

        mutex_lock(&s_boot_timer_mutex);
        delay_time = msecs_to_jiffies(boot_timer_info->count_step_value);
        if (boot_timer_info->boot_timer_count_task_should_run)
        {
            bfm_check_boot_time(boot_timer_info);
            mod_timer(&boot_timer_info->boot_timer, jiffies + delay_time);
        }
        else
        {
            BFMR_PRINT_SIMPLE_INFO("hwboot_timer: time counting thread will stop now!\n");
            s_boot_timer_info = NULL;
            del_timer_sync(&boot_timer_info->boot_timer);
            bfmr_free(boot_timer_info);
            mutex_unlock(&s_boot_timer_mutex);
            break;
        }
        mutex_unlock(&s_boot_timer_mutex);
    }

    return 0;
}


/**
    @function: int bfm_get_boot_timer_state(int *state)
    @brief: get state of the boot timer.

    @param: state [out], the state of the boot timer.

    @return: 0 - success, -1 - failed.

    @note:
        1. this fuction only need be initialized in kernel.
        2. if *state == 0, the boot timer is disabled, if *state == 1, the boot timer is enbaled.
*/
int bfm_get_boot_timer_state(int *state)
{
    int ret = -1;

    if (unlikely(NULL == state))
    {
        return -1;
    }

    mutex_lock(&s_boot_timer_mutex);
    if (likely(NULL != s_boot_timer_info))
    {
        *state = (s_boot_timer_info->boot_timer_count_enable) ? 1 : 0;
        ret = 0;
    }
    else
    {
        *state = 0;
    }
    mutex_unlock(&s_boot_timer_mutex);

    return ret;
}
EXPORT_SYMBOL(bfm_get_boot_timer_state);


/**
    @function: int bfm_suspend_boot_timer(void)
    @brief: suspend the boot timer.

    @param: none.

    @return: 0 - success, -1 - failed.

    @note:
*/
int bfm_suspend_boot_timer(void)
{
    int ret = -1;

    BFMR_PRINT_KEY_INFO("disable short timer!\n");
    mutex_lock(&s_boot_timer_mutex);
    if (likely(NULL != s_boot_timer_info))
    {
        s_boot_timer_info->boot_timer_count_enable = false;
        ret = 0;
    }
    mutex_unlock(&s_boot_timer_mutex);

    return ret;
}
EXPORT_SYMBOL(bfm_suspend_boot_timer);


/**
    @function: int bfmr_resume_boot_timer(void)
    @brief: resume the boot timer.

    @param: none.

    @return: 0 - success, -1 - failed.

    @note:
*/
int bfmr_resume_boot_timer(void)
{
    int ret = -1;

    BFMR_PRINT_KEY_INFO("enable short timer!\n");
    mutex_lock(&s_boot_timer_mutex);
    if (likely(NULL != s_boot_timer_info))
    {
        s_boot_timer_info->boot_timer_count_enable = true;
        ret = 0;
    }
    mutex_unlock(&s_boot_timer_mutex);

    return ret;
}
EXPORT_SYMBOL(bfmr_resume_boot_timer);


/**
    @function: int bfm_set_boot_timer_timeout_value(int timeout_value)
    @brief: set timeout count_step_value of the boot timer.

    @param: timeout_value [int], timeout count_step_value to be set.

    @return: 0 - success, -1 - failed.

    @note:
        1. this fuction only need be initialized in kernel.
*/
int bfm_set_boot_timer_timeout_value(int timeout_value)
{
    int ret = -1;

    BFMR_PRINT_KEY_INFO("update timeout value to: %d!\n", timeout_value);
    mutex_lock(&s_boot_timer_mutex);
    if (likely(NULL != s_boot_timer_info))
    {
        s_boot_timer_info->short_timer_timeout_value = timeout_value;
        ret = 0;
    }
    mutex_unlock(&s_boot_timer_mutex);

    return ret;
}
EXPORT_SYMBOL(bfm_set_boot_timer_timeout_value);


/**
    @function: int bfm_get_boot_timer_timeout_value(int *ptimeout_value)
    @brief: get timeout count_step_value of the boot timer.

    @param: ptimeout_value [out], timeout count_step_value of the timer.

    @return: 0 - success, -1 - failed.

    @note:
        1. this fuction only need be initialized in kernel.
*/
int bfm_get_boot_timer_timeout_value(int *ptimeout_value)
{
    int ret = -1;

    if (unlikely(NULL == ptimeout_value))
    {
        return -1;
    }

    mutex_lock(&s_boot_timer_mutex);
    if (likely(NULL != s_boot_timer_info))
    {
        *ptimeout_value = s_boot_timer_info->short_timer_timeout_value;
        ret = 0;
    }
    mutex_unlock(&s_boot_timer_mutex);

    return ret;
}
EXPORT_SYMBOL(bfm_get_boot_timer_timeout_value);


/**
    @function: int bfm_stop_boot_timer(void)
    @brief: stop the boot timer.

    @param: none.

    @return: 0 - success, -1 - failed.

    @note: this fuction only need be initialized in kernel.
*/
int bfm_stop_boot_timer(void)
{
    int ret = -1;

    BFMR_PRINT_KEY_INFO("stop timer!\n");
    mutex_lock(&s_boot_timer_mutex);
    if (likely(NULL != s_boot_timer_info))
    {
        s_boot_timer_info->boot_timer_count_task_should_run = false;
        ret = 0;
    }
    mutex_unlock(&s_boot_timer_mutex);

    return ret;
}
EXPORT_SYMBOL(bfm_stop_boot_timer);


/**
    @function: int bfm_init_boot_timer(void)
    @brief: init the boot timer.

    @param: none.

    @return: 0 - success, -1 - failed.

    @note: this fuction only need be initialized in kernel.
*/
int bfm_init_boot_timer(void)
{
    int ret = 0;
    unsigned long delay_time = 0;
    struct bfm_boot_timer_info *boot_timer_info;

    boot_timer_info = bfmr_malloc(sizeof(struct bfm_boot_timer_info));
    if (NULL == boot_timer_info)
    {
        BFMR_PRINT_ERR("bfmr_malloc failed!\n");
        return -EIO;
    }

    s_boot_timer_info = boot_timer_info;
    boot_timer_info->boot_time_task = kthread_create(bfm_boot_timer_count_kthread,
        boot_timer_info, "hwboot_time");
    if (IS_ERR(boot_timer_info->boot_time_task))
    {
        ret = PTR_ERR(boot_timer_info->boot_time_task);
        goto err;
    }

    boot_timer_info->count_step_value = BOOT_TIMER_COUNT_STEP;
    boot_timer_info->long_timer_timeout_value = BFMR_TIMEOUT_VALUE_FOR_LONG_TIMER;
    boot_timer_info->short_timer_timeout_value = BFMR_TIMEOUT_VALUE_FOR_SHORT_TIMER;
    boot_timer_info->boot_timer_count_enable = true;
    boot_timer_info->boot_timer_count_task_should_run = true;
    mutex_init(&s_boot_timer_mutex);

    delay_time = msecs_to_jiffies(boot_timer_info->count_step_value);
    init_completion(&boot_timer_info->boot_complete);
    wake_up_process(boot_timer_info->boot_time_task);
    init_timer(&boot_timer_info->boot_timer);
    boot_timer_info->boot_timer.data = (unsigned long)boot_timer_info;
    boot_timer_info->boot_timer.function = bfm_wakeup_boot_timer_count_task;
    boot_timer_info->boot_timer.expires = jiffies + delay_time;
    add_timer(&boot_timer_info->boot_timer);

    return 0;

err:
    kzfree(boot_timer_info);

    return ret;
}
EXPORT_SYMBOL(bfm_init_boot_timer);

