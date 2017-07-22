

#ifndef __ADS_MNTN_H__
#define __ADS_MNTN_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "TafDiagComm.h"
#include "ImmInterface.h"
#include "IpsMntn.h"
#include "AdsTcpIpTypeDef.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/

#define ADS_MNTN_HOOK_PKT_MAX_SIZE      (52)

#define ADS_MNTN_COMM_MOUDLE_ID         (DIAG_GEN_MODULE(MODEM_ID_0, DIAG_MODE_COMM))

#define ADS_MNTN_REC_UL_PKT_MAX_NUM     (IPF_ULBD_DESC_SIZE)                    /* 上行IP报文记录最大个数 */
#define ADS_MNTN_REC_DL_PKT_MAX_NUM     (IPF_DLRD_DESC_SIZE)                    /* 下行IP报文记录最大个数 */
#define ADS_MNTN_UL_RKT_REC_INFO_ARRAY  (&(g_stAdsUlPktRecInfo))                /* 记录上行IP报文的数组   */
#define ADS_MNTN_DL_RKT_REC_INFO_ARRAY  (&(g_stAdsDlPktRecInfo))                /* 记录下行IP报文的数组   */

/*****************************************************************************
  3 枚举定义
*****************************************************************************/


/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/

/*****************************************************************************
 结构名称  : ADS_MNTN_COMM_HEADER_STRU
 结构说明  : ADS可维可测公共头结构
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucVer;
    VOS_UINT8                           ucReserved;

    VOS_UINT16                          usReserved0;
    VOS_UINT16                          usReserved1;
    VOS_UINT16                          usReserved2;

} ADS_MNTN_COMM_HEADER_STRU;


/*****************************************************************************
 结构名称  : ADS_MNTN_UL_IPF_PROC_STATS_STRU
 结构说明  : 下行行IPF统计信息上报结构
*****************************************************************************/
typedef struct
{
    ADS_MNTN_COMM_HEADER_STRU           stCommHeader;

    VOS_UINT32                          ulULQueNonEmptyTrigEvent;
    VOS_UINT32                          ulULQueFullTrigEvent;
    VOS_UINT32                          ulULQueHitThresTrigEvent;
    VOS_UINT32                          ulULTmrHitThresTrigEvent;
    VOS_UINT32                          ulUL10MsTmrTrigEvent;
    VOS_UINT32                          ulULSpeIntTrigEvent;
    VOS_UINT32                          ulULProcEventNum;

    VOS_UINT32                          ulULBdqCfgIpfHaveNoBd;
    VOS_UINT32                          ulULBdqCfgBdSuccNum;
    VOS_UINT32                          ulULBdqCfgBdFailNum;
    VOS_UINT32                          ulULBdqCfgIpfSuccNum;
    VOS_UINT32                          ulULBdqCfgIpfFailNum;
    VOS_UINT32                          ulULBdqSaveSrcMemNum;
    VOS_UINT32                          ulULBdqFreeSrcMemNum;
    VOS_UINT32                          ulULBdqFreeSrcMemErr;

    VOS_UINT32                          ulULBuffThresholdCurrent;

    VOS_UINT32                          ulULBuffThreshold1;
    VOS_UINT32                          ulULBuffThreshold2;
    VOS_UINT32                          ulULBuffThreshold3;
    VOS_UINT32                          ulULBuffThreshold4;

    VOS_UINT32                          ulULWmLevel1HitNum;
    VOS_UINT32                          ulULWmLevel2HitNum;
    VOS_UINT32                          ulULWmLevel3HitNum;
    VOS_UINT32                          ulULWmLevel4HitNum;

} ADS_MNTN_UL_IPF_PROC_STATS_STRU;


