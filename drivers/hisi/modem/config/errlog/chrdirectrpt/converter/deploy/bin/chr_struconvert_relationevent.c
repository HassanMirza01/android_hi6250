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
#include "LRrcLPhyInterface.h"
#include "LRrcLNasInterface.h"
#include "PsRrmInterface.h"
    //#include "RrcDsdsComm.h"      /*RB  complie*/
#include "LRrcPdcpInterface.h"
#include "LRrcRlcInterface.h"
#include "LRrcMacInterface.h"
#include "AppRrcInterface.h"
#include "AppRrcLteCommonInterface.h"
#include "LMacPhyInterface.h"
#include "LMac.h"
#include "LUPAppItf.h"
#include "OmCommon.h"
#include "LMacOmItf.h"
#include "LPdcpOmItf.h"
#include "LRlcOmItf.h"
#include "LTcPdcpInterface.h"
#include "AppEsmInterface.h"
#include "AppMmInterface.h"
#include "MmcLmmInterface.h"
#include "CallImsaInterface.h"
#include "MnCallApi.h"
#include "GmmLmmInterface.h"
#include "ImsaCdsInterface.h"
#include "ImsaErrlogInterface.h"
#include "SpmImsaInterface.h"
#include "ImsaMtcInterface.h"
#include "ImsaInterface.h"
#include "TTFMemCtrl.h"
#include "ImsaLmmInterface.h"
#include "SmEsmInterface.h"
#include "LRrcGrrInterface.h"
#include "LmmCssInterface.h"
#include "LmmSmsInterface.h"
#include "MmLmmInterface.h"
#include "LRrcWRrcInterface.h"
#include "CdsErabmInterface.h"
#include "CdsEtcInterface.h"
#include "CdsNdInterface.h"
#include "ApsNdInterface.h"
#include "CdsAdsInterface.h"
#include "CdsMmcInterface.h"
#include "CdsRabmInterface.h"
    //#include "mac_rlc_het.h"
    //#include "TdsLayerMsg.h"
#include "TrrcDebug.h"
#include "TrrcErrLogInterface.h"
#include "TRrcGrrInterface.h"
    // #include "TMacCsVoice.h"
#include "LRrcTRrcInterface.h"
#include "Nasrrcinterface.h"
#include "NasPdcpInterface.h"
#include "NasRlcInterface.h"
#include "GasOmInterface.h"
#include "LnasErrlogInterface.h"
#include "MsgImsaInterface.h"
#include "AtImsaInterface.h"
#include "LRrcCdmaInterface.h"
#include "LRrcCmmcaInterface.h"
#include "ImsaLrrcInterface.h"
#include "BastetCdsInterface.h"
#include "BastetRrcInterface.h"
#include "lrrccashrpdinterface.h"
#include "CssInterface.h"
#include "CssLphyInterface.h"
#include "CssNvInterface.h"
#include "CssOmInterface.h"
#include "UsimPsInterface.h"
#include "OmEmmInterface.h"
#include "OmEsmInterface.h"
#include "LUPDtItf.h"
    //#include "RrcRrcDebug.h"          /* RB3 -RB 32*/
#include "TafLcsInterface.h"
#include "CssAtInterface.h"
#include "LcsLppInterface.h"
#include "LmmLcsInterface.h"
#include "LcsMmInterface.h"
#include "AdsNdInterface.h"
    //#include "LPsTimerInterface.h"
    //#include "mac_rlc_het.h"
    //#include "pdc_rab_het.h"
#include "LPPLRrcInterface.h"
#include "VcImsaInterface.h"
    //#include "AppTPsDtInterface.h"
#include "TPsTPhyInterface.h"
#include "TdsDsdsComm.h"
#include "TdsL2Om.h"
#include "ImsaNvInterface.h"
#include "LPSCommon.h"
#include "TrrcCcb.h"
#include "TdsL2Debug.h"
#include "PsLogdef.h"
#include "TafApsApi.h"
#include "LrrcErrLogInterface.h"
#include "hids_elf_tl_stub.h"
#include "ChrEventIDComm.h"
#include "ChrRelationEvent_cfg.h"

#ifdef __cplusplus
  #if __cplusplus
  extern "C"{
  #endif
#endif


#include "ChrRelationEvent.c"

/*****************************************************************************
  2 全局变量声明
*****************************************************************************/

/*****************************************************************************
  3 函数申明
*****************************************************************************/

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

