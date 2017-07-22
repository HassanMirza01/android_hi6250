#ifndef __SOC_OTG_INTERFACE_H__
#define __SOC_OTG_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_OTG_GOTGCTL_ADDR(base) ((base) + (0x0000))
#define SOC_OTG_GOTGINT_ADDR(base) ((base) + (0x0004))
#define SOC_OTG_GAHBCFG_ADDR(base) ((base) + (0x0008))
#define SOC_OTG_GUSBCFG_ADDR(base) ((base) + (0x000C))
#define SOC_OTG_GRSTCTL_ADDR(base) ((base) + (0x0010))
#define SOC_OTG_GINTSTS_ADDR(base) ((base) + (0x0014))
#define SOC_OTG_GINTMSK_ADDR(base) ((base) + (0x0018))
#define SOC_OTG_GRXSTSR_ADDR(base) ((base) + (0x001C))
#define SOC_OTG_GRXSTSP_ADDR(base) ((base) + (0x0020))
#define SOC_OTG_GRXFSIZ_ADDR(base) ((base) + (0x0024))
#define SOC_OTG_GNPTXFSIZ_ADDR(base) ((base) + (0x0028))
#define SOC_OTG_GNPTXSTS_ADDR(base) ((base) + (0x002C))
#define SOC_OTG_GSNPSID_ADDR(base) ((base) + (0x0040))
#define SOC_OTG_GHWCFG1_ADDR(base) ((base) + (0x0044))
#define SOC_OTG_GHWCFG2_ADDR(base) ((base) + (0x0048))
#define SOC_OTG_GHWCFG3_ADDR(base) ((base) + (0x004C))
#define SOC_OTG_GHWCFG4_ADDR(base) ((base) + (0x0050))
#define SOC_OTG_GLPMCFG_ADDR(base) ((base) + (0x0054))
#define SOC_OTG_GPWRDN_ADDR(base) ((base) + (0x0058))
#define SOC_OTG_GDFIFOCFG_ADDR(base) ((base) + (0x005C))
#define SOC_OTG_GADPCTL_ADDR(base) ((base) + (0x0060))
#define SOC_OTG_HPTXFSIZ_ADDR(base) ((base) + (0x0100))
#define SOC_OTG_DIEPTXF1_ADDR(base) ((base) + (0x0104))
#define SOC_OTG_DIEPTXF2_ADDR(base) ((base) + (0x0108))
#define SOC_OTG_DIEPTXF3_ADDR(base) ((base) + (0x010C))
#define SOC_OTG_DIEPTXF4_ADDR(base) ((base) + (0x0110))
#define SOC_OTG_DIEPTXF5_ADDR(base) ((base) + (0x0114))
#define SOC_OTG_DIEPTXF6_ADDR(base) ((base) + (0x0118))
#define SOC_OTG_DIEPTXF7_ADDR(base) ((base) + (0x011C))
#define SOC_OTG_DIEPTXF8_ADDR(base) ((base) + (0x0120))
#define SOC_OTG_DIEPTXF9_ADDR(base) ((base) + (0x0124))
#define SOC_OTG_DIEPTXF10_ADDR(base) ((base) + (0x0128))
#define SOC_OTG_DIEPTXF11_ADDR(base) ((base) + (0x012C))
#define SOC_OTG_DIEPTXF12_ADDR(base) ((base) + (0x0130))
#define SOC_OTG_DIEPTXF13_ADDR(base) ((base) + (0x0134))
#define SOC_OTG_DIEPTXF14_ADDR(base) ((base) + (0x0138))
#define SOC_OTG_DIEPTXF15_ADDR(base) ((base) + (0x013C))
#define SOC_OTG_HCFG_ADDR(base) ((base) + (0x0400))
#define SOC_OTG_HFIR_ADDR(base) ((base) + (0x0404))
#define SOC_OTG_HFNUM_ADDR(base) ((base) + (0x0408))
#define SOC_OTG_HPTXSTS_ADDR(base) ((base) + (0x0410))
#define SOC_OTG_HAINT_ADDR(base) ((base) + (0x0414))
#define SOC_OTG_HAINTMSK_ADDR(base) ((base) + (0x0418))
#define SOC_OTG_HFLBAddr_ADDR(base) ((base) + (0x041C))
#define SOC_OTG_HPRT_ADDR(base) ((base) + (0x0440))
#define SOC_OTG_HCCHARp_ADDR(base,p) ((base) + (0x0500+0x20*(p)))
#define SOC_OTG_HCSPLTp_ADDR(base,p) ((base) + (0x0504+(p)*0x20))
#define SOC_OTG_HCINTp_ADDR(base,p) ((base) + (0x0508+(p)*0x20))
#define SOC_OTG_HCINTMSKp_ADDR(base,p) ((base) + (0x050C+(p)*0x20))
#define SOC_OTG_HCTSIZp_ADDR(base,p) ((base) + (0x0510+(p)*0x20))
#define SOC_OTG_HCTSIZp_non_sg_ADDR(base,p) ((base) + (0x0510+(p)*0x20))
#define SOC_OTG_HCDMAp_ADDR(base,p) ((base) + (0x0514+(p)*0x20))
#define SOC_OTG_HCDMABp_ADDR(base,p) ((base) + (0x051C+(p)*0x20))
#define SOC_OTG_DCFG_ADDR(base) ((base) + (0x0800))
#define SOC_OTG_DCTL_ADDR(base) ((base) + (0x0804))
#define SOC_OTG_DSTS_ADDR(base) ((base) + (0x0808))
#define SOC_OTG_DIEPMSK_ADDR(base) ((base) + (0x0810))
#define SOC_OTG_DOEPMSK_ADDR(base) ((base) + (0x0814))
#define SOC_OTG_DAINT_ADDR(base) ((base) + (0x0818))
#define SOC_OTG_DAINTMSK_ADDR(base) ((base) + (0x081C))
#define SOC_OTG_DVBUSDIS_ADDR(base) ((base) + (0x0828))
#define SOC_OTG_DVBUSPULSE_ADDR(base) ((base) + (0x082C))
#define SOC_OTG_DTHRCTL_ADDR(base) ((base) + (0x0830))
#define SOC_OTG_DIEPEMPMSK_ADDR(base) ((base) + (0x0834))
#define SOC_OTG_DIEPCTL0_ADDR(base) ((base) + (0x0900))
#define SOC_OTG_DIEPCTLn_ADDR(base,n) ((base) + (0x0900+0x20*(n)))
#define SOC_OTG_DIEPINTm_ADDR(base,m) ((base) + (0x0908+0x20*(m)))
#define SOC_OTG_DIEPTSIZ0_ADDR(base) ((base) + (0x0910))
#define SOC_OTG_DIEPTSIZn_ADDR(base,n) ((base) + (0x0910+0x20*(n)))
#define SOC_OTG_DIEPDMAm_ADDR(base,m) ((base) + (0x0914+0x20*(m)))
#define SOC_OTG_DTXFSTSm_ADDR(base) ((base) + (0x0918))
#define SOC_OTG_DIEPDMABn_ADDR(base,m) ((base) + (0x091C+0x20*(m)))
#define SOC_OTG_DOEPCTL0_ADDR(base) ((base) + (0x0B00))
#define SOC_OTG_DOEPCTLn_ADDR(base,n) ((base) + (0x0B00+0x20*(n)))
#define SOC_OTG_DOEPINTm_ADDR(base,m) ((base) + (0x0B08+0x20*(m)))
#define SOC_OTG_DOEPTSIZ0_ADDR(base) ((base) + (0x0B10))
#define SOC_OTG_DOEPTSIZn_ADDR(base,n) ((base) + (0x0B10+0x20*(n)))
#define SOC_OTG_DOEPDMAm_ADDR(base,m) ((base) + (0x0B14+0x20*(m)))
#define SOC_OTG_DOEPDMABm_ADDR(base,m) ((base) + (0x0B1C+0x20*(m)))
#define SOC_OTG_PCGCCTL_ADDR(base) ((base) + (0x0E00))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SesReqScs : 1;
        unsigned int SesReq : 1;
        unsigned int VbvalidOvEn : 1;
        unsigned int VbvalidOvVal : 1;
        unsigned int AvalidOvEn : 1;
        unsigned int AvalidOvVal : 1;
        unsigned int BvalidOvEn : 1;
        unsigned int BvalidOvVal : 1;
        unsigned int HstNegScs : 1;
        unsigned int HNPReq : 1;
        unsigned int HstSetHNPEn : 1;
        unsigned int DevHNPEn : 1;
        unsigned int EHEn : 1;
        unsigned int reserved_0 : 2;
        unsigned int DbnceFltrBypass : 1;
        unsigned int conidsts : 1;
        unsigned int dbnc_time : 1;
        unsigned int asessvld : 1;
        unsigned int bsesvld : 1;
        unsigned int otg_version : 1;
        unsigned int reserved_1 : 1;
        unsigned int multvaldidbc : 5;
        unsigned int chirpen : 1;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_OTG_GOTGCTL_UNION;