/*****************************************************************************
 结构名称  : ADS_MNTN_DL_IPF_PROC_STATS_STRU
 结构说明  : 下行IPF统计信息上报结构
*****************************************************************************/
typedef struct
{
    ADS_MNTN_COMM_HEADER_STRU           stCommHeader;

    VOS_UINT32                          ulDLRcvIpfRdIntNum;
    VOS_UINT32                          ulDLProcIpfRdEventNum;
    VOS_UINT32                          ulDLRcvIpfAdqEmptyIntNum;
    VOS_UINT32                          ulDLProcIpfAdEventNum;
    VOS_UINT32                          ulDLCCoreResetTrigEvent;

    VOS_UINT32                          ulDLRdqRxRdNum;
    VOS_UINT32                          ulDLRdqGetRd0Num;
    VOS_UINT32                          ulDLRdqTransMemFailNum;
    VOS_UINT32                          ulDLRdqRxNormPktNum;
    VOS_UINT32                          ulDLRdqRxNdPktNum;
    VOS_UINT32                          ulDLRdqRxDhcpPktNum;
    VOS_UINT32                          ulDLRdqRxErrPktNum;
    VOS_UINT32                          ulDLRdqFilterErrNum;

    VOS_UINT32                          ulDLAdqAllocSysMemSuccNum;
    VOS_UINT32                          ulDLAdqAllocSysMemFailNum;
    VOS_UINT32                          ulDLAdqAllocMemSuccNum;
    VOS_UINT32                          ulDLAdqAllocMemFailNum;
    VOS_UINT32                          ulDLAdqFreeMemNum;
    VOS_UINT32                          ulDLAdqRecycleMemSuccNum;
    VOS_UINT32                          ulDLAdqRecycleMemFailNum;
    VOS_UINT32                          ulDLAdqGetFreeAdSuccNum;
    VOS_UINT32                          ulDLAdqGetFreeAdFailNum;
    VOS_UINT32                          ulDLAdqCfgAdNum;
    VOS_UINT32                          ulDLAdqCfgAd0Num;
    VOS_UINT32                          ulDLAdqCfgAd1Num;
    VOS_UINT32                          ulDLAdqCfgIpfSuccNum;
    VOS_UINT32                          ulDLAdqCfgIpfFailNum;
    VOS_UINT32                          ulDLAdqStartEmptyTmrNum;
    VOS_UINT32                          ulDLAdqEmptyTmrTimeoutNum;
    VOS_UINT32                          ulDLAdqRcvAd0EmptyIntNum;
    VOS_UINT32                          ulDLAdqRcvAd1EmptyIntNum;

} ADS_MNTN_DL_IPF_PROC_STATS_STRU;


/*****************************************************************************
 结构名称  : ADS_MNTN_UL_PKT_PROC_STATS_STRU
 结构说明  : 上行数据统计信息上报结构
*****************************************************************************/
typedef struct
{
    ADS_MNTN_COMM_HEADER_STRU           stCommHeader;

    VOS_UINT32                          ulULRmnetRxPktNum;
    VOS_UINT32                          ulULRmnetModemIdErrNum;
    VOS_UINT32                          ulULRmnetRabIdErrNum;
    VOS_UINT32                          ulULRmnetEnQueSuccNum;
    VOS_UINT32                          ulULRmnetEnQueFailNum;
    VOS_UINT32                          ulULPktEnQueSuccNum;
    VOS_UINT32                          ulULPktEnQueFailNum;

} ADS_MNTN_UL_PKT_PROC_STATS_STRU;


/*****************************************************************************
 结构名称  : ADS_MNTN_DL_PKT_PROC_STATS_STRU
 结构说明  : 下行数据统计信息上报结构
*****************************************************************************/
typedef struct
{
    ADS_MNTN_COMM_HEADER_STRU           stCommHeader;

    VOS_UINT32                          ulDLRmnetTxPktNum;
    VOS_UINT32                          ulDLRmnetNoFuncFreePktNum;
    VOS_UINT32                          ulDLRmnetRabIdErrNum;

} ADS_MNTN_DL_PKT_PROC_STATS_STRU;


/*****************************************************************************
 结构名称  : ADS_MNTN_THROUGHPUT_STATS_STRU
 结构说明  : 流量统计信息上报结构
*****************************************************************************/
typedef struct
{
    ADS_MNTN_COMM_HEADER_STRU           stCommHeader;

    VOS_UINT32                          ulULDataRate;
    VOS_UINT32                          ulDLDataRate;

} ADS_MNTN_THROUGHPUT_STATS_STRU;


/*****************************************************************************
 结构名称  : SPE_MNTN_COMM_HEADER_STRU
 结构说明  : SPE可维可测公共头结构
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucVer;
    VOS_UINT8                           ucReserved;

    VOS_UINT16                          usReserved0;
    VOS_UINT16                          usReserved1;
    VOS_UINT16                          usReserved2;

} SPE_MNTN_COMM_HEADER_STRU;


/*****************************************************************************
 结构名称  : SPE_MNTN_PORT_PROC_STATS_STRU
 结构说明  : SPE端口统计信息上报结构
*****************************************************************************/
typedef struct
{
    SPE_MNTN_COMM_HEADER_STRU           stCommHeader;

    VOS_UINT32                          ulTdInputRate;
    VOS_UINT32                          ulRdOutputRate;

    VOS_UINT32                          ulTdPtrA;
    VOS_UINT32                          ulTdUsingNum;
    VOS_UINT32                          ulTdFullH;
    VOS_UINT32                          ulTdEmptyH;
    VOS_UINT32                          ulTdFullS;

    VOS_UINT32                          ulRdPtrA;
    VOS_UINT32                          ulRdUsingNum;
    VOS_UINT32                          ulRdFullH;
    VOS_UINT32                          ulRdEmptyH;
    VOS_UINT32                          ulRdFullS;

} SPE_MNTN_PORT_PROC_STATS_STRU;

