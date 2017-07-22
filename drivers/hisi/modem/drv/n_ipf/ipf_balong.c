/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifdef __cplusplus
extern "C" {
#endif

#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/clk.h>
#include <linux/of.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/skbuff.h>
#include <bsp_slice.h>
#include <bsp_pm_om.h>
#include <linux/syscore_ops.h>
#include <bsp_ipc.h>
#include "osl_cache.h"
#include <bsp_ddr.h>
#include <n_bsp_psam.h>
#include <n_bsp_ipf.h>
#include <ipf_balong.h>
#include <bsp_reset.h>

ipf_ctx_t g_ipf_ctx;
extern struct dev_pm_ops ipf_dev_pm_ops;
#define DELAY_WAIT_CIPHER	2
static inline void ipf_record_start_time_stamp(unsigned int en, unsigned int* rec_point)
{
    if (!en) {
        return;
    }
    *rec_point = bsp_get_slice_value_hrt();
    return;
}

static inline void
ipf_record_end_time_stamp(unsigned int en, unsigned int beg_time)
{
    unsigned int diff_time;
    IPF_TIMESTAMP_INFO_S* stamp_info = &g_ipf_ctx.timestamp;
    int idx;

    if (!en) {
        return;
    }

    diff_time = bsp_get_slice_value_hrt() - beg_time;

    /* avoid to record the overflowed value */
    if (diff_time > IPF_MAX_TIME_LIMIT) {
        stamp_info->overflow++;
    }
    else {
        if (diff_time > stamp_info->diff_max)
            stamp_info->diff_max = diff_time;

        stamp_info->diff_sum += diff_time;
        stamp_info->cnt_sum++;

        /* find the first bit not zero */
        idx = ((fls((int)diff_time)-1) & IPF_FLS_MASK);
        stamp_info->diff_order_cnt[idx]++;
    }
}

static inline
unsigned int ipf_calc_percent(unsigned int value, unsigned int sum)
{
    if (0 == sum) {
        return 0;
    }
    return (value * 100 / sum);
}

static void ipf_get_version(void)
{
	unsigned int ver;
	ver = ipf_readl(HI_IPF_VERSION_OFFSET);
	printk(" ipf version is 0x%x\n", ver);
	switch(ver){
	case IPF_VER_120A:
		g_ipf_ctx.ipf_version = IPF_VERSION_120a;
		break;
	case IPF_VER_130A:
		g_ipf_ctx.ipf_version = IPF_VERSION_130a;
		break;
	case IPF_VER_130B:
		g_ipf_ctx.ipf_version = IPF_VERSION_130b;
		break;
	case IPF_VER_140A:
		g_ipf_ctx.ipf_version = IPF_VERSION_140a;
		break;
    case IPF_VER_150A:
        g_ipf_ctx.ipf_version = IPF_VERSION_150a;
        break;
	default:
		g_ipf_ctx.ipf_version = IPF_VERSION_0000;
		break;
	}
}

static int ipf_get_limit_addr(void)
{
    struct memblock_type *type;
	phys_addr_t mem_start;
	phys_addr_t mem_end;
    unsigned int i;

	type = &memblock.memory;
	if(0 == type->cnt){
		dev_err(g_ipf_ctx.dev, "ipf limit addr not get\n");
		g_ipf_ctx.limit_addr->block_err = 1;
		return BSP_ERR_IPF_INVALID_PARA;
	}

    mem_start = type->regions[0].base;
	mem_end = type->regions[type->cnt-1].base + type->regions[type->cnt-1].size;

    *(g_ipf_ctx.memblock_show) = type->cnt;
    for(i=0; i < type->cnt; i++){
        *(g_ipf_ctx.memblock_show + i + 1) = (unsigned int)(type->regions[i].base);
        if(mem_start > type->regions[i].base){
            mem_start = type->regions[i].base;
        }
        
        if(mem_end < (type->regions[i].base + type->regions[i].size)){
            mem_end = type->regions[i].base + type->regions[i].size;
        }
    }

    if(mem_end > (phys_addr_t)0xffffffff){
        mem_end = (phys_addr_t)0xffffffff;
    }
    
	if((MODEM_START_ADDR >= mem_start) && ((MODEM_START_ADDR + MODEM_START_SIZE) <= mem_end)){
		g_ipf_ctx.limit_addr->block_sum 		=2;
		g_ipf_ctx.limit_addr->block1_start 		=(unsigned int)mem_start;
		g_ipf_ctx.limit_addr->block1_end		=MODEM_START_ADDR;
		g_ipf_ctx.limit_addr->block2_start 		=MODEM_START_ADDR + MODEM_START_SIZE;
		g_ipf_ctx.limit_addr->block2_end		=(unsigned int)mem_end;
	}
	else{
		g_ipf_ctx.limit_addr->block_sum 		=1;
		g_ipf_ctx.limit_addr->block1_start 		=(unsigned int)mem_start;
		g_ipf_ctx.limit_addr->block1_end		=(unsigned int)mem_end;
	}

	return 0;
}

static void ipf_dl_job_done_cb(void){
	if(g_ipf_ctx.dl_info.pFnDlIntCb)
		g_ipf_ctx.dl_info.pFnDlIntCb();
}

static void ipf_dl_ads_empty_cb(void){
    if(g_ipf_ctx.dl_info.pAdqEmptyDlCb)
        g_ipf_ctx.dl_info.pAdqEmptyDlCb(IPF_EMPTY_ADQ0);
}

static void ipf_dl_adl_empty_cb(void){
    if(g_ipf_ctx.dl_info.pAdqEmptyDlCb)
        g_ipf_ctx.dl_info.pAdqEmptyDlCb(IPF_EMPTY_ADQ1);
}

static void ipf_ul_bd_empty_cb(void){
    if(g_ipf_ctx.ul_info.handle_bd_empty)
        g_ipf_ctx.ul_info.handle_bd_empty();
}

static void ipf_mst_sec_rd_err_cb(void){
	struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();
	
    disable_irq_nosync(g_ipf_ctx.irq);
	IPF_PRINT("ipf sec rd err\n");
	system_error(DRV_ERRNO_IPF_OUT_REG, 0, 0, (char*)sm->uad0, IPF_ULAD0_MEM_SIZE + IPF_ULAD1_MEM_SIZE);
}

static void ipf_mst_sec_wr_err_cb(void){
	struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();
	
    disable_irq_nosync(g_ipf_ctx.irq);
	IPF_PRINT("ipf sec wr err\n");
	system_error(DRV_ERRNO_IPF_OUT_REG, 0, 0, (char*)sm->uad0, IPF_ULAD0_MEM_SIZE + IPF_ULAD1_MEM_SIZE);
}

struct int_handler ipf_int_table[32] = {
		{"ul_rpt_int1",                 0,  NULL},                  /* [0..0] 上行结果上报中断1 */
		{"ul_timeout_int1",             0,  NULL},                  /* [1..1] 上行结果上报超时中断1 */
		{"ul_disable_end_int1",         0,  NULL},                  /* [2..2] 上行通道关闭完成中断1 */
		{"ul_idle_cfg_bd_int1",         0,  NULL},                  /* [3..3] 上行通道IDLE期间软件配置BD指示中断1 */
		{"ul_trail_cfg_bd_int1",        0,  NULL},                  /* [4..4] 上行通道关闭但BD没有处理完期间软件继续配置BD指示中断1 */
		{"ul_noidle_clrptr_int1",       0,  NULL},                  /* [5..5] 上行非IDLE态清指针指示中断1 */
		{"ul_rdq_downoverflow_int1",    0,  NULL},                  /* [6..6] 上行RDQ下溢中断1 */
		{"ul_bdq_upoverflow_int1",      0,  NULL},                  /* [7..7] 上行BDQ上溢中断1 */
		{"ul_rdq_full_int1",            0,  NULL},                  /* [8..8] 上行RDQ满中断1 */
		{"ul_bdq_epty_int1",            0,  ipf_ul_bd_empty_cb},  	/* [9..9] 上行BDQ空中断1 */
		{"ul_adq0_epty_int1",           0,  NULL},                  /* [10..10] 上行ADQ0空中断1 */
		{"ul_adq1_epty_int1",           0,  NULL},                  /* [11..11] 上行ADQ1空中断1 */
		{"reserved_1",                  0,  NULL},                  /* [15..12] 保留 */
		{"reserved_1",                  0,  NULL},                  /* [15..12] 保留 */
		{"reserved_1",                  0,  NULL},                  /* [15..12] 保留 */
		{"reserved_1",                  0,  NULL},                  /* [15..12] 保留 */
		{"dl_rpt_int1",                 0,  ipf_dl_job_done_cb},	/* [16..16] 下行结果上报中断1 */
		{"dl_timeout_int1",             0,  ipf_dl_job_done_cb},	/* [17..17] 下行结果上报超时中断1 */
		{"dl_disable_end_int1",         0,  NULL},                  /* [18..18] 下行通道关闭完成中断1 */
		{"dl_idle_cfg_bd_int1",         0,  NULL},                  /* [19..19] 下行通道IDLE期间软件配置BD指示中断1 */
		{"dl_trail_cfg_bd_int1",        0,  NULL},                  /* [20..20] 下行通道关闭但BD没有处理完期间软件继续配置BD指示中断1 */
		{"dl_noidle_clrptr_int1",       0,  NULL},                  /* [21..21] 下行非IDLE态清指针指示中断1 */
		{"dl_rdq_downoverflow_int1",    0,  NULL},                  /* [22..22] 下行RDQ下溢中断1 */
		{"dl_bdq_upoverflow_int1",      0,  NULL},                  /* [23..23] 下行BDQ上溢中断1 */
		{"dl_rdq_full_int1",            0,  ipf_dl_job_done_cb},	/* [24..24] 下行RDQ满中断1 */
		{"dl_bdq_epty_int1",            0,  NULL},                  /* [25..25] 下行BDQ空中断1 */
		{"dl_adq0_epty_int1",           0,  ipf_dl_ads_empty_cb},	/* [26..26] 下行ADQ0空中断1 */
		{"dl_adq1_epty_int1",           0,  ipf_dl_adl_empty_cb},	/* [27..27] 下行ADQ1空中断1 */
		{"ipf_mst_sec_wr_err_int1",     0,  ipf_mst_sec_wr_err_cb},	/* [28..28] IPF MST写操作地址溢出中断1。 */
		{"ipf_mst_sec_rd_err_int1",     0,  ipf_mst_sec_rd_err_cb},	/* [29..29] IPF MST读操作地址溢出中断1。 */
		{"reserved_0",                  0,  NULL},                  /* [31..30] 保留。 */
		{"reserved_0",                  0,  NULL},                  /* [31..30] 保留。 */
};

static irqreturn_t ipf_interrupt(int irq, void* dev)
{
	int bit;
	unsigned int reg;

	reg = ipf_readl(HI_IPF_INT1_OFFSET);
	ipf_writel(reg, HI_IPF_INT_STATE_OFFSET);

	for_each_set_bit(bit,(unsigned long*)&reg, 32)
	{
		ipf_int_table[bit].cnt++;
		if(ipf_int_table[bit].callback){
		    ipf_int_table[bit].callback();
		}
	}
	
    return IRQ_HANDLED;
}

static void ipf_ctx_init(void)
{
	struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();

    g_ipf_ctx.ul_info.pstIpfBDQ = sm->ubd;
    g_ipf_ctx.ul_info.pstIpfRDQ = sm->urd;
    g_ipf_ctx.ul_info.pstIpfADQ0 = sm->uad0;
    g_ipf_ctx.ul_info.pstIpfADQ1 = sm->uad1;
    g_ipf_ctx.ul_info.pu32IdleBd = sm->idle;

    g_ipf_ctx.dl_info.pstIpfBDQ = sm->dbd;
    g_ipf_ctx.dl_info.pstIpfRDQ = sm->drd;
    g_ipf_ctx.dl_info.pstIpfADQ0 = sm->dad0;
    g_ipf_ctx.dl_info.pstIpfADQ1 = sm->dad1;
    g_ipf_ctx.dl_info.pstIpfCDQ = sm->dcd;

    g_ipf_ctx.dl_info.pstIpfPhyBDQ = (ipf_bd_s*)(SHD_DDR_V2P((void *)sm->dbd));
    g_ipf_ctx.dl_info.pstIpfPhyRDQ = (ipf_rd_s*)(SHD_DDR_V2P((void *)sm->drd));
    g_ipf_ctx.dl_info.pstIpfPhyADQ0 = (ipf_ad_s*)(SHD_DDR_V2P((void *)sm->dad0));
	g_ipf_ctx.dl_info.pstIpfPhyADQ1 = (ipf_ad_s*)(SHD_DDR_V2P((void *)sm->dad1));
    g_ipf_ctx.dl_info.u32IpfCdRptr = &sm->dcd_rptr;
    *(g_ipf_ctx.dl_info.u32IpfCdRptr) = 0;

	g_ipf_ctx.share_mem = sm;
}

static void ipf_desc_init(void)
{
	unsigned int reg;
	
	/* 配置下行通道的AD、BD和RD深度 */
	UPDATE1(reg,	HI_IPF_CH1_BDQ_SIZE,
			dl_bdq_size,	IPF_DLBD_DESC_SIZE-1);

	UPDATE1(reg,	HI_IPF_CH1_RDQ_SIZE,
			dl_rdq_size,	IPF_DLRD_DESC_SIZE-1);

#ifdef CONFIG_PSAM
	UPDATE1(reg,	HI_IPF_CH1_ADQ_CTRL,
			dl_adq_en,	IPF_NONE_ADQ_EN);
#else
	UPDATE4(reg,	HI_IPF_CH1_ADQ_CTRL,
			dl_adq_en,	IPF_BOTH_ADQ_EN,
			dl_adq0_size_sel,	CONFIG_IPF_ADQ_LEN,
			dl_adq1_size_sel,	CONFIG_IPF_ADQ_LEN,
			dl_adq_plen_th,	IPF_ULADQ_PLEN_TH);
#endif

	/*下行通道的BD和RD起始地址*/
	UPDATE1(reg, HI_IPF_CH1_BDQ_BADDR,
			dl_bdq_baddr,	(unsigned int)(unsigned long)g_ipf_ctx.dl_info.pstIpfPhyBDQ);
	UPDATE1(reg, HI_IPF_CH1_RDQ_BADDR,
			dl_rdq_baddr,	(unsigned int)(unsigned long)g_ipf_ctx.dl_info.pstIpfPhyRDQ);
	UPDATE1(reg, HI_IPF_CH1_ADQ0_BASE,
			dl_adq0_base,	(unsigned int)(unsigned long)g_ipf_ctx.dl_info.pstIpfPhyADQ0);
	UPDATE1(reg, HI_IPF_CH1_ADQ1_BASE,
			dl_adq1_base,	(unsigned int)(unsigned long)g_ipf_ctx.dl_info.pstIpfPhyADQ1);
	
}

int ipf_init(void)
{
	int ret;
	struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();
	
    memset((void*)sm->dbd, 0x0, IPF_DLDESC_SIZE);
   	ipf_ctx_init();

    #ifndef CONFIG_IPF_PROPERTY_MBB
    spin_lock_init(&g_ipf_ctx.filter_spinlock);
    #endif

    ipf_desc_init();

	g_ipf_ctx.irq_hd = ipf_int_table;
	ret = request_irq(g_ipf_ctx.irq, ipf_interrupt, IRQF_SHARED, "ipf", g_ipf_ctx.dev);
	if(0 != ret) {
		dev_err(g_ipf_ctx.dev, "request irq failed\n");
	}

    sm->init.status.modem = IPF_FORRESET_CONTROL_ALLOW;

    if(0 != mdrv_sysboot_register_reset_notify("IPF_BALONG",bsp_ipf_reset_ccore_cb, 0, DRV_RESET_CB_PIOR_IPF))
    {
    	dev_err(g_ipf_ctx.dev, "set modem reset call back func failed\n");
    }

	/*acore use first block,ccore use scnd block*/
	g_ipf_ctx.status = (struct ipf_debug*)&sm->debug[1] ;
	memset(g_ipf_ctx.status, 0, sizeof(struct ipf_debug));

	ipf_get_version();
    g_ipf_ctx.status->init_ok = IPF_ACORE_INIT_SUCCESS;
    g_ipf_ctx.modem_status = IPF_FORRESET_CONTROL_ALLOW;
	g_ipf_ctx.ccore_rst_idle = 0;

	dev_err(g_ipf_ctx.dev, "ipf init success\n");

	return 0;
}

void bsp_ipf_set_debug_para(void ** psam_get_debug)
{
	*(psam_get_debug) = (void *)(g_ipf_ctx.status);
}

int bsp_ipf_srest(void)
{
	unsigned int reg;
	int tmp_cnt = 10000;
	
	/*reset*/
	UPDATE1(reg,	HI_IPF_SRST,
			ipf_srst,	1);

	while(!ipf_readl(HI_IPF_SRST_STATE_OFFSET)){
		tmp_cnt--;
		if(!tmp_cnt){
			return -1;
		}
	}

	ipf_writel(IPF_INT_OPEN0, HI_IPF_INT_MASK0_OFFSET);
    ipf_writel(IPF_INT_OPEN1, HI_IPF_INT_MASK1_OFFSET);
	return 0;
}

int bsp_ipf_config_timeout(unsigned int u32Timeout)
{
	unsigned int reg;

    if((u32Timeout == 0) || (u32Timeout > 0xFFFF))
    {
    	dev_err(g_ipf_ctx.dev, "%s para invalid\n", __func__);
        return BSP_ERR_IPF_INVALID_PARA;
    }

	UPDATE2(reg,	HI_IPF_TIME_OUT,
			time_out_cfg,	u32Timeout,
			time_out_valid,	1);

    return IPF_SUCCESS;
}

int bsp_ipf_set_pktlen(unsigned int u32MaxLen, unsigned int u32MinLen)
{
	unsigned int reg;

    /* 参数检查 */
    if(u32MaxLen < u32MinLen)
    {
    	dev_err(g_ipf_ctx.dev, "%s para invalid\n", __func__);
        return BSP_ERR_IPF_INVALID_PARA;
    }

	UPDATE2(reg,HI_IPF_PKT_LEN,
			min_pkt_len,	u32MinLen,
			max_pkt_len,	u32MaxLen);
	
    return IPF_SUCCESS;
}

void bsp_set_init_status(int stat)
{
    g_ipf_ctx.status->init_ok = stat;    
}

int bsp_get_init_status(void)
{
    return g_ipf_ctx.status->init_ok;    
}

void mdrv_ipf_reinit_dlreg(void)
{
	struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();
	
    memset((void*)sm->dbd, 0x0, IPF_DLBD_DESC_SIZE);

    ipf_ctx_init();
	
    ipf_desc_init();
	
#ifdef CONFIG_PSAM
	psam_reinit_regs();
#endif

    g_ipf_ctx.status->init_ok = IPF_ACORE_INIT_SUCCESS;

    dev_err(g_ipf_ctx.dev, "ipf dl register reinit success\n");

    return;

}
#ifndef CONFIG_PSAM
int bsp_ipf_get_used_dlad(IPF_AD_TYPE_E eAdType, unsigned int * pu32AdNum, IPF_AD_DESC_S * pstAdDesc)
{
	unsigned int u32Timeout = 10;
	unsigned int u32DlStateValue;
	unsigned int u32FreeAdNum = 0;
	unsigned int u32ADQwptr;
	unsigned int u32ADQrptr;
	unsigned int reg;

	/*入参检测*/
	if((NULL == pu32AdNum)||(NULL == pstAdDesc))
	{
		bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_IPF,"\r BSP_IPF_ConfigDlAd input para ERROR!NULL == pu32AdNum or NULL == pstAdDesc\n");
		return BSP_ERR_IPF_INVALID_PARA;
	}
	/*关闭下行AD配置接口*/
	if (g_ipf_ctx.status) {
		g_ipf_ctx.status->init_ok = 0;
	}
	/*等待通道idle ,200ms超时*/
	do
	{
		u32DlStateValue = ipf_readl(HI_IPF_CH1_STATE_OFFSET);
		if(u32DlStateValue == IPF_CHANNEL_STATE_IDLE)
		{
			break;
		}
		msleep(20);
	}while(--u32Timeout);
	
	if (!u32Timeout)
	{
		bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_IPF,"\r After 20ms IPF dl channel still on, unable to free AD \n");
		return IPF_ERROR;
	}
	/*尝试关闭下行通道*/
	UPDATE1(reg,	HI_IPF_CH_EN,
			dl_en,	0);

	/*关闭AD，用于防止产生ADQ预取*/
	UPDATE1(reg,	HI_IPF_CH1_ADQ_CTRL,
			dl_adq_en,	0);

	if(IPF_AD_0 == eAdType)
	{
		/*回退AD读指针*/
		u32ADQwptr = ipf_readl(HI_IPF_CH1_ADQ0_WPTR_OFFSET);
		u32ADQrptr = ipf_readl(HI_IPF_CH1_ADQ0_RPTR_OFFSET);
		while(u32ADQrptr != u32ADQwptr)
		{
			pstAdDesc->u32OutPtr1 = g_ipf_ctx.dl_info.pstIpfADQ0[u32ADQrptr].u32OutPtr1;
			pstAdDesc->u32OutPtr0 = g_ipf_ctx.dl_info.pstIpfADQ0[u32ADQrptr].u32OutPtr0;
			u32ADQrptr = ((u32ADQrptr + 1) < IPF_DLAD0_DESC_SIZE)? (u32ADQrptr + 1) : 0;
			pstAdDesc++;
			u32FreeAdNum++;
		}
	}
	else if(IPF_AD_1 == eAdType)
	{
		/*回退AD读指针*/
		u32ADQwptr = ipf_readl(  HI_IPF_CH1_ADQ1_WPTR_OFFSET);
		u32ADQrptr = ipf_readl(  HI_IPF_CH1_ADQ1_RPTR_OFFSET);
		while(u32ADQrptr != u32ADQwptr)
		{
			pstAdDesc->u32OutPtr1 = g_ipf_ctx.dl_info.pstIpfADQ1[u32ADQrptr].u32OutPtr1;
			pstAdDesc->u32OutPtr0 = g_ipf_ctx.dl_info.pstIpfADQ1[u32ADQrptr].u32OutPtr0;
			u32ADQrptr = ((u32ADQrptr + 1) < IPF_DLAD1_DESC_SIZE)? (u32ADQrptr + 1) : 0;
			pstAdDesc++;
			u32FreeAdNum++;
		}
	}
	else
	{
		bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_IPF,"\r BSP_IPF_ConfigDlAd input para ERROR! u32AdType >= IPF_AD_MAX\n");
		return BSP_ERR_IPF_INVALID_PARA;
	}
	/*返回AD*/
	*pu32AdNum = u32FreeAdNum;
	return IPF_SUCCESS;

}
#endif
int mdrv_ipf_get_used_dlad(IPF_AD_TYPE_E eAdType, unsigned int * pu32AdNum, IPF_AD_DESC_S * pstAdDesc)
{	
#ifdef CONFIG_PSAM
	return bsp_psam_get_used_dlad(eAdType, pu32AdNum, pstAdDesc);
#else
	return bsp_ipf_get_used_dlad(eAdType, pu32AdNum, pstAdDesc);
#endif
}

