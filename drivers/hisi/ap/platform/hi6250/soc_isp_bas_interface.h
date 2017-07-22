#ifndef __SOC_ISP_BAS_INTERFACE_H__
#define __SOC_ISP_BAS_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_BAS_BAS_MODE_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_BAS_BAS_IHLEFT_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_BAS_BAS_IHRIGHT_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_BAS_BAS_IVTOP_ADDR(base) ((base) + (0x000C))
#define SOC_ISP_BAS_BAS_IVBOTTOM_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_BAS_BAS_IHINC_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_BAS_BAS_IVINC_ADDR(base) ((base) + (0x0018))
#define SOC_ISP_BAS_BAS_COEF_ACTIVE_ADDR(base) ((base) + (0x001C))
#define SOC_ISP_BAS_BAS_H_COEF_0_ADDR(base,TAP6) ((base) + (0x0100+0x4*(TAP6)))
#define SOC_ISP_BAS_BAS_H_COEF_1_ADDR(base,TAP6) ((base) + (0x0200+0x4*(TAP6)))
#define SOC_ISP_BAS_BAS_V4TAP_COEF_0_ADDR(base,TAP4) ((base) + (0x0300+0x4*(TAP4)))
#define SOC_ISP_BAS_BAS_V4TAP_COEF_1_ADDR(base,TAP4) ((base) + (0x0400+0x4*(TAP4)))
#define SOC_ISP_BAS_BAS_V6TAP_COEF_0_ADDR(base,TAP6) ((base) + (0x0500+0x4*(TAP6)))
#define SOC_ISP_BAS_BAS_V6TAP_COEF_1_ADDR(base,TAP6) ((base) + (0x0600+0x4*(TAP6)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mode : 2;
        unsigned int v_filter_sel : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISP_BAS_BAS_MODE_UNION;
#endif
#define SOC_ISP_BAS_BAS_MODE_mode_START (0)
#define SOC_ISP_BAS_BAS_MODE_mode_END (1)
#define SOC_ISP_BAS_BAS_MODE_v_filter_sel_START (2)
#define SOC_ISP_BAS_BAS_MODE_v_filter_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihleft : 32;
    } reg;
} SOC_ISP_BAS_BAS_IHLEFT_UNION;
#endif
#define SOC_ISP_BAS_BAS_IHLEFT_ihleft_START (0)
#define SOC_ISP_BAS_BAS_IHLEFT_ihleft_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihright : 32;
    } reg;
} SOC_ISP_BAS_BAS_IHRIGHT_UNION;
#endif
#define SOC_ISP_BAS_BAS_IHRIGHT_ihright_START (0)
#define SOC_ISP_BAS_BAS_IHRIGHT_ihright_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivtop : 32;
    } reg;
} SOC_ISP_BAS_BAS_IVTOP_UNION;
#endif
#define SOC_ISP_BAS_BAS_IVTOP_ivtop_START (0)
#define SOC_ISP_BAS_BAS_IVTOP_ivtop_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivbottom : 32;
    } reg;
} SOC_ISP_BAS_BAS_IVBOTTOM_UNION;
#endif
#define SOC_ISP_BAS_BAS_IVBOTTOM_ivbottom_START (0)
#define SOC_ISP_BAS_BAS_IVBOTTOM_ivbottom_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihinc : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_ISP_BAS_BAS_IHINC_UNION;
#endif
#define SOC_ISP_BAS_BAS_IHINC_ihinc_START (0)
#define SOC_ISP_BAS_BAS_IHINC_ihinc_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivinc : 22;
        unsigned int reserved : 10;
    } reg;
} SOC_ISP_BAS_BAS_IVINC_UNION;
#endif
#define SOC_ISP_BAS_BAS_IVINC_ivinc_START (0)
#define SOC_ISP_BAS_BAS_IVINC_ivinc_END (21)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int h_coef_active : 1;
        unsigned int v_coef_4tap_active : 1;
        unsigned int v_coef_6tap_active : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISP_BAS_BAS_COEF_ACTIVE_UNION;
#endif
#define SOC_ISP_BAS_BAS_COEF_ACTIVE_h_coef_active_START (0)
#define SOC_ISP_BAS_BAS_COEF_ACTIVE_h_coef_active_END (0)
#define SOC_ISP_BAS_BAS_COEF_ACTIVE_v_coef_4tap_active_START (1)
#define SOC_ISP_BAS_BAS_COEF_ACTIVE_v_coef_4tap_active_END (1)
#define SOC_ISP_BAS_BAS_COEF_ACTIVE_v_coef_6tap_active_START (2)
#define SOC_ISP_BAS_BAS_COEF_ACTIVE_v_coef_6tap_active_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int h6tap_coef0_0_5 : 7;
        unsigned int reserved_0 : 1;
        unsigned int h6tap_coef0_1_4 : 8;
        unsigned int h6tap_coef0_2_3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_BAS_BAS_H_COEF_0_UNION;
