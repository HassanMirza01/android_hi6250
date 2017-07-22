#include "hisi_fb.h"
#include "lcdkit_panel.h"
#include "lcdkit_dbg.h"
#include "lcdkit_disp.h"
#include "lcdkit_parse.h"

/*
*name:lcdkit_info_init
*function:lcd_panel_info init
*@pinfo:lcd panel info
*/
void lcdkit_info_init(void* pdata)
{
    struct hisi_panel_info* pinfo;

    pinfo = (struct hisi_panel_info*) pdata;
    pinfo->xres = lcdkit_info.panel_infos.xres;
    pinfo->yres = lcdkit_info.panel_infos.yres;
    pinfo->width = lcdkit_info.panel_infos.width;
    pinfo->height = lcdkit_info.panel_infos.height;
    pinfo->esd_enable = lcdkit_info.panel_infos.esd_support;
    pinfo->bl_min = lcdkit_info.panel_infos.bl_level_min;
    pinfo->bl_max = lcdkit_info.panel_infos.bl_level_max;

    pinfo->pxl_clk_rate *= 1000000UL;
    pinfo->mipi.max_tx_esc_clk *= 1000000;

    /*for fps*/
    if (lcdkit_info.panel_infos.fps_func_switch){
        pinfo->fps = 60;
        pinfo->fps_updt = 60;
    }

    if (pinfo->bl_set_type == BL_SET_BY_BLPWM)
    {
        pinfo->blpwm_input_ena = 1;
    }

    if (pinfo->ifbc_type == IFBC_TYPE_ORISE3X)
    {
        pinfo->ifbc_cmp_dat_rev0 = 0;
        pinfo->ifbc_cmp_dat_rev1 = 0;
        pinfo->ifbc_auto_sel = 1;
        pinfo->ifbc_orise_ctr = 1;

        //FIXME:
        pinfo->pxl_clk_rate_div = 3;
        pinfo->ifbc_orise_ctl = IFBC_ORISE_CTL_FRAME;
    }

    if (pinfo->ifbc_type == IFBC_TYPE_VESA3X_SINGLE) {
        pinfo->pxl_clk_rate_div = 3;

        /* dsc parameter info */
        pinfo->vesa_dsc.bits_per_component = 8;
        pinfo->vesa_dsc.bits_per_pixel = 8;
        pinfo->vesa_dsc.slice_width = 719;
        pinfo->vesa_dsc.slice_height = 31;

        pinfo->vesa_dsc.initial_xmit_delay = 512;
        pinfo->vesa_dsc.first_line_bpg_offset = 12;
        pinfo->vesa_dsc.mux_word_size = 48;

        /*  DSC_CTRL */
        pinfo->vesa_dsc.block_pred_enable = 1;
        pinfo->vesa_dsc.linebuf_depth = 9;

        /* RC_PARAM3 */
        pinfo->vesa_dsc.initial_offset = 6144;

        /* FLATNESS_QP_TH */
        pinfo->vesa_dsc.flatness_min_qp = 3;
        pinfo->vesa_dsc.flatness_max_qp = 12;

        /* DSC_PARAM4 */
        pinfo->vesa_dsc.rc_edge_factor = 0x6;
        pinfo->vesa_dsc.rc_model_size = 8192;

        /* DSC_RC_PARAM5: 0x330b0b */
        pinfo->vesa_dsc.rc_tgt_offset_lo = (0x330b0b >> 20) & 0xF;
        pinfo->vesa_dsc.rc_tgt_offset_hi = (0x330b0b >> 16) & 0xF;
        pinfo->vesa_dsc.rc_quant_incr_limit1 = (0x330b0b >> 8) & 0x1F;
        pinfo->vesa_dsc.rc_quant_incr_limit0 = (0x330b0b >> 0) & 0x1F;

        /* DSC_RC_BUF_THRESH0: 0xe1c2a38 */
        pinfo->vesa_dsc.rc_buf_thresh0 = (0xe1c2a38 >> 24) & 0xFF;
        pinfo->vesa_dsc.rc_buf_thresh1 = (0xe1c2a38 >> 16) & 0xFF;
        pinfo->vesa_dsc.rc_buf_thresh2 = (0xe1c2a38 >> 8) & 0xFF;
        pinfo->vesa_dsc.rc_buf_thresh3 = (0xe1c2a38 >> 0) & 0xFF;

        /* DSC_RC_BUF_THRESH1: 0x46546269 */
        pinfo->vesa_dsc.rc_buf_thresh4 = (0x46546269 >> 24) & 0xFF;
        pinfo->vesa_dsc.rc_buf_thresh5 = (0x46546269 >> 16) & 0xFF;
        pinfo->vesa_dsc.rc_buf_thresh6 = (0x46546269 >> 8) & 0xFF;
        pinfo->vesa_dsc.rc_buf_thresh7 = (0x46546269 >> 0) & 0xFF;

        /* DSC_RC_BUF_THRESH2: 0x7077797b */
        pinfo->vesa_dsc.rc_buf_thresh8 = (0x7077797b >> 24) & 0xFF;
        pinfo->vesa_dsc.rc_buf_thresh9 = (0x7077797b >> 16) & 0xFF;
        pinfo->vesa_dsc.rc_buf_thresh10 = (0x7077797b >> 8) & 0xFF;
        pinfo->vesa_dsc.rc_buf_thresh11 = (0x7077797b >> 0) & 0xFF;

        /* DSC_RC_BUF_THRESH3: 0x7d7e0000 */
        pinfo->vesa_dsc.rc_buf_thresh12 = (0x7d7e0000 >> 24) & 0xFF;
        pinfo->vesa_dsc.rc_buf_thresh13 = (0x7d7e0000 >> 16) & 0xFF;

        /* DSC_RC_RANGE_PARAM0: 0x1020100 */
        pinfo->vesa_dsc.range_min_qp0 = (0x1020100 >> 27) & 0x1F;
        pinfo->vesa_dsc.range_max_qp0 = (0x1020100 >> 22) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset0 = (0x1020100 >> 16) & 0x3F;
        pinfo->vesa_dsc.range_min_qp1 = (0x1020100 >> 11) & 0x1F;
        pinfo->vesa_dsc.range_max_qp1 = (0x1020100 >> 6) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset1 = (0x1020100 >> 0) & 0x3F;

        /* DSC_RC_RANGE_PARAM1: 0x94009be */
        pinfo->vesa_dsc.range_min_qp2 = (0x94009be >> 27) & 0x1F;
        pinfo->vesa_dsc.range_max_qp2 = (0x94009be >> 22) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset2 = (0x94009be >> 16) & 0x3F;
        pinfo->vesa_dsc.range_min_qp3 = (0x94009be >> 11) & 0x1F;
        pinfo->vesa_dsc.range_max_qp3 = (0x94009be >> 6) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset3 = (0x94009be >> 0) & 0x3F;

        /* DSC_RC_RANGE_PARAM2, 0x19fc19fa */
        pinfo->vesa_dsc.range_min_qp4 = (0x19fc19fa >> 27) & 0x1F;
        pinfo->vesa_dsc.range_max_qp4 = (0x19fc19fa >> 22) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset4 = (0x19fc19fa >> 16) & 0x3F;
        pinfo->vesa_dsc.range_min_qp5 = (0x19fc19fa >> 11) & 0x1F;
        pinfo->vesa_dsc.range_max_qp5 = (0x19fc19fa >> 6) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset5 = (0x19fc19fa >> 0) & 0x3F;

        /* DSC_RC_RANGE_PARAM3, 0x19f81a38 */
        pinfo->vesa_dsc.range_min_qp6 = (0x19f81a38 >> 27) & 0x1F;
        pinfo->vesa_dsc.range_max_qp6 = (0x19f81a38 >> 22) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset6 = (0x19f81a38 >> 16) & 0x3F;
        pinfo->vesa_dsc.range_min_qp7 = (0x19f81a38 >> 11) & 0x1F;
        pinfo->vesa_dsc.range_max_qp7 = (0x19f81a38 >> 6) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset7 = (0x19f81a38 >> 0) & 0x3F;

        /* DSC_RC_RANGE_PARAM4, 0x1a781ab6 */
        pinfo->vesa_dsc.range_min_qp8 = (0x1a781ab6 >> 27) & 0x1F;
        pinfo->vesa_dsc.range_max_qp8 = (0x1a781ab6 >> 22) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset8 = (0x1a781ab6 >> 16) & 0x3F;
        pinfo->vesa_dsc.range_min_qp9 = (0x1a781ab6 >> 11) & 0x1F;
        pinfo->vesa_dsc.range_max_qp9 = (0x1a781ab6 >> 6) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset9 = (0x1a781ab6 >> 0) & 0x3F;

        /* DSC_RC_RANGE_PARAM5, 0x2af62b34 */
        pinfo->vesa_dsc.range_min_qp10 = (0x2af62b34 >> 27) & 0x1F;
        pinfo->vesa_dsc.range_max_qp10 = (0x2af62b34 >> 22) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset10 = (0x2af62b34 >> 16) & 0x3F;
        pinfo->vesa_dsc.range_min_qp11 = (0x2af62b34 >> 11) & 0x1F;
        pinfo->vesa_dsc.range_max_qp11 = (0x2af62b34 >> 6) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset11 = (0x2af62b34 >> 0) & 0x3F;

        /* DSC_RC_RANGE_PARAM6, 0x2b743b74 */
        pinfo->vesa_dsc.range_min_qp12 = (0x2b743b74 >> 27) & 0x1F;
        pinfo->vesa_dsc.range_max_qp12 = (0x2b743b74 >> 22) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset12 = (0x2b743b74 >> 16) & 0x3F;
        pinfo->vesa_dsc.range_min_qp13 = (0x2b743b74 >> 11) & 0x1F;
        pinfo->vesa_dsc.range_max_qp13 = (0x2b743b74 >> 6) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset13 = (0x2b743b74 >> 0) & 0x3F;

        /* DSC_RC_RANGE_PARAM7, 0x6bf40000 */
        pinfo->vesa_dsc.range_min_qp14 = (0x6bf40000 >> 27) & 0x1F;
        pinfo->vesa_dsc.range_max_qp14 = (0x6bf40000 >> 22) & 0x1F;
        pinfo->vesa_dsc.range_bpg_offset14 = (0x6bf40000 >> 16) & 0x3F;

        if (pinfo->pxl_clk_rate_div > 1) {
            pinfo->ldi.h_back_porch /= pinfo->pxl_clk_rate_div;
            pinfo->ldi.h_front_porch /= pinfo->pxl_clk_rate_div;
            pinfo->ldi.h_pulse_width /= pinfo->pxl_clk_rate_div;
        }
        /* IFBC Setting end */
    }


    /*ce rely on acm*/
    if (pinfo->acm_support == 0)
    {
        pinfo->acm_ce_support = 0;
    }

}