void bsp_ipf_set_control_flag_for_ccore_reset(IPF_FORRESET_CONTROL_E eResetFlag)
{
#ifndef CONFIG_IPF_PROPERTY_MBB
        struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();
#endif
    /*设置标志，终止上行数传*/
    g_ipf_ctx.modem_status = eResetFlag;
#ifndef CONFIG_IPF_PROPERTY_MBB
    /*设置标志，终止下行数传*/
    sm->init.status.modem = eResetFlag;
#endif
    cache_sync();
}

int bsp_ipf_reset_ccore_cb(DRV_RESET_CB_MOMENT_E eparam, int userdata)
{
	unsigned int u32Timeout = 30;
	unsigned int idle_cnt = 10;
	unsigned int time_out = 2000;
	unsigned int u32DlStateValue;
	int psam_status = 0;

	(void)userdata;
	
	if(MDRV_RESET_CB_BEFORE == eparam)
	{
		bsp_ipf_set_control_flag_for_ccore_reset(IPF_FORRESET_CONTROL_FORBID);

		if(g_ipf_ctx.ipf_version >= IPF_VERSION_130b){
			do{
				udelay(DELAY_WAIT_CIPHER);	//wait cipher idle
				u32DlStateValue = ipf_readl(HI_IPF_CH1_STATE_OFFSET);
				psam_status = bsp_psam_idle();
				time_out--;
				if((u32DlStateValue == IPF_CHANNEL_STATE_IDLE) && psam_status){
					idle_cnt--;
				}else{
					idle_cnt = 10;
				}
			}while(idle_cnt && time_out);

			if(!idle_cnt){
				g_ipf_ctx.ccore_rst_idle = 1;
			}

			if (!time_out)
			{
				bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_IPF,
					"\r IPF dl channel on after bsp_ipf_reset_ccore_cb called \n");
			}
		}
		else{
		    do
		    {
    			u32DlStateValue = ipf_readl(  HI_IPF_CH1_STATE_OFFSET);
    			if(u32DlStateValue == IPF_CHANNEL_STATE_IDLE)
    			{
    				break;
    			}
				msleep(10);
			}while(--u32Timeout);
			if (!u32Timeout)
			{
				bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_IPF,
					"\r IPF dl channel on after bsp_ipf_reset_ccore_cb called \n");
			}else{
				g_ipf_ctx.ccore_rst_idle = 1;
			}
		}
	}
	else if(MDRV_RESET_CB_AFTER == eparam)
	{
		g_ipf_ctx.ccore_rst_idle = 0;
		bsp_ipf_set_control_flag_for_ccore_reset(IPF_FORRESET_CONTROL_ALLOW);
		return IPF_SUCCESS;
	}
	else
	{
		/*under the requeset of yaoguocai*/
		return IPF_SUCCESS;
	}
	return IPF_SUCCESS;
}

