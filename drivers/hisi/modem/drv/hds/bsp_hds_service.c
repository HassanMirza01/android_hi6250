

#include "bsp_hds_service.h"
#include "bsp_hds_cmd.h"
#include "bsp_diag_frame.h"
#include "bsp_module.h"
#include <linux/list.h>
#include <linux/kernel.h>
#include "osl_malloc.h"

/*lint -save -e826 */
bsp_hds_cmd_stru g_hds_cmd_list_head;
hds_cnf_func     g_hds_cnf_fn = NULL;
/*************************************************************************
 函 数 名	: bsp_hds_cmd_register
 功能描述	: bsp消息处理cmdid和回调函数注册接口
 输入参数	: u32 cmdid, bsp_hds_func fn
 返 回 值	: 0
 修改历史	:
 日    期	: 2016年8月10日
 作    者	: l00354607
 修改内容	:
*************************************************************************/
void bsp_hds_cmd_register(u32 cmdid, bsp_hds_func fn)
{
    bsp_hds_cmd_stru *hds_list;
    struct list_head *me;
    bsp_hds_cmd_stru *pstDiag = NULL;

    /*判断cmdid是否重复注册*/
    list_for_each(me,&g_hds_cmd_list_head.list)
    {
        pstDiag = list_entry(me, bsp_hds_cmd_stru, list);

        if(cmdid == pstDiag->ulCmdId)
        {
            printk(KERN_ERR"cmdid:0x%x have registered!\n",cmdid);
            return;
        }
    }
    hds_list = osl_malloc((unsigned int)sizeof(bsp_hds_cmd_stru));
    if (NULL == hds_list)
    {
        printk(KERN_ERR"malloc hds_list memory failed!\n");
        return;
    }
    hds_list->ulCmdId = cmdid;
    hds_list->pFunc = fn;

    /*将注册的cmdid和回调函数添加到链表中*/
    list_add(&hds_list->list, &g_hds_cmd_list_head.list);
    //printk(KERN_ERR"registered cmdid:0x%x\n",hds_list->ulCmdId);
}

/*************************************************************************
 函 数 名	: bsp_hds_msg_proc
 功能描述	: bsp消息处理
 输入参数	: u32 cmdid, bsp_hds_func fn
 返 回 值	: 0
 修改历史	:
 日    期	: 2016年8月10日
 作    者	: l00354607
 修改内容	:
*************************************************************************/
int bsp_hds_msg_proc(diag_frame_head_stru *pData)
{
    s32 ret = 0;
    struct list_head *me;
    bsp_hds_cmd_stru *pstDiag = NULL;

    if(DIAG_FRAME_MSG_TYPE_BSP != pData->stID.pri4b)
    {
        printk(KERN_ERR"Rcv Error Msg Id 0x%x\n",pData->u32CmdId);
        return BSP_ERROR;
    }

    /*遍历链表，根据注册的cmdid，跳到对应的回调中处理*/
    list_for_each(me,&g_hds_cmd_list_head.list)
    {
        pstDiag = list_entry(me, bsp_hds_cmd_stru, list);

        if(pstDiag->ulCmdId == pData->u32CmdId)
        {
            pstDiag->ulReserve ++;
            ret = pstDiag->pFunc((u8*)pData);
            return ret;
        }
    }

    /*未注册此cmdid，返回对应的错误码*/
    printk(KERN_ERR"cmdid is not register:%d\n",pData->u32CmdId);

    return HDS_CMD_ERROR;
}

void bsp_hds_get_cmdlist(u32 *cmdlist, u32 *num)
{
    u32 i = 0;
    struct list_head *me;
    bsp_hds_cmd_stru *pstDiag = NULL;

    memset(cmdlist, 0, (unsigned long)(*num));

    list_for_each(me,&g_hds_cmd_list_head.list)
    {
        if(i >= *num)
        {
            break;
        }

        pstDiag = list_entry(me, bsp_hds_cmd_stru, list);
        cmdlist[i++] = pstDiag->ulCmdId;
    }

    *num = i;

    return;
}

void bsp_hds_cnf_register(hds_cnf_func fn)
{
    g_hds_cnf_fn = fn;
}

void bsp_hds_confirm(hds_cnf_stru *cnf, void *data, u32 len)
{
    if(g_hds_cnf_fn)
    {
        g_hds_cnf_fn((void *)cnf, data, len);
    }
    else
    {
        printk(KERN_ERR"cnf fn isn't register, confirm failed!\n");
    }

    return;
}

void bsp_hds_cnf_common_fill(hds_cnf_stru *cnf, diag_frame_head_stru *req)
{
    cnf->ulSSId       = DIAG_FRAME_SSID_APP_CPU;
    cnf->ulMsgType    = DIAG_FRAME_MSG_TYPE_BSP;
    cnf->ulMode       = req->stID.mode4b;
    cnf->ulSubType    = req->stID.sec5b;
    cnf->ulDirection  = DIAG_FRAME_MT_CNF;
    cnf->ulModemid    = 0;
    cnf->ulMsgId      = req->u32CmdId;
    cnf->ulTransId    = req->stService.MsgTransId;
}

/*************************************************************************
 函 数 名	: bsp_ShowDebugInfo
 功能描述	: bsp消息回调debug信息
 输入参数	:
 返 回 值	:
 修改历史	:
 日    期	: 2016年8月10日
 作    者	: l00354607
 修改内容	:
*************************************************************************/
void bsp_ShowDebugInfo(void)
{
    struct list_head *me;
    bsp_hds_cmd_stru *pstDiag;

    list_for_each(me,&g_hds_cmd_list_head.list)
    {
        pstDiag = list_entry(me, bsp_hds_cmd_stru, list);

        printk(KERN_ERR"cmdid:0x%x\n",pstDiag->ulCmdId);
    }
}

void bsp_hds_service_init(void)
{
    INIT_LIST_HEAD(&g_hds_cmd_list_head.list);
    bsp_hds_log_init();
}

/*lint -restore +e826 */




