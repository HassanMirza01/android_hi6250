#ifndef __SOC_ISP_CC_INTERFACE_H__
#define __SOC_ISP_CC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_CC_CCCFG_ADDR(base) ((base) + (0x000))
#define SOC_ISP_CC_BRIGHTCOEFF_ADDR(base) ((base) + (0x004))
#define SOC_ISP_CC_DARKCOEFF_ADDR(base) ((base) + (0x008))
#define SOC_ISP_CC_THRESA_ADDR(base) ((base) + (0x018))
#define SOC_ISP_CC_THRESB_ADDR(base) ((base) + (0x01C))
#define SOC_ISP_CC_THRESC_ADDR(base) ((base) + (0x020))
#define SOC_ISP_CC_CCMATRIXA0_ADDR(base) ((base) + (0x024))
#define SOC_ISP_CC_CCMATRIXA1_ADDR(base) ((base) + (0x028))
#define SOC_ISP_CC_CCMATRIXA2_ADDR(base) ((base) + (0x02C))
#define SOC_ISP_CC_CCMATRIXA3_ADDR(base) ((base) + (0x030))
#define SOC_ISP_CC_CCMATRIXA4_ADDR(base) ((base) + (0x034))
#define SOC_ISP_CC_CCMATRIXA5_ADDR(base) ((base) + (0x038))
#define SOC_ISP_CC_PIX_YCOEF_ADDR(base) ((base) + (0x0044))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bimplementcc : 1;
        unsigned int bpixyconst : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ISP_CC_CCCFG_UNION;
#endif
#define SOC_ISP_CC_CCCFG_bimplementcc_START (0)
#define SOC_ISP_CC_CCCFG_bimplementcc_END (0)
#define SOC_ISP_CC_CCCFG_bpixyconst_START (1)
#define SOC_ISP_CC_CCCFG_bpixyconst_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brightcoeffab : 15;
        unsigned int reserved_0 : 1;
        unsigned int brightcoeffbc : 15;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_ISP_CC_BRIGHTCOEFF_UNION;
#endif
#define SOC_ISP_CC_BRIGHTCOEFF_brightcoeffab_START (0)
#define SOC_ISP_CC_BRIGHTCOEFF_brightcoeffab_END (14)
#define SOC_ISP_CC_BRIGHTCOEFF_brightcoeffbc_START (16)
#define SOC_ISP_CC_BRIGHTCOEFF_brightcoeffbc_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int darkcoeffab : 15;
        unsigned int reserved_0 : 1;
        unsigned int darkcoeffbc : 15;
        unsigned int reserved_1 : 1;
    } reg;
} SOC_ISP_CC_DARKCOEFF_UNION;
#endif
#define SOC_ISP_CC_DARKCOEFF_darkcoeffab_START (0)
#define SOC_ISP_CC_DARKCOEFF_darkcoeffab_END (14)
#define SOC_ISP_CC_DARKCOEFF_darkcoeffbc_START (16)
#define SOC_ISP_CC_DARKCOEFF_darkcoeffbc_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brightthres_0 : 12;
        unsigned int reserved_0 : 4;
        unsigned int brightthres_1 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CC_THRESA_UNION;
#endif
#define SOC_ISP_CC_THRESA_brightthres_0_START (0)
#define SOC_ISP_CC_THRESA_brightthres_0_END (11)
#define SOC_ISP_CC_THRESA_brightthres_1_START (16)
#define SOC_ISP_CC_THRESA_brightthres_1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int darthres_0 : 12;
        unsigned int reserved_0 : 4;
        unsigned int darkthres_1 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CC_THRESB_UNION;
#endif
#define SOC_ISP_CC_THRESB_darthres_0_START (0)
#define SOC_ISP_CC_THRESB_darthres_0_END (11)
#define SOC_ISP_CC_THRESB_darkthres_1_START (16)
#define SOC_ISP_CC_THRESB_darkthres_1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int brightthres_2 : 12;
        unsigned int reserved_0 : 4;
        unsigned int darkthres_2 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CC_THRESC_UNION;
