#ifndef __SOC_ISP_STREAM_ROUTER_INTERFACE_H__
#define __SOC_ISP_STREAM_ROUTER_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_ADDR(base) ((base) + (0x0))
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_ADDR(base) ((base) + (0x4))
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_GO_ADDR(base) ((base) + (0xC))
#define SOC_ISP_STREAM_ROUTER_PRESSURE_START_ADDR(base) ((base) + (0x10))
#define SOC_ISP_STREAM_ROUTER_PRESSURE_STOP_ADDR(base) ((base) + (0x14))
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_ADDR(base) ((base) + (0x18))
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_1_ADDR(base) ((base) + (0x1C))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_0_ADDR(base) ((base) + (0x20))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_0_ADDR(base) ((base) + (0x24))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_1_ADDR(base) ((base) + (0x28))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_1_ADDR(base) ((base) + (0x2c))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_2_ADDR(base) ((base) + (0x30))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_2_ADDR(base) ((base) + (0x34))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_6_ADDR(base) ((base) + (0x50))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_6_ADDR(base) ((base) + (0x54))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_7_ADDR(base) ((base) + (0x58))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_7_ADDR(base) ((base) + (0x5c))
#define SOC_ISP_STREAM_ROUTER_EOL_CNT_ADDR(base) ((base) + (0x60))
#define SOC_ISP_STREAM_ROUTER_DPCM_ADDR(base) ((base) + (0x78))
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_ADDR(base) ((base) + (0x7C))
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_ADDR(base) ((base) + (0x80))
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_3_ADDR(base) ((base) + (0x88))
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_CONVERT_ADDR(base) ((base) + (0x8C))
#define SOC_ISP_STREAM_ROUTER_PEAK_CTRL_ADDR(base) ((base) + (0x90))
#define SOC_ISP_STREAM_ROUTER_PEAK_STATUS_ADDR(base) ((base) + (0x94))
#define SOC_ISP_STREAM_ROUTER_BP_SOURCE_ADDR(base) ((base) + (0x98))
#define SOC_ISP_STREAM_ROUTER_DFS_CFG_ADDR(base) ((base) + (0x100))
#define SOC_ISP_STREAM_ROUTER_CROPV_ADDR(base,Range2) ((base) + (0x104+0x8*(Range2)))
#define SOC_ISP_STREAM_ROUTER_CROPH_ADDR(base,Range2) ((base) + (0x108+0x8*(Range2)))
#define SOC_ISP_STREAM_ROUTER_FORCE_CLK_ON_CFG_ADDR(base) ((base) + (0x120))
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CFG_ADDR(base,NumGen_Range) ((base) + (0x140+0x10*(NumGen_Range)))
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CTRL_ADDR(base,NumGen_Range) ((base) + (0x144+0x10*(NumGen_Range)))
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_DATA_ADDR(base,NumGen_Range) ((base) + (0x148+0x10*(NumGen_Range)))
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_CFG_ADDR(base) ((base) + (0x200))
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_POS_ADDR(base,NumExtract0_Range) ((base) + (0x204+0x4*(NumExtract0_Range)))
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_CFG_ADDR(base) ((base) + (0x290))
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_POS_ADDR(base,NumExtract1_Range) ((base) + (0x294+0x4*(NumExtract1_Range)))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_0_ADDR(base) ((base) + (0x320))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_1_ADDR(base) ((base) + (0x324))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_2_ADDR(base) ((base) + (0x328))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_6_ADDR(base) ((base) + (0x338))
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_7_ADDR(base) ((base) + (0x33c))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csia_data_type_0 : 6;
        unsigned int csia_virtual_ch_0 : 2;
        unsigned int csia_data_type_1 : 6;
        unsigned int csia_virtual_ch_1 : 2;
        unsigned int csia_data_type_2 : 6;
        unsigned int csia_virtual_ch_2 : 2;
        unsigned int csia_data_type_3 : 6;
        unsigned int csia_virtual_ch_3 : 2;
    } reg;
} SOC_ISP_STREAM_ROUTER_CSIFILTER_A_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_data_type_0_START (0)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_data_type_0_END (5)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_virtual_ch_0_START (6)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_virtual_ch_0_END (7)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_data_type_1_START (8)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_data_type_1_END (13)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_virtual_ch_1_START (14)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_virtual_ch_1_END (15)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_data_type_2_START (16)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_data_type_2_END (21)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_virtual_ch_2_START (22)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_virtual_ch_2_END (23)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_data_type_3_START (24)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_data_type_3_END (29)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_virtual_ch_3_START (30)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_A_csia_virtual_ch_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int csib_data_type_0 : 6;
        unsigned int csib_virtual_ch_0 : 2;
        unsigned int csib_data_type_1 : 6;
        unsigned int csib_virtual_ch_1 : 2;
        unsigned int csib_data_type_2 : 6;
        unsigned int csib_virtual_ch_2 : 2;
        unsigned int csib_data_type_3 : 6;
        unsigned int csib_virtual_ch_3 : 2;
    } reg;
} SOC_ISP_STREAM_ROUTER_CSIFILTER_B_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_data_type_0_START (0)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_data_type_0_END (5)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_virtual_ch_0_START (6)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_virtual_ch_0_END (7)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_data_type_1_START (8)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_data_type_1_END (13)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_virtual_ch_1_START (14)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_virtual_ch_1_END (15)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_data_type_2_START (16)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_data_type_2_END (21)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_virtual_ch_2_START (22)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_virtual_ch_2_END (23)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_data_type_3_START (24)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_data_type_3_END (29)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_virtual_ch_3_START (30)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_B_csib_virtual_ch_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int filter_go : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ISP_STREAM_ROUTER_CSIFILTER_GO_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_GO_filter_go_START (0)
#define SOC_ISP_STREAM_ROUTER_CSIFILTER_GO_filter_go_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pressure_threshold_start_a : 8;
        unsigned int pressure_threshold_start_b : 8;
        unsigned int reserved : 15;
        unsigned int pressure_enable : 1;
    } reg;
} SOC_ISP_STREAM_ROUTER_PRESSURE_START_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_PRESSURE_START_pressure_threshold_start_a_START (0)
#define SOC_ISP_STREAM_ROUTER_PRESSURE_START_pressure_threshold_start_a_END (7)
#define SOC_ISP_STREAM_ROUTER_PRESSURE_START_pressure_threshold_start_b_START (8)
#define SOC_ISP_STREAM_ROUTER_PRESSURE_START_pressure_threshold_start_b_END (15)
#define SOC_ISP_STREAM_ROUTER_PRESSURE_START_pressure_enable_START (31)
#define SOC_ISP_STREAM_ROUTER_PRESSURE_START_pressure_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int pressure_threshold_stop_a : 8;
        unsigned int pressure_threshold_stop_b : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_STREAM_ROUTER_PRESSURE_STOP_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_PRESSURE_STOP_pressure_threshold_stop_a_START (0)
