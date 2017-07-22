#include "lcdkit_panel.h"
#include "lcdkit_dbg.h"
#include "lcdkit_parse.h"
#include <huawei_ts_kit.h>

struct lcdkit_diff_func lcdkit_diff_func_array[] = {
    {0, lcdkit_jdi_nt35696_5p5_gram_check_show},//checksum show
};

void lcdkit_diff_func_init(struct device_node* np, void* pdata)
{
    if (!strncmp(lcdkit_info.panel_infos.panel_name, "JDI_NT35696 5.5' CMD TFT 1920 x 1080", strlen(lcdkit_info.panel_infos.panel_name))) {
        lcdkit_diff_func_array[0].enable = 1;//checksum enable
    }
}

/***********************************************************
  *function: LCD resoure init, include gpio,regulator,xml parse and so on.
  *input:
  *@np: this node is used to parse DTS file.
  *output: get the pinfo struct
*/
void lcdkit_init(struct device_node* np, void* pdata)
{
    lcdkit_parse_panel_dts(np);
    lcdkit_parse_platform_dts(np, pdata);
    lcdkit_info_init(pdata);
    lcdkit_diff_func_init(np, pdata);

    lcdkit_info.panel_infos.display_on_need_send = false;
}

/***********************************************************
  *function: send display on cmds of LCD
  *input:
  *@pdata: this void point is used to converte to fb data struct.
  *@cmds:  the display on code
*/
void lcdkit_on_cmd(void* pdata, struct lcdkit_dsi_panel_cmds* cmds)
{
    lcdkit_dsi_tx(pdata, cmds);
}

/***********************************************************
  *function:  send display off cmds of LCD
  *input:
  *@pdata: this void point is used to converte to fb data struct.
  *@cmds:  the display off code
*/
void lcdkit_off_cmd(void* pdata, struct lcdkit_dsi_panel_cmds* cmds)
{
    lcdkit_dsi_tx(pdata, cmds);
}

/***********************************************************
  *function: this function is used to get the lcdkit_panel_data struct.
*/
struct lcdkit_panel_data* lcdkit_get_panel_info()
{
    return &lcdkit_info;
}

/***********************************************************
  *function:  this function is used to get the type of LCD
  *output:
  *@buf: get the type of lcd
*/

static ssize_t lcdkit_model_show(char* buf)
{
    return snprintf(buf, PAGE_SIZE, "%s\n", lcdkit_info.panel_infos.panel_name);
}

static ssize_t lcdkit_panel_info_show(char* buf)
{
    ssize_t ret = 0;
    u32 bl_max_nit = 0;


    if( g_ts_kit_lcd_brightness_info ){
        bl_max_nit = g_ts_kit_lcd_brightness_info ;
    } else {
        bl_max_nit = lcdkit_info.panel_infos.bl_max_nit;
    }

    if (lcdkit_is_lcd_panel())
    {
        LCDKIT_INFO("is lcd panel!\n");
        ret = snprintf(buf, PAGE_SIZE, "blmax:%u,blmin:%u,blmax_nit_actual:%d,blmax_nit_standard:%d,lcdtype:%s,\n",
                       lcdkit_info.panel_infos.bl_level_max, lcdkit_info.panel_infos.bl_level_min,\
                       bl_max_nit, lcdkit_info.panel_infos.bl_max_nit,"LCD");
    }
    else if (lcdkit_is_oled_panel())
    {
        ret = snprintf(buf, PAGE_SIZE, "blmax:%u,blmin:%u,blmax_nit_actual:%d,blmax_nit_standard:%d,lcdtype:%s,\n",
                       lcdkit_info.panel_infos.bl_level_max,lcdkit_info.panel_infos.bl_level_min,\
                       bl_max_nit, lcdkit_info.panel_infos.bl_max_nit,  "AMOLED");
    }

    return ret;
}

/***********************************************************
  *function: this function is used to get the cabc mode of LCD
  *output:
  *@buf: get the cabc mode of lcd
*/
static ssize_t lcdkit_cabc_mode_show(char* buf)
{
    return snprintf(buf, PAGE_SIZE, "%d\n", lcdkit_info.panel_infos.cabc_mode);
}

/***********************************************************
 *function: this function is used to set the cabc mode of LCD
  *input:
  *@pdata: this void point is used to converte to fb data struct.
  *@buf: the value of cabc mode to be set
*/
static ssize_t lcdkit_cabc_mode_store(void* pdata, const char* buf)
{
    int ret = 0;
    unsigned long val = 0;

    ret = strict_strtoul(buf, 0, &val);

    if (ret)
    {
        LCDKIT_ERR("invalid data!\n");
        return -EINVAL;
    }

    switch (val)
    {
        case CABC_OFF :
            lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.cabc_off_cmds);
            break;

        case CABC_UI_MODE :
            lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.cabc_ui_cmds);
            break;

        case CABC_STILL_MODE:
            lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.cabc_still_cmds);
            break;

        case CABC_MOVING_MODE :
            lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.cabc_moving_cmds);
            break;

        default:
            return -EINVAL;
    }

    lcdkit_info.panel_infos.cabc_mode = (int)val;
    LCDKIT_INFO("cabc_mode = %d\n", lcdkit_info.panel_infos.cabc_mode);

    return ret;
}

/***********************************************************
  *function: this function is used to get the inversion mode of LCD
  *output:
  *@buf: get the inversion mode of lcd
*/
static ssize_t lcdkit_inversion_mode_show(char* buf)
{
    return snprintf(buf, PAGE_SIZE, "%d\n", lcdkit_info.panel_infos.inversion_mode);
}

