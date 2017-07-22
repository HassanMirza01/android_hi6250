/******************************************************************************

  Copyright(C)2008,Hisilicon Co. LTD.

******************************************************************************
File Name       : ChrRelationEvent_cfg.c
Description     : 关联事件关联表
History         :
   1.q00312157      2016-5-25     Draft Enact

******************************************************************************/

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include "ChrRelationEvent_cfg.h"

#ifdef __cplusplus
  #if __cplusplus
  extern "C"{
  #endif
#endif

/*lint -e767 */
//#define    THIS_FILE_ID        PS_FILE_ID_CHRRELATIONEVENT_CFG_C
/*lint +e767 */

/*****************************************************************************
  2 全局变量声明
*****************************************************************************/

#if (FEATURE_ON == FEATURE_PTM)

/* TODO: python search flag satrt */
int g_aulModem0ErrRpt[][3]=
{
    RELATIONEVENT1,

};

#if (FEATURE_ON == FEATURE_MULTI_MODEM)
int g_aulModem1ErrRpt[][3]=
{
    RELATIONEVENT1,

};
#if(3 == MULTI_MODEM_NUMBER)
int g_aulModem2ErrRpt[][3]=
{
    RELATIONEVENT1,

};
#endif
#endif
/* TODO: python search flag end */

#endif

/*****************************************************************************
  3 函数申明
*****************************************************************************/

/*****************************************************************************
 函 数 名  : Modem_ErrLog_GetErrReptAddrAndSize
 功能描述  : 获取Errlog全局变量地址
 输入参数  : ulModemId 主modem/副modem的id

 输出参数  : pulErrLogAddr
             pulsize

 返 回 值  : 0：success  其他：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月8日
    作    者   : q00312157
    修改内容   : Modem直通项目新增
*****************************************************************************/
VOS_INT32 Modem_ErrLog_GetErrReptAddrAndSize(
    VOS_UINT32                           ulModemId,
    VOS_UINT_PTR                        *pulErrLogAddr,
    VOS_UINT32                          *pulsize
)
{
#if (FEATURE_ON == FEATURE_PTM)
    if (MODEM_ID_0 == ulModemId)
    {
        *pulErrLogAddr = (VOS_UINT_PTR)g_aulModem0ErrRpt;
        *pulsize = sizeof(g_aulModem0ErrRpt);
    }
#if ( FEATURE_ON == FEATURE_MULTI_MODEM )
    else if (MODEM_ID_1 == ulModemId)
    {
        *pulErrLogAddr = (VOS_UINT_PTR)g_aulModem1ErrRpt;
        *pulsize = sizeof(g_aulModem1ErrRpt);

    }
#if (3 == MULTI_MODEM_NUMBER)
    else if (MODEM_ID_2 == ulModemId)
    {
        *pulErrLogAddr = (VOS_UINT_PTR)g_aulModem2ErrRpt;
        *pulsize = sizeof(g_aulModem2ErrRpt);
    }
#endif
#endif
    else
    {
        return VOS_ERR;
    }

    return VOS_OK;

#else
    return VOS_ERR;

#endif

}

/*****************************************************************************
 函 数 名  : Modem_ErrLog_GetPidAndAlarmId
 功能描述  : ulFaultId关联的pid/alarm_id查询接口
 输入参数  : ulModemId 主modem/副modem的id
             ulFaultId fault id

 输出参数  : paustAlarmArray fault id相关联的pid alarm_id数组，内存空间由diag_om提供，最大长度2048，支持一个faultid关联256个alarm_id；
             pulAlarmNum     fault id相关联的pid alarm_id数组成员个数，最大256；

 返 回 值  : 0：success  其他：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月8日
    作    者   : q00312157
    修改内容   : Modem直通项目新增
*****************************************************************************/
VOS_INT32 Modem_ErrLog_GetPidAndAlarmId(
    VOS_UINT32                          ulModemId,
    VOS_UINT32                          ulFaultId,
    ERRLOG_ALARM_STRU                  *paustAlarmArray,
    VOS_UINT32                         *pulAlarmNum
)
{
    VOS_UINT_PTR                        ulErrLogAddr = VOS_NULL;
    VOS_UINT32                          ulsize;
    VOS_UINT32                          ulCount = 0;
    VOS_UINT32                          i;
    VOS_UINT32                          (*pulErrLogArry)[3];

    if (VOS_NULL_PTR == paustAlarmArray)
    {
        return VOS_ERR;
    }

    if (VOS_OK != Modem_ErrLog_GetErrReptAddrAndSize(ulModemId, &ulErrLogAddr, &ulsize))
    {
        return VOS_ERR;
    }

    pulErrLogArry = (VOS_UINT32(*)[3])ulErrLogAddr;

    for (i=0; i < (ulsize / (3 * sizeof(VOS_UINT32))); i++)
    {
        if (ulFaultId == pulErrLogArry[i][0])
        {
            if (FAULT_ID_CONTAIN_ALARM_ID_MAX_NUM <= ulCount)
            {
                return VOS_ERR;
            }

            paustAlarmArray[ulCount].ulSndPID      = pulErrLogArry[i][1];
            paustAlarmArray[ulCount].usAlarmID     = (VOS_UINT16)pulErrLogArry[i][2];
            ulCount++;
        }
    }

    *pulAlarmNum = ulCount;

    return VOS_OK;
}

/*****************************************************************************
 函 数 名  : Modem_ErrLog_IsContainPID
 功能描述  : 检查PID是否已经存在
 输入参数  : PID数组已及大小

 输出参数  : 是否存在

 返 回 值  : VOS_TRUE：存在  其他：VOS_FALSE
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月8日
    作    者   : q00312157
    修改内容   : Modem直通项目新增

*****************************************************************************/
VOS_BOOL Modem_ErrLog_IsContainPID(
    VOS_UINT32                         *PaulPidArray,
    VOS_UINT32                          ulPidArrayLen,
    VOS_UINT32                          ulDstPid
)
{
    VOS_UINT32                          i;

    for (i=0; i < ulPidArrayLen; i++)
    {
        if (ulDstPid == PaulPidArray[i])
        {
            return VOS_TRUE;
        }
    }

    return VOS_FALSE;
}

/*****************************************************************************
 函 数 名  : Modem_ErrLog_GetErrlogPid
 功能描述  : 提供errlog相关的pid列表，用于errlog开关控制给各pid发送消息
 输入参数  : ulModemId 主modem/副modem的id

 输出参数  : PaulPidArray   errlog相关联的pid数组，内存空间由diag_om提供，最大长度1024，支持256个pid；
             pulPidNum      errlog相关联的pid数组成员个数，最大256；

 返 回 值  : 0：success  其他：fail
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年06月8日
    作    者   : q00312157
    修改内容   : Modem直通项目新增

*****************************************************************************/
VOS_INT32 Modem_ErrLog_GetErrlogPid(
    VOS_UINT32                          ulModemId,
    VOS_UINT32                         *PaulPidArray,
    VOS_UINT32                         *pulPidNum
)
{
    VOS_UINT_PTR                        ulErrLogAddr = VOS_NULL;
    VOS_UINT32                          ulsize;
    VOS_UINT32                          ulCount = 0;
    VOS_UINT32                          i;
    VOS_UINT32                          (*pulErrLogArry)[3];

    if (VOS_NULL_PTR == PaulPidArray)
    {
        return VOS_ERR;
    }

    if (VOS_OK != Modem_ErrLog_GetErrReptAddrAndSize(ulModemId, &ulErrLogAddr, &ulsize))
    {
        return VOS_ERR;
    }

    pulErrLogArry = (VOS_UINT32(*)[3])ulErrLogAddr;

    for (i=0; i < (ulsize / (3 * sizeof(VOS_UINT32))); i++)
    {
        if (0 == i)
        {
            PaulPidArray[0] = pulErrLogArry[i][1];
            ulCount++;
            continue;
        }

        if (VOS_TRUE != Modem_ErrLog_IsContainPID(PaulPidArray, ulCount, pulErrLogArry[i][1]))
        {
            if (ERR_LOG_PID_MAX_NUM <= ulCount)
            {
                return VOS_ERR;
            }

            PaulPidArray[ulCount] = pulErrLogArry[i][1];
            ulCount++;
        }
    }

    *pulPidNum = ulCount;

    return VOS_OK;
}


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

