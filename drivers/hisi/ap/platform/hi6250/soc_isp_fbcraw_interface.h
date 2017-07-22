#ifndef __SOC_ISP_FBCRAW_INTERFACE_H__
#define __SOC_ISP_FBCRAW_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_FBCRAW_FBC_CFG1_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_FBCRAW_FBC_CFG2_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_FBCRAW_FBC_CFG3_ADDR(base) ((base) + (0x0008))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bypass : 1;
        unsigned int reserved_0 : 1;
        unsigned int pix_size : 2;
        unsigned int reserved_1 : 4;
        unsigned int extra_budget : 6;
        unsigned int reserved_2 : 2;
        unsigned int line_width : 13;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_ISP_FBCRAW_FBC_CFG1_UNION;
#endif
#define SOC_ISP_FBCRAW_FBC_CFG1_bypass_START (0)
#define SOC_ISP_FBCRAW_FBC_CFG1_bypass_END (0)
#define SOC_ISP_FBCRAW_FBC_CFG1_pix_size_START (2)
#define SOC_ISP_FBCRAW_FBC_CFG1_pix_size_END (3)
#define SOC_ISP_FBCRAW_FBC_CFG1_extra_budget_START (8)
#define SOC_ISP_FBCRAW_FBC_CFG1_extra_budget_END (13)
#define SOC_ISP_FBCRAW_FBC_CFG1_line_width_START (16)
#define SOC_ISP_FBCRAW_FBC_CFG1_line_width_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int initqp : 6;
        unsigned int reserved_0: 10;
        unsigned int bit_thres : 8;
        unsigned int reserved_1: 8;
    } reg;
} SOC_ISP_FBCRAW_FBC_CFG2_UNION;
#endif
#define SOC_ISP_FBCRAW_FBC_CFG2_initqp_START (0)
#define SOC_ISP_FBCRAW_FBC_CFG2_initqp_END (5)
#define SOC_ISP_FBCRAW_FBC_CFG2_bit_thres_START (16)
#define SOC_ISP_FBCRAW_FBC_CFG2_bit_thres_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int step_size : 7;
        unsigned int reserved_0 : 1;
        unsigned int nb_rstmkr : 6;
        unsigned int reserved_1 : 2;
        unsigned int encoding_width : 13;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_ISP_FBCRAW_FBC_CFG3_UNION;
#endif
#define SOC_ISP_FBCRAW_FBC_CFG3_step_size_START (0)
#define SOC_ISP_FBCRAW_FBC_CFG3_step_size_END (6)
#define SOC_ISP_FBCRAW_FBC_CFG3_nb_rstmkr_START (8)
#define SOC_ISP_FBCRAW_FBC_CFG3_nb_rstmkr_END (13)
#define SOC_ISP_FBCRAW_FBC_CFG3_encoding_width_START (16)
#define SOC_ISP_FBCRAW_FBC_CFG3_encoding_width_END (28)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