/***********************************************************
  *function: this function is used to set the inversion mode of LCD
  *input:
  *@pdata: this void point is used to converte to fb data struct.
  *@buf: the value of inversion mode to be set
*/
static ssize_t lcdkit_inversion_mode_store(void* pdata, const char* buf)
{
    ssize_t ret = 0;
    unsigned long val = 0;

    ret = strict_strtoul(buf, 0, &val);

    if (ret)
    {
        LCDKIT_ERR("invalid data!\n");
        return -EINVAL;
    }

    //switch dot and column inversion
    switch (val)
    {
        case COLUMN_INVERSION :
            lcdkit_switch_hs_lp(pdata, 1);
            lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.column_inversion_cmds);
            lcdkit_switch_hs_lp(pdata, 0);
            break;

        case DOT_INVERSION :
            lcdkit_switch_hs_lp(pdata, 1);
            lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.dot_inversion_cmds);
            lcdkit_switch_hs_lp(pdata, 0);
            break;

        default :
            return -EINVAL;
    }

    lcdkit_info.panel_infos.inversion_mode = (int)val;
    LCDKIT_INFO("inversion_mode = %d\n", lcdkit_info.panel_infos.inversion_mode);

    return ret;
}

/***********************************************************
  *function: this function is used to get the scan mode of LCD
  *output:
  *@buf: get the scan mode of lcd.
*/
static ssize_t lcdkit_scan_mode_show(char* buf)
{
    return snprintf(buf, PAGE_SIZE, "%d\n", lcdkit_info.panel_infos.scan_mode);
}

/***********************************************************
  *function: this function is used to set the inversion mode of LCD
  *input:
  *@pdata: this void point is used to converte to fb data struct.
  *@buf: the value of scan mode to be set
*/
static ssize_t lcdkit_scan_mode_store(void* pdata,  const char* buf)
{
    int ret = 0;
    unsigned long val = 0;

    ret = strict_strtoul(buf, 0, &val);

    if (ret)
    {
        LCDKIT_ERR("invalid data!\n");
        return -EINVAL;
    }

    //switch revert and scan mode
    switch (val)
    {
        case FORWORD_SCAN:
            lcdkit_switch_hs_lp(pdata, 1);
            lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.forword_scan_cmds);
            lcdkit_switch_hs_lp(pdata, 0);
            break;

        case REVERT_SCAN :
            lcdkit_switch_hs_lp(pdata, 1);
            lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.revert_scan_cmds);
            lcdkit_switch_hs_lp(pdata, 0);
            break;

        default:
            return -EINVAL;
    }

    lcdkit_info.panel_infos.scan_mode = (int)val;
    LCDKIT_INFO("scan_mode = %d\n", lcdkit_info.panel_infos.scan_mode);
    return ret;
}

/***********************************************************
  *function: this function is used to check the status reg of LCD
  *input:
  *@pdata: this void point is used to converte to fb data struct.
  *output:
   *@buf: output the check result, "OK" means SUCCESS, "FAIL" means FAIL
*/
static ssize_t lcdkit_check_reg_show(void* pdata, char* buf)
{
    int ret = 0;
    uint32_t read_value[MAX_REG_READ_COUNT];
    uint32_t i = 0;
    char* expect_ptr = NULL;

    expect_ptr = lcdkit_info.panel_infos.check_reg_value.buf;
    lcdkit_dsi_rx(pdata, read_value, 1, &lcdkit_info.panel_infos.check_reg_cmds);

    for (i = 0; i < lcdkit_info.panel_infos.check_reg_cmds.cmd_cnt; i++)
    {
        if (read_value[i] != expect_ptr[i])
        {
            ret = 1;
            LCDKIT_INFO("read_value[%u] = %d, but expect_ptr[%u] = %d!\n", i, read_value[i], i, expect_ptr[i]);
            break;
        }
        LCDKIT_INFO("read_value[%u] = %d same with expect value!\n", i, read_value[i]);
    }

    if (!ret)
    {
        ret = snprintf(buf, PAGE_SIZE, "OK\n");
    }
    else
    {
        ret = snprintf(buf, PAGE_SIZE, "ERROR\n");
    }

    return ret;
}

/***********************************************************
  *function: this function is used to check the esd status reg of LCD
  *input:
  *@pdata: this void point is used to converte to fb data struct.
  *@cmds: the esd reg to be check.
  *output:
*/
static ssize_t lcdkit_check_esd(void* pdata)
{
    ssize_t ret = 0;
    uint32_t read_value[MAX_REG_READ_COUNT];
    uint32_t i = 0;
    char* expect_ptr = NULL;

    if (lcdkit_dbg.g_esd_debug.esd_enable == 1)
    {
        ret = lcdkit_esd_debug(pdata);
        return ret;
    }

    if (lcdkit_dbg.g_esd_debug.esd_recover_test)
    {
        return -EINVAL;
    }

    expect_ptr = lcdkit_info.panel_infos.esd_value.buf;

    lcdkit_dsi_rx(pdata, read_value, 1, &lcdkit_info.panel_infos.esd_cmds);

    for (i = 0; i < lcdkit_info.panel_infos.esd_cmds.cmd_cnt; i++)
    {
        if (read_value[i] != expect_ptr[i])
        {
            LCDKIT_INFO("read_value[%u] = %d, but expect_ptr[%u] = %d!\n", i, read_value[i], i, expect_ptr[i]);
            ret = 1;
            break;
        }
    }

    return ret;
}