#endif
#define SOC_OTG_GOTGCTL_SesReqScs_START (0)
#define SOC_OTG_GOTGCTL_SesReqScs_END (0)
#define SOC_OTG_GOTGCTL_SesReq_START (1)
#define SOC_OTG_GOTGCTL_SesReq_END (1)
#define SOC_OTG_GOTGCTL_VbvalidOvEn_START (2)
#define SOC_OTG_GOTGCTL_VbvalidOvEn_END (2)
#define SOC_OTG_GOTGCTL_VbvalidOvVal_START (3)
#define SOC_OTG_GOTGCTL_VbvalidOvVal_END (3)
#define SOC_OTG_GOTGCTL_AvalidOvEn_START (4)
#define SOC_OTG_GOTGCTL_AvalidOvEn_END (4)
#define SOC_OTG_GOTGCTL_AvalidOvVal_START (5)
#define SOC_OTG_GOTGCTL_AvalidOvVal_END (5)
#define SOC_OTG_GOTGCTL_BvalidOvEn_START (6)
#define SOC_OTG_GOTGCTL_BvalidOvEn_END (6)
#define SOC_OTG_GOTGCTL_BvalidOvVal_START (7)
#define SOC_OTG_GOTGCTL_BvalidOvVal_END (7)
#define SOC_OTG_GOTGCTL_HstNegScs_START (8)
#define SOC_OTG_GOTGCTL_HstNegScs_END (8)
#define SOC_OTG_GOTGCTL_HNPReq_START (9)
#define SOC_OTG_GOTGCTL_HNPReq_END (9)
#define SOC_OTG_GOTGCTL_HstSetHNPEn_START (10)
#define SOC_OTG_GOTGCTL_HstSetHNPEn_END (10)
#define SOC_OTG_GOTGCTL_DevHNPEn_START (11)
#define SOC_OTG_GOTGCTL_DevHNPEn_END (11)
#define SOC_OTG_GOTGCTL_EHEn_START (12)
#define SOC_OTG_GOTGCTL_EHEn_END (12)
#define SOC_OTG_GOTGCTL_DbnceFltrBypass_START (15)
#define SOC_OTG_GOTGCTL_DbnceFltrBypass_END (15)
#define SOC_OTG_GOTGCTL_conidsts_START (16)
#define SOC_OTG_GOTGCTL_conidsts_END (16)
#define SOC_OTG_GOTGCTL_dbnc_time_START (17)
#define SOC_OTG_GOTGCTL_dbnc_time_END (17)
#define SOC_OTG_GOTGCTL_asessvld_START (18)
#define SOC_OTG_GOTGCTL_asessvld_END (18)
#define SOC_OTG_GOTGCTL_bsesvld_START (19)
#define SOC_OTG_GOTGCTL_bsesvld_END (19)
#define SOC_OTG_GOTGCTL_otg_version_START (20)
#define SOC_OTG_GOTGCTL_otg_version_END (20)
#define SOC_OTG_GOTGCTL_multvaldidbc_START (22)
#define SOC_OTG_GOTGCTL_multvaldidbc_END (26)
#define SOC_OTG_GOTGCTL_chirpen_START (27)
#define SOC_OTG_GOTGCTL_chirpen_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int SesEndDet : 1;
        unsigned int reserved_1 : 5;
        unsigned int SesReqSucStsChng : 1;
        unsigned int HstNegSucStsChng : 1;
        unsigned int reserved_2 : 7;
        unsigned int HstNegDet : 1;
        unsigned int ADevTOUTChg : 1;
        unsigned int DbnceDone : 1;
        unsigned int MultValIDChng : 1;
        unsigned int reserved_3 : 11;
    } reg;
} SOC_OTG_GOTGINT_UNION;
#endif
#define SOC_OTG_GOTGINT_SesEndDet_START (2)
#define SOC_OTG_GOTGINT_SesEndDet_END (2)
#define SOC_OTG_GOTGINT_SesReqSucStsChng_START (8)
#define SOC_OTG_GOTGINT_SesReqSucStsChng_END (8)
#define SOC_OTG_GOTGINT_HstNegSucStsChng_START (9)
#define SOC_OTG_GOTGINT_HstNegSucStsChng_END (9)
#define SOC_OTG_GOTGINT_HstNegDet_START (17)
#define SOC_OTG_GOTGINT_HstNegDet_END (17)
#define SOC_OTG_GOTGINT_ADevTOUTChg_START (18)
#define SOC_OTG_GOTGINT_ADevTOUTChg_END (18)
#define SOC_OTG_GOTGINT_DbnceDone_START (19)
#define SOC_OTG_GOTGINT_DbnceDone_END (19)
#define SOC_OTG_GOTGINT_MultValIDChng_START (20)
#define SOC_OTG_GOTGINT_MultValIDChng_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GlblIntrMsk : 1;
        unsigned int HBstLen : 4;
        unsigned int DMAEn : 1;
        unsigned int reserved_0 : 1;
        unsigned int NPTxFEmpLvl : 1;
        unsigned int reserved_1 : 13;
        unsigned int RemMemSupp : 1;
        unsigned int NotiAllDmaWrit : 1;
        unsigned int AHBsingle : 1;
        unsigned int InvDescEndianness : 1;
        unsigned int reserved_2 : 7;
    } reg;
} SOC_OTG_GAHBCFG_UNION;
#endif
#define SOC_OTG_GAHBCFG_GlblIntrMsk_START (0)
#define SOC_OTG_GAHBCFG_GlblIntrMsk_END (0)
#define SOC_OTG_GAHBCFG_HBstLen_START (1)
#define SOC_OTG_GAHBCFG_HBstLen_END (4)
#define SOC_OTG_GAHBCFG_DMAEn_START (5)
#define SOC_OTG_GAHBCFG_DMAEn_END (5)
#define SOC_OTG_GAHBCFG_NPTxFEmpLvl_START (7)
#define SOC_OTG_GAHBCFG_NPTxFEmpLvl_END (7)
#define SOC_OTG_GAHBCFG_RemMemSupp_START (21)
#define SOC_OTG_GAHBCFG_RemMemSupp_END (21)
#define SOC_OTG_GAHBCFG_NotiAllDmaWrit_START (22)
#define SOC_OTG_GAHBCFG_NotiAllDmaWrit_END (22)
#define SOC_OTG_GAHBCFG_AHBsingle_START (23)
#define SOC_OTG_GAHBCFG_AHBsingle_END (23)
#define SOC_OTG_GAHBCFG_InvDescEndianness_START (24)
#define SOC_OTG_GAHBCFG_InvDescEndianness_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int TOutCal : 3;
        unsigned int PHYIf : 1;
        unsigned int ULPI_UTMI_Sel : 1;
        unsigned int FSIntf : 1;
        unsigned int PHYSel : 1;
        unsigned int DDRSel : 1;
        unsigned int SRPCap : 1;
        unsigned int HNPCap : 1;
        unsigned int USBTrdTim : 4;
        unsigned int reserved : 1;
        unsigned int PhyPwrClkSel : 1;
        unsigned int Otgl2CSel : 1;
        unsigned int ULPIFsLs : 1;
        unsigned int ULPIAutoRes : 1;
        unsigned int ULPIClkSusM : 1;
        unsigned int ULPIExVbusDrv : 1;
        unsigned int ULPIExtVbusIndicator : 1;
        unsigned int TermSelDLPulse : 1;
        unsigned int Complement : 1;
        unsigned int Indicator : 1;
        unsigned int ULPI : 1;
        unsigned int IC_USBCap : 1;
        unsigned int IC_USBTrafCtl : 1;
        unsigned int TxEndDelay : 1;
        unsigned int ForceHstMode : 1;
        unsigned int ForceDevMode : 1;
        unsigned int CtptTxPkt : 1;
    } reg;
} SOC_OTG_GUSBCFG_UNION;
#endif
#define SOC_OTG_GUSBCFG_TOutCal_START (0)
#define SOC_OTG_GUSBCFG_TOutCal_END (2)
#define SOC_OTG_GUSBCFG_PHYIf_START (3)
#define SOC_OTG_GUSBCFG_PHYIf_END (3)
#define SOC_OTG_GUSBCFG_ULPI_UTMI_Sel_START (4)
#define SOC_OTG_GUSBCFG_ULPI_UTMI_Sel_END (4)
#define SOC_OTG_GUSBCFG_FSIntf_START (5)
#define SOC_OTG_GUSBCFG_FSIntf_END (5)
#define SOC_OTG_GUSBCFG_PHYSel_START (6)
#define SOC_OTG_GUSBCFG_PHYSel_END (6)
#define SOC_OTG_GUSBCFG_DDRSel_START (7)
#define SOC_OTG_GUSBCFG_DDRSel_END (7)
#define SOC_OTG_GUSBCFG_SRPCap_START (8)
#define SOC_OTG_GUSBCFG_SRPCap_END (8)
#define SOC_OTG_GUSBCFG_HNPCap_START (9)
#define SOC_OTG_GUSBCFG_HNPCap_END (9)
#define SOC_OTG_GUSBCFG_USBTrdTim_START (10)
#define SOC_OTG_GUSBCFG_USBTrdTim_END (13)
#define SOC_OTG_GUSBCFG_PhyPwrClkSel_START (15)
#define SOC_OTG_GUSBCFG_PhyPwrClkSel_END (15)
#define SOC_OTG_GUSBCFG_Otgl2CSel_START (16)
#define SOC_OTG_GUSBCFG_Otgl2CSel_END (16)
#define SOC_OTG_GUSBCFG_ULPIFsLs_START (17)
#define SOC_OTG_GUSBCFG_ULPIFsLs_END (17)
#define SOC_OTG_GUSBCFG_ULPIAutoRes_START (18)
#define SOC_OTG_GUSBCFG_ULPIAutoRes_END (18)
#define SOC_OTG_GUSBCFG_ULPIClkSusM_START (19)
#define SOC_OTG_GUSBCFG_ULPIClkSusM_END (19)
#define SOC_OTG_GUSBCFG_ULPIExVbusDrv_START (20)
#define SOC_OTG_GUSBCFG_ULPIExVbusDrv_END (20)
#define SOC_OTG_GUSBCFG_ULPIExtVbusIndicator_START (21)
#define SOC_OTG_GUSBCFG_ULPIExtVbusIndicator_END (21)
#define SOC_OTG_GUSBCFG_TermSelDLPulse_START (22)
#define SOC_OTG_GUSBCFG_TermSelDLPulse_END (22)
#define SOC_OTG_GUSBCFG_Complement_START (23)
#define SOC_OTG_GUSBCFG_Complement_END (23)
#define SOC_OTG_GUSBCFG_Indicator_START (24)
#define SOC_OTG_GUSBCFG_Indicator_END (24)
#define SOC_OTG_GUSBCFG_ULPI_START (25)
#define SOC_OTG_GUSBCFG_ULPI_END (25)
#define SOC_OTG_GUSBCFG_IC_USBCap_START (26)
#define SOC_OTG_GUSBCFG_IC_USBCap_END (26)
#define SOC_OTG_GUSBCFG_IC_USBTrafCtl_START (27)
#define SOC_OTG_GUSBCFG_IC_USBTrafCtl_END (27)
#define SOC_OTG_GUSBCFG_TxEndDelay_START (28)
#define SOC_OTG_GUSBCFG_TxEndDelay_END (28)
#define SOC_OTG_GUSBCFG_ForceHstMode_START (29)
#define SOC_OTG_GUSBCFG_ForceHstMode_END (29)
#define SOC_OTG_GUSBCFG_ForceDevMode_START (30)
#define SOC_OTG_GUSBCFG_ForceDevMode_END (30)
#define SOC_OTG_GUSBCFG_CtptTxPkt_START (31)
#define SOC_OTG_GUSBCFG_CtptTxPkt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CSftRst : 1;
        unsigned int reserved_0 : 1;
        unsigned int FrmCntrRst : 1;
        unsigned int reserved_1 : 1;
        unsigned int RxFFlsh : 1;
        unsigned int TxFFlsh : 1;
        unsigned int TxFNum : 5;
        unsigned int reserved_2 : 19;
        unsigned int DMAReq : 1;
        unsigned int AHBIdle : 1;
    } reg;
} SOC_OTG_GRSTCTL_UNION;
#endif
#define SOC_OTG_GRSTCTL_CSftRst_START (0)
#define SOC_OTG_GRSTCTL_CSftRst_END (0)
#define SOC_OTG_GRSTCTL_FrmCntrRst_START (2)
#define SOC_OTG_GRSTCTL_FrmCntrRst_END (2)
#define SOC_OTG_GRSTCTL_RxFFlsh_START (4)
#define SOC_OTG_GRSTCTL_RxFFlsh_END (4)
#define SOC_OTG_GRSTCTL_TxFFlsh_START (5)
#define SOC_OTG_GRSTCTL_TxFFlsh_END (5)
#define SOC_OTG_GRSTCTL_TxFNum_START (6)
#define SOC_OTG_GRSTCTL_TxFNum_END (10)
#define SOC_OTG_GRSTCTL_DMAReq_START (30)
#define SOC_OTG_GRSTCTL_DMAReq_END (30)
#define SOC_OTG_GRSTCTL_AHBIdle_START (31)
#define SOC_OTG_GRSTCTL_AHBIdle_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CurMode : 1;
        unsigned int ModeMis : 1;
        unsigned int OTGInt : 1;
        unsigned int Sof : 1;
        unsigned int RxFLvl : 1;
        unsigned int NPTxFEmp : 1;
        unsigned int GINNakEff : 1;
        unsigned int GOUTNakEff : 1;
        unsigned int ULPICKINT : 1;
        unsigned int I2CINT : 1;
        unsigned int ErlySusp : 1;
        unsigned int USBSusp : 1;
        unsigned int USBRst : 1;
        unsigned int EnumDone : 1;
        unsigned int ISOOutDrop : 1;
        unsigned int EOPF : 1;
        unsigned int RstrDoneInt : 1;
        unsigned int reserved : 1;
        unsigned int IEPInt : 1;
        unsigned int OEPInt : 1;
        unsigned int incompISOIN : 1;
        unsigned int incompISOOUT : 1;
        unsigned int FetSusp : 1;
        unsigned int ResetDet : 1;
        unsigned int HPrtInt : 1;
        unsigned int HChInt : 1;
        unsigned int PTxFEmp : 1;
        unsigned int LPM_Int : 1;
        unsigned int ConIDStsChg : 1;
        unsigned int DisconnInt : 1;
        unsigned int SessReqInt : 1;
        unsigned int WkUpInt : 1;
    } reg;
} SOC_OTG_GINTSTS_UNION;
#endif
#define SOC_OTG_GINTSTS_CurMode_START (0)
#define SOC_OTG_GINTSTS_CurMode_END (0)
#define SOC_OTG_GINTSTS_ModeMis_START (1)
#define SOC_OTG_GINTSTS_ModeMis_END (1)
#define SOC_OTG_GINTSTS_OTGInt_START (2)
#define SOC_OTG_GINTSTS_OTGInt_END (2)
#define SOC_OTG_GINTSTS_Sof_START (3)
#define SOC_OTG_GINTSTS_Sof_END (3)
#define SOC_OTG_GINTSTS_RxFLvl_START (4)
#define SOC_OTG_GINTSTS_RxFLvl_END (4)
#define SOC_OTG_GINTSTS_NPTxFEmp_START (5)
#define SOC_OTG_GINTSTS_NPTxFEmp_END (5)
#define SOC_OTG_GINTSTS_GINNakEff_START (6)
#define SOC_OTG_GINTSTS_GINNakEff_END (6)
#define SOC_OTG_GINTSTS_GOUTNakEff_START (7)
#define SOC_OTG_GINTSTS_GOUTNakEff_END (7)
#define SOC_OTG_GINTSTS_ULPICKINT_START (8)
#define SOC_OTG_GINTSTS_ULPICKINT_END (8)
#define SOC_OTG_GINTSTS_I2CINT_START (9)
#define SOC_OTG_GINTSTS_I2CINT_END (9)
#define SOC_OTG_GINTSTS_ErlySusp_START (10)
#define SOC_OTG_GINTSTS_ErlySusp_END (10)
#define SOC_OTG_GINTSTS_USBSusp_START (11)
#define SOC_OTG_GINTSTS_USBSusp_END (11)
#define SOC_OTG_GINTSTS_USBRst_START (12)
#define SOC_OTG_GINTSTS_USBRst_END (12)
#define SOC_OTG_GINTSTS_EnumDone_START (13)
#define SOC_OTG_GINTSTS_EnumDone_END (13)
#define SOC_OTG_GINTSTS_ISOOutDrop_START (14)
#define SOC_OTG_GINTSTS_ISOOutDrop_END (14)
#define SOC_OTG_GINTSTS_EOPF_START (15)
#define SOC_OTG_GINTSTS_EOPF_END (15)
#define SOC_OTG_GINTSTS_RstrDoneInt_START (16)
#define SOC_OTG_GINTSTS_RstrDoneInt_END (16)
#define SOC_OTG_GINTSTS_IEPInt_START (18)
#define SOC_OTG_GINTSTS_IEPInt_END (18)
#define SOC_OTG_GINTSTS_OEPInt_START (19)
#define SOC_OTG_GINTSTS_OEPInt_END (19)
#define SOC_OTG_GINTSTS_incompISOIN_START (20)
#define SOC_OTG_GINTSTS_incompISOIN_END (20)
#define SOC_OTG_GINTSTS_incompISOOUT_START (21)
#define SOC_OTG_GINTSTS_incompISOOUT_END (21)
#define SOC_OTG_GINTSTS_FetSusp_START (22)
#define SOC_OTG_GINTSTS_FetSusp_END (22)
#define SOC_OTG_GINTSTS_ResetDet_START (23)
#define SOC_OTG_GINTSTS_ResetDet_END (23)
#define SOC_OTG_GINTSTS_HPrtInt_START (24)
#define SOC_OTG_GINTSTS_HPrtInt_END (24)
#define SOC_OTG_GINTSTS_HChInt_START (25)
#define SOC_OTG_GINTSTS_HChInt_END (25)
#define SOC_OTG_GINTSTS_PTxFEmp_START (26)
#define SOC_OTG_GINTSTS_PTxFEmp_END (26)
#define SOC_OTG_GINTSTS_LPM_Int_START (27)
#define SOC_OTG_GINTSTS_LPM_Int_END (27)
#define SOC_OTG_GINTSTS_ConIDStsChg_START (28)
#define SOC_OTG_GINTSTS_ConIDStsChg_END (28)
#define SOC_OTG_GINTSTS_DisconnInt_START (29)
#define SOC_OTG_GINTSTS_DisconnInt_END (29)
#define SOC_OTG_GINTSTS_SessReqInt_START (30)
#define SOC_OTG_GINTSTS_SessReqInt_END (30)
#define SOC_OTG_GINTSTS_WkUpInt_START (31)
#define SOC_OTG_GINTSTS_WkUpInt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 1;
        unsigned int ModeMisMsk : 1;
        unsigned int OTGIntMsk : 1;
        unsigned int SofMsk : 1;
        unsigned int RxFLvlMsk : 1;
        unsigned int NPTxFEmpMsk : 1;
        unsigned int GINNakEffMsk : 1;
        unsigned int GOUTNakEffMsk : 1;
        unsigned int ULPICKINTMsk : 1;
        unsigned int I2CIntMsk : 1;
        unsigned int ErlySuspMsk : 1;
        unsigned int USBSuspMsk : 1;
        unsigned int USBRstMsk : 1;
        unsigned int EnumDoneMsk : 1;
        unsigned int ISOOutDropMsk : 1;
        unsigned int EOPFMsk : 1;
        unsigned int RstrDoneMsk : 1;
        unsigned int EPMisMsk : 1;
        unsigned int IEPIntMsk : 1;
        unsigned int OEPIntMsk : 1;
        unsigned int incompISOINMsk : 1;
        unsigned int incompISOOUTMsk : 1;
        unsigned int FetSuspMsk : 1;
        unsigned int ResetDetMsk : 1;
        unsigned int HPrtIntMsk : 1;
        unsigned int HChIntMsk : 1;
        unsigned int PTxFEmpMsk : 1;
        unsigned int LPM_IntMsk : 1;
        unsigned int ConIDStsChngMsk : 1;
        unsigned int DisconnIntMsk : 1;
        unsigned int SessReqIntMsk : 1;
        unsigned int WkUpIntMsk : 1;
    } reg;
} SOC_OTG_GINTMSK_UNION;
#endif
#define SOC_OTG_GINTMSK_ModeMisMsk_START (1)
#define SOC_OTG_GINTMSK_ModeMisMsk_END (1)
#define SOC_OTG_GINTMSK_OTGIntMsk_START (2)
#define SOC_OTG_GINTMSK_OTGIntMsk_END (2)
#define SOC_OTG_GINTMSK_SofMsk_START (3)
#define SOC_OTG_GINTMSK_SofMsk_END (3)
#define SOC_OTG_GINTMSK_RxFLvlMsk_START (4)
#define SOC_OTG_GINTMSK_RxFLvlMsk_END (4)
#define SOC_OTG_GINTMSK_NPTxFEmpMsk_START (5)
#define SOC_OTG_GINTMSK_NPTxFEmpMsk_END (5)
#define SOC_OTG_GINTMSK_GINNakEffMsk_START (6)
#define SOC_OTG_GINTMSK_GINNakEffMsk_END (6)
#define SOC_OTG_GINTMSK_GOUTNakEffMsk_START (7)
#define SOC_OTG_GINTMSK_GOUTNakEffMsk_END (7)
#define SOC_OTG_GINTMSK_ULPICKINTMsk_START (8)
#define SOC_OTG_GINTMSK_ULPICKINTMsk_END (8)
#define SOC_OTG_GINTMSK_I2CIntMsk_START (9)
#define SOC_OTG_GINTMSK_I2CIntMsk_END (9)
#define SOC_OTG_GINTMSK_ErlySuspMsk_START (10)
#define SOC_OTG_GINTMSK_ErlySuspMsk_END (10)
#define SOC_OTG_GINTMSK_USBSuspMsk_START (11)
#define SOC_OTG_GINTMSK_USBSuspMsk_END (11)
#define SOC_OTG_GINTMSK_USBRstMsk_START (12)
#define SOC_OTG_GINTMSK_USBRstMsk_END (12)
#define SOC_OTG_GINTMSK_EnumDoneMsk_START (13)
#define SOC_OTG_GINTMSK_EnumDoneMsk_END (13)
#define SOC_OTG_GINTMSK_ISOOutDropMsk_START (14)
#define SOC_OTG_GINTMSK_ISOOutDropMsk_END (14)
#define SOC_OTG_GINTMSK_EOPFMsk_START (15)
#define SOC_OTG_GINTMSK_EOPFMsk_END (15)
#define SOC_OTG_GINTMSK_RstrDoneMsk_START (16)
#define SOC_OTG_GINTMSK_RstrDoneMsk_END (16)
#define SOC_OTG_GINTMSK_EPMisMsk_START (17)
#define SOC_OTG_GINTMSK_EPMisMsk_END (17)
#define SOC_OTG_GINTMSK_IEPIntMsk_START (18)
#define SOC_OTG_GINTMSK_IEPIntMsk_END (18)
#define SOC_OTG_GINTMSK_OEPIntMsk_START (19)
#define SOC_OTG_GINTMSK_OEPIntMsk_END (19)
#define SOC_OTG_GINTMSK_incompISOINMsk_START (20)
#define SOC_OTG_GINTMSK_incompISOINMsk_END (20)
#define SOC_OTG_GINTMSK_incompISOOUTMsk_START (21)
#define SOC_OTG_GINTMSK_incompISOOUTMsk_END (21)
#define SOC_OTG_GINTMSK_FetSuspMsk_START (22)
#define SOC_OTG_GINTMSK_FetSuspMsk_END (22)
#define SOC_OTG_GINTMSK_ResetDetMsk_START (23)
#define SOC_OTG_GINTMSK_ResetDetMsk_END (23)
#define SOC_OTG_GINTMSK_HPrtIntMsk_START (24)
#define SOC_OTG_GINTMSK_HPrtIntMsk_END (24)
#define SOC_OTG_GINTMSK_HChIntMsk_START (25)
#define SOC_OTG_GINTMSK_HChIntMsk_END (25)
#define SOC_OTG_GINTMSK_PTxFEmpMsk_START (26)
#define SOC_OTG_GINTMSK_PTxFEmpMsk_END (26)
#define SOC_OTG_GINTMSK_LPM_IntMsk_START (27)
#define SOC_OTG_GINTMSK_LPM_IntMsk_END (27)
#define SOC_OTG_GINTMSK_ConIDStsChngMsk_START (28)
#define SOC_OTG_GINTMSK_ConIDStsChngMsk_END (28)
#define SOC_OTG_GINTMSK_DisconnIntMsk_START (29)
#define SOC_OTG_GINTMSK_DisconnIntMsk_END (29)
#define SOC_OTG_GINTMSK_SessReqIntMsk_START (30)
#define SOC_OTG_GINTMSK_SessReqIntMsk_END (30)
#define SOC_OTG_GINTMSK_WkUpIntMsk_START (31)
#define SOC_OTG_GINTMSK_WkUpIntMsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ChNum : 4;
        unsigned int BCnt : 11;
        unsigned int DPID : 2;
        unsigned int PktSts : 4;
        unsigned int reserved : 11;
    } reg;
} SOC_OTG_GRXSTSR_UNION;
#endif
#define SOC_OTG_GRXSTSR_ChNum_START (0)
#define SOC_OTG_GRXSTSR_ChNum_END (3)
#define SOC_OTG_GRXSTSR_BCnt_START (4)
#define SOC_OTG_GRXSTSR_BCnt_END (14)
#define SOC_OTG_GRXSTSR_DPID_START (15)
#define SOC_OTG_GRXSTSR_DPID_END (16)
#define SOC_OTG_GRXSTSR_PktSts_START (17)
#define SOC_OTG_GRXSTSR_PktSts_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int EPNum : 4;
        unsigned int BCnt : 11;
        unsigned int DPID : 2;
        unsigned int PktSts : 4;
        unsigned int FN : 4;
        unsigned int reserved : 7;
    } reg;
} SOC_OTG_GRXSTSP_UNION;
#endif
#define SOC_OTG_GRXSTSP_EPNum_START (0)
#define SOC_OTG_GRXSTSP_EPNum_END (3)
#define SOC_OTG_GRXSTSP_BCnt_START (4)
#define SOC_OTG_GRXSTSP_BCnt_END (14)
#define SOC_OTG_GRXSTSP_DPID_START (15)
#define SOC_OTG_GRXSTSP_DPID_END (16)
#define SOC_OTG_GRXSTSP_PktSts_START (17)
#define SOC_OTG_GRXSTSP_PktSts_END (20)
#define SOC_OTG_GRXSTSP_FN_START (21)
#define SOC_OTG_GRXSTSP_FN_END (24)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RxFDep : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_OTG_GRXFSIZ_UNION;
#endif
#define SOC_OTG_GRXFSIZ_RxFDep_START (0)
#define SOC_OTG_GRXFSIZ_RxFDep_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NPTxFStAddr : 16;
        unsigned int NPTxFDep : 16;
    } reg;
} SOC_OTG_GNPTXFSIZ_UNION;
#endif
#define SOC_OTG_GNPTXFSIZ_NPTxFStAddr_START (0)
#define SOC_OTG_GNPTXFSIZ_NPTxFStAddr_END (15)
#define SOC_OTG_GNPTXFSIZ_NPTxFDep_START (16)
#define SOC_OTG_GNPTXFSIZ_NPTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NPTxFSpcAvail : 16;
        unsigned int NPTxQSpcAvail : 8;
        unsigned int NPTxQTop : 7;
        unsigned int reserved : 1;
    } reg;
} SOC_OTG_GNPTXSTS_UNION;
#endif
#define SOC_OTG_GNPTXSTS_NPTxFSpcAvail_START (0)
#define SOC_OTG_GNPTXSTS_NPTxFSpcAvail_END (15)
#define SOC_OTG_GNPTXSTS_NPTxQSpcAvail_START (16)
#define SOC_OTG_GNPTXSTS_NPTxQSpcAvail_END (23)
#define SOC_OTG_GNPTXSTS_NPTxQTop_START (24)
#define SOC_OTG_GNPTXSTS_NPTxQTop_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int UserID : 32;
    } reg;
} SOC_OTG_GSNPSID_UNION;
#endif
#define SOC_OTG_GSNPSID_UserID_START (0)
#define SOC_OTG_GSNPSID_UserID_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int epdir : 32;
    } reg;
} SOC_OTG_GHWCFG1_UNION;
#endif
#define SOC_OTG_GHWCFG1_epdir_START (0)
#define SOC_OTG_GHWCFG1_epdir_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int OtgMode : 3;
        unsigned int OtgArch : 2;
        unsigned int SingPnt : 1;
        unsigned int HSPhyType : 2;
        unsigned int FSPhyType : 2;
        unsigned int NumDevEps : 4;
        unsigned int NumHstChnl : 4;
        unsigned int PerioSupport : 1;
        unsigned int DynFifoSizing : 1;
        unsigned int MultiProcIntrpt : 1;
        unsigned int reserved : 1;
        unsigned int NPTxQDepth : 2;
        unsigned int PTxQDepth : 2;
        unsigned int TknQDepth : 5;
        unsigned int OTG_IC_USB : 1;
    } reg;
} SOC_OTG_GHWCFG2_UNION;
#endif
#define SOC_OTG_GHWCFG2_OtgMode_START (0)
#define SOC_OTG_GHWCFG2_OtgMode_END (2)
#define SOC_OTG_GHWCFG2_OtgArch_START (3)
#define SOC_OTG_GHWCFG2_OtgArch_END (4)
#define SOC_OTG_GHWCFG2_SingPnt_START (5)
#define SOC_OTG_GHWCFG2_SingPnt_END (5)
#define SOC_OTG_GHWCFG2_HSPhyType_START (6)
#define SOC_OTG_GHWCFG2_HSPhyType_END (7)
#define SOC_OTG_GHWCFG2_FSPhyType_START (8)
#define SOC_OTG_GHWCFG2_FSPhyType_END (9)
#define SOC_OTG_GHWCFG2_NumDevEps_START (10)
#define SOC_OTG_GHWCFG2_NumDevEps_END (13)
#define SOC_OTG_GHWCFG2_NumHstChnl_START (14)
#define SOC_OTG_GHWCFG2_NumHstChnl_END (17)
#define SOC_OTG_GHWCFG2_PerioSupport_START (18)
#define SOC_OTG_GHWCFG2_PerioSupport_END (18)
#define SOC_OTG_GHWCFG2_DynFifoSizing_START (19)
#define SOC_OTG_GHWCFG2_DynFifoSizing_END (19)
#define SOC_OTG_GHWCFG2_MultiProcIntrpt_START (20)
#define SOC_OTG_GHWCFG2_MultiProcIntrpt_END (20)
#define SOC_OTG_GHWCFG2_NPTxQDepth_START (22)
#define SOC_OTG_GHWCFG2_NPTxQDepth_END (23)
#define SOC_OTG_GHWCFG2_PTxQDepth_START (24)
#define SOC_OTG_GHWCFG2_PTxQDepth_END (25)
#define SOC_OTG_GHWCFG2_TknQDepth_START (26)
#define SOC_OTG_GHWCFG2_TknQDepth_END (30)
#define SOC_OTG_GHWCFG2_OTG_IC_USB_START (31)
#define SOC_OTG_GHWCFG2_OTG_IC_USB_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int XferSizeWidth : 4;
        unsigned int PktSizeWidth : 3;
        unsigned int OtgEn : 1;
        unsigned int I2CIntSel : 1;
        unsigned int VndctlSupt : 1;
        unsigned int OptFeature : 1;
        unsigned int RstType : 1;
        unsigned int OTG_ADP_SUPPORT : 1;
        unsigned int OTG_ENABLE_HSIC : 1;
        unsigned int OTG_BC_SUPPORT : 1;
        unsigned int OTG_ENABLE_LPM : 1;
        unsigned int DfifoDepth : 16;
    } reg;
} SOC_OTG_GHWCFG3_UNION;
#endif
#define SOC_OTG_GHWCFG3_XferSizeWidth_START (0)
#define SOC_OTG_GHWCFG3_XferSizeWidth_END (3)
#define SOC_OTG_GHWCFG3_PktSizeWidth_START (4)
#define SOC_OTG_GHWCFG3_PktSizeWidth_END (6)
#define SOC_OTG_GHWCFG3_OtgEn_START (7)
#define SOC_OTG_GHWCFG3_OtgEn_END (7)
#define SOC_OTG_GHWCFG3_I2CIntSel_START (8)
#define SOC_OTG_GHWCFG3_I2CIntSel_END (8)
#define SOC_OTG_GHWCFG3_VndctlSupt_START (9)
#define SOC_OTG_GHWCFG3_VndctlSupt_END (9)
#define SOC_OTG_GHWCFG3_OptFeature_START (10)
#define SOC_OTG_GHWCFG3_OptFeature_END (10)
#define SOC_OTG_GHWCFG3_RstType_START (11)
#define SOC_OTG_GHWCFG3_RstType_END (11)
#define SOC_OTG_GHWCFG3_OTG_ADP_SUPPORT_START (12)
#define SOC_OTG_GHWCFG3_OTG_ADP_SUPPORT_END (12)
#define SOC_OTG_GHWCFG3_OTG_ENABLE_HSIC_START (13)
#define SOC_OTG_GHWCFG3_OTG_ENABLE_HSIC_END (13)
#define SOC_OTG_GHWCFG3_OTG_BC_SUPPORT_START (14)
#define SOC_OTG_GHWCFG3_OTG_BC_SUPPORT_END (14)
#define SOC_OTG_GHWCFG3_OTG_ENABLE_LPM_START (15)
#define SOC_OTG_GHWCFG3_OTG_ENABLE_LPM_END (15)
#define SOC_OTG_GHWCFG3_DfifoDepth_START (16)
#define SOC_OTG_GHWCFG3_DfifoDepth_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NumDevEps : 4;
        unsigned int EnablePwrOpt : 1;
        unsigned int AhbFreq : 1;
        unsigned int Hibernation : 1;
        unsigned int ExtndedHibernation : 1;
        unsigned int reserved_0 : 6;
        unsigned int PhyDataWidth : 2;
        unsigned int NumCtlEps : 4;
        unsigned int IddigFltr : 1;
        unsigned int VBusValidFltr : 1;
        unsigned int AValidFltr : 1;
        unsigned int BValidFltr : 1;
        unsigned int SessEndFltr : 1;
        unsigned int DedFifoMode : 1;
        unsigned int INEps : 4;
        unsigned int SGDMA : 1;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_OTG_GHWCFG4_UNION;
