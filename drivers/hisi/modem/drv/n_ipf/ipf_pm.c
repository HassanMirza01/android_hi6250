#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/syscore_ops.h>
#include <bsp_ipc.h>
#include <n_bsp_ipf.h>
#include <n_bsp_psam.h>
#include <bsp_slice.h>
#include <bsp_pm_om.h>
#include "ipf_balong.h"

extern ipf_ctx_t g_ipf_ctx;

const unsigned int ipf_save_table[] =
{
    HI_IPF_CTRL_OFFSET,
    HI_IPF_GATE_OFFSET,
    HI_IPF_DMA_CTRL1_OFFSET,
    HI_IPF_EF_BADDR_OFFSET,
    HI_IPF_CH0_CTRL_OFFSET,
    HI_IPF_CH1_CTRL_OFFSET,		
    HI_IPF_CH0_BDQ_SIZE_OFFSET,
    HI_IPF_CH1_BDQ_SIZE_OFFSET,
    HI_IPF_CH0_RDQ_SIZE_OFFSET,
    HI_IPF_CH1_RDQ_SIZE_OFFSET,
    HI_IPF_CH0_BDQ_BADDR_OFFSET,
    HI_IPF_CH1_BDQ_BADDR_OFFSET,
    HI_IPF_CH0_RDQ_BADDR_OFFSET,
    HI_IPF_CH1_RDQ_BADDR_OFFSET,
    HI_IPF_CH0_ADQ0_BASE_OFFSET, 
    HI_IPF_CH0_ADQ1_BASE_OFFSET,
    HI_IPF_CH1_ADQ0_BASE_OFFSET,  
    HI_IPF_CH1_ADQ1_BASE_OFFSET, 
    HI_IPF_TIME_OUT_OFFSET,
    HI_IPF_PKT_LEN_OFFSET,
    HI_IPF_CH0_ADQ0_RPTR_OFFSET, 
    HI_IPF_CH0_ADQ1_RPTR_OFFSET, 
    HI_IPF_CH1_ADQ0_RPTR_OFFSET, 
    HI_IPF_CH1_ADQ1_RPTR_OFFSET, 
    HI_IPF_CH0_ADQ0_STAT_OFFSET, 
    HI_IPF_CH0_ADQ1_STAT_OFFSET, 
    HI_IPF_CH1_ADQ0_STAT_OFFSET, 
    HI_IPF_CH1_ADQ1_STAT_OFFSET,
    HI_IPF_CH0_ADQ0_WPTR_OFFSET, 
    HI_IPF_CH0_ADQ1_WPTR_OFFSET, 
    HI_IPF_CH1_ADQ0_WPTR_OFFSET, 
    HI_IPF_CH1_ADQ1_WPTR_OFFSET, 
    HI_IPF_CH0_ADQ_CTRL_OFFSET,
    HI_IPF_CH1_ADQ_CTRL_OFFSET,
    HI_IPF_INT_MASK0_OFFSET,
    HI_IPF_INT_MASK1_OFFSET,		
    HI_IPF_CH_EN_OFFSET,
    HI_IPF_MST_REGION0_START_OFFSET,
	HI_IPF_MST_REGION0_END_OFFSET,
	HI_IPF_MST_REGION1_START_OFFSET,
	HI_IPF_MST_REGION1_END_OFFSET,
	HI_IPF_MST_REGION2_START_OFFSET,
	HI_IPF_MST_REGION2_END_OFFSET,
	HI_IPF_MST_REGION3_START_OFFSET,
	HI_IPF_MST_REGION3_END_OFFSET,
	HI_IPF_MST_DEFAULT_ADDR_OFFSET,
	HI_IPF_MST_SECCTRL_OFFSET,
};

#ifdef CONFIG_PM

static int _ipf_reg_save(void)
{
	unsigned int reg;
    int i = 0;

    struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();

	// disable ch0 adq
	UPDATE1(reg,	HI_IPF_CH0_ADQ_CTRL,
			ul_adq_en,	0);

#ifndef CONFIG_PSAM
    // disable ch1 adq
	UPDATE1(reg,	HI_IPF_CH1_ADQ_CTRL,
			ul_adq_en,	0);
#endif
    
    for(i=0; i<sizeof(ipf_save_table)/sizeof(ipf_save_table[0]); i++)
    {
       sm->reg_save[i] = ipf_readl(ipf_save_table[i]);
    }
    
    return IPF_SUCCESS;
}