int lcdkit_cmds_to_dsi_cmds(struct lcdkit_dsi_panel_cmds* lcdkit_cmds, struct dsi_cmd_desc* cmd)
{
    struct dsi_cmd_desc* dsi_cmd;
    int i = 0;

    dsi_cmd = cmd;

    if (lcdkit_cmds == NULL)
    {
        LCDKIT_ERR("lcdkit_cmds is null point!\n");
        return -EINVAL;
    }

    lcdkit_dump_cmds(lcdkit_cmds);

    for (i = 0; i < lcdkit_cmds->cmd_cnt; i++)
    {
        dsi_cmd[i].dtype = lcdkit_cmds->cmds[i].dtype;
        dsi_cmd[i].vc =  lcdkit_cmds->cmds[i].vc;
        dsi_cmd[i].wait =  lcdkit_cmds->cmds[i].wait;
        dsi_cmd[i].waittype =  lcdkit_cmds->cmds[i].waittype;
        dsi_cmd[i].dlen =  lcdkit_cmds->cmds[i].dlen;
        dsi_cmd[i].payload = lcdkit_cmds->cmds[i].payload;
    }

    return 0;

}

/*
 *  dsi send cmds
*/
void lcdkit_dsi_tx(void* pdata, struct lcdkit_dsi_panel_cmds* cmds)
{
    struct hisi_fb_data_type* hisifd = NULL;
    char __iomem* mipi_dsi0_base = NULL;
    int ret = 0;
    struct dsi_cmd_desc* cmd;

    if (!cmds || cmds->cmd_cnt <= 0){
        LCDKIT_DEBUG("cmd cnt is 0!\n");
        return ;
    }

    cmd = (struct dsi_cmd_desc*)kzalloc(sizeof(struct dsi_cmd_desc) * cmds->cmd_cnt, GFP_KERNEL);
    if (!cmd)
    {
        LCDKIT_ERR("cmd kzalloc fail!\n");
        return ;
    }
    ret = lcdkit_cmds_to_dsi_cmds(cmds, cmd);

    if (ret)
    {
        LCDKIT_ERR("lcdkit_cmds convert fail!\n");
        kfree(cmd);
        return ;
    }

    hisifd = (struct hisi_fb_data_type*) pdata;
    mipi_dsi0_base = hisifd->mipi_dsi0_base;

    ret =  mipi_dsi_cmds_tx(cmd, cmds->cmd_cnt, mipi_dsi0_base);

    kfree(cmd);

    return;

}