#endif
#define SOC_OTG_GHWCFG4_NumDevEps_START (0)
#define SOC_OTG_GHWCFG4_NumDevEps_END (3)
#define SOC_OTG_GHWCFG4_EnablePwrOpt_START (4)
#define SOC_OTG_GHWCFG4_EnablePwrOpt_END (4)
#define SOC_OTG_GHWCFG4_AhbFreq_START (5)
#define SOC_OTG_GHWCFG4_AhbFreq_END (5)
#define SOC_OTG_GHWCFG4_Hibernation_START (6)
#define SOC_OTG_GHWCFG4_Hibernation_END (6)
#define SOC_OTG_GHWCFG4_ExtndedHibernation_START (7)
#define SOC_OTG_GHWCFG4_ExtndedHibernation_END (7)
#define SOC_OTG_GHWCFG4_PhyDataWidth_START (14)
#define SOC_OTG_GHWCFG4_PhyDataWidth_END (15)
#define SOC_OTG_GHWCFG4_NumCtlEps_START (16)
#define SOC_OTG_GHWCFG4_NumCtlEps_END (19)
#define SOC_OTG_GHWCFG4_IddigFltr_START (20)
#define SOC_OTG_GHWCFG4_IddigFltr_END (20)
#define SOC_OTG_GHWCFG4_VBusValidFltr_START (21)
#define SOC_OTG_GHWCFG4_VBusValidFltr_END (21)
#define SOC_OTG_GHWCFG4_AValidFltr_START (22)
#define SOC_OTG_GHWCFG4_AValidFltr_END (22)
#define SOC_OTG_GHWCFG4_BValidFltr_START (23)
#define SOC_OTG_GHWCFG4_BValidFltr_END (23)
#define SOC_OTG_GHWCFG4_SessEndFltr_START (24)
#define SOC_OTG_GHWCFG4_SessEndFltr_END (24)
#define SOC_OTG_GHWCFG4_DedFifoMode_START (25)
#define SOC_OTG_GHWCFG4_DedFifoMode_END (25)
#define SOC_OTG_GHWCFG4_INEps_START (26)
#define SOC_OTG_GHWCFG4_INEps_END (29)
#define SOC_OTG_GHWCFG4_SGDMA_START (30)
#define SOC_OTG_GHWCFG4_SGDMA_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int LPMCap : 1;
        unsigned int APPL1Res : 1;
        unsigned int HIRD : 4;
        unsigned int bRemoteWake : 1;
        unsigned int EnblSlpM : 1;
        unsigned int HIRD_Thres : 5;
        unsigned int CoreL1Res : 2;
        unsigned int SlpSts : 1;
        unsigned int L1ResumeOk : 1;
        unsigned int LPM_Chnl_Index : 4;
        unsigned int LPM_Retry_Cnt : 3;
        unsigned int SndLPM : 1;
        unsigned int LPM_RetryCnt_Sts : 3;
        unsigned int EnBESL : 1;
        unsigned int RstrSlpSts : 1;
        unsigned int HSICCon : 1;
        unsigned int InvSelHsic : 1;
    } reg;
} SOC_OTG_GLPMCFG_UNION;
#endif
#define SOC_OTG_GLPMCFG_LPMCap_START (0)
#define SOC_OTG_GLPMCFG_LPMCap_END (0)
#define SOC_OTG_GLPMCFG_APPL1Res_START (1)
#define SOC_OTG_GLPMCFG_APPL1Res_END (1)
#define SOC_OTG_GLPMCFG_HIRD_START (2)
#define SOC_OTG_GLPMCFG_HIRD_END (5)
#define SOC_OTG_GLPMCFG_bRemoteWake_START (6)
#define SOC_OTG_GLPMCFG_bRemoteWake_END (6)
#define SOC_OTG_GLPMCFG_EnblSlpM_START (7)
#define SOC_OTG_GLPMCFG_EnblSlpM_END (7)
#define SOC_OTG_GLPMCFG_HIRD_Thres_START (8)
#define SOC_OTG_GLPMCFG_HIRD_Thres_END (12)
#define SOC_OTG_GLPMCFG_CoreL1Res_START (13)
#define SOC_OTG_GLPMCFG_CoreL1Res_END (14)
#define SOC_OTG_GLPMCFG_SlpSts_START (15)
#define SOC_OTG_GLPMCFG_SlpSts_END (15)
#define SOC_OTG_GLPMCFG_L1ResumeOk_START (16)
#define SOC_OTG_GLPMCFG_L1ResumeOk_END (16)
#define SOC_OTG_GLPMCFG_LPM_Chnl_Index_START (17)
#define SOC_OTG_GLPMCFG_LPM_Chnl_Index_END (20)
#define SOC_OTG_GLPMCFG_LPM_Retry_Cnt_START (21)
#define SOC_OTG_GLPMCFG_LPM_Retry_Cnt_END (23)
#define SOC_OTG_GLPMCFG_SndLPM_START (24)
#define SOC_OTG_GLPMCFG_SndLPM_END (24)
#define SOC_OTG_GLPMCFG_LPM_RetryCnt_Sts_START (25)
#define SOC_OTG_GLPMCFG_LPM_RetryCnt_Sts_END (27)
#define SOC_OTG_GLPMCFG_EnBESL_START (28)
#define SOC_OTG_GLPMCFG_EnBESL_END (28)
#define SOC_OTG_GLPMCFG_RstrSlpSts_START (29)
#define SOC_OTG_GLPMCFG_RstrSlpSts_END (29)
#define SOC_OTG_GLPMCFG_HSICCon_START (30)
#define SOC_OTG_GLPMCFG_HSICCon_END (30)
#define SOC_OTG_GLPMCFG_InvSelHsic_START (31)
#define SOC_OTG_GLPMCFG_InvSelHsic_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PMUIntSel : 1;
        unsigned int PMUActv : 1;
        unsigned int Restore : 1;
        unsigned int PwrDnClmp : 1;
        unsigned int PwrDnRst_n : 1;
        unsigned int PwrDnSwtch : 1;
        unsigned int VbusOff : 1;
        unsigned int LnStsChng : 1;
        unsigned int LnStsChngMsk : 1;
        unsigned int ResetDetected : 1;
        unsigned int ResetDetMsk : 1;
        unsigned int DisconnectDetect : 1;
        unsigned int DisconnectDetectMsk : 1;
        unsigned int ConnectDet : 1;
        unsigned int ConnDetMsk : 1;
        unsigned int SRPDetect : 1;
        unsigned int SRPDetectMsk : 1;
        unsigned int StsChngInt : 1;
        unsigned int StsChngMsk : 1;
        unsigned int LineState : 2;
        unsigned int IDDIG : 1;
        unsigned int BSessVld : 1;
        unsigned int ADPInt : 1;
        unsigned int MultValIdBc : 5;
        unsigned int reserved : 3;
    } reg;
} SOC_OTG_GPWRDN_UNION;
#endif
#define SOC_OTG_GPWRDN_PMUIntSel_START (0)
#define SOC_OTG_GPWRDN_PMUIntSel_END (0)
#define SOC_OTG_GPWRDN_PMUActv_START (1)
#define SOC_OTG_GPWRDN_PMUActv_END (1)
#define SOC_OTG_GPWRDN_Restore_START (2)
#define SOC_OTG_GPWRDN_Restore_END (2)
#define SOC_OTG_GPWRDN_PwrDnClmp_START (3)
#define SOC_OTG_GPWRDN_PwrDnClmp_END (3)
#define SOC_OTG_GPWRDN_PwrDnRst_n_START (4)
#define SOC_OTG_GPWRDN_PwrDnRst_n_END (4)
#define SOC_OTG_GPWRDN_PwrDnSwtch_START (5)
#define SOC_OTG_GPWRDN_PwrDnSwtch_END (5)
#define SOC_OTG_GPWRDN_VbusOff_START (6)
#define SOC_OTG_GPWRDN_VbusOff_END (6)
#define SOC_OTG_GPWRDN_LnStsChng_START (7)
#define SOC_OTG_GPWRDN_LnStsChng_END (7)
#define SOC_OTG_GPWRDN_LnStsChngMsk_START (8)
#define SOC_OTG_GPWRDN_LnStsChngMsk_END (8)
#define SOC_OTG_GPWRDN_ResetDetected_START (9)
#define SOC_OTG_GPWRDN_ResetDetected_END (9)
#define SOC_OTG_GPWRDN_ResetDetMsk_START (10)
#define SOC_OTG_GPWRDN_ResetDetMsk_END (10)
#define SOC_OTG_GPWRDN_DisconnectDetect_START (11)
#define SOC_OTG_GPWRDN_DisconnectDetect_END (11)
#define SOC_OTG_GPWRDN_DisconnectDetectMsk_START (12)
#define SOC_OTG_GPWRDN_DisconnectDetectMsk_END (12)
#define SOC_OTG_GPWRDN_ConnectDet_START (13)
#define SOC_OTG_GPWRDN_ConnectDet_END (13)
#define SOC_OTG_GPWRDN_ConnDetMsk_START (14)
#define SOC_OTG_GPWRDN_ConnDetMsk_END (14)
#define SOC_OTG_GPWRDN_SRPDetect_START (15)
#define SOC_OTG_GPWRDN_SRPDetect_END (15)
#define SOC_OTG_GPWRDN_SRPDetectMsk_START (16)
#define SOC_OTG_GPWRDN_SRPDetectMsk_END (16)
#define SOC_OTG_GPWRDN_StsChngInt_START (17)
#define SOC_OTG_GPWRDN_StsChngInt_END (17)
#define SOC_OTG_GPWRDN_StsChngMsk_START (18)
#define SOC_OTG_GPWRDN_StsChngMsk_END (18)
#define SOC_OTG_GPWRDN_LineState_START (19)
#define SOC_OTG_GPWRDN_LineState_END (20)
#define SOC_OTG_GPWRDN_IDDIG_START (21)
#define SOC_OTG_GPWRDN_IDDIG_END (21)
#define SOC_OTG_GPWRDN_BSessVld_START (22)
#define SOC_OTG_GPWRDN_BSessVld_END (22)
#define SOC_OTG_GPWRDN_ADPInt_START (23)
#define SOC_OTG_GPWRDN_ADPInt_END (23)
#define SOC_OTG_GPWRDN_MultValIdBc_START (24)
#define SOC_OTG_GPWRDN_MultValIdBc_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int GDFIFOCfg : 16;
        unsigned int EPInfoBaseAddr : 16;
    } reg;
} SOC_OTG_GDFIFOCFG_UNION;
#endif
#define SOC_OTG_GDFIFOCFG_GDFIFOCfg_START (0)
#define SOC_OTG_GDFIFOCFG_GDFIFOCfg_END (15)
#define SOC_OTG_GDFIFOCFG_EPInfoBaseAddr_START (16)
#define SOC_OTG_GDFIFOCFG_EPInfoBaseAddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PrbDschng : 2;
        unsigned int PrbDelta : 2;
        unsigned int PrbPer : 2;
        unsigned int RTIM : 11;
        unsigned int EnaPrb : 1;
        unsigned int EnaSns : 1;
        unsigned int ADPRes : 1;
        unsigned int ADPEn : 1;
        unsigned int AdpPrbInt : 1;
        unsigned int AdpSnsInt : 1;
        unsigned int AdpTmoutInt : 1;
        unsigned int AdpPrbIntMsk : 1;
        unsigned int AdpSnsIntMsk : 1;
        unsigned int AdpTmoutMsk : 1;
        unsigned int AR : 2;
        unsigned int reserved : 3;
    } reg;
} SOC_OTG_GADPCTL_UNION;
#endif
#define SOC_OTG_GADPCTL_PrbDschng_START (0)
#define SOC_OTG_GADPCTL_PrbDschng_END (1)
#define SOC_OTG_GADPCTL_PrbDelta_START (2)
#define SOC_OTG_GADPCTL_PrbDelta_END (3)
#define SOC_OTG_GADPCTL_PrbPer_START (4)
#define SOC_OTG_GADPCTL_PrbPer_END (5)
#define SOC_OTG_GADPCTL_RTIM_START (6)
#define SOC_OTG_GADPCTL_RTIM_END (16)
#define SOC_OTG_GADPCTL_EnaPrb_START (17)
#define SOC_OTG_GADPCTL_EnaPrb_END (17)
#define SOC_OTG_GADPCTL_EnaSns_START (18)
#define SOC_OTG_GADPCTL_EnaSns_END (18)
#define SOC_OTG_GADPCTL_ADPRes_START (19)
#define SOC_OTG_GADPCTL_ADPRes_END (19)
#define SOC_OTG_GADPCTL_ADPEn_START (20)
#define SOC_OTG_GADPCTL_ADPEn_END (20)
#define SOC_OTG_GADPCTL_AdpPrbInt_START (21)
#define SOC_OTG_GADPCTL_AdpPrbInt_END (21)
#define SOC_OTG_GADPCTL_AdpSnsInt_START (22)
#define SOC_OTG_GADPCTL_AdpSnsInt_END (22)
#define SOC_OTG_GADPCTL_AdpTmoutInt_START (23)
#define SOC_OTG_GADPCTL_AdpTmoutInt_END (23)
#define SOC_OTG_GADPCTL_AdpPrbIntMsk_START (24)
#define SOC_OTG_GADPCTL_AdpPrbIntMsk_END (24)
#define SOC_OTG_GADPCTL_AdpSnsIntMsk_START (25)
#define SOC_OTG_GADPCTL_AdpSnsIntMsk_END (25)
#define SOC_OTG_GADPCTL_AdpTmoutMsk_START (26)
#define SOC_OTG_GADPCTL_AdpTmoutMsk_END (26)
#define SOC_OTG_GADPCTL_AR_START (27)
#define SOC_OTG_GADPCTL_AR_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PTxFStAddr : 16;
        unsigned int PTxFSize : 16;
    } reg;
} SOC_OTG_HPTXFSIZ_UNION;
#endif
#define SOC_OTG_HPTXFSIZ_PTxFStAddr_START (0)
#define SOC_OTG_HPTXFSIZ_PTxFStAddr_END (15)
#define SOC_OTG_HPTXFSIZ_PTxFSize_START (16)
#define SOC_OTG_HPTXFSIZ_PTxFSize_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF1_UNION;
#endif
#define SOC_OTG_DIEPTXF1_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF1_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF1_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF1_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF2_UNION;
#endif
#define SOC_OTG_DIEPTXF2_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF2_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF2_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF2_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF3_UNION;
#endif
#define SOC_OTG_DIEPTXF3_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF3_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF3_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF3_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF4_UNION;
#endif
#define SOC_OTG_DIEPTXF4_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF4_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF4_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF4_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF5_UNION;
#endif
#define SOC_OTG_DIEPTXF5_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF5_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF5_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF5_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF6_UNION;
#endif
#define SOC_OTG_DIEPTXF6_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF6_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF6_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF6_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF7_UNION;
#endif
#define SOC_OTG_DIEPTXF7_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF7_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF7_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF7_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF8_UNION;
#endif
#define SOC_OTG_DIEPTXF8_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF8_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF8_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF8_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF9_UNION;
#endif
#define SOC_OTG_DIEPTXF9_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF9_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF9_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF9_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF10_UNION;
#endif
#define SOC_OTG_DIEPTXF10_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF10_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF10_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF10_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF11_UNION;
#endif
#define SOC_OTG_DIEPTXF11_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF11_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF11_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF11_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF12_UNION;
#endif
#define SOC_OTG_DIEPTXF12_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF12_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF12_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF12_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF13_UNION;
#endif
#define SOC_OTG_DIEPTXF13_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF13_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF13_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF13_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF14_UNION;
#endif
#define SOC_OTG_DIEPTXF14_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF14_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF14_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF14_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPnTxFStAddr : 16;
        unsigned int INEPnTxFDep : 16;
    } reg;
} SOC_OTG_DIEPTXF15_UNION;
#endif
#define SOC_OTG_DIEPTXF15_INEPnTxFStAddr_START (0)
#define SOC_OTG_DIEPTXF15_INEPnTxFStAddr_END (15)
#define SOC_OTG_DIEPTXF15_INEPnTxFDep_START (16)
#define SOC_OTG_DIEPTXF15_INEPnTxFDep_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FSLSPclkSel : 2;
        unsigned int FSLSSupp : 1;
        unsigned int reserved_0 : 4;
        unsigned int Ena32KHzS : 1;
        unsigned int ResValid : 8;
        unsigned int reserved_1 : 7;
        unsigned int DescDMA : 1;
        unsigned int FrListEn : 2;
        unsigned int PerSchedEna : 1;
        unsigned int resered : 4;
        unsigned int ModeChTimEn : 1;
    } reg;
} SOC_OTG_HCFG_UNION;
#endif
#define SOC_OTG_HCFG_FSLSPclkSel_START (0)
#define SOC_OTG_HCFG_FSLSPclkSel_END (1)
#define SOC_OTG_HCFG_FSLSSupp_START (2)
#define SOC_OTG_HCFG_FSLSSupp_END (2)
#define SOC_OTG_HCFG_Ena32KHzS_START (7)
#define SOC_OTG_HCFG_Ena32KHzS_END (7)
#define SOC_OTG_HCFG_ResValid_START (8)
#define SOC_OTG_HCFG_ResValid_END (15)
#define SOC_OTG_HCFG_DescDMA_START (23)
#define SOC_OTG_HCFG_DescDMA_END (23)
#define SOC_OTG_HCFG_FrListEn_START (24)
#define SOC_OTG_HCFG_FrListEn_END (25)
#define SOC_OTG_HCFG_PerSchedEna_START (26)
#define SOC_OTG_HCFG_PerSchedEna_END (26)
#define SOC_OTG_HCFG_resered_START (27)
#define SOC_OTG_HCFG_resered_END (30)
#define SOC_OTG_HCFG_ModeChTimEn_START (31)
#define SOC_OTG_HCFG_ModeChTimEn_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FrInt : 16;
        unsigned int HFIRRldCtrl : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_OTG_HFIR_UNION;
