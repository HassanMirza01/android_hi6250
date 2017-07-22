#ifndef __SOC_CCI500_INTERFACE_H__
#define __SOC_CCI500_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_CCI500_CTRL_OVR_ADDR(base) ((base) + (0x00000))
#define SOC_CCI500_SECR_ACC_ADDR(base) ((base) + (0x00008))
#define SOC_CCI500_STATUS_ADDR(base) ((base) + (0x0000C))
#define SOC_CCI500_IMPR_ERR_ADDR(base) ((base) + (0x00010))
#define SOC_CCI500_QOS_THRESHOLD_ADDR(base) ((base) + (0x00014))
#define SOC_CCI500_PMU_CTRL_ADDR(base) ((base) + (0x00100))
#define SOC_CCI500_DEBUG_CTRL_ADDR(base) ((base) + (0x00104))
#define SOC_CCI500_PERIPHERAL_ID4_ADDR(base) ((base) + (0x00FD0))
#define SOC_CCI500_PERIPHERAL_ID5_ADDR(base) ((base) + (0x00FD4))
#define SOC_CCI500_PERIPHERAL_ID6_ADDR(base) ((base) + (0x00FD8))
#define SOC_CCI500_PERIPHERAL_ID7_ADDR(base) ((base) + (0x00FDC))
#define SOC_CCI500_PERIPHERAL_ID0_ADDR(base) ((base) + (0x00FE0))
#define SOC_CCI500_PERIPHERAL_ID1_ADDR(base) ((base) + (0x00FE4))
#define SOC_CCI500_PERIPHERAL_ID2_ADDR(base) ((base) + (0x00FE8))
#define SOC_CCI500_PERIPHERAL_ID3_ADDR(base) ((base) + (0x00FEC))
#define SOC_CCI500_COMPONENT_ID0_ADDR(base) ((base) + (0x00FF0))
#define SOC_CCI500_COMPONENT_ID1_ADDR(base) ((base) + (0x00FF4))
#define SOC_CCI500_COMPONENT_ID2_ADDR(base) ((base) + (0x00FF8))
#define SOC_CCI500_COMPONENT_ID3_ADDR(base) ((base) + (0x00FFC))
#define SOC_CCI500_SNOOP_CTRL_S0_ADDR(base) ((base) + (0x01000))
#define SOC_CCI500_SHARE_OVR_S0_ADDR(base) ((base) + (0x01004))
#define SOC_CCI500_ARQOS_OVR_S0_ADDR(base) ((base) + (0x01100))
#define SOC_CCI500_AWQOS_OVR_S0_ADDR(base) ((base) + (0x01104))
#define SOC_CCI500_QOS_MAX_OT_S0_ADDR(base) ((base) + (0x01110))
#define SOC_CCI500_SNOOP_CTRL_S1_ADDR(base) ((base) + (0x02000))
#define SOC_CCI500_SHARE_OVR_S1_ADDR(base) ((base) + (0x02004))
#define SOC_CCI500_ARQOS_OVR_S1_ADDR(base) ((base) + (0x02100))
#define SOC_CCI500_AWQOS_OVR_S1_ADDR(base) ((base) + (0x02104))
#define SOC_CCI500_QOS_MAX_OT_31_ADDR(base) ((base) + (0x02110))
#define SOC_CCI500_EVNT_SEL_0_ADDR(base) ((base) + (0x10000))
#define SOC_CCI500_ECNT_DATA_0_ADDR(base) ((base) + (0x10004))
#define SOC_CCI500_ECNT_CTRL_0_ADDR(base) ((base) + (0x10008))
#define SOC_CCI500_ECNT_CLR_OVFL_0_ADDR(base) ((base) + (0x1000C))
#define SOC_CCI500_EVNT_SEL_1_ADDR(base) ((base) + (0x20000))
#define SOC_CCI500_ECNT_DATA_1_ADDR(base) ((base) + (0x20004))
#define SOC_CCI500_ECNT_CTRL_1_ADDR(base) ((base) + (0x20008))
#define SOC_CCI500_ECNT_CLR_OVFL_1_ADDR(base) ((base) + (0x2000C))
#define SOC_CCI500_EVNT_SEL_2_ADDR(base) ((base) + (0x30000))
#define SOC_CCI500_ECNT_DATA_2_ADDR(base) ((base) + (0x30004))
#define SOC_CCI500_ECNT_CTRL_2_ADDR(base) ((base) + (0x30008))
#define SOC_CCI500_ECNT_CLR_OVFL_2_ADDR(base) ((base) + (0x3000C))
#define SOC_CCI500_EVNT_SEL_3_ADDR(base) ((base) + (0x40000))
#define SOC_CCI500_ECNT_DATA_3_ADDR(base) ((base) + (0x40004))
#define SOC_CCI500_ECNT_CTRL_3_ADDR(base) ((base) + (0x40008))
#define SOC_CCI500_ECNT_CLR_OVFL_3_ADDR(base) ((base) + (0x4000C))
#define SOC_CCI500_EVNT_SEL_4_ADDR(base) ((base) + (0x50000))
#define SOC_CCI500_ECNT_DATA_4_ADDR(base) ((base) + (0x50004))
#define SOC_CCI500_ECNT_CTRL_4_ADDR(base) ((base) + (0x50008))
#define SOC_CCI500_ECNT_CLR_OVFL_4_ADDR(base) ((base) + (0x5000C))
#define SOC_CCI500_EVNT_SEL_5_ADDR(base) ((base) + (0x60000))
#define SOC_CCI500_ECNT_DATA_5_ADDR(base) ((base) + (0x60004))
#define SOC_CCI500_ECNT_CTRL_5_ADDR(base) ((base) + (0x60008))
#define SOC_CCI500_ECNT_CLR_OVFL_5_ADDR(base) ((base) + (0x6000C))
#define SOC_CCI500_EVNT_SEL_6_ADDR(base) ((base) + (0x70000))
#define SOC_CCI500_ECNT_DATA_6_ADDR(base) ((base) + (0x70004))
#define SOC_CCI500_ECNT_CTRL_6_ADDR(base) ((base) + (0x70008))
#define SOC_CCI500_ECNT_CLR_OVFL_6_ADDR(base) ((base) + (0x7000C))
#define SOC_CCI500_EVNT_SEL_7_ADDR(base) ((base) + (0x80000))
#define SOC_CCI500_ECNT_DATA_7_ADDR(base) ((base) + (0x80004))
#define SOC_CCI500_ECNT_CTRL_7_ADDR(base) ((base) + (0x80008))
#define SOC_CCI500_ECNT_CLR_OVFL_7_ADDR(base) ((base) + (0x8000C))
#define SOC_CCI500_SLAVE_DEBUG_0_ADDR(base) ((base) + (0x90000))
#define SOC_CCI500_SLAVE_DEBUG_1_ADDR(base) ((base) + (0x90004))
#define SOC_CCI500_MASTER_DEBUG_0_ADDR(base) ((base) + (0x90100))
#define SOC_CCI500_MASTER_DEBUG_1_ADDR(base) ((base) + (0x90104))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int snoop_disable : 1;
        unsigned int dvm_message_disable : 1;
        unsigned int disable_snoop_filter : 1;
        unsigned int disable_clock_gating : 1;
        unsigned int reserved : 28;
    } reg;
} SOC_CCI500_CTRL_OVR_UNION;
#endif
#define SOC_CCI500_CTRL_OVR_snoop_disable_START (0)
#define SOC_CCI500_CTRL_OVR_snoop_disable_END (0)
#define SOC_CCI500_CTRL_OVR_dvm_message_disable_START (1)
#define SOC_CCI500_CTRL_OVR_dvm_message_disable_END (1)
#define SOC_CCI500_CTRL_OVR_disable_snoop_filter_START (2)
#define SOC_CCI500_CTRL_OVR_disable_snoop_filter_END (2)
#define SOC_CCI500_CTRL_OVR_disable_clock_gating_START (3)
#define SOC_CCI500_CTRL_OVR_disable_clock_gating_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int non_secure_register_access_override : 1;
        unsigned int debug_monitor_security_override : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_CCI500_SECR_ACC_UNION;
