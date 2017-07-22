#include "lcdkit_panel.h"
#include "lcdkit_dbg.h"
#include "lcdkit_parse.h"
#include "huawei_ts_kit.h"

/***********************************************************
*function definition
***********************************************************/
/*
*name:hw_lcd_parse_array_data
*function:parse panel data from dtsi
*@np:device tree node
*@name:parse name
*@out:output data
*/
static int lcdkit_parse_array_data(struct device_node* np,
                                   char* name, struct lcdkit_array_data* out)
{
    const char* data;
    int blen = 0, len = 0, ret;
    char* buf;

    data = of_get_property(np, name, &blen);

    ret = buf_trans(data, blen, &buf, &len);

    if (ret)
    {
        LCDKIT_ERR("buffer trans fail!\n");
        return -ENOMEM;
    }

    out->buf = buf;
    out->cnt = len;
    return 0;
}

static int lcdkit_parse_arrays_data(struct device_node* np,
                                    char* name, struct lcdkit_arrays_data* out)
{
    int i, cnt, ret = 0;
    char* buf, *bp;
    const char* data;
    int len, blen, length;

    data = of_get_property(np, name, &blen);

    if (!data)
    {
        LCDKIT_ERR("%s: parse property %s error\n", __func__, name);
        return -ENOMEM;
    }

    ret = buf_trans(data, blen, &buf, &len);
    if (ret)
    {
        LCDKIT_ERR("buffer trans fail!\n");
        return -ENOMEM;
    }

    cnt = 0;
    bp = buf;
    length = len;

    while (length > 1)
    {
        len = *bp;
        bp++;
        length--;

        if (len > length)
        {
            LCDKIT_ERR("data length = %x error\n", len);
            goto exit_free;
        }

        bp += len;
        length -= len;
        cnt++;
    }

    if (length != 0)
    {
        LCDKIT_ERR("dts data parse error! data len = %d\n", len);
        goto exit_free;
    }

    out->cnt = cnt;
    out->arry_data = kzalloc(sizeof(struct lcdkit_array_data) * cnt, GFP_KERNEL);

    if (!out->arry_data)
    {
        goto exit_free;
    }

    bp = buf;

    for (i = 0; i < cnt; i++)
    {
        len = *bp;
        out->arry_data[i].cnt = len;
        bp++;

        out->arry_data[i].buf = bp;
        bp += len;
    }

    return 0;

exit_free:
    kfree(buf);
    return -ENOMEM;
}