#endif
#define SOC_ISP_BAS_BAS_H_COEF_0_h6tap_coef0_0_5_START (0)
#define SOC_ISP_BAS_BAS_H_COEF_0_h6tap_coef0_0_5_END (6)
#define SOC_ISP_BAS_BAS_H_COEF_0_h6tap_coef0_1_4_START (8)
#define SOC_ISP_BAS_BAS_H_COEF_0_h6tap_coef0_1_4_END (15)
#define SOC_ISP_BAS_BAS_H_COEF_0_h6tap_coef0_2_3_START (16)
#define SOC_ISP_BAS_BAS_H_COEF_0_h6tap_coef0_2_3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int h6tap_coef1_0_5 : 7;
        unsigned int reserved_0 : 1;
        unsigned int h6tap_coef1_1_4 : 8;
        unsigned int h6tap_coef1_2_3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_BAS_BAS_H_COEF_1_UNION;
#endif
#define SOC_ISP_BAS_BAS_H_COEF_1_h6tap_coef1_0_5_START (0)
#define SOC_ISP_BAS_BAS_H_COEF_1_h6tap_coef1_0_5_END (6)
#define SOC_ISP_BAS_BAS_H_COEF_1_h6tap_coef1_1_4_START (8)
#define SOC_ISP_BAS_BAS_H_COEF_1_h6tap_coef1_1_4_END (15)
#define SOC_ISP_BAS_BAS_H_COEF_1_h6tap_coef1_2_3_START (16)
#define SOC_ISP_BAS_BAS_H_COEF_1_h6tap_coef1_2_3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 8;
        unsigned int v4tap_coef0_0_3 : 8;
        unsigned int v4tap_coef0_1_2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_BAS_BAS_V4TAP_COEF_0_UNION;
#endif
#define SOC_ISP_BAS_BAS_V4TAP_COEF_0_v4tap_coef0_0_3_START (8)
#define SOC_ISP_BAS_BAS_V4TAP_COEF_0_v4tap_coef0_0_3_END (15)
#define SOC_ISP_BAS_BAS_V4TAP_COEF_0_v4tap_coef0_1_2_START (16)
#define SOC_ISP_BAS_BAS_V4TAP_COEF_0_v4tap_coef0_1_2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 8;
        unsigned int v4tap_coef1_0_3 : 8;
        unsigned int v4tap_coef1_1_2 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_BAS_BAS_V4TAP_COEF_1_UNION;
#endif
#define SOC_ISP_BAS_BAS_V4TAP_COEF_1_v4tap_coef1_0_3_START (8)
#define SOC_ISP_BAS_BAS_V4TAP_COEF_1_v4tap_coef1_0_3_END (15)
#define SOC_ISP_BAS_BAS_V4TAP_COEF_1_v4tap_coef1_1_2_START (16)
#define SOC_ISP_BAS_BAS_V4TAP_COEF_1_v4tap_coef1_1_2_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int v6tap_coef0_0_5 : 7;
        unsigned int reserved_0 : 1;
        unsigned int v6tap_coef0_1_4 : 8;
        unsigned int v6tap_coef0_2_3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_BAS_BAS_V6TAP_COEF_0_UNION;
#endif
#define SOC_ISP_BAS_BAS_V6TAP_COEF_0_v6tap_coef0_0_5_START (0)
#define SOC_ISP_BAS_BAS_V6TAP_COEF_0_v6tap_coef0_0_5_END (6)
#define SOC_ISP_BAS_BAS_V6TAP_COEF_0_v6tap_coef0_1_4_START (8)
#define SOC_ISP_BAS_BAS_V6TAP_COEF_0_v6tap_coef0_1_4_END (15)
#define SOC_ISP_BAS_BAS_V6TAP_COEF_0_v6tap_coef0_2_3_START (16)
#define SOC_ISP_BAS_BAS_V6TAP_COEF_0_v6tap_coef0_2_3_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int v6tap_coef1_0_5 : 7;
        unsigned int reserved_0 : 1;
        unsigned int v6tap_coef1_1_4 : 8;
        unsigned int v6tap_coef1_2_3 : 10;
        unsigned int reserved_1 : 6;
    } reg;
} SOC_ISP_BAS_BAS_V6TAP_COEF_1_UNION;
#endif
#define SOC_ISP_BAS_BAS_V6TAP_COEF_1_v6tap_coef1_0_5_START (0)
#define SOC_ISP_BAS_BAS_V6TAP_COEF_1_v6tap_coef1_0_5_END (6)
#define SOC_ISP_BAS_BAS_V6TAP_COEF_1_v6tap_coef1_1_4_START (8)
#define SOC_ISP_BAS_BAS_V6TAP_COEF_1_v6tap_coef1_1_4_END (15)
#define SOC_ISP_BAS_BAS_V6TAP_COEF_1_v6tap_coef1_2_3_START (16)
#define SOC_ISP_BAS_BAS_V6TAP_COEF_1_v6tap_coef1_2_3_END (25)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
