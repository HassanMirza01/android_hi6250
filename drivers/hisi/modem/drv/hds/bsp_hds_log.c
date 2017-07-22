


#include <linux/string.h>
#include "bsp_hds_service.h"
#include "bsp_hds_log.h"
#include "bsp_diag_frame.h"
#include "bsp_hds_cmd.h"
#include "bsp_hds_ind.h"
#include "bsp_hds_service.h"

u32 g_printlog_conn   = false;
u32 g_printlog_enable = false;
u32 g_translog_conn   = false;
u32 g_printlog_level  = 0;

/*************************************************************************
 函 数 名	: bsp_hds_translog_conn
 功能描述	: 与工具连接状态设置
 输入参数	: 无
 返 回 值	: 成功与否标识码
 修改历史	:
 日    期	: 2016年8月10日
 作    者	: l00354607
 修改内容	:
*************************************************************************/
int bsp_hds_translog_conn(void)
{
    g_translog_conn=true;
    return BSP_OK;
}

/*************************************************************************
 函 数 名	: bsp_printlog_cfg
 功能描述	: 开关状态、打印级别设置
 输入参数	: 无
 返 回 值	: 成功与否标识码
 修改历史	:
 日    期	: 2016年8月10日
 作    者	: l00354607
 修改内容	:
*************************************************************************/
int bsp_printlog_cfg(u32 enable,u32 level)
{
    if(level>7)
    {
       printk(KERN_ERR"printlog level err %d\n",level);
       return BSP_ERROR;
    }
    g_printlog_level=level;

    if(enable)
    {
        g_printlog_enable=true;
    }
    else
    {
        g_printlog_enable=false;
    }

    printk(KERN_ERR"printlog switch:%d,level:%d\n",g_printlog_enable,g_printlog_level);
    return BSP_OK;
}

/*************************************************************************
 函 数 名	: bsp_hds_printlog_conn
 功能描述	: 与工具连接状态设置
 输入参数	: 无
 返 回 值	: 成功与否标识码
 修改历史	:
 日    期	: 2016年8月10日
 作    者	: l00354607
 修改内容	:
*************************************************************************/
int bsp_hds_printlog_conn(void)
{
    g_printlog_conn=true;
    return BSP_OK;

}

/*************************************************************************
 函 数 名	: bsp_LogProcEntry
 功能描述	: 处理DIAG FW发过来的BSP LOG配置命令的处理入口
 输入参数	: u8* pstReq, u8 *cnf, u32 *cnf_len
 返 回 值	:
 修改历史	:
 日    期	: 2016年8月10日
 作    者	: l00354607
 修改内容	:
*************************************************************************/
int bsp_LogProcEntry(u8* pstReq)
{
    diag_frame_head_stru    *pData;
    MSP_DIAG_DATA_REQ_STRU  *pReqData;
    DRV_PRINT_CFG_REQ       *plogcfg;
    DIAG_BSP_COMM_CNF_STRU  stLogSetCnf = {0};
    hds_cnf_stru            stCommCnf   = {0};
    /*lint -save -e826 */
    HDS_GET_MSG_DATA_CFG(pstReq, pData, pReqData);
    plogcfg  = (DRV_PRINT_CFG_REQ *)((void*)(pReqData->ucData));
    /*lint -restore +e826 */

    /*set confirm data*/
    stLogSetCnf.ulRet  = (u32)bsp_printlog_cfg(plogcfg->enable,plogcfg->level);
    stLogSetCnf.ulAuid = pReqData->ulAuid;
    stLogSetCnf.ulSn   = pReqData->ulSn;

    if (stLogSetCnf.ulRet == BSP_OK)
    {
        return BSP_OK;
    }
    else
    {
        bsp_hds_cnf_common_fill(&stCommCnf, pData);
        bsp_hds_confirm(&stCommCnf, (void*)&stLogSetCnf, (unsigned int)sizeof(DIAG_BSP_COMM_CNF_STRU));
        return (int)stLogSetCnf.ulRet;
    }
}

/*************************************************************************
 函 数 名	: bsp_hds_log_init
 功能描述	: 向bsp注册cmdid和回调函数
 输入参数	:
 返 回 值	:
 修改历史	:
 日    期	: 2016年8月10日
 作    者	: l00354607
 修改内容	:
*************************************************************************/
void bsp_hds_log_init(void)
{
    bsp_hds_cmd_register(DIAG_CMD_LOG_SET, (bsp_hds_func)bsp_LogProcEntry);
}