static int lcdkit_parse_dcs_cmds(struct device_node* np, char* cmd_key,
                                 char* link_key, struct lcdkit_dsi_panel_cmds* pcmds)
{
    const char* data = NULL;
    int blen = 0, len = 0, buflen = 0, ret = 0;
    char* buf = NULL, *bp = NULL;
    struct lcdkit_dsi_cmd_desc* dchdr = NULL;
    int i = 0, cnt = 0;

    memset(pcmds, 0, sizeof(struct lcdkit_dsi_panel_cmds));
    data = of_get_property(np, cmd_key, &blen);

    if (!data)
    {
        LCDKIT_ERR(" failed, key = %s\n", cmd_key);
        return -ENOMEM;
    }

    ret = buf_trans(data, blen, &buf, &buflen);

    if (ret)
    {
        LCDKIT_ERR("buffer trans fail!\n");
        return -ENOMEM;
    }

    /* scan dcs commands */
    bp = buf;
    len = buflen;

    while (len >= (sizeof(*dchdr) - sizeof(dchdr->payload)))
    {
        dchdr = (struct lcdkit_dsi_cmd_desc*)bp;
        //dchdr->dlen = ntohs(dchdr->dlen);
        bp += (sizeof(*dchdr) - sizeof(dchdr->payload));
        len -= (sizeof(*dchdr) - sizeof(dchdr->payload));

        if (dchdr->dlen > len)
        {
            LCDKIT_ERR("cmd = 0x%x parse error, len = %d\n", dchdr->dtype, dchdr->dlen);
            goto exit_free;
        }

        bp += dchdr->dlen;
        len -= dchdr->dlen;
        cnt++;
    }

    if (len != 0)
    {
        LCDKIT_ERR("dcs_cmd parse error! cmd len = %d\n", len);
        goto exit_free;
    }

    pcmds->cmds = kzalloc(cnt * sizeof(struct lcdkit_dsi_cmd_desc), GFP_KERNEL);

    if (!pcmds->cmds)
    {
        goto exit_free;
    }

    pcmds->cmd_cnt = cnt;
    pcmds->buf = buf;
    pcmds->blen = buflen;

    bp = buf;
    len = buflen;

    for (i = 0; i < cnt; i++)
    {
        dchdr = (struct lcdkit_dsi_cmd_desc*)bp;
        len -= (sizeof(*dchdr) - sizeof(dchdr->payload));
        bp += (sizeof(*dchdr) - sizeof(dchdr->payload));
        pcmds->cmds[i] = *dchdr;
        pcmds->cmds[i].payload = bp;
        bp += dchdr->dlen;
        len -= dchdr->dlen;
    }

    pcmds->flags = LCDKIT_CMD_REQ_COMMIT;
    /*Set default link state to LP Mode*/
    pcmds->link_state = LCDKIT_DSI_LP_MODE;

    if (link_key)
    {
        data = of_get_property(np, link_key, NULL);

        if (data && !strcmp(data, "dsi_hs_mode"))
        {
            pcmds->link_state = LCDKIT_DSI_HS_MODE;
        }
        else
        {
            pcmds->link_state = LCDKIT_DSI_LP_MODE;
        }
    }

    return 0;

exit_free:
    kfree(buf);
    return -ENOMEM;

}

