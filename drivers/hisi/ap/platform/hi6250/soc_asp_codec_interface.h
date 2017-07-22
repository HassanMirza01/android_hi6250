#ifndef __SOC_ASP_CODEC_INTERFACE_H__
#define __SOC_ASP_CODEC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ASP_CODEC_SW_RST_N_ADDR(base) ((base) + (0x00))
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_ADDR(base) ((base) + (0x04))
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_ADDR(base) ((base) + (0x08))
#define SOC_ASP_CODEC_FS_CFG_ADDR(base) ((base) + (0x0C))
#define SOC_ASP_CODEC_I2S_CFG_ADDR(base) ((base) + (0x10))
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_ADDR(base) ((base) + (0x14))
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_ADDR(base) ((base) + (0x18))
#define SOC_ASP_CODEC_ADC_PGA_CFG_ADDR(base) ((base) + (0x1C))
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_ADDR(base) ((base) + (0x20))
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_ADDR(base) ((base) + (0x24))
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_ADDR(base) ((base) + (0x28))
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_ADDR(base) ((base) + (0x2C))
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_ADDR(base) ((base) + (0x30))
#define SOC_ASP_CODEC_APB_AFIFO_CFG_2_ADDR(base) ((base) + (0x34))
#define SOC_ASP_CODEC_STEREO_DLINK_FIFO_TH_CFG_ADDR(base) ((base) + (0x38))
#define SOC_ASP_CODEC_STEREO_UPLINK_FIFO_TH_CFG_ADDR(base) ((base) + (0x3C))
#define SOC_ASP_CODEC_VOICE_UPLINK_FIFO_TH_CFG_ADDR(base) ((base) + (0x40))
#define SOC_ASP_CODEC_CODEC_IRQ_MASK_ADDR(base) ((base) + (0x44))
#define SOC_ASP_CODEC_CODEC_IRQ_ADDR(base) ((base) + (0x48))
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_ADDR(base) ((base) + (0x4C))
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_ADDR(base) ((base) + (0x50))
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_ADDR(base) ((base) + (0x54))
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_ADDR(base) ((base) + (0x58))
#define SOC_ASP_CODEC_DMIC_SIF_CFG_ADDR(base) ((base) + (0x5C))
#define SOC_ASP_CODEC_MISC_CFG_ADDR(base) ((base) + (0x60))
#define SOC_ASP_CODEC_S2_SRC_CFG_ADDR(base) ((base) + (0x64))
#define SOC_ASP_CODEC_MEM_CFG_ADDR(base) ((base) + (0x68))
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_ADDR(base) ((base) + (0x6C))
#define SOC_ASP_CODEC_THIRD_MODEM_FIFO_TH_ADDR(base) ((base) + (0x70))
#define SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_TX_INC_CNT_ADDR(base) ((base) + (0x74))
#define SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_TX_DEC_CNT_ADDR(base) ((base) + (0x78))
#define SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_RX_INC_CNT_ADDR(base) ((base) + (0x7C))
#define SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_RX_DEC_CNT_ADDR(base) ((base) + (0x80))
#define SOC_ASP_CODEC_ANTI_FREQ_JITTER_EN_ADDR(base) ((base) + (0x84))
#define SOC_ASP_CODEC_CLK_SEL_ADDR(base) ((base) + (0x88))
#define SOC_ASP_CODEC_UPLINK_TEST_SEL_ADDR(base) ((base) + (0x8C))
#define SOC_ASP_CODEC_THIRDMD_DLINK_CHANNEL_ADDR(base) ((base) + (0xE8))
#define SOC_ASP_CODEC_THIRDMD_UPLINK_CHANNEL_ADDR(base) ((base) + (0xEC))
#define SOC_ASP_CODEC_VOICE_DLINK_CHANNEL_ADDR(base) ((base) + (0xF0))
#define SOC_ASP_CODEC_STEREO_DLINK_CHANNEL_ADDR(base) ((base) + (0xF4))
#define SOC_ASP_CODEC_STEREO_UPLINK_CHANNEL_ADDR(base) ((base) + (0xF8))
#define SOC_ASP_CODEC_VOICE_UPLINK_CHANNEL_ADDR(base) ((base) + (0xFC))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sw_rst_n : 1;
        unsigned int dig_ro_00 : 7;
        unsigned int version : 8;
        unsigned int dig_rw_00 : 16;
    } reg;
} SOC_ASP_CODEC_SW_RST_N_UNION;
#endif
#define SOC_ASP_CODEC_SW_RST_N_sw_rst_n_START (0)
#define SOC_ASP_CODEC_SW_RST_N_sw_rst_n_END (0)
#define SOC_ASP_CODEC_SW_RST_N_dig_ro_00_START (1)
#define SOC_ASP_CODEC_SW_RST_N_dig_ro_00_END (7)
#define SOC_ASP_CODEC_SW_RST_N_version_START (8)
#define SOC_ASP_CODEC_SW_RST_N_version_END (15)
#define SOC_ASP_CODEC_SW_RST_N_dig_rw_00_START (16)
#define SOC_ASP_CODEC_SW_RST_N_dig_rw_00_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stereo_uplink_l_en : 1;
        unsigned int stereo_uplink_r_en : 1;
        unsigned int voice_uplink_l_en : 1;
        unsigned int voice_uplink_r_en : 1;
        unsigned int stereo_dlink_l_en : 1;
        unsigned int stereo_dlink_r_en : 1;
        unsigned int voice_dlink_en : 1;
        unsigned int voice_dlink_src_en : 1;
        unsigned int s1_if_clk_en : 1;
        unsigned int s1_il_pga_en : 1;
        unsigned int s1_ir_pga_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int s2_il_pga_en : 1;
        unsigned int s2_ir_pga_en : 1;
        unsigned int s2_ol_src_en : 1;
        unsigned int s2_ol_mixer_en : 1;
        unsigned int s2_if_clk_en : 1;
        unsigned int reserved_1 : 3;
        unsigned int s3_if_clk_en : 1;
        unsigned int reserved_2 : 3;
        unsigned int thirdmd_dlink_en : 1;
        unsigned int thirdmd_uplink_en : 1;
        unsigned int reserved_3 : 6;
    } reg;
} SOC_ASP_CODEC_IF_CLK_EN_CFG_UNION;
#endif
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_stereo_uplink_l_en_START (0)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_stereo_uplink_l_en_END (0)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_stereo_uplink_r_en_START (1)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_stereo_uplink_r_en_END (1)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_voice_uplink_l_en_START (2)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_voice_uplink_l_en_END (2)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_voice_uplink_r_en_START (3)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_voice_uplink_r_en_END (3)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_stereo_dlink_l_en_START (4)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_stereo_dlink_l_en_END (4)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_stereo_dlink_r_en_START (5)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_stereo_dlink_r_en_END (5)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_voice_dlink_en_START (6)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_voice_dlink_en_END (6)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_voice_dlink_src_en_START (7)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_voice_dlink_src_en_END (7)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s1_if_clk_en_START (8)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s1_if_clk_en_END (8)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s1_il_pga_en_START (9)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s1_il_pga_en_END (9)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s1_ir_pga_en_START (10)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s1_ir_pga_en_END (10)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s2_il_pga_en_START (12)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s2_il_pga_en_END (12)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s2_ir_pga_en_START (13)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s2_ir_pga_en_END (13)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s2_ol_src_en_START (14)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s2_ol_src_en_END (14)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s2_ol_mixer_en_START (15)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s2_ol_mixer_en_END (15)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s2_if_clk_en_START (16)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s2_if_clk_en_END (16)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s3_if_clk_en_START (20)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_s3_if_clk_en_END (20)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_thirdmd_dlink_en_START (24)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_thirdmd_dlink_en_END (24)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_thirdmd_uplink_en_START (25)
#define SOC_ASP_CODEC_IF_CLK_EN_CFG_thirdmd_uplink_en_END (25)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adcl_pga_en : 1;
        unsigned int adcl_hpf_en : 1;
        unsigned int adcl_hbfvd_en : 1;
        unsigned int adcl_hbf2d_en : 1;
        unsigned int adcl_compd_en : 1;
        unsigned int adcl_cic_en : 1;
        unsigned int sidetone_pga_en : 1;
        unsigned int reserved_0 : 1;
        unsigned int adcr_pga_en : 1;
        unsigned int adcr_hpf_en : 1;
        unsigned int adcr_hbfvd_en : 1;
        unsigned int adcr_hbf2d_en : 1;
        unsigned int adcr_compd_en : 1;
        unsigned int adcr_cic_en : 1;
        unsigned int reserved_1 : 2;
        unsigned int dacl_agc_en : 1;
        unsigned int dacl_mixer_en : 1;
        unsigned int dacl_deemp_en : 1;
        unsigned int dacl_hbf1i_en : 1;
        unsigned int dacl_hbf2i_en : 1;
        unsigned int dacl_compi_en : 1;
        unsigned int dacl_sdm_en : 1;
        unsigned int reserved_2 : 1;
        unsigned int dacr_agc_en : 1;
        unsigned int dacr_mixer_en : 1;
        unsigned int dacr_deemp_en : 1;
        unsigned int dacr_hbf1i_en : 1;
        unsigned int dacr_hbf2i_en : 1;
        unsigned int dacr_compi_en : 1;
        unsigned int dacr_sdm_en : 1;
        unsigned int reserved_3 : 1;
    } reg;
} SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_UNION;
#endif
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcl_pga_en_START (0)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcl_pga_en_END (0)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcl_hpf_en_START (1)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcl_hpf_en_END (1)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcl_hbfvd_en_START (2)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcl_hbfvd_en_END (2)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcl_hbf2d_en_START (3)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcl_hbf2d_en_END (3)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcl_compd_en_START (4)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcl_compd_en_END (4)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcl_cic_en_START (5)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcl_cic_en_END (5)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_sidetone_pga_en_START (6)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_sidetone_pga_en_END (6)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcr_pga_en_START (8)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcr_pga_en_END (8)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcr_hpf_en_START (9)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcr_hpf_en_END (9)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcr_hbfvd_en_START (10)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcr_hbfvd_en_END (10)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcr_hbf2d_en_START (11)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcr_hbf2d_en_END (11)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcr_compd_en_START (12)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcr_compd_en_END (12)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcr_cic_en_START (13)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_adcr_cic_en_END (13)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_agc_en_START (16)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_agc_en_END (16)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_mixer_en_START (17)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_mixer_en_END (17)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_deemp_en_START (18)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_deemp_en_END (18)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_hbf1i_en_START (19)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_hbf1i_en_END (19)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_hbf2i_en_START (20)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_hbf2i_en_END (20)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_compi_en_START (21)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_compi_en_END (21)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_sdm_en_START (22)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacl_sdm_en_END (22)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_agc_en_START (24)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_agc_en_END (24)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_mixer_en_START (25)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_mixer_en_END (25)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_deemp_en_START (26)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_deemp_en_END (26)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_hbf1i_en_START (27)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_hbf1i_en_END (27)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_hbf2i_en_START (28)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_hbf2i_en_END (28)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_compi_en_START (29)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_compi_en_END (29)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_sdm_en_START (30)
#define SOC_ASP_CODEC_DIG_FILTER_CLK_EN_CFG_dacr_sdm_en_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int fs_voice_dlink : 3;
        unsigned int reserved_0 : 1;
        unsigned int fs_stereo_dlink_l : 3;
        unsigned int reserved_1 : 1;
        unsigned int fs_stereo_dlink_r : 3;
        unsigned int reserved_2 : 5;
        unsigned int fs_daclr : 3;
        unsigned int reserved_3 : 1;
        unsigned int fs_adclr : 3;
        unsigned int reserved_4 : 1;
        unsigned int fs_s1 : 3;
        unsigned int reserved_5 : 1;
        unsigned int fs_s2 : 3;
        unsigned int reserved_6 : 1;
    } reg;
} SOC_ASP_CODEC_FS_CFG_UNION;
#endif
#define SOC_ASP_CODEC_FS_CFG_fs_voice_dlink_START (0)
#define SOC_ASP_CODEC_FS_CFG_fs_voice_dlink_END (2)
#define SOC_ASP_CODEC_FS_CFG_fs_stereo_dlink_l_START (4)
#define SOC_ASP_CODEC_FS_CFG_fs_stereo_dlink_l_END (6)
#define SOC_ASP_CODEC_FS_CFG_fs_stereo_dlink_r_START (8)
#define SOC_ASP_CODEC_FS_CFG_fs_stereo_dlink_r_END (10)
#define SOC_ASP_CODEC_FS_CFG_fs_daclr_START (16)
#define SOC_ASP_CODEC_FS_CFG_fs_daclr_END (18)
#define SOC_ASP_CODEC_FS_CFG_fs_adclr_START (20)
#define SOC_ASP_CODEC_FS_CFG_fs_adclr_END (22)
#define SOC_ASP_CODEC_FS_CFG_fs_s1_START (24)
#define SOC_ASP_CODEC_FS_CFG_fs_s1_END (26)
#define SOC_ASP_CODEC_FS_CFG_fs_s2_START (28)
#define SOC_ASP_CODEC_FS_CFG_fs_s2_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s1_func_mode : 3;
        unsigned int s1_codec_data_format : 1;
        unsigned int s1_rx_clk_sel : 1;
        unsigned int s1_tx_clk_sel : 1;
        unsigned int s1_direct_loop : 2;
        unsigned int s1_codec_io_wordlength : 2;
        unsigned int s1_chnnl_mode : 1;
        unsigned int s1_lrclk_mode : 1;
        unsigned int s1_mst_slv : 1;
        unsigned int s1_frame_mode : 1;
        unsigned int s1_if_rx_ena : 1;
        unsigned int s1_if_tx_ena : 1;
        unsigned int s2_func_mode : 3;
        unsigned int s2_codec_data_format : 1;
        unsigned int s2_rx_clk_sel : 1;
        unsigned int s2_tx_clk_sel : 1;
        unsigned int s2_direct_loop : 2;
        unsigned int s2_codec_io_wordlength : 2;
        unsigned int s2_chnnl_mode : 1;
        unsigned int s2_lrclk_mode : 1;
        unsigned int s2_mst_slv : 1;
        unsigned int s2_frame_mode : 1;
        unsigned int s2_if_rx_ena : 1;
        unsigned int s2_if_tx_ena : 1;
    } reg;
} SOC_ASP_CODEC_I2S_CFG_UNION;
#endif
#define SOC_ASP_CODEC_I2S_CFG_s1_func_mode_START (0)
#define SOC_ASP_CODEC_I2S_CFG_s1_func_mode_END (2)
#define SOC_ASP_CODEC_I2S_CFG_s1_codec_data_format_START (3)
#define SOC_ASP_CODEC_I2S_CFG_s1_codec_data_format_END (3)
#define SOC_ASP_CODEC_I2S_CFG_s1_rx_clk_sel_START (4)
#define SOC_ASP_CODEC_I2S_CFG_s1_rx_clk_sel_END (4)
#define SOC_ASP_CODEC_I2S_CFG_s1_tx_clk_sel_START (5)
#define SOC_ASP_CODEC_I2S_CFG_s1_tx_clk_sel_END (5)
#define SOC_ASP_CODEC_I2S_CFG_s1_direct_loop_START (6)
#define SOC_ASP_CODEC_I2S_CFG_s1_direct_loop_END (7)
#define SOC_ASP_CODEC_I2S_CFG_s1_codec_io_wordlength_START (8)
#define SOC_ASP_CODEC_I2S_CFG_s1_codec_io_wordlength_END (9)
#define SOC_ASP_CODEC_I2S_CFG_s1_chnnl_mode_START (10)
#define SOC_ASP_CODEC_I2S_CFG_s1_chnnl_mode_END (10)
#define SOC_ASP_CODEC_I2S_CFG_s1_lrclk_mode_START (11)
#define SOC_ASP_CODEC_I2S_CFG_s1_lrclk_mode_END (11)
#define SOC_ASP_CODEC_I2S_CFG_s1_mst_slv_START (12)
#define SOC_ASP_CODEC_I2S_CFG_s1_mst_slv_END (12)
#define SOC_ASP_CODEC_I2S_CFG_s1_frame_mode_START (13)
#define SOC_ASP_CODEC_I2S_CFG_s1_frame_mode_END (13)
#define SOC_ASP_CODEC_I2S_CFG_s1_if_rx_ena_START (14)
#define SOC_ASP_CODEC_I2S_CFG_s1_if_rx_ena_END (14)
#define SOC_ASP_CODEC_I2S_CFG_s1_if_tx_ena_START (15)
#define SOC_ASP_CODEC_I2S_CFG_s1_if_tx_ena_END (15)
#define SOC_ASP_CODEC_I2S_CFG_s2_func_mode_START (16)
#define SOC_ASP_CODEC_I2S_CFG_s2_func_mode_END (18)
#define SOC_ASP_CODEC_I2S_CFG_s2_codec_data_format_START (19)
#define SOC_ASP_CODEC_I2S_CFG_s2_codec_data_format_END (19)
#define SOC_ASP_CODEC_I2S_CFG_s2_rx_clk_sel_START (20)
#define SOC_ASP_CODEC_I2S_CFG_s2_rx_clk_sel_END (20)
#define SOC_ASP_CODEC_I2S_CFG_s2_tx_clk_sel_START (21)
#define SOC_ASP_CODEC_I2S_CFG_s2_tx_clk_sel_END (21)
#define SOC_ASP_CODEC_I2S_CFG_s2_direct_loop_START (22)
#define SOC_ASP_CODEC_I2S_CFG_s2_direct_loop_END (23)
#define SOC_ASP_CODEC_I2S_CFG_s2_codec_io_wordlength_START (24)
#define SOC_ASP_CODEC_I2S_CFG_s2_codec_io_wordlength_END (25)
#define SOC_ASP_CODEC_I2S_CFG_s2_chnnl_mode_START (26)
#define SOC_ASP_CODEC_I2S_CFG_s2_chnnl_mode_END (26)
#define SOC_ASP_CODEC_I2S_CFG_s2_lrclk_mode_START (27)
#define SOC_ASP_CODEC_I2S_CFG_s2_lrclk_mode_END (27)
#define SOC_ASP_CODEC_I2S_CFG_s2_mst_slv_START (28)
#define SOC_ASP_CODEC_I2S_CFG_s2_mst_slv_END (28)
#define SOC_ASP_CODEC_I2S_CFG_s2_frame_mode_START (29)
#define SOC_ASP_CODEC_I2S_CFG_s2_frame_mode_END (29)
#define SOC_ASP_CODEC_I2S_CFG_s2_if_rx_ena_START (30)
#define SOC_ASP_CODEC_I2S_CFG_s2_if_rx_ena_END (30)
#define SOC_ASP_CODEC_I2S_CFG_s2_if_tx_ena_START (31)
#define SOC_ASP_CODEC_I2S_CFG_s2_if_tx_ena_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rm_codec_dac2adc : 3;
        unsigned int reserved_0 : 1;
        unsigned int lm_codec_dac2adc : 3;
        unsigned int reserved_1 : 1;
        unsigned int sw_dacl_sdm_dither : 1;
        unsigned int sw_dacr_sdm_dither : 1;
        unsigned int reserved_2 : 6;
        unsigned int dacl_mixer_in1_mute : 1;
        unsigned int dacl_mixer_in2_mute : 1;
        unsigned int dacl_mixer_in3_mute : 1;
        unsigned int dacl_mixer_in4_mute : 1;
        unsigned int dacl_mixer_gain : 2;
        unsigned int reserved_3 : 2;
        unsigned int dacr_mixer_in1_mute : 1;
        unsigned int dacr_mixer_in2_mute : 1;
        unsigned int dacr_mixer_in3_mute : 1;
        unsigned int dacr_mixer_in4_mute : 1;
        unsigned int dacr_mixer_gain : 2;
        unsigned int reserved_4 : 2;
    } reg;
} SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_UNION;
#endif
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_rm_codec_dac2adc_START (0)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_rm_codec_dac2adc_END (2)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_lm_codec_dac2adc_START (4)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_lm_codec_dac2adc_END (6)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_sw_dacl_sdm_dither_START (8)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_sw_dacl_sdm_dither_END (8)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_sw_dacr_sdm_dither_START (9)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_sw_dacr_sdm_dither_END (9)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacl_mixer_in1_mute_START (16)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacl_mixer_in1_mute_END (16)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacl_mixer_in2_mute_START (17)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacl_mixer_in2_mute_END (17)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacl_mixer_in3_mute_START (18)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacl_mixer_in3_mute_END (18)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacl_mixer_in4_mute_START (19)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacl_mixer_in4_mute_END (19)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacl_mixer_gain_START (20)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacl_mixer_gain_END (21)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacr_mixer_in1_mute_START (24)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacr_mixer_in1_mute_END (24)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacr_mixer_in2_mute_START (25)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacr_mixer_in2_mute_END (25)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacr_mixer_in3_mute_START (26)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacr_mixer_in3_mute_END (26)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacr_mixer_in4_mute_START (27)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacr_mixer_in4_mute_END (27)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacr_mixer_gain_START (28)
#define SOC_ASP_CODEC_DIG_FILTER_MODULE_CFG_dacr_mixer_gain_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int voice_dlink_src_mode : 3;
        unsigned int voice_dlink_src_rdy : 1;
        unsigned int s2_ol_src_mode : 2;
        unsigned int s2_ol_src_rdy : 1;
        unsigned int reserved_0 : 1;
        unsigned int s2_ol_mixer_in1_mute : 1;
        unsigned int s2_ol_mixer_in2_mute : 1;
        unsigned int s2_ol_mixer_gain : 2;
        unsigned int voice_dlink_mixer_in1_mute : 1;
        unsigned int voice_dlink_mixer_in2_mute : 1;
        unsigned int voice_dlink_mixer_gain : 2;
        unsigned int reserved_1 : 16;
    } reg;
} SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_UNION;
#endif
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_voice_dlink_src_mode_START (0)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_voice_dlink_src_mode_END (2)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_voice_dlink_src_rdy_START (3)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_voice_dlink_src_rdy_END (3)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_s2_ol_src_mode_START (4)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_s2_ol_src_mode_END (5)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_s2_ol_src_rdy_START (6)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_s2_ol_src_rdy_END (6)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_s2_ol_mixer_in1_mute_START (8)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_s2_ol_mixer_in1_mute_END (8)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_s2_ol_mixer_in2_mute_START (9)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_s2_ol_mixer_in2_mute_END (9)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_s2_ol_mixer_gain_START (10)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_s2_ol_mixer_gain_END (11)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_voice_dlink_mixer_in1_mute_START (12)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_voice_dlink_mixer_in1_mute_END (12)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_voice_dlink_mixer_in2_mute_START (13)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_voice_dlink_mixer_in2_mute_END (13)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_voice_dlink_mixer_gain_START (14)
#define SOC_ASP_CODEC_MUX_TOP_MODULE_CFG_voice_dlink_mixer_gain_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int adcl_pga_integer_config : 8;
        unsigned int adcl_pga_frac_config : 1;
        unsigned int adcl_pga_mute : 1;
        unsigned int reserved_0 : 2;
        unsigned int adcl_pga_thr_config : 2;
        unsigned int reserved_1 : 2;
        unsigned int adcr_pga_integer_config : 8;
        unsigned int adcr_pga_frac_config : 1;
        unsigned int adcr_pga_mute : 1;
        unsigned int reserved_2 : 2;
        unsigned int adcr_pga_thr_config : 2;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_ASP_CODEC_ADC_PGA_CFG_UNION;
