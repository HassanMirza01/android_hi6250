

/******************************************************************************
   1 头文件包含
******************************************************************************/
#include "PsAcpuLogFilter.h"
#include "PsLogFilterComm.h"
#include "msp_diag_comm.h"


#define    THIS_FILE_ID        PS_FILE_ID_ACPU_LOG_FILTER_C

/******************************************************************************
   2 外部函数变量声明
******************************************************************************/

/******************************************************************************
   3 私有定义
******************************************************************************/


/******************************************************************************
   4 全局变量定义
******************************************************************************/

/*****************************************************************************
 功能描述  : 根据定义的可注册过滤函数的数量，对全局变量进行初始化操作
 修改历史      :
  1.日    期   : 2016年9月5日
    作    者   : z00383822
    修改内容   : 增加全局变量

*****************************************************************************/
PS_OM_ACPU_LAYER_MSG_FILTER_CTRL_STRU        g_stAcpuLayerMsgFilterCtrl =
    {0, {VOS_NULL_PTR, VOS_NULL_PTR, VOS_NULL_PTR, VOS_NULL_PTR}};
PS_OM_ACPU_LAYER_MSG_MATCH_CTRL_STRU         g_stAcpuLayerMsgMatchCtrl  =
    {0, {VOS_NULL_PTR, VOS_NULL_PTR, VOS_NULL_PTR, VOS_NULL_PTR}};

/******************************************************************************
   5 函数实现
******************************************************************************/


/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgMatch_Acpu
 功能描述  : A核层间消息替换接口
 输入参数  : VOS_VOID                           *pstMsg
 输出参数  : 无
 返 回 值  : VOS_VOID*
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月14日
    作    者   : z00383822
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID* PS_OM_LayerMsgMatch_Acpu
(
    VOS_VOID                           *pMsg
)
{
    VOS_VOID                           *pResult;

    pResult = PS_OM_LayerMsgCommMatch(pMsg,
                        g_stAcpuLayerMsgMatchCtrl.ulRegCnt,
                        g_stAcpuLayerMsgMatchCtrl.apfuncMatchEntry, 
                        PS_OM_ACPU_LAYER_MSG_MATCH_ITEM_MAX_CNT);
    return pResult;
}

/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgFilter_Acpu
 功能描述  : A核层间消息过滤接口
 输入参数  : const VOID *pMsg:消息指针
 输出参数  : 无
 返 回 值  : VOS_UINT32:
                返回VOS_TRUE:  表示该消息需要进行过滤
                返回VOS_FALSE: 表示该消息无需进行过滤
 调用函数  :
 被调函数  :
 修改历史      :
  1.日    期   : 2016年11月3日
    作    者   : z00383822
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 PS_OM_LayerMsgFilter_Acpu
(
    const VOS_VOID                     *pMsg
)
{  
    VOS_UINT32                          ulResult;
 
    ulResult = PS_OM_LayerMsgCommFilter(pMsg, 
                    g_stAcpuLayerMsgFilterCtrl.ulRegCnt, 
                    g_stAcpuLayerMsgFilterCtrl.apfuncFilterEntry, 
                    PS_OM_ACPU_LAYER_MSG_FILTER_ITEM_MAX_CNT);
    return ulResult;    
}

/* 防止PC工程编译过程中函数多重定义 */
/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgMatchInit
 功能描述  : 用于向DIAG组件进行注册的公共的LOG替换函数
             (本函数在A核任务中注册，用于替换A核内部层间消息)
 输入参数  : VOS_VOID
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月3日
    作    者   : z00383822
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PS_OM_LayerMsgMatchInit(VOS_VOID)
{
    (VOS_VOID)DIAG_TraceMatchFuncReg(PS_OM_LayerMsgMatch_Acpu);

    return;
}

/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgMatchFuncReg
 功能描述  : 注册MsgMatch回调接口
 输入参数  : PS_OM_LAYER_MSG_MATCH_PFUNC          pFunc
 输出参数  : 无
 输入参数回调接口规则:
             1.如果注册回调内部没有对消息进行处理，则需要将入参指针返回，否则
               本模块不知道是否需要将此消息传递给下一个注册回调进行处理
             2.如果注册回调内部对消息进行了处理，则返回值能够实现两个功能:
               ①返回VOS_NULL，则将此消息进行完全过滤，不会再勾取出来
               ②返回与入参指针不同的另一个指针，则勾取的消息将会使用返回的指
                 针内容替换原消息的内容。另本模块不负责对替换的内存进行释放，
                 替换原消息使用的内存请各模块自行管理。
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月3日
    作    者   : z00383822
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PS_OM_LayerMsgMatchFuncReg
(
    PS_OM_LAYER_MSG_MATCH_PFUNC         pFunc
)
{
    VOS_UINT32                          ulResult;
          
    ulResult = PS_OM_LayerMsgMatchFuncCommReg(pFunc,
                    &(g_stAcpuLayerMsgMatchCtrl.ulRegCnt),
                    g_stAcpuLayerMsgMatchCtrl.apfuncMatchEntry,
                    PS_OM_ACPU_LAYER_MSG_MATCH_ITEM_MAX_CNT);

    return ulResult;
}

/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgFilterInit
 功能描述  : 用于向DIAG组件进行注册的公共的LOG过滤函数
             (本函数在A核任务中注册，用于过滤A核内部层间消息)
 输入参数  : VOS_VOID
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月3日
    作    者   : z00383822
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PS_OM_LayerMsgFilterInit(VOS_VOID)
{
   (VOS_VOID)DIAG_TraceFilterFuncReg(PS_OM_LayerMsgFilter_Acpu);

    return;
}

/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgFilterFuncReg
 功能描述  : 注册MsgMatch回调接口
 输入参数回调接口规则:
             1.如果注册回调内部没有对消息进行处理，返回VOS_FALSE，否则
               本模块不知道是否需要将此消息传递给下一个注册回调进行处理
             2.如果注册回调内部对消息进行了处理，返回VOS_TRUE表示该消息
               需要进行过滤。
 输入参数  : PS_OM_ACPU_LAYER_MSG_FILTER_PFUNC          pFunc
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年11月3日
    作    者   : z00383822
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PS_OM_LayerMsgFilterFuncReg
(
    PS_OM_LAYER_MSG_FILTER_PFUNC        pFunc
)
{
    VOS_UINT32                          ulResult;
    
    ulResult = PS_OM_LayerMsgFilterFuncCommReg(pFunc,
                    &(g_stAcpuLayerMsgFilterCtrl.ulRegCnt),
                    g_stAcpuLayerMsgFilterCtrl.apfuncFilterEntry,
                    PS_OM_ACPU_LAYER_MSG_FILTER_ITEM_MAX_CNT);
    return ulResult;
}