void lcdkit_dsi_rx(void* pdata, uint32_t* out, int len, struct lcdkit_dsi_panel_cmds* cmds)
{
    struct hisi_fb_data_type* hisifd = NULL;
    char __iomem* mipi_dsi0_base = NULL;
    int ret = 0;
    struct dsi_cmd_desc* cmd;
    cmd = kzalloc(sizeof(struct dsi_cmd_desc) * cmds->cmd_cnt, GFP_KERNEL);

    ret = lcdkit_cmds_to_dsi_cmds(cmds, cmd);

    if (ret)
    {
        LCDKIT_ERR("lcdkit_cmds convert fail!\n");
        return ;
    }

    hisifd = (struct hisi_fb_data_type*) pdata;
    mipi_dsi0_base = hisifd->mipi_dsi0_base;

    ret = mipi_dsi_cmds_rx(out, cmd, cmds->cmd_cnt, mipi_dsi0_base);

    kfree(cmd);

    return;

}

/*switch lp to hs or hs to lp*/
void lcdkit_switch_hs_lp(void* pdata, bool enable)
{
    struct hisi_fb_data_type* hisifd = NULL;
    char __iomem* mipi_dsi0_base = NULL;

    hisifd = (struct hisi_fb_data_type*) pdata;
    mipi_dsi0_base = hisifd->mipi_dsi0_base;

    if (is_mipi_cmd_panel(hisifd))
    {
        set_reg(mipi_dsi0_base + MIPIDSI_CMD_MODE_CFG_OFFSET, enable, 1, 14);
        set_reg(mipi_dsi0_base + MIPIDSI_CMD_MODE_CFG_OFFSET, enable, 1, 9);
    }
    else
    {
        set_reg(mipi_dsi0_base + MIPIDSI_VID_MODE_CFG_OFFSET, 0x1, 1, 15);
    }

}