#endif
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcl_pga_integer_config_START (0)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcl_pga_integer_config_END (7)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcl_pga_frac_config_START (8)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcl_pga_frac_config_END (8)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcl_pga_mute_START (9)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcl_pga_mute_END (9)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcl_pga_thr_config_START (12)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcl_pga_thr_config_END (13)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcr_pga_integer_config_START (16)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcr_pga_integer_config_END (23)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcr_pga_frac_config_START (24)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcr_pga_frac_config_END (24)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcr_pga_mute_START (25)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcr_pga_mute_END (25)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcr_pga_thr_config_START (28)
#define SOC_ASP_CODEC_ADC_PGA_CFG_adcr_pga_thr_config_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s1_il_pga_integer_config : 8;
        unsigned int s1_il_pga_frac_config : 1;
        unsigned int s1_il_pga_mute : 1;
        unsigned int reserved_0 : 2;
        unsigned int s1_il_pga_thr_config : 2;
        unsigned int reserved_1 : 2;
        unsigned int s1_ir_pga_integer_config : 8;
        unsigned int s1_ir_pga_frac_config : 1;
        unsigned int s1_ir_pga_mute : 1;
        unsigned int reserved_2 : 2;
        unsigned int s1_ir_pga_thr_config : 2;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_ASP_CODEC_S1_INPUT_PGA_CFG_UNION;
