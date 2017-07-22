#ifndef __SOC_ISP_FE_INTERFACE_H__
#define __SOC_ISP_FE_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_FE_FCLK_EN_FE_ADDR(base) ((base) + (0x0))
#define SOC_ISP_FE_CONTROL_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_FE_CROP_H_1_ADDR(base) ((base) + (0x0020))
#define SOC_ISP_FE_CROP_V_1_ADDR(base) ((base) + (0x0024))
#define SOC_ISP_FE_ACQ_H_OFFSET_ADDR(base) ((base) + (0x0030))
#define SOC_ISP_FE_ACQ_V_OFFSET_ADDR(base) ((base) + (0x0034))
#define SOC_ISP_FE_ACQ_H_SIZE_ADDR(base) ((base) + (0x0038))
#define SOC_ISP_FE_ACQ_V_SIZE_ADDR(base) ((base) + (0x003C))
#define SOC_ISP_FE_OUT_H_OFFSET_ADDR(base) ((base) + (0x0040))
#define SOC_ISP_FE_OUT_V_OFFSET_ADDR(base) ((base) + (0x0044))
#define SOC_ISP_FE_OUT_H_SIZE_ADDR(base) ((base) + (0x0048))
#define SOC_ISP_FE_OUT_V_SIZE_ADDR(base) ((base) + (0x004C))
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_ADDR(base) ((base) + (0x0050))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fclk_en_fe : 16;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_FE_FCLK_EN_FE_UNION;
#endif
#define SOC_ISP_FE_FCLK_EN_FE_fclk_en_fe_START (0)
#define SOC_ISP_FE_FCLK_EN_FE_fclk_en_fe_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 2;
        unsigned int bayer_pat_fe : 2;
        unsigned int ir_position : 1;
        unsigned int sensor_ir : 1;
        unsigned int ff_before_pdaf : 1;
        unsigned int reserved_2 : 24;
    } reg;
} SOC_ISP_FE_CONTROL_UNION;
#endif
#define SOC_ISP_FE_CONTROL_bayer_pat_fe_START (3)
#define SOC_ISP_FE_CONTROL_bayer_pat_fe_END (4)
#define SOC_ISP_FE_CONTROL_ir_position_START (5)
#define SOC_ISP_FE_CONTROL_ir_position_END (5)
#define SOC_ISP_FE_CONTROL_sensor_ir_START (6)
#define SOC_ISP_FE_CONTROL_sensor_ir_END (6)
#define SOC_ISP_FE_CONTROL_ff_before_pdaf_START (7)
#define SOC_ISP_FE_CONTROL_ff_before_pdaf_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ihleft : 13;
        unsigned int reserved_0: 3;
        unsigned int ihright : 13;
        unsigned int reserved_1: 3;
    } reg;
} SOC_ISP_FE_CROP_H_1_UNION;
#endif
#define SOC_ISP_FE_CROP_H_1_ihleft_START (0)
#define SOC_ISP_FE_CROP_H_1_ihleft_END (12)
#define SOC_ISP_FE_CROP_H_1_ihright_START (16)
#define SOC_ISP_FE_CROP_H_1_ihright_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ivtop : 13;
        unsigned int reserved_0: 3;
        unsigned int ivbottom : 13;
        unsigned int reserved_1: 3;
    } reg;
} SOC_ISP_FE_CROP_V_1_UNION;
#endif
#define SOC_ISP_FE_CROP_V_1_ivtop_START (0)
#define SOC_ISP_FE_CROP_V_1_ivtop_END (12)
#define SOC_ISP_FE_CROP_V_1_ivbottom_START (16)
#define SOC_ISP_FE_CROP_V_1_ivbottom_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_ACQ_H_OFFSET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_ACQ_V_OFFSET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_ACQ_H_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_ACQ_V_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_OUT_H_OFFSET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_OUT_V_OFFSET_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_OUT_H_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0: 13;
        unsigned int reserved_1: 19;
    } reg;
} SOC_ISP_FE_OUT_V_SIZE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_clk_on_0 : 1;
        unsigned int force_clk_on_1 : 1;
        unsigned int reserved_0 : 1;
        unsigned int reserved_1 : 1;
        unsigned int force_clk_on_4 : 1;
        unsigned int force_clk_on_5 : 1;
        unsigned int reserved_2 : 1;
        unsigned int force_clk_on_7 : 1;
        unsigned int force_clk_on_8 : 1;
        unsigned int force_clk_on_9 : 1;
        unsigned int reserved_3 : 22;
    } reg;
} SOC_ISP_FE_FORCE_CLK_ON_CFG_UNION;
#endif
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_0_START (0)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_0_END (0)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_1_START (1)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_1_END (1)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_4_START (4)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_4_END (4)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_5_START (5)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_5_END (5)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_7_START (7)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_7_END (7)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_8_START (8)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_8_END (8)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_9_START (9)
#define SOC_ISP_FE_FORCE_CLK_ON_CFG_force_clk_on_9_END (9)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