#ifndef CONFIG_PSAM
int ipf_config_dl_ad(unsigned int u32AdType, unsigned int  u32AdNum, IPF_AD_DESC_S * pstAdDesc)
{
	unsigned int u32ADQwptr = 0;
	struct tagIPF_AD_DESC_S * pstADDesc = pstAdDesc;
	IPF_DL_S* dl_ad = &g_ipf_ctx.dl_info;
	unsigned int i;

	g_ipf_ctx.status->cfg_ad_times++;
	if(NULL == pstAdDesc || u32AdType >= IPF_AD_MAX)
	{
		pr_err("%s para invalid\n", __func__);
		g_ipf_ctx.status->invalid_para++;
		return BSP_ERR_IPF_INVALID_PARA;
	}

	/* 检查模块是否初始化 */
	if(g_ipf_ctx.status && (IPF_ACORE_INIT_SUCCESS != g_ipf_ctx.status->init_ok))
	{
		g_ipf_ctx.status->mdrv_called_not_init++;
		pr_err("%s ipf not init\n", __func__);
		return BSP_ERR_IPF_NOT_INIT;
	}


	if(IPF_AD_0 == u32AdType)
	{
		if(u32AdNum >= IPF_DLAD0_DESC_SIZE)
		{
			pr_err("%s too much short ad num\n", __func__);
			g_ipf_ctx.status->invalid_para++;
			return BSP_ERR_IPF_INVALID_PARA;
		}

		/*读出写指针*/
		u32ADQwptr = ipf_readl(  HI_IPF_CH1_ADQ0_WPTR_OFFSET);
		for(i=0; i < u32AdNum; i++)
		{
			if(0 == pstADDesc->u32OutPtr1)
			{
				pr_err("%s the %d short ad outptr is null\n", __func__, i);
				g_ipf_ctx.status->ad_out_ptr_null[IPF_AD_0]++;
				return BSP_ERR_IPF_INVALID_PARA;
			}
			dl_ad->pstIpfADQ0[u32ADQwptr].u32OutPtr1 = pstADDesc->u32OutPtr1;
			dl_ad->pstIpfADQ0[u32ADQwptr].u32OutPtr0 = pstADDesc->u32OutPtr0;
			u32ADQwptr = ((u32ADQwptr + 1) < IPF_DLAD0_DESC_SIZE)? (u32ADQwptr + 1) : 0;
			pstADDesc++;
		}
		g_ipf_ctx.status->cfg_ad_cnt[IPF_AD_0] += u32AdNum;
		/* 更新AD0写指针*/
		ipf_writel(u32ADQwptr, HI_IPF_CH1_ADQ0_WPTR_OFFSET);
	}
	else if(IPF_AD_1 == u32AdType)
	{
		if(u32AdNum >= IPF_DLAD1_DESC_SIZE)
		{
			pr_err("%s too much long ad num\n", __func__);
			g_ipf_ctx.status->invalid_para++;
			return BSP_ERR_IPF_INVALID_PARA;
		}

		/*读出写指针*/
		u32ADQwptr = ipf_readl(  HI_IPF_CH1_ADQ1_WPTR_OFFSET);
		for(i=0; i < u32AdNum; i++)
		{
			if(0 == pstADDesc->u32OutPtr1)
			{
				pr_err("%s the %d long ad outptr is null\n", __func__, i);
				g_ipf_ctx.status->ad_out_ptr_null[IPF_AD_1]++;
				return BSP_ERR_IPF_INVALID_PARA;
			}

			dl_ad->pstIpfADQ1[u32ADQwptr].u32OutPtr1 = pstADDesc->u32OutPtr1;
			dl_ad->pstIpfADQ1[u32ADQwptr].u32OutPtr0 = pstADDesc->u32OutPtr0;
			u32ADQwptr = ((u32ADQwptr + 1) < IPF_DLAD1_DESC_SIZE)? (u32ADQwptr + 1) : 0;
			pstADDesc++;
		}
		g_ipf_ctx.status->cfg_ad_cnt[IPF_AD_1] += u32AdNum;

		/* 更新AD1写指针*/
		ipf_writel(u32ADQwptr, HI_IPF_CH1_ADQ1_WPTR_OFFSET);
	}
	return IPF_SUCCESS;
}
#endif
int ipf_register_wakeup_dlcb(BSP_IPF_WakeupDlCb pFnWakeupDl)
{
    /* 参数检查 */
    if(NULL == pFnWakeupDl)
    {
    	g_ipf_ctx.status->invalid_para++;
    	pr_err("%s invalid para\n", __func__);
        return BSP_ERR_IPF_INVALID_PARA;
    }
    g_ipf_ctx.dl_info.pFnDlIntCb = pFnWakeupDl;
    return IPF_SUCCESS;
}