#endif
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_il_pga_integer_config_START (0)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_il_pga_integer_config_END (7)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_il_pga_frac_config_START (8)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_il_pga_frac_config_END (8)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_il_pga_mute_START (9)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_il_pga_mute_END (9)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_il_pga_thr_config_START (12)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_il_pga_thr_config_END (13)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_ir_pga_integer_config_START (16)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_ir_pga_integer_config_END (23)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_ir_pga_frac_config_START (24)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_ir_pga_frac_config_END (24)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_ir_pga_mute_START (25)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_ir_pga_mute_END (25)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_ir_pga_thr_config_START (28)
#define SOC_ASP_CODEC_S1_INPUT_PGA_CFG_s1_ir_pga_thr_config_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s2_il_pga_integer_config : 8;
        unsigned int s2_il_pga_frac_config : 1;
        unsigned int s2_il_pga_mute : 1;
        unsigned int reserved_0 : 2;
        unsigned int s2_il_pga_thr_config : 2;
        unsigned int reserved_1 : 2;
        unsigned int s2_ir_pga_integer_config : 8;
        unsigned int s2_ir_pga_frac_config : 1;
        unsigned int s2_ir_pga_mute : 1;
        unsigned int reserved_2 : 2;
        unsigned int s2_ir_pga_thr_config : 2;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_ASP_CODEC_S2_INPUT_PGA_CFG_UNION;
