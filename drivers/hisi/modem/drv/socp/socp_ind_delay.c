
#include "socp_ind_delay.h"
#include "socp_balong.h"
#include <linux/vmalloc.h>
#include <linux/device.h>



extern  unsigned long SCM_CoderDstChanMemInit(void);
extern unsigned long SCM_CoderDstChannelInit(void);
extern unsigned long simple_strtoul(const char *cp, char **endp, unsigned int base);

struct socp_enc_dst_log_cfg g_stEncDstBufLogConfig = {NULL,0,0,10,false,10,false,0,0};
socp_early_cfg_stru         g_stSocpEarlyCfg    = {NULL,0,0,0,0,0};
socp_mem_reserve_stru       g_stSocpMemReserve  = {NULL,0,0,0,0};

void *socp_logbuffer_memremap(unsigned long phys_addr, size_t size);

/*lint -e528*/
/*****************************************************************************
* 函 数 名  : socp_logbuffer_sizeparse
*
* 功能描述  : 在代码编译阶段将CMD LINE中的BUFFER大小参数解析出来
*
* 输入参数  : 无
*
* 输出参数  : 无
*
* 返 回 值  : 无
*****************************************************************************/
static int __init socp_logbuffer_sizeparse(char *pucChar)
{
    u32      ulBufferSize;

    /* Buffer的大小以Byte为单位，原则上不大于200M，不小于1M */
    ulBufferSize = (u32)simple_strtoul(pucChar, NULL, 0);

    if ((ulBufferSize > SOCP_MAX_MEM_SIZE )
      || (ulBufferSize < SOCP_MIN_MEM_SIZE))
    {
        socp_printf("BuffSize too long or short ,BuffSize: 0x%x\n",ulBufferSize);
        g_stSocpEarlyCfg.ulBufUsable = BSP_FALSE;
        return -1;
    }

    /* 为了保持ulBufferSize的长度8字节对齐,如果长度不是8字节对齐地址也不会 */
    if (0 != (ulBufferSize % 8))
    {
        socp_printf("BuffSize no 8 byte allignment,BuffSize: 0x%x\n",ulBufferSize);
        g_stSocpEarlyCfg.ulBufUsable = BSP_FALSE;
        return -1;
    }
    g_stSocpEarlyCfg.ulBufferSize = ulBufferSize;
    socp_printf("early_cfg:BufferSize 0x%x, adapt buffer_size: 0x%x\n",
                ulBufferSize,
                g_stSocpEarlyCfg.ulBufferSize);
    
    g_stSocpEarlyCfg.ulBufUsable  =  BSP_TRUE;
    return 0;
}
early_param("mdmlogsize", socp_logbuffer_sizeparse);

/*****************************************************************************
* 函 数 名  : socp_logbuffer_timeparse
*
* 功能描述  : 在代码编译阶段将CMD LINE中的TIMEOUT大小参数解析出来
*
* 输入参数  : 无
*
* 输出参数  : 无
*
* 返 回 值  : 无
*****************************************************************************/
static int __init socp_logbuffer_timeparse(char *pucChar)
{
    u32      ulTimeout;

    /* 输入字符串以秒为单位，需要再转换成毫秒，至少为1秒，不大于20分钟 */
    ulTimeout = (u32)simple_strtoul(pucChar, NULL,0);

    if (SOCP_MAX_TIMEOUT < ulTimeout)
    {

        ulTimeout = SOCP_MAX_TIMEOUT;
    }

    ulTimeout *= 1000;

    g_stSocpEarlyCfg.ulTimeout  = ulTimeout;

    socp_printf("early_cfg: timeout 0x%x\n", g_stSocpEarlyCfg.ulTimeout);

    return 0;
}
early_param("mdmlogtime", socp_logbuffer_timeparse);


/*****************************************************************************
* 函 数 名  : socp_logbuffer_addrparse
*
* 功能描述  : 在代码编译阶段将CMD LINE中的基地址参数解析出来
*
* 输入参数  : 无
*
* 输出参数  : 无
*
* 返 回 值  : 无
*****************************************************************************/
static int __init socp_logbuffer_addrparse(char *pucChar)
{
    unsigned long  ulBaseAddr;

    ulBaseAddr = simple_strtoul(pucChar, NULL, 0);

    /* 物理地址是32位的实地址并且是8字节对齐的 */
    if ((0 != (ulBaseAddr % 8))
        || (0 == ulBaseAddr))
    {
        socp_printf("early_cfg: BaseAdress 0x%x\n", ulBaseAddr);

        return -1;
    }

    g_stSocpEarlyCfg.ulPhyBufferAddr = ulBaseAddr;

    socp_printf("early_cfg: bufferaddr 0x%x\n", g_stSocpEarlyCfg.ulPhyBufferAddr);

    return 0;
}
early_param("mdmlogbase", socp_logbuffer_addrparse);