int ipf_register_ul_bd_empty(ipf_bd_empty bd_handle)
{
   if(NULL == bd_handle)
    {
    	g_ipf_ctx.status->invalid_para++;
    	pr_err("%s invalid para\n", __func__);
        return BSP_ERR_IPF_INVALID_PARA;
    }
    g_ipf_ctx.ul_info.handle_bd_empty = bd_handle;
	return 0;
}
#ifndef CONFIG_PSAM
int ipf_register_adq_empty_dlcb(BSP_IPF_AdqEmptyDlCb pAdqEmptyDl)
{
    /* 参数检查 */
    if(NULL == pAdqEmptyDl)
    {
    	g_ipf_ctx.status->invalid_para++;
    	pr_err("%s invalid para\n", __func__);
        return IPF_ERROR;
    }
    g_ipf_ctx.dl_info.pAdqEmptyDlCb = pAdqEmptyDl;
    return IPF_SUCCESS;
}
#endif
int ipf_rd_rate(unsigned int enable, IPF_CHANNEL_TYPE_E eChnType)
{
	unsigned int rate = 0;
	int rd_len = 0;
	unsigned int rd_ts =  0;
	unsigned int ratio = IPF_LEN_RATIO / (IPF_TIMER_RATIO * 8);

	if(!enable) {
		return IPF_ERROR;
	}

	switch(eChnType)
    {
		case IPF_CHANNEL_DOWN:
			rd_ts =  bsp_get_slice_value() - g_ipf_ctx.status->rd_ts;
			if(rd_ts < IPF_RD_TMOUT) {
				return IPF_ERROR;
			}

			rd_len = g_ipf_ctx.status->rd_len_update - g_ipf_ctx.status->rd_len;
			g_ipf_ctx.status->rd_ts = bsp_get_slice_value();
			g_ipf_ctx.status->rd_len = g_ipf_ctx.status->rd_len_update;
			break;
		default:
            break;
	}

	if(rd_len <= 0 || rd_ts <= 0) {
		IPF_PRINT("ipf rd len or ts err!\n");
		return IPF_ERROR;
	} else {
		rate = rd_len / (rd_ts * ratio);
		IPF_PRINT("ipf rd rate:%uMbps\n", rate);
	}

	return IPF_SUCCESS;
}

