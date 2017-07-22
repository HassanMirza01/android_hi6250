

#include "bsp_diag_frame.h"
#include "bsp_hds_log.h"
#include "bsp_hds_ind.h"
#include "bsp_hds_service.h"
#include "bsp_slice.h"


void mdrv_hds_cmd_register(unsigned int cmdid, bsp_hds_func fn)
{
    bsp_hds_cmd_register(cmdid, fn);
}

void mdrv_hds_get_cmdlist(unsigned int *cmdlist, unsigned int *num)
{
    bsp_hds_get_cmdlist(cmdlist, num);
}

void mdrv_hds_cnf_register(hds_cnf_func fn)
{
    bsp_hds_cnf_register(fn);
}


int mdrv_hds_msg_proc(void *pstReq)
{
    return bsp_hds_msg_proc((diag_frame_head_stru *)pstReq);
}


/*************************************************************************
 函 数 名	: mdrv_hds_translog_conn
 功能描述	: 与工具连接状态设置
 输入参数	: 无
 返 回 值	: 成功与否标识码
 修改历史	:
 日    期	: 2016年8月10日
 作    者	: l00354607
 修改内容	:
*************************************************************************/
int mdrv_hds_translog_conn(void)
{
    return bsp_hds_translog_conn();
}


/*************************************************************************
 函 数 名	: mdrv_hds_printlog_conn
 功能描述	: 与工具连接状态设置
 输入参数	: 无
 返 回 值	: 成功与否标识码
 修改历史	:
 日    期	: 2016年8月10日
 作    者	: l00354607
 修改内容	:
*************************************************************************/
int mdrv_hds_printlog_conn(void)
{
    return bsp_hds_printlog_conn();
}