/*****************************************************************************
 函 数 名  : socp_logbuffer_memremap
 功能描述  : 用于LOG延迟写入时把数据从SOCP通道的缓冲中发送到VCOM端口把实地址转换成虚地址
             底软实现，仅做移植到COMM
 输入参数  : phys_addr:需要REMAP的物理地址
             size:     需要REMAP的数据大小
 输出参数  : 无
 返 回 值  : REMAP后的虚拟地址

 修改历史      :
  1.日    期   : 2014年8月11日
    作    者   : h59254
    修改内容   : V8R1 LOG延迟写入新增
*****************************************************************************/
void *socp_logbuffer_memremap(unsigned long phys_addr, size_t size)
{
    unsigned long i;
    u8* vaddr;
    unsigned long npages = (PAGE_ALIGN((phys_addr & (PAGE_SIZE - 1)) + size) >> PAGE_SHIFT);
    unsigned long offset = phys_addr & (PAGE_SIZE - 1);
    struct page **pages;

    pages = vmalloc(sizeof(struct page *) * npages);
    if (!pages)
    {
        return NULL;
    }

    pages[0] = phys_to_page(phys_addr);

    for (i = 0; i < npages - 1 ; i++)
    {
        pages[i + 1] = pages[i] + 1;
    }

    vaddr = (u8*)vmap(pages, (unsigned int)npages, (unsigned long)VM_MAP, pgprot_writecombine(PAGE_KERNEL));

    if ( NULL != vaddr )

    {
        vaddr += offset;
    }

    vfree(pages);

    return (void *)vaddr;
}

/*****************************************************************************
* 函 数 名  : socp_logbuffer_bufferinit
*
* 功能描述  : 在代码初始化阶段将LOG延迟输出使用的内存申请出来
*
* 输入参数  : 无
*
* 输出参数  : 无
*
* 返 回 值  : 无
*****************************************************************************/
static int __init socp_logbuffer_mmap(void)
{
    /*step1: if logcfg is on, mmap kernel reserved memory */
    if(SOCP_RESERVED_TRUE == g_stSocpEarlyCfg.ulLogCfg)
    {
        if(BSP_TRUE == g_stSocpMemReserve.ulBufUsable)
        {
            /* 映射虚拟地址 */
            g_stSocpMemReserve.pVirBuffer = socp_logbuffer_memremap(g_stSocpMemReserve.ulPhyBufferAddr,
                                                                    (size_t)g_stSocpMemReserve.ulBufferSize);
            if(NULL == g_stSocpMemReserve.pVirBuffer)
            {
                socp_printf("[%s]: kernel reserved buffer mmap failed, virt addr 0x%p!\n",
                            __FUNCTION__,g_stSocpMemReserve.pVirBuffer);
                g_stSocpMemReserve.ulBufUsable = BSP_FALSE;
                return BSP_ERROR;
            }

            socp_printf("[%s]: kernel reserved buffer mmap success, virt addr 0x%p!\n",
                            __FUNCTION__,g_stSocpMemReserve.pVirBuffer);
            return BSP_OK;
        }
        else
        {
            socp_printf("[%s]: kernel reserved buffer is invalid, don't mmap\n",__FUNCTION__);
            return BSP_ERROR;
        }
    }

    /*step2: if buffer addr is invalid or buffer size is invalide,
             it means fastboot do not reserve memory to us,
             or memory reserved is invalid, do nothing*/
    if(BSP_FALSE == g_stSocpEarlyCfg.ulBufUsable)
    {
        socp_printf("[%s]:BufferSize or BufferAddr is invalid!\n",__FUNCTION__);
        return BSP_OK;
    }

    /*step3: memmap socp buffer, and record virtual buffer address */
    g_stSocpEarlyCfg.pVirBuffer = socp_logbuffer_memremap(g_stSocpEarlyCfg.ulPhyBufferAddr,
                                                          (size_t)g_stSocpEarlyCfg.ulBufferSize);
    if(NULL == g_stSocpEarlyCfg.pVirBuffer)
    {
        socp_printf("[%s]:virBuffer is invalid!\n",__FUNCTION__);
        g_stSocpEarlyCfg.ulBufUsable = BSP_FALSE;
        return BSP_ERROR;
    }

    g_stSocpEarlyCfg.ulBufUsable = BSP_TRUE;

    socp_printf("[%s]:fastboot resered buffer is valid 0x%p 0x%x 0x%x!\n",
                __FUNCTION__,
                g_stSocpEarlyCfg.pVirBuffer,
                g_stSocpEarlyCfg.ulPhyBufferAddr,
                g_stSocpEarlyCfg.ulBufferSize);

    return BSP_OK;
}