unsigned int mdrv_ipf_get_ulbd_num(void)
{
    unsigned int u32IdleBd;
    HI_IPF_CH0_DQ_DEPTH_T dq_depth;

	g_ipf_ctx.status->get_bd_num_times++;
	
    dq_depth.u32 = ipf_readl(HI_IPF_CH0_DQ_DEPTH_OFFSET);
    u32IdleBd = IPF_ULBD_DESC_SIZE - (dq_depth.bits.ul_bdq_depth);
    *(g_ipf_ctx.ul_info.pu32IdleBd) = u32IdleBd;

    if(0 == u32IdleBd)
	{
		g_ipf_ctx.status->bd_full++;
	}
    return u32IdleBd;
}

unsigned int mdrv_ipf_get_ulrd_num(void)
{
    HI_IPF_CH0_DQ_DEPTH_T dq_depth;

    dq_depth.u32 = ipf_readl(HI_IPF_CH0_DQ_DEPTH_OFFSET);
    return dq_depth.bits.ul_rdq_depth;
}

unsigned int mdrv_ipf_get_uldesc_num(void)
{
	return mdrv_ipf_get_ulbd_num();
}

int mdrv_ipf_config_ulbd(unsigned int u32Num, IPF_CONFIG_ULPARAM_S* pstUlPara)
{
    IPF_CONFIG_ULPARAM_S* pstUlParam = pstUlPara;
    unsigned int u32BD;
    unsigned int i;
    ipf_desc_attr_t bd_attr;
    HI_IPF_CH0_BDQ_WPTR_T bdq_wptr;

	g_ipf_ctx.status->cfg_bd_times++;

    /* 参数检查 */
    if((NULL == pstUlPara)||(0 == u32Num))
    {
    	g_ipf_ctx.status->invalid_para++;
    	pr_err("%s para invalid\n", __func__);
        return BSP_ERR_IPF_INVALID_PARA;
    }

    /* 检查模块是否初始化 */
    if(g_ipf_ctx.status && (IPF_ACORE_INIT_SUCCESS != g_ipf_ctx.status->init_ok))
    {
		g_ipf_ctx.status->mdrv_called_not_init++;
		pr_err("%s ipf not init\n", __func__);
        return BSP_ERR_IPF_NOT_INIT;
    }

    /* 检查Ccore是否上电*/
    if(IPF_FORRESET_CONTROL_FORBID <= g_ipf_ctx.modem_status)
    {
       	g_ipf_ctx.status->mdrv_called_not_init++;
        return BSP_ERR_IPF_CCORE_RESETTING;
    }

    for(i = 0; i < u32Num; i++)
    {
        if(0 == pstUlParam[i].u16Len)
        {
        	pr_err("%s the %d bdlen is zero drop packet\n", __func__, i);
			g_ipf_ctx.status->bd_len_zero_err++;
            return BSP_ERR_IPF_INVALID_PARA;
        }
    }

    /* 读出BD写指针,将u32BdqWptr作为临时写指针使用 */
    bdq_wptr.u32 = ipf_readl(HI_IPF_CH0_BDQ_WPTR_OFFSET);
    u32BD = bdq_wptr.bits.ul_bdq_wptr;
    for(i = 0; i < u32Num; i++)
    {
        bd_attr.u16 = pstUlPara[i].u16Attribute;
        bd_attr.bits.cd_en = ipf_disable;
        g_ipf_ctx.ul_info.pstIpfBDQ[u32BD].u16Attribute = bd_attr.u16;
        g_ipf_ctx.ul_info.pstIpfBDQ[u32BD].u32InPtr = pstUlParam[i].u32Data;
        g_ipf_ctx.ul_info.pstIpfBDQ[u32BD].u16PktLen = pstUlParam[i].u16Len;
        g_ipf_ctx.ul_info.pstIpfBDQ[u32BD].u16UsrField1 = pstUlParam[i].u16UsrField1;
        g_ipf_ctx.ul_info.pstIpfBDQ[u32BD].u32UsrField2= pstUlParam[i].u32UsrField2;
        g_ipf_ctx.ul_info.pstIpfBDQ[u32BD].u32UsrField3 = pstUlParam[i].u32UsrField3;
        ipf_record_start_time_stamp(g_ipf_ctx.status->timestamp_en, &g_ipf_ctx.ul_info.pstIpfBDQ[u32BD].u32UsrField2);

        u32BD = ((u32BD + 1) < IPF_ULBD_DESC_SIZE)? (u32BD + 1) : 0;
    }

    /* 检查Ccore是否上电*/
    if(IPF_FORRESET_CONTROL_FORBID <= g_ipf_ctx.modem_status)
    {
    	g_ipf_ctx.status->mdrv_called_not_init++;
        return BSP_ERR_IPF_CCORE_RESETTING;
    }
	g_ipf_ctx.status->cfg_bd_cnt += u32Num;

    /* 更新BD写指针*/
    ipf_writel(u32BD, HI_IPF_CH0_BDQ_WPTR_OFFSET);
    return IPF_SUCCESS;
}
int mdrv_ipf_config_dlad(IPF_AD_TYPE_E eAdType, unsigned int u32AdNum, IPF_AD_DESC_S * pstAdDesc)
{
#ifdef CONFIG_PSAM
	return psam_config_dlad(eAdType, u32AdNum, pstAdDesc);
#else
	return ipf_config_dl_ad(eAdType, u32AdNum, pstAdDesc);
#endif
}