/*
     public lcd par

*/
void lcdkit_parse_panel_dts(struct device_node* np)
{
    int ret = 0;

    lcdkit_info.panel_infos.panel_name = (char*)of_get_property(np, "hw,lcdkit-panel-name", NULL);
//	lcdkit_info.panel_infos.support_check_mode = (char*)of_get_property(np, "hw,lcdkit-panel-check-mode", NULL);
    /*parse panel info*/
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-panel-type", &lcdkit_info.panel_infos.panel_type);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-xres", &lcdkit_info.panel_infos.xres);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-yres", &lcdkit_info.panel_infos.yres);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-width", &lcdkit_info.panel_infos.width);
    OF_PROPERTY_READ_U32_RETURN(np, "hw,lcdkit-panel-height", &lcdkit_info.panel_infos.height);
    OF_PROPERTY_READ_U8_RETURN(np, "hw,lcdkit-panel-cmd-type", &lcdkit_info.panel_infos.lcd_disp_type);

    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-cabc-support", &lcdkit_info.panel_infos.cabc_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-inversion-support", &lcdkit_info.panel_infos.inversion_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-scan-support", &lcdkit_info.panel_infos.scan_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-esd-support", &lcdkit_info.panel_infos.esd_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-check-reg-support", &lcdkit_info.panel_infos.check_reg_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-display-region-support", &lcdkit_info.panel_infos.display_region_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-checksum-support", &lcdkit_info.panel_infos.checksum_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-dynamic-sram-check-support", &lcdkit_info.panel_infos.dynamic_sram_check_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-mipi-detect-support", &lcdkit_info.panel_infos.mipi_detect_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-lptohs-mipi-check-support", &lcdkit_info.panel_infos.lp2hs_mipi_check_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-fps-func-switch", &lcdkit_info.panel_infos.fps_func_switch, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-current-detect-support", &lcdkit_info.panel_infos.current_detect_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-lv-detect-support", &lcdkit_info.panel_infos.lv_detect_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-pt-test-support", &lcdkit_info.panel_infos.PT_test_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-acl-ctrl-support", &lcdkit_info.panel_infos.acl_ctrl_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-hbm-ctrl-support", &lcdkit_info.panel_infos.hbm_ctrl_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-hkadc-support", &lcdkit_info.panel_infos.hkadc_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-vr-support", &lcdkit_info.panel_infos.vr_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-shutdown-sleep-support", &lcdkit_info.panel_infos.shutdown_sleep_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-ce-support", &lcdkit_info.panel_infos.ce_support, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-display-on-effect-support",&lcdkit_info.panel_infos.display_effect_on_support,0);

    /*Parse panel on cmds*/
    ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-on-command", "hw,lcdkit-panel-on-command-state",
                                &lcdkit_info.panel_infos.display_on_cmds);

    /*Parse panel on cmds*/
    ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-display-on-command", "hw,lcdkit-panel-on-command-state",
                                &lcdkit_info.panel_infos.display_on_in_backlight_cmds);

    /*Parse panel off cmds*/
    ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-off-command", "hw,lcdkit-panel-off-command-state",
                                &lcdkit_info.panel_infos.display_off_cmds);

    /*Parse backlight cmds*/
    ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-backlight-command", "hw,lcdkit-panel-backlight-command-state",
                                &lcdkit_info.panel_infos.backlight_cmds);

    if (lcdkit_info.panel_infos.cabc_support)
    {
        /*Parse cabc off cmds*/
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-cabc-off-command", "hw,lcdkit-panel-cabc-off-command-state",
                                    &lcdkit_info.panel_infos.cabc_off_cmds);
        /*Parse cabc ui cmds*/
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-cabc-ui-command", "hw,lcdkit-panel-cabc-ui-command-state",
                                    &lcdkit_info.panel_infos.cabc_ui_cmds);
        /*Parse cabc still cmds*/
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-cabc-still-command", "hw,lcdkit-panel-cabc-still-command-state",
                                    &lcdkit_info.panel_infos.cabc_still_cmds);
        /*Parse cabc moving cmds*/
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-cabc-moving-command", "hw,lcdkit-panel-cabc-moving-command-state",
                                    &lcdkit_info.panel_infos.cabc_moving_cmds);
    }
    else
    {
        LCDKIT_INFO("cabc is not support!\n");
    }

    if (lcdkit_info.panel_infos.inversion_support)
    {
        /*Parse Dot inversion  cmds*/
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-dot-inversion-command", "hw,lcdkit-dot-inversion-cmds-state",
                                    &lcdkit_info.panel_infos.dot_inversion_cmds);
        /*Parse column inversion  cmds*/
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-column-inversion-command", "hw,lcdkit-column-inversion-cmds-state",
                                    &lcdkit_info.panel_infos.column_inversion_cmds);
    }
    else
    {
        LCDKIT_INFO("inversion is not support!\n");
    }

    if (lcdkit_info.panel_infos.scan_support)
    {
        /*Parse Forword Scan  cmds*/
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-forword-scan-command", "hw,lcdkit-forword-scan-cmds-state",
                                    &lcdkit_info.panel_infos.forword_scan_cmds);
        /*Parse Revert Scan cmds*/
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-revert-scan-command", "hw,lcdkit-revert-scan-cmds-state",
                                    &lcdkit_info.panel_infos.revert_scan_cmds);
    }
    else
    {
        LCDKIT_INFO("scan is not support!\n");
    }

    if (lcdkit_info.panel_infos.display_region_support)
    {
        /*Parse Dirty Region cmds*/
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-display-region-command", "hw,lcdkit-panel-display-region-command-state",
                                    &lcdkit_info.panel_infos.display_region_cmds);
    }
    else
    {
        LCDKIT_INFO("display_region is not support!\n");
    }

    if (lcdkit_info.panel_infos.esd_support)
    {
        /*esd check*/
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-esd-reg-command", "hw,lcdkit-panel-esd-reg-command-state", &lcdkit_info.panel_infos.esd_cmds);
        ret = lcdkit_parse_array_data(np, "hw,lcdkit-panel-esd-value", &lcdkit_info.panel_infos.esd_value);
    }
    else
    {
        LCDKIT_INFO("esd is not support!\n");
    }

    if (lcdkit_info.panel_infos.check_reg_support)
    {
        /*mipi check reg*/
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-check-reg-command", "hw,lcdkit-panel-check-reg-command-state", &lcdkit_info.panel_infos.check_reg_cmds);
        ret = lcdkit_parse_array_data(np, "hw,lcdkit-panel-check-reg-value", &lcdkit_info.panel_infos.check_reg_value);
    }
    else
    {
        LCDKIT_INFO("check reg is not support!\n");
    }

    if (lcdkit_info.panel_infos.mipi_detect_support)
    {
        /*mipi check reg*/
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-mipi-detect-command", "hw,lcdkit-panel-mipi-detect-command-state",  &lcdkit_info.panel_infos.mipi_detect_cmds);
        ret = lcdkit_parse_array_data(np, "hw,lcdkit-panel-mipi-detect-value", &lcdkit_info.panel_infos.mipi_detect_value);
        ret = lcdkit_parse_array_data(np, "hw,lcdkit-panel-mipi-detect-mask", &lcdkit_info.panel_infos.mipi_detect_mask);
    }
    else
    {
        LCDKIT_INFO("mipi detect is not support!\n");
    }

    if (lcdkit_info.panel_infos.checksum_support)
    {
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-checksum-command", "hw,lcdkit-panel-checksum-command-state",  &lcdkit_info.panel_infos.checksum_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-checksum-enter-command", "hw,lcdkit-panel-checksum-enter-command-state",  &lcdkit_info.panel_infos.checksum_enter_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-checksum-exit-command", "hw,lcdkit-panel-checksum-exit-command-state",  &lcdkit_info.panel_infos.checksum_exit_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-checksum-enable-command", "hw,lcdkit-panel-checksum-enable-command-state",  &lcdkit_info.panel_infos.checksum_enable_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-checksum-disable-command", "hw,lcdkit-panel-checksum-disable-command-state",  &lcdkit_info.panel_infos.checksum_disable_cmds);
        ret = lcdkit_parse_arrays_data(np, "hw,lcdkit-panel-checksum-value", &lcdkit_info.panel_infos.checksum_value);
        ret = lcdkit_parse_arrays_data(np, "hw,lcdkit-panel-checksum-read-again", &lcdkit_info.panel_infos.checksum_read_again);
    }
    else
    {
        LCDKIT_INFO("checksum is not support!\n");
    }

    if (lcdkit_info.panel_infos.dynamic_sram_check_support)
    {
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-dynamic-sram-check-command", "hw,lcdkit-panel-dynamic-sram-check-command-state",  &lcdkit_info.panel_infos.dynamic_sram_check_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-dynamic-sram-check-enter-command", "hw,lcdkit-panel-dynamic-sram-check-enter-command-state",  &lcdkit_info.panel_infos.dynamic_sram_check_enter_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-dynamic-sram-check-exit-command", "hw,lcdkit-panel-dynamic-sram-check-exit-command-state",  &lcdkit_info.panel_infos.dynamic_sram_check_exit_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-dynamic-sram-check-enable-command", "hw,lcdkit-panel-dynamic-sram-check-enable-command-state",  &lcdkit_info.panel_infos.dynamic_sram_check_enable_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-dynamic-sram-check-disable-command", "hw,lcdkit-panel-dynamic-sram-check-disable-command-state",  &lcdkit_info.panel_infos.dynamic_sram_check_disable_cmds);
        ret = lcdkit_parse_arrays_data(np, "hw,lcdkit-panel-dynamic-sram-check-value", &lcdkit_info.panel_infos.dynamic_sram_check_value);
    }
    else
    {
        LCDKIT_INFO("dynamic_sram_check is not support!\n");
    }

    if (lcdkit_info.panel_infos.fps_func_switch)
    {
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-fps-to-thirty-command", "hw,lcdkit-panel-fps-to-thirty-command-state",  &lcdkit_info.panel_infos.fps_to_30_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-fps-to-sixty-command", "hw,lcdkit-panel-fps-to-sixty-command-state",  &lcdkit_info.panel_infos.fps_to_60_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-dfr-enable-command", "hw,lcdkit-panel-dfr-enable-command-state",  &lcdkit_info.panel_infos.dfr_enable_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-dfr-disable-command", "hw,lcdkit-panel-dfr-disable-command-state",  &lcdkit_info.panel_infos.dfr_disable_cmds);
        if(!lcdkit_is_cmd_panel())
        {
            ret = lcdkit_parse_array_data(np, "hw,lcdkit-panel-fps-to-thirty-value", &lcdkit_info.panel_infos.fps_30_porch_param);
            ret = lcdkit_parse_array_data(np, "hw,lcdkit-panel-fps-to-sixty-value", &lcdkit_info.panel_infos.fps_60_porch_param);
        }
    }
    else
    {
        LCDKIT_INFO("fps_updt is not support!\n");
    }

    if (lcdkit_info.panel_infos.acl_ctrl_support)
    {
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-acl-enable-command", "hw,lcdkit-panel-acl-enable-command-state",  &lcdkit_info.panel_infos.acl_enable_cmds);
    }
    else
    {
        LCDKIT_INFO("acl_ctrl is not support!\n");
    }

    if (lcdkit_info.panel_infos.hbm_ctrl_support)
    {
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-hbm-enable-command", "hw,lcdkit-panel-hbm-enable-command-state",  &lcdkit_info.panel_infos.hbm_enable_cmds);
    }
    else
    {
        LCDKIT_INFO("hbm_ctrl is not support!\n");
    }

    if ( lcdkit_info.panel_infos.vr_support )
    {
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-vr-mode-enable-command", "hw,lcdkit-panel-vr-mode-enable-command-state",  &lcdkit_info.panel_infos.vr_mode_enable_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-vr-mode-disable-command", "hw,lcdkit-panel-vr-mode-disable-command-state",  &lcdkit_info.panel_infos.vr_mode_disable_cmds);
    }
    else
    {
        LCDKIT_INFO("vr mode is not support!\n");
    }

    if ( lcdkit_info.panel_infos.current_detect_support )
    {
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-current-detect-enter-command", "hw,lcdkit-panel-current-detect-enter-command-state",  &lcdkit_info.panel_infos.current_detect_enter_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-current-detect-exit-command", "hw,lcdkit-panel-current-detect-exit-command-state",  &lcdkit_info.panel_infos.current_detect_exit_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-current-detect-command", "hw,lcdkit-panel-current-detect-command-state",  &lcdkit_info.panel_infos.current_detect_cmds);
        ret = lcdkit_parse_array_data(np, "hw,lcdkit-panel-current-mask",  &lcdkit_info.panel_infos.current_mask);
    }
    else
    {
        LCDKIT_INFO("current detect is not support!\n");
    }

    if ( lcdkit_info.panel_infos.lv_detect_support )
    {
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-lv-detect-enter-command", "hw,lcdkit-panel-lv-detect-enter-command-state",  &lcdkit_info.panel_infos.lv_detect_enter_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-lv-detect-exit-command", "hw,lcdkit-panel-lv-detect-exit-command-state",  &lcdkit_info.panel_infos.lv_detect_exit_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-lv-detect-command", "hw,lcdkit-panel-lv-detect-command-state",  &lcdkit_info.panel_infos.lv_detect_cmds);
    }
    else
    {
        LCDKIT_INFO("lv detect is not support!\n");
    }

    if ( lcdkit_info.panel_infos.lp2hs_mipi_check_support )
    {
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-lptohs-mipi-check-write-command", "hw,lcdkit-panel-lptohs-mipi-check-write-command-state",  &lcdkit_info.panel_infos.lp2hs_mipi_check_write_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-lptohs-mipi-check-read-command", "hw,lcdkit-panel-lptohs-mipi-check-read-command-state",  &lcdkit_info.panel_infos.lp2hs_mipi_check_read_cmds);
        OF_PROPERTY_READ_U32_DEFAULT(np, "hw,lcdkit-panel-lptohs-mipi-check-value",  &lcdkit_info.panel_infos.lp2hs_mipi_check_expected_value, 0);
        OF_PROPERTY_READ_U32_DEFAULT(np, "hw,lcdkit-panel-lptohs-mipi-check-mask",  &lcdkit_info.panel_infos.lp2hs_mipi_check_read_mask, 0);
    }
    else
    {
        LCDKIT_INFO("lp2hs mipi check is not support!\n");
    }

    if (lcdkit_info.panel_infos.shutdown_sleep_support)
    {
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-shutdown-sleep_command", "hw,lcdkit-panel-shutdown-sleep_command-state", &lcdkit_info.panel_infos.shutdown_sleep_cmds);
    }
    else
    {
        LCDKIT_INFO("shutdown sleep is not support!\n");
    }

    if(lcdkit_info.panel_infos.ce_support)
    {
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-ce-off-command", "hw,lcdkit-panel-ce-off-command-state",  &lcdkit_info.panel_infos.ce_off_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-ce-srgb-command", "hw,lcdkit-panel-ce-srgb-command-state",  &lcdkit_info.panel_infos.ce_srgb_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-ce-user-command", "hw,lcdkit-panel-ce-user-command-state",  &lcdkit_info.panel_infos.ce_user_cmds);
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-ce-vivid-command", "hw,lcdkit-panel-ce-vivid-command-state",  &lcdkit_info.panel_infos.ce_vivid_cmds);
    }
    else
    {
        LCDKIT_INFO("ce is not support!\n");
    }

    if(lcdkit_info.panel_infos.display_effect_on_support)
    {
        ret = lcdkit_parse_dcs_cmds(np, "hw,lcdkit-panel-display-on-effect-command", "hw,lcdkit-panel-display-on-effect-command-state",  &lcdkit_info.panel_infos.display_effect_on_cmds);
    }
    else
    {
        LCDKIT_INFO("display effect on is not support!\n");
    }

    /*for TP power ctrl*/
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-lcd-type", &g_tskit_ic_type, 1);
    /*for power mode ctrl*/
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-bias-power-ctrl-mode", &lcdkit_info.panel_infos.bias_power_ctrl_mode, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-iovcc-power-ctrl-mode", &lcdkit_info.panel_infos.iovcc_power_ctrl_mode, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-vci-power-ctrl-mode", &lcdkit_info.panel_infos.vci_power_ctrl_mode, 0);
    /*gpio information*/
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-id0-gpio", &lcdkit_info.panel_infos.gpio_lcd_id0, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-id1-gpio", &lcdkit_info.panel_infos.gpio_lcd_id1, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-reset-gpio", &lcdkit_info.panel_infos.gpio_lcd_reset, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-te-gpio", &lcdkit_info.panel_infos.gpio_lcd_te, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-iovcc-gpio", &lcdkit_info.panel_infos.gpio_lcd_iovcc, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-vci-gpio", &lcdkit_info.panel_infos.gpio_lcd_vci, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-vsp-gpio", &lcdkit_info.panel_infos.gpio_lcd_vsp, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-vsn-gpio", &lcdkit_info.panel_infos.gpio_lcd_vsn, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-bl-gpio", &lcdkit_info.panel_infos.gpio_lcd_bl, 0);
    if(lcdkit_info.panel_infos.pcd_errflag_check_support)
    {
        OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-pcd-gpio", &lcdkit_info.panel_infos.gpio_pcd, 0);
        OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-err-flag-gpio", &lcdkit_info.panel_infos.gpio_err_flag, 0);
    }
    /*for vcc and bias setting*/
    OF_PROPERTY_READ_U32_DEFAULT(np, "hw,lcdkit-lcdanalog-vcc", &lcdkit_info.panel_infos.lcdanalog_vcc, 0);
    OF_PROPERTY_READ_U32_DEFAULT(np, "hw,lcdkit-lcdio-vcc", &lcdkit_info.panel_infos.lcdio_vcc, 0);
    OF_PROPERTY_READ_U32_DEFAULT(np, "hw,lcdkit-lcd-bias", &lcdkit_info.panel_infos.lcd_bias, 0);
    OF_PROPERTY_READ_U32_DEFAULT(np, "hw,lcdkit-lcd-vsp", &lcdkit_info.panel_infos.lcd_vsp, 0);
    OF_PROPERTY_READ_U32_DEFAULT(np, "hw,lcdkit-lcd-vsn", &lcdkit_info.panel_infos.lcd_vsn, 0);
    /*for delay of reset*/
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-lcd-rst-first-high", &lcdkit_info.panel_infos.reset_step1_H, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-lcd-rst-low", &lcdkit_info.panel_infos.reset_L, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-lcd-rst-second-high", &lcdkit_info.panel_infos.reset_step2_H, 0);
    /*for reset ctrl*/
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-iovcc-on-is-need-reset", &lcdkit_info.panel_infos.first_reset, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-vsn-on-is-need-reset", &lcdkit_info.panel_infos.second_reset, 0);
    /*for delay of power sequence*/
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-delay-af-vci-on", &lcdkit_info.panel_infos.delay_af_vci_on, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-delay-af-iovcc-on", &lcdkit_info.panel_infos.delay_af_iovcc_on, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-delay-af-bias-on", &lcdkit_info.panel_infos.delay_af_bias_on, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-delay-af-vsp-on", &lcdkit_info.panel_infos.delay_af_vsp_on, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-delay-af-vsn-on", &lcdkit_info.panel_infos.delay_af_vsn_on, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-delay-af-lp11", &lcdkit_info.panel_infos.delay_af_LP11, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-delay-af-tp-reset", &lcdkit_info.panel_infos.delay_af_tp_reset, 0);

    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-delay-af-vsn-off", &lcdkit_info.panel_infos.delay_af_vsn_off, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-delay-af-vsp-off", &lcdkit_info.panel_infos.delay_af_vsp_off, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-delay-af-bias-off", &lcdkit_info.panel_infos.delay_af_bias_off, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-delay-af-iovcc-off", &lcdkit_info.panel_infos.delay_af_iovcc_off, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-delay-af-vci-off", &lcdkit_info.panel_infos.delay_af_vci_off, 0);
    OF_PROPERTY_READ_U32_DEFAULT(np, "hw,lcdkit-delay-before-bl", &lcdkit_info.panel_infos.delay_bf_bl, 0);

    OF_PROPERTY_READ_U32_DEFAULT(np, "hw,lcdkit-panel-blmin", &lcdkit_info.panel_infos.bl_level_min, 0);
    OF_PROPERTY_READ_U32_DEFAULT(np, "hw,lcdkit-panel-blmax", &lcdkit_info.panel_infos.bl_level_max, 0);
    OF_PROPERTY_READ_U32_DEFAULT(np, "hw,lcdkit-panel-bl-maxnit", &lcdkit_info.panel_infos.bl_max_nit, 0);
    OF_PROPERTY_READ_U32_DEFAULT(np, "hw,lcdkit-panel-off-reset-high", &lcdkit_info.panel_infos.panel_off_reset_high, 0);

    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-tp-resume-nosync", &lcdkit_info.panel_infos.tp_resume_no_sync, 0);
    OF_PROPERTY_READ_U8_DEFAULT(np, "hw,lcdkit-panel-display-on-in-backlight", &lcdkit_info.panel_infos.display_on_in_backlight, 0);
    OF_PROPERTY_READ_U32_DEFAULT(np, "hw,lcdkit-effect-support-mode", &lcdkit_info.panel_infos.effect_support_mode, 0);

    return;
}