void lcdkit_hs_lp_switch(void* pdata, int mode)
{
    struct hisi_fb_data_type* hisifd = NULL;
    char __iomem* mipi_dsi0_base = NULL;

    hisifd = (struct hisi_fb_data_type*) pdata;
    mipi_dsi0_base = hisifd->mipi_dsi0_base;

    switch(mode)
    {
        case LCDKIT_DSI_LP_MODE:
            LCDKIT_INFO("lcdkit switch to lp mode\n");
            /* set mipi in lp mode */
            set_reg(mipi_dsi0_base + MIPIDSI_CMD_MODE_CFG_OFFSET, 0x7f, 7, 8);
            set_reg(mipi_dsi0_base + MIPIDSI_CMD_MODE_CFG_OFFSET, 0xf, 4, 16);
            set_reg(mipi_dsi0_base + MIPIDSI_CMD_MODE_CFG_OFFSET, 0x1, 1, 24);
            break;
        case LCDKIT_DSI_HS_MODE:
            LCDKIT_INFO("lcdkit switch to hs mode\n");
            /* set mipi in hs mode */
            set_reg(mipi_dsi0_base + MIPIDSI_CMD_MODE_CFG_OFFSET, 0x0, 7, 8);
            set_reg(mipi_dsi0_base + MIPIDSI_CMD_MODE_CFG_OFFSET, 0x0, 4, 16);
            set_reg(mipi_dsi0_base + MIPIDSI_CMD_MODE_CFG_OFFSET, 0x0, 1, 24);
            break;
        default:
            LCDKIT_ERR("lcdkit set unknown mipi mode:%d\n", mode);
            break;
    }
}

void lcdkit_mipi_dsi_max_return_packet_size(void* pdata, struct lcdkit_dsi_cmd_desc* cm)
{
    uint32_t hdr = 0;
    struct hisi_fb_data_type* hisifd = NULL;
    char __iomem* mipi_dsi0_base = NULL;

    hisifd = (struct hisi_fb_data_type*) pdata;
    mipi_dsi0_base = hisifd->mipi_dsi0_base;

    /* fill up header */
    hdr |= DSI_HDR_DTYPE(cm->dtype);
    hdr |= DSI_HDR_VC(cm->vc);
    hdr |= DSI_HDR_WC(cm->dlen);
    set_reg(mipi_dsi0_base + MIPIDSI_GEN_HDR_OFFSET, hdr, 24, 0);
}

int lcdkit_mipi_dsi_read_compare(struct mipi_dsi_read_compare_data* data,
                                 void* pdata)
{
    uint32_t* read_value = NULL;
    uint32_t* expected_value = NULL;
    uint32_t* read_mask = NULL;
    char** reg_name = NULL;
    int log_on = 0;
    struct lcdkit_dsi_cmd_desc* cmds = NULL;
    int cnt = 0;
    int cnt_not_match = 0;
    int ret = 0;
    int i;

    BUG_ON(data == NULL);

    read_value = data->read_value;
    expected_value = data->expected_value;
    read_mask = data->read_mask;
    reg_name = data->reg_name;
    log_on = data->log_on;

    cmds = data->cmds;
    cnt = data->cnt;

    lcdkit_dsi_rx(pdata, read_value, 1, cmds);

    for (i = 0; i < cnt; i++)
    {
        if (log_on)
        {
            LCDKIT_INFO("Read reg %s: 0x%x, value = 0x%x\n",
                        reg_name[i], cmds[i].payload[0], read_value[i]);
        }

        if (expected_value[i] != (read_value[i] & read_mask[i]))
        {
            cnt_not_match++;
        }
    }

    return cnt_not_match;
}

bool lcdkit_is_cmd_panel(void)
{
    if ( lcdkit_info.panel_infos.lcd_disp_type & (PANEL_MIPI_CMD | PANEL_DUAL_MIPI_CMD) )
    { 
        return true; 
    }

    return false;
}

void lcdkit_updt_porch(struct platform_device* pdev, int scence)
{
    struct hisi_fb_data_type* hisifd = NULL;
    struct hisi_panel_info* pinfo = NULL;

    BUG_ON(pdev == NULL);
    hisifd = platform_get_drvdata(pdev);
    BUG_ON(hisifd == NULL);
    pinfo = &(hisifd->panel_info);

    switch (scence)
    {
        case LCDKIT_FPS_SCENCE_IDLE:
            pinfo->ldi_updt.h_back_porch = lcdkit_info.panel_infos.fps_30_porch_param.buf[0];
            pinfo->ldi_updt.h_front_porch = lcdkit_info.panel_infos.fps_30_porch_param.buf[1];
            pinfo->ldi_updt.h_pulse_width = lcdkit_info.panel_infos.fps_30_porch_param.buf[2];
            pinfo->ldi_updt.v_back_porch = lcdkit_info.panel_infos.fps_30_porch_param.buf[3];
            pinfo->ldi_updt.v_front_porch = lcdkit_info.panel_infos.fps_30_porch_param.buf[4];
            pinfo->ldi_updt.v_pulse_width = lcdkit_info.panel_infos.fps_30_porch_param.buf[5];
            LCDKIT_INFO("scence is LCDKIT_FPS_SCENCE_IDLE, framerate is 30fps\n");
            break;

        case LCDKIT_FPS_SCENCE_EBOOK:
            pinfo->ldi_updt.h_back_porch = lcdkit_info.panel_infos.fps_55_porch_param.buf[0];
            pinfo->ldi_updt.h_front_porch = lcdkit_info.panel_infos.fps_55_porch_param.buf[1];
            pinfo->ldi_updt.h_pulse_width = lcdkit_info.panel_infos.fps_55_porch_param.buf[2];
            pinfo->ldi_updt.v_back_porch = lcdkit_info.panel_infos.fps_55_porch_param.buf[3];
            pinfo->ldi_updt.v_front_porch = lcdkit_info.panel_infos.fps_55_porch_param.buf[4];
            pinfo->ldi_updt.v_pulse_width = lcdkit_info.panel_infos.fps_55_porch_param.buf[5];
            LCDKIT_INFO("scence is LCD_FPS_SCENCE_EBOOK, framerate is 55fps!\n");
            break;

        default:
            pinfo->ldi_updt.h_back_porch = lcdkit_info.panel_infos.fps_60_porch_param.buf[0];
            pinfo->ldi_updt.h_front_porch = lcdkit_info.panel_infos.fps_60_porch_param.buf[1];
            pinfo->ldi_updt.h_pulse_width = lcdkit_info.panel_infos.fps_60_porch_param.buf[2];
            pinfo->ldi_updt.v_back_porch = lcdkit_info.panel_infos.fps_60_porch_param.buf[3];
            pinfo->ldi_updt.v_front_porch = lcdkit_info.panel_infos.fps_60_porch_param.buf[4];
            pinfo->ldi_updt.v_pulse_width = lcdkit_info.panel_infos.fps_60_porch_param.buf[5];
            LCDKIT_INFO("scence is default, framerate is 60fps!\n");
            break;
    }
}