#endif
#define SOC_CCI500_SECR_ACC_non_secure_register_access_override_START (0)
#define SOC_CCI500_SECR_ACC_non_secure_register_access_override_END (0)
#define SOC_CCI500_SECR_ACC_debug_monitor_security_override_START (1)
#define SOC_CCI500_SECR_ACC_debug_monitor_security_override_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int change_pending : 1;
        unsigned int sf_ram_initialization : 1;
        unsigned int sf_ram_state : 3;
        unsigned int sf_ram_state_request : 3;
        unsigned int sf_ram_state_change_pending : 1;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_STATUS_UNION;
#endif
#define SOC_CCI500_STATUS_change_pending_START (0)
#define SOC_CCI500_STATUS_change_pending_END (0)
#define SOC_CCI500_STATUS_sf_ram_initialization_START (1)
#define SOC_CCI500_STATUS_sf_ram_initialization_END (1)
#define SOC_CCI500_STATUS_sf_ram_state_START (2)
#define SOC_CCI500_STATUS_sf_ram_state_END (4)
#define SOC_CCI500_STATUS_sf_ram_state_request_START (5)
#define SOC_CCI500_STATUS_sf_ram_state_request_END (7)
#define SOC_CCI500_STATUS_sf_ram_state_change_pending_START (8)
#define SOC_CCI500_STATUS_sf_ram_state_change_pending_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int imprecise_error_indicator_mi0 : 1;
        unsigned int imprecise_error_indicator_mi1 : 1;
        unsigned int imprecise_error_indicator_mi2 : 1;
        unsigned int imprecise_error_indicator_mi3 : 1;
        unsigned int imprecise_error_indicator_mi4 : 1;
        unsigned int imprecise_error_indicator_mi5 : 1;
        unsigned int reserved_0 : 10;
        unsigned int imprecise_error_indicator_si0 : 1;
        unsigned int imprecise_error_indicator_si1 : 1;
        unsigned int imprecise_error_indicator_si2 : 1;
        unsigned int imprecise_error_indicator_si3 : 1;
        unsigned int imprecise_error_indicator_si4 : 1;
        unsigned int imprecise_error_indicator_si5 : 1;
        unsigned int imprecise_error_indicator_si6 : 1;
        unsigned int reserved_1 : 9;
    } reg;
} SOC_CCI500_IMPR_ERR_UNION;
#endif
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi0_START (0)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi0_END (0)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi1_START (1)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi1_END (1)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi2_START (2)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi2_END (2)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi3_START (3)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi3_END (3)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi4_START (4)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi4_END (4)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi5_START (5)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_mi5_END (5)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si0_START (16)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si0_END (16)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si1_START (17)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si1_END (17)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si2_START (18)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si2_END (18)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si3_START (19)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si3_END (19)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si4_START (20)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si4_END (20)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si5_START (21)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si5_END (21)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si6_START (22)
#define SOC_CCI500_IMPR_ERR_imprecise_error_indicator_si6_END (22)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int r_qv_thresh_high : 4;
        unsigned int reserved_0 : 12;
        unsigned int w_qv_thresh_high : 4;
        unsigned int reserved_1 : 12;
    } reg;
} SOC_CCI500_QOS_THRESHOLD_UNION;
#endif
#define SOC_CCI500_QOS_THRESHOLD_r_qv_thresh_high_START (0)
#define SOC_CCI500_QOS_THRESHOLD_r_qv_thresh_high_END (3)
#define SOC_CCI500_QOS_THRESHOLD_w_qv_thresh_high_START (16)
#define SOC_CCI500_QOS_THRESHOLD_w_qv_thresh_high_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int CEN : 1;
        unsigned int RST : 1;
        unsigned int reserved_0 : 2;
        unsigned int EX : 1;
        unsigned int reserved_1 : 6;
        unsigned int number_of_counters : 5;
        unsigned int reserved_2 : 16;
    } reg;
} SOC_CCI500_PMU_CTRL_UNION;
#endif
#define SOC_CCI500_PMU_CTRL_CEN_START (0)
#define SOC_CCI500_PMU_CTRL_CEN_END (0)
#define SOC_CCI500_PMU_CTRL_RST_START (1)
#define SOC_CCI500_PMU_CTRL_RST_END (1)
#define SOC_CCI500_PMU_CTRL_EX_START (4)
#define SOC_CCI500_PMU_CTRL_EX_END (4)
#define SOC_CCI500_PMU_CTRL_number_of_counters_START (11)
#define SOC_CCI500_PMU_CTRL_number_of_counters_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int enable_interface_monitors : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_DEBUG_CTRL_UNION;
#endif
#define SOC_CCI500_DEBUG_CTRL_enable_interface_monitors_START (0)
#define SOC_CCI500_DEBUG_CTRL_enable_interface_monitors_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peri_id4_1 : 4;
        unsigned int peri_id4_2 : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID4_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID4_peri_id4_1_START (0)