arch_initcall(socp_logbuffer_mmap); 

/*****************************************************************************
* 函 数 名  : socp_logbuffer_dmalloc
* 功能描述  : 动态申请内存
* 输入参数  : 设备节点
* 输出参数  : 无
* 返 回 值  : 设置成功与否标志
*****************************************************************************/
s32 socp_logbuffer_dmalloc(struct device_node* dev)
{
    dma_addr_t      ulAddress = 0;
    u8              *pucBuf;
    int             ret;
    u32             aulDstChan[SOCP_DST_CHAN_CFG_BUTT]={0};
    u32             size;
    struct device dev1;
    
    ret = of_property_read_u32_array(dev, "dst_chan_cfg", aulDstChan, (size_t)SOCP_DST_CHAN_CFG_BUTT);
    if(ret)
    {
        socp_printf("socp_logbuffer_dmalloc:dts don't config dmalloc logbuffer size, use default size 1M!\n");
        size = 1*1024*1024;
    }
    else
    {
        socp_printf("socp_ind_delay_init:of_property_read_u32_array get size 0x%x!\n", aulDstChan[SOCP_DST_CHAN_CFG_SIZE]);
        size = aulDstChan[SOCP_DST_CHAN_CFG_SIZE];
    }
    /* coverity[secure_coding] */
    memset(&dev1,0,sizeof(dev1));
    pucBuf =(u8 *) dma_alloc_coherent(&dev1, (size_t)size, &ulAddress, GFP_KERNEL);

    if(BSP_NULL == pucBuf)
    {
        socp_printf("socp_logbuffer_dmalloc alloc buffer failed, pucBuf 0x%p.\n", pucBuf);
        return BSP_ERROR;
    }

    socp_printf("socp_logbuffer_dmalloc success,  ulAddress 0x%lx, pucBuf 0x%p. size 0x%x\n", ulAddress, pucBuf, size);

    g_stEncDstBufLogConfig.ulPhyBufferAddr  = (unsigned long)ulAddress;
    g_stEncDstBufLogConfig.pVirBuffer       = pucBuf;
    g_stEncDstBufLogConfig.ulCurTimeout     = 10; /* 使用默认值 */
    g_stEncDstBufLogConfig.BufferSize       = size;
    g_stEncDstBufLogConfig.logOnFlag        = SOCP_DST_CHAN_DTS;

    return BSP_OK;
}

/* log2.0 2014-03-19 Begin:*/
/*****************************************************************************
* 函 数 名  : bsp_socp_get_log_cfg
*
* 功能描述  : 获取LOG2.0 SOCP水线、超时配置信息
*
* 输入参数  : 无
*
* 输出参数  : 无
*
* 返 回 值  : SOCP_ENC_DST_BUF_LOG_CFG_STRU指针
*****************************************************************************/
struct socp_enc_dst_log_cfg * bsp_socp_get_log_cfg(void)
{
    return &g_stEncDstBufLogConfig;
}

u32 bsp_socp_get_sd_logcfg(SOCP_ENC_DST_BUF_LOG_CFG_STRU* cfg)
{
    struct socp_enc_dst_log_cfg* LogCfg;

    if(NULL == cfg)
        return BSP_ERR_SOCP_INVALID_PARA;

    LogCfg = bsp_socp_get_log_cfg();

    cfg->logOnFlag       = LogCfg->logOnFlag;
    cfg->BufferSize      = LogCfg->BufferSize;
    cfg->overTime        = LogCfg->overTime;
    cfg->pVirBuffer      = LogCfg->pVirBuffer;
    cfg->ulCurTimeout    = LogCfg->ulCurTimeout;
    cfg->ulPhyBufferAddr = LogCfg->ulPhyBufferAddr;

    return BSP_OK;
}