#define SOC_ISP_STREAM_ROUTER_PRESSURE_STOP_pressure_threshold_stop_a_END (7)
#define SOC_ISP_STREAM_ROUTER_PRESSURE_STOP_pressure_threshold_stop_b_START (8)
#define SOC_ISP_STREAM_ROUTER_PRESSURE_STOP_pressure_threshold_stop_b_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int idr_input_stream_0 : 4;
        unsigned int idr_enable_0 : 1;
        unsigned int reserved_0 : 3;
        unsigned int idr_input_stream_1 : 4;
        unsigned int idr_enable_1 : 1;
        unsigned int reserved_1 : 3;
        unsigned int idr_input_stream_2 : 4;
        unsigned int idr_enable_2 : 1;
        unsigned int reserved_2 : 11;
    } reg;
} SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_idr_input_stream_0_START (0)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_idr_input_stream_0_END (3)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_idr_enable_0_START (4)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_idr_enable_0_END (4)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_idr_input_stream_1_START (8)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_idr_input_stream_1_END (11)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_idr_enable_1_START (12)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_idr_enable_1_END (12)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_idr_input_stream_2_START (16)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_idr_input_stream_2_END (19)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_idr_enable_2_START (20)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_0_idr_enable_2_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int idr_input_stream_6 : 4;
        unsigned int idr_enable_6 : 1;
        unsigned int reserved_1 : 3;
        unsigned int idr_input_stream_7 : 4;
        unsigned int idr_enable_7 : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_ISP_STREAM_ROUTER_ID_ROUTER_1_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_1_idr_input_stream_6_START (16)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_1_idr_input_stream_6_END (19)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_1_idr_enable_6_START (20)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_1_idr_enable_6_END (20)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_1_idr_input_stream_7_START (24)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_1_idr_input_stream_7_END (27)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_1_idr_enable_7_START (28)