int mdrv_ipf_register_ops(struct mdrv_ipf_ops *ops)
{
	if(ops)
	{
		if(ipf_register_wakeup_dlcb(ops->rx_complete_cb)!= IPF_SUCCESS)
			return IPF_ERROR;
#ifdef CONFIG_PSAM
		if(psam_register_adq_empty_dlcb((adq_emtpy_cb_t)ops->adq_empty_cb)!= IPF_SUCCESS)
			return IPF_ERROR;
#else
		if(ipf_register_adq_empty_dlcb((BSP_IPF_AdqEmptyDlCb)ops->adq_empty_cb)!= IPF_SUCCESS)
			return IPF_ERROR;
#endif
	} else {
		pr_err("%s para invalid\n", __func__);
		g_ipf_ctx.status->invalid_para++;
		return IPF_ERROR;
	}
	return IPF_SUCCESS;
}

static inline void ipf_pm_print_packet(void *buf, size_t len)
{
	void *virt = buf;

	if (g_ipf_ctx.status->resume_with_intr){
		if (!virt_addr_valid(buf)){
			virt = phys_to_virt((unsigned long)buf);
			if(!virt_addr_valid(virt)){
				return;
			}
		}

		virt = (void *)(((struct sk_buff*)virt)->data);
		if (!virt_addr_valid(virt)){
			return;
		}
		
		if (len > MAX_PM_OM_SAVE_SIZE) {
			len = MAX_PM_OM_SAVE_SIZE;
		}
		
    	dma_unmap_single(g_ipf_ctx.dev, (dma_addr_t)virt_to_phys(virt), len, DMA_FROM_DEVICE);

		bsp_pm_log(PM_OM_AIPF, len, virt);

		print_hex_dump(KERN_INFO, "", DUMP_PREFIX_ADDRESS, 16, 1, virt, len, 0);

		g_ipf_ctx.status->resume_with_intr = 0;
	}
	return;
}

