

#ifndef    _BSP_IPF_H_
#define    _BSP_IPF_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/**************************************************************************
  头文件包含
**************************************************************************/
#include "hi_ipf.h"
#include <bsp_shared_ddr.h>
#ifndef __CMSIS_RTOS
#include "mdrv_ipf.h"

#else
#include "mdrv_ipf_comm.h"
#endif


#include <bsp_trace.h>
#include <bsp_dump.h>
#ifdef CONFIG_BALONG_MODEM_RESET
#include "mdrv_sysboot.h"
#endif

/***************************************/
#define SET1(reg,type,a1,b1)        ((type##_T*)&reg)->bits.a1 = b1
#define SET2(reg,type,a1,b1,a2,b2)     SET1(reg,type,a1,b1);SET1(reg,type,a2,b2)
#define SET3(reg,type,a1,b1,a2,b2,a3,b3)     SET2(reg,type,a1,b1,a2,b2);SET1(reg,type,a3,b3)
#define SET4(reg,type,a1,b1,a2,b2,a3,b3,a4,b4)     SET3(reg,type,a1,b1,a2,b2,a3,b3);SET1(reg, type,a4,b4)
#define SET5(reg,type,a1,b1,a2,b2,a3,b3,a4,b4,a5,b5)     SET4(reg,type,a1,b1,a2,b2,a3,b3,a4,b4);SET1(reg, type,a5,b5)