/***********************************************************
  *function: this function is used to check the gram status reg of LCD
  *input:
  *@pdata: this void point is used to converte to fb data struct.
  *output:
  *@buf: output the check result, "OK" means SUCCESS, "FAIL" means FAIL
*/
static ssize_t lcdkit_gram_check_show(void* pdata, char* buf)
{
    int ret = 0, i = 0, checksum_result = 1;
    uint32_t rd[LCDKIT_CHECKSUM_SIZE] = {0};
    struct lcdkit_dsi_cmd_desc packet_size_set_cmd = {LCDKIT_DTYPE_MAX_PKTSIZE, 1, 0, 0, 10, LCDKIT_WAIT_TYPE_US, 1, NULL};
    return 0;
    LCDKIT_INFO("enter \n");

    if (lcdkit_diff_func_array[0].enable) {
        ret = lcdkit_diff_func_array[0].lcdkit_show(pdata, buf);
        LCDKIT_INFO("%s\n", buf);
        return ret;
    }

    lcdkit_mipi_dsi_max_return_packet_size(pdata, &packet_size_set_cmd);
    lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.checksum_enter_cmds);

    for (i = 0; i < LCDKIT_CHECKSUM_SIZE; i++)
    {
        char* data = lcdkit_info.panel_infos.checksum_cmds.cmds[i].payload;
        *data = 0x73 + i;

        lcdkit_dsi_rx(pdata, (rd + i), 0, &lcdkit_info.panel_infos.checksum_cmds);

        if (rd[i] != lcdkit_info.panel_infos.checksum_value.arry_data[lcdkit_info.panel_infos.checksum_pic_num].buf[i])
        {
            LCDKIT_ERR("rd[%d] = 0x%x, expect checksum_value[%d]= 0x%x\n", i, rd[i], i, lcdkit_info.panel_infos.checksum_value.arry_data[lcdkit_info.panel_infos.checksum_pic_num].buf[i]);
            checksum_result = 0;
            break;
        }
    }

    ret = snprintf(buf, PAGE_SIZE, "%d\n", checksum_result);
    LCDKIT_INFO("%d %d %d %d %d %d %d %d\n", \
                rd[0], rd[1], rd[2], rd[3], rd[4], rd[5], rd[6], rd[7]);

    lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.checksum_exit_cmds);

    return ret;
}

static ssize_t lcdkit_gram_check_store(void* pdata, const char* buf)
{
    ssize_t ret = 0;
    unsigned long val = 0;
    return 0;
    ret = strict_strtoul(buf, 0, &val);
    if (ret)
    {
        return ret;
    }
    LCDKIT_INFO("val=%ld\n", val);

    if (1 == val)
    {
        lcdkit_info.panel_infos.checksum_support = true;
    }
    else if (0 == val)
    {
        lcdkit_info.panel_infos.checksum_support = false;
    }
    else if (val > 0 && val < 6)
    {
        lcdkit_info.panel_infos.checksum_pic_num = val - 3;
        LCDKIT_INFO("checksum_pic_num is %d\n", lcdkit_info.panel_infos.checksum_pic_num);
        return 0;
    }
    else
    {
        LCDKIT_INFO("val is invaild\n");
    }

    if (lcdkit_info.panel_infos.checksum_support == true)
    {
        lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.checksum_enable_cmds);
        LCDKIT_INFO("Enable checksum\n");
        lcdkit_effect_switch_ctrl(pdata, 1);
    }
    else
    {
        lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.checksum_disable_cmds);
        LCDKIT_INFO("Disable checksum\n");
        lcdkit_effect_switch_ctrl(pdata, 0);
    }

    return ret;
}

static ssize_t lcdkit_dynamic_sram_check_show(void* pdata, char* buf)
{
    int ret = 0, i = 0, checksum_result = 1;
    uint32_t rd[LCDKIT_CHECKSUM_SIZE] = {0};
    struct lcdkit_dsi_cmd_desc packet_size_set_cmd = {LCDKIT_DTYPE_MAX_PKTSIZE, 1, 0, 0, 10, LCDKIT_WAIT_TYPE_US, 1, NULL};

    lcdkit_mipi_dsi_max_return_packet_size(pdata, &packet_size_set_cmd);
    lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.dynamic_sram_check_enter_cmds);

    for (i = 0; i < LCDKIT_CHECKSUM_SIZE; i++)
    {
        char* data = lcdkit_info.panel_infos.checksum_cmds.cmds[i].payload;
        *data = 0x73 + i;

        lcdkit_dsi_rx(pdata, (rd + i), 0, &lcdkit_info.panel_infos.dynamic_sram_check_cmds);

        if (rd[i] != lcdkit_info.panel_infos.dynamic_sram_check_value.arry_data[lcdkit_info.panel_infos.dynamic_sram_check_pic_num].buf[i])
        {
            LCDKIT_ERR("rd[%d] = 0x%x, expect checksum_value[%d]= 0x%x\n", i, rd[i], i, lcdkit_info.panel_infos.dynamic_sram_check_value.arry_data[lcdkit_info.panel_infos.dynamic_sram_check_pic_num].buf[i]);
            checksum_result = 0;
            break;
        }
    }

    ret = snprintf(buf, PAGE_SIZE, "%d\n", checksum_result);
    LCDKIT_INFO("%d %d %d %d %d %d %d %d\n", \
                rd[0], rd[1], rd[2], rd[3], rd[4], rd[5], rd[6], rd[7]);

    lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.dynamic_sram_check_exit_cmds);

    return ret;
}

static ssize_t lcdkit_dynamic_sram_check_store(void* pdata, const char* buf)
{
    ssize_t ret = 0;

    if ((!*buf) || (!strchr("yY1nN0", *buf)))
    {
        LCDKIT_ERR("Input param is error(valid: yY1nN0): %s. \n", buf);
        return -EINVAL;
    }

    lcdkit_info.panel_infos.dynamic_sram_check_pic_num = (int)(buf[1] - '0');
    lcdkit_info.panel_infos.dynamic_sram_check_support = !!strchr("yY1", *buf);

    if ( lcdkit_info.panel_infos.dynamic_sram_check_support == true )
    {
        if (0 <= lcdkit_info.panel_infos.dynamic_sram_check_pic_num && lcdkit_info.panel_infos.dynamic_sram_check_pic_num < LCDKIT_CHECKSUM_PIC_NUM)
        {
            lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.dynamic_sram_check_enable_cmds);

        }
        else
        {
            LCDKIT_ERR("Input param is invalid: %s, pic_num=%d. \n", buf,  lcdkit_info.panel_infos.dynamic_sram_check_pic_num);
            return -EINVAL;
        }

        LCDKIT_DEBUG("Enable dyanmic_sram_check!\n");
    }
    else
    {
        lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.dynamic_sram_check_disable_cmds);
        LCDKIT_DEBUG("Disable dyanmic_sram_check!\n");
    }

    return ret;
}