#define SOC_ISP_STREAM_ROUTER_ID_ROUTER_1_idr_enable_7_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_num_lines_0 : 13;
        unsigned int reformat_pixel_reorder_0 : 3;
        unsigned int reformat_num_pixels_0 : 13;
        unsigned int reserved : 2;
        unsigned int reformat_enable_0 : 1;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_0_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_0_reformat_num_lines_0_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_0_reformat_num_lines_0_END (12)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_0_reformat_pixel_reorder_0_START (13)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_0_reformat_pixel_reorder_0_END (15)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_0_reformat_num_pixels_0_START (16)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_0_reformat_num_pixels_0_END (28)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_0_reformat_enable_0_START (31)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_0_reformat_enable_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_min_vertical_space_0 : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_0_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_0_reformat_min_vertical_space_0_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_0_reformat_min_vertical_space_0_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_num_lines_1 : 13;
        unsigned int reformat_pixel_reorder_1 : 3;
        unsigned int reformat_num_pixels_1 : 13;
        unsigned int reserved : 2;
        unsigned int reformat_enable_1 : 1;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_1_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_1_reformat_num_lines_1_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_1_reformat_num_lines_1_END (12)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_1_reformat_pixel_reorder_1_START (13)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_1_reformat_pixel_reorder_1_END (15)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_1_reformat_num_pixels_1_START (16)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_1_reformat_num_pixels_1_END (28)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_1_reformat_enable_1_START (31)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_1_reformat_enable_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_min_vertical_space_1 : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_1_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_1_reformat_min_vertical_space_1_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_1_reformat_min_vertical_space_1_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_num_lines_2 : 13;
        unsigned int reformat_pixel_reorder_2 : 3;
        unsigned int reformat_num_pixels_2 : 13;
        unsigned int reserved : 2;
        unsigned int reformat_enable_2 : 1;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_2_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_2_reformat_num_lines_2_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_2_reformat_num_lines_2_END (12)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_2_reformat_pixel_reorder_2_START (13)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_2_reformat_pixel_reorder_2_END (15)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_2_reformat_num_pixels_2_START (16)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_2_reformat_num_pixels_2_END (28)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_2_reformat_enable_2_START (31)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_2_reformat_enable_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_min_vertical_space_2 : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_2_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_2_reformat_min_vertical_space_2_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_2_reformat_min_vertical_space_2_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_num_lines_6 : 13;
        unsigned int reformat_pixel_reorder_6 : 3;
        unsigned int reformat_num_pixels_6 : 13;
        unsigned int reserved : 2;
        unsigned int reformat_enable_6 : 1;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_6_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_6_reformat_num_lines_6_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_6_reformat_num_lines_6_END (12)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_6_reformat_pixel_reorder_6_START (13)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_6_reformat_pixel_reorder_6_END (15)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_6_reformat_num_pixels_6_START (16)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_6_reformat_num_pixels_6_END (28)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_6_reformat_enable_6_START (31)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_6_reformat_enable_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_min_vertical_space_6 : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_6_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_6_reformat_min_vertical_space_6_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_6_reformat_min_vertical_space_6_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_num_lines_7 : 13;
        unsigned int reformat_pixel_reorder_7 : 3;
        unsigned int reformat_num_pixels_7 : 13;
        unsigned int reserved : 2;
        unsigned int reformat_enable_7 : 1;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_7_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_7_reformat_num_lines_7_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_7_reformat_num_lines_7_END (12)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_7_reformat_pixel_reorder_7_START (13)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_7_reformat_pixel_reorder_7_END (15)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_7_reformat_num_pixels_7_START (16)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_7_reformat_num_pixels_7_END (28)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_7_reformat_enable_7_START (31)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_7_reformat_enable_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_min_vertical_space_7 : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_7_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_7_reformat_min_vertical_space_7_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_MINSPACE_7_reformat_min_vertical_space_7_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int eol_num_lines_0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int eol_num_lines_1 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_STREAM_ROUTER_EOL_CNT_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_EOL_CNT_eol_num_lines_0_START (0)
