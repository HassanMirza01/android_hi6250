#ifndef __SOC_OTG_USB_AHBIF_INTERFACE_H__
#define __SOC_OTG_USB_AHBIF_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_ADDR(base) ((base) + (0x00))
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL1_ADDR(base) ((base) + (0x04))
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_ADDR(base) ((base) + (0x08))
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_ADDR(base) ((base) + (0x0C))
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_ADDR(base) ((base) + (0x10))
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL5_ADDR(base) ((base) + (0x14))
#define SOC_OTG_USB_AHBIF_BC_CTRL0_ADDR(base) ((base) + (0x18))
#define SOC_OTG_USB_AHBIF_BC_CTRL1_ADDR(base) ((base) + (0x1C))
#define SOC_OTG_USB_AHBIF_BC_CTRL2_ADDR(base) ((base) + (0x20))
#define SOC_OTG_USB_AHBIF_BC_CTRL3_ADDR(base) ((base) + (0x24))
#define SOC_OTG_USB_AHBIF_BC_CTRL4_ADDR(base) ((base) + (0x28))
#define SOC_OTG_USB_AHBIF_BC_CTRL5_ADDR(base) ((base) + (0x2C))
#define SOC_OTG_USB_AHBIF_BC_CTRL6_ADDR(base) ((base) + (0x30))
#define SOC_OTG_USB_AHBIF_BC_CTRL7_ADDR(base) ((base) + (0x34))
#define SOC_OTG_USB_AHBIF_BC_CTRL8_ADDR(base) ((base) + (0x38))
#define SOC_OTG_USB_AHBIF_BC_STS0_ADDR(base) ((base) + (0x3C))
#define SOC_OTG_USB_AHBIF_BC_STS1_ADDR(base) ((base) + (0x40))
#define SOC_OTG_USB_AHBIF_BC_STS2_ADDR(base) ((base) + (0x44))
#define SOC_OTG_USB_AHBIF_BC_STS3_ADDR(base) ((base) + (0x48))
#define SOC_OTG_USB_AHBIF_BC_STS4_ADDR(base) ((base) + (0x4C))
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_ADDR(base) ((base) + (0x50))
#define SOC_OTG_USB_AHBIF_USBOTG2_STS_ADDR(base) ((base) + (0x54))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int idpullup_sel : 1;
        unsigned int idpullup : 1;
        unsigned int acaenb_sel : 1;
        unsigned int acaenb : 1;
        unsigned int id_sel : 2;
        unsigned int id : 1;
        unsigned int drvvbus_sel : 1;
        unsigned int drvvbus : 1;
        unsigned int vbusvalid_sel : 1;
        unsigned int sessvld_sel : 1;
        unsigned int sessvld : 1;
        unsigned int dpdmpulldown_sel : 1;
        unsigned int dppulldown : 1;
        unsigned int dmpulldown : 1;
        unsigned int dbnce_fltr_bypass : 1;
        unsigned int reserved : 16;
    } reg;
} SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_UNION;
#endif
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_idpullup_sel_START (0)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_idpullup_sel_END (0)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_idpullup_START (1)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_idpullup_END (1)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_acaenb_sel_START (2)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_acaenb_sel_END (2)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_acaenb_START (3)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_acaenb_END (3)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_id_sel_START (4)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_id_sel_END (5)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_id_START (6)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_id_END (6)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_drvvbus_sel_START (7)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_drvvbus_sel_END (7)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_drvvbus_START (8)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_drvvbus_END (8)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_vbusvalid_sel_START (9)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_vbusvalid_sel_END (9)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_sessvld_sel_START (10)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_sessvld_sel_END (10)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_sessvld_START (11)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_sessvld_END (11)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_dpdmpulldown_sel_START (12)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_dpdmpulldown_sel_END (12)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_dppulldown_START (13)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_dppulldown_END (13)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_dmpulldown_START (14)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_dmpulldown_END (14)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_dbnce_fltr_bypass_START (15)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL0_dbnce_fltr_bypass_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int scaledown_mode : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_OTG_USB_AHBIF_USBOTG2_CTRL1_UNION;
#endif
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL1_scaledown_mode_START (0)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL1_scaledown_mode_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int commononn : 1;
        unsigned int otgdisable : 1;
        unsigned int vbusvldsel : 1;
        unsigned int vbusvldext : 1;
        unsigned int txbitstuffen : 1;
        unsigned int txbitstuffenh : 1;
        unsigned int fsxcvrowner : 1;
        unsigned int txenablen : 1;
        unsigned int fsdataext : 1;
        unsigned int fsse0ext : 1;
        unsigned int vatestenb : 2;
        unsigned int reserved : 20;
    } reg;
} SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_UNION;
#endif
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_commononn_START (0)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_commononn_END (0)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_otgdisable_START (1)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_otgdisable_END (1)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_vbusvldsel_START (2)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_vbusvldsel_END (2)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_vbusvldext_START (3)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_vbusvldext_END (3)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_txbitstuffen_START (4)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_txbitstuffen_END (4)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_txbitstuffenh_START (5)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_txbitstuffenh_END (5)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_fsxcvrowner_START (6)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_fsxcvrowner_END (6)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_txenablen_START (7)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_txenablen_END (7)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_fsdataext_START (8)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_fsdataext_END (8)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_fsse0ext_START (9)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_fsse0ext_END (9)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_vatestenb_START (10)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL2_vatestenb_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int comdistune : 3;
        unsigned int otgtune : 3;
        unsigned int sqrxtune : 3;
        unsigned int txfslstune : 4;
        unsigned int txpreempamptune : 2;
        unsigned int txpreemppulsetune : 1;
        unsigned int txrisetune : 2;
        unsigned int txvreftune : 4;
        unsigned int txhsxvtune : 2;
        unsigned int txrestune : 2;
        unsigned int vdatreftune : 2;
        unsigned int reserved : 4;
    } reg;
} SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_UNION;
#endif
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_comdistune_START (0)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_comdistune_END (2)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_otgtune_START (3)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_otgtune_END (5)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_sqrxtune_START (6)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_sqrxtune_END (8)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txfslstune_START (9)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txfslstune_END (12)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txpreempamptune_START (13)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txpreempamptune_END (14)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txpreemppulsetune_START (15)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txpreemppulsetune_END (15)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txrisetune_START (16)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txrisetune_END (17)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txvreftune_START (18)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txvreftune_END (21)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txhsxvtune_START (22)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txhsxvtune_END (23)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txrestune_START (24)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_txrestune_END (25)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_vdatreftune_START (26)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL3_vdatreftune_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int siddq : 1;
        unsigned int vregbypass : 1;
        unsigned int loopbackenb : 1;
        unsigned int bypasssel : 1;
        unsigned int bypassdmen : 1;
        unsigned int bypassdpen : 1;
        unsigned int bypassdmdata : 1;
        unsigned int bypassdpdata : 1;
        unsigned int hsxcvrrextctl : 1;
        unsigned int retenablen : 1;
        unsigned int autorsmenb : 1;
        unsigned int reserved : 21;
    } reg;
} SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_UNION;
#endif
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_siddq_START (0)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_siddq_END (0)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_vregbypass_START (1)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_vregbypass_END (1)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_loopbackenb_START (2)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_loopbackenb_END (2)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_bypasssel_START (3)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_bypasssel_END (3)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_bypassdmen_START (4)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_bypassdmen_END (4)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_bypassdpen_START (5)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_bypassdpen_END (5)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_bypassdmdata_START (6)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_bypassdmdata_END (6)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_bypassdpdata_START (7)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_bypassdpdata_END (7)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_hsxcvrrextctl_START (8)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_hsxcvrrextctl_END (8)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_retenablen_START (9)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_retenablen_END (9)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_autorsmenb_START (10)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL4_autorsmenb_END (10)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int refclksel : 2;
        unsigned int fsel : 3;
        unsigned int pllbtune : 1;
        unsigned int pllitune : 2;
        unsigned int pllptune : 4;
        unsigned int reserved : 20;
    } reg;
} SOC_OTG_USB_AHBIF_USBOTG2_CTRL5_UNION;
#endif
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL5_refclksel_START (0)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL5_refclksel_END (1)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL5_fsel_START (2)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL5_fsel_END (4)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL5_pllbtune_START (5)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL5_pllbtune_END (5)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL5_pllitune_START (6)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL5_pllitune_END (7)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL5_pllptune_START (8)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL5_pllptune_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int chrg_det_en : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_OTG_USB_AHBIF_BC_CTRL0_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_CTRL0_chrg_det_en_START (0)
#define SOC_OTG_USB_AHBIF_BC_CTRL0_chrg_det_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int chrg_det_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_OTG_USB_AHBIF_BC_CTRL1_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_CTRL1_chrg_det_int_clr_START (0)
#define SOC_OTG_USB_AHBIF_BC_CTRL1_chrg_det_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int chrg_det_int_msk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_OTG_USB_AHBIF_BC_CTRL2_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_CTRL2_chrg_det_int_msk_START (0)
#define SOC_OTG_USB_AHBIF_BC_CTRL2_chrg_det_int_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bc_mode : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_OTG_USB_AHBIF_BC_CTRL3_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_CTRL3_bc_mode_START (0)
#define SOC_OTG_USB_AHBIF_BC_CTRL3_bc_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bc_opmode : 2;
        unsigned int bc_xcvrselect : 2;
        unsigned int bc_termselect : 1;
        unsigned int bc_txvalid : 1;
        unsigned int bc_txvalidh : 1;
        unsigned int bc_idpullup : 1;
        unsigned int bc_dppulldown : 1;
        unsigned int bc_dmpulldown : 1;
        unsigned int bc_suspendm : 1;
        unsigned int bc_sleepm : 1;
        unsigned int reserved : 20;
    } reg;
} SOC_OTG_USB_AHBIF_BC_CTRL4_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_opmode_START (0)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_opmode_END (1)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_xcvrselect_START (2)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_xcvrselect_END (3)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_termselect_START (4)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_termselect_END (4)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_txvalid_START (5)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_txvalid_END (5)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_txvalidh_START (6)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_txvalidh_END (6)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_idpullup_START (7)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_idpullup_END (7)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_dppulldown_START (8)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_dppulldown_END (8)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_dmpulldown_START (9)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_dmpulldown_END (9)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_suspendm_START (10)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_suspendm_END (10)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_sleepm_START (11)
#define SOC_OTG_USB_AHBIF_BC_CTRL4_bc_sleepm_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bc_aca_en : 1;
        unsigned int bc_chrg_sel : 1;
        unsigned int bc_vdat_src_en : 1;
        unsigned int bc_vdat_det_en : 1;
        unsigned int bc_dcd_en : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_OTG_USB_AHBIF_BC_CTRL5_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_CTRL5_bc_aca_en_START (0)