static int _ipf_reg_load(void)
{
    int i=0;
    
    struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();

    for(i=0; i<sizeof(ipf_save_table)/sizeof(ipf_save_table[0]); i++)
    {
       ipf_writel(sm->reg_save[i],ipf_save_table[i]);
    }

    return 0;
}

static int _ipf_filter_load(void)
{
    int i;
	filter_map* map;
    struct ipf_filter_handler* fh = g_ipf_ctx.filter_handler;
    struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();
    

    for(i=0;i<IPF_MODEM_MAX;i++)
    {
        map = fh->launched[i];
        while(map)
        {
            if(map->index>=fh->bf_num)
                break;
            fh->basic_write(map->index, &sm->filter[i]);
            map = map->next;
        }
    }

    return 0;

}

static int ipf_pm_prepare_ex(struct device *pdev)
{
	unsigned int reg;
    HI_IPF_CH0_STATE_T state;

    struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();

    /* ÅÐ¶ÏÉÏÐÐIPFÊÇ·ñ¿ÕÏÐ */
    state.u32 = ipf_readl(HI_IPF_CH0_STATE_OFFSET);

    if(state.bits.ul_busy)
    {
        bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_IPF,"\r IPF CHANNEL NOT IDLE! \n");
        return IPF_ERROR;
    }

	UPDATE1(reg,	HI_IPF_CH_EN,
			ul_en,	0);

	sm->init.status.acore = IPF_PWR_PREPARED;

    return IPF_SUCCESS;
}

static int ipf_pm_suspend_ex(struct device *pdev)
{
    unsigned long ipf_flags = 0;
	struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();
	
    spin_lock_irqsave(&g_ipf_ctx.filter_spinlock, ipf_flags);
    bsp_ipc_spin_lock(IPC_SEM_IPF_PWCTRL);
    if(sm->init.status.save){   
        _ipf_reg_save();
    }
    sm->init.status.save++;
    sm->init.status.ccore=IPF_PWR_DOWN;
    cache_sync();
    bsp_ipc_spin_unlock(IPC_SEM_IPF_PWCTRL);
    spin_unlock_irqrestore(&g_ipf_ctx.filter_spinlock, ipf_flags);

    g_ipf_ctx.status->suspend++;
	return IPF_SUCCESS;
}

static int ipf_pm_resume_ex(struct device *pdev)
{
    unsigned int status;
	unsigned long ipf_flags = 0;
	unsigned int reg;
	HI_IPF_CH_EN_T* ch_en_p;
	struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();
	
    spin_lock_irqsave(&g_ipf_ctx.filter_spinlock, ipf_flags);
    bsp_ipc_spin_lock(IPC_SEM_IPF_PWCTRL);
    if(sm->init.status.save){
        sm->init.status.save=0;
        _ipf_reg_load();
        if(sm->rsracc){
            _ipf_filter_load();
        }
    }
    sm->init.status.acore=1;
    cache_sync();
    bsp_ipc_spin_unlock(IPC_SEM_IPF_PWCTRL);
    spin_unlock_irqrestore(&g_ipf_ctx.filter_spinlock, ipf_flags);
    
	status = ipf_readl(HI_IPF_INT0_OFFSET); 
	if (status & (IPF_UL_RPT_INT0 \
					| IPF_UL_TIMEOUT_INT0 \
					| IPF_UL_ADQ0_EPTY_INT0 \
					| IPF_UL_ADQ1_EPTY_INT0)) {
		g_ipf_ctx.status->resume_with_intr++;
	}
	reg = ipf_readl(HI_IPF_CH_EN_OFFSET);
	ch_en_p = (HI_IPF_CH_EN_T*)&reg;
    ch_en_p->bits.ul_en = 1;
	ipf_writel(reg,   HI_IPF_CH_EN_OFFSET);
    g_ipf_ctx.status->resume++;
	return IPF_SUCCESS;
}

struct dev_pm_ops ipf_dev_pm_ops={

    .prepare = ipf_pm_prepare_ex,
    .suspend_noirq = ipf_pm_suspend_ex,
    .resume_noirq = ipf_pm_resume_ex,

};
#endif


