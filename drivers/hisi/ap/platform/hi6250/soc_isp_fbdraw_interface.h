#ifndef __SOC_ISP_FBDRAW_INTERFACE_H__
#define __SOC_ISP_FBDRAW_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_FBDRAW_FBD_CFG1_ADDR(base) ((base) + (0x0000))
#define SOC_ISP_FBDRAW_FBD_CFG2_ADDR(base) ((base) + (0x0004))
#define SOC_ISP_FBDRAW_FBD_STATUS_ADDR(base) ((base) + (0x0008))
#define SOC_ISP_FBDRAW_CROPLR_ADDR(base) ((base) + (0x0010))
#define SOC_ISP_FBDRAW_VP_RD_CFG_ADDR(base) ((base) + (0x14))
#define SOC_ISP_FBDRAW_VP_RD_LWG_ADDR(base) ((base) + (0x18))
#define SOC_ISP_FBDRAW_VP_RD_FHG_ADDR(base) ((base) + (0x1C))
#define SOC_ISP_FBDRAW_VP_RD_AXI_FS_ADDR(base) ((base) + (0x20))
#define SOC_ISP_FBDRAW_VP_RD_AXI_LINE_ADDR(base) ((base) + (0x24))
#define SOC_ISP_FBDRAW_VP_RD_PREFETCH_ADDR(base) ((base) + (0x28))
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
} SOC_ISP_FBDRAW_FBD_CFG1_UNION;
#endif
#define SOC_ISP_FBDRAW_FBD_CFG1_bypass_START (0)
#define SOC_ISP_FBDRAW_FBD_CFG1_bypass_END (0)
#define SOC_ISP_FBDRAW_FBD_CFG1_pix_size_START (2)
#define SOC_ISP_FBDRAW_FBD_CFG1_pix_size_END (3)
#define SOC_ISP_FBDRAW_FBD_CFG1_extra_budget_START (8)
#define SOC_ISP_FBDRAW_FBD_CFG1_extra_budget_END (13)
#define SOC_ISP_FBDRAW_FBD_CFG1_line_width_START (16)
#define SOC_ISP_FBDRAW_FBD_CFG1_line_width_END (28)
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
} SOC_ISP_FBDRAW_FBD_CFG2_UNION;
#endif
#define SOC_ISP_FBDRAW_FBD_CFG2_step_size_START (0)
#define SOC_ISP_FBDRAW_FBD_CFG2_step_size_END (6)
#define SOC_ISP_FBDRAW_FBD_CFG2_nb_rstmkr_START (8)
#define SOC_ISP_FBDRAW_FBD_CFG2_nb_rstmkr_END (13)
#define SOC_ISP_FBDRAW_FBD_CFG2_encoding_width_START (16)
#define SOC_ISP_FBDRAW_FBD_CFG2_encoding_width_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stream_error : 1;
        unsigned int rstmkr_error : 1;
        unsigned int replica_flag : 1;
        unsigned int reserved : 29;
    } reg;
} SOC_ISP_FBDRAW_FBD_STATUS_UNION;
#endif
#define SOC_ISP_FBDRAW_FBD_STATUS_stream_error_START (0)
#define SOC_ISP_FBDRAW_FBD_STATUS_stream_error_END (0)
#define SOC_ISP_FBDRAW_FBD_STATUS_rstmkr_error_START (1)
#define SOC_ISP_FBDRAW_FBD_STATUS_rstmkr_error_END (1)
#define SOC_ISP_FBDRAW_FBD_STATUS_replica_flag_START (2)
#define SOC_ISP_FBDRAW_FBD_STATUS_replica_flag_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cleft : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_FBDRAW_CROPLR_UNION;
#endif
#define SOC_ISP_FBDRAW_CROPLR_cleft_START (0)
#define SOC_ISP_FBDRAW_CROPLR_cleft_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_pixel_format : 3;
        unsigned int reserved_0 : 1;
        unsigned int vprd_pixel_expansion : 1;
        unsigned int reserved_1 : 27;
    } reg;
} SOC_ISP_FBDRAW_VP_RD_CFG_UNION;
#endif
#define SOC_ISP_FBDRAW_VP_RD_CFG_vprd_pixel_format_START (0)
#define SOC_ISP_FBDRAW_VP_RD_CFG_vprd_pixel_format_END (2)
#define SOC_ISP_FBDRAW_VP_RD_CFG_vprd_pixel_expansion_START (4)
#define SOC_ISP_FBDRAW_VP_RD_CFG_vprd_pixel_expansion_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_size : 13;
        unsigned int reserved : 19;
    } reg;
} SOC_ISP_FBDRAW_VP_RD_LWG_UNION;
#endif
#define SOC_ISP_FBDRAW_VP_RD_LWG_vprd_line_size_START (0)
#define SOC_ISP_FBDRAW_VP_RD_LWG_vprd_line_size_END (12)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_frame_size : 12;
        unsigned int reserved : 20;
    } reg;
} SOC_ISP_FBDRAW_VP_RD_FHG_UNION;
#endif
#define SOC_ISP_FBDRAW_VP_RD_FHG_vprd_frame_size_START (0)
#define SOC_ISP_FBDRAW_VP_RD_FHG_vprd_frame_size_END (11)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vprd_axi_frame_start : 28;
    } reg;
} SOC_ISP_FBDRAW_VP_RD_AXI_FS_UNION;
#endif
#define SOC_ISP_FBDRAW_VP_RD_AXI_FS_vprd_axi_frame_start_START (4)
#define SOC_ISP_FBDRAW_VP_RD_AXI_FS_vprd_axi_frame_start_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_stride : 10;
        unsigned int reserved : 22;
    } reg;
} SOC_ISP_FBDRAW_VP_RD_AXI_LINE_UNION;
#endif
#define SOC_ISP_FBDRAW_VP_RD_AXI_LINE_vprd_line_stride_START (0)
#define SOC_ISP_FBDRAW_VP_RD_AXI_LINE_vprd_line_stride_END (9)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_index_id0 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vprd_index_id1 : 7;
        unsigned int reserved_1 : 1;
        unsigned int vprd_stream_id : 6;
        unsigned int reserved_2 : 9;
        unsigned int vprd_prefetch_bypass : 1;
    } reg;
} SOC_ISP_FBDRAW_VP_RD_PREFETCH_UNION;
#endif
#define SOC_ISP_FBDRAW_VP_RD_PREFETCH_vprd_index_id0_START (0)
#define SOC_ISP_FBDRAW_VP_RD_PREFETCH_vprd_index_id0_END (6)
#define SOC_ISP_FBDRAW_VP_RD_PREFETCH_vprd_index_id1_START (8)
#define SOC_ISP_FBDRAW_VP_RD_PREFETCH_vprd_index_id1_END (14)
#define SOC_ISP_FBDRAW_VP_RD_PREFETCH_vprd_stream_id_START (16)
#define SOC_ISP_FBDRAW_VP_RD_PREFETCH_vprd_stream_id_END (21)
#define SOC_ISP_FBDRAW_VP_RD_PREFETCH_vprd_prefetch_bypass_START (31)
#define SOC_ISP_FBDRAW_VP_RD_PREFETCH_vprd_prefetch_bypass_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