void lcdkit_lp2hs_mipi_test(void* pdata)
{
    u32 lp2hs_mipi_check_read_value[1] = {0};

    struct lcdkit_dsi_read_compare_data g_lp2hs_mipi_check_data =
    {
        .read_value = lp2hs_mipi_check_read_value,
        .expected_value = lcdkit_info.panel_infos.lp2hs_mipi_check_expected_value,
        .read_mask = lcdkit_info.panel_infos.lp2hs_mipi_check_read_mask,
        .reg_name = "power mode",
        .log_on = 1,
        .cmds = &lcdkit_info.panel_infos.lp2hs_mipi_check_read_cmds,
        .cnt = lcdkit_info.panel_infos.lp2hs_mipi_check_read_cmds.cmd_cnt,
    };

    if (lcdkit_info.panel_infos.lp2hs_mipi_check_support)
    {
        lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.lp2hs_mipi_check_write_cmds);

        if (!lcdkit_mipi_dsi_read_compare(&g_lp2hs_mipi_check_data, pdata))
        {
            LCDKIT_INFO("lp2hs test OK\n");
            lcdkit_info.panel_infos.g_lp2hs_mipi_check_result = true;
        }
        else
        {
            LCDKIT_INFO("lp2hs test fail\n");
            lcdkit_info.panel_infos.g_lp2hs_mipi_check_result = false;
        }
    }
}

void lcdkit_effect_switch_ctrl(void* pdata, bool ctrl)
{
#if 0
    struct hisi_fb_data_type* hisifd = NULL;
    struct hisi_panel_info* pinfo = NULL;
    char __iomem* mipi_dsi0_base = NULL;
    char __iomem* dpp_base = NULL;
    char __iomem* lcp_base = NULL;
    char __iomem* gamma_base = NULL;

    hisifd = (struct hisi_fb_data_type*) pdata;

    if ( NULL == hisifd )
    {
        LCDKIT_ERR("NULL point!\n");
        return;
    }

    mipi_dsi0_base = hisifd->mipi_dsi0_base;
    dpp_base = hisifd->dss_base + DSS_DPP_OFFSET;
    lcp_base = hisifd->dss_base + DSS_DPP_LCP_OFFSET;
    gamma_base = hisifd->dss_base + DSS_DPP_GAMA_OFFSET;

    pinfo = &(hisifd->panel_info);

    if (ctrl)
    {
        if (pinfo->gamma_support == 1){
            HISI_FB_INFO("disable gamma\n");
            /* disable de-gamma */
            set_reg(lcp_base + LCP_DEGAMA_EN, 0x0, 1, 0);
            /* disable gamma */
            set_reg(gamma_base + GAMA_EN, 0x0, 1, 0);
        }
        if (pinfo->gmp_support == 1) {
            HISI_FB_INFO("disable gmp\n");
            /* disable gmp */
            set_reg(dpp_base + LCP_GMP_BYPASS_EN, 0x1, 1, 0);
        }
        if (pinfo->xcc_support == 1) {
            HISI_FB_INFO("disable xcc\n");
            /* disable xcc */
            set_reg(lcp_base + LCP_XCC_BYPASS_EN, 0x1, 1, 0);
        }

        /* disable bittext */
        set_reg(hisifd->dss_base + DSS_DPP_BITEXT0_OFFSET + BIT_EXT0_CTL, 0x0, 1, 0);
    } else {
        if (pinfo->gamma_support == 1) {
            HISI_FB_INFO("enable gamma\n");
            /* enable de-gamma */
            set_reg(lcp_base + LCP_DEGAMA_EN, 0x1, 1, 0);
            /* enable gamma */
            set_reg(gamma_base + GAMA_EN, 0x1, 1, 0);
        }
        if (pinfo->gmp_support == 1) {
            HISI_FB_INFO("enable gmp\n");
            /* enable gmp */
            set_reg(dpp_base + LCP_GMP_BYPASS_EN, 0x0, 1, 0);
        }
        if (pinfo->xcc_support == 1) {
            HISI_FB_INFO("enable xcc\n");
            /* enable xcc */
            set_reg(lcp_base + LCP_XCC_BYPASS_EN, 0x0, 1, 0);
        }
        /* enable bittext */
        set_reg(hisifd->dss_base + DSS_DPP_BITEXT0_OFFSET + BIT_EXT0_CTL, 0x1, 1, 0);
    }
#endif
}