#define UPDATE0(reg, type)    do{                        \
                            reg = ipf_readl(type##_OFFSET);   \
                            ipf_writel(reg, type##_OFFSET); \
                        }while(0)

#define UPDATE1(reg, type, a1, b1)    do{                        \
                            reg = ipf_readl(type##_OFFSET);   \
                            SET1(reg, type,a1,b1);                  \
                            ipf_writel(reg, type##_OFFSET); \
                        }while(0)
#define UPDATE2(reg, type, a1, b1, a2, b2)    do{                        \
                            reg = ipf_readl(type##_OFFSET);   \
                            SET2(reg, type,a1, b1, a2, b2);                  \
                            ipf_writel(reg, type##_OFFSET); \
                        }while(0)
#define UPDATE3(reg, type, a1, b1, a2, b2, a3, b3)    do{                        \
                            reg = ipf_readl(type##_OFFSET);   \
                            SET3(reg, type,a1, b1, a2, b2, a3, b3);                  \
                            ipf_writel(reg, type##_OFFSET); \
                        }while(0)
#define UPDATE4(reg, type, a1, b1, a2, b2, a3, b3, a4, b4)    do{                        \
                            reg = ipf_readl(type##_OFFSET);   \
                            SET4(reg, type,a1, b1, a2, b2, a3, b3,a4,b4);                  \
                            ipf_writel(reg, type##_OFFSET); \
                        }while(0)
#define UPDATE5(reg, type, a1, b1, a2, b2, a3, b3, a4, b4, a5, b5)    do{                        \
							reg = ipf_readl(type##_OFFSET);   \
							SET5(reg, type,a1,b1,a2,b2,a3,b3,a4,b4,a5,b5);				   \
							ipf_writel(reg, type##_OFFSET); \
						}while(0)


/***************************************/


/* #define __BSP_IPF_DEBUG__*/

#define IPF_MEMBLOCK_CNT                (20)

/*IPF描述符地址定义*/

#define IPF_SHAREMEM_BASE				(unsigned long)((unsigned long)SHM_BASE_ADDR + SHM_OFFSET_IPF)

#define IPF_DLBD_MEM_SIZE				(IPF_DLBD_DESC_SIZE * sizeof(ipf_bd_s))
#define IPF_DLRD_MEM_SIZE				(IPF_DLRD_DESC_SIZE * sizeof(ipf_rd_s))
#define IPF_DLAD0_MEM_SIZE				(IPF_DLAD0_DESC_SIZE * sizeof(ipf_ad_s))
#define IPF_DLAD1_MEM_SIZE				(IPF_DLAD1_DESC_SIZE * sizeof(ipf_ad_s))
#define IPF_DLCD_MEM_SIZE               (IPF_DLCD_DESC_SIZE * sizeof(ipf_cd_s))
#define IPF_ULBD_MEM_SIZE               (IPF_ULBD_DESC_SIZE * sizeof(ipf_bd_s))
#define IPF_ULRD_MEM_SIZE               (IPF_ULRD_DESC_SIZE * sizeof(ipf_rd_s))
#define IPF_ULAD0_MEM_SIZE				(IPF_ULAD0_DESC_SIZE * sizeof(ipf_ad_s))
#define IPF_ULAD1_MEM_SIZE				(IPF_ULAD1_DESC_SIZE * sizeof(ipf_ad_s))
#define IPF_PWRCTL_BASIC_FILTER_SIZE	(IPF_BF_NUM * sizeof(ipf_filter_node_s))
#define IPF_EXT_FILTER_SIZE				(EXFLITER_NUM * sizeof(ipf_filter_node_s))
#define IPF_PWRCTL_INFO_SIZE			128
#define IPF_PWRCTL_ADQ_WPTR_INFO_SIZE	32
#define IPF_PWRCTL_ADQ_RPTR_CHCTRL_SIZE	64
#define IPF_PWRCTL_ADDR_LIMIT_SIZE		64
#define IPF_INIT_SIZE					16
#define IPF_ULBD_IDLENUM_SIZE			16
#define IPF_DLCDRPTR_MEM_SIZE			sizeof(unsigned int)
#define IPF_DEBUG_INFO_SIZE				(sizeof(struct ipf_debug) * 0x2)
#define IPF_TRANS_LIMIT_SIZE			32
#define IPF_OUT_ADDR_LIMIT_SIZE			sizeof(unsigned int)
#define IPF_ADDR_MEMBLOCK_SIZE			(IPF_MEMBLOCK_CNT*4)
#define IPF_DLDESC_SIZE					(IPF_DLBD_MEM_SIZE + IPF_DLRD_MEM_SIZE + IPF_DLAD0_MEM_SIZE + IPF_DLAD1_MEM_SIZE + IPF_DLCD_MEM_SIZE)
#define EXFLITER_NUM					(IPF_TOTAL_FILTER_NUM-IPF_BF_NUM_EX) /* 扩展过滤器数目 */
#define IPF_DISABLE_FILTER				0  /* filter disable*/

#define IPF_BF_NUM						64  /* 基本过滤器数目 */
#define IPF_TOTAL_FILTER_NUM            256  /* 过滤器总数目先使用一半 */
#define IPF_TAIL_INDEX					511  /* filter标识最后一个filter */

#define IPF_BF_NUM_EX					128  /* 基本过滤器数目 */
#define IPF_TOTAL_FILTER_NUM_EX			IPF_TOTAL_FILTER_NUM  /* 过滤器总数目先使用一半 */
#define IPF_TAIL_INDEX_EX				1023  /* filter标识最后一个filter */

#define TIME_OUT_CFG					65           /* 默认超时时间,时钟频率166MHZ下为0.1ms */
#define IPF_BDWPTR_MUX					0x100  /*BD写指针互斥量*/
#define IPF_INT_OPEN0					0x00000C03        /*上行通道中断屏蔽*/
#define IPF_INT_OPEN1					0x3D030000 /*下行通道中断屏蔽*/

#define IPF_CHANNEL_STATE_IDLE       	0x14 /*通道状态IDLE*/
#define IPF_ADQ_BUF_EPT_MASK            0x00000004
#define IPF_ADQ_BUF_FULL_MASK           0x00000008
#define IPF_ULADQ_PLEN_TH               404
#define IPF_ACORE_INIT_SUCCESS          0x10000

#define IPF_UL_RPT_INT0					0x1            /*上行结果上报中断0*/
#define IPF_UL_RDQ_FULL					(0x1 << 8)

#define IPF_UL_TIMEOUT_INT0             0x2            /*上行结果上报超时中断0*/
#define IPF_UL_ADQ0_EPTY_INT0			0x400         /*上行ADQ0空中断0*/
#define IPF_UL_ADQ1_EPTY_INT0			0x800         /*上行ADQ1空中断0*/
#define	IPF_UL_BDQ_EPTY_INT1			0x200			/*Upload BD empty interrupt*/

#define IPF_DL_RPT_INT1					0x10000       /*下行结果上报中断0*/
#define IPF_DL_RDQ_FULL					(0x1 << 24)

#define IPF_DL_TIMEOUT_INT1             0x20000       /*下行结果上报超时中断0*/
#define IPF_DL_RD_FULL_INT1         	0x1000000	  /*下行rd满中断1*/
#define IPF_DL_ADQ0_EPTY_INT1			0x4000000    /*下行ADQ0空中断0*/
#define IPF_DL_ADQ1_EPTY_INT1			0x8000000    /*下行ADQ1空中断0*/

#define SCH_ALL_DESC					1
#define	IPF_TIMER_RATIO					(32768)					/*one second*/
#define	IPF_RD_TMOUT					(2 * IPF_TIMER_RATIO)   /*must less than 16 second*/
#define	IPF_LEN_RATIO					(1024*1024)
#define MAX_PM_OM_SAVE_SIZE				40				/*dpm first packet print cnt*/
#define IPF_PWR_PREPARED				2
#define IPF_PWR_UP						1
#define IPF_PWR_DOWN					0
#define SAVE_NONE						0
#define SAVE_PASS						1
#define SAVE_DONE						2
#define IPF_VER_120A					(0x31323061)
#define IPF_VER_130A					(0x31333061)
#define IPF_VER_130B					(0x31333062)
#define IPF_VER_140A					(0x31343061)
#define IPF_VER_150A    				(0x31353061)

#ifdef __KERNEL__
#define IPF_PRINT     printk
#else
#define IPF_PRINT	SRE_Printf
#endif

enum ipf_version{
	IPF_VERSION_0000  = 0x0,
	IPF_VERSION_120a  = 0x1,		
	IPF_VERSION_130a  = 0x2,
	IPF_VERSION_130b  = 0x3,
	IPF_VERSION_140a  = 0x4,
	IPF_VERSION_150a  = 0x5,
	IPF_VERSTION_BOTTOM
};

typedef enum ipf_enable
{
    ipf_disable, 
    ipf_enable, 
    ipf_en_bottom
}ipf_enable_t;

typedef enum tagIPF_FORRESET_CONTROL_E
{
    IPF_FORRESET_CONTROL_ALLOW = 0xabcd1234,     /*允许发送*/
    IPF_FORRESET_CONTROL_FORBID,    /*禁止发送*/
    IPF_FORRESET_CONTROL_MAX
}IPF_FORRESET_CONTROL_E;

typedef struct ipf_ddr {
	unsigned int start;
	unsigned int ul_start;
	unsigned int filter_pwc_start;
	unsigned int pwc_info_start;
	unsigned int dlcdrptr;
	unsigned int debug_dlcd_start;
	unsigned int debug_dlcd_size;
	unsigned int end;
	unsigned int len;
} ipf_ddr_t;

struct ipf_debug
{
	int	init_ok;
	int	mdrv_called_not_init;
	unsigned int ad_thred;
	int flt_chain_loop;
	int get_rd_times;
	int get_rd_num_times;
	unsigned int	get_rd_cnt[IPF_AD_MAX];
	int get_ad_num_times;
	int cfg_ad_times;
	unsigned int	cfg_ad_cnt[IPF_AD_MAX];
	int	ad_out_ptr_null[IPF_AD_MAX];
	int	busy_cnt;
	int	occupy_cnt;
	int get_bd_num_times;
	int	cfg_bd_times;
	unsigned int	cfg_bd_cnt;
	int	bd_full;
	int	bd_len_zero_err;
	int	cd_not_enough;
	int	suspend;
	int	resume;
	int	resume_with_intr;
	unsigned int	timestamp_en;
	int rd_len_update;
	int	rd_len;
	unsigned int	rd_ts;
	int	rate_en;
	int	dump_mem_alloc_ok;
	int invalid_para;
	ipf_ddr_t share_ddr_info;
	int reg_scur_wr_err;
	int reg_scur_rd_err;
	unsigned int ccore_rst_err;
	int rsr_suspend_begin;
	int rsr_suspend_end;
	int rsr_resume_begin;
	int rsr_resume_end;
};

typedef union ipf_desc_attr
{
	struct
	{
		unsigned short    int_en        : 1; 
		unsigned short    mode         : 2;
		unsigned short    cd_en         : 1; 
		unsigned short    fc_head      : 4; 
		unsigned short    reserved     : 8; 
	} bits;

	unsigned short u16;
}ipf_desc_attr_t;
	
typedef void (*ipf_bd_empty)(void);
typedef int (*BSP_IPF_WakeupUlCb)(void);
typedef int (*BSP_IPF_AdqEmptyUlCb)(IPF_ADQ_EMPTY_E eAdqEmpty);

/* RD描述符 */
typedef struct
{
    unsigned short u16Attribute;
    unsigned short u16PktLen;
    unsigned int u32InPtr;
    unsigned int u32OutPtr;
    unsigned short u16Result;
    unsigned short u16UsrField1;
    unsigned int u32UsrField2;
    unsigned int u32UsrField3;
    unsigned int u32UsrField4;
    unsigned int u32UsrField5;
}ipf_rd_s;

/* BD描述符 */
typedef struct
{
    unsigned short u16Attribute;
    unsigned short u16PktLen;
    unsigned int u32InPtr;
    unsigned int u32OutPtr;
    unsigned short u16Result;
    unsigned short u16UsrField1;
    unsigned int u32UsrField2;
    unsigned int u32UsrField3;
    unsigned int u32UsrField4;
    unsigned int u32UsrField5;
} ipf_bd_s;

typedef struct
{
    unsigned int u32OutPtr0;
    unsigned int u32OutPtr1;
} ipf_ad_s;

typedef struct
{
    unsigned short u16Attribute;
    unsigned short u16PktLen;
    unsigned int u32Ptr;
}ipf_cd_s;


typedef struct {
    unsigned char u8SrcAddr[16];
    unsigned char u8DstAddr[16];
    unsigned char u8DstMsk[16];
    union{
        struct{
        	unsigned int u16SrcPortLo:16;
        	unsigned int u16SrcPortHi:16;
        }Bits;
	    unsigned int u32SrcPort;
    } unSrcPort;
    union{
        struct
        {
            unsigned int u16DstPortLo:16;
        	unsigned int u16DstPortHi:16;
        }Bits;
    	unsigned int u32DstPort;
    } unDstPort;
    union{
        struct
        {
            unsigned int u8TrafficClass:8;
        	unsigned int u8TrafficClassMask:8;
        	unsigned int u16Reserve:16;
        }Bits;
    	unsigned int u32TrafficClass;
    }unTrafficClass;
    union{
        struct
        {
            unsigned int fltn_local_addr_mask:7;
        	unsigned int Reserve:25;
        }Bits;
    	unsigned int u32LocalAddressMsk;
    }unLocalAddressMsk;
    union{
        struct
        {
            unsigned int    fltn_next_header:8;
            unsigned int    reserved:24;
        }u32NextHeader;
    	unsigned int u32Protocol;
    }unNextHeader;
    union
    {
        struct
        {
            unsigned int    fltn_fow_lable             : 20; /* [19..0] 过滤表流标签配置寄存器，字节小端排列 */
            unsigned int    reserved                   : 12; /* [31..20] 保留。 */
        } bits;
        unsigned int    u32;
    }u32FlowLable;
    union{
        struct{
            unsigned int    fltn_type                  : 8; /* [7..0] 过滤器type域配置值 */
            unsigned int    reserved_1                 : 8; /* [15..8] 保留。 */
            unsigned int    fltn_code                  : 8; /* [23..16] 过滤器code域配置值 */
            unsigned int    reserved_0                 : 8; /* [31..24] 保留。 */
        }Bits;
    	unsigned int u32CodeType;
    } unFltCodeType;
    union{
        struct{
            unsigned int    fltn_next_index            : 10; /* [9..0] 下一个过滤器对应的index */
            unsigned int    reserved_1                 : 6; /* [15..10] 保留。 */
            unsigned int    fltn_pri                   : 9; /* [24..16] 过滤器优先级，fltn_pri数值越小优先级越高 */
            unsigned int    reserved_0                 : 7; /* [31..25] 保留。 */
        }Bits;
    	unsigned int u32FltChain;
    } unFltChain;
    unsigned int u32FltSpi;
    union{
    	struct{
    		unsigned int FltEn:1;
    		unsigned int FltType:1;
    		unsigned int Resv1:2;
            unsigned int FltSpiEn:1;
            unsigned int FltCodeEn:1;
            unsigned int FltTypeEn:1;
            unsigned int FltFlEn:1;
            unsigned int FltNhEn:1;
            unsigned int FltTosEn:1;
            unsigned int FltRPortEn:1;
            unsigned int FltLPortEn:1;
            unsigned int FltRAddrEn:1;
            unsigned int FltLAddrEn:1;
            unsigned int Resv2:2;
            unsigned int FltBid:6;
            unsigned int Resv3:10;
    	}Bits;
    	unsigned int u32FltRuleCtrl;
    }unFltRuleCtrl;
}ipf_filter_node_s;


typedef struct tagIPF_DL_S
{
    ipf_bd_s* pstIpfBDQ;
    ipf_rd_s* pstIpfRDQ;
    ipf_ad_s* pstIpfADQ0;
    ipf_ad_s* pstIpfADQ1;
    ipf_cd_s* pstIpfCDQ;
	
#ifdef __KERNEL__
    BSP_IPF_WakeupDlCb pFnDlIntCb; /* 中断中唤醒的PS任务 */
    BSP_IPF_AdqEmptyDlCb pAdqEmptyDlCb;/*下行AD空回调，A核心*/

/*ACore硬件使用的物理地址*/
    ipf_bd_s* pstIpfPhyBDQ;
    ipf_rd_s* pstIpfPhyRDQ;
    ipf_ad_s* pstIpfPhyADQ0;
    ipf_ad_s* pstIpfPhyADQ1;

#endif
    unsigned int *u32IpfCdRptr; /* 当前可以读出的位置 */
    unsigned int u32IpfCdWptr;
    unsigned int u32IdleBd; /* 记录上一次获取的空闲BD 数 */
}IPF_DL_S;

typedef struct tagIPF_LIMIT_ADDR{
	unsigned int block_sum;
	unsigned int block1_start;
	unsigned int block1_end;
	unsigned int block2_start;
	unsigned int block2_end;
	unsigned int block_err;
}IPF_LIMIT_ADDR_S;

typedef struct filter_map_node
{
    unsigned int ps_id;
    unsigned int index;
    struct filter_map_node* next;
}filter_map;

struct ipf_limit_handler{
    void (*region_set)(unsigned int region, unsigned int start, unsigned int end);
    void (*secctrl_set)(unsigned int ctrl);
    unsigned int (*secctrl_get)(void);
    void (*default_set)(unsigned int outlimit);
    void (*sideband_set)(unsigned int sideband);
};

struct ipf_share_mem_map
{
    ipf_bd_s dbd[IPF_DLBD_DESC_SIZE];
    ipf_rd_s drd[IPF_DLRD_DESC_SIZE];
    ipf_ad_s dad0[IPF_DLAD0_DESC_SIZE];
    ipf_ad_s dad1[IPF_DLAD1_DESC_SIZE];
    ipf_cd_s dcd[IPF_DLCD_DESC_SIZE];
    ipf_bd_s ubd[IPF_ULBD_DESC_SIZE];
    ipf_rd_s urd[IPF_ULRD_DESC_SIZE];
    ipf_ad_s uad0[IPF_ULAD0_DESC_SIZE];
    ipf_ad_s uad1[IPF_ULAD1_DESC_SIZE];
    ipf_filter_node_s filter[IPF_TOTAL_FILTER_NUM];
    unsigned char reg_save[IPF_PWRCTL_INFO_SIZE+IPF_PWRCTL_ADQ_WPTR_INFO_SIZE+IPF_PWRCTL_ADQ_RPTR_CHCTRL_SIZE+
IPF_PWRCTL_ADDR_LIMIT_SIZE];
    union{
        unsigned char init[IPF_INIT_SIZE];
        struct {
            unsigned int acore;
            unsigned int ccore;
            unsigned int modem;
            unsigned int save;
        } status;
    }init;
    int rsracc;
    unsigned int idle[4];
    unsigned int dcd_rptr;
    struct ipf_debug debug[2];
    unsigned char trans_limit[IPF_TRANS_LIMIT_SIZE];
    unsigned int out_addr_limit;
    unsigned char memlock[IPF_MEMBLOCK_CNT*4];
    unsigned int bottom[0];
}__attribute__((packed, aligned(1)));

#define bsp_ipf_get_sharemem() (struct ipf_share_mem_map*)(((unsigned char*)SHM_BASE_ADDR + SHM_OFFSET_IPF))

struct ipf_mannul_unit{
    char* name;
    char* desc;
};


int bsp_ipf_srest(void);
void bsp_ipf_set_debug_para(void ** psam_get_debug);
void bsp_set_init_status(int stat);
int bsp_get_init_status(void);

#if defined(__OS_VXWORKS__) || defined(__OS_RTOSCK__)||defined(__OS_RTOSCK_SMP__)
int ipf_config_cd(void* pstTtf, unsigned short* pu16TotalDataLen, unsigned int* pu32BdInPtr);
void bsp_ipf_dl_rpt1_switch(int value);
int ipf_init(void);
IPF_FORRESET_CONTROL_E bsp_ipf_get_control_flag_for_ccore_reset(void);

#ifdef CONFIG_MODULE_BUSSTRESS
int ipf_ul_stress_test_start(int task_priority);
#endif

#endif

#ifdef __CMSIS_RTOS
/*****************************************************************************
* 函 数 名       : ipf_drx_bak_reg
*
* 功能描述  : 提供的低功耗接口，保存IPF相关信息
*
* 输入参数  : 无
*
* 输出参数  : 无
* 返 回 值     : IPF_SUCCESS     IPF可以下电，相关信息已经保存
*                           IPF_ERROR        IPF不可以下电
*
* 修改记录  : 2011年2月14日   鲁婷  创建
*****************************************************************************/
int ipf_drx_bak_reg(void);

/*****************************************************************************
* 函 数 名       : ipf_drx_restore_reg
*
* 功能描述  : 提供的低功耗接口，用于IPF上电恢复
*
* 输入参数  : 无
*
* 输出参数  : 无
* 返 回 值     : 无
*
* 注意:该函数需要在锁中断的情况下调用
* 修改记录  : 2011年2月14日   鲁婷  创建
*****************************************************************************/
void ipf_drx_restore_reg(void);
int	bsp_ipf_init(void);

#ifdef CONFIG_BALONG_MODEM_RESET
/*****************************************************************************
* 函 数 名  : bsp_ipf_reset_ccore_lpm3_cb
*
* 功能描述  : 在ccore单独复位流程中，设置ipf reset标记
*
* 输入参数  : 
*             
* 输出参数  : 无
* 返 回 值  : 无
*
* 修改记录  : 2012年11月29日   z00212992  创建
*****************************************************************************/
int bsp_ipf_reset_ccore_lpm3_cb(DRV_RESET_CB_MOMENT_E eparam, int userdata);
#endif

#endif

#ifdef __cplusplus
} /* allow C++ to use these headers */
#endif /* __cplusplus */

#endif    /* End #define _BSP_DMAC_H_ */