#endif
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_il_pga_integer_config_START (0)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_il_pga_integer_config_END (7)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_il_pga_frac_config_START (8)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_il_pga_frac_config_END (8)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_il_pga_mute_START (9)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_il_pga_mute_END (9)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_il_pga_thr_config_START (12)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_il_pga_thr_config_END (13)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_ir_pga_integer_config_START (16)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_ir_pga_integer_config_END (23)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_ir_pga_frac_config_START (24)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_ir_pga_frac_config_END (24)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_ir_pga_mute_START (25)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_ir_pga_mute_END (25)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_ir_pga_thr_config_START (28)
#define SOC_ASP_CODEC_S2_INPUT_PGA_CFG_s2_ir_pga_thr_config_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stereo_dlink_l_pga_integer_config : 8;
        unsigned int stereo_dlink_l_pga_frac_config : 1;
        unsigned int stereo_dlink_l_pga_mute : 1;
        unsigned int reserved_0 : 2;
        unsigned int stereo_dlink_l_pga_thr_config : 2;
        unsigned int reserved_1 : 2;
        unsigned int stereo_dlink_r_pga_integer_config : 8;
        unsigned int stereo_dlink_r_pga_frac_config : 1;
        unsigned int stereo_dlink_r_pga_mute : 1;
        unsigned int reserved_2 : 2;
        unsigned int stereo_dlink_r_pga_thr_config : 2;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_UNION;
#endif
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_l_pga_integer_config_START (0)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_l_pga_integer_config_END (7)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_l_pga_frac_config_START (8)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_l_pga_frac_config_END (8)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_l_pga_mute_START (9)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_l_pga_mute_END (9)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_l_pga_thr_config_START (12)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_l_pga_thr_config_END (13)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_r_pga_integer_config_START (16)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_r_pga_integer_config_END (23)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_r_pga_frac_config_START (24)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_r_pga_frac_config_END (24)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_r_pga_mute_START (25)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_r_pga_mute_END (25)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_r_pga_thr_config_START (28)
#define SOC_ASP_CODEC_STEREO_DLINK_PGA_CFG_stereo_dlink_r_pga_thr_config_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int voice_dlink_pga_integer_config : 8;
        unsigned int voice_dlink_pga_frac_config : 1;
        unsigned int voice_dlink_pga_mute : 1;
        unsigned int reserved_0 : 2;
        unsigned int voice_dlink_pga_thr_config : 2;
        unsigned int reserved_1 : 2;
        unsigned int sidetone_pga_integer_config : 8;
        unsigned int sidetone_pga_frac_config : 1;
        unsigned int sidetone_pga_mute : 1;
        unsigned int reserved_2 : 2;
        unsigned int sidetone_pga_thr_config : 2;
        unsigned int reserved_3 : 2;
    } reg;
} SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_UNION;
#endif
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_voice_dlink_pga_integer_config_START (0)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_voice_dlink_pga_integer_config_END (7)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_voice_dlink_pga_frac_config_START (8)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_voice_dlink_pga_frac_config_END (8)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_voice_dlink_pga_mute_START (9)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_voice_dlink_pga_mute_END (9)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_voice_dlink_pga_thr_config_START (12)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_voice_dlink_pga_thr_config_END (13)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_sidetone_pga_integer_config_START (16)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_sidetone_pga_integer_config_END (23)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_sidetone_pga_frac_config_START (24)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_sidetone_pga_frac_config_END (24)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_sidetone_pga_mute_START (25)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_sidetone_pga_mute_END (25)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_sidetone_pga_thr_config_START (28)
#define SOC_ASP_CODEC_VOICE_SIDETONE_DLINK_PGA_CFG_sidetone_pga_thr_config_END (29)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stereo_uplink_l_fifo_clr : 1;
        unsigned int stereo_uplink_r_fifo_clr : 1;
        unsigned int voice_uplink_l_fifo_clr : 1;
        unsigned int voice_uplink_r_fifo_clr : 1;
        unsigned int stereo_dlink_l_fifo_clr : 1;
        unsigned int stereo_dlink_r_fifo_clr : 1;
        unsigned int voice_dlink_fifo_clr : 1;
        unsigned int thirdmd_dlink_fifo_clr : 1;
        unsigned int thirdmd_uplink_fifo_clr : 1;
        unsigned int reserved_0 : 7;
        unsigned int stereo_uplink_l_fifo_werror : 1;
        unsigned int stereo_uplink_r_fifo_werror : 1;
        unsigned int voice_uplink_l_fifo_werror : 1;
        unsigned int voice_uplink_r_fifo_werror : 1;
        unsigned int stereo_dlink_l_fifo_werror : 1;
        unsigned int stereo_dlink_r_fifo_werror : 1;
        unsigned int voice_dlink_fifo_werror : 1;
        unsigned int reserved_1 : 1;
        unsigned int stereo_uplink_l_fifo_rerror : 1;
        unsigned int stereo_uplink_r_fifo_rerror : 1;
        unsigned int voice_uplink_l_fifo_rerror : 1;
        unsigned int voice_uplink_r_fifo_rerror : 1;
        unsigned int stereo_dlink_l_fifo_rerror : 1;
        unsigned int stereo_dlink_r_fifo_rerror : 1;
        unsigned int voice_dlink_fifo_rerror : 1;
        unsigned int reserved_2 : 1;
    } reg;
} SOC_ASP_CODEC_APB_AFIFO_CFG_1_UNION;
#endif
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_uplink_l_fifo_clr_START (0)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_uplink_l_fifo_clr_END (0)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_uplink_r_fifo_clr_START (1)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_uplink_r_fifo_clr_END (1)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_uplink_l_fifo_clr_START (2)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_uplink_l_fifo_clr_END (2)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_uplink_r_fifo_clr_START (3)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_uplink_r_fifo_clr_END (3)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_dlink_l_fifo_clr_START (4)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_dlink_l_fifo_clr_END (4)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_dlink_r_fifo_clr_START (5)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_dlink_r_fifo_clr_END (5)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_dlink_fifo_clr_START (6)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_dlink_fifo_clr_END (6)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_thirdmd_dlink_fifo_clr_START (7)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_thirdmd_dlink_fifo_clr_END (7)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_thirdmd_uplink_fifo_clr_START (8)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_thirdmd_uplink_fifo_clr_END (8)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_uplink_l_fifo_werror_START (16)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_uplink_l_fifo_werror_END (16)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_uplink_r_fifo_werror_START (17)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_uplink_r_fifo_werror_END (17)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_uplink_l_fifo_werror_START (18)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_uplink_l_fifo_werror_END (18)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_uplink_r_fifo_werror_START (19)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_uplink_r_fifo_werror_END (19)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_dlink_l_fifo_werror_START (20)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_dlink_l_fifo_werror_END (20)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_dlink_r_fifo_werror_START (21)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_dlink_r_fifo_werror_END (21)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_dlink_fifo_werror_START (22)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_dlink_fifo_werror_END (22)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_uplink_l_fifo_rerror_START (24)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_uplink_l_fifo_rerror_END (24)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_uplink_r_fifo_rerror_START (25)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_uplink_r_fifo_rerror_END (25)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_uplink_l_fifo_rerror_START (26)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_uplink_l_fifo_rerror_END (26)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_uplink_r_fifo_rerror_START (27)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_uplink_r_fifo_rerror_END (27)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_dlink_l_fifo_rerror_START (28)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_dlink_l_fifo_rerror_END (28)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_dlink_r_fifo_rerror_START (29)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_stereo_dlink_r_fifo_rerror_END (29)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_dlink_fifo_rerror_START (30)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_1_voice_dlink_fifo_rerror_END (30)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int voice_dlink_fifo_afull_th : 5;
        unsigned int reserved_0 : 3;
        unsigned int voice_dlink_fifo_aempty_th : 5;
        unsigned int reserved_1 : 3;
        unsigned int stereo_uplink_l_fifo_din_sel : 1;
        unsigned int stereo_uplink_r_fifo_din_sel : 1;
        unsigned int voice_uplink_l_fifo_din_sel : 1;
        unsigned int voice_uplink_r_fifo_din_sel : 1;
        unsigned int reserved_2 : 12;
    } reg;
} SOC_ASP_CODEC_APB_AFIFO_CFG_2_UNION;
#endif
#define SOC_ASP_CODEC_APB_AFIFO_CFG_2_voice_dlink_fifo_afull_th_START (0)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_2_voice_dlink_fifo_afull_th_END (4)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_2_voice_dlink_fifo_aempty_th_START (8)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_2_voice_dlink_fifo_aempty_th_END (12)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_2_stereo_uplink_l_fifo_din_sel_START (16)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_2_stereo_uplink_l_fifo_din_sel_END (16)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_2_stereo_uplink_r_fifo_din_sel_START (17)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_2_stereo_uplink_r_fifo_din_sel_END (17)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_2_voice_uplink_l_fifo_din_sel_START (18)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_2_voice_uplink_l_fifo_din_sel_END (18)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_2_voice_uplink_r_fifo_din_sel_START (19)
#define SOC_ASP_CODEC_APB_AFIFO_CFG_2_voice_uplink_r_fifo_din_sel_END (19)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stereo_dlink_l_fifo_afull_th : 5;
        unsigned int reserved_0 : 3;
        unsigned int stereo_dlink_l_fifo_aempty_th : 5;
        unsigned int reserved_1 : 3;
        unsigned int stereo_dlink_r_fifo_afull_th : 5;
        unsigned int reserved_2 : 3;
        unsigned int stereo_dlink_r_fifo_aempty_th : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_ASP_CODEC_STEREO_DLINK_FIFO_TH_CFG_UNION;