int adc_get_value(int channel)
{
    // hisi_adc_get_value(channel);
    return 0;
}

int lcdkit_fake_update_bl(void *pdata, uint32_t bl_level)
{
    int ret = 0;
    struct hisi_fb_data_type *hisifd = NULL;

    hisifd = (struct hisi_fb_data_type *)pdata;

    BUG_ON(hisifd == NULL);

    if (bl_level > 0) {
        /*enable bl gpio*/
//        if (bl_enable_flag) {
//            gpio_direction_output(gpio_lcd_bl_enable, 1);
//        }
        mdelay(2);
        /* backlight on */
//        hisi_lcd_backlight_on(pdev);

        HISI_FB_INFO("set backlight to %d\n", bl_level);
        ret = hisi_blpwm_set_backlight(hisifd, bl_level);
    } else {
        ret = hisi_blpwm_set_backlight(hisifd, 0);
        /* backlight off */
//        hisi_lcd_backlight_off(pdev);
        /*disable bl gpio*/
//        if (bl_enable_flag) {
//            gpio_direction_output(gpio_lcd_bl_enable, 0);
//        }
    }
}

int buf_trans(const char* inbuf, int inlen, char** outbuf, int* outlen)
{
    char* buf;
    int i;
    int bufsize = inlen;

    if (!inbuf)
    {
        LCDKIT_ERR("inbuf is null point!\n");
        return -ENOMEM;
    }

    /*The property is 4bytes long per element in cells: <>*/
    bufsize = bufsize / 4;
    /*If use bype property: [], this division should be removed*/
    buf = kzalloc(sizeof(char) * bufsize, GFP_KERNEL);

    if (!buf)
    {
        LCDKIT_ERR("buf is null point!\n");
        return -ENOMEM;
    }

    //For use cells property: <>
    for (i = 0; i < bufsize; i++)
    {
        buf[i] = inbuf[i * 4 + 3];
    }

    *outbuf = buf;
    *outlen = bufsize;

    return 0;
}

