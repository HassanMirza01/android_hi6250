

#ifndef __ATCMDIMSPROC_H__
#define __ATCMDIMSPROC_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "AtCtx.h"
#include "AtParse.h"
#include "AtImsaInterface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)
#if (FEATURE_ON == FEATURE_IMS)
/*****************************************************************************
  2 宏定义
*****************************************************************************/
#define AT_IMS_PAYLOAD_TYPE_RANGE_MAX    (0x7f)
#define AT_IMS_PAYLOAD_TYPE_RANGE_MIN    (0x60)
#define AT_IMS_AMR_WB_MODE_MAX           (8)
#define AT_IMS_TIMER_DATA_RANGE_MAX      (128000)                               /* 定时器最大时长:单位(ms) */

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

/*AT与IMSA模块间消息处理函数指针*/
typedef VOS_UINT32 (*AT_IMSA_MSG_PROC_FUNC)(VOS_VOID *pMsg);

/*****************************************************************************
 结构名    : AT_IMSA_MSG_PRO_FUNC_STRU
 结构说明  : AT与IMSA消息与对应处理函数的结构
*****************************************************************************/
/*lint -e958 -e959 修改人:l60609;原因:64bit*/
typedef struct
{
    AT_IMSA_MSG_TYPE_ENUM_UINT32        ulMsgId;
    AT_IMSA_MSG_PROC_FUNC               pProcMsgFunc;
}AT_IMSA_MSG_PRO_FUNC_STRU;
/*lint +e958 +e959 修改人:l60609;原因:64bit*/

/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
VOS_VOID AT_ProcImsaMsg(AT_IMSA_MSG_STRU *pstMsg);