void mdrv_ipf_get_dlrd(unsigned int* pu32Num, IPF_RD_DESC_S *pstRd)
{
    unsigned int u32RdqRptr;
    unsigned int u32RdqDepth;
    unsigned int u32Num;
    unsigned int i;
    unsigned int u32CdqRptr;
    ipf_desc_attr_t rd_attr;
    HI_IPF_CH1_DQ_DEPTH_T dq_depth;

    /* 读取RD深度 */
    dq_depth.u32 = ipf_readl(HI_IPF_CH1_DQ_DEPTH_OFFSET);
    u32RdqDepth = dq_depth.bits.dl_rdq_depth;

	g_ipf_ctx.status->get_rd_times++;
	
    u32Num = (u32RdqDepth < *pu32Num)?u32RdqDepth:*pu32Num;
    if(0 == u32Num)
    {
        *pu32Num = 0;
        return;
    }

    u32RdqRptr = ipf_readl(HI_IPF_CH1_RDQ_RPTR_OFFSET);
    for(i = 0; i < u32Num; i++)
    {
        rd_attr.u16 = g_ipf_ctx.dl_info.pstIpfRDQ[u32RdqRptr].u16Attribute;
        pstRd[i].u16Attribute = g_ipf_ctx.dl_info.pstIpfRDQ[u32RdqRptr].u16Attribute;
        pstRd[i].u16PktLen = g_ipf_ctx.dl_info.pstIpfRDQ[u32RdqRptr].u16PktLen;
        pstRd[i].u16Result = g_ipf_ctx.dl_info.pstIpfRDQ[u32RdqRptr].u16Result;
        pstRd[i].u32InPtr = g_ipf_ctx.dl_info.pstIpfRDQ[u32RdqRptr].u32InPtr;
#ifdef CONFIG_PSAM
		pstRd[i].u32OutPtr = g_ipf_ctx.dl_info.pstIpfRDQ[u32RdqRptr].u32UsrField3;
#else
		pstRd[i].u32OutPtr = g_ipf_ctx.dl_info.pstIpfRDQ[u32RdqRptr].u32OutPtr;
#endif
        pstRd[i].u16UsrField1 = g_ipf_ctx.dl_info.pstIpfRDQ[u32RdqRptr].u16UsrField1;
        pstRd[i].u32UsrField2 = g_ipf_ctx.dl_info.pstIpfRDQ[u32RdqRptr].u32UsrField2;
        pstRd[i].u32UsrField3 = g_ipf_ctx.dl_info.pstIpfRDQ[u32RdqRptr].u32UsrField3;
        ipf_record_end_time_stamp(g_ipf_ctx.status->timestamp_en, g_ipf_ctx.dl_info.pstIpfRDQ[u32RdqRptr].u32UsrField2);
        if(ipf_enable == rd_attr.bits.cd_en){
            /* 更新CD读指针 */
        	u32CdqRptr = ((unsigned long)SHD_DDR_P2V((void *)(unsigned long)MDDR_FAMA(pstRd[i].u32InPtr)) - (unsigned long)g_ipf_ctx.dl_info.pstIpfCDQ)/sizeof(ipf_cd_s);

            while(g_ipf_ctx.dl_info.pstIpfCDQ[u32CdqRptr].u16Attribute != 1)
            {
                /* 将释放的CD  清0 */
                g_ipf_ctx.dl_info.pstIpfCDQ[u32CdqRptr].u16Attribute = 0;
                g_ipf_ctx.dl_info.pstIpfCDQ[u32CdqRptr].u16PktLen = 0;
                g_ipf_ctx.dl_info.pstIpfCDQ[u32CdqRptr].u32Ptr = 0;
                u32CdqRptr = ((u32CdqRptr+1) < IPF_DLCD_DESC_SIZE)?(u32CdqRptr+1):0;
            }
            g_ipf_ctx.dl_info.pstIpfCDQ[u32CdqRptr].u16Attribute = 0;
            g_ipf_ctx.dl_info.pstIpfCDQ[u32CdqRptr].u16PktLen = 0;
            g_ipf_ctx.dl_info.pstIpfCDQ[u32CdqRptr].u32Ptr = 0;
            u32CdqRptr = ((u32CdqRptr+1) < IPF_DLCD_DESC_SIZE)?(u32CdqRptr+1):0;
            *(g_ipf_ctx.dl_info.u32IpfCdRptr) = u32CdqRptr;
        }
		ipf_pm_print_packet((void *)(unsigned long)MDDR_FAMA(pstRd[i].u32OutPtr), pstRd[i].u16PktLen);
        /* 更新RD读指针 */
        u32RdqRptr = ((u32RdqRptr+1) < IPF_DLRD_DESC_SIZE)?(u32RdqRptr+1):0;
		pstRd[i].u16PktLen > (g_ipf_ctx.status->ad_thred)? g_ipf_ctx.status->get_rd_cnt[IPF_AD_1]++:\
						   		  					   g_ipf_ctx.status->get_rd_cnt[IPF_AD_0]++;

        g_ipf_ctx.status->rd_len_update += pstRd[i].u16PktLen;
    }

	ipf_rd_rate(g_ipf_ctx.status->rate_en, IPF_CHANNEL_DOWN);
    ipf_writel(u32RdqRptr, HI_IPF_CH1_RDQ_RPTR_OFFSET);
    *pu32Num = u32Num;
}