ssize_t lcdkit_jdi_nt35696_5p5_gram_check_show(void* pdata, char* buf)
{

    ssize_t ret = 0;
    struct hisi_fb_data_type *hisifd = NULL;
    char __iomem *mipi_dsi0_base = NULL;
    uint32_t rd1[LCDKIT_CHECKSUM_SIZE] = {0};
    uint32_t rd2[LCDKIT_CHECKSUM_SIZE] = {0};
    int i = 0;
    char cmd3_enable[] = {0xFF, 0xF0};
    char crc_dc_select[] = {0xEA, 0x00};
    char crc_mipi_select1[] = {0x7B, 0x00};
    char crc_mipi_select2[] = {0x7B, 0x20};
    char checksum_read[] = {0x73};
    //0:success; 1:fail
    int checksum_result = 0;
    struct dsi_cmd_desc packet_size_set_cmd = {DTYPE_MAX_PKTSIZE, 0, 10, WAIT_TYPE_US, 1, NULL};
    struct dsi_cmd_desc lcd_cmd3_enable_cmds[] = {
        {DTYPE_DCS_WRITE1, 0, 50, WAIT_TYPE_MS,
            sizeof(cmd3_enable), cmd3_enable},
        {DTYPE_DCS_WRITE1, 0, 50, WAIT_TYPE_MS,
            sizeof(crc_dc_select), crc_dc_select},
    };
    struct dsi_cmd_desc lcd_crc_mipi_select1_cmds[] = {
        {DTYPE_DCS_WRITE1, 0, 10, WAIT_TYPE_MS,
            sizeof(crc_mipi_select1), crc_mipi_select1},
    };
    struct dsi_cmd_desc lcd_crc_mipi_select2_cmds[] = {
        {DTYPE_DCS_WRITE1, 0, 10, WAIT_TYPE_MS,
            sizeof(crc_mipi_select2), crc_mipi_select2},
    };
    struct dsi_cmd_desc lcd_check_reg[] = {
        {DTYPE_DCS_READ, 0, 20, WAIT_TYPE_US,
            sizeof(checksum_read), checksum_read},
    };

    static uint32_t expected_checksum1[3][8] = {
        {0xaa, 0x8b, 0x4, 0x5e, 0xab, 0xcb, 0xef, 0x5e}, //runningtest1
        {0x65, 0xd0, 0xe0, 0x02, 0xd8, 0x98, 0xfa, 0x4e}, //runningtest2
        {0x17, 0x40, 0xe3, 0xd8, 0xf0, 0x36, 0xa8, 0x2e}, //runningtest3
    };

    static uint32_t expected_checksum2[3][8] = {
        {0x66, 0x73, 0xa3, 0xea, 0xd0, 0x26, 0x5f, 0xbf}, //runningtest1
        {0x96, 0x0a, 0xea, 0x96, 0xa2, 0x04, 0x1d, 0x52}, //runningtest2
        {0x75, 0xa6, 0x28, 0xde, 0x88, 0xad, 0xe8, 0xb5}, //runningtest3
    };

    HISI_FB_INFO("%s +\n", __func__);
    switch (lcdkit_info.panel_infos.checksum_pic_num){
        case 0:
        case 1:
        case 2:
            HISI_FB_INFO("%s start check gram checksum:[%d]\n", __func__, lcdkit_info.panel_infos.checksum_pic_num);
            break;
        default:
            HISI_FB_ERR("%s gram checksum pic num unknown(%d)\n", __func__, lcdkit_info.panel_infos.checksum_pic_num);
            //unknown pic, return fail
            ret = snprintf(buf, PAGE_SIZE, "1\n");
            return ret;
    }

    hisifd = (struct hisi_fb_data_type*) pdata;

    mipi_dsi0_base = hisifd->mipi_dsi0_base;

    mipi_dsi_max_return_packet_size(&packet_size_set_cmd, mipi_dsi0_base);
    mipi_dsi_cmds_tx(lcd_cmd3_enable_cmds, \
        ARRAY_SIZE(lcd_cmd3_enable_cmds), mipi_dsi0_base);
    mipi_dsi_cmds_tx(lcd_crc_mipi_select1_cmds, \
        ARRAY_SIZE(lcd_crc_mipi_select1_cmds), mipi_dsi0_base);
    for (i = 0; i < LCDKIT_CHECKSUM_SIZE; i++) {
        char *data = lcd_check_reg[0].payload;
        *data = 0x73 + i;
        mipi_dsi_cmds_rx((rd1 + i), lcd_check_reg, \
            ARRAY_SIZE(lcd_check_reg), mipi_dsi0_base);

        if (rd1[i] != expected_checksum1[lcdkit_info.panel_infos.checksum_pic_num][i]) {
            HISI_FB_ERR("rd[%d] = 0x%x, pic_num=%d, expected = 0x%x\n", i, rd1[i], lcdkit_info.panel_infos.checksum_pic_num,
                expected_checksum1[lcdkit_info.panel_infos.checksum_pic_num][i]);
            checksum_result++;
        }
    }
    HISI_FB_INFO("0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x, pic_num=%d\n", \
            rd1[0], rd1[1], rd1[2], rd1[3], rd1[4], rd1[5], rd1[6], rd1[7], lcdkit_info.panel_infos.checksum_pic_num);

    mipi_dsi_cmds_tx(lcd_crc_mipi_select2_cmds, \
        ARRAY_SIZE(lcd_crc_mipi_select2_cmds), mipi_dsi0_base);
    for (i = 0; i < LCDKIT_CHECKSUM_SIZE; i++) {
        char *data = lcd_check_reg[0].payload;
        *data = 0x73 + i;
        mipi_dsi_cmds_rx((rd2 + i), lcd_check_reg, \
            ARRAY_SIZE(lcd_check_reg), mipi_dsi0_base);

        if (rd2[i] != expected_checksum2[lcdkit_info.panel_infos.checksum_pic_num][i]) {
            HISI_FB_ERR("rd[%d] = 0x%x, pic_num=%d, expected = 0x%x\n", i, rd2[i], lcdkit_info.panel_infos.checksum_pic_num,
                expected_checksum2[lcdkit_info.panel_infos.checksum_pic_num][i]);
            checksum_result++;
        }
    }
    HISI_FB_INFO("0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x, pic_num=%d\n", \
            rd2[0], rd2[1], rd2[2], rd2[3], rd2[4], rd2[5], rd2[6], rd2[7], lcdkit_info.panel_infos.checksum_pic_num);

    if (checksum_result){
        HISI_FB_ERR("checksum_result:%d\n", checksum_result);
        checksum_result = 1;
    }

    ret = snprintf(buf, PAGE_SIZE, "%d\n", checksum_result);
    HISI_FB_INFO("fb%d, -.\n", hisifd->index);
    return ret;
}