#define SOC_CCI500_PERIPHERAL_ID4_peri_id4_1_END (3)
#define SOC_CCI500_PERIPHERAL_ID4_peri_id4_2_START (4)
#define SOC_CCI500_PERIPHERAL_ID4_peri_id4_2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peri_id5 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID5_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID5_peri_id5_START (0)
#define SOC_CCI500_PERIPHERAL_ID5_peri_id5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peri_id6 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID6_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID6_peri_id6_START (0)
#define SOC_CCI500_PERIPHERAL_ID6_peri_id6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peri_id7 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID7_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID7_peri_id7_START (0)
#define SOC_CCI500_PERIPHERAL_ID7_peri_id7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peri_id0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID0_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID0_peri_id0_START (0)
#define SOC_CCI500_PERIPHERAL_ID0_peri_id0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int peri_id1_num : 4;
        unsigned int jep106_id_l : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID1_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID1_peri_id1_num_START (0)
#define SOC_CCI500_PERIPHERAL_ID1_peri_id1_num_END (3)
#define SOC_CCI500_PERIPHERAL_ID1_jep106_id_l_START (4)
#define SOC_CCI500_PERIPHERAL_ID1_jep106_id_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int jep106_id_h : 3;
        unsigned int manu_id_code : 1;
        unsigned int ccr_rev : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID2_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID2_jep106_id_h_START (0)