#endif
#define SOC_OTG_HFIR_FrInt_START (0)
#define SOC_OTG_HFIR_FrInt_END (15)
#define SOC_OTG_HFIR_HFIRRldCtrl_START (16)
#define SOC_OTG_HFIR_HFIRRldCtrl_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int FrNum : 16;
        unsigned int FrRem : 16;
    } reg;
} SOC_OTG_HFNUM_UNION;
#endif
#define SOC_OTG_HFNUM_FrNum_START (0)
#define SOC_OTG_HFNUM_FrNum_END (15)
#define SOC_OTG_HFNUM_FrRem_START (16)
#define SOC_OTG_HFNUM_FrRem_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PTxSpcAvail : 16;
        unsigned int PTxQSpcAvail : 8;
        unsigned int PTxQTop : 8;
    } reg;
} SOC_OTG_HPTXSTS_UNION;
#endif
#define SOC_OTG_HPTXSTS_PTxSpcAvail_START (0)
#define SOC_OTG_HPTXSTS_PTxSpcAvail_END (15)
#define SOC_OTG_HPTXSTS_PTxQSpcAvail_START (16)
#define SOC_OTG_HPTXSTS_PTxQSpcAvail_END (23)
#define SOC_OTG_HPTXSTS_PTxQTop_START (24)
#define SOC_OTG_HPTXSTS_PTxQTop_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int HAINT : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_OTG_HAINT_UNION;
#endif
#define SOC_OTG_HAINT_HAINT_START (0)
#define SOC_OTG_HAINT_HAINT_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int HAINTMsk : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_OTG_HAINTMSK_UNION;
#endif
#define SOC_OTG_HAINTMSK_HAINTMsk_START (0)
#define SOC_OTG_HAINTMSK_HAINTMsk_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int HFLBAddr : 32;
    } reg;
} SOC_OTG_HFLBAddr_UNION;
#endif
#define SOC_OTG_HFLBAddr_HFLBAddr_START (0)
#define SOC_OTG_HFLBAddr_HFLBAddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PrtConnSts : 1;
        unsigned int PrtConnDet : 1;
        unsigned int PrtEna : 1;
        unsigned int PrtEnChng : 1;
        unsigned int PrtOvrCurrAct : 1;
        unsigned int PrtOvrCurrChng : 1;
        unsigned int PrtRes : 1;
        unsigned int PrtSusp : 1;
        unsigned int PrtRst : 1;
        unsigned int reserved_0 : 1;
        unsigned int PrtLnSts : 2;
        unsigned int PrtPwr : 1;
        unsigned int PrtTstCtl : 4;
        unsigned int PrtSpd : 2;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_OTG_HPRT_UNION;
