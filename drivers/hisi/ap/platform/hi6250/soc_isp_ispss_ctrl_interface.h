#ifndef __SOC_ISP_ISPSS_CTRL_INTERFACE_H__
#define __SOC_ISP_ISPSS_CTRL_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_ISPSS_CTRL_IP_ID_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_ISPSS_CTRL_VERSION_ID_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_ISPSS_CTRL_REVISION_ID_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P1_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P2_ADDR(base) ((base) + (0x0018))
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_ADDR(base) ((base) + (0x001C))
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_ADDR(base) ((base) + (0x0024))
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P2_ADDR(base) ((base) + (0x0028))
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_ADDR(base) ((base) + (0x0040))
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P2_ADDR(base) ((base) + (0x0044))
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_ADDR(base) ((base) + (0x0048))
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P2_ADDR(base) ((base) + (0x004C))
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_ADDR(base) ((base) + (0x0050))
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P2_ADDR(base) ((base) + (0x0054))
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_ADDR(base) ((base) + (0x0060))
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P1_ADDR(base) ((base) + (0x0064))
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P2_ADDR(base) ((base) + (0x0068))
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_ADDR(base) ((base) + (0x006C))
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_ADDR(base) ((base) + (0x0070))
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_ADDR(base) ((base) + (0x0074))
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P2_ADDR(base) ((base) + (0x0078))
#define SOC_ISP_ISPSS_CTRL_CONTROL_ADDR(base) ((base) + (0x0090))
#define SOC_ISP_ISPSS_CTRL_CONTROL_0_P1_ADDR(base) ((base) + (0x0094))
#define SOC_ISP_ISPSS_CTRL_CONTROL_0_P2_ADDR(base) ((base) + (0x0098))
#define SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_ADDR(base) ((base) + (0x0100))
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_ADDR(base) ((base) + (0x0104))
#define SOC_ISP_ISPSS_CTRL_LST_LOW_ADDR(base) ((base) + (0x0120))
#define SOC_ISP_ISPSS_CTRL_LST_HIGH_ADDR(base) ((base) + (0x0124))
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P1_ADDR(base) ((base) + (0x0130))
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P2_ADDR(base) ((base) + (0x0134))
#define SOC_ISP_ISPSS_CTRL_CROP_H_3_P1_ADDR(base) ((base) + (0x0140))
#define SOC_ISP_ISPSS_CTRL_CROP_V_3_P1_ADDR(base) ((base) + (0x0144))
#define SOC_ISP_ISPSS_CTRL_CROP_H_3_P2_ADDR(base) ((base) + (0x0148))
#define SOC_ISP_ISPSS_CTRL_CROP_V_3_P2_ADDR(base) ((base) + (0x014C))
#define SOC_ISP_ISPSS_CTRL_GPO_ADDR(base) ((base) + (0x0160))
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_ADDR(base) ((base) + (0x0164))
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_2_ADDR(base) ((base) + (0x0168))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_1_1_ADDR(base) ((base) + (0x0170))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_1_2_ADDR(base) ((base) + (0x0174))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_2_1_ADDR(base) ((base) + (0x0178))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_2_2_ADDR(base) ((base) + (0x017C))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_3_1_ADDR(base) ((base) + (0x0180))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_3_2_ADDR(base) ((base) + (0x0184))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_4_1_ADDR(base) ((base) + (0x0188))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_4_2_ADDR(base) ((base) + (0x018C))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_5_1_ADDR(base) ((base) + (0x0190))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_5_2_ADDR(base) ((base) + (0x0194))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_6_1_ADDR(base) ((base) + (0x0198))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_6_2_ADDR(base) ((base) + (0x019C))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_7_1_ADDR(base) ((base) + (0x01A0))
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_7_2_ADDR(base) ((base) + (0x01A4))
#define SOC_ISP_ISPSS_CTRL_PRE_DIV_ADDR(base) ((base) + (0x01B0))
#define SOC_ISP_ISPSS_CTRL_CROP_H_4_P1_ADDR(base) ((base) + (0x01B4))
#define SOC_ISP_ISPSS_CTRL_CROP_V_4_P1_ADDR(base) ((base) + (0x01B8))
#define SOC_ISP_ISPSS_CTRL_CROP_H_4_P2_ADDR(base) ((base) + (0x01BC))
#define SOC_ISP_ISPSS_CTRL_CROP_V_4_P2_ADDR(base) ((base) + (0x01C0))
#define SOC_ISP_ISPSS_CTRL_VPBG_CTRL_1_ADDR(base) ((base) + (0x01D0))
#define SOC_ISP_ISPSS_CTRL_VPBG_CTRL_2_ADDR(base) ((base) + (0x01D4))
#define SOC_ISP_ISPSS_CTRL_VPBG_CTRL_3_ADDR(base) ((base) + (0x01D8))
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_ADDR(base) ((base) + (0x01E0))
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_ADDR(base) ((base) + (0x01E4))
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_C_DBG_ADDR(base) ((base) + (0x01E8))
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_ADDR(base) ((base) + (0x01EC))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_id : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_IP_ID_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_IP_ID_ip_id_START (0)
#define SOC_ISP_ISPSS_CTRL_IP_ID_ip_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_version : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_VERSION_ID_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_VERSION_ID_ip_version_START (0)
#define SOC_ISP_ISPSS_CTRL_VERSION_ID_ip_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_revision : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_REVISION_ID_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_REVISION_ID_ip_revision_START (0)
#define SOC_ISP_ISPSS_CTRL_REVISION_ID_ip_revision_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int cgr_3 : 1;
        unsigned int reserved_3: 1;
        unsigned int cgr_5 : 1;
        unsigned int cgr_6 : 1;
        unsigned int cgr_7 : 1;
        unsigned int cgr_8 : 1;
        unsigned int reserved_4: 1;
        unsigned int cgr_10 : 1;
        unsigned int cgr_11 : 1;
        unsigned int cgr_12 : 1;
        unsigned int cgr_13 : 1;
        unsigned int cgr_14 : 1;
        unsigned int reserved_5: 17;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_3_START (3)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_3_END (3)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_5_START (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_5_END (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_6_START (6)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_6_END (6)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_7_START (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_7_END (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_8_END (8)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_10_START (10)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_10_END (10)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_11_START (11)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_11_END (11)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_12_START (12)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_12_END (12)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_13_START (13)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_13_END (13)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_14_START (14)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_cgr_14_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cgr_0 : 1;
        unsigned int cgr_1 : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int cgr_4 : 1;
        unsigned int cgr_5 : 1;
        unsigned int cgr_6 : 1;
        unsigned int reserved_2: 25;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P1_cgr_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P1_cgr_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P1_cgr_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P1_cgr_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P1_cgr_4_START (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P1_cgr_4_END (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P1_cgr_5_START (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P1_cgr_5_END (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P1_cgr_6_START (6)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P1_cgr_6_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cgr_0 : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int cgr_6 : 1;
        unsigned int reserved_5: 25;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P2_cgr_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P2_cgr_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P2_cgr_6_START (6)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_TOP_P2_cgr_6_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cgr_0 : 1;
        unsigned int cgr_1 : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int cgr_4 : 1;
        unsigned int cgr_5 : 1;
        unsigned int reserved_2: 1;
        unsigned int cgr_7 : 1;
        unsigned int cgr_8 : 1;
        unsigned int reserved_3: 23;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_cgr_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_cgr_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_cgr_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_cgr_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_cgr_4_START (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_cgr_4_END (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_cgr_5_START (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_cgr_5_END (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_cgr_7_START (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_cgr_7_END (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_cgr_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P1_cgr_8_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cgr_0 : 1;
        unsigned int cgr_1 : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int cgr_4 : 1;
        unsigned int cgr_5 : 1;
        unsigned int reserved_2: 1;
        unsigned int cgr_7 : 1;
        unsigned int cgr_8 : 1;
        unsigned int reserved_3: 23;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_cgr_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_cgr_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_cgr_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_cgr_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_cgr_4_START (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_cgr_4_END (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_cgr_5_START (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_cgr_5_END (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_cgr_7_START (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_cgr_7_END (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_cgr_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_FE_P2_cgr_8_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cgr_0 : 1;
        unsigned int cgr_1 : 1;
        unsigned int cgr_2 : 1;
        unsigned int cgr_3 : 1;
        unsigned int cgr_4 : 1;
        unsigned int cgr_5 : 1;
        unsigned int cgr_6 : 1;
        unsigned int cgr_7 : 1;
        unsigned int cgr_8 : 1;
        unsigned int cgr_9 : 1;
        unsigned int cgr_10 : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int cgr_13 : 1;
        unsigned int cgr_14 : 1;
        unsigned int cgr_15 : 1;
        unsigned int reserved_2: 16;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_2_START (2)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_2_END (2)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_3_START (3)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_3_END (3)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_4_START (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_4_END (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_5_START (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_5_END (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_6_START (6)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_6_END (6)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_7_START (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_7_END (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_8_END (8)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_9_START (9)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_9_END (9)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_10_START (10)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_10_END (10)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_13_START (13)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_13_END (13)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_14_START (14)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_14_END (14)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_15_START (15)
#define SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P1_cgr_15_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 19;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_CGR_BE_P2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int light_sleep_0 : 1;
        unsigned int light_sleep_1 : 1;
        unsigned int light_sleep_2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int light_sleep_4 : 1;
        unsigned int light_sleep_5 : 1;
        unsigned int light_sleep_6 : 1;
        unsigned int reserved_1 : 1;
        unsigned int light_sleep_8 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int light_sleep_11 : 1;
        unsigned int reserved_4 : 1;
        unsigned int light_sleep_13 : 1;
        unsigned int light_sleep_14 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int light_sleep_19 : 1;
        unsigned int reserved_9 : 12;
    } reg;
} SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_2_START (2)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_2_END (2)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_4_START (4)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_4_END (4)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_5_START (5)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_5_END (5)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_6_START (6)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_6_END (6)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_8_END (8)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_11_START (11)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_11_END (11)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_13_START (13)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_13_END (13)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_14_START (14)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_14_END (14)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_19_START (19)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P1_light_sleep_19_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int light_sleep_0 : 1;
        unsigned int light_sleep_1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int light_sleep_7 : 1;
        unsigned int light_sleep_8 : 1;
        unsigned int reserved_5 : 23;
    } reg;
} SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P2_light_sleep_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P2_light_sleep_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P2_light_sleep_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P2_light_sleep_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P2_light_sleep_7_START (7)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P2_light_sleep_7_END (7)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P2_light_sleep_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR_CLK_P2_light_sleep_8_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int deep_sleep_0 : 1;
        unsigned int deep_sleep_1 : 1;
        unsigned int deep_sleep_2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int deep_sleep_4 : 1;
        unsigned int deep_sleep_5 : 1;
        unsigned int deep_sleep_6 : 1;
        unsigned int reserved_1 : 1;
        unsigned int deep_sleep_8 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int deep_sleep_11 : 1;
        unsigned int reserved_4 : 1;
        unsigned int deep_sleep_13 : 1;
        unsigned int deep_sleep_14 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int deep_sleep_19 : 1;
        unsigned int reserved_9 : 12;
    } reg;
} SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_2_START (2)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_2_END (2)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_4_START (4)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_4_END (4)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_5_START (5)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_5_END (5)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_6_START (6)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_6_END (6)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_8_END (8)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_11_START (11)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_11_END (11)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_13_START (13)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_13_END (13)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_14_START (14)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_14_END (14)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_19_START (19)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P1_deep_sleep_19_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int deep_sleep_0 : 1;
        unsigned int deep_sleep_1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int deep_sleep_7 : 1;
        unsigned int deep_sleep_8 : 1;
        unsigned int reserved_5 : 23;
    } reg;
} SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P2_deep_sleep_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P2_deep_sleep_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P2_deep_sleep_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P2_deep_sleep_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P2_deep_sleep_7_START (7)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P2_deep_sleep_7_END (7)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P2_deep_sleep_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR2_CLK_P2_deep_sleep_8_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_down_0 : 1;
        unsigned int power_down_1 : 1;
        unsigned int power_down_2 : 1;
        unsigned int reserved_0 : 1;
        unsigned int power_down_4 : 1;
        unsigned int power_down_5 : 1;
        unsigned int power_down_6 : 1;
        unsigned int reserved_1 : 1;
        unsigned int power_down_8 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int power_down_11 : 1;
        unsigned int reserved_4 : 1;
        unsigned int power_down_13 : 1;
        unsigned int power_down_14 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int power_down_19 : 1;
        unsigned int reserved_9 : 12;
    } reg;
} SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_2_START (2)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_2_END (2)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_4_START (4)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_4_END (4)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_5_START (5)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_5_END (5)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_6_START (6)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_6_END (6)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_8_END (8)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_11_START (11)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_11_END (11)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_13_START (13)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_13_END (13)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_14_START (14)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_14_END (14)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_19_START (19)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P1_power_down_19_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int power_down_0 : 1;
        unsigned int power_down_1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int power_down_7 : 1;
        unsigned int power_down_8 : 1;
        unsigned int reserved_5 : 23;
    } reg;
} SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P2_power_down_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P2_power_down_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P2_power_down_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P2_power_down_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P2_power_down_7_START (7)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P2_power_down_7_END (7)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P2_power_down_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MEM_PWR3_CLK_P2_power_down_8_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int rst_3 : 1;
        unsigned int reserved_3: 1;
        unsigned int rst_5 : 1;
        unsigned int rst_6 : 1;
        unsigned int rst_7 : 1;
        unsigned int rst_8 : 1;
        unsigned int reserved_4: 1;
        unsigned int rst_10 : 1;
        unsigned int rst_11 : 1;
        unsigned int rst_12 : 1;
        unsigned int rst_13 : 1;
        unsigned int rst_14 : 1;
        unsigned int rst_15 : 1;
        unsigned int reserved_5: 1;
        unsigned int rst_17 : 1;
        unsigned int reserved_6: 14;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_3_START (3)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_3_END (3)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_5_START (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_5_END (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_6_START (6)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_6_END (6)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_7_START (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_7_END (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_8_END (8)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_10_START (10)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_10_END (10)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_11_START (11)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_11_END (11)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_12_START (12)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_12_END (12)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_13_START (13)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_13_END (13)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_14_START (14)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_14_END (14)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_15_START (15)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_15_END (15)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_17_START (17)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_rst_17_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_0 : 1;
        unsigned int rst_1 : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int rst_4 : 1;
        unsigned int rst_5 : 1;
        unsigned int rst_6 : 1;
        unsigned int reserved_2: 25;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P1_rst_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P1_rst_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P1_rst_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P1_rst_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P1_rst_4_START (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P1_rst_4_END (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P1_rst_5_START (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P1_rst_5_END (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P1_rst_6_START (6)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P1_rst_6_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int rst_1 : 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int rst_6 : 1;
        unsigned int reserved_5: 25;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P2_rst_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P2_rst_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P2_rst_6_START (6)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_TOP_P2_rst_6_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_0 : 1;
        unsigned int rst_1 : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int rst_4 : 1;
        unsigned int rst_5 : 1;
        unsigned int reserved_2: 1;
        unsigned int rst_7 : 1;
        unsigned int rst_8 : 1;
        unsigned int reserved_3: 23;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_rst_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_rst_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_rst_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_rst_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_rst_4_START (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_rst_4_END (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_rst_5_START (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_rst_5_END (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_rst_7_START (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_rst_7_END (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_rst_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P1_rst_8_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_0 : 1;
        unsigned int rst_1 : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int rst_4 : 1;
        unsigned int rst_5 : 1;
        unsigned int reserved_2: 1;
        unsigned int rst_7 : 1;
        unsigned int rst_8 : 1;
        unsigned int reserved_3: 23;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_rst_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_rst_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_rst_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_rst_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_rst_4_START (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_rst_4_END (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_rst_5_START (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_rst_5_END (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_rst_7_START (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_rst_7_END (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_rst_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_FE_P2_rst_8_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rst_0 : 1;
        unsigned int rst_1 : 1;
        unsigned int rst_2 : 1;
        unsigned int rst_3 : 1;
        unsigned int rst_4 : 1;
        unsigned int rst_5 : 1;
        unsigned int rst_6 : 1;
        unsigned int rst_7 : 1;
        unsigned int rst_8 : 1;
        unsigned int rst_9 : 1;
        unsigned int rst_10 : 1;
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int rst_13 : 1;
        unsigned int rst_14 : 1;
        unsigned int rst_15 : 1;
        unsigned int reserved_2: 16;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_0_START (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_0_END (0)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_1_START (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_1_END (1)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_2_START (2)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_2_END (2)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_3_START (3)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_3_END (3)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_4_START (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_4_END (4)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_5_START (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_5_END (5)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_6_START (6)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_6_END (6)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_7_START (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_7_END (7)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_8_START (8)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_8_END (8)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_9_START (9)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_9_END (9)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_10_START (10)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_10_END (10)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_13_START (13)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_13_END (13)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_14_START (14)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_14_END (14)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_15_START (15)
#define SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P1_rst_15_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 16;
    } reg;
} SOC_ISP_ISPSS_CTRL_MODULE_RESET_BE_P2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int flash_mode : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 3;
        unsigned int disable_axi_data_packing : 1;
        unsigned int spare : 2;
        unsigned int reserved_4 : 20;
    } reg;
} SOC_ISP_ISPSS_CTRL_CONTROL_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_CONTROL_flash_mode_START (4)
#define SOC_ISP_ISPSS_CTRL_CONTROL_flash_mode_END (4)
#define SOC_ISP_ISPSS_CTRL_CONTROL_disable_axi_data_packing_START (9)
#define SOC_ISP_ISPSS_CTRL_CONTROL_disable_axi_data_packing_END (9)
#define SOC_ISP_ISPSS_CTRL_CONTROL_spare_START (10)
#define SOC_ISP_ISPSS_CTRL_CONTROL_spare_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int isp_be_scaler_1 : 1;
        unsigned int isp_be_scaler_2 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int reserved_3 : 2;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 5;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int reserved_13 : 1;
        unsigned int spare : 2;
        unsigned int reserved_14 : 9;
    } reg;
} SOC_ISP_ISPSS_CTRL_CONTROL_0_P1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_CONTROL_0_P1_isp_be_scaler_1_START (1)
#define SOC_ISP_ISPSS_CTRL_CONTROL_0_P1_isp_be_scaler_1_END (1)
#define SOC_ISP_ISPSS_CTRL_CONTROL_0_P1_isp_be_scaler_2_START (2)
#define SOC_ISP_ISPSS_CTRL_CONTROL_0_P1_isp_be_scaler_2_END (2)
#define SOC_ISP_ISPSS_CTRL_CONTROL_0_P1_spare_START (21)
#define SOC_ISP_ISPSS_CTRL_CONTROL_0_P1_spare_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 2;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 5;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 14;
    } reg;
} SOC_ISP_ISPSS_CTRL_CONTROL_0_P2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r1_1_rt_srt : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int r2_1_rt_srt : 1;
        unsigned int reserved_3 : 1;
        unsigned int r11_1_rt_srt : 1;
        unsigned int r11_2_rt_srt : 1;
        unsigned int r12_1_rt_srt : 1;
        unsigned int r12_2_rt_srt : 1;
        unsigned int reserved_4 : 22;
    } reg;
} SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_r1_1_rt_srt_START (0)
#define SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_r1_1_rt_srt_END (0)
#define SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_r2_1_rt_srt_START (4)
#define SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_r2_1_rt_srt_END (4)
#define SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_r11_1_rt_srt_START (6)
#define SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_r11_1_rt_srt_END (6)
#define SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_r11_2_rt_srt_START (7)
#define SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_r11_2_rt_srt_END (7)
#define SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_r12_1_rt_srt_START (8)
#define SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_r12_1_rt_srt_END (8)
#define SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_r12_2_rt_srt_START (9)
#define SOC_ISP_ISPSS_CTRL_CVDR_RD_CTRL_r12_2_rt_srt_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int w1_1_rt_srt : 1;
        unsigned int w1_2_rt_srt : 1;
        unsigned int w14_1_rt_srt : 1;
        unsigned int w14_2_rt_srt : 1;
        unsigned int reserved_0 : 2;
        unsigned int w3_1_rt_srt : 1;
        unsigned int w4_1_1_rt_srt : 1;
        unsigned int w4_1_2_rt_srt : 1;
        unsigned int reserved_1 : 1;
        unsigned int reserved_2 : 1;
        unsigned int w5_1_1_rt_srt : 1;
        unsigned int w5_1_2_rt_srt : 1;
        unsigned int reserved_3 : 1;
        unsigned int reserved_4 : 1;
        unsigned int reserved_5 : 1;
        unsigned int reserved_6 : 1;
        unsigned int reserved_7 : 1;
        unsigned int reserved_8 : 1;
        unsigned int reserved_9 : 1;
        unsigned int reserved_10 : 1;
        unsigned int reserved_11 : 1;
        unsigned int reserved_12 : 1;
        unsigned int w11_1_rt_srt : 1;
        unsigned int w11_2_rt_srt : 1;
        unsigned int w12_1_rt_srt : 1;
        unsigned int w12_2_rt_srt : 1;
        unsigned int w13_1_rt_srt : 1;
        unsigned int w13_2_rt_srt : 1;
        unsigned int reserved_13 : 3;
    } reg;
} SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w1_1_rt_srt_START (0)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w1_1_rt_srt_END (0)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w1_2_rt_srt_START (1)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w1_2_rt_srt_END (1)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w14_1_rt_srt_START (2)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w14_1_rt_srt_END (2)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w14_2_rt_srt_START (3)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w14_2_rt_srt_END (3)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w3_1_rt_srt_START (6)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w3_1_rt_srt_END (6)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w4_1_1_rt_srt_START (7)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w4_1_1_rt_srt_END (7)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w4_1_2_rt_srt_START (8)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w4_1_2_rt_srt_END (8)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w5_1_1_rt_srt_START (11)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w5_1_1_rt_srt_END (11)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w5_1_2_rt_srt_START (12)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w5_1_2_rt_srt_END (12)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w11_1_rt_srt_START (23)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w11_1_rt_srt_END (23)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w11_2_rt_srt_START (24)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w11_2_rt_srt_END (24)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w12_1_rt_srt_START (25)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w12_1_rt_srt_END (25)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w12_2_rt_srt_START (26)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w12_2_rt_srt_END (26)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w13_1_rt_srt_START (27)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w13_1_rt_srt_END (27)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w13_2_rt_srt_START (28)
#define SOC_ISP_ISPSS_CTRL_CVDR_WR_CTRL_w13_2_rt_srt_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lst_low : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_LST_LOW_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_LST_LOW_lst_low_START (0)
#define SOC_ISP_ISPSS_CTRL_LST_LOW_lst_low_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int lst_high : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_LST_HIGH_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_LST_HIGH_lst_high_START (0)
#define SOC_ISP_ISPSS_CTRL_LST_HIGH_lst_high_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pos_out_sel_1 : 4;
        unsigned int reserved_0 : 4;
        unsigned int pos_in_sel_1 : 4;
        unsigned int reserved_1 : 4;
        unsigned int pos_out_sel_2 : 4;
        unsigned int reserved_2 : 4;
        unsigned int pos_in_sel_2 : 4;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P1_pos_out_sel_1_START (0)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P1_pos_out_sel_1_END (3)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P1_pos_in_sel_1_START (8)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P1_pos_in_sel_1_END (11)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P1_pos_out_sel_2_START (16)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P1_pos_out_sel_2_END (19)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P1_pos_in_sel_2_START (24)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P1_pos_in_sel_2_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pos_out_sel_1 : 4;
        unsigned int reserved_0 : 4;
        unsigned int pos_in_sel_1 : 4;
        unsigned int reserved_1 : 4;
        unsigned int pos_out_sel_2 : 4;
        unsigned int reserved_2 : 4;
        unsigned int pos_in_sel_2 : 4;
        unsigned int reserved_3 : 4;
    } reg;
} SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P2_pos_out_sel_1_START (0)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P2_pos_out_sel_1_END (3)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P2_pos_in_sel_1_START (8)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P2_pos_in_sel_1_END (11)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P2_pos_out_sel_2_START (16)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P2_pos_out_sel_2_END (19)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P2_pos_in_sel_2_START (24)
#define SOC_ISP_ISPSS_CTRL_IOTAP_MAP_P2_pos_in_sel_2_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 13;
        unsigned int reserved_3: 3;
    } reg;
} SOC_ISP_ISPSS_CTRL_CROP_H_3_P1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 13;
        unsigned int reserved_3: 3;
    } reg;
} SOC_ISP_ISPSS_CTRL_CROP_V_3_P1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 13;
        unsigned int reserved_3: 3;
    } reg;
} SOC_ISP_ISPSS_CTRL_CROP_H_3_P2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 13;
        unsigned int reserved_3: 3;
    } reg;
} SOC_ISP_ISPSS_CTRL_CROP_V_3_P2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpo0 : 1;
        unsigned int gpo1 : 1;
        unsigned int gpo2 : 1;
        unsigned int gpo3 : 1;
        unsigned int gpo4 : 1;
        unsigned int gpo5 : 1;
        unsigned int gpo6 : 1;
        unsigned int gpo7 : 1;
        unsigned int gpo8 : 1;
        unsigned int gpo9 : 1;
        unsigned int gpo10 : 1;
        unsigned int gpo11 : 1;
        unsigned int gpo12 : 1;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_ISPSS_CTRL_GPO_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_GPO_gpo0_START (0)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo0_END (0)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo1_START (1)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo1_END (1)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo2_START (2)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo2_END (2)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo3_START (3)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo3_END (3)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo4_START (4)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo4_END (4)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo5_START (5)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo5_END (5)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo6_START (6)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo6_END (6)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo7_START (7)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo7_END (7)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo8_START (8)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo8_END (8)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo9_START (9)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo9_END (9)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo10_START (10)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo10_END (10)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo11_START (11)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo11_END (11)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo12_START (12)
#define SOC_ISP_ISPSS_CTRL_GPO_gpo12_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int gpo2_sel : 2;
        unsigned int gpo3_sel : 2;
        unsigned int gpo4_sel : 2;
        unsigned int gpo5_sel : 2;
        unsigned int reserved_0: 2;
        unsigned int gpo10_sel : 2;
        unsigned int gpo11_sel : 2;
        unsigned int gpo12_sel : 2;
        unsigned int reserved_1: 16;
    } reg;
} SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo2_sel_START (0)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo2_sel_END (1)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo3_sel_START (2)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo3_sel_END (3)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo4_sel_START (4)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo4_sel_END (5)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo5_sel_START (6)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo5_sel_END (7)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo10_sel_START (10)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo10_sel_END (11)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo11_sel_START (12)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo11_sel_END (13)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo12_sel_START (14)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_1_gpo12_sel_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode_repeat : 7;
        unsigned int reserved_0 : 1;
        unsigned int pwm_mode : 7;
        unsigned int reserved_1 : 1;
        unsigned int start : 7;
        unsigned int reserved_2 : 9;
    } reg;
} SOC_ISP_ISPSS_CTRL_GPO_CTRL_2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_2_mode_repeat_START (0)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_2_mode_repeat_END (6)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_2_pwm_mode_START (8)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_2_pwm_mode_END (14)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_2_start_START (16)
#define SOC_ISP_ISPSS_CTRL_GPO_CTRL_2_start_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo5_seq_pat_1 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_1_1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_1_1_pwm_gpo5_seq_pat_1_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_1_1_pwm_gpo5_seq_pat_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo5_seq_pat_2 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_1_2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_1_2_pwm_gpo5_seq_pat_2_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_1_2_pwm_gpo5_seq_pat_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo4_seq_pat_1 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_2_1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_2_1_pwm_gpo4_seq_pat_1_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_2_1_pwm_gpo4_seq_pat_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo4_seq_pat_2 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_2_2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_2_2_pwm_gpo4_seq_pat_2_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_2_2_pwm_gpo4_seq_pat_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo2_seq_pat_1 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_3_1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_3_1_pwm_gpo2_seq_pat_1_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_3_1_pwm_gpo2_seq_pat_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo2_seq_pat_2 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_3_2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_3_2_pwm_gpo2_seq_pat_2_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_3_2_pwm_gpo2_seq_pat_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo3_seq_pat_1 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_4_1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_4_1_pwm_gpo3_seq_pat_1_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_4_1_pwm_gpo3_seq_pat_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo3_seq_pat_2 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_4_2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_4_2_pwm_gpo3_seq_pat_2_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_4_2_pwm_gpo3_seq_pat_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo6_seq_pat_1 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_5_1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_5_1_pwm_gpo6_seq_pat_1_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_5_1_pwm_gpo6_seq_pat_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo6_seq_pat_2 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_5_2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_5_2_pwm_gpo6_seq_pat_2_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_5_2_pwm_gpo6_seq_pat_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo11_seq_pat_1 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_6_1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_6_1_pwm_gpo11_seq_pat_1_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_6_1_pwm_gpo11_seq_pat_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo11_seq_pat_2 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_6_2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_6_2_pwm_gpo11_seq_pat_2_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_6_2_pwm_gpo11_seq_pat_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo12_seq_pat_1 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_7_1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_7_1_pwm_gpo12_seq_pat_1_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_7_1_pwm_gpo12_seq_pat_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pwm_gpo12_seq_pat_2 : 32;
    } reg;
} SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_7_2_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_7_2_pwm_gpo12_seq_pat_2_START (0)
#define SOC_ISP_ISPSS_CTRL_PATTERN_CTRL_7_2_pwm_gpo12_seq_pat_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prediv : 27;
        unsigned int reserved : 5;
    } reg;
} SOC_ISP_ISPSS_CTRL_PRE_DIV_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PRE_DIV_prediv_START (0)
#define SOC_ISP_ISPSS_CTRL_PRE_DIV_prediv_END (26)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 13;
        unsigned int reserved_3: 3;
    } reg;
} SOC_ISP_ISPSS_CTRL_CROP_H_4_P1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 13;
        unsigned int reserved_3: 3;
    } reg;
} SOC_ISP_ISPSS_CTRL_CROP_V_4_P1_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 13;
        unsigned int reserved_3: 3;
    } reg;
} SOC_ISP_ISPSS_CTRL_CROP_H_4_P2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 3;
        unsigned int reserved_2: 13;
        unsigned int reserved_3: 3;
    } reg;
} SOC_ISP_ISPSS_CTRL_CROP_V_4_P2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 2;
        unsigned int ctrl_vpbg_8_1 : 2;
        unsigned int reserved_4 : 2;
        unsigned int reserved_5 : 2;
        unsigned int reserved_6 : 2;
        unsigned int reserved_7 : 2;
        unsigned int reserved_8 : 2;
        unsigned int reserved_9 : 2;
        unsigned int reserved_10 : 2;
        unsigned int reserved_11 : 2;
        unsigned int reserved_12 : 2;
        unsigned int reserved_13 : 2;
        unsigned int reserved_14 : 2;
    } reg;
} SOC_ISP_ISPSS_CTRL_VPBG_CTRL_1_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_VPBG_CTRL_1_ctrl_vpbg_8_1_START (8)
#define SOC_ISP_ISPSS_CTRL_VPBG_CTRL_1_ctrl_vpbg_8_1_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 2;
        unsigned int reserved_1: 2;
        unsigned int reserved_2: 2;
        unsigned int reserved_3: 10;
        unsigned int reserved_4: 2;
        unsigned int reserved_5: 2;
        unsigned int reserved_6: 2;
        unsigned int reserved_7: 2;
        unsigned int reserved_8: 2;
        unsigned int reserved_9: 2;
        unsigned int reserved_10: 2;
        unsigned int reserved_11: 2;
    } reg;
} SOC_ISP_ISPSS_CTRL_VPBG_CTRL_2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ctrl_vpbg_37_1 : 5;
        unsigned int reserved_0 : 3;
        unsigned int reserved_1 : 3;
        unsigned int reserved_2 : 21;
    } reg;
} SOC_ISP_ISPSS_CTRL_VPBG_CTRL_3_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_VPBG_CTRL_3_ctrl_vpbg_37_1_START (0)
#define SOC_ISP_ISPSS_CTRL_VPBG_CTRL_3_ctrl_vpbg_37_1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxactivehs_0 : 1;
        unsigned int rxactivehs_1 : 1;
        unsigned int rxactivehs_2 : 1;
        unsigned int rxactivehs_3 : 1;
        unsigned int rxlpdtesc_0 : 1;
        unsigned int rxlpdtesc_1 : 1;
        unsigned int rxlpdtesc_2 : 1;
        unsigned int rxlpdtesc_3 : 1;
        unsigned int ulpsactivenot_0 : 1;
        unsigned int ulpsactivenot_1 : 1;
        unsigned int ulpsactivenot_2 : 1;
        unsigned int ulpsactivenot_3 : 1;
        unsigned int errsyncesc_0 : 1;
        unsigned int errsyncesc_1 : 1;
        unsigned int errsyncesc_2 : 1;
        unsigned int errsyncesc_3 : 1;
        unsigned int ulpsactivenotclk : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxactivehs_0_START (0)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxactivehs_0_END (0)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxactivehs_1_START (1)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxactivehs_1_END (1)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxactivehs_2_START (2)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxactivehs_2_END (2)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxactivehs_3_START (3)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxactivehs_3_END (3)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxlpdtesc_0_START (4)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxlpdtesc_0_END (4)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxlpdtesc_1_START (5)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxlpdtesc_1_END (5)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxlpdtesc_2_START (6)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxlpdtesc_2_END (6)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxlpdtesc_3_START (7)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_rxlpdtesc_3_END (7)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_ulpsactivenot_0_START (8)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_ulpsactivenot_0_END (8)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_ulpsactivenot_1_START (9)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_ulpsactivenot_1_END (9)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_ulpsactivenot_2_START (10)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_ulpsactivenot_2_END (10)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_ulpsactivenot_3_START (11)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_ulpsactivenot_3_END (11)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_errsyncesc_0_START (12)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_errsyncesc_0_END (12)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_errsyncesc_1_START (13)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_errsyncesc_1_END (13)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_errsyncesc_2_START (14)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_errsyncesc_2_END (14)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_errsyncesc_3_START (15)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_errsyncesc_3_END (15)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_ulpsactivenotclk_START (16)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_A_DBG_ulpsactivenotclk_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rxactivehs_0 : 1;
        unsigned int rxactivehs_1 : 1;
        unsigned int rxactivehs_2 : 1;
        unsigned int rxactivehs_3 : 1;
        unsigned int rxlpdtesc_0 : 1;
        unsigned int rxlpdtesc_1 : 1;
        unsigned int rxlpdtesc_2 : 1;
        unsigned int rxlpdtesc_3 : 1;
        unsigned int ulpsactivenot_0 : 1;
        unsigned int ulpsactivenot_1 : 1;
        unsigned int ulpsactivenot_2 : 1;
        unsigned int ulpsactivenot_3 : 1;
        unsigned int errsyncesc_0 : 1;
        unsigned int errsyncesc_1 : 1;
        unsigned int errsyncesc_2 : 1;
        unsigned int errsyncesc_3 : 1;
        unsigned int ulpsactivenotclk : 1;
        unsigned int reserved : 15;
    } reg;
} SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxactivehs_0_START (0)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxactivehs_0_END (0)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxactivehs_1_START (1)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxactivehs_1_END (1)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxactivehs_2_START (2)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxactivehs_2_END (2)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxactivehs_3_START (3)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxactivehs_3_END (3)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxlpdtesc_0_START (4)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxlpdtesc_0_END (4)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxlpdtesc_1_START (5)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxlpdtesc_1_END (5)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxlpdtesc_2_START (6)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxlpdtesc_2_END (6)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxlpdtesc_3_START (7)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_rxlpdtesc_3_END (7)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_ulpsactivenot_0_START (8)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_ulpsactivenot_0_END (8)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_ulpsactivenot_1_START (9)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_ulpsactivenot_1_END (9)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_ulpsactivenot_2_START (10)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_ulpsactivenot_2_END (10)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_ulpsactivenot_3_START (11)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_ulpsactivenot_3_END (11)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_errsyncesc_0_START (12)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_errsyncesc_0_END (12)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_errsyncesc_1_START (13)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_errsyncesc_1_END (13)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_errsyncesc_2_START (14)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_errsyncesc_2_END (14)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_errsyncesc_3_START (15)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_errsyncesc_3_END (15)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_ulpsactivenotclk_START (16)
#define SOC_ISP_ISPSS_CTRL_PHY_CSI_B_DBG_ulpsactivenotclk_END (16)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 1;
        unsigned int reserved_1: 1;
        unsigned int reserved_2: 1;
        unsigned int reserved_3: 1;
        unsigned int reserved_4: 1;
        unsigned int reserved_5: 1;
        unsigned int reserved_6: 1;
        unsigned int reserved_7: 1;
        unsigned int reserved_8: 1;
        unsigned int reserved_9: 1;
        unsigned int reserved_10: 1;
        unsigned int reserved_11: 1;
        unsigned int reserved_12: 1;
        unsigned int reserved_13: 1;
        unsigned int reserved_14: 1;
        unsigned int reserved_15: 1;
        unsigned int reserved_16: 1;
        unsigned int reserved_17: 15;
    } reg;
} SOC_ISP_ISPSS_CTRL_PHY_CSI_C_DBG_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 2;
        unsigned int reserved_3 : 3;
        unsigned int reserved_4 : 2;
        unsigned int reserved_5 : 2;
        unsigned int tpsbram_kp : 3;
        unsigned int tpsbram_wtsel : 2;
        unsigned int tpsbram_rtsel : 2;
        unsigned int spmbram_wtsel : 2;
        unsigned int spmbram_rtsel : 2;
        unsigned int spsbram_wtsel : 2;
        unsigned int spsbram_rtsel : 2;
        unsigned int reserved_6 : 4;
    } reg;
} SOC_ISP_ISPSS_CTRL_MEM_CTRL_UNION;
#endif
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_tpsbram_kp_START (13)
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_tpsbram_kp_END (15)
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_tpsbram_wtsel_START (16)
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_tpsbram_wtsel_END (17)
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_tpsbram_rtsel_START (18)
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_tpsbram_rtsel_END (19)
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_spmbram_wtsel_START (20)
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_spmbram_wtsel_END (21)
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_spmbram_rtsel_START (22)
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_spmbram_rtsel_END (23)
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_spsbram_wtsel_START (24)
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_spsbram_wtsel_END (25)
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_spsbram_rtsel_START (26)
#define SOC_ISP_ISPSS_CTRL_MEM_CTRL_spsbram_rtsel_END (27)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
