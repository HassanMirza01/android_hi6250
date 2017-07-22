#ifndef __SOC_ISP_CMDLST_INTERFACE_H__
#define __SOC_ISP_CMDLST_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_CMDLST_CMDLST_ID_ADDR(base) ((base) + (0x0))
#define SOC_ISP_CMDLST_CMDLST_VERSION_ADDR(base) ((base) + (0x4))
#define SOC_ISP_CMDLST_CMDLST_CFG_ADDR(base) ((base) + (0x20))
#define SOC_ISP_CMDLST_CMDLST_DEBUG_0_ADDR(base) ((base) + (0x40))
#define SOC_ISP_CMDLST_CMDLST_DEBUG_1_ADDR(base) ((base) + (0x44))
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_ADDR(base) ((base) + (0x48))
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_ADDR(base) ((base) + (0x4C))
#define SOC_ISP_CMDLST_CMDLST_DEBUG_4_ADDR(base) ((base) + (0x50))
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_ADDR_ADDR(base,CHANNEL_NBR_range) ((base) + (0x80+0x80*(CHANNEL_NBR_range)))
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_0_ADDR(base,CHANNEL_NBR_range) ((base) + (0x84+0x80*(CHANNEL_NBR_range)))
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_1_ADDR(base,CHANNEL_NBR_range) ((base) + (0x88+0x80*(CHANNEL_NBR_range)))
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_2_ADDR(base,CHANNEL_NBR_range) ((base) + (0x8C+0x80*(CHANNEL_NBR_range)))
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_3_ADDR(base,CHANNEL_NBR_range) ((base) + (0x90+0x80*(CHANNEL_NBR_range)))
#define SOC_ISP_CMDLST_CMDLST_SW_BRANCH_ADDR(base,CHANNEL_NBR_range) ((base) + (0xA0+0x80*(CHANNEL_NBR_range)))
#define SOC_ISP_CMDLST_CMDLST_LAST_EXEC_RD_DATA_3_ADDR(base,CHANNEL_NBR_range) ((base) + (0xA4+0x80*(CHANNEL_NBR_range)))
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_ADDR_ADDR(base,CHANNEL_NBR_range) ((base) + (0xC0+0x80*(CHANNEL_NBR_range)))
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_0_ADDR(base,CHANNEL_NBR_range) ((base) + (0xC4+0x80*(CHANNEL_NBR_range)))
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_1_ADDR(base,CHANNEL_NBR_range) ((base) + (0xC8+0x80*(CHANNEL_NBR_range)))
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_2_ADDR(base,CHANNEL_NBR_range) ((base) + (0xCC+0x80*(CHANNEL_NBR_range)))
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_3_ADDR(base,CHANNEL_NBR_range) ((base) + (0xD0+0x80*(CHANNEL_NBR_range)))
#define SOC_ISP_CMDLST_CMDLST_CHANNEL_DEBUG_ADDR(base,CHANNEL_NBR_range) ((base) + (0xE0+0x80*(CHANNEL_NBR_range)))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_id : 32;
    } reg;
} SOC_ISP_CMDLST_CMDLST_ID_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_ID_ip_id_START (0)
#define SOC_ISP_CMDLST_CMDLST_ID_ip_id_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int ip_version : 32;
    } reg;
} SOC_ISP_CMDLST_CMDLST_VERSION_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_VERSION_ip_version_START (0)
#define SOC_ISP_CMDLST_CMDLST_VERSION_ip_version_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int prefetch : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_CMDLST_CMDLST_CFG_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_CFG_prefetch_START (0)
#define SOC_ISP_CMDLST_CMDLST_CFG_prefetch_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_fifo_nb_elem : 3;
        unsigned int reserved_0 : 1;
        unsigned int dbg_lb_master_fsm : 3;
        unsigned int reserved_1 : 1;
        unsigned int dbg_vp_wr_fsm : 2;
        unsigned int reserved_2 : 2;
        unsigned int dbg_arb_fsm : 1;
        unsigned int reserved_3 : 3;
        unsigned int dbg_sw_start : 8;
        unsigned int dbg_hw_start : 8;
    } reg;
} SOC_ISP_CMDLST_CMDLST_DEBUG_0_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_DEBUG_0_dbg_fifo_nb_elem_START (0)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_0_dbg_fifo_nb_elem_END (2)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_0_dbg_lb_master_fsm_START (4)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_0_dbg_lb_master_fsm_END (6)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_0_dbg_vp_wr_fsm_START (8)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_0_dbg_vp_wr_fsm_END (9)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_0_dbg_arb_fsm_START (12)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_0_dbg_arb_fsm_END (12)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_0_dbg_sw_start_START (16)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_0_dbg_sw_start_END (23)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_0_dbg_hw_start_START (24)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_0_dbg_hw_start_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_sw_start : 16;
        unsigned int dbg_hw_start : 16;
    } reg;
} SOC_ISP_CMDLST_CMDLST_DEBUG_1_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_DEBUG_1_dbg_sw_start_START (0)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_1_dbg_sw_start_END (15)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_1_dbg_hw_start_START (16)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_1_dbg_hw_start_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_fsm_ch_0 : 3;
        unsigned int reserved_0 : 1;
        unsigned int dbg_fsm_ch_1 : 3;
        unsigned int reserved_1 : 1;
        unsigned int dbg_fsm_ch_2 : 3;
        unsigned int reserved_2 : 1;
        unsigned int dbg_fsm_ch_3 : 3;
        unsigned int reserved_3 : 1;
        unsigned int dbg_fsm_ch_4 : 3;
        unsigned int reserved_4 : 1;
        unsigned int dbg_fsm_ch_5 : 3;
        unsigned int reserved_5 : 1;
        unsigned int dbg_fsm_ch_6 : 3;
        unsigned int reserved_6 : 1;
        unsigned int dbg_fsm_ch_7 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_ISP_CMDLST_CMDLST_DEBUG_2_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_0_START (0)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_0_END (2)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_1_START (4)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_1_END (6)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_2_START (8)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_2_END (10)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_3_START (12)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_3_END (14)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_4_START (16)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_4_END (18)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_5_START (20)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_5_END (22)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_6_START (24)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_6_END (26)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_7_START (28)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_2_dbg_fsm_ch_7_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_fsm_ch_8 : 3;
        unsigned int reserved_0 : 1;
        unsigned int dbg_fsm_ch_9 : 3;
        unsigned int reserved_1 : 1;
        unsigned int dbg_fsm_ch_10 : 3;
        unsigned int reserved_2 : 1;
        unsigned int dbg_fsm_ch_11 : 3;
        unsigned int reserved_3 : 1;
        unsigned int dbg_fsm_ch_12 : 3;
        unsigned int reserved_4 : 1;
        unsigned int dbg_fsm_ch_13 : 3;
        unsigned int reserved_5 : 1;
        unsigned int dbg_fsm_ch_14 : 3;
        unsigned int reserved_6 : 1;
        unsigned int dbg_fsm_ch_15 : 3;
        unsigned int reserved_7 : 1;
    } reg;
} SOC_ISP_CMDLST_CMDLST_DEBUG_3_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_8_START (0)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_8_END (2)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_9_START (4)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_9_END (6)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_10_START (8)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_10_END (10)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_11_START (12)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_11_END (14)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_12_START (16)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_12_END (18)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_13_START (20)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_13_END (22)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_14_START (24)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_14_END (26)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_15_START (28)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_3_dbg_fsm_ch_15_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int last_lb_addr : 21;
        unsigned int reserved : 11;
    } reg;
} SOC_ISP_CMDLST_CMDLST_DEBUG_4_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_DEBUG_4_last_lb_addr_START (0)
#define SOC_ISP_CMDLST_CMDLST_DEBUG_4_last_lb_addr_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int sw_cvdr_rd_address : 19;
        unsigned int reserved_1 : 3;
        unsigned int sw_cvdr_rd_size : 2;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_ADDR_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_ADDR_sw_cvdr_rd_address_START (2)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_ADDR_sw_cvdr_rd_address_END (20)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_ADDR_sw_cvdr_rd_size_START (24)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_ADDR_sw_cvdr_rd_size_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_pixel_format : 4;
        unsigned int vprd_pixel_expansion : 1;
        unsigned int vprd_allocated_du : 5;
        unsigned int vprd_access_limiter : 4;
        unsigned int reserved : 1;
        unsigned int vprd_last_page : 17;
    } reg;
} SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_0_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_0_vprd_pixel_format_START (0)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_0_vprd_pixel_format_END (3)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_0_vprd_pixel_expansion_START (4)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_0_vprd_pixel_expansion_END (4)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_0_vprd_allocated_du_START (5)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_0_vprd_allocated_du_END (9)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_0_vprd_access_limiter_START (10)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_0_vprd_access_limiter_END (13)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_0_vprd_last_page_START (15)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_0_vprd_last_page_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_size : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_horizontal_blanking : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_1_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_1_vprd_line_size_START (0)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_1_vprd_line_size_END (12)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_1_vprd_horizontal_blanking_START (16)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_1_vprd_horizontal_blanking_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_frame_size : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_vertical_blanking : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_2_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_2_vprd_frame_size_START (0)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_2_vprd_frame_size_END (12)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_2_vprd_vertical_blanking_START (16)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_2_vprd_vertical_blanking_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vprd_axi_frame_start_0 : 28;
    } reg;
} SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_3_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_3_vprd_axi_frame_start_0_START (4)
#define SOC_ISP_CMDLST_CMDLST_SW_CVDR_RD_DATA_3_vprd_axi_frame_start_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int branching : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_CMDLST_CMDLST_SW_BRANCH_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_SW_BRANCH_branching_START (0)
#define SOC_ISP_CMDLST_CMDLST_SW_BRANCH_branching_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shadowed_rd_data_3 : 32;
    } reg;
} SOC_ISP_CMDLST_CMDLST_LAST_EXEC_RD_DATA_3_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_LAST_EXEC_RD_DATA_3_shadowed_rd_data_3_START (0)
#define SOC_ISP_CMDLST_CMDLST_LAST_EXEC_RD_DATA_3_shadowed_rd_data_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 2;
        unsigned int hw_cvdr_rd_address : 19;
        unsigned int reserved_1 : 3;
        unsigned int hw_cvdr_rd_size : 2;
        unsigned int reserved_2 : 6;
    } reg;
} SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_ADDR_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_ADDR_hw_cvdr_rd_address_START (2)
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_ADDR_hw_cvdr_rd_address_END (20)
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_ADDR_hw_cvdr_rd_size_START (24)
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_ADDR_hw_cvdr_rd_size_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hw_cvdr_rd_data_0 : 32;
    } reg;
} SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_0_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_0_hw_cvdr_rd_data_0_START (0)
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_0_hw_cvdr_rd_data_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hw_cvdr_rd_data_1 : 32;
    } reg;
} SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_1_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_1_hw_cvdr_rd_data_1_START (0)
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_1_hw_cvdr_rd_data_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hw_cvdr_rd_data_2 : 32;
    } reg;
} SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_2_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_2_hw_cvdr_rd_data_2_START (0)
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_2_hw_cvdr_rd_data_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int hw_cvdr_rd_data_3 : 32;
    } reg;
} SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_3_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_3_hw_cvdr_rd_data_3_START (0)
#define SOC_ISP_CMDLST_CMDLST_HW_CVDR_RD_DATA_3_hw_cvdr_rd_data_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dbg_fsm_ch : 3;
        unsigned int reserved_0 : 1;
        unsigned int dbg_sw_start : 1;
        unsigned int reserved_1 : 3;
        unsigned int dbg_hw_start : 1;
        unsigned int reserved_2 : 23;
    } reg;
} SOC_ISP_CMDLST_CMDLST_CHANNEL_DEBUG_UNION;
#endif
#define SOC_ISP_CMDLST_CMDLST_CHANNEL_DEBUG_dbg_fsm_ch_START (0)
#define SOC_ISP_CMDLST_CMDLST_CHANNEL_DEBUG_dbg_fsm_ch_END (2)
#define SOC_ISP_CMDLST_CMDLST_CHANNEL_DEBUG_dbg_sw_start_START (4)
#define SOC_ISP_CMDLST_CMDLST_CHANNEL_DEBUG_dbg_sw_start_END (4)
#define SOC_ISP_CMDLST_CMDLST_CHANNEL_DEBUG_dbg_hw_start_START (8)
#define SOC_ISP_CMDLST_CMDLST_CHANNEL_DEBUG_dbg_hw_start_END (8)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