#endif
#define SOC_ASP_CODEC_STEREO_DLINK_FIFO_TH_CFG_stereo_dlink_l_fifo_afull_th_START (0)
#define SOC_ASP_CODEC_STEREO_DLINK_FIFO_TH_CFG_stereo_dlink_l_fifo_afull_th_END (4)
#define SOC_ASP_CODEC_STEREO_DLINK_FIFO_TH_CFG_stereo_dlink_l_fifo_aempty_th_START (8)
#define SOC_ASP_CODEC_STEREO_DLINK_FIFO_TH_CFG_stereo_dlink_l_fifo_aempty_th_END (12)
#define SOC_ASP_CODEC_STEREO_DLINK_FIFO_TH_CFG_stereo_dlink_r_fifo_afull_th_START (16)
#define SOC_ASP_CODEC_STEREO_DLINK_FIFO_TH_CFG_stereo_dlink_r_fifo_afull_th_END (20)
#define SOC_ASP_CODEC_STEREO_DLINK_FIFO_TH_CFG_stereo_dlink_r_fifo_aempty_th_START (24)
#define SOC_ASP_CODEC_STEREO_DLINK_FIFO_TH_CFG_stereo_dlink_r_fifo_aempty_th_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stereo_uplink_l_fifo_afull_th : 5;
        unsigned int reserved_0 : 3;
        unsigned int stereo_uplink_l_fifo_aempty_th : 5;
        unsigned int reserved_1 : 3;
        unsigned int stereo_uplink_r_fifo_afull_th : 5;
        unsigned int reserved_2 : 3;
        unsigned int stereo_uplink_r_fifo_aempty_th : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_ASP_CODEC_STEREO_UPLINK_FIFO_TH_CFG_UNION;
#endif
#define SOC_ASP_CODEC_STEREO_UPLINK_FIFO_TH_CFG_stereo_uplink_l_fifo_afull_th_START (0)
#define SOC_ASP_CODEC_STEREO_UPLINK_FIFO_TH_CFG_stereo_uplink_l_fifo_afull_th_END (4)
#define SOC_ASP_CODEC_STEREO_UPLINK_FIFO_TH_CFG_stereo_uplink_l_fifo_aempty_th_START (8)
#define SOC_ASP_CODEC_STEREO_UPLINK_FIFO_TH_CFG_stereo_uplink_l_fifo_aempty_th_END (12)
#define SOC_ASP_CODEC_STEREO_UPLINK_FIFO_TH_CFG_stereo_uplink_r_fifo_afull_th_START (16)
#define SOC_ASP_CODEC_STEREO_UPLINK_FIFO_TH_CFG_stereo_uplink_r_fifo_afull_th_END (20)
#define SOC_ASP_CODEC_STEREO_UPLINK_FIFO_TH_CFG_stereo_uplink_r_fifo_aempty_th_START (24)
#define SOC_ASP_CODEC_STEREO_UPLINK_FIFO_TH_CFG_stereo_uplink_r_fifo_aempty_th_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int voice_uplink_l_fifo_afull_th : 5;
        unsigned int reserved_0 : 3;
        unsigned int voice_uplink_l_fifo_aempty_th : 5;
        unsigned int reserved_1 : 3;
        unsigned int voice_uplink_r_fifo_afull_th : 5;
        unsigned int reserved_2 : 3;
        unsigned int voice_uplink_r_fifo_aempty_th : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_ASP_CODEC_VOICE_UPLINK_FIFO_TH_CFG_UNION;
