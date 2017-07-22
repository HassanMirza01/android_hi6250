#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#include <osl_types.h>
#include <osl_sem.h>
#include <osl_thread.h>
#include <bsp_nvim.h>
#include "nv_comm.h"

extern u32 bsp_nvm_reload(void);
void nv_read_write_task(void * parm);
u32 g_read_write_count = 0;
osl_sem_id g_read_write_task_sem;
void nv_test_set_read_write_count(u32 count);
void nv_test_create_read_write_task(void);
void nv_test_wakeup_read_write_task(void);
struct task_struct* g_task_id;

void nv_test_create_read_write_task(void)
{
    u32 ret = 0;

    osl_sem_init(0,&g_read_write_task_sem);

    ret = (u32)osl_task_init("rw_task", 30, 4096, (OSL_TASK_FUNC)nv_read_write_task, NULL, (OSL_TASK_ID *)&g_task_id);
    if(ret)
    {
        nv_printf("init rw_task fail, ret = 0x%x\n", ret);
    }


    return;
}

void nv_test_set_read_write_count(u32 count)
{
    g_read_write_count = count;
    return;
}

void nv_test_wakeup_read_write_task(void)
{
    osl_sem_up(&g_read_write_task_sem);
    return;
}
void nv_read_write_task(void * parm)
{
    u32 ret = 0;
    u32 nvid = 135;
    u8  data[320] = {0};
    u8  new_data[320] = {0};
    u32 i = 1;
    u32 j = 0;

    while(++i)
    {
        j = i/320;
        osl_sem_down(&g_read_write_task_sem);
        nv_taskdelay(1);
        nv_printf("\n****************第%d次测试开始**************************\n", i);

        ret = bsp_nvm_read(nvid, data, 320);
        if(ret)
        {
            nv_printf("read fail ,ret = 0x%x\n", ret);
            return;
        }
        data[j]++;
        ret = bsp_nvm_write(nvid, data, 320);
        if(ret)
        {
            nv_printf("write fail ,ret = 0x%x\n", ret);
            return;
        }
        ret = bsp_nvm_reload();
        if(ret)
        {
            nv_printf("load nv fail\n");
            return;
        }

        ret = bsp_nvm_read(nvid, new_data, 320);
        if(ret)
        {
            nv_printf("read fail ,ret = 0x%x\n", ret);
            return;
        }
        if(data[j] != new_data[j])
        {
            nv_printf("write nv value fail\n");
            return;
        }
        if((0 == g_read_write_count)||(i < g_read_write_count))
        {
            osl_sem_up(&g_read_write_task_sem);
        }
        else
        {
            i = 0;
        }
    }
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