#define SOC_ISP_STREAM_ROUTER_EOL_CNT_eol_num_lines_0_END (12)
#define SOC_ISP_STREAM_ROUTER_EOL_CNT_eol_num_lines_1_START (16)
#define SOC_ISP_STREAM_ROUTER_EOL_CNT_eol_num_lines_1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 14;
        unsigned int dpcm_enable_0 : 1;
        unsigned int dpcm_format_0 : 1;
        unsigned int reserved_1 : 14;
        unsigned int dpcm_enable_1 : 1;
        unsigned int dpcm_format_1 : 1;
    } reg;
} SOC_ISP_STREAM_ROUTER_DPCM_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_DPCM_dpcm_enable_0_START (14)
#define SOC_ISP_STREAM_ROUTER_DPCM_dpcm_enable_0_END (14)
#define SOC_ISP_STREAM_ROUTER_DPCM_dpcm_format_0_START (15)
#define SOC_ISP_STREAM_ROUTER_DPCM_dpcm_format_0_END (15)
#define SOC_ISP_STREAM_ROUTER_DPCM_dpcm_enable_1_START (30)
#define SOC_ISP_STREAM_ROUTER_DPCM_dpcm_enable_1_END (30)
#define SOC_ISP_STREAM_ROUTER_DPCM_dpcm_format_1_START (31)
#define SOC_ISP_STREAM_ROUTER_DPCM_dpcm_format_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpr_input_vp_0 : 4;
        unsigned int vpr_enable_0 : 1;
        unsigned int reserved_0 : 3;
        unsigned int vpr_input_vp_1 : 4;
        unsigned int vpr_enable_1 : 1;
        unsigned int reserved_1 : 11;
        unsigned int vpr_input_vp_3 : 4;
        unsigned int vpr_enable_3 : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_vpr_input_vp_0_START (0)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_vpr_input_vp_0_END (3)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_vpr_enable_0_START (4)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_vpr_enable_0_END (4)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_vpr_input_vp_1_START (8)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_vpr_input_vp_1_END (11)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_vpr_enable_1_START (12)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_vpr_enable_1_END (12)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_vpr_input_vp_3_START (24)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_vpr_input_vp_3_END (27)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_vpr_enable_3_START (28)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_0_vpr_enable_3_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpr_input_vp_4 : 4;
        unsigned int vpr_enable_4 : 1;
        unsigned int reserved_0 : 11;
        unsigned int vpr_input_vp_6 : 4;
        unsigned int vpr_enable_6 : 1;
        unsigned int reserved_1 : 3;
        unsigned int vpr_input_vp_7 : 4;
        unsigned int vpr_enable_7 : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_vpr_input_vp_4_START (0)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_vpr_input_vp_4_END (3)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_vpr_enable_4_START (4)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_vpr_enable_4_END (4)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_vpr_input_vp_6_START (16)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_vpr_input_vp_6_END (19)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_vpr_enable_6_START (20)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_vpr_enable_6_END (20)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_vpr_input_vp_7_START (24)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_vpr_input_vp_7_END (27)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_vpr_enable_7_START (28)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_1_vpr_enable_7_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 16;
        unsigned int vpr_input_vp_14 : 4;
        unsigned int vpr_enable_14 : 1;
        unsigned int reserved_1 : 3;
        unsigned int vpr_input_vp_15 : 4;
        unsigned int vpr_enable_15 : 1;
        unsigned int reserved_2 : 3;
    } reg;
} SOC_ISP_STREAM_ROUTER_VP_ROUTER_3_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_3_vpr_input_vp_14_START (16)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_3_vpr_input_vp_14_END (19)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_3_vpr_enable_14_START (20)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_3_vpr_enable_14_END (20)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_3_vpr_input_vp_15_START (24)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_3_vpr_input_vp_15_END (27)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_3_vpr_enable_15_START (28)
#define SOC_ISP_STREAM_ROUTER_VP_ROUTER_3_vpr_enable_15_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dma3_out : 1;
        unsigned int dma2_out : 1;
        unsigned int reserved_0: 1;
        unsigned int fe2_out : 1;
        unsigned int fe1_out : 1;
        unsigned int reserved_1: 27;
    } reg;
} SOC_ISP_STREAM_ROUTER_PIXFRAG_CONVERT_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_CONVERT_dma3_out_START (0)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_CONVERT_dma3_out_END (0)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_CONVERT_dma2_out_START (1)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_CONVERT_dma2_out_END (1)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_CONVERT_fe2_out_START (3)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_CONVERT_fe2_out_END (3)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_CONVERT_fe1_out_START (4)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_CONVERT_fe1_out_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peak_fifo_id : 3;
        unsigned int reserved_0 : 5;
        unsigned int peak_enable : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_ISP_STREAM_ROUTER_PEAK_CTRL_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_PEAK_CTRL_peak_fifo_id_START (0)