#if 0
static ssize_t lcd_ic_color_enhancement_mode_show()
{}

static ssize_t lcd_ic_color_enhancement_mode_store()
{}
#endif

static ssize_t lcdkit_ce_mode_show(void* pdata, char* buf)
{
    return snprintf(buf, PAGE_SIZE, "%d\n", lcdkit_info.panel_infos.ce_mode);
}

static ssize_t lcdkit_ce_mode_store(void* pdata, const char* buf, size_t count)
{
    int ret = 0;
    unsigned long val = 0;
    int flag=-1;

    ret = strict_strtoul(buf, 0, &val);
    if(ret)
       return ret;

    flag=(int)val;

    switch(flag)
    {
        case CE_OFF:
            LCDKIT_INFO("ce mode = %d!\n", flag);
            lcdkit_dsi_tx(pdata,&lcdkit_info.panel_infos.ce_off_cmds);
            break;

        case CE_SRGB_MODE:
            LCDKIT_INFO("ce mode = %d!\n", flag);
            lcdkit_dsi_tx(pdata,&lcdkit_info.panel_infos.ce_srgb_cmds);
            break;
        case CE_USER_MODE:
            LCDKIT_INFO("ce mode = %d!\n", flag);
            lcdkit_dsi_tx(pdata,&lcdkit_info.panel_infos.ce_user_cmds);
            break;
        case CE_VIVID_MODE:
            LCDKIT_INFO("ce mode = %d!\n", flag);
            lcdkit_dsi_tx(pdata,&lcdkit_info.panel_infos.ce_vivid_cmds);
            break;
        default:
            LCDKIT_INFO("wrong flag!\n");
            break;
    }

    lcdkit_info.panel_infos.ce_mode = flag;

    return count;

}

static ssize_t lcdkit_sleep_ctrl_show(char* buf)
{
    return  snprintf(buf, PAGE_SIZE, "enable_PT_test=%d, PT_test_support=%d\n",
                     lcdkit_info.panel_infos.enable_PT_test, lcdkit_info.panel_infos.PT_test_support);
}

static ssize_t lcdkit_sleep_ctrl_store(const char* buf)
{
    int ret = 0;
    unsigned long val = 0;

    ret = strict_strtoul(buf, 0, &val);

    if (ret)
    {
        LCDKIT_ERR("invalid parameter!\n");
        return ret;
    }

    if ( lcdkit_info.panel_infos.PT_test_support )
    {
        lcdkit_info.panel_infos.enable_PT_test = val;
    }

    if (lcdkit_info.panel_infos.enable_PT_test == 2)
    {
        g_tskit_pt_station_flag = 1;    //used for pt  current test, tp sleep
    }
    else
    {
        g_tskit_pt_station_flag = 0;    //used for pt  current test, tp power off
    }

    LCDKIT_INFO("exit!\n");
    return ret;

}

static ssize_t lcdkit_lp2hs_mipi_check_show(char* buf)
{
    if (lcdkit_info.panel_infos.g_lp2hs_mipi_check_result)
    {
        return snprintf(buf, PAGE_SIZE, "OK\n");
    }
    else
    {
        return snprintf(buf, PAGE_SIZE, "FAIL\n");
    }
}

static ssize_t lcdkit_lp2hs_mipi_check_store(void* pdata, const char* buf)
{
    int ret = 0;
    unsigned long val = 0;
    int flag = -1;

    ret = strict_strtoul(buf, 0, &val);

    if (ret)
    { return ret; }

    flag = (int)val;

    if (flag == LP2HS_MIPI_TEST_OFF)
    {
        lcdkit_info.panel_infos.lp2hs_mipi_check_support = false;
        lcdkit_info.panel_infos.g_lp2hs_mipi_check_result = false;
        lcdkit_info.panel_infos.lcd_self_testing = false;
        LCDKIT_INFO("lp2hs_mipi test OFF\n");
    }
    else  if (flag == LP2HS_MIPI_TEST_ON)
    {
        lcdkit_info.panel_infos.lp2hs_mipi_check_support = true;
        lcdkit_info.panel_infos.g_lp2hs_mipi_check_result = true;
        lcdkit_info.panel_infos.lcd_self_testing = true;
        LCDKIT_INFO("lp2hs_mipi test ON\n");
    }

    return ret;

}

static ssize_t lcdkit_bist_check_show(void* pdata, char* buf)
{
    ssize_t ret = 0;
#if 0
    if (lcdkit_diff_func_array[0].enable) {
        ret = lcdkit_diff_func_array[0].lcdkit_show(pdata, buf);
        LCDKIT_INFO("%s\n", buf);
        return ret;
    }
#endif
    return ret;
}