#endif
#define SOC_OTG_HPRT_PrtConnSts_START (0)
#define SOC_OTG_HPRT_PrtConnSts_END (0)
#define SOC_OTG_HPRT_PrtConnDet_START (1)
#define SOC_OTG_HPRT_PrtConnDet_END (1)
#define SOC_OTG_HPRT_PrtEna_START (2)
#define SOC_OTG_HPRT_PrtEna_END (2)
#define SOC_OTG_HPRT_PrtEnChng_START (3)
#define SOC_OTG_HPRT_PrtEnChng_END (3)
#define SOC_OTG_HPRT_PrtOvrCurrAct_START (4)
#define SOC_OTG_HPRT_PrtOvrCurrAct_END (4)
#define SOC_OTG_HPRT_PrtOvrCurrChng_START (5)
#define SOC_OTG_HPRT_PrtOvrCurrChng_END (5)
#define SOC_OTG_HPRT_PrtRes_START (6)
#define SOC_OTG_HPRT_PrtRes_END (6)
#define SOC_OTG_HPRT_PrtSusp_START (7)
#define SOC_OTG_HPRT_PrtSusp_END (7)
#define SOC_OTG_HPRT_PrtRst_START (8)
#define SOC_OTG_HPRT_PrtRst_END (8)
#define SOC_OTG_HPRT_PrtLnSts_START (10)
#define SOC_OTG_HPRT_PrtLnSts_END (11)
#define SOC_OTG_HPRT_PrtPwr_START (12)
#define SOC_OTG_HPRT_PrtPwr_END (12)
#define SOC_OTG_HPRT_PrtTstCtl_START (13)
#define SOC_OTG_HPRT_PrtTstCtl_END (16)
#define SOC_OTG_HPRT_PrtSpd_START (17)
#define SOC_OTG_HPRT_PrtSpd_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MPS : 11;
        unsigned int EPNum : 4;
        unsigned int EPDir : 1;
        unsigned int reserved : 1;
        unsigned int LSpdDev : 1;
        unsigned int EPType : 2;
        unsigned int MC_EC : 2;
        unsigned int DevAddr : 7;
        unsigned int OddFrm : 1;
        unsigned int ChDis : 1;
        unsigned int ChEna : 1;
    } reg;
} SOC_OTG_HCCHARp_UNION;
#endif
#define SOC_OTG_HCCHARp_MPS_START (0)
#define SOC_OTG_HCCHARp_MPS_END (10)
#define SOC_OTG_HCCHARp_EPNum_START (11)
#define SOC_OTG_HCCHARp_EPNum_END (14)
#define SOC_OTG_HCCHARp_EPDir_START (15)
#define SOC_OTG_HCCHARp_EPDir_END (15)
#define SOC_OTG_HCCHARp_LSpdDev_START (17)
#define SOC_OTG_HCCHARp_LSpdDev_END (17)
#define SOC_OTG_HCCHARp_EPType_START (18)
#define SOC_OTG_HCCHARp_EPType_END (19)
#define SOC_OTG_HCCHARp_MC_EC_START (20)
#define SOC_OTG_HCCHARp_MC_EC_END (21)
#define SOC_OTG_HCCHARp_DevAddr_START (22)
#define SOC_OTG_HCCHARp_DevAddr_END (28)
#define SOC_OTG_HCCHARp_OddFrm_START (29)
#define SOC_OTG_HCCHARp_OddFrm_END (29)
#define SOC_OTG_HCCHARp_ChDis_START (30)
#define SOC_OTG_HCCHARp_ChDis_END (30)
#define SOC_OTG_HCCHARp_ChEna_START (31)
#define SOC_OTG_HCCHARp_ChEna_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int PrtAddr : 7;
        unsigned int HubAddr : 7;
        unsigned int XactPos : 2;
        unsigned int CompSplt : 1;
        unsigned int reserved : 14;
        unsigned int SpltEna : 1;
    } reg;
} SOC_OTG_HCSPLTp_UNION;
#endif
#define SOC_OTG_HCSPLTp_PrtAddr_START (0)
#define SOC_OTG_HCSPLTp_PrtAddr_END (6)
#define SOC_OTG_HCSPLTp_HubAddr_START (7)
#define SOC_OTG_HCSPLTp_HubAddr_END (13)
#define SOC_OTG_HCSPLTp_XactPos_START (14)
#define SOC_OTG_HCSPLTp_XactPos_END (15)
#define SOC_OTG_HCSPLTp_CompSplt_START (16)
#define SOC_OTG_HCSPLTp_CompSplt_END (16)
#define SOC_OTG_HCSPLTp_SpltEna_START (31)
#define SOC_OTG_HCSPLTp_SpltEna_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int XferCompl : 1;
        unsigned int ChHlted : 1;
        unsigned int AHBErr : 1;
        unsigned int STALL : 1;
        unsigned int NAK : 1;
        unsigned int ACK : 1;
        unsigned int NYET : 1;
        unsigned int XactErr : 1;
        unsigned int BblErr : 1;
        unsigned int FrmOvrun : 1;
        unsigned int DataTglErr : 1;
        unsigned int BNAIntr : 1;
        unsigned int XCS_XACT_ERR : 1;
        unsigned int DESC_LST_ROLLIntr : 1;
        unsigned int reserved : 18;
    } reg;
} SOC_OTG_HCINTp_UNION;
#endif
#define SOC_OTG_HCINTp_XferCompl_START (0)
#define SOC_OTG_HCINTp_XferCompl_END (0)
#define SOC_OTG_HCINTp_ChHlted_START (1)
#define SOC_OTG_HCINTp_ChHlted_END (1)
#define SOC_OTG_HCINTp_AHBErr_START (2)
#define SOC_OTG_HCINTp_AHBErr_END (2)
#define SOC_OTG_HCINTp_STALL_START (3)
#define SOC_OTG_HCINTp_STALL_END (3)
#define SOC_OTG_HCINTp_NAK_START (4)
#define SOC_OTG_HCINTp_NAK_END (4)
#define SOC_OTG_HCINTp_ACK_START (5)
#define SOC_OTG_HCINTp_ACK_END (5)
#define SOC_OTG_HCINTp_NYET_START (6)
#define SOC_OTG_HCINTp_NYET_END (6)
#define SOC_OTG_HCINTp_XactErr_START (7)
#define SOC_OTG_HCINTp_XactErr_END (7)
#define SOC_OTG_HCINTp_BblErr_START (8)
#define SOC_OTG_HCINTp_BblErr_END (8)
#define SOC_OTG_HCINTp_FrmOvrun_START (9)
#define SOC_OTG_HCINTp_FrmOvrun_END (9)
#define SOC_OTG_HCINTp_DataTglErr_START (10)
#define SOC_OTG_HCINTp_DataTglErr_END (10)
#define SOC_OTG_HCINTp_BNAIntr_START (11)
#define SOC_OTG_HCINTp_BNAIntr_END (11)
#define SOC_OTG_HCINTp_XCS_XACT_ERR_START (12)
#define SOC_OTG_HCINTp_XCS_XACT_ERR_END (12)
#define SOC_OTG_HCINTp_DESC_LST_ROLLIntr_START (13)
#define SOC_OTG_HCINTp_DESC_LST_ROLLIntr_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int XferCompl : 1;
        unsigned int ChHlted : 1;
        unsigned int AHBErr : 1;
        unsigned int STALL : 1;
        unsigned int NAK : 1;
        unsigned int ACK : 1;
        unsigned int NYET : 1;
        unsigned int XactErr : 1;
        unsigned int BblErr : 1;
        unsigned int FrmOvrunMsk : 1;
        unsigned int DataTglErrMsk : 1;
        unsigned int BNAIntrMsk : 1;
        unsigned int reserved_0 : 1;
        unsigned int DESC_LST_ROLLIntrMsk : 1;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_OTG_HCINTMSKp_UNION;
