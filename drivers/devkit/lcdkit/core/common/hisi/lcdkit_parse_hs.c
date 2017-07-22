#include "hisi_fb.h"
#include "lcdkit_panel.h"
#include "lcdkit_dbg.h"
/***********************************************************
*function definition
***********************************************************/

void lcdkit_parse_platform_dts(struct device_node* np,  void* pdata)
{
    struct hisi_panel_info* pinfo;

    pinfo = (struct hisi_panel_info*) pdata;

    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-orientation", &pinfo->orientation);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-bpp", &pinfo->bpp);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-bgrfmt", &pinfo->bgr_fmt);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-bl-type", &pinfo->bl_set_type);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-blmin", &pinfo->bl_min);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-blmax", &pinfo->bl_max);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-bl-def", &pinfo->bl_default);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-cmd-type", &pinfo->type);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-panel-frc-enable", &pinfo->frc_enable);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-panel-esd-skip-mipi-check", &pinfo->esd_skip_mipi_check);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-panel-ifbctype", &pinfo->ifbc_type);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-panel-bl-ic-ctrl-type", &pinfo->bl_ic_ctrl_mode);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-fps-updt-only", &pinfo->fps_updt_panel_only, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-fps-updt-support", &pinfo->fps_updt_support, 0);

    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-pxl-clk", &pinfo->pxl_clk_rate);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-pxl-clk-div", &pinfo->pxl_clk_rate_div);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-panel-dirt-updt-support", &pinfo->dirty_region_updt_support);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-panel-dsi-upt-support", &pinfo->dsi_bit_clk_upt_support);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-vsyn-ctr-type", &pinfo->vsync_ctrl_type);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-panel-step-support", &pinfo->lcd_uninit_step_support);
	OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-xcc-set-in-isr-support", &pinfo->xcc_set_in_isr_support, 0);

    /*effect info*/
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-sbl-support", &pinfo->sbl_support);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-gamma-support", &pinfo->gamma_support);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-gmp-support", &pinfo->gmp_support);

    OF_PROPERTY_READ_U8_DEFAULT(np,"hw,lcdkit-color-temp-support",&pinfo->color_temperature_support,0);
    OF_PROPERTY_READ_U8_DEFAULT(np,"hw,lcdkit-comform-mode-support",&pinfo->comform_mode_support,0);
    OF_PROPERTY_READ_U8_DEFAULT(np,"hw,lcdkit-cinema-mode-support",&pinfo->cinema_mode_support,0);
    OF_PROPERTY_READ_U8_DEFAULT(np,"hw,lcdkit-xcc-support",&pinfo->xcc_support,0);

    OF_PROPERTY_READ_U8_DEFAULT(np,"hw,lcdkit-hiace-support",&pinfo->hiace_support,0);
    OF_PROPERTY_READ_U8_DEFAULT(np,"hw,lcdkit-panel-ce-support",&pinfo->panel_effect_support,0);
    OF_PROPERTY_READ_U8_DEFAULT(np,"hw,lcdkit-arsr1p-sharpness-support",&pinfo->arsr1p_sharpness_support,0);

    if(pinfo->hiace_support){
        OF_PROPERTY_READ_U32_DEFAULT(np,"hw,lcdkit-iglobal-hist-black-pos",&pinfo->hiace_param.iGlobalHistBlackPos,0);
        OF_PROPERTY_READ_U32_DEFAULT(np,"hw,lcdkit-iglobal-hist-white-pos",&pinfo->hiace_param.iGlobalHistWhitePos,0);
        OF_PROPERTY_READ_U32_DEFAULT(np,"hw,lcdkit-iglobal-hist-black-weight",&pinfo->hiace_param.iGlobalHistBlackWeight,0);
        OF_PROPERTY_READ_U32_DEFAULT(np,"hw,lcdkit-iglobal-hist-white-weight",&pinfo->hiace_param.iGlobalHistWhiteWeight,0);
        OF_PROPERTY_READ_U32_DEFAULT(np,"hw,lcdkit-iglobal-hist-zero-cut-ratio",&pinfo->hiace_param.iGlobalHistZeroCutRatio,0);
        OF_PROPERTY_READ_U32_DEFAULT(np,"hw,lcdkit-iglobal-hist-slope-cut-ratio",&pinfo->hiace_param.iGlobalHistSlopeCutRatio,0);
        OF_PROPERTY_READ_U32_DEFAULT(np,"hw,lcdkit-imax-lcd-luminance",&pinfo->hiace_param.iMaxLcdLuminance,0);
        OF_PROPERTY_READ_U32_DEFAULT(np,"hw,lcdkit-imin-lcd-luminance",&pinfo->hiace_param.iMinLcdLuminance,0);
        lcdkit_info.panel_infos.hiace_chCfgName = (char*)of_get_property(np, "hw,lcdkit-cfg-name", NULL);
        strncpy(pinfo->hiace_param.chCfgName, lcdkit_info.panel_infos.hiace_chCfgName, sizeof(pinfo->hiace_param.chCfgName)-1);
        LCDKIT_INFO("chname:%s\n",lcdkit_info.panel_infos.hiace_chCfgName);
    }

    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-prefix-ce-support", &pinfo->prefix_ce_support);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-prefix-sharp-one-d-support", &pinfo->prefix_sharpness1D_support);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-prefix-sharp-two-d-support", &pinfo->prefix_sharpness2D_support);

    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-acm-support", &pinfo->acm_support);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-acm-ce-support", &pinfo->acm_ce_support);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-acm-valid-num", &pinfo->acm_valid_num);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_hh0", &pinfo->r0_hh);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_lh0", &pinfo->r0_lh);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_hh1", &pinfo->r1_hh);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_lh1", &pinfo->r1_lh);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_hh2", &pinfo->r2_hh);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_lh2", &pinfo->r2_lh);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_hh3", &pinfo->r3_hh);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_lh3", &pinfo->r3_lh);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_hh4", &pinfo->r4_hh);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_lh4", &pinfo->r4_lh);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_hh5", &pinfo->r5_hh);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_lh5", &pinfo->r5_lh);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_hh6", &pinfo->r6_hh);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-r_lh6", &pinfo->r6_lh);

    /*sbl info*/
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-stren-limit", &pinfo->smart_bl.strength_limit);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-cal-a", &pinfo->smart_bl.calibration_a);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-cal-b", &pinfo->smart_bl.calibration_b);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-cal-c", &pinfo->smart_bl.calibration_c);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-cal-d", &pinfo->smart_bl.calibration_d);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-tf-ctl", &pinfo->smart_bl.t_filter_control);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-bl-min", &pinfo->smart_bl.backlight_min);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-bl-max", &pinfo->smart_bl.backlight_max);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-bl-scale", &pinfo->smart_bl.backlight_scale);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-am-light-min", &pinfo->smart_bl.ambient_light_min);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-filter-a", &pinfo->smart_bl.filter_a);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-filter-b", &pinfo->smart_bl.filter_b);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-logo-left", &pinfo->smart_bl.logo_left);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-logo-top", &pinfo->smart_bl.logo_top);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-variance-intensity-space", &pinfo->smart_bl.variance_intensity_space);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-slope-max", &pinfo->smart_bl.slope_max);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-sbl-slope-min", &pinfo->smart_bl.slope_min);

    /*ldi info*/
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-h-back-porch", &pinfo->ldi.h_back_porch);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-h-front-porch", &pinfo->ldi.h_front_porch);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-h-pulse-width", &pinfo->ldi.h_pulse_width);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-v-back-porch", &pinfo->ldi.v_back_porch);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-v-front-porch", &pinfo->ldi.v_front_porch);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-v-pulse-width", &pinfo->ldi.v_pulse_width);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-ldi-hsync-plr", &pinfo->ldi.hsync_plr);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-ldi-vsync-plr", &pinfo->ldi.vsync_plr);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-ldi-pixel-clk-plr", &pinfo->ldi.pixelclk_plr);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-ldi-data-en-plr", &pinfo->ldi.data_en_plr);

    /*mipi info*/
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-mipi-lane-nums", &pinfo->mipi.lane_nums);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-mipi-color-mode", &pinfo->mipi.color_mode);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-mipi-vc", &pinfo->mipi.vc);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-burst-mode", &pinfo->mipi.burst_mode);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-dsi-bit-clk", &pinfo->mipi.dsi_bit_clk);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-max-esc-clk", &pinfo->mipi.max_tx_esc_clk);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-dsi-bit-clk-val-a", &pinfo->mipi.dsi_bit_clk_val1);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-dsi-bit-clk-val-b", &pinfo->mipi.dsi_bit_clk_val2);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-dsi-bit-clk-val-c", &pinfo->mipi.dsi_bit_clk_val3);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-dsi-bit-clk-val-d", &pinfo->mipi.dsi_bit_clk_val4);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-dsi-bit-clk-val-e", &pinfo->mipi.dsi_bit_clk_val5);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-dsi-bit-clk-upt", &pinfo->mipi.dsi_bit_clk_upt);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-mipi-non-continue-enable", &pinfo->mipi.non_continue_en);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-clk-post-adjust", &pinfo->mipi.clk_post_adjust);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-clk-pre-adjust", &pinfo->mipi.clk_pre_adjust);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-clk-t-hs-prepare-adjust", &pinfo->mipi.clk_t_hs_prepare_adjust);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-clk-t-lpx-adjust", &pinfo->mipi.clk_t_lpx_adjust);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-clk-t-hs-trail-adjust", &pinfo->mipi.clk_t_hs_trial_adjust);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-clk-t-hs-exit-adjust", &pinfo->mipi.clk_t_hs_exit_adjust);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-mipi-clk-t-hs-zero-adjust", &pinfo->mipi.clk_t_hs_zero_adjust);

    OF_PROPERTY_READ_DIRTYREGION_INFO_RETURN(np, "hw,lcdkit-dirt-left-align", &pinfo->dirty_region_info.left_align);
    OF_PROPERTY_READ_DIRTYREGION_INFO_RETURN(np, "hw,lcdkit-dirt-right-align", &pinfo->dirty_region_info.right_align);
    OF_PROPERTY_READ_DIRTYREGION_INFO_RETURN(np, "hw,lcdkit-dirt-top-align", &pinfo->dirty_region_info.top_align);
    OF_PROPERTY_READ_DIRTYREGION_INFO_RETURN(np, "hw,lcdkit-dirt-bott-align", &pinfo->dirty_region_info.bottom_align);
    OF_PROPERTY_READ_DIRTYREGION_INFO_RETURN(np, "hw,lcdkit-dirt-width-align", &pinfo->dirty_region_info.w_align);
    OF_PROPERTY_READ_DIRTYREGION_INFO_RETURN(np, "hw,lcdkit-dirt-height-align", &pinfo->dirty_region_info.h_align);
    OF_PROPERTY_READ_DIRTYREGION_INFO_RETURN(np, "hw,lcdkit-dirt-width-min", &pinfo->dirty_region_info.w_min);
    OF_PROPERTY_READ_DIRTYREGION_INFO_RETURN(np, "hw,lcdkit-dirt-height-min", &pinfo->dirty_region_info.h_min);
    OF_PROPERTY_READ_DIRTYREGION_INFO_RETURN(np, "hw,lcdkit-dirt-top-start", &pinfo->dirty_region_info.top_start);
    OF_PROPERTY_READ_DIRTYREGION_INFO_RETURN(np, "hw,lcdkit-dirt-bott-start", &pinfo->dirty_region_info.bottom_start);

    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-panel-bl-type", &lcdkit_info.panel_infos.bl_type);

}