/*mipi detect*/
/*function:
  *input:
  *@pdata: this void point is used to converte to fb data struct.
  *output:
  *@buf: output the test result,OK means success, FAIL means fail.
*/
static ssize_t lcdkit_mipi_detect_show(void* pdata, char* buf)
{
    int i = 0;
    ssize_t ret = 0;
    uint32_t read_value[MAX_REG_READ_COUNT] = {0};
    char* expect_ptr = NULL;
    char* mask = NULL;

    expect_ptr = lcdkit_info.panel_infos.mipi_detect_value.buf;
    mask = lcdkit_info.panel_infos.mipi_detect_mask.buf;

    lcdkit_dsi_rx(pdata, read_value, 0, &lcdkit_info.panel_infos.mipi_detect_cmds);

    for (i = 0; i < lcdkit_info.panel_infos.mipi_detect_cmds.cmd_cnt; i++)
    {
        if (read_value[i] != (expect_ptr[i] & mask[i] ))
        {
            ret = snprintf(buf, PAGE_SIZE, "FAIL\n");
            LCDKIT_ERR("read_value[%d] = %d, expect_ptr[%d]=%d ", i, read_value[i], i, expect_ptr[i]);
            ret = 1;
            break;
        }
    }

    if (!ret)
    {
        ret = snprintf(buf, PAGE_SIZE, "OK\n");
    }

    return ret;
}

static ssize_t lcdkit_hkadc_debug_show(char* buf)
{
    return snprintf(buf, PAGE_SIZE, "%d\n", lcdkit_info.panel_infos.hkadc_buf * 4);
}

static ssize_t lcdkit_hkadc_debug_store(const char* buf)
{
    ssize_t ret = 0;
    int channel = 0;

    ret = sscanf(buf, "%u", &channel);

    if (ret <= 0)
    {
        LCDKIT_ERR("ivalid parameter!\n");
        return ret;
    }

    lcdkit_info.panel_infos.hkadc_buf = adc_get_value(channel);
    return ret;
}


static ssize_t lcdkit_pcd_errflag_check(char* buf )
{
    int pcd_gpio = 0;
    int errflag_gpio = 0;
    ssize_t ret = 0;
    u8 result_value = 0;

    pcd_gpio = gpio_get_value_cansleep(lcdkit_info.panel_infos.gpio_pcd);
    errflag_gpio = gpio_get_value_cansleep(lcdkit_info.panel_infos.gpio_err_flag);

    if ((pcd_gpio == 1) && (errflag_gpio == 0))
    {
        result_value = 0; // PCD_ERR_FLAG_SUCCESS
    }
    else if ((pcd_gpio == 0) && (errflag_gpio == 0))
    {
        result_value = 1; //only  PCD_FAIL
    }
    else if ((pcd_gpio == 1) && (errflag_gpio == 1))
    {
        result_value = 2; //only ERRFLAG FAIL
    }
    else if ((pcd_gpio == 0) && (errflag_gpio == 1))
    {
        result_value = 3; //PCD_ERR_FLAG_FAIL
    }
    else
    {
        result_value = 0;
    }

    LCDKIT_INFO("Test cmd is pcd_errflag,and the result_value = %d\n",result_value);
    ret = snprintf(buf, PAGE_SIZE, "%d\n", result_value);
    return ret;

}

static ssize_t lcdkit_amoled_acl_ctrl_show(char* buf)
{
    ssize_t ret = 0;
    ret = snprintf(buf, PAGE_SIZE, "%d\n", lcdkit_info.panel_infos.acl_ctrl_mode);
    return ret;
}

static ssize_t lcdkit_amoled_acl_ctrl_store(void* pdata, const char* buf)
{
    ssize_t ret = 0;
    unsigned long val = 0;
    int flag = 0;

    ret = strict_strtoul(buf, 0, &val);

    if (ret)
    {
        return ret;
    }

    flag = (int)val;

    if (flag == lcdkit_info.panel_infos.acl_ctrl_mode)
    {
        return ret;
    }

    lcdkit_info.panel_infos.acl_ctrl_mode = flag;
    lcdkit_info.panel_infos.acl_enable_cmds.cmds->payload[1] = flag;

    switch (flag)
    {
        case ACL_OFF:
            lcdkit_info.panel_infos.acl_ctrl_mode = flag;
            break;

        case ACL_ON_SET1:
            lcdkit_info.panel_infos.acl_ctrl_mode = flag;
            break;

        case ACL_ON_SET2:
            lcdkit_info.panel_infos.acl_ctrl_mode = flag;
            break;

        case ACL_ON_SET3:
            lcdkit_info.panel_infos.acl_ctrl_mode = flag;
            break;

        default:
            LCDKIT_ERR("check your input parameter !\n");
            return ret;
    }

    lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.acl_enable_cmds);
    return ret;
}

static ssize_t lcdkit_amoled_vr_mode_show(char* buf)
{
    return snprintf(buf, PAGE_SIZE,  "%d\n", lcdkit_info.panel_infos.vr_mode);
}

static ssize_t lcdkit_amoled_vr_mode_store(void* pdata, const char* buf)
{
    ssize_t ret = 0;
    unsigned long val = 0;
    int flag = -1;

    ret = strict_strtoul(buf, 0, &val);

    if (ret)
    {
        LCDKIT_ERR("string to l int error, buf[%s], ret:%ld\n", buf, ret);
        return ret;
    }

    flag = (int)val;

    switch (flag)
    {
        case VR_MODE_ENABLE:
            LCDKIT_INFO("VR CYCLE SET vr mode\n");
            lcdkit_info.panel_infos.vr_mode = VR_MODE_ENABLE;
            lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.vr_mode_enable_cmds);
            break;

        case  VR_MODE_DISABLE:
            LCDKIT_INFO("VR CYCLE SET normal mode\n");
            lcdkit_info.panel_infos.vr_mode = VR_MODE_DISABLE;
            lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.vr_mode_disable_cmds);
            break;

        default:
            lcdkit_info.panel_infos.vr_mode = VR_MODE_DISABLE;
            LCDKIT_INFO("VR CYCLE SET unknown mode\n");
            break;
    }

    return ret;
}