VOS_UINT32 AT_RcvImsaCiregSetCnf(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaCiregQryCnf(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaCirepSetCnf(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaCirepQryCnf(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaImpuSetCnf(VOS_VOID * pMsg);

VOS_UINT32 AT_SetVolteImpiPara(TAF_UINT8 ucIndex);

VOS_UINT32 AT_SetVolteDomainPara(TAF_UINT8 ucIndex);

VOS_UINT32 AT_RcvImsaVolteImpiQryCnf(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaVolteDomainQryCnf(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaCirephInd(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaCirepiInd(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaCireguInd(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaCcwaiSetCnf(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaVtPdpActInd(VOS_VOID * pMsg);
VOS_UINT32 AT_RcvImsaVtPdpDeactInd(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaMtStateInd(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaImsCtrlMsg(VOS_VOID *pMsg);

VOS_UINT32 AT_RcvImsaImsRegDomainQryCnf(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaCallEncryptSetCnf(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaRoamImsServiceQryCnf(VOS_VOID * pMsg);

VOS_UINT32 AT_RcvImsaRatHandoverInd(VOS_VOID * pMsg);
VOS_UINT32 AT_RcvSrvStatusUpdateInd(VOS_VOID * pMsg);

VOS_VOID At_FillDmdynNumParaInCmd (
    VOS_UINT16                         *pusLength,
    VOS_UINT32                          ulValue,
    VOS_UINT32                          ulValueValidFlg
);

VOS_VOID At_FillDmdynStrParaInCmd (
    VOS_UINT16                         *pusLength,
    VOS_CHAR                           *pcValue,
    VOS_UINT32                          ulValueValidFlg,
    VOS_UINT32                          ulLastParaFlg
);

VOS_VOID At_FillIpv6AddrInCmd (
    VOS_UINT16                         *pusLength,
    VOS_UINT8                          *pucAddr,
    VOS_UINT32                          ulAddrValidFlg,
    VOS_UINT32                          ulSipPort,
    VOS_UINT32                          ulPortValidFlg
);

VOS_VOID At_FillIpv4AddrInCmd (
    VOS_UINT16                         *pusLength,
    VOS_UINT8                          *pucAddr,
    VOS_UINT32                          ulAddrValidFlg,
    VOS_UINT32                          ulSipPort,
    VOS_UINT32                          ulPortValidFlg
);

VOS_UINT32 AT_RcvImsaPcscfSetCnf(
    VOS_VOID                           *pMsg
);

VOS_UINT32 AT_RcvImsaPcscfQryCnf(
    VOS_VOID                           *pMsg
);

VOS_UINT32 AT_RcvImsaDmDynSetCnf(
    VOS_VOID                           *pMsg
);

VOS_UINT32 AT_RcvImsaDmDynQryCnf(
    VOS_VOID                           *pMsg
);

VOS_UINT32 AT_RcvImsaDmcnInd(
    VOS_VOID                           *pMsg
);

VOS_UINT32 AT_ParseIpv6PcscfData(
    VOS_UINT32                         *pulAddrExistFlg,
    VOS_UINT8                          *pucIpAddr,
    VOS_UINT32                         *pulPortExistFlg,
    VOS_UINT32                         *pulPortNum,
    VOS_UINT32                          ulIndex
);

VOS_UINT32 AT_FillIpv6PcscfData(
    AT_IMSA_PCSCF_SET_REQ_STRU         *pstPcscf
);

VOS_UINT32 AT_ParseIpv4PcscfData(
    VOS_UINT32                         *pulAddrExistFlg,
    VOS_UINT8                          *pucIpAddr,
    VOS_UINT32                         *pulPortExistFlg,
    VOS_UINT32                         *pulPortNum,
    VOS_UINT32                          ulIndex
);

VOS_UINT32 AT_FillIpv4PcscfData(
    AT_IMSA_PCSCF_SET_REQ_STRU         *pstPcscf
);

VOS_UINT32 AT_FillDataToPcscf(
    AT_IMSA_PCSCF_SET_REQ_STRU         *pstPcscf
);

VOS_UINT32 AT_SetImsPcscfPara(VOS_UINT8 ucIndex);

VOS_UINT32 At_FillImsPayloadTypePara (
    VOS_UINT32                         *pulValue,
    VOS_UINT32                         *pulValueValidFlg,
    VOS_UINT32                          ulIndex
);

VOS_UINT32 At_FillImsAmrWbModePara (
    VOS_UINT32                         *pulValue,
    VOS_UINT32                         *pulValueValidFlg,
    VOS_UINT32                          ulIndex
);

VOS_UINT32 At_FillImsRtpPortPara (
    VOS_UINT32                         *pulValue,
    VOS_UINT32                         *pulValueValidFlg,
    VOS_UINT32                          ulIndex
);

VOS_UINT32 At_FillImsaNumericPara (
    VOS_UINT32                         *pulValue,
    VOS_UINT32                         *pulValueValidFlg,
    VOS_UINT32                          ulIndex
);

VOS_UINT32 At_FillImsaStrPara (
    VOS_CHAR                           *pucStr,
    VOS_UINT32                         *pulStrValidFlg,
    VOS_UINT32                          ulMaxLen,
    VOS_UINT32                          ulIndex
);

VOS_UINT32 AT_SetDmDynPara(TAF_UINT8 ucIndex);

VOS_UINT32 AT_QryImsPcscfPara(VOS_UINT8 ucIndex);

VOS_UINT32 AT_QryDmDynPara(VOS_UINT8 ucIndex);

/* Added by f00367319 for LGU+迭代一, 2016-6-21, begin */
VOS_VOID At_FillImsaTimerParaInCmd(
    VOS_UINT16                         *pusLength,
    VOS_UINT32                          ulValue,
    VOS_UINT32                          ulValueValidFlg,
    VOS_UINT32                          ulLastParaFlg
);
VOS_UINT32 AT_FillImsTimerReqBitAndPara(
    VOS_UINT32                          *pulValue,
    VOS_UINT32                          *pulBitOpValue,
    VOS_UINT32                          ulIndex
);
VOS_UINT32 AT_FillImsTimerReqData(
    AT_IMSA_IMSTIMER_SET_REQ_STRU       *pstImsTimer
);
VOS_UINT32 AT_SetImsTimerPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_SetImsSmsPsiPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryImsTimerPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryImsSmsPsiPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryDmUserPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_RcvImsaImsTimerSetCnf(VOS_VOID* pMsg);
VOS_UINT32 AT_RcvImsaImsTimerQryCnf(VOS_VOID* pMsg);
VOS_UINT32 AT_RcvImsaImsPsiSetCnf(VOS_VOID * pMsg);
VOS_UINT32 AT_RcvImsaImsPsiQryCnf(VOS_VOID * pMsg);
VOS_UINT32 AT_RcvImsaDmUserQryCnf(VOS_VOID* pMsg);

/* Added by f00367319 for LGU+迭代一, 2016-6-21, end */

VOS_UINT32 AT_SetNickNamePara(TAF_UINT8 ucIndex);
VOS_UINT32 AT_QryNickNamePara(TAF_UINT8 ucIndex);
VOS_UINT32 AT_RcvImsaNickNameSetCnf(VOS_VOID * pMsg);
VOS_UINT32 AT_RcvImsaNickNameQryCnf(VOS_VOID * pMsg);
VOS_UINT32 AT_RcvImsaImsRegFailInd(VOS_VOID * pMsg);
VOS_UINT32 AT_SetBatteryInfoPara(TAF_UINT8 ucIndex);
VOS_UINT32 AT_RcvImsaBatteryInfoSetCnf(VOS_VOID * pMsg);
VOS_UINT32 AT_QryBatteryInfoPara(TAF_UINT8 ucIndex);
VOS_UINT32 AT_SetVolteRegPara(TAF_UINT8 ucIndex);

VOS_UINT32 AT_SetImsSmsCfgPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_QryImsSmsCfgPara(VOS_UINT8 ucIndex);
VOS_UINT32 AT_RcvMmaImsSmsCfgQryCnf(
    VOS_VOID                           *pMsg
);
VOS_UINT32 AT_RcvMmaImsSmsCfgSetCnf(
    VOS_VOID                           *pMsg
);
VOS_UINT32 AT_SetImsVideoCallCancelPara(TAF_UINT8 ucIndex);
VOS_UINT32 AT_RcvImsaImsVideoCallCancelSetCnf(VOS_VOID * pMsg);

VOS_UINT32 AT_SetImsRegErrRpt(
    TAF_UINT8                           ucIndex
);

VOS_UINT32 AT_RcvImsaRegErrRptSetCnf(
    VOS_VOID                           *pMsg
);

VOS_UINT32 AT_QryImsRegErrRpt(
    TAF_UINT8                           ucIndex
);

VOS_UINT32 AT_RcvImsaRegErrRptQryCnf(
    VOS_VOID                           *pMsg
);

VOS_UINT32 AT_RcvImsaRegErrRptInd(
    VOS_VOID                           *pMsg
);

VOS_UINT32 AT_IsImsRegErrRptParaValid(
    VOS_VOID                           *pMsg
);

#endif /* end of FEATURE_IMS */
extern VOS_UINT32 AT_DigitString2Hex(
    VOS_UINT8                          *pucDigitStr,
    VOS_UINT16                          usLen,
    VOS_UINT32                         *pulDestHex
);

VOS_UINT32 At_SetEflociInfoPara(VOS_UINT8 ucIndex);
VOS_UINT32 At_QryEflociInfoPara(VOS_UINT8 ucIndex);
VOS_UINT32 At_SetPsEflociInfoPara(VOS_UINT8 ucIndex);
VOS_UINT32 At_QryPsEflociInfoPara(VOS_UINT8 ucIndex);
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

#endif /* end of AtCmdImsProc.h */