#endif
#define SOC_ASP_CODEC_VOICE_UPLINK_FIFO_TH_CFG_voice_uplink_l_fifo_afull_th_START (0)
#define SOC_ASP_CODEC_VOICE_UPLINK_FIFO_TH_CFG_voice_uplink_l_fifo_afull_th_END (4)
#define SOC_ASP_CODEC_VOICE_UPLINK_FIFO_TH_CFG_voice_uplink_l_fifo_aempty_th_START (8)
#define SOC_ASP_CODEC_VOICE_UPLINK_FIFO_TH_CFG_voice_uplink_l_fifo_aempty_th_END (12)
#define SOC_ASP_CODEC_VOICE_UPLINK_FIFO_TH_CFG_voice_uplink_r_fifo_afull_th_START (16)
#define SOC_ASP_CODEC_VOICE_UPLINK_FIFO_TH_CFG_voice_uplink_r_fifo_afull_th_END (20)
#define SOC_ASP_CODEC_VOICE_UPLINK_FIFO_TH_CFG_voice_uplink_r_fifo_aempty_th_START (24)
#define SOC_ASP_CODEC_VOICE_UPLINK_FIFO_TH_CFG_voice_uplink_r_fifo_aempty_th_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int codec_data_intrp_mask : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ASP_CODEC_CODEC_IRQ_MASK_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_IRQ_MASK_codec_data_intrp_mask_START (0)
#define SOC_ASP_CODEC_CODEC_IRQ_MASK_codec_data_intrp_mask_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int codec_data_intrp : 6;
        unsigned int reserved : 26;
    } reg;
} SOC_ASP_CODEC_CODEC_IRQ_UNION;
#endif
#define SOC_ASP_CODEC_CODEC_IRQ_codec_data_intrp_START (0)
#define SOC_ASP_CODEC_CODEC_IRQ_codec_data_intrp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dacl_agc_gwin_config : 2;
        unsigned int dacl_agc_levellow_config : 2;
        unsigned int dacl_agc_gstepd_config : 2;
        unsigned int dacl_agc_timemute_config : 2;
        unsigned int dacl_agc_ngw_config : 2;
        unsigned int dacl_agc_ytarget_config : 3;
        unsigned int dacl_agc_t_amin_config : 2;
        unsigned int dacl_agc_gsuppress : 1;
        unsigned int dacl_agc_kfslow : 2;
        unsigned int dacl_agc_kfrapid : 2;
        unsigned int dacl_agc_ngl_config : 2;
        unsigned int dacl_agc_ngh_config : 2;
        unsigned int dacl_agc_timer : 3;
        unsigned int dacl_agc_ngi_config : 3;
        unsigned int dacl_agc_timenng_config : 2;
    } reg;
} SOC_ASP_CODEC_DACL_AGC_CFG_1_UNION;
#endif
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_gwin_config_START (0)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_gwin_config_END (1)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_levellow_config_START (2)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_levellow_config_END (3)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_gstepd_config_START (4)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_gstepd_config_END (5)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_timemute_config_START (6)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_timemute_config_END (7)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_ngw_config_START (8)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_ngw_config_END (9)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_ytarget_config_START (10)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_ytarget_config_END (12)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_t_amin_config_START (13)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_t_amin_config_END (14)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_gsuppress_START (15)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_gsuppress_END (15)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_kfslow_START (16)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_kfslow_END (17)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_kfrapid_START (18)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_kfrapid_END (19)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_ngl_config_START (20)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_ngl_config_END (21)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_ngh_config_START (22)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_ngh_config_END (23)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_timer_START (24)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_timer_END (26)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_ngi_config_START (27)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_ngi_config_END (29)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_timenng_config_START (30)
#define SOC_ASP_CODEC_DACL_AGC_CFG_1_dacl_agc_timenng_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dacl_agc_timedecay_config : 2;
        unsigned int dacl_agc_timeghold_config : 2;
        unsigned int dacl_agc_gmute_config : 2;
        unsigned int dacl_agc_mute_bypass : 1;
        unsigned int dacl_agc_bypass : 1;
        unsigned int dacl_agc_usr_gdb_integer : 8;
        unsigned int dacl_agc_usr_gdb_frac : 1;
        unsigned int dacl_agc_sw_clr : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CODEC_DACL_AGC_CFG_2_UNION;
#endif
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_timedecay_config_START (0)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_timedecay_config_END (1)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_timeghold_config_START (2)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_timeghold_config_END (3)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_gmute_config_START (4)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_gmute_config_END (5)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_mute_bypass_START (6)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_mute_bypass_END (6)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_bypass_START (7)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_bypass_END (7)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_usr_gdb_integer_START (8)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_usr_gdb_integer_END (15)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_usr_gdb_frac_START (16)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_usr_gdb_frac_END (16)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_sw_clr_START (17)
#define SOC_ASP_CODEC_DACL_AGC_CFG_2_dacl_agc_sw_clr_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dacr_agc_gwin_config : 2;
        unsigned int dacr_agc_levellow_config : 2;
        unsigned int dacr_agc_gstepd_config : 2;
        unsigned int dacr_agc_timemute_config : 2;
        unsigned int dacr_agc_ngw_config : 2;
        unsigned int dacr_agc_ytarget_config : 3;
        unsigned int dacr_agc_t_amin_config : 2;
        unsigned int dacr_agc_gsuppress : 1;
        unsigned int dacr_agc_kfslow : 2;
        unsigned int dacr_agc_kfrapid : 2;
        unsigned int dacr_agc_ngl_config : 2;
        unsigned int dacr_agc_ngh_config : 2;
        unsigned int dacr_agc_timer : 3;
        unsigned int dacr_agc_ngi_config : 3;
        unsigned int dacr_agc_timenng_config : 2;
    } reg;
} SOC_ASP_CODEC_DACR_AGC_CFG_1_UNION;
#endif
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_gwin_config_START (0)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_gwin_config_END (1)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_levellow_config_START (2)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_levellow_config_END (3)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_gstepd_config_START (4)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_gstepd_config_END (5)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_timemute_config_START (6)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_timemute_config_END (7)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_ngw_config_START (8)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_ngw_config_END (9)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_ytarget_config_START (10)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_ytarget_config_END (12)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_t_amin_config_START (13)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_t_amin_config_END (14)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_gsuppress_START (15)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_gsuppress_END (15)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_kfslow_START (16)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_kfslow_END (17)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_kfrapid_START (18)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_kfrapid_END (19)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_ngl_config_START (20)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_ngl_config_END (21)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_ngh_config_START (22)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_ngh_config_END (23)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_timer_START (24)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_timer_END (26)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_ngi_config_START (27)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_ngi_config_END (29)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_timenng_config_START (30)
#define SOC_ASP_CODEC_DACR_AGC_CFG_1_dacr_agc_timenng_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int dacr_agc_timedecay_config : 2;
        unsigned int dacr_agc_timeghold_config : 2;
        unsigned int dacr_agc_gmute_config : 2;
        unsigned int dacr_agc_mute_bypass : 1;
        unsigned int dacr_agc_bypass : 1;
        unsigned int dacr_agc_usr_gdb_integer : 8;
        unsigned int dacr_agc_usr_gdb_frac : 1;
        unsigned int dacr_agc_sw_clr : 1;
        unsigned int reserved : 14;
    } reg;
} SOC_ASP_CODEC_DACR_AGC_CFG_2_UNION;
#endif
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_timedecay_config_START (0)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_timedecay_config_END (1)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_timeghold_config_START (2)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_timeghold_config_END (3)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_gmute_config_START (4)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_gmute_config_END (5)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_mute_bypass_START (6)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_mute_bypass_END (6)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_bypass_START (7)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_bypass_END (7)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_usr_gdb_integer_START (8)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_usr_gdb_integer_END (15)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_usr_gdb_frac_START (16)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_usr_gdb_frac_END (16)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_sw_clr_START (17)
#define SOC_ASP_CODEC_DACR_AGC_CFG_2_dacr_agc_sw_clr_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int sif_adcl_en : 1;
        unsigned int sif_adcr_en : 1;
        unsigned int sif_dacl_en : 1;
        unsigned int sif_dacr_en : 1;
        unsigned int dac_p2s_loopback : 1;
        unsigned int sif_s2p_loopback : 1;
        unsigned int sif_edge_sel : 1;
        unsigned int sif_en : 1;
        unsigned int reserved_0 : 8;
        unsigned int sw_dmic_mode : 1;
        unsigned int dmic_reverse : 1;
        unsigned int fs_dmic : 2;
        unsigned int dmic_en : 1;
        unsigned int reserved_1 : 11;
    } reg;
} SOC_ASP_CODEC_DMIC_SIF_CFG_UNION;
#endif
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_adcl_en_START (0)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_adcl_en_END (0)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_adcr_en_START (1)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_adcr_en_END (1)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_dacl_en_START (2)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_dacl_en_END (2)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_dacr_en_START (3)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_dacr_en_END (3)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_dac_p2s_loopback_START (4)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_dac_p2s_loopback_END (4)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_s2p_loopback_START (5)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_s2p_loopback_END (5)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_edge_sel_START (6)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_edge_sel_END (6)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_en_START (7)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sif_en_END (7)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sw_dmic_mode_START (16)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_sw_dmic_mode_END (16)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_dmic_reverse_START (17)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_dmic_reverse_END (17)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_fs_dmic_START (18)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_fs_dmic_END (19)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_dmic_en_START (20)
#define SOC_ASP_CODEC_DMIC_SIF_CFG_dmic_en_END (20)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s2_dout_left_sel : 1;
        unsigned int s1_dout_test_sel : 1;
        unsigned int s2_dout_test_sel : 1;
        unsigned int s2_dout_right_sel : 1;
        unsigned int stereo_dlink_test_sel : 1;
        unsigned int reserved_0 : 1;
        unsigned int voice_dlink_din_sel : 1;
        unsigned int voice_dlink_test_sel : 1;
        unsigned int voice_dlink_src_up_dout_vld_sel : 1;
        unsigned int reserved_1 : 3;
        unsigned int s3_din_test_sel : 1;
        unsigned int s3_dout_left_sel : 1;
        unsigned int s3_dout_right_sel : 2;
        unsigned int thirdmd_dlink_din_sel : 1;
        unsigned int thirdmd_dlink_test_sel : 1;
        unsigned int reserved_2 : 14;
    } reg;
} SOC_ASP_CODEC_MISC_CFG_UNION;
#endif
#define SOC_ASP_CODEC_MISC_CFG_s2_dout_left_sel_START (0)
#define SOC_ASP_CODEC_MISC_CFG_s2_dout_left_sel_END (0)
#define SOC_ASP_CODEC_MISC_CFG_s1_dout_test_sel_START (1)
#define SOC_ASP_CODEC_MISC_CFG_s1_dout_test_sel_END (1)
#define SOC_ASP_CODEC_MISC_CFG_s2_dout_test_sel_START (2)
#define SOC_ASP_CODEC_MISC_CFG_s2_dout_test_sel_END (2)
#define SOC_ASP_CODEC_MISC_CFG_s2_dout_right_sel_START (3)
#define SOC_ASP_CODEC_MISC_CFG_s2_dout_right_sel_END (3)
#define SOC_ASP_CODEC_MISC_CFG_stereo_dlink_test_sel_START (4)
#define SOC_ASP_CODEC_MISC_CFG_stereo_dlink_test_sel_END (4)
#define SOC_ASP_CODEC_MISC_CFG_voice_dlink_din_sel_START (6)
#define SOC_ASP_CODEC_MISC_CFG_voice_dlink_din_sel_END (6)
#define SOC_ASP_CODEC_MISC_CFG_voice_dlink_test_sel_START (7)
#define SOC_ASP_CODEC_MISC_CFG_voice_dlink_test_sel_END (7)
#define SOC_ASP_CODEC_MISC_CFG_voice_dlink_src_up_dout_vld_sel_START (8)
#define SOC_ASP_CODEC_MISC_CFG_voice_dlink_src_up_dout_vld_sel_END (8)
#define SOC_ASP_CODEC_MISC_CFG_s3_din_test_sel_START (12)
#define SOC_ASP_CODEC_MISC_CFG_s3_din_test_sel_END (12)
#define SOC_ASP_CODEC_MISC_CFG_s3_dout_left_sel_START (13)
#define SOC_ASP_CODEC_MISC_CFG_s3_dout_left_sel_END (13)
#define SOC_ASP_CODEC_MISC_CFG_s3_dout_right_sel_START (14)
#define SOC_ASP_CODEC_MISC_CFG_s3_dout_right_sel_END (15)
#define SOC_ASP_CODEC_MISC_CFG_thirdmd_dlink_din_sel_START (16)
#define SOC_ASP_CODEC_MISC_CFG_thirdmd_dlink_din_sel_END (16)
#define SOC_ASP_CODEC_MISC_CFG_thirdmd_dlink_test_sel_START (17)
#define SOC_ASP_CODEC_MISC_CFG_thirdmd_dlink_test_sel_END (17)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s2_il_src_up_en : 1;
        unsigned int s2_il_src_down_en : 1;
        unsigned int s2_ir_src_up_en : 1;
        unsigned int s2_ir_src_down_en : 1;
        unsigned int s2_il_src_up_src_rdy : 1;
        unsigned int s2_il_src_down_src_rdy : 1;
        unsigned int s2_ir_src_up_src_rdy : 1;
        unsigned int s2_ir_src_down_src_rdy : 1;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_CODEC_S2_SRC_CFG_UNION;