/*****************************************************************************
* 函 数 名  : bsp_socp_set_ind_mode
*
* 功能描述  : 上报模式接口
*
* 输入参数  : 模式参数
*
* 输出参数  : 无
*
* 返 回 值  : BSP_S32 BSP_OK:成功 BSP_ERROR:失败
*****************************************************************************/
s32 bsp_socp_set_ind_mode(SOCP_IND_MODE_ENUM eMode)
{
    u32 time;

    switch (eMode)
    {
        case SOCP_IND_MODE_DIRECT:
        {
            if(SOCP_IND_MODE_DIRECT == g_stEncDstBufLogConfig.currentMode)
            {
                socp_printf("the ind mode direct is already config!\n");
                break;
            }
            
            (void)bsp_socp_set_timeout(SOCP_TIMEOUT_TRF, 0x17);
            g_stEncDstBufLogConfig.ulCurTimeout = 10;
            bsp_socp_set_enc_dst_threshold((bool)FALSE,SOCP_CODER_DST_OM_IND);
            bsp_socp_encdst_set_cycle(SOCP_CODER_DST_OM_IND, 0);

            g_stEncDstBufLogConfig.currentMode = eMode;
            socp_printf("the ind  mode direct config sucess!\n");

            break;
        }
        case SOCP_IND_MODE_DELAY:
        {
            if(SOCP_IND_MODE_DELAY == g_stEncDstBufLogConfig.currentMode)
            {
                socp_printf("the ind mode delay is already config!\n");
                break;
            }

            /* if logbuffer is not configed, can't enable delay mode*/
            if(g_stEncDstBufLogConfig.logOnFlag == SOCP_DST_CHAN_DELAY)
            {
                time = (g_stEncDstBufLogConfig.overTime * 2289)/1000;
                (void)bsp_socp_set_timeout(SOCP_TIMEOUT_TRF, time);
                g_stEncDstBufLogConfig.ulCurTimeout = g_stEncDstBufLogConfig.overTime;
                bsp_socp_set_enc_dst_threshold((bool)TRUE,SOCP_CODER_DST_OM_IND);
                bsp_socp_encdst_set_cycle(SOCP_CODER_DST_OM_IND, 1);

                g_stEncDstBufLogConfig.currentMode = eMode;
                socp_printf("the ind delay mode config sucess!\n");

            }
            else
            {
                socp_printf("ind delay can't config:mem can't be setted!\n");
            }
            break;

        }
        case SOCP_IND_MODE_CYCLE:
        {
            if(SOCP_IND_MODE_CYCLE == g_stEncDstBufLogConfig.currentMode)
            {
                socp_printf("the ind mode cycle is already config!\n");
                break;
            }

            /* if logbuffer is not configed, can't enable cycle mode*/
            if((g_stEncDstBufLogConfig.logOnFlag == SOCP_DST_CHAN_DELAY)&&
                (BSP_TRUE == g_stSocpMemReserve.ulBufUsable))
            {
                bsp_socp_encdst_set_cycle(SOCP_CODER_DST_OM_IND, 2);

                g_stEncDstBufLogConfig.currentMode = eMode;
                socp_printf("the ind cycle mode config sucess!\n");
            }
            else
            {
                socp_printf("ind delay can't config:mem can't be setted!\n");
            }
            break;
        }
        default:
        {
            socp_printf("bsp_socp_set_ind_mode: invalid mode: %d!\n",g_stEncDstBufLogConfig.currentMode);
            return  BSP_ERROR;
        }
    }

    return BSP_OK ;
 }