int mdrv_ipf_get_dlad_num (unsigned int* pu32AD0Num, unsigned int* pu32AD1Num)
{
	g_ipf_ctx.status->get_ad_num_times++;
#ifdef CONFIG_PSAM
	return psam_get_dlad_num(pu32AD0Num, pu32AD1Num);
#else
	return ipf_get_dl_ad_num(pu32AD0Num, pu32AD1Num);
#endif
}

unsigned int mdrv_ipf_get_dlrd_num(void)
{
    HI_IPF_CH1_DQ_DEPTH_T dq_depth;

    /* 读取RD深度 */
    dq_depth.u32 = ipf_readl(  HI_IPF_CH1_DQ_DEPTH_OFFSET);
	g_ipf_ctx.status->get_rd_num_times++;
    return dq_depth.bits.dl_rdq_depth;
}

static int ipf_probe(struct platform_device *pdev)
{
	struct resource	*regs;
	int ret;
	struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();

	regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!regs)
		return -ENXIO;

    memset(&g_ipf_ctx, 0, sizeof(ipf_ctx_t));

	g_ipf_ctx.irq = platform_get_irq(pdev, 0);
	if (unlikely(g_ipf_ctx.irq == 0))
		return -ENXIO;

	g_ipf_ctx.regs = devm_ioremap_resource(&pdev->dev, regs);
	if (IS_ERR(g_ipf_ctx.regs))
		return PTR_ERR(g_ipf_ctx.regs);
	

	g_ipf_ctx.dev = &pdev->dev;
	g_ipf_ctx.dma_mask = 0xffffffffULL;
	g_ipf_ctx.dev->dma_mask = &g_ipf_ctx.dma_mask;

	g_ipf_ctx.clk = devm_clk_get(g_ipf_ctx.dev, "ipf_clk");
	if (IS_ERR(g_ipf_ctx.clk)) {
		dev_err(g_ipf_ctx.dev, "ipf clock not available\n");
		return -ENXIO;
	} else {
		ret = clk_prepare_enable(g_ipf_ctx.clk);
		if (ret) {
			dev_err(g_ipf_ctx.dev, "failed to enable ipf clock\n");
			return ret;
		}
	}

	g_ipf_ctx.limit_addr = (IPF_LIMIT_ADDR_S *)sm->trans_limit;
    g_ipf_ctx.memblock_show = (unsigned long *)sm->memlock;
	memset((void*)sm->trans_limit, 0x0, IPF_TRANS_LIMIT_SIZE);
    memset((void*)sm->memlock, 0x0, IPF_ADDR_MEMBLOCK_SIZE);

	if(ipf_get_limit_addr()){
		g_ipf_ctx.not_get_space++;
		dev_info(g_ipf_ctx.dev, "ipf addr limit func disable\n");
	}

	ipf_init();

	return 0;

}

static int ipf_remove(struct platform_device *pdev)
{
    return IPF_SUCCESS;
}

static const struct of_device_id ipf_match[] = {
	{ .compatible = "hisilicon,ipf_balong_app" },
	{},
};

static struct platform_driver ipf_pltfm_driver = {
	.probe		= ipf_probe,
	.remove		= ipf_remove,
	.driver		= {
		.name		= "ipf",
		.of_match_table	= ipf_match,
		.pm = &ipf_dev_pm_ops,
	},
};

EXPORT_SYMBOL(g_ipf_ctx);
EXPORT_SYMBOL(mdrv_ipf_config_dlad);
EXPORT_SYMBOL(mdrv_ipf_get_used_dlad);
EXPORT_SYMBOL(bsp_ipf_config_timeout);
EXPORT_SYMBOL(bsp_ipf_set_control_flag_for_ccore_reset);
EXPORT_SYMBOL(bsp_ipf_set_pktlen);
EXPORT_SYMBOL(mdrv_ipf_reinit_dlreg);
EXPORT_SYMBOL(mdrv_ipf_get_uldesc_num);
EXPORT_SYMBOL(mdrv_ipf_config_ulbd);
EXPORT_SYMBOL(mdrv_ipf_get_dlad_num);
EXPORT_SYMBOL(mdrv_ipf_get_ulbd_num);
EXPORT_SYMBOL(bsp_ipf_srest);
EXPORT_SYMBOL(ipf_init);
EXPORT_SYMBOL(mdrv_ipf_get_dlrd);
EXPORT_SYMBOL(mdrv_ipf_register_ops);
EXPORT_SYMBOL(ipf_register_wakeup_dlcb);


module_platform_driver(ipf_pltfm_driver);//lint !e64
MODULE_LICENSE("GPL v2");
MODULE_ALIAS("platform:ipf");

#ifdef __cplusplus
}
#endif

/*lint -restore*/