static ssize_t lcdkit_amoled_hbm_ctrl_show(char* buf)
{
    return  snprintf(buf, PAGE_SIZE, "%d\n", lcdkit_info.panel_infos.hbm_ctrl_mode);
}

static ssize_t lcdkit_amoled_hbm_ctrl_store(void* pdata, const char* buf)
{
    ssize_t ret = 0;
    unsigned long val = 0;

    ret = strict_strtoul(buf, 0, &val);

    if (ret)
    { return ret; }

    lcdkit_info.panel_infos.hbm_ctrl_mode = (int)val;
    lcdkit_info.panel_infos.hbm_enable_cmds.cmds->payload[1] =  lcdkit_info.panel_infos.hbm_ctrl_mode ? 0xe8 : 0x20;

    lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.hbm_enable_cmds);

    return ret;
}

static ssize_t lcdkit_support_mode_show(char* buf)
{
    return snprintf(buf, PAGE_SIZE, "%d\n", lcdkit_info.panel_infos.effect_support_mode);
}

static ssize_t lcdkit_support_mode_store(const char* buf)
{
    ssize_t ret = 0;
    unsigned long val = 0;
    ret = strict_strtoul(buf, 0, &val);

    if (ret)
    {
        return ret;
    }

    lcdkit_info.panel_infos.effect_support_mode = (int)val;
    return ret;
}

static ssize_t lcdkit_support_checkmode_show(char* buf)
{
    ssize_t ret = 0;

    ret = snprintf(buf, PAGE_SIZE, "checksum:%d;lp2hs_mipi_check:%d\n", lcdkit_info.panel_infos.checksum_support, lcdkit_info.panel_infos.lp2hs_mipi_check_support);

    return ret;
}

static ssize_t lcdkit_current_detect(void* pdata)
{
    ssize_t current_check_result = 0;
        int i = 0;
    uint32_t rd[LCDKIT_CHECKSUM_SIZE] = {0};
    struct lcdkit_dsi_cmd_desc packet_size_set_cmd = {LCDKIT_DTYPE_MAX_PKTSIZE, 1, 0, 0, 10, LCDKIT_WAIT_TYPE_US, 1, NULL};
    LCDKIT_INFO("current detect enter!\n");
   
    if(!lcdkit_info.panel_infos.lv_detect_support)
    {
        LCDKIT_INFO("current detect is not support! return!\n");
        return 0;
    }

    lcdkit_mipi_dsi_max_return_packet_size(pdata, &packet_size_set_cmd);
    lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.current_detect_enter_cmds);
    lcdkit_dsi_rx(pdata, rd, 0, &lcdkit_info.panel_infos.current_detect_cmds);

    LCDKIT_INFO("%d %d %d %d %d %d %d %d\n", \
                rd[0], rd[1], rd[2], rd[3], rd[4], rd[5], rd[6], rd[7]);

    if ((rd[i] & lcdkit_info.panel_infos.current_mask.buf[0]) == 0) {
        current_check_result = 0;
        LCDKIT_ERR("no current over\n");
    }
    else{
        if (rd[i] & lcdkit_info.panel_infos.current_mask.buf[1]){
            LCDKIT_ERR("AVEE current over\n");
            current_check_result = 1;
        }
        if (rd[i] & lcdkit_info.panel_infos.current_mask.buf[2]){
           LCDKIT_ERR("ADD current over\n");
           current_check_result = 1;
        }
    }

    lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.current_detect_exit_cmds);

    return current_check_result;
}

static ssize_t lcdkit_lv_detect(void* pdata)
{
    ssize_t lv_detect_result = 0;
    int i = 0;
    uint32_t rd[LCDKIT_CHECKSUM_SIZE] = {0};
    struct lcdkit_dsi_cmd_desc packet_size_set_cmd = {LCDKIT_DTYPE_MAX_PKTSIZE, 1, 0, 0, 10, LCDKIT_WAIT_TYPE_US, 1, NULL};

    LCDKIT_INFO("lv detect enter!\n");

    if(!lcdkit_info.panel_infos.lv_detect_support)
    {
        LCDKIT_INFO("lv detect is not support! return!\n");
        return 0;
    }

    lcdkit_mipi_dsi_max_return_packet_size(pdata, &packet_size_set_cmd);
    lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.lv_detect_enter_cmds);
    lcdkit_dsi_rx(pdata, rd, 0, &lcdkit_info.panel_infos.lv_detect_cmds);

    LCDKIT_INFO("%d %d %d %d %d %d %d %d\n", \
                rd[0], rd[1], rd[2], rd[3], rd[4], rd[5], rd[6], rd[7]);

    if (rd[i] != 0) {
        LCDKIT_ERR("rd[%d] = 0x%x, expected = 0x00\n", i, rd[i]);
        lv_detect_result = 1;
    }else{
        lv_detect_result = 0;
    }

    lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.lv_detect_exit_cmds);
    return lv_detect_result;
}


