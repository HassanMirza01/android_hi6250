#ifndef __SOC_ISP_BLC_INTERFACE_H__
#define __SOC_ISP_BLC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_BLC_BLS_CTRL_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_BLC_BLS_SAMPLES_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_BLC_BLS_H1_START_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_BLC_BLS_H1_STOP_ADDR(base) ((base) + (0x000C))
#define SOC_ISP_BLC_BLS_V1_START_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_BLC_BLS_V1_STOP_ADDR(base) ((base) + (0x0014))
#define SOC_ISP_BLC_BLS_H2_START_ADDR(base) ((base) + (0x0018))
#define SOC_ISP_BLC_BLS_H2_STOP_ADDR(base) ((base) + (0x001C))
#define SOC_ISP_BLC_BLS_V2_START_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_BLC_BLS_V2_STOP_ADDR(base) ((base) + (0x0024))
#define SOC_ISP_BLC_BLS_A_FIXED_ADDR(base) ((base) + (0x0028))
#define SOC_ISP_BLC_BLS_B_FIXED_ADDR(base) ((base) + (0x002C))
#define SOC_ISP_BLC_BLS_C_FIXED_ADDR(base) ((base) + (0x0030))
#define SOC_ISP_BLC_BLS_D_FIXED_ADDR(base) ((base) + (0x0034))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bls_enable : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 28;
    } reg;
} SOC_ISP_BLC_BLS_CTRL_UNION;
#endif
#define SOC_ISP_BLC_BLS_CTRL_bls_enable_START (0)
#define SOC_ISP_BLC_BLS_CTRL_bls_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 5;
        unsigned int reserved_1: 27;
    } reg;
} SOC_ISP_BLC_BLS_SAMPLES_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 14;
        unsigned int reserved_1: 18;
    } reg;
} SOC_ISP_BLC_BLS_H1_START_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 14;
        unsigned int reserved_1: 18;
    } reg;
} SOC_ISP_BLC_BLS_H1_STOP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 14;
        unsigned int reserved_1: 18;
    } reg;
} SOC_ISP_BLC_BLS_V1_START_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 14;
        unsigned int reserved_1: 18;
    } reg;
} SOC_ISP_BLC_BLS_V1_STOP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 14;
        unsigned int reserved_1: 18;
    } reg;
} SOC_ISP_BLC_BLS_H2_START_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 14;
        unsigned int reserved_1: 18;
    } reg;
} SOC_ISP_BLC_BLS_H2_STOP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 14;
        unsigned int reserved_1: 18;
    } reg;
} SOC_ISP_BLC_BLS_V2_START_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 14;
        unsigned int reserved_1: 18;
    } reg;
} SOC_ISP_BLC_BLS_V2_STOP_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bls_a_fixed : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_ISP_BLC_BLS_A_FIXED_UNION;
#endif
#define SOC_ISP_BLC_BLS_A_FIXED_bls_a_fixed_START (0)
#define SOC_ISP_BLC_BLS_A_FIXED_bls_a_fixed_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bls_b_fixed : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_ISP_BLC_BLS_B_FIXED_UNION;
#endif
#define SOC_ISP_BLC_BLS_B_FIXED_bls_b_fixed_START (0)
#define SOC_ISP_BLC_BLS_B_FIXED_bls_b_fixed_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bls_c_fixed : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_ISP_BLC_BLS_C_FIXED_UNION;
#endif
#define SOC_ISP_BLC_BLS_C_FIXED_bls_c_fixed_START (0)
#define SOC_ISP_BLC_BLS_C_FIXED_bls_c_fixed_END (14)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bls_d_fixed : 15;
        unsigned int reserved : 17;
    } reg;
} SOC_ISP_BLC_BLS_D_FIXED_UNION;
#endif
#define SOC_ISP_BLC_BLS_D_FIXED_bls_d_fixed_START (0)
#define SOC_ISP_BLC_BLS_D_FIXED_bls_d_fixed_END (14)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