#define SOC_OTG_USB_AHBIF_BC_CTRL5_bc_aca_en_END (0)
#define SOC_OTG_USB_AHBIF_BC_CTRL5_bc_chrg_sel_START (1)
#define SOC_OTG_USB_AHBIF_BC_CTRL5_bc_chrg_sel_END (1)
#define SOC_OTG_USB_AHBIF_BC_CTRL5_bc_vdat_src_en_START (2)
#define SOC_OTG_USB_AHBIF_BC_CTRL5_bc_vdat_src_en_END (2)
#define SOC_OTG_USB_AHBIF_BC_CTRL5_bc_vdat_det_en_START (3)
#define SOC_OTG_USB_AHBIF_BC_CTRL5_bc_vdat_det_en_END (3)
#define SOC_OTG_USB_AHBIF_BC_CTRL5_bc_dcd_en_START (4)
#define SOC_OTG_USB_AHBIF_BC_CTRL5_bc_dcd_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bc_chirp_int_clr : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_OTG_USB_AHBIF_BC_CTRL6_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_CTRL6_bc_chirp_int_clr_START (0)
#define SOC_OTG_USB_AHBIF_BC_CTRL6_bc_chirp_int_clr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bc_chirp_int_msk : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_OTG_USB_AHBIF_BC_CTRL7_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_CTRL7_bc_chirp_int_msk_START (0)
#define SOC_OTG_USB_AHBIF_BC_CTRL7_bc_chirp_int_msk_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_len : 32;
    } reg;
} SOC_OTG_USB_AHBIF_BC_CTRL8_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_CTRL8_filter_len_START (0)
#define SOC_OTG_USB_AHBIF_BC_CTRL8_filter_len_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int chrg_det_rawint : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_OTG_USB_AHBIF_BC_STS0_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_STS0_chrg_det_rawint_START (0)
#define SOC_OTG_USB_AHBIF_BC_STS0_chrg_det_rawint_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int chrg_det_mskint : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_OTG_USB_AHBIF_BC_STS1_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_STS1_chrg_det_mskint_START (0)
#define SOC_OTG_USB_AHBIF_BC_STS1_chrg_det_mskint_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bc_vbus_valid : 1;
        unsigned int bc_sess_valid : 1;
        unsigned int bc_fs_vplus : 1;
        unsigned int bc_fs_vminus : 1;
        unsigned int bc_chg_det : 1;
        unsigned int bc_iddig : 1;
        unsigned int bc_rid_float : 1;
        unsigned int bc_rid_gnd : 1;
        unsigned int bc_rid_a : 1;
        unsigned int bc_rid_b : 1;
        unsigned int bc_rid_c : 1;
        unsigned int bc_chirp_on : 1;
        unsigned int bc_linestate : 2;
        unsigned int reserved : 18;
    } reg;
} SOC_OTG_USB_AHBIF_BC_STS2_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_vbus_valid_START (0)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_vbus_valid_END (0)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_sess_valid_START (1)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_sess_valid_END (1)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_fs_vplus_START (2)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_fs_vplus_END (2)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_fs_vminus_START (3)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_fs_vminus_END (3)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_chg_det_START (4)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_chg_det_END (4)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_iddig_START (5)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_iddig_END (5)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_rid_float_START (6)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_rid_float_END (6)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_rid_gnd_START (7)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_rid_gnd_END (7)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_rid_a_START (8)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_rid_a_END (8)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_rid_b_START (9)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_rid_b_END (9)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_rid_c_START (10)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_rid_c_END (10)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_chirp_on_START (11)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_chirp_on_END (11)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_linestate_START (12)
#define SOC_OTG_USB_AHBIF_BC_STS2_bc_linestate_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bc_rawint : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_OTG_USB_AHBIF_BC_STS3_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_STS3_bc_rawint_START (0)
#define SOC_OTG_USB_AHBIF_BC_STS3_bc_rawint_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bc_mskint : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_OTG_USB_AHBIF_BC_STS4_UNION;
#endif
#define SOC_OTG_USB_AHBIF_BC_STS4_bc_mskint_START (0)
#define SOC_OTG_USB_AHBIF_BC_STS4_bc_mskint_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int testclk : 1;
        unsigned int testdataoutsel : 1;
        unsigned int test_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int testaddr : 4;
        unsigned int testdatain : 8;
        unsigned int test_mux : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_UNION;