static ssize_t lcdkit_test_config_show(void* pdata, char* buf)
{
    int i = 0;
    int test_result = 0;

    for (i = 0; i < SENCE_ARRAY_SIZE; i++)
    {
        if (sence_array[i] == NULL) {
            LCDKIT_INFO("Sence cmd is end, total num is:%d\n", i);
            break;
        }
        if ( !strncmp(lcdkit_info.panel_infos.lcd_cmd_now, sence_array[i], strlen(lcdkit_info.panel_infos.lcd_cmd_now)))
        {
            LCDKIT_INFO("current test cmd:%s,return cmd:%s\n",
                        lcdkit_info.panel_infos.lcd_cmd_now, cmd_array[i]);
            return snprintf(buf, PAGE_SIZE, cmd_array[i]);
        }
    }

    /* lcd support over current and over voltage detect */
    if (!strncmp(lcdkit_info.panel_infos.lcd_cmd_now, "CURRENT_TEST_MODE", strlen("CURRENT_TEST_MODE"))) {
        return snprintf(buf, PAGE_SIZE, "LCD_CUR_DET_MODE");
    /* over current detect */
    } else if (!strncmp(lcdkit_info.panel_infos.lcd_cmd_now, "OVER_CURRENT_DETECTION", strlen("OVER_CURRENT_DETECTION"))) {
        test_result = lcdkit_current_detect(pdata);
        return snprintf(buf, PAGE_SIZE, "%d", test_result);
    /* over voltage detect */
    } else if (!strncmp(lcdkit_info.panel_infos.lcd_cmd_now, "OVER_VOLTAGE_DETECTION", strlen("OVER_VOLTAGE_DETECTION"))) {
        test_result = lcdkit_lv_detect(pdata);
        return snprintf(buf, PAGE_SIZE, "%d", test_result);
    /* input invaild */
    } else {
        LCDKIT_INFO("cmd invaild,current test cmd:%s\n", lcdkit_info.panel_infos.lcd_cmd_now);
        return snprintf(buf, PAGE_SIZE, "INVALID");
    }
}

static ssize_t lcdkit_test_config_store(const char* buf)
{
    if (strlen(buf) < LCDKIT_CMD_NAME_MAX)
    {
        memcpy(lcdkit_info.panel_infos.lcd_cmd_now, buf, strlen(buf) + 1);
        LCDKIT_INFO("current test cmd:%s\n", lcdkit_info.panel_infos.lcd_cmd_now);
    }
    else
    {
        memcpy(lcdkit_info.panel_infos.lcd_cmd_now, "INVALID", strlen("INVALID") + 1);
        LCDKIT_INFO("invalid test cmd:%s\n", lcdkit_info.panel_infos.lcd_cmd_now);
    }

    return 0;
}

static ssize_t lcdkit_fps_scence_handle(struct platform_device* pdev, uint32_t scence)
{
    lcdkit_fps_scence_adaptor_handle(pdev, scence);

    /*for video panel, updt porch*/
    if (!lcdkit_is_cmd_panel())
    {
        lcdkit_updt_porch(pdev, scence);
    }

    return 0;
}

static ssize_t lcdkit_fps_updt_handle(void* pdata)
{
    lcdkit_fps_updt_adaptor_handle(pdata);
    return 0;
}

/*function: this function is used to set the Partial  display of LCD
  *input:
  *@pdata: this void point is used to converte to fb data struct.
  *@dirty: the region of partial display need
*/
static ssize_t lcdkit_set_display_region(void* pdata, void* dirty)
{
    struct dirty_rect* dirty_region = NULL;
    ssize_t ret = 0;

    if ( dirty == NULL)
    {
        LCDKIT_ERR("dirty is null point!\n");
        return ret;
    }

    dirty_region = (struct dirty_rect*) dirty;

    lcdkit_dump_cmds(&lcdkit_info.panel_infos.display_region_cmds);

    lcdkit_info.panel_infos.display_region_cmds.cmds[0].payload[1] = (dirty_region->x >> 8) & 0xff;
    lcdkit_info.panel_infos.display_region_cmds.cmds[0].payload[2] = dirty_region->x & 0xff;
    lcdkit_info.panel_infos.display_region_cmds.cmds[0].payload[3] = ((dirty_region->x + dirty_region->w - 1) >> 8) & 0xff;
    lcdkit_info.panel_infos.display_region_cmds.cmds[0].payload[4] = (dirty_region->x + dirty_region->w - 1) & 0xff;
    lcdkit_info.panel_infos.display_region_cmds.cmds[1].payload[1] = (dirty_region->y >> 8) & 0xff;
    lcdkit_info.panel_infos.display_region_cmds.cmds[1].payload[2] = dirty_region->y & 0xff;
    lcdkit_info.panel_infos.display_region_cmds.cmds[1].payload[3] = ((dirty_region->y + dirty_region->h - 1) >> 8) & 0xff;
    lcdkit_info.panel_infos.display_region_cmds.cmds[1].payload[4] = (dirty_region->y + dirty_region->h - 1) & 0xff;

    lcdkit_dump_cmds(&lcdkit_info.panel_infos.display_region_cmds);
    lcdkit_dsi_tx(pdata, &lcdkit_info.panel_infos.display_region_cmds);

    return ret;
}

static void lcdkit_vsp_enable(bool en)
{
    LCDKIT_INFO("vsp enable(%d)\n", en);

    if(lcdkit_bias_is_gpio_ctrl_power())
    {
        if(en)
            gpio_direction_output(lcdkit_info.panel_infos.gpio_lcd_vsp, 1);
        else
            gpio_direction_output(lcdkit_info.panel_infos.gpio_lcd_vsp, 0);
    }
    else if(lcdkit_bias_is_regulator_ctrl_power())
    {
        if(en)
        {
//            gpio_direction_output(volt.vsp_gpio, 1);
               ;
        }
        else
        {
//            gpio_direction_output(volt.vsp_gpio, 0);
             ;
        }
    }
}

static void lcdkit_vsn_enable(bool en)
{
    LCDKIT_INFO("vsn enable(%d)\n", en);

    if(en)
        gpio_direction_output(lcdkit_info.panel_infos.gpio_lcd_vsn, 1);
    else
        gpio_direction_output(lcdkit_info.panel_infos.gpio_lcd_vsn, 0);
}

static void lcdkit_vddio_enable(bool en)
{
    LCDKIT_INFO("obsolescent\n");

}

static void lcdkit_vci_enable(bool en)
{
    LCDKIT_INFO("obsolescent\n");
}

static int lcdkit_fake_panel_bl_update(void *pdata, uint32_t bl_level)
{
    int ret = 0;
    ret = lcdkit_fake_update_bl(pdata,bl_level);
    return ret;
}