/*****************************************************************************
* 函 数 名  : bsp_socp_timeout_init
*
* 功能描述  : 模块初始化目的buffer上报超时配置的函数
*
* 输入参数  : 无
*
* 输出参数  : 无
*
* 返 回 值  : 初始化成功的标识码
*****************************************************************************/
s32 bsp_socp_logbuffer_init(struct device_node* dev)
{
    s32 ret;

    /*step1: if modlog config enabled, use kernel reserved buffer */
    if(SOCP_RESERVED_TRUE ==g_stSocpEarlyCfg.ulLogCfg)
    {
        /*step1.1: if kernel reserved buffer is valid, enable ind delay */
        if(BSP_TRUE == g_stSocpMemReserve.ulBufUsable)
        {
            g_stEncDstBufLogConfig.pVirBuffer       = g_stSocpMemReserve.pVirBuffer;
            g_stEncDstBufLogConfig.ulPhyBufferAddr  = g_stSocpMemReserve.ulPhyBufferAddr;
            g_stEncDstBufLogConfig.BufferSize       = g_stSocpMemReserve.ulBufferSize;
            g_stEncDstBufLogConfig.overTime         = g_stSocpMemReserve.ulTimeout;
            g_stEncDstBufLogConfig.logOnFlag        = SOCP_DST_CHAN_DELAY;
        }
        /*step1.2: if kernel reserved buffer is invalid, disable ind delay, use 1M malloc buffer */
        else
        {
            g_stEncDstBufLogConfig.logOnFlag        = SOCP_DST_CHAN_NOT_CFG;
        }
    }
    /*step2: if modlog config is not parsed, use fastboot reserved memory*/
    else
    {
        /*step2.1: if fastboot reserved memory is valid, enable ind delay*/
        if(BSP_TRUE == g_stSocpEarlyCfg.ulBufUsable)
        {
            g_stEncDstBufLogConfig.pVirBuffer       = g_stSocpEarlyCfg.pVirBuffer;
            g_stEncDstBufLogConfig.ulPhyBufferAddr  = g_stSocpEarlyCfg.ulPhyBufferAddr;
            g_stEncDstBufLogConfig.BufferSize       = g_stSocpEarlyCfg.ulBufferSize;
            g_stEncDstBufLogConfig.overTime         = g_stSocpEarlyCfg.ulTimeout;
            g_stEncDstBufLogConfig.logOnFlag        = SOCP_DST_CHAN_DELAY;
        }
        /*step2.2: if fastboot reserved memory is invalid, use 1M malloc buffer, disable ind delay*/
        else
        {
             g_stEncDstBufLogConfig.logOnFlag=SOCP_DST_CHAN_NOT_CFG;
        }
    }

    /*step3: use dmalloc buffer, disable ind delay*/
    /* 延迟上报没打开时判断DTSI中是否配置目的通道的buffer size */
    if(SOCP_DST_CHAN_NOT_CFG == g_stEncDstBufLogConfig.logOnFlag)
    {
        ret = socp_logbuffer_dmalloc(dev);
        if(ret)
        {
            socp_printf("socp_ind_delay_init:of_property_read_u32_array failed!\n");
            return BSP_ERROR;
        }
    }

    return BSP_OK;
}


/*****************************************************************************
* 函 数 名  : bsp_socp_timeout_init
*
* 功能描述  : 模块初始化目的buffer上报超时配置的函数
*
* 输入参数  : 无
*
* 输出参数  : 无
*
* 返 回 值  : 初始化成功的标识码
*****************************************************************************/
void bsp_socp_timeout_init(void)
{
    /*如果配置延时上报，需要配置超时寄存器*/
    if(SOCP_DST_CHAN_DELAY == g_stEncDstBufLogConfig.logOnFlag)
    {
        bsp_socp_set_timeout(SOCP_TIMEOUT_TRF, g_stEncDstBufLogConfig.overTime*2289/1000);
    }
    else
    {
        bsp_socp_set_timeout(SOCP_TIMEOUT_TRF, SOCP_MIN_TIMEOUT*2289/1000);
    }

    return;
}

/*****************************************************************************
* 函 数 名  : socp_ind_delay_init
*
* 功能描述  : 模块初始化函数
*
* 输入参数  : 无
*
* 输出参数  : 无
*
* 返 回 值  : 初始化成功的标识码
*****************************************************************************/
s32 bsp_socp_ind_delay_init(void)
{
    s32 ret;
    struct device_node* dev;

    dev = of_find_compatible_node(NULL,NULL,"hisilicon,socp_balong_app");
    if(NULL == dev)
    {
        socp_printf("socp_ind_delay_init: Socp dev find failed\n");
        return BSP_ERROR;
    }


    ret = bsp_socp_logbuffer_init(dev);
    if(ret)
    {
        socp_printf("socp dst logbuffer init faield!\n");
        return ret;
    }

    /* init timeout */
    bsp_socp_timeout_init();


    socp_printf("[%s]:socp_ind_delay init sucess!\n", __FUNCTION__);

    return BSP_OK;
}