#define SOC_CCI500_PERIPHERAL_ID2_jep106_id_h_END (2)
#define SOC_CCI500_PERIPHERAL_ID2_manu_id_code_START (3)
#define SOC_CCI500_PERIPHERAL_ID2_manu_id_code_END (3)
#define SOC_CCI500_PERIPHERAL_ID2_ccr_rev_START (4)
#define SOC_CCI500_PERIPHERAL_ID2_ccr_rev_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mod_num : 4;
        unsigned int eco_num : 4;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_PERIPHERAL_ID3_UNION;
#endif
#define SOC_CCI500_PERIPHERAL_ID3_mod_num_START (0)
#define SOC_CCI500_PERIPHERAL_ID3_mod_num_END (3)
#define SOC_CCI500_PERIPHERAL_ID3_eco_num_START (4)
#define SOC_CCI500_PERIPHERAL_ID3_eco_num_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int component_id0 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_COMPONENT_ID0_UNION;
#endif
#define SOC_CCI500_COMPONENT_ID0_component_id0_START (0)
#define SOC_CCI500_COMPONENT_ID0_component_id0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int component_id1 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_COMPONENT_ID1_UNION;
#endif
#define SOC_CCI500_COMPONENT_ID1_component_id1_START (0)
#define SOC_CCI500_COMPONENT_ID1_component_id1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int component_id2 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_COMPONENT_ID2_UNION;
#endif
#define SOC_CCI500_COMPONENT_ID2_component_id2_START (0)
#define SOC_CCI500_COMPONENT_ID2_component_id2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int component_id3 : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_COMPONENT_ID3_UNION;
#endif
#define SOC_CCI500_COMPONENT_ID3_component_id3_START (0)
#define SOC_CCI500_COMPONENT_ID3_component_id3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int snoop_en : 1;
        unsigned int dvm_en : 1;
        unsigned int reserved : 28;
        unsigned int snoop_support : 1;
        unsigned int dvm_support : 1;
    } reg;
} SOC_CCI500_SNOOP_CTRL_S0_UNION;
#endif
#define SOC_CCI500_SNOOP_CTRL_S0_snoop_en_START (0)
#define SOC_CCI500_SNOOP_CTRL_S0_snoop_en_END (0)
#define SOC_CCI500_SNOOP_CTRL_S0_dvm_en_START (1)
#define SOC_CCI500_SNOOP_CTRL_S0_dvm_en_END (1)
#define SOC_CCI500_SNOOP_CTRL_S0_snoop_support_START (30)
#define SOC_CCI500_SNOOP_CTRL_S0_snoop_support_END (30)
#define SOC_CCI500_SNOOP_CTRL_S0_dvm_support_START (31)
#define SOC_CCI500_SNOOP_CTRL_S0_dvm_support_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shareable_override : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CCI500_SHARE_OVR_S0_UNION;
#endif
#define SOC_CCI500_SHARE_OVR_S0_shareable_override_START (0)
#define SOC_CCI500_SHARE_OVR_S0_shareable_override_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qv_max : 4;
        unsigned int qv_min : 4;
        unsigned int reserved_0 : 8;
        unsigned int bandwidth_allocation : 4;
        unsigned int reserved_1 : 4;
        unsigned int excess_bytes_per_qv : 3;
        unsigned int reserved_2 : 4;
        unsigned int reg_enable : 1;
    } reg;
} SOC_CCI500_ARQOS_OVR_S0_UNION;
#endif
#define SOC_CCI500_ARQOS_OVR_S0_qv_max_START (0)
#define SOC_CCI500_ARQOS_OVR_S0_qv_max_END (3)
#define SOC_CCI500_ARQOS_OVR_S0_qv_min_START (4)
#define SOC_CCI500_ARQOS_OVR_S0_qv_min_END (7)
#define SOC_CCI500_ARQOS_OVR_S0_bandwidth_allocation_START (16)
#define SOC_CCI500_ARQOS_OVR_S0_bandwidth_allocation_END (19)
#define SOC_CCI500_ARQOS_OVR_S0_excess_bytes_per_qv_START (24)
#define SOC_CCI500_ARQOS_OVR_S0_excess_bytes_per_qv_END (26)
#define SOC_CCI500_ARQOS_OVR_S0_reg_enable_START (31)
#define SOC_CCI500_ARQOS_OVR_S0_reg_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qv_max : 4;
        unsigned int qv_min : 4;
        unsigned int reserved_0 : 8;
        unsigned int bandwidth_allocation : 4;
        unsigned int reserved_1 : 4;
        unsigned int excess_bytes_per_qv : 3;
        unsigned int reserved_2 : 4;
        unsigned int reg_enable : 1;
    } reg;
} SOC_CCI500_AWQOS_OVR_S0_UNION;
#endif
#define SOC_CCI500_AWQOS_OVR_S0_qv_max_START (0)
#define SOC_CCI500_AWQOS_OVR_S0_qv_max_END (3)
#define SOC_CCI500_AWQOS_OVR_S0_qv_min_START (4)
#define SOC_CCI500_AWQOS_OVR_S0_qv_min_END (7)
#define SOC_CCI500_AWQOS_OVR_S0_bandwidth_allocation_START (16)
#define SOC_CCI500_AWQOS_OVR_S0_bandwidth_allocation_END (19)
#define SOC_CCI500_AWQOS_OVR_S0_excess_bytes_per_qv_START (24)
#define SOC_CCI500_AWQOS_OVR_S0_excess_bytes_per_qv_END (26)
#define SOC_CCI500_AWQOS_OVR_S0_reg_enable_START (31)
#define SOC_CCI500_AWQOS_OVR_S0_reg_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int max_ot : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_QOS_MAX_OT_S0_UNION;
#endif
#define SOC_CCI500_QOS_MAX_OT_S0_max_ot_START (0)
#define SOC_CCI500_QOS_MAX_OT_S0_max_ot_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int snoop_en : 1;
        unsigned int dvm_en : 1;
        unsigned int reserved : 28;
        unsigned int snoop_support : 1;
        unsigned int dvm_support : 1;
    } reg;
} SOC_CCI500_SNOOP_CTRL_S1_UNION;
#endif
#define SOC_CCI500_SNOOP_CTRL_S1_snoop_en_START (0)
#define SOC_CCI500_SNOOP_CTRL_S1_snoop_en_END (0)
#define SOC_CCI500_SNOOP_CTRL_S1_dvm_en_START (1)
#define SOC_CCI500_SNOOP_CTRL_S1_dvm_en_END (1)
#define SOC_CCI500_SNOOP_CTRL_S1_snoop_support_START (30)
#define SOC_CCI500_SNOOP_CTRL_S1_snoop_support_END (30)
#define SOC_CCI500_SNOOP_CTRL_S1_dvm_support_START (31)
#define SOC_CCI500_SNOOP_CTRL_S1_dvm_support_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int shareable_override : 2;
        unsigned int reserved : 30;
    } reg;
} SOC_CCI500_SHARE_OVR_S1_UNION;
#endif
#define SOC_CCI500_SHARE_OVR_S1_shareable_override_START (0)
#define SOC_CCI500_SHARE_OVR_S1_shareable_override_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qv_max : 4;
        unsigned int qv_min : 4;
        unsigned int reserved_0 : 8;
        unsigned int bandwidth_allocation : 4;
        unsigned int reserved_1 : 4;
        unsigned int excess_bytes_per_qv : 3;
        unsigned int reserved_2 : 4;
        unsigned int reg_enable : 1;
    } reg;
} SOC_CCI500_ARQOS_OVR_S1_UNION;
#endif
#define SOC_CCI500_ARQOS_OVR_S1_qv_max_START (0)
#define SOC_CCI500_ARQOS_OVR_S1_qv_max_END (3)
#define SOC_CCI500_ARQOS_OVR_S1_qv_min_START (4)
#define SOC_CCI500_ARQOS_OVR_S1_qv_min_END (7)
#define SOC_CCI500_ARQOS_OVR_S1_bandwidth_allocation_START (16)
#define SOC_CCI500_ARQOS_OVR_S1_bandwidth_allocation_END (19)
#define SOC_CCI500_ARQOS_OVR_S1_excess_bytes_per_qv_START (24)
#define SOC_CCI500_ARQOS_OVR_S1_excess_bytes_per_qv_END (26)
#define SOC_CCI500_ARQOS_OVR_S1_reg_enable_START (31)
#define SOC_CCI500_ARQOS_OVR_S1_reg_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int qv_max : 4;
        unsigned int qv_min : 4;
        unsigned int reserved_0 : 8;
        unsigned int bandwidth_allocation : 4;
        unsigned int reserved_1 : 4;
        unsigned int excess_bytes_per_qv : 3;
        unsigned int reserved_2 : 4;
        unsigned int reg_enable : 1;
    } reg;
} SOC_CCI500_AWQOS_OVR_S1_UNION;
#endif
#define SOC_CCI500_AWQOS_OVR_S1_qv_max_START (0)
#define SOC_CCI500_AWQOS_OVR_S1_qv_max_END (3)
#define SOC_CCI500_AWQOS_OVR_S1_qv_min_START (4)
#define SOC_CCI500_AWQOS_OVR_S1_qv_min_END (7)
#define SOC_CCI500_AWQOS_OVR_S1_bandwidth_allocation_START (16)
#define SOC_CCI500_AWQOS_OVR_S1_bandwidth_allocation_END (19)
#define SOC_CCI500_AWQOS_OVR_S1_excess_bytes_per_qv_START (24)
#define SOC_CCI500_AWQOS_OVR_S1_excess_bytes_per_qv_END (26)
#define SOC_CCI500_AWQOS_OVR_S1_reg_enable_START (31)
#define SOC_CCI500_AWQOS_OVR_S1_reg_enable_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int max_ot : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_CCI500_QOS_MAX_OT_31_UNION;
#endif
#define SOC_CCI500_QOS_MAX_OT_31_max_ot_START (0)
#define SOC_CCI500_QOS_MAX_OT_31_max_ot_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_0_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_0_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_0_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_0_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_0_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_0_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_0_counter_START (0)
#define SOC_CCI500_ECNT_DATA_0_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_0_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_0_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_0_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_0_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_0_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_0_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_1_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_1_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_1_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_1_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_1_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_1_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_1_counter_START (0)
#define SOC_CCI500_ECNT_DATA_1_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_1_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_1_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_1_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_1_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_1_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_1_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_2_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_2_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_2_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_2_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_2_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_2_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_2_counter_START (0)
#define SOC_CCI500_ECNT_DATA_2_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_2_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_2_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_2_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_2_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_2_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_2_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_3_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_3_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_3_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_3_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_3_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_3_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_3_counter_START (0)
#define SOC_CCI500_ECNT_DATA_3_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_3_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_3_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_3_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_3_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_3_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_3_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_4_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_4_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_4_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_4_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_4_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_4_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_4_counter_START (0)
#define SOC_CCI500_ECNT_DATA_4_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_4_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_4_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_4_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_4_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_4_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_4_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_5_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_5_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_5_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_5_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_5_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_5_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_5_counter_START (0)
#define SOC_CCI500_ECNT_DATA_5_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_5_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_5_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_5_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_5_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_5_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_5_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_6_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_6_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_6_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_6_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_6_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_6_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_6_counter_START (0)
#define SOC_CCI500_ECNT_DATA_6_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_6_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_6_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_6_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_6_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_6_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_6_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mon_evtx : 5;
        unsigned int mon_intx : 4;
        unsigned int reserved : 23;
    } reg;
} SOC_CCI500_EVNT_SEL_7_UNION;
#endif
#define SOC_CCI500_EVNT_SEL_7_mon_evtx_START (0)
#define SOC_CCI500_EVNT_SEL_7_mon_evtx_END (4)
#define SOC_CCI500_EVNT_SEL_7_mon_intx_START (5)
#define SOC_CCI500_EVNT_SEL_7_mon_intx_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter : 32;
    } reg;
} SOC_CCI500_ECNT_DATA_7_UNION;
#endif
#define SOC_CCI500_ECNT_DATA_7_counter_START (0)
#define SOC_CCI500_ECNT_DATA_7_counter_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int counter_enable : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CTRL_7_UNION;
#endif
#define SOC_CCI500_ECNT_CTRL_7_counter_enable_START (0)
#define SOC_CCI500_ECNT_CTRL_7_counter_enable_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int event_counter : 1;
        unsigned int reserved : 31;
    } reg;
} SOC_CCI500_ECNT_CLR_OVFL_7_UNION;
#endif
#define SOC_CCI500_ECNT_CLR_OVFL_7_event_counter_START (0)
#define SOC_CCI500_ECNT_CLR_OVFL_7_event_counter_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stalled_ar_channel : 1;
        unsigned int stalled_r_channel : 1;
        unsigned int stalled_aw_channel : 1;
        unsigned int stalled_w_channel : 1;
        unsigned int stalled_b_channel : 1;
        unsigned int stalled_ac_channel : 1;
        unsigned int stalled_cr_channel : 1;
        unsigned int stalled_cd_channel : 1;
        unsigned int outstanding_reads : 8;
        unsigned int outstanding_writes : 8;
        unsigned int outstanding_snoops : 8;
    } reg;
} SOC_CCI500_SLAVE_DEBUG_0_UNION;
#endif
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_ar_channel_START (0)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_ar_channel_END (0)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_r_channel_START (1)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_r_channel_END (1)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_aw_channel_START (2)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_aw_channel_END (2)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_w_channel_START (3)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_w_channel_END (3)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_b_channel_START (4)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_b_channel_END (4)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_ac_channel_START (5)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_ac_channel_END (5)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_cr_channel_START (6)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_cr_channel_END (6)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_cd_channel_START (7)
#define SOC_CCI500_SLAVE_DEBUG_0_stalled_cd_channel_END (7)
#define SOC_CCI500_SLAVE_DEBUG_0_outstanding_reads_START (8)
#define SOC_CCI500_SLAVE_DEBUG_0_outstanding_reads_END (15)
#define SOC_CCI500_SLAVE_DEBUG_0_outstanding_writes_START (16)
#define SOC_CCI500_SLAVE_DEBUG_0_outstanding_writes_END (23)
#define SOC_CCI500_SLAVE_DEBUG_0_outstanding_snoops_START (24)
#define SOC_CCI500_SLAVE_DEBUG_0_outstanding_snoops_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stalled_ar_channel : 1;
        unsigned int stalled_r_channel : 1;
        unsigned int stalled_aw_channel : 1;
        unsigned int stalled_w_channel : 1;
        unsigned int stalled_b_channel : 1;
        unsigned int stalled_ac_channel : 1;
        unsigned int stalled_cr_channel : 1;
        unsigned int stalled_cd_channel : 1;
        unsigned int outstanding_reads : 8;
        unsigned int outstanding_writes : 8;
        unsigned int outstanding_snoops : 8;
    } reg;
} SOC_CCI500_SLAVE_DEBUG_1_UNION;
#endif
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_ar_channel_START (0)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_ar_channel_END (0)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_r_channel_START (1)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_r_channel_END (1)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_aw_channel_START (2)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_aw_channel_END (2)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_w_channel_START (3)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_w_channel_END (3)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_b_channel_START (4)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_b_channel_END (4)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_ac_channel_START (5)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_ac_channel_END (5)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_cr_channel_START (6)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_cr_channel_END (6)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_cd_channel_START (7)
#define SOC_CCI500_SLAVE_DEBUG_1_stalled_cd_channel_END (7)
#define SOC_CCI500_SLAVE_DEBUG_1_outstanding_reads_START (8)
#define SOC_CCI500_SLAVE_DEBUG_1_outstanding_reads_END (15)
#define SOC_CCI500_SLAVE_DEBUG_1_outstanding_writes_START (16)
#define SOC_CCI500_SLAVE_DEBUG_1_outstanding_writes_END (23)
#define SOC_CCI500_SLAVE_DEBUG_1_outstanding_snoops_START (24)
#define SOC_CCI500_SLAVE_DEBUG_1_outstanding_snoops_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stalled_ar_channel : 1;
        unsigned int stalled_r_channel : 1;
        unsigned int stalled_aw_channel : 1;
        unsigned int stalled_w_channel : 1;
        unsigned int stalled_b_channel : 1;
        unsigned int reserved_0 : 3;
        unsigned int outstanding_reads : 8;
        unsigned int outstanding_writes : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_CCI500_MASTER_DEBUG_0_UNION;