#define SOC_ISP_STREAM_ROUTER_PEAK_CTRL_peak_fifo_id_END (2)
#define SOC_ISP_STREAM_ROUTER_PEAK_CTRL_peak_enable_START (8)
#define SOC_ISP_STREAM_ROUTER_PEAK_CTRL_peak_enable_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peak_fifo_status : 12;
        unsigned int reserved : 17;
        unsigned int csi_afifo_status : 3;
    } reg;
} SOC_ISP_STREAM_ROUTER_PEAK_STATUS_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_PEAK_STATUS_peak_fifo_status_START (0)
#define SOC_ISP_STREAM_ROUTER_PEAK_STATUS_peak_fifo_status_END (11)
#define SOC_ISP_STREAM_ROUTER_PEAK_STATUS_csi_afifo_status_START (29)
#define SOC_ISP_STREAM_ROUTER_PEAK_STATUS_csi_afifo_status_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int bp_source_a : 2;
        unsigned int bp_source_b : 2;
        unsigned int reserved : 28;
    } reg;
} SOC_ISP_STREAM_ROUTER_BP_SOURCE_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_BP_SOURCE_bp_source_a_START (0)
#define SOC_ISP_STREAM_ROUTER_BP_SOURCE_bp_source_a_END (1)
#define SOC_ISP_STREAM_ROUTER_BP_SOURCE_bp_source_b_START (2)
#define SOC_ISP_STREAM_ROUTER_BP_SOURCE_bp_source_b_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dfs_granularity : 10;
        unsigned int dfs_trig_wait_before : 2;
        unsigned int dfs_enable : 11;
        unsigned int dfs_trig_wait_after : 9;
    } reg;
} SOC_ISP_STREAM_ROUTER_DFS_CFG_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_DFS_CFG_dfs_granularity_START (0)
#define SOC_ISP_STREAM_ROUTER_DFS_CFG_dfs_granularity_END (9)
#define SOC_ISP_STREAM_ROUTER_DFS_CFG_dfs_trig_wait_before_START (10)
#define SOC_ISP_STREAM_ROUTER_DFS_CFG_dfs_trig_wait_before_END (11)
#define SOC_ISP_STREAM_ROUTER_DFS_CFG_dfs_enable_START (12)
#define SOC_ISP_STREAM_ROUTER_DFS_CFG_dfs_enable_END (22)
#define SOC_ISP_STREAM_ROUTER_DFS_CFG_dfs_trig_wait_after_START (23)
#define SOC_ISP_STREAM_ROUTER_DFS_CFG_dfs_trig_wait_after_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int cropv_start_0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int cropv_end_0 : 13;
        unsigned int reserved_1 : 2;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_ISP_STREAM_ROUTER_CROPV_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_CROPV_cropv_start_0_START (0)
#define SOC_ISP_STREAM_ROUTER_CROPV_cropv_start_0_END (12)
#define SOC_ISP_STREAM_ROUTER_CROPV_cropv_end_0_START (16)
#define SOC_ISP_STREAM_ROUTER_CROPV_cropv_end_0_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int croph_start_0 : 12;
        unsigned int reserved_0 : 4;
        unsigned int croph_end_0 : 12;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_STREAM_ROUTER_CROPH_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_CROPH_croph_start_0_START (0)