#endif
#define SOC_OTG_HCINTMSKp_XferCompl_START (0)
#define SOC_OTG_HCINTMSKp_XferCompl_END (0)
#define SOC_OTG_HCINTMSKp_ChHlted_START (1)
#define SOC_OTG_HCINTMSKp_ChHlted_END (1)
#define SOC_OTG_HCINTMSKp_AHBErr_START (2)
#define SOC_OTG_HCINTMSKp_AHBErr_END (2)
#define SOC_OTG_HCINTMSKp_STALL_START (3)
#define SOC_OTG_HCINTMSKp_STALL_END (3)
#define SOC_OTG_HCINTMSKp_NAK_START (4)
#define SOC_OTG_HCINTMSKp_NAK_END (4)
#define SOC_OTG_HCINTMSKp_ACK_START (5)
#define SOC_OTG_HCINTMSKp_ACK_END (5)
#define SOC_OTG_HCINTMSKp_NYET_START (6)
#define SOC_OTG_HCINTMSKp_NYET_END (6)
#define SOC_OTG_HCINTMSKp_XactErr_START (7)
#define SOC_OTG_HCINTMSKp_XactErr_END (7)
#define SOC_OTG_HCINTMSKp_BblErr_START (8)
#define SOC_OTG_HCINTMSKp_BblErr_END (8)
#define SOC_OTG_HCINTMSKp_FrmOvrunMsk_START (9)
#define SOC_OTG_HCINTMSKp_FrmOvrunMsk_END (9)
#define SOC_OTG_HCINTMSKp_DataTglErrMsk_START (10)
#define SOC_OTG_HCINTMSKp_DataTglErrMsk_END (10)
#define SOC_OTG_HCINTMSKp_BNAIntrMsk_START (11)
#define SOC_OTG_HCINTMSKp_BNAIntrMsk_END (11)
#define SOC_OTG_HCINTMSKp_DESC_LST_ROLLIntrMsk_START (13)
#define SOC_OTG_HCINTMSKp_DESC_LST_ROLLIntrMsk_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SCHED_INFO : 8;
        unsigned int NTD : 8;
        unsigned int reserved : 13;
        unsigned int PID : 2;
        unsigned int DoPng : 1;
    } reg;
} SOC_OTG_HCTSIZp_UNION;
#endif
#define SOC_OTG_HCTSIZp_SCHED_INFO_START (0)
#define SOC_OTG_HCTSIZp_SCHED_INFO_END (7)
#define SOC_OTG_HCTSIZp_NTD_START (8)
#define SOC_OTG_HCTSIZp_NTD_END (15)
#define SOC_OTG_HCTSIZp_PID_START (29)
#define SOC_OTG_HCTSIZp_PID_END (30)
#define SOC_OTG_HCTSIZp_DoPng_START (31)
#define SOC_OTG_HCTSIZp_DoPng_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int XferSize : 19;
        unsigned int PktCnt : 10;
        unsigned int PID : 2;
        unsigned int DoPng : 1;
    } reg;
} SOC_OTG_HCTSIZp_non_sg_UNION;
#endif
#define SOC_OTG_HCTSIZp_non_sg_XferSize_START (0)
#define SOC_OTG_HCTSIZp_non_sg_XferSize_END (18)
#define SOC_OTG_HCTSIZp_non_sg_PktCnt_START (19)
#define SOC_OTG_HCTSIZp_non_sg_PktCnt_END (28)
#define SOC_OTG_HCTSIZp_non_sg_PID_START (29)
#define SOC_OTG_HCTSIZp_non_sg_PID_END (30)
#define SOC_OTG_HCTSIZp_non_sg_DoPng_START (31)
#define SOC_OTG_HCTSIZp_non_sg_DoPng_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DMAAddr : 32;
    } reg;
} SOC_OTG_HCDMAp_UNION;
#endif
#define SOC_OTG_HCDMAp_DMAAddr_START (0)
#define SOC_OTG_HCDMAp_DMAAddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int HCDMA : 32;
    } reg;
} SOC_OTG_HCDMABp_UNION;
#endif
#define SOC_OTG_HCDMABp_HCDMA_START (0)
#define SOC_OTG_HCDMABp_HCDMA_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DevSpd : 2;
        unsigned int NZStsOUTHShk : 1;
        unsigned int reserved_0 : 1;
        unsigned int DevAddr : 7;
        unsigned int PerFrInt : 2;
        unsigned int EnDevOutNak : 1;
        unsigned int reserved_1 : 4;
        unsigned int EpMisCnt : 5;
        unsigned int DescDMA : 1;
        unsigned int PerSchIntvl : 2;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_OTG_DCFG_UNION;