#endif
#define SOC_CCI500_MASTER_DEBUG_0_stalled_ar_channel_START (0)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_ar_channel_END (0)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_r_channel_START (1)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_r_channel_END (1)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_aw_channel_START (2)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_aw_channel_END (2)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_w_channel_START (3)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_w_channel_END (3)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_b_channel_START (4)
#define SOC_CCI500_MASTER_DEBUG_0_stalled_b_channel_END (4)
#define SOC_CCI500_MASTER_DEBUG_0_outstanding_reads_START (8)
#define SOC_CCI500_MASTER_DEBUG_0_outstanding_reads_END (15)
#define SOC_CCI500_MASTER_DEBUG_0_outstanding_writes_START (16)
#define SOC_CCI500_MASTER_DEBUG_0_outstanding_writes_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stalled_ar_channel : 1;
        unsigned int stalled_r_channel : 1;
        unsigned int stalled_aw_channel : 1;
        unsigned int stalled_w_channel : 1;
        unsigned int stalled_b_channel : 1;
        unsigned int reserved_0 : 3;
        unsigned int outstanding_reads : 8;
        unsigned int outstanding_writes : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_CCI500_MASTER_DEBUG_1_UNION;
#endif
#define SOC_CCI500_MASTER_DEBUG_1_stalled_ar_channel_START (0)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_ar_channel_END (0)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_r_channel_START (1)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_r_channel_END (1)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_aw_channel_START (2)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_aw_channel_END (2)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_w_channel_START (3)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_w_channel_END (3)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_b_channel_START (4)
#define SOC_CCI500_MASTER_DEBUG_1_stalled_b_channel_END (4)
#define SOC_CCI500_MASTER_DEBUG_1_outstanding_reads_START (8)
#define SOC_CCI500_MASTER_DEBUG_1_outstanding_reads_END (15)
#define SOC_CCI500_MASTER_DEBUG_1_outstanding_writes_START (16)
#define SOC_CCI500_MASTER_DEBUG_1_outstanding_writes_END (23)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
