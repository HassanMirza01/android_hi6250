/******************************************************************************

  Copyright(C)2008,Hisilicon Co. LTD.

******************************************************************************
File Name       : ChrRelationEvent_cfg.c
Description     : 非关联事件定义表
History         :
   1.q00312157      2016-7-12     Draft Enact

******************************************************************************/

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include "ChrEventIDComm.h"

#ifdef __cplusplus
  #if __cplusplus
  extern "C"{
  #endif
#endif

/*lint -e767 */
//#define    THIS_FILE_ID        PS_FILE_ID_CHRABSOLUTEEVENT_CFG_C
/*lint +e767 */

/*****************************************************************************
  2 全局变量声明
*****************************************************************************/

#if (FEATURE_ON == FEATURE_PTM)

/* TRRC 非关联直通事件定义集合 */
int g_aulTRRCAbosulteEvent[][2]=
{
    {TRRC_STATISTIC_INFO_COLLECTION_EVENTID, TRRC_OUT_OF_SYNC_CELL_UPDATE_INFO_STRU_ALARMID},
    {TRRC_STATISTIC_INFO_COLLECTION_EVENTID, TRRC_APP_COLLECT_TDS_FREQ_REPORT_STRU_ALARMID },
    {TRRC_STATISTIC_INFO_COLLECTION_EVENTID, TRRC_CS_CALL_EST_CNF_INFO_STRU_ALARMID},
    {TRRC_STATISTIC_INFO_COLLECTION_EVENTID, TRRC_CS_CALL_CONN_REQ_INFO_STRU_ALARMID}, 
    {TRRC_STATISTIC_INFO_COLLECTION_EVENTID, TRRC_CS_CALL_AIRMSG_INFO_STRU_ALARMID},
    {TRRC_STATISTIC_INFO_COLLECTION_EVENTID, TRRC_APP_CONFIG_PCH_CELL_INFO_REPORT_STRU_ALARMID},
};

/* TMAC 非关联直通事件定义集合 */
int g_aulTMACbosulteEvent[][2]=
{

};

/* LRRC 统计1 非关联直通事件定义集合 */
int g_aulLRRCStatictic1Event[][2]=
{

};

/* LRRC 统计2 非关联直通事件定义集合 */
int g_aulLRRCStatictic2Event[][2]=
{

};

/* LL2 统计1 非关联直通事件定义集合 */
int g_aulLL2StaticticEvent[][2]=
{
    {LL2_STATISTIC_INFO_COLLECTION_EVENTID, LMAC_OM_PREAMBLE_SPEC_NOT_MATCH_INFO_STRU_ALARMID},
};

/* Volte自诊断事件 */
int g_aulLRRCVolteFaultAutoAnIndEvent[][2]=
{
    {LRRC_VOLTE_FAULT_AUTOAN_IND_EVENTID, LPS_OM_VOLTE_FAULT_AUTOAN_INFO_STRU_ALARMID},
};

int g_aulLRRCVolteStatIndEvent[][2]=
{
    {LPS_VOLTE_STAT_IND_EVENTID, LPS_OM_VOLTE_GENERAL_STAT_INFO_STRU_ALARMID},
};



/* LMAS 统计 非关联直通事件定义集合 */
int g_aulLNASStaticticEvent[][2]=
{

};


#endif

/*****************************************************************************
  3 函数申明
*****************************************************************************/


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