#endif
#define SOC_OTG_DCFG_DevSpd_START (0)
#define SOC_OTG_DCFG_DevSpd_END (1)
#define SOC_OTG_DCFG_NZStsOUTHShk_START (2)
#define SOC_OTG_DCFG_NZStsOUTHShk_END (2)
#define SOC_OTG_DCFG_DevAddr_START (4)
#define SOC_OTG_DCFG_DevAddr_END (10)
#define SOC_OTG_DCFG_PerFrInt_START (11)
#define SOC_OTG_DCFG_PerFrInt_END (12)
#define SOC_OTG_DCFG_EnDevOutNak_START (13)
#define SOC_OTG_DCFG_EnDevOutNak_END (13)
#define SOC_OTG_DCFG_EpMisCnt_START (18)
#define SOC_OTG_DCFG_EpMisCnt_END (22)
#define SOC_OTG_DCFG_DescDMA_START (23)
#define SOC_OTG_DCFG_DescDMA_END (23)
#define SOC_OTG_DCFG_PerSchIntvl_START (24)
#define SOC_OTG_DCFG_PerSchIntvl_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int RmtWkUpSig : 1;
        unsigned int SftDiscon : 1;
        unsigned int GNPINNakSts : 1;
        unsigned int GOUTNakSts : 1;
        unsigned int TstCtl : 3;
        unsigned int SGNPInNak : 1;
        unsigned int CGNPInNak : 1;
        unsigned int SGOUTNak : 1;
        unsigned int CGOUTNak : 1;
        unsigned int PWROnPrgDone : 1;
        unsigned int reserved_0 : 1;
        unsigned int GMC : 2;
        unsigned int IgnrFrmNum : 1;
        unsigned int NakOnBble : 1;
        unsigned int EnContOnBNA : 1;
        unsigned int DeepSleepBESLReject : 1;
        unsigned int reserved_1 : 13;
    } reg;
} SOC_OTG_DCTL_UNION;
#endif
#define SOC_OTG_DCTL_RmtWkUpSig_START (0)
#define SOC_OTG_DCTL_RmtWkUpSig_END (0)
#define SOC_OTG_DCTL_SftDiscon_START (1)
#define SOC_OTG_DCTL_SftDiscon_END (1)
#define SOC_OTG_DCTL_GNPINNakSts_START (2)
#define SOC_OTG_DCTL_GNPINNakSts_END (2)
#define SOC_OTG_DCTL_GOUTNakSts_START (3)
#define SOC_OTG_DCTL_GOUTNakSts_END (3)
#define SOC_OTG_DCTL_TstCtl_START (4)
#define SOC_OTG_DCTL_TstCtl_END (6)
#define SOC_OTG_DCTL_SGNPInNak_START (7)
#define SOC_OTG_DCTL_SGNPInNak_END (7)
#define SOC_OTG_DCTL_CGNPInNak_START (8)
#define SOC_OTG_DCTL_CGNPInNak_END (8)
#define SOC_OTG_DCTL_SGOUTNak_START (9)
#define SOC_OTG_DCTL_SGOUTNak_END (9)
#define SOC_OTG_DCTL_CGOUTNak_START (10)
#define SOC_OTG_DCTL_CGOUTNak_END (10)
#define SOC_OTG_DCTL_PWROnPrgDone_START (11)
#define SOC_OTG_DCTL_PWROnPrgDone_END (11)
#define SOC_OTG_DCTL_GMC_START (13)
#define SOC_OTG_DCTL_GMC_END (14)
#define SOC_OTG_DCTL_IgnrFrmNum_START (15)
#define SOC_OTG_DCTL_IgnrFrmNum_END (15)
#define SOC_OTG_DCTL_NakOnBble_START (16)
#define SOC_OTG_DCTL_NakOnBble_END (16)
#define SOC_OTG_DCTL_EnContOnBNA_START (17)
#define SOC_OTG_DCTL_EnContOnBNA_END (17)
#define SOC_OTG_DCTL_DeepSleepBESLReject_START (18)
#define SOC_OTG_DCTL_DeepSleepBESLReject_END (18)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int SuspSts : 1;
        unsigned int EnumSpd : 2;
        unsigned int ErrticErr : 1;
        unsigned int reserved_0: 4;
        unsigned int SOFFN : 14;
        unsigned int DevLnSts : 2;
        unsigned int reserved_1: 8;
    } reg;
} SOC_OTG_DSTS_UNION;
#endif
#define SOC_OTG_DSTS_SuspSts_START (0)
#define SOC_OTG_DSTS_SuspSts_END (0)
#define SOC_OTG_DSTS_EnumSpd_START (1)
#define SOC_OTG_DSTS_EnumSpd_END (2)
#define SOC_OTG_DSTS_ErrticErr_START (3)
#define SOC_OTG_DSTS_ErrticErr_END (3)
#define SOC_OTG_DSTS_SOFFN_START (8)
#define SOC_OTG_DSTS_SOFFN_END (21)
#define SOC_OTG_DSTS_DevLnSts_START (22)
#define SOC_OTG_DSTS_DevLnSts_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int XferComplMsk : 1;
        unsigned int EPDisbldMsk : 1;
        unsigned int AHBErrMsk : 1;
        unsigned int TimeOUTMsk : 1;
        unsigned int INTknTXFEmpMsk : 1;
        unsigned int reserved_0 : 1;
        unsigned int INEPNakEffMsk : 1;
        unsigned int reserved_1 : 1;
        unsigned int TxfifoUndrnMsk : 1;
        unsigned int BNAInIntrMsk : 1;
        unsigned int reserved_2 : 3;
        unsigned int NAKMsk : 1;
        unsigned int reserved_3 : 18;
    } reg;
} SOC_OTG_DIEPMSK_UNION;
#endif
#define SOC_OTG_DIEPMSK_XferComplMsk_START (0)
#define SOC_OTG_DIEPMSK_XferComplMsk_END (0)
#define SOC_OTG_DIEPMSK_EPDisbldMsk_START (1)
#define SOC_OTG_DIEPMSK_EPDisbldMsk_END (1)
#define SOC_OTG_DIEPMSK_AHBErrMsk_START (2)
#define SOC_OTG_DIEPMSK_AHBErrMsk_END (2)
#define SOC_OTG_DIEPMSK_TimeOUTMsk_START (3)
#define SOC_OTG_DIEPMSK_TimeOUTMsk_END (3)
#define SOC_OTG_DIEPMSK_INTknTXFEmpMsk_START (4)
#define SOC_OTG_DIEPMSK_INTknTXFEmpMsk_END (4)
#define SOC_OTG_DIEPMSK_INEPNakEffMsk_START (6)
#define SOC_OTG_DIEPMSK_INEPNakEffMsk_END (6)
#define SOC_OTG_DIEPMSK_TxfifoUndrnMsk_START (8)
#define SOC_OTG_DIEPMSK_TxfifoUndrnMsk_END (8)
#define SOC_OTG_DIEPMSK_BNAInIntrMsk_START (9)
#define SOC_OTG_DIEPMSK_BNAInIntrMsk_END (9)
#define SOC_OTG_DIEPMSK_NAKMsk_START (13)
#define SOC_OTG_DIEPMSK_NAKMsk_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int XferComplMsk : 1;
        unsigned int EPDisbldMsk : 1;
        unsigned int AHBErrMsk : 1;
        unsigned int SetUPMsk : 1;
        unsigned int OUTTknEPdisMsk : 1;
        unsigned int reserved_0 : 1;
        unsigned int Back2BackSetup : 1;
        unsigned int reserved_1 : 1;
        unsigned int OutPktErrMsk : 1;
        unsigned int BNAOutIntrMsk : 1;
        unsigned int reserved_2 : 2;
        unsigned int BbleErrMsk : 1;
        unsigned int NAKMsk : 1;
        unsigned int NYETMsk : 1;
        unsigned int reserved_3 : 17;
    } reg;
} SOC_OTG_DOEPMSK_UNION;
#endif
#define SOC_OTG_DOEPMSK_XferComplMsk_START (0)
#define SOC_OTG_DOEPMSK_XferComplMsk_END (0)
#define SOC_OTG_DOEPMSK_EPDisbldMsk_START (1)
#define SOC_OTG_DOEPMSK_EPDisbldMsk_END (1)
#define SOC_OTG_DOEPMSK_AHBErrMsk_START (2)
#define SOC_OTG_DOEPMSK_AHBErrMsk_END (2)
#define SOC_OTG_DOEPMSK_SetUPMsk_START (3)
#define SOC_OTG_DOEPMSK_SetUPMsk_END (3)
#define SOC_OTG_DOEPMSK_OUTTknEPdisMsk_START (4)
#define SOC_OTG_DOEPMSK_OUTTknEPdisMsk_END (4)
#define SOC_OTG_DOEPMSK_Back2BackSetup_START (6)
#define SOC_OTG_DOEPMSK_Back2BackSetup_END (6)
#define SOC_OTG_DOEPMSK_OutPktErrMsk_START (8)
#define SOC_OTG_DOEPMSK_OutPktErrMsk_END (8)
#define SOC_OTG_DOEPMSK_BNAOutIntrMsk_START (9)
#define SOC_OTG_DOEPMSK_BNAOutIntrMsk_END (9)
#define SOC_OTG_DOEPMSK_BbleErrMsk_START (12)
#define SOC_OTG_DOEPMSK_BbleErrMsk_END (12)
#define SOC_OTG_DOEPMSK_NAKMsk_START (13)
#define SOC_OTG_DOEPMSK_NAKMsk_END (13)
#define SOC_OTG_DOEPMSK_NYETMsk_START (14)
#define SOC_OTG_DOEPMSK_NYETMsk_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int InEpInt : 16;
        unsigned int OutEpInt : 16;
    } reg;
} SOC_OTG_DAINT_UNION;
#endif
#define SOC_OTG_DAINT_InEpInt_START (0)
#define SOC_OTG_DAINT_InEpInt_END (15)
#define SOC_OTG_DAINT_OutEpInt_START (16)
#define SOC_OTG_DAINT_OutEpInt_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int InEpMsk : 16;
        unsigned int OutEpMsk : 16;
    } reg;
} SOC_OTG_DAINTMSK_UNION;
#endif
#define SOC_OTG_DAINTMSK_InEpMsk_START (0)
#define SOC_OTG_DAINTMSK_InEpMsk_END (15)
#define SOC_OTG_DAINTMSK_OutEpMsk_START (16)
#define SOC_OTG_DAINTMSK_OutEpMsk_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DVBUSDis : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_OTG_DVBUSDIS_UNION;
#endif
#define SOC_OTG_DVBUSDIS_DVBUSDis_START (0)
#define SOC_OTG_DVBUSDIS_DVBUSDis_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DVBUSPulse : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_OTG_DVBUSPULSE_UNION;
#endif
#define SOC_OTG_DVBUSPULSE_DVBUSPulse_START (0)
#define SOC_OTG_DVBUSPULSE_DVBUSPulse_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int NonISOThrEn : 1;
        unsigned int ISOThrEn : 1;
        unsigned int TxThrLen : 9;
        unsigned int AHBThrRatio : 2;
        unsigned int reserved_0 : 3;
        unsigned int RxThrEn : 1;
        unsigned int RxThrLen : 9;
        unsigned int reserved_1 : 1;
        unsigned int ArbPkEn : 1;
        unsigned int reserved_2 : 4;
    } reg;
} SOC_OTG_DTHRCTL_UNION;
#endif
#define SOC_OTG_DTHRCTL_NonISOThrEn_START (0)
#define SOC_OTG_DTHRCTL_NonISOThrEn_END (0)
#define SOC_OTG_DTHRCTL_ISOThrEn_START (1)
#define SOC_OTG_DTHRCTL_ISOThrEn_END (1)
#define SOC_OTG_DTHRCTL_TxThrLen_START (2)
#define SOC_OTG_DTHRCTL_TxThrLen_END (10)
#define SOC_OTG_DTHRCTL_AHBThrRatio_START (11)
#define SOC_OTG_DTHRCTL_AHBThrRatio_END (12)
#define SOC_OTG_DTHRCTL_RxThrEn_START (16)
#define SOC_OTG_DTHRCTL_RxThrEn_END (16)
#define SOC_OTG_DTHRCTL_RxThrLen_START (17)
#define SOC_OTG_DTHRCTL_RxThrLen_END (25)
#define SOC_OTG_DTHRCTL_ArbPkEn_START (27)
#define SOC_OTG_DTHRCTL_ArbPkEn_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int InEpTxfEmpMsk : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_OTG_DIEPEMPMSK_UNION;
#endif
#define SOC_OTG_DIEPEMPMSK_InEpTxfEmpMsk_START (0)
#define SOC_OTG_DIEPEMPMSK_InEpTxfEmpMsk_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MPS : 2;
        unsigned int reserved_0: 9;
        unsigned int NextEp : 4;
        unsigned int USBActEP : 1;
        unsigned int reserved_1: 1;
        unsigned int NAKSts : 1;
        unsigned int EPType : 2;
        unsigned int reserved_2: 1;
        unsigned int Stall : 1;
        unsigned int TxFNum : 4;
        unsigned int CNAK : 1;
        unsigned int SNAK : 1;
        unsigned int reserved_3: 2;
        unsigned int EPDis : 1;
        unsigned int EPEna : 1;
    } reg;
} SOC_OTG_DIEPCTL0_UNION;
#endif
#define SOC_OTG_DIEPCTL0_MPS_START (0)
#define SOC_OTG_DIEPCTL0_MPS_END (1)
#define SOC_OTG_DIEPCTL0_NextEp_START (11)
#define SOC_OTG_DIEPCTL0_NextEp_END (14)
#define SOC_OTG_DIEPCTL0_USBActEP_START (15)
#define SOC_OTG_DIEPCTL0_USBActEP_END (15)
#define SOC_OTG_DIEPCTL0_NAKSts_START (17)
#define SOC_OTG_DIEPCTL0_NAKSts_END (17)
#define SOC_OTG_DIEPCTL0_EPType_START (18)
#define SOC_OTG_DIEPCTL0_EPType_END (19)
#define SOC_OTG_DIEPCTL0_Stall_START (21)
#define SOC_OTG_DIEPCTL0_Stall_END (21)
#define SOC_OTG_DIEPCTL0_TxFNum_START (22)
#define SOC_OTG_DIEPCTL0_TxFNum_END (25)
#define SOC_OTG_DIEPCTL0_CNAK_START (26)
#define SOC_OTG_DIEPCTL0_CNAK_END (26)
#define SOC_OTG_DIEPCTL0_SNAK_START (27)
#define SOC_OTG_DIEPCTL0_SNAK_END (27)
#define SOC_OTG_DIEPCTL0_EPDis_START (30)
#define SOC_OTG_DIEPCTL0_EPDis_END (30)
#define SOC_OTG_DIEPCTL0_EPEna_START (31)
#define SOC_OTG_DIEPCTL0_EPEna_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MPS : 11;
        unsigned int reserved_0: 4;
        unsigned int USBActEp : 1;
        unsigned int DPID : 1;
        unsigned int NAKSts : 1;
        unsigned int EPType : 2;
        unsigned int reserved_1: 1;
        unsigned int Stall : 1;
        unsigned int TxFNum : 4;
        unsigned int CNAK : 1;
        unsigned int SNAK : 1;
        unsigned int SetD0PID : 1;
        unsigned int SetD1PID : 1;
        unsigned int EPDis : 1;
        unsigned int EPEna : 1;
    } reg;
} SOC_OTG_DIEPCTLn_UNION;
#endif
#define SOC_OTG_DIEPCTLn_MPS_START (0)
#define SOC_OTG_DIEPCTLn_MPS_END (10)
#define SOC_OTG_DIEPCTLn_USBActEp_START (15)
#define SOC_OTG_DIEPCTLn_USBActEp_END (15)
#define SOC_OTG_DIEPCTLn_DPID_START (16)
#define SOC_OTG_DIEPCTLn_DPID_END (16)
#define SOC_OTG_DIEPCTLn_NAKSts_START (17)
#define SOC_OTG_DIEPCTLn_NAKSts_END (17)
#define SOC_OTG_DIEPCTLn_EPType_START (18)
#define SOC_OTG_DIEPCTLn_EPType_END (19)
#define SOC_OTG_DIEPCTLn_Stall_START (21)
#define SOC_OTG_DIEPCTLn_Stall_END (21)
#define SOC_OTG_DIEPCTLn_TxFNum_START (22)
#define SOC_OTG_DIEPCTLn_TxFNum_END (25)
#define SOC_OTG_DIEPCTLn_CNAK_START (26)
#define SOC_OTG_DIEPCTLn_CNAK_END (26)
#define SOC_OTG_DIEPCTLn_SNAK_START (27)
#define SOC_OTG_DIEPCTLn_SNAK_END (27)
#define SOC_OTG_DIEPCTLn_SetD0PID_START (28)
#define SOC_OTG_DIEPCTLn_SetD0PID_END (28)
#define SOC_OTG_DIEPCTLn_SetD1PID_START (29)
#define SOC_OTG_DIEPCTLn_SetD1PID_END (29)
#define SOC_OTG_DIEPCTLn_EPDis_START (30)
#define SOC_OTG_DIEPCTLn_EPDis_END (30)
#define SOC_OTG_DIEPCTLn_EPEna_START (31)
#define SOC_OTG_DIEPCTLn_EPEna_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int XferCompl : 1;
        unsigned int EPDisbld : 1;
        unsigned int AHBErr : 1;
        unsigned int reserved_0 : 1;
        unsigned int INTknTXFEmp : 1;
        unsigned int reserved_1 : 1;
        unsigned int INEPNakEff : 1;
        unsigned int TxFEmp : 1;
        unsigned int TxfifoUndrn : 1;
        unsigned int BNAIntr : 1;
        unsigned int reserved_2 : 1;
        unsigned int PktDrpSts : 1;
        unsigned int BbleErr : 1;
        unsigned int NAKIntrpt : 1;
        unsigned int NYETIntrpt : 1;
        unsigned int StupPktRcvd : 1;
        unsigned int reserved_3 : 16;
    } reg;
} SOC_OTG_DIEPINTm_UNION;
#endif
#define SOC_OTG_DIEPINTm_XferCompl_START (0)
#define SOC_OTG_DIEPINTm_XferCompl_END (0)
#define SOC_OTG_DIEPINTm_EPDisbld_START (1)
#define SOC_OTG_DIEPINTm_EPDisbld_END (1)
#define SOC_OTG_DIEPINTm_AHBErr_START (2)
#define SOC_OTG_DIEPINTm_AHBErr_END (2)
#define SOC_OTG_DIEPINTm_INTknTXFEmp_START (4)
#define SOC_OTG_DIEPINTm_INTknTXFEmp_END (4)
#define SOC_OTG_DIEPINTm_INEPNakEff_START (6)
#define SOC_OTG_DIEPINTm_INEPNakEff_END (6)
#define SOC_OTG_DIEPINTm_TxFEmp_START (7)
#define SOC_OTG_DIEPINTm_TxFEmp_END (7)
#define SOC_OTG_DIEPINTm_TxfifoUndrn_START (8)
#define SOC_OTG_DIEPINTm_TxfifoUndrn_END (8)
#define SOC_OTG_DIEPINTm_BNAIntr_START (9)
#define SOC_OTG_DIEPINTm_BNAIntr_END (9)
#define SOC_OTG_DIEPINTm_PktDrpSts_START (11)
#define SOC_OTG_DIEPINTm_PktDrpSts_END (11)
#define SOC_OTG_DIEPINTm_BbleErr_START (12)
#define SOC_OTG_DIEPINTm_BbleErr_END (12)
#define SOC_OTG_DIEPINTm_NAKIntrpt_START (13)
#define SOC_OTG_DIEPINTm_NAKIntrpt_END (13)
#define SOC_OTG_DIEPINTm_NYETIntrpt_START (14)
#define SOC_OTG_DIEPINTm_NYETIntrpt_END (14)
#define SOC_OTG_DIEPINTm_StupPktRcvd_START (15)
#define SOC_OTG_DIEPINTm_StupPktRcvd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int XferSize : 7;
        unsigned int reserved_0: 12;
        unsigned int PktCnt : 2;
        unsigned int reserved_1: 11;
    } reg;
} SOC_OTG_DIEPTSIZ0_UNION;
#endif
#define SOC_OTG_DIEPTSIZ0_XferSize_START (0)
#define SOC_OTG_DIEPTSIZ0_XferSize_END (6)
#define SOC_OTG_DIEPTSIZ0_PktCnt_START (19)
#define SOC_OTG_DIEPTSIZ0_PktCnt_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int XferSize : 19;
        unsigned int PktCnt : 10;
        unsigned int MC : 2;
        unsigned int reserved : 1;
    } reg;
} SOC_OTG_DIEPTSIZn_UNION;
#endif
#define SOC_OTG_DIEPTSIZn_XferSize_START (0)
#define SOC_OTG_DIEPTSIZn_XferSize_END (18)
#define SOC_OTG_DIEPTSIZn_PktCnt_START (19)
#define SOC_OTG_DIEPTSIZn_PktCnt_END (28)
#define SOC_OTG_DIEPTSIZn_MC_START (29)
#define SOC_OTG_DIEPTSIZn_MC_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DMAADDR : 32;
    } reg;
} SOC_OTG_DIEPDMAm_UNION;
#endif
#define SOC_OTG_DIEPDMAm_DMAADDR_START (0)
#define SOC_OTG_DIEPDMAm_DMAADDR_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int INEPTxFSpcAvail : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_OTG_DTXFSTSm_UNION;
#endif
#define SOC_OTG_DTXFSTSm_INEPTxFSpcAvail_START (0)
#define SOC_OTG_DTXFSTSm_INEPTxFSpcAvail_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DMABufferAddr : 32;
    } reg;
} SOC_OTG_DIEPDMABn_UNION;
#endif
#define SOC_OTG_DIEPDMABn_DMABufferAddr_START (0)
#define SOC_OTG_DIEPDMABn_DMABufferAddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MPS : 2;
        unsigned int reserved_0: 13;
        unsigned int USBActEP : 1;
        unsigned int reserved_1: 1;
        unsigned int NAKSts : 1;
        unsigned int EPType : 2;
        unsigned int Snp : 1;
        unsigned int Stall : 1;
        unsigned int reserved_2: 4;
        unsigned int CNAK : 1;
        unsigned int SNAK : 1;
        unsigned int reserved_3: 2;
        unsigned int EPDis : 1;
        unsigned int EPEna : 1;
    } reg;
} SOC_OTG_DOEPCTL0_UNION;
#endif
#define SOC_OTG_DOEPCTL0_MPS_START (0)
#define SOC_OTG_DOEPCTL0_MPS_END (1)
#define SOC_OTG_DOEPCTL0_USBActEP_START (15)
#define SOC_OTG_DOEPCTL0_USBActEP_END (15)
#define SOC_OTG_DOEPCTL0_NAKSts_START (17)
#define SOC_OTG_DOEPCTL0_NAKSts_END (17)
#define SOC_OTG_DOEPCTL0_EPType_START (18)
#define SOC_OTG_DOEPCTL0_EPType_END (19)
#define SOC_OTG_DOEPCTL0_Snp_START (20)
#define SOC_OTG_DOEPCTL0_Snp_END (20)
#define SOC_OTG_DOEPCTL0_Stall_START (21)
#define SOC_OTG_DOEPCTL0_Stall_END (21)
#define SOC_OTG_DOEPCTL0_CNAK_START (26)
#define SOC_OTG_DOEPCTL0_CNAK_END (26)
#define SOC_OTG_DOEPCTL0_SNAK_START (27)
#define SOC_OTG_DOEPCTL0_SNAK_END (27)
#define SOC_OTG_DOEPCTL0_EPDis_START (30)
#define SOC_OTG_DOEPCTL0_EPDis_END (30)
#define SOC_OTG_DOEPCTL0_EPEna_START (31)
#define SOC_OTG_DOEPCTL0_EPEna_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int MPS : 11;
        unsigned int reserved : 4;
        unsigned int USBActEp : 1;
        unsigned int DPID : 1;
        unsigned int NAKSts : 1;
        unsigned int EPType : 2;
        unsigned int Snp : 1;
        unsigned int Stall : 1;
        unsigned int TxFNum : 4;
        unsigned int CNAK : 1;
        unsigned int SNAK : 1;
        unsigned int SetD0PID : 1;
        unsigned int SetD1PID : 1;
        unsigned int EPDis : 1;
        unsigned int EPEna : 1;
    } reg;
} SOC_OTG_DOEPCTLn_UNION;
#endif
#define SOC_OTG_DOEPCTLn_MPS_START (0)
#define SOC_OTG_DOEPCTLn_MPS_END (10)
#define SOC_OTG_DOEPCTLn_USBActEp_START (15)
#define SOC_OTG_DOEPCTLn_USBActEp_END (15)
#define SOC_OTG_DOEPCTLn_DPID_START (16)
#define SOC_OTG_DOEPCTLn_DPID_END (16)
#define SOC_OTG_DOEPCTLn_NAKSts_START (17)
#define SOC_OTG_DOEPCTLn_NAKSts_END (17)
#define SOC_OTG_DOEPCTLn_EPType_START (18)
#define SOC_OTG_DOEPCTLn_EPType_END (19)
#define SOC_OTG_DOEPCTLn_Snp_START (20)
#define SOC_OTG_DOEPCTLn_Snp_END (20)
#define SOC_OTG_DOEPCTLn_Stall_START (21)
#define SOC_OTG_DOEPCTLn_Stall_END (21)
#define SOC_OTG_DOEPCTLn_TxFNum_START (22)
#define SOC_OTG_DOEPCTLn_TxFNum_END (25)
#define SOC_OTG_DOEPCTLn_CNAK_START (26)
#define SOC_OTG_DOEPCTLn_CNAK_END (26)
#define SOC_OTG_DOEPCTLn_SNAK_START (27)
#define SOC_OTG_DOEPCTLn_SNAK_END (27)
#define SOC_OTG_DOEPCTLn_SetD0PID_START (28)
#define SOC_OTG_DOEPCTLn_SetD0PID_END (28)
#define SOC_OTG_DOEPCTLn_SetD1PID_START (29)
#define SOC_OTG_DOEPCTLn_SetD1PID_END (29)
#define SOC_OTG_DOEPCTLn_EPDis_START (30)
#define SOC_OTG_DOEPCTLn_EPDis_END (30)
#define SOC_OTG_DOEPCTLn_EPEna_START (31)
#define SOC_OTG_DOEPCTLn_EPEna_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int XferCompl : 1;
        unsigned int EPDisbld : 1;
        unsigned int AHBErr : 1;
        unsigned int reserved_0 : 1;
        unsigned int INTknTXFEmp : 1;
        unsigned int reserved_1 : 1;
        unsigned int INEPNakEff : 1;
        unsigned int reserved_2 : 1;
        unsigned int OutPktErr : 1;
        unsigned int BNAIntr : 1;
        unsigned int reserved_3 : 1;
        unsigned int PktDrpSts : 1;
        unsigned int BbleErr : 1;
        unsigned int NAKIntrpt : 1;
        unsigned int NYET : 1;
        unsigned int StupPktRcvd : 1;
        unsigned int reserved_4 : 16;
    } reg;
} SOC_OTG_DOEPINTm_UNION;
#endif
#define SOC_OTG_DOEPINTm_XferCompl_START (0)
#define SOC_OTG_DOEPINTm_XferCompl_END (0)
#define SOC_OTG_DOEPINTm_EPDisbld_START (1)
#define SOC_OTG_DOEPINTm_EPDisbld_END (1)
#define SOC_OTG_DOEPINTm_AHBErr_START (2)
#define SOC_OTG_DOEPINTm_AHBErr_END (2)
#define SOC_OTG_DOEPINTm_INTknTXFEmp_START (4)
#define SOC_OTG_DOEPINTm_INTknTXFEmp_END (4)
#define SOC_OTG_DOEPINTm_INEPNakEff_START (6)
#define SOC_OTG_DOEPINTm_INEPNakEff_END (6)
#define SOC_OTG_DOEPINTm_OutPktErr_START (8)
#define SOC_OTG_DOEPINTm_OutPktErr_END (8)
#define SOC_OTG_DOEPINTm_BNAIntr_START (9)
#define SOC_OTG_DOEPINTm_BNAIntr_END (9)
#define SOC_OTG_DOEPINTm_PktDrpSts_START (11)
#define SOC_OTG_DOEPINTm_PktDrpSts_END (11)
#define SOC_OTG_DOEPINTm_BbleErr_START (12)
#define SOC_OTG_DOEPINTm_BbleErr_END (12)
#define SOC_OTG_DOEPINTm_NAKIntrpt_START (13)
#define SOC_OTG_DOEPINTm_NAKIntrpt_END (13)
#define SOC_OTG_DOEPINTm_NYET_START (14)
#define SOC_OTG_DOEPINTm_NYET_END (14)
#define SOC_OTG_DOEPINTm_StupPktRcvd_START (15)
#define SOC_OTG_DOEPINTm_StupPktRcvd_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int XferSize : 7;
        unsigned int reserved_0: 12;
        unsigned int PktCnt : 1;
        unsigned int reserved_1: 9;
        unsigned int SUPCnt : 2;
        unsigned int reserved_2: 1;
    } reg;
} SOC_OTG_DOEPTSIZ0_UNION;
#endif
#define SOC_OTG_DOEPTSIZ0_XferSize_START (0)
#define SOC_OTG_DOEPTSIZ0_XferSize_END (6)
#define SOC_OTG_DOEPTSIZ0_PktCnt_START (19)
#define SOC_OTG_DOEPTSIZ0_PktCnt_END (19)
#define SOC_OTG_DOEPTSIZ0_SUPCnt_START (29)
#define SOC_OTG_DOEPTSIZ0_SUPCnt_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int XferSize : 19;
        unsigned int PktCnt : 10;
        unsigned int RxDPID : 2;
        unsigned int reserved : 1;
    } reg;
} SOC_OTG_DOEPTSIZn_UNION;
#endif
#define SOC_OTG_DOEPTSIZn_XferSize_START (0)
#define SOC_OTG_DOEPTSIZn_XferSize_END (18)
#define SOC_OTG_DOEPTSIZn_PktCnt_START (19)
#define SOC_OTG_DOEPTSIZn_PktCnt_END (28)
#define SOC_OTG_DOEPTSIZn_RxDPID_START (29)
#define SOC_OTG_DOEPTSIZn_RxDPID_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DMAAddr : 32;
    } reg;
} SOC_OTG_DOEPDMAm_UNION;
#endif
#define SOC_OTG_DOEPDMAm_DMAAddr_START (0)
#define SOC_OTG_DOEPDMAm_DMAAddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int DMABufferAddr : 32;
    } reg;
} SOC_OTG_DOEPDMABm_UNION;
#endif
#define SOC_OTG_DOEPDMABm_DMABufferAddr_START (0)
#define SOC_OTG_DOEPDMABm_DMABufferAddr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int StopPclk : 1;
        unsigned int GateHclk : 1;
        unsigned int PwrClmp : 1;
        unsigned int RstPdenModule : 1;
        unsigned int reserved : 1;
        unsigned int Enbl_L1Gating : 1;
        unsigned int PhySleep : 1;
        unsigned int L1_suspended : 1;
        unsigned int ResetAfterSusp : 1;
        unsigned int RestoreMode : 1;
        unsigned int EnExtndedHibernation : 1;
        unsigned int ExtndedHibernationClamp : 1;
        unsigned int ExtndedHibernationSwitch : 1;
        unsigned int EssRegRestored : 1;
        unsigned int RestoreValue : 18;
    } reg;
} SOC_OTG_PCGCCTL_UNION;
#endif
#define SOC_OTG_PCGCCTL_StopPclk_START (0)
#define SOC_OTG_PCGCCTL_StopPclk_END (0)
#define SOC_OTG_PCGCCTL_GateHclk_START (1)
#define SOC_OTG_PCGCCTL_GateHclk_END (1)
#define SOC_OTG_PCGCCTL_PwrClmp_START (2)
#define SOC_OTG_PCGCCTL_PwrClmp_END (2)
#define SOC_OTG_PCGCCTL_RstPdenModule_START (3)
#define SOC_OTG_PCGCCTL_RstPdenModule_END (3)
#define SOC_OTG_PCGCCTL_Enbl_L1Gating_START (5)
#define SOC_OTG_PCGCCTL_Enbl_L1Gating_END (5)
#define SOC_OTG_PCGCCTL_PhySleep_START (6)
#define SOC_OTG_PCGCCTL_PhySleep_END (6)
#define SOC_OTG_PCGCCTL_L1_suspended_START (7)
#define SOC_OTG_PCGCCTL_L1_suspended_END (7)
#define SOC_OTG_PCGCCTL_ResetAfterSusp_START (8)
#define SOC_OTG_PCGCCTL_ResetAfterSusp_END (8)
#define SOC_OTG_PCGCCTL_RestoreMode_START (9)
#define SOC_OTG_PCGCCTL_RestoreMode_END (9)
#define SOC_OTG_PCGCCTL_EnExtndedHibernation_START (10)
#define SOC_OTG_PCGCCTL_EnExtndedHibernation_END (10)
#define SOC_OTG_PCGCCTL_ExtndedHibernationClamp_START (11)
#define SOC_OTG_PCGCCTL_ExtndedHibernationClamp_END (11)
#define SOC_OTG_PCGCCTL_ExtndedHibernationSwitch_START (12)
#define SOC_OTG_PCGCCTL_ExtndedHibernationSwitch_END (12)
#define SOC_OTG_PCGCCTL_EssRegRestored_START (13)
#define SOC_OTG_PCGCCTL_EssRegRestored_END (13)
#define SOC_OTG_PCGCCTL_RestoreValue_START (14)
#define SOC_OTG_PCGCCTL_RestoreValue_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