void lcdkit_fps_scence_adaptor_handle(struct platform_device* pdev, uint32_t scence)
{
    struct hisi_fb_data_type *hisifd = NULL;
    struct hisi_panel_info *pinfo = NULL;

    LCDKIT_DEBUG("+.\n");
    if (NULL == pdev) {
        LCDKIT_ERR("pdev NULL Pointer!\n");
        return;
    }
    hisifd = platform_get_drvdata(pdev);
    if (NULL == hisifd){
        LCDKIT_ERR("hisifd NULL Pointer!\n");
        return;
    }
    pinfo = &(hisifd->panel_info);
    switch (scence)
    {
        case LCD_FPS_SCENCE_NORMAL:
            pinfo->fps_updt = LCD_FPS_60;
            LCDKIT_DEBUG("scence is LCD_FPS_SCENCE_NORMAL, framerate is 60fps!\n");
            break;

        case LCD_FPS_SCENCE_IDLE:
            pinfo->fps_updt = LCD_FPS_30;
            LCDKIT_DEBUG("scence is LCD_FPS_SCENCE_IDLE, framerate is 30fps!\n");
            break;

        /*
        * Open dss dynamic fps function, dss 30fps, panel 30fps, 
        * and dfr closed if panel support
        */
        case LCD_FPS_SCENCE_FORCE_30FPS:
            LCDKIT_INFO("scence is  LCD_FPS_SCENCE_FORCE_30FPS\n");
            pinfo->fps_updt_support = 1;
            pinfo->fps_updt_panel_only = 1;
            pinfo->fps_updt = LCD_FPS_30;
            pinfo->fps_updt_force_update = 1;
            pinfo->fps_scence = scence;
            break;
        /*
        * Open dss dynamic fps function, dss 30<->60,
        * panel 60fps, and dfr open if panel support
        */
        case LCD_FPS_SCENCE_FUNC_DEFAULT_ENABLE:
            LCDKIT_INFO("scence is  LCD_FPS_SCENCE_FUNC_DEFAULT_ENABLE\n");
            pinfo->fps_updt_support = 1;
            pinfo->fps_updt_panel_only = 0;
            pinfo->fps_updt = LCD_FPS_60;
            pinfo->fps_updt_force_update = 1;
            pinfo->fps_scence = scence;
            break;
        /*
        * Close dss dynamic fps function, dss 60fps, panel 60fps,
        * and dfr closed if panel support
        */
        case LCD_FPS_SCENCE_FUNC_DEFAULT_DISABLE:
            LCDKIT_INFO("scence is  LCD_FPS_SCENCE_FUNC_DEFAULT_DISABLE\n");
            pinfo->fps_updt_force_update = 1;
            pinfo->fps_updt = LCD_FPS_60;
            pinfo->fps_scence = scence;
            break;

        default:
            pinfo->fps_updt = LCD_FPS_60;
            LCDKIT_INFO("scence is LCD_FPS_SCENCE_NORMAL, framerate is 60fps!\n");
            break;
    }

    LCDKIT_DEBUG("-.\n");
    return;
}

void lcdkit_fps_updt_adaptor_handle(void* pdata)
{
    struct hisi_fb_data_type* hisifd = NULL;
    struct hisi_panel_info *pinfo = NULL;
    struct platform_device *pdev = NULL;

    pdev = (struct platform_device *)pdata;
    if (NULL == pdev) {
        LCDKIT_ERR("pdev NULL Pointer!\n");
        return;
    }

    hisifd = platform_get_drvdata(pdev);
    if (NULL == hisifd){
        LCDKIT_ERR("hisifd NULL Pointer!\n");
        return;
    }

    pinfo = &(hisifd->panel_info);
    switch(pinfo->fps_scence)
    {
        /* USE fps_to_60_cmds for one cmd */
        case LCD_FPS_SCENCE_FUNC_DEFAULT_DISABLE:
            LCDKIT_INFO("fps to 60 and disable dfr\n");
            if (LCDKIT_DSI_LP_MODE
                == lcdkit_info.panel_infos.fps_to_60_cmds.link_state)
                lcdkit_hs_lp_switch(hisifd, LCDKIT_DSI_LP_MODE);
            lcdkit_dsi_tx(hisifd, &lcdkit_info.panel_infos.fps_to_60_cmds);
            if (LCDKIT_DSI_LP_MODE
                == lcdkit_info.panel_infos.fps_to_60_cmds.link_state)
                lcdkit_hs_lp_switch(hisifd, LCDKIT_DSI_HS_MODE);

            LCDKIT_INFO("set fps_updt_support = 0, fps_updt_panel_only = 0\n");
            pinfo->fps_updt_support = 0;
            pinfo->fps_updt_panel_only = 0;
            break;
        /* USE dfr_enable_cmds for one cmd */
        case LCD_FPS_SCENCE_FUNC_DEFAULT_ENABLE:
            LCDKIT_INFO("fps to 60 and enable dfr\n");
            if (LCDKIT_DSI_LP_MODE
                == lcdkit_info.panel_infos.dfr_enable_cmds.link_state)
                lcdkit_hs_lp_switch(hisifd, LCDKIT_DSI_LP_MODE);
            lcdkit_dsi_tx(hisifd, &lcdkit_info.panel_infos.dfr_enable_cmds);
            if (LCDKIT_DSI_LP_MODE
                == lcdkit_info.panel_infos.dfr_enable_cmds.link_state)
                lcdkit_hs_lp_switch(hisifd, LCDKIT_DSI_HS_MODE);
            break;
        /* USE fps_to_30_cmds for one cmd */
        case LCD_FPS_SCENCE_FORCE_30FPS:
            LCDKIT_INFO("fps to 30 and disable dfr\n");
            if (LCDKIT_DSI_LP_MODE
                == lcdkit_info.panel_infos.fps_to_30_cmds.link_state)
                lcdkit_hs_lp_switch(hisifd, LCDKIT_DSI_LP_MODE);
            lcdkit_dsi_tx(hisifd, &lcdkit_info.panel_infos.fps_to_30_cmds);
            if (LCDKIT_DSI_LP_MODE
                == lcdkit_info.panel_infos.fps_to_30_cmds.link_state)
                lcdkit_hs_lp_switch(hisifd, LCDKIT_DSI_HS_MODE);
            break;
        default:
            LCDKIT_INFO("unknown scence:%d\n", pinfo->fps_scence);
            break;
    }

    if (pinfo->fps_updt_force_update)
    {
        LCDKIT_INFO("set fps_updt_force_update = 0\n");
        pinfo->fps_updt_force_update = 0;
    }
    return;
}