s32 bsp_socp_dst_init(void)
{
    unsigned long ret;

    ret = SCM_CoderDstChanMemInit();
    if(ret)
    {
        socp_printf("[%s]:SCM channel mem init fail\n", __FUNCTION__);
        return BSP_ERROR;
    }

    ret = SCM_CoderDstChannelInit();
    if(ret)
    {
        socp_printf("[%s]:SCM channel config init fail\n", __FUNCTION__);
        return BSP_ERROR;
    }
return BSP_OK;
}
u32 bsp_socp_read_cur_mode(u32 chanid)
{
    u32 u32modestate;
    /*lint -save -e647*/
    u32modestate = SOCP_REG_GETBITS(SOCP_REG_ENCDEST_SBCFG(chanid),1,1); 
    /*lint -restore +e647*/
    return u32modestate;
}
/*****************************************************************************
* 函 数 名  : socp_logbuffer_cfgshow
*
* 功能描述  : 打印延时写入的配置信息
*
* 输入参数  : 无
*
* 输出参数  : 无
*
* 返 回 值  : 无
*****************************************************************************/
void bsp_socp_logbuffer_cfgshow(void)
{

    socp_printf("socp_logbuffer_cfgshow: overTime           %d\n", g_stEncDstBufLogConfig.overTime);
    socp_printf("socp_logbuffer_cfgshow: Current Time Out   %d\n", g_stEncDstBufLogConfig.ulCurTimeout);
    socp_printf("socp_logbuffer_cfgshow: BufferSize         %d\n", g_stEncDstBufLogConfig.BufferSize);
    socp_printf("socp_logbuffer_cfgshow: logOnFlag          %d\n", g_stEncDstBufLogConfig.logOnFlag);
    socp_printf("socp_logbuffer_cfgshow: PhyBufferAddr      0x%lx\n", g_stEncDstBufLogConfig.ulPhyBufferAddr);
    socp_printf("socp_logbuffer_cfgshow: currentmode        %d\n", g_stEncDstBufLogConfig.currentMode);
    

    return;
}
/*****************************************************************************
* 函 数 名  : socp_logbuffer_early_cfgshow
*
* 功能描述  : cmdline方式申请内存信息
*
* 输入参数  : 无
*
* 输出参数  : 无
*
* 返 回 值  : 无
*****************************************************************************/
void bsp_socp_logbuffer_early_cfgshow(void)
{

    socp_printf("socp_logbuffer_early_cfgshow: BufferSize         %d\n", g_stSocpEarlyCfg.ulBufferSize);
    socp_printf("socp_logbuffer_early_cfgshow: BufUsable          %d\n", g_stSocpEarlyCfg.ulBufUsable);
    socp_printf("socp_logbuffer_early_cfgshow: logCfg             %d\n", g_stSocpEarlyCfg.ulLogCfg);
    socp_printf("socp_logbuffer_early_cfgshow: PhyBufferAddr      0x%lx\n", g_stSocpEarlyCfg.ulPhyBufferAddr);
    socp_printf("socp_logbuffer_early_cfgshow: time               %d\n", g_stSocpEarlyCfg.ulTimeout);
    

    return;
}
/*****************************************************************************
* 函 数 名  : socp_logbuffer_memreseve_cfgshow
*
* 功能描述  : kernel预留内存配置信息
*
* 输入参数  : 无
*
* 输出参数  : 无
*
* 返 回 值  : 无
*****************************************************************************/
void bsp_socp_logbuffer_memreserve_cfgshow(void)
{

    socp_printf("socp_logbuffer_memreserve_cfgshow: BufferSize         %d\n", g_stSocpMemReserve.ulBufferSize);
    socp_printf("socp_logbuffer_memreserve_cfgshow: BufUsable          %d\n", g_stSocpMemReserve.ulBufUsable);
    socp_printf("socp_logbuffer_memreserve_cfgshow: PhyBufferAddr      0x%lx\n", g_stSocpMemReserve.ulPhyBufferAddr);
    socp_printf("socp_logbuffer_memreserve_cfgshow: time               %d\n", g_stSocpMemReserve.ulTimeout);
    

    return;
}
EXPORT_SYMBOL(bsp_socp_get_log_cfg);