/*****************************************************************************
 结构名    : ADS_MNTN_IP_PKT_INFO_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : 保存IP关键信息
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucIpVer;                                /* IP 协议版本 */
    VOS_UINT8                           ucL4Proto;                              /* 协议类型ICMP,TCP,UDP */
    VOS_UINT8                           ucIcmpType;                             /* ICMP报文类型*/
    VOS_UINT8                           aucRsv[1];

    VOS_UINT16                          usDataLen;                              /* IP 数据包长度*/
    VOS_UINT16                          usIp4Id;                                /* IPv4 IDENTIFY字段 */
    VOS_UINT16                          usSrcPort;                              /* IP 源端口号*/
    VOS_UINT16                          usDstPort;                              /* IP 目的端口号 */

    VOS_UINT32                          ulL4Id;                                 /* 层4的IDENTIFY,ICMP IDENTIFY+SN,TCP SEQ */
    VOS_UINT32                          ulTcpAckSeq;                            /* TCP ACK SEQ */
    VOS_UINT32                          ulParam1;                               /* 自定义参数 */
    VOS_UINT32                          ulParam2;                               /* 自定义参数 */
    VOS_UINT32                          ulParam3;                               /* 自定义参数 */
} ADS_MNTN_IP_PKT_INFO_STRU;

/*****************************************************************************
 结构名    : ADS_MNTN_UL_IP_PKT_REC_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : ADS上行IP报文记录结构
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucVer;
    VOS_UINT8                           aucRsv[3];

    VOS_UINT32                          ulRptNum;
    ADS_MNTN_IP_PKT_INFO_STRU           astIpPktRecInfo[ADS_MNTN_REC_UL_PKT_MAX_NUM];
} ADS_MNTN_UL_IP_PKT_REC_STRU;

/*****************************************************************************
 结构名    : ADS_MNTN_DL_IP_PKT_REC_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : ADS下行IP报文记录结构
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucVer;
    VOS_UINT8                           aucRsv[3];

    VOS_UINT32                          ulRptNum;
    ADS_MNTN_IP_PKT_INFO_STRU           astIpPktRecInfo[ADS_MNTN_REC_DL_PKT_MAX_NUM];
} ADS_MNTN_DL_IP_PKT_REC_STRU;


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/

VOS_VOID ADS_MNTN_ReportAllStatsInfo(VOS_VOID);
#if (defined(CONFIG_BALONG_SPE))
VOS_VOID SPE_MNTN_ReportAllStatsInfo(VOS_VOID);
#endif
VOS_VOID ADS_MNTN_HookIpPkt(
            IMM_ZC_STRU *pstImmZc, VOS_UINT16 usMsgType,
            VOS_UINT32 ulParam1, VOS_UINT32 ulParam2,
            VOS_UINT32 ulParam3, VOS_UINT32 ulParam4);

VOS_VOID ADS_MNTN_ReportULPktInfo(VOS_VOID);
VOS_VOID ADS_MNTN_ReportDLPktInfo(VOS_VOID);
VOS_VOID ADS_MNTN_DecodeIpPktInfo(
    VOS_UINT8                          *pucIpPkt,
    ADS_MNTN_IP_PKT_INFO_STRU          *pstPktInfo
);
VOS_VOID ADS_MNTN_RecULIpPktInfo(
    IMM_ZC_STRU                        *pstImmZc,
    VOS_UINT32                          ulParam1,
    VOS_UINT32                          ulParam2,
    VOS_UINT32                          ulParam3
);
VOS_VOID ADS_MNTN_RecDLIpPktInfo(
    IMM_ZC_STRU                        *pstImmZc,
    VOS_UINT32                          ulParam1,
    VOS_UINT32                          ulParam2,
    VOS_UINT32                          ulParam3
);



#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of AdsMntn.h */