#endif
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_testclk_START (0)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_testclk_END (0)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_testdataoutsel_START (1)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_testdataoutsel_END (1)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_test_sel_START (2)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_test_sel_END (2)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_testaddr_START (4)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_testaddr_END (7)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_testdatain_START (8)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_testdatain_END (15)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_test_mux_START (16)
#define SOC_OTG_USB_AHBIF_USBOTG2_CTRL6_test_mux_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int testdataout : 4;
        unsigned int hssqyelch : 1;
        unsigned int hsrxdat : 1;
        unsigned int fslsrcv : 1;
        unsigned int reserved : 25;
    } reg;
} SOC_OTG_USB_AHBIF_USBOTG2_STS_UNION;
#endif
#define SOC_OTG_USB_AHBIF_USBOTG2_STS_testdataout_START (0)
#define SOC_OTG_USB_AHBIF_USBOTG2_STS_testdataout_END (3)
#define SOC_OTG_USB_AHBIF_USBOTG2_STS_hssqyelch_START (4)
#define SOC_OTG_USB_AHBIF_USBOTG2_STS_hssqyelch_END (4)
#define SOC_OTG_USB_AHBIF_USBOTG2_STS_hsrxdat_START (5)
#define SOC_OTG_USB_AHBIF_USBOTG2_STS_hsrxdat_END (5)
#define SOC_OTG_USB_AHBIF_USBOTG2_STS_fslsrcv_START (6)
#define SOC_OTG_USB_AHBIF_USBOTG2_STS_fslsrcv_END (6)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