#endif
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_il_src_up_en_START (0)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_il_src_up_en_END (0)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_il_src_down_en_START (1)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_il_src_down_en_END (1)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_ir_src_up_en_START (2)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_ir_src_up_en_END (2)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_ir_src_down_en_START (3)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_ir_src_down_en_END (3)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_il_src_up_src_rdy_START (4)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_il_src_up_src_rdy_END (4)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_il_src_down_src_rdy_START (5)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_il_src_down_src_rdy_END (5)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_ir_src_up_src_rdy_START (6)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_ir_src_up_src_rdy_END (6)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_ir_src_down_src_rdy_START (7)
#define SOC_ASP_CODEC_S2_SRC_CFG_s2_ir_src_down_src_rdy_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int mem_ctrl_s : 16;
        unsigned int mem_ctrl_d1w2r : 16;
    } reg;
} SOC_ASP_CODEC_MEM_CFG_UNION;
#endif
#define SOC_ASP_CODEC_MEM_CFG_mem_ctrl_s_START (0)
#define SOC_ASP_CODEC_MEM_CFG_mem_ctrl_s_END (15)
#define SOC_ASP_CODEC_MEM_CFG_mem_ctrl_d1w2r_START (16)
#define SOC_ASP_CODEC_MEM_CFG_mem_ctrl_d1w2r_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s3_func_mode : 3;
        unsigned int s3_codec_data_format : 1;
        unsigned int s3_rx_clk_sel : 1;
        unsigned int s3_tx_clk_sel : 1;
        unsigned int s3_direct_loop : 2;
        unsigned int s3_codec_io_wordlength : 2;
        unsigned int s3_chnnl_mode : 1;
        unsigned int s3_lrclk_mode : 1;
        unsigned int s3_mst_slv : 1;
        unsigned int s3_frame_mode : 1;
        unsigned int s3_if_rx_ena : 1;
        unsigned int s3_if_tx_ena : 1;
        unsigned int fs_s3 : 3;
        unsigned int reserved : 1;
        unsigned int thirdmd_dlink_pga_integer_config : 8;
        unsigned int thirdmd_dlink_pga_frac_config : 1;
        unsigned int thirdmd_dlink_pga_mute : 1;
        unsigned int thirdmd_dlink_pga_thr_config : 2;
    } reg;
} SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_UNION;
#endif
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_func_mode_START (0)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_func_mode_END (2)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_codec_data_format_START (3)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_codec_data_format_END (3)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_rx_clk_sel_START (4)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_rx_clk_sel_END (4)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_tx_clk_sel_START (5)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_tx_clk_sel_END (5)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_direct_loop_START (6)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_direct_loop_END (7)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_codec_io_wordlength_START (8)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_codec_io_wordlength_END (9)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_chnnl_mode_START (10)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_chnnl_mode_END (10)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_lrclk_mode_START (11)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_lrclk_mode_END (11)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_mst_slv_START (12)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_mst_slv_END (12)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_frame_mode_START (13)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_frame_mode_END (13)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_if_rx_ena_START (14)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_if_rx_ena_END (14)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_if_tx_ena_START (15)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_s3_if_tx_ena_END (15)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_fs_s3_START (16)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_fs_s3_END (18)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_thirdmd_dlink_pga_integer_config_START (20)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_thirdmd_dlink_pga_integer_config_END (27)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_thirdmd_dlink_pga_frac_config_START (28)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_thirdmd_dlink_pga_frac_config_END (28)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_thirdmd_dlink_pga_mute_START (29)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_thirdmd_dlink_pga_mute_END (29)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_thirdmd_dlink_pga_thr_config_START (30)
#define SOC_ASP_CODEC_THIRDMD_PCM_PGA_CFG_thirdmd_dlink_pga_thr_config_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thirdmd_dlink_fifo_afull_th : 5;
        unsigned int reserved_0 : 3;
        unsigned int thirdmd_dlink_fifo_aempty_th : 5;
        unsigned int reserved_1 : 3;
        unsigned int thirdmd_uplink_fifo_afull_th : 5;
        unsigned int reserved_2 : 3;
        unsigned int thirdmd_uplink_fifo_aempty_th : 5;
        unsigned int reserved_3 : 3;
    } reg;
} SOC_ASP_CODEC_THIRD_MODEM_FIFO_TH_UNION;
#endif
#define SOC_ASP_CODEC_THIRD_MODEM_FIFO_TH_thirdmd_dlink_fifo_afull_th_START (0)
#define SOC_ASP_CODEC_THIRD_MODEM_FIFO_TH_thirdmd_dlink_fifo_afull_th_END (4)
#define SOC_ASP_CODEC_THIRD_MODEM_FIFO_TH_thirdmd_dlink_fifo_aempty_th_START (8)
#define SOC_ASP_CODEC_THIRD_MODEM_FIFO_TH_thirdmd_dlink_fifo_aempty_th_END (12)
#define SOC_ASP_CODEC_THIRD_MODEM_FIFO_TH_thirdmd_uplink_fifo_afull_th_START (16)
#define SOC_ASP_CODEC_THIRD_MODEM_FIFO_TH_thirdmd_uplink_fifo_afull_th_END (20)
#define SOC_ASP_CODEC_THIRD_MODEM_FIFO_TH_thirdmd_uplink_fifo_aempty_th_START (24)
#define SOC_ASP_CODEC_THIRD_MODEM_FIFO_TH_thirdmd_uplink_fifo_aempty_th_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s3_tx_inc_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_TX_INC_CNT_UNION;
#endif
#define SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_TX_INC_CNT_s3_tx_inc_cnt_START (0)
#define SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_TX_INC_CNT_s3_tx_inc_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s3_tx_dec_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_TX_DEC_CNT_UNION;
#endif
#define SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_TX_DEC_CNT_s3_tx_dec_cnt_START (0)
#define SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_TX_DEC_CNT_s3_tx_dec_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s3_rx_inc_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_RX_INC_CNT_UNION;
#endif
#define SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_RX_INC_CNT_s3_rx_inc_cnt_START (0)
#define SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_RX_INC_CNT_s3_rx_inc_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s3_rx_dec_cnt : 8;
        unsigned int reserved : 24;
    } reg;
} SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_RX_DEC_CNT_UNION;
#endif
#define SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_RX_DEC_CNT_s3_rx_dec_cnt_START (0)
#define SOC_ASP_CODEC_S3_ANTI_FREQ_JITTER_RX_DEC_CNT_s3_rx_dec_cnt_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int s3_tx_anti_freq_jitter_en : 1;
        unsigned int s3_rx_anti_freq_jitter_en : 1;
        unsigned int reserved : 30;
    } reg;
} SOC_ASP_CODEC_ANTI_FREQ_JITTER_EN_UNION;
#endif
#define SOC_ASP_CODEC_ANTI_FREQ_JITTER_EN_s3_tx_anti_freq_jitter_en_START (0)
#define SOC_ASP_CODEC_ANTI_FREQ_JITTER_EN_s3_tx_anti_freq_jitter_en_END (0)
#define SOC_ASP_CODEC_ANTI_FREQ_JITTER_EN_s3_rx_anti_freq_jitter_en_START (1)
#define SOC_ASP_CODEC_ANTI_FREQ_JITTER_EN_s3_rx_anti_freq_jitter_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int external_12288k_sel : 1;
        unsigned int i2s_bt_fm_sel : 1;
        unsigned int reserved : 14;
        unsigned int dig_rw_01 : 16;
    } reg;
} SOC_ASP_CODEC_CLK_SEL_UNION;
#endif
#define SOC_ASP_CODEC_CLK_SEL_external_12288k_sel_START (0)
#define SOC_ASP_CODEC_CLK_SEL_external_12288k_sel_END (0)
#define SOC_ASP_CODEC_CLK_SEL_i2s_bt_fm_sel_START (1)
#define SOC_ASP_CODEC_CLK_SEL_i2s_bt_fm_sel_END (1)
#define SOC_ASP_CODEC_CLK_SEL_dig_rw_01_START (16)
#define SOC_ASP_CODEC_CLK_SEL_dig_rw_01_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stereo_uplink_r_test_sel : 1;
        unsigned int stereo_uplink_l_test_sel : 1;
        unsigned int voice_uplink_l_test_sel : 1;
        unsigned int thirdmd_uplink_l_test_sel : 1;
        unsigned int smart_pa_fb_sel : 1;
        unsigned int reserved : 27;
    } reg;
} SOC_ASP_CODEC_UPLINK_TEST_SEL_UNION;
#endif
#define SOC_ASP_CODEC_UPLINK_TEST_SEL_stereo_uplink_r_test_sel_START (0)
#define SOC_ASP_CODEC_UPLINK_TEST_SEL_stereo_uplink_r_test_sel_END (0)
#define SOC_ASP_CODEC_UPLINK_TEST_SEL_stereo_uplink_l_test_sel_START (1)
#define SOC_ASP_CODEC_UPLINK_TEST_SEL_stereo_uplink_l_test_sel_END (1)
#define SOC_ASP_CODEC_UPLINK_TEST_SEL_voice_uplink_l_test_sel_START (2)
#define SOC_ASP_CODEC_UPLINK_TEST_SEL_voice_uplink_l_test_sel_END (2)
#define SOC_ASP_CODEC_UPLINK_TEST_SEL_thirdmd_uplink_l_test_sel_START (3)
#define SOC_ASP_CODEC_UPLINK_TEST_SEL_thirdmd_uplink_l_test_sel_END (3)
#define SOC_ASP_CODEC_UPLINK_TEST_SEL_smart_pa_fb_sel_START (4)
#define SOC_ASP_CODEC_UPLINK_TEST_SEL_smart_pa_fb_sel_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thirdmd_dlink_wdata : 32;
    } reg;
} SOC_ASP_CODEC_THIRDMD_DLINK_CHANNEL_UNION;
#endif
#define SOC_ASP_CODEC_THIRDMD_DLINK_CHANNEL_thirdmd_dlink_wdata_START (0)
#define SOC_ASP_CODEC_THIRDMD_DLINK_CHANNEL_thirdmd_dlink_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int thirdmd_uplink_rdata : 32;
    } reg;
} SOC_ASP_CODEC_THIRDMD_UPLINK_CHANNEL_UNION;
#endif
#define SOC_ASP_CODEC_THIRDMD_UPLINK_CHANNEL_thirdmd_uplink_rdata_START (0)
#define SOC_ASP_CODEC_THIRDMD_UPLINK_CHANNEL_thirdmd_uplink_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int voice_dlink_wdata : 32;
    } reg;
} SOC_ASP_CODEC_VOICE_DLINK_CHANNEL_UNION;
#endif
#define SOC_ASP_CODEC_VOICE_DLINK_CHANNEL_voice_dlink_wdata_START (0)
#define SOC_ASP_CODEC_VOICE_DLINK_CHANNEL_voice_dlink_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stereo_dlink_wdata : 32;
    } reg;
} SOC_ASP_CODEC_STEREO_DLINK_CHANNEL_UNION;
#endif
#define SOC_ASP_CODEC_STEREO_DLINK_CHANNEL_stereo_dlink_wdata_START (0)
#define SOC_ASP_CODEC_STEREO_DLINK_CHANNEL_stereo_dlink_wdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int stereo_uplink_rdata : 32;
    } reg;
} SOC_ASP_CODEC_STEREO_UPLINK_CHANNEL_UNION;
#endif
#define SOC_ASP_CODEC_STEREO_UPLINK_CHANNEL_stereo_uplink_rdata_START (0)
#define SOC_ASP_CODEC_STEREO_UPLINK_CHANNEL_stereo_uplink_rdata_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int voice_uplink_rdata : 32;
    } reg;
} SOC_ASP_CODEC_VOICE_UPLINK_CHANNEL_UNION;
#endif
#define SOC_ASP_CODEC_VOICE_UPLINK_CHANNEL_voice_uplink_rdata_START (0)
#define SOC_ASP_CODEC_VOICE_UPLINK_CHANNEL_voice_uplink_rdata_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