#define SOC_ISP_STREAM_ROUTER_CROPH_croph_start_0_END (11)
#define SOC_ISP_STREAM_ROUTER_CROPH_croph_end_0_START (16)
#define SOC_ISP_STREAM_ROUTER_CROPH_croph_end_0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int force_clk_on : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_ISP_STREAM_ROUTER_FORCE_CLK_ON_CFG_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_FORCE_CLK_ON_CFG_force_clk_on_START (0)
#define SOC_ISP_STREAM_ROUTER_FORCE_CLK_ON_CFG_force_clk_on_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sensorgen_hsize : 12;
        unsigned int reserved_0 : 4;
        unsigned int sensorgen_vsize : 13;
        unsigned int reserved_1 : 1;
        unsigned int sensorgen_mode : 1;
        unsigned int sensorgen_start : 1;
    } reg;
} SOC_ISP_STREAM_ROUTER_SENSORGEN_CFG_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CFG_sensorgen_hsize_START (0)
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CFG_sensorgen_hsize_END (11)
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CFG_sensorgen_vsize_START (16)
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CFG_sensorgen_vsize_END (28)
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CFG_sensorgen_mode_START (30)
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CFG_sensorgen_mode_END (30)
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CFG_sensorgen_start_START (31)
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CFG_sensorgen_start_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sensorgen_dataen_pattern : 16;
        unsigned int sensorgen_vblanking : 8;
        unsigned int sensorgen_hblanking : 8;
    } reg;
} SOC_ISP_STREAM_ROUTER_SENSORGEN_CTRL_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CTRL_sensorgen_dataen_pattern_START (0)
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CTRL_sensorgen_dataen_pattern_END (15)
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CTRL_sensorgen_vblanking_START (16)
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CTRL_sensorgen_vblanking_END (23)
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CTRL_sensorgen_hblanking_START (24)
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_CTRL_sensorgen_hblanking_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sensorgen_data : 32;
    } reg;
} SOC_ISP_STREAM_ROUTER_SENSORGEN_DATA_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_DATA_sensorgen_data_START (0)
#define SOC_ISP_STREAM_ROUTER_SENSORGEN_DATA_sensorgen_data_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int extract0_vsize : 8;
        unsigned int extract0_hsize : 6;
        unsigned int reserved : 17;
        unsigned int extract0_mode : 1;
    } reg;
} SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_CFG_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_CFG_extract0_vsize_START (0)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_CFG_extract0_vsize_END (7)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_CFG_extract0_hsize_START (8)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_CFG_extract0_hsize_END (13)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_CFG_extract0_mode_START (31)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_CFG_extract0_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int extract0_vpos : 8;
        unsigned int extract0_hpos : 6;
        unsigned int reserved : 17;
        unsigned int extract0_pos_enable : 1;
    } reg;
} SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_POS_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_POS_extract0_vpos_START (0)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_POS_extract0_vpos_END (7)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_POS_extract0_hpos_START (8)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_POS_extract0_hpos_END (13)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_POS_extract0_pos_enable_START (31)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT0_POS_extract0_pos_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int extract1_vsize : 8;
        unsigned int extract1_hsize : 6;
        unsigned int reserved : 17;
        unsigned int extract1_mode : 1;
    } reg;
} SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_CFG_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_CFG_extract1_vsize_START (0)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_CFG_extract1_vsize_END (7)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_CFG_extract1_hsize_START (8)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_CFG_extract1_hsize_END (13)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_CFG_extract1_mode_START (31)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_CFG_extract1_mode_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int extract1_vpos : 8;
        unsigned int extract1_hpos : 6;
        unsigned int reserved : 17;
        unsigned int extract1_pos_enable : 1;
    } reg;
} SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_POS_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_POS_extract1_vpos_START (0)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_POS_extract1_vpos_END (7)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_POS_extract1_hpos_START (8)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_POS_extract1_hpos_END (13)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_POS_extract1_pos_enable_START (31)
#define SOC_ISP_STREAM_ROUTER_PIXFRAG_EXTRACT1_POS_extract1_pos_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_debug_0 : 32;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_0_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_0_reformat_debug_0_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_0_reformat_debug_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_debug_1 : 32;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_1_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_1_reformat_debug_1_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_1_reformat_debug_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_debug_2 : 32;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_2_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_2_reformat_debug_2_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_2_reformat_debug_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_debug_6 : 32;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_6_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_6_reformat_debug_6_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_6_reformat_debug_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reformat_debug_7 : 32;
    } reg;
} SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_7_UNION;
#endif
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_7_reformat_debug_7_START (0)
#define SOC_ISP_STREAM_ROUTER_REFORMAT_DEBUG_7_reformat_debug_7_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