static ssize_t  lcdkit_voltage_enable_store(void *pdata, const char* buf)
{
    char command[10] = {0};

    uint32_t bl_value = 0;
    int ret = 0;
    char bl_value_buf[10] = {0};

    if (!sscanf(buf, "%s", command)) {
        LCDKIT_INFO("bad command(%s)\n", command);
        return -EINVAL;
    }

    LCDKIT_INFO("command(%s)\n", command);
    if (!strncmp("vsp:", command, strlen("vsp:"))) {
        if('0' == command[strlen("vsp:")])
            lcdkit_vsp_enable(false);
        else
            lcdkit_vsp_enable(true);
    }

    if (!strncmp("vsn:", command, strlen("vsn:"))) {
        if('0' == command[strlen("vsn:")])
            lcdkit_vsn_enable(false);
        else
            lcdkit_vsn_enable(true);
    }

    if (!strncmp("vddio:", command, strlen("vddio:"))) {
        if('0' == command[strlen("vddio:")])
            lcdkit_vddio_enable(false);
        else
            lcdkit_vddio_enable(true);
    }

    if (!strncmp("vci:", command, strlen("vci:"))) {
        if('0' == command[strlen("vci:")])
            lcdkit_vci_enable(false);
        else
            lcdkit_vci_enable(true);
    }

    if (!strncmp("bl:", command, strlen("bl:"))) {
        if (((strlen(command) - strlen("bl:")) > 0) &&((strlen(command) - strlen("bl:")) < sizeof(bl_value_buf))) {
            memcpy(bl_value_buf, &command[strlen("bl:")], strlen(command)-strlen("bl:"));
            bl_value = simple_strtoul(bl_value_buf, NULL, 0);
            LCDKIT_INFO("bl_value_buf is %s, bl_value is %d\n", bl_value_buf, bl_value);
        } else {
            bl_value = 0;
        }

        ret = lcdkit_fake_panel_bl_update(pdata, bl_value);
    }

    return ret;
}

struct lcdkit_panel_data lcdkit_info =
{
    .lcdkit_init = lcdkit_init,
    .lcdkit_on_cmd  = lcdkit_on_cmd,
    .lcdkit_off_cmd = lcdkit_off_cmd,
    .lcdkit_model_show = lcdkit_model_show,
    .lcdkit_panel_info_show =  lcdkit_panel_info_show,
    .lcdkit_cabc_mode_show = lcdkit_cabc_mode_show,
    .lcdkit_cabc_mode_store = lcdkit_cabc_mode_store,
    .lcdkit_inversion_mode_store = lcdkit_inversion_mode_store,
    .lcdkit_inversion_mode_show = lcdkit_inversion_mode_show,
    .lcdkit_scan_mode_store = lcdkit_scan_mode_store,
    .lcdkit_scan_mode_show = lcdkit_scan_mode_show,
    .lcdkit_check_reg_show = lcdkit_check_reg_show,
    .lcdkit_check_esd  = lcdkit_check_esd,
    .lcdkit_gram_check_show = lcdkit_gram_check_show,
    .lcdkit_gram_check_store = lcdkit_gram_check_store,
    .lcdkit_dynamic_sram_check_show = lcdkit_dynamic_sram_check_show,
    .lcdkit_dynamic_sram_check_store = lcdkit_dynamic_sram_check_store,
    .lcdkit_sleep_ctrl_show = lcdkit_sleep_ctrl_show,
    .lcdkit_sleep_ctrl_store = lcdkit_sleep_ctrl_store,
    .lcdkit_lp2hs_mipi_check_show = lcdkit_lp2hs_mipi_check_show,
    .lcdkit_lp2hs_mipi_check_store = lcdkit_lp2hs_mipi_check_store,
    .lcdkit_bist_check_show = lcdkit_bist_check_show,
    .lcdkit_mipi_detect_show = lcdkit_mipi_detect_show,
    .lcdkit_hkadc_debug_show = lcdkit_hkadc_debug_show,
    .lcdkit_hkadc_debug_store = lcdkit_hkadc_debug_store,
    .lcdkit_voltage_enable_store = lcdkit_voltage_enable_store,
    .lcdkit_pcd_errflag_check = lcdkit_pcd_errflag_check,
    .lcdkit_amoled_acl_ctrl_show = lcdkit_amoled_acl_ctrl_show,
    .lcdkit_amoled_acl_ctrl_store = lcdkit_amoled_acl_ctrl_store,
    .lcdkit_amoled_vr_mode_show = lcdkit_amoled_vr_mode_show,
    .lcdkit_amoled_vr_mode_store = lcdkit_amoled_vr_mode_store,
    .lcdkit_amoled_hbm_ctrl_show = lcdkit_amoled_hbm_ctrl_show,
    .lcdkit_amoled_hbm_ctrl_store = lcdkit_amoled_hbm_ctrl_store,
    .lcdkit_support_mode_show = lcdkit_support_mode_show,
    .lcdkit_support_mode_store = lcdkit_support_mode_store,
    .lcdkit_support_checkmode_show = lcdkit_support_checkmode_show,
    .lcdkit_test_config_show = lcdkit_test_config_show,
    .lcdkit_test_config_store = lcdkit_test_config_store,
    .lcdkit_fps_scence_handle = lcdkit_fps_scence_handle,
    .lcdkit_fps_updt_handle = lcdkit_fps_updt_handle,
    .lcdkit_set_display_region = lcdkit_set_display_region,
    .lcdkit_current_detect = lcdkit_current_detect,
    .lcdkit_lv_detect = lcdkit_lv_detect,
    .lcdkit_ce_mode_show = lcdkit_ce_mode_show,
    .lcdkit_ce_mode_store = lcdkit_ce_mode_store,
};