#endif
#define SOC_ISP_CC_THRESC_brightthres_2_START (0)
#define SOC_ISP_CC_THRESC_brightthres_2_END (11)
#define SOC_ISP_CC_THRESC_darkthres_2_START (16)
#define SOC_ISP_CC_THRESC_darkthres_2_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coeff0 : 14;
        unsigned int reserved_0: 2;
        unsigned int coeff1 : 14;
        unsigned int reserved_1: 2;
    } reg;
} SOC_ISP_CC_CCMATRIXA0_UNION;
#endif
#define SOC_ISP_CC_CCMATRIXA0_coeff0_START (0)
#define SOC_ISP_CC_CCMATRIXA0_coeff0_END (13)
#define SOC_ISP_CC_CCMATRIXA0_coeff1_START (16)
#define SOC_ISP_CC_CCMATRIXA0_coeff1_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coeff2 : 14;
        unsigned int reserved_0: 2;
        unsigned int coeff3 : 14;
        unsigned int reserved_1: 2;
    } reg;
} SOC_ISP_CC_CCMATRIXA1_UNION;
#endif
#define SOC_ISP_CC_CCMATRIXA1_coeff2_START (0)
#define SOC_ISP_CC_CCMATRIXA1_coeff2_END (13)
#define SOC_ISP_CC_CCMATRIXA1_coeff3_START (16)
#define SOC_ISP_CC_CCMATRIXA1_coeff3_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coeff4 : 14;
        unsigned int reserved_0: 2;
        unsigned int coeff5 : 14;
        unsigned int reserved_1: 2;
    } reg;
} SOC_ISP_CC_CCMATRIXA2_UNION;
#endif
#define SOC_ISP_CC_CCMATRIXA2_coeff4_START (0)
#define SOC_ISP_CC_CCMATRIXA2_coeff4_END (13)
#define SOC_ISP_CC_CCMATRIXA2_coeff5_START (16)
#define SOC_ISP_CC_CCMATRIXA2_coeff5_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coeff6 : 14;
        unsigned int reserved_0: 2;
        unsigned int coeff7 : 14;
        unsigned int reserved_1: 2;
    } reg;
} SOC_ISP_CC_CCMATRIXA3_UNION;
#endif
#define SOC_ISP_CC_CCMATRIXA3_coeff6_START (0)
#define SOC_ISP_CC_CCMATRIXA3_coeff6_END (13)
#define SOC_ISP_CC_CCMATRIXA3_coeff7_START (16)
#define SOC_ISP_CC_CCMATRIXA3_coeff7_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coeff8 : 14;
        unsigned int reserved_0: 2;
        unsigned int coeff9 : 14;
        unsigned int reserved_1: 2;
    } reg;
} SOC_ISP_CC_CCMATRIXA4_UNION;
#endif
#define SOC_ISP_CC_CCMATRIXA4_coeff8_START (0)
#define SOC_ISP_CC_CCMATRIXA4_coeff8_END (13)
#define SOC_ISP_CC_CCMATRIXA4_coeff9_START (16)
#define SOC_ISP_CC_CCMATRIXA4_coeff9_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int coeff10 : 14;
        unsigned int reserved_0: 2;
        unsigned int coeff11 : 14;
        unsigned int reserved_1: 2;
    } reg;
} SOC_ISP_CC_CCMATRIXA5_UNION;
#endif
#define SOC_ISP_CC_CCMATRIXA5_coeff10_START (0)
#define SOC_ISP_CC_CCMATRIXA5_coeff10_END (13)
#define SOC_ISP_CC_CCMATRIXA5_coeff11_START (16)
#define SOC_ISP_CC_CCMATRIXA5_coeff11_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pix_ycoef_val : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ISP_CC_PIX_YCOEF_UNION;
#endif
#define SOC_ISP_CC_PIX_YCOEF_pix_ycoef_val_START (0)
#define SOC_ISP_CC_PIX_YCOEF_pix_ycoef_val_END (5)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
