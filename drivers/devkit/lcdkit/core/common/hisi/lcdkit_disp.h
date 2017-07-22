/* Copyright (c) 2008-2011, Hisilicon Tech. Co., Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Code Aurora Forum, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef __LCDKIT_DISP_H_
#define __LCDKIT_DISP_H_
/***********************************************************
*macro definition
***********************************************************/
#include "lcdkit_panel.h"
#include "hisi_fb.h"
#include "hisi_mipi_dsi.h"
#include "voltage/tps65132.h"

#define DTS_COMP_LCDKIT_PANEL_TYPE     "huawei,lcd_panel_type"
#define LCDKIT_PANEL_COMP_LENGTH       128
#define ESD_DEBUG   0
#define LCDKIT_TYPE_BUF 30

/***********************************************************
*variable declaration
***********************************************************/
/*extern variable*/
extern bool gesture_func;

//extern void ts_kit_check_bootup_upgrade(void);

/*extern fun*/
extern int mipi_dsi_ulps_cfg(struct hisi_fb_data_type* hisifd, int enable);

struct lcdkit_vsp_vsn_voltage{
    u32 voltage;
    int value;
};

static struct lcdkit_vsp_vsn_voltage voltage_table[] = {
        {4000000,TPS65132_VOL_40},
        {4100000,TPS65132_VOL_41},
        {4200000,TPS65132_VOL_42},
        {4300000,TPS65132_VOL_43},
        {4400000,TPS65132_VOL_44},
        {4500000,TPS65132_VOL_45},
        {4600000,TPS65132_VOL_46},
        {4700000,TPS65132_VOL_47},
        {4800000,TPS65132_VOL_48},
        {4900000,TPS65132_VOL_49},
        {5000000,TPS65132_VOL_50},
        {5100000,TPS65132_VOL_51},
        {5200000,TPS65132_VOL_52},
        {5300000,TPS65132_VOL_53},
        {5400000,TPS65132_VOL_54},
        {5500000,TPS65132_VOL_55},
        {5600000,TPS65132_VOL_56},
        {5700000,TPS65132_VOL_57},
        {5800000,TPS65132_VOL_58},
        {5900000,TPS65132_VOL_59},
        {6000000,TPS65132_VOL_60},
};

/************************************************************
 *
 * LCD VCC
 *
 ************************************************************/
#define LCDKIT_VCC_BACKLIGHT_NAME      "lcd_backlight"
#define LCDKIT_VCC_LCDBIAS_NAME        "vcc_lcdbias"
#define LCDKIT_VCC_LCD_VSN_NAME        "lcd_vsn"
#define LCDKIT_VCC_LCD_VSP_NAME        "lcd_vsp"

/* scharg regulator */
static struct regulator* lcdkit_bl_vcc;
static struct regulator* lcdkit_bias_vcc;
static struct regulator* lcdkit_vsn_vcc;
static struct regulator* lcdkit_vsp_vcc;

static struct vcc_desc lcdkit_scharger_bias_get_cmds[] =
{
    /* vcc get */
    {DTYPE_VCC_GET, LCDKIT_VCC_BACKLIGHT_NAME, &lcdkit_bl_vcc,   0, 0, 0, 0},
    {DTYPE_VCC_GET, LCDKIT_VCC_LCDBIAS_NAME,   &lcdkit_bias_vcc, 0, 0, 0, 0},
    {DTYPE_VCC_GET, LCDKIT_VCC_LCD_VSN_NAME,   &lcdkit_vsn_vcc,  0, 0, 0, 0},
    {DTYPE_VCC_GET, LCDKIT_VCC_LCD_VSP_NAME,   &lcdkit_vsp_vcc,  0, 0, 0, 0},
};

static struct vcc_desc lcdkit_scharger_bias_set_cmds[] =
{
    /* vcc set voltage */
    {DTYPE_VCC_SET_VOLTAGE, LCDKIT_VCC_LCDBIAS_NAME, &lcdkit_bias_vcc, 5400000, 5400000, 0, 0},
    {DTYPE_VCC_SET_VOLTAGE, LCDKIT_VCC_LCD_VSP_NAME, &lcdkit_vsp_vcc,  5400000, 5400000, 0, 0},
    {DTYPE_VCC_SET_VOLTAGE, LCDKIT_VCC_LCD_VSN_NAME, &lcdkit_vsn_vcc,  5400000, 5400000, 0, 0},
};

static struct vcc_desc lcdkit_scharger_bias_put_cmds[] =
{
    /* vcc put */
    {DTYPE_VCC_PUT, LCDKIT_VCC_BACKLIGHT_NAME, &lcdkit_bl_vcc,   0, 0, 0, 0},
    {DTYPE_VCC_PUT, LCDKIT_VCC_LCDBIAS_NAME,   &lcdkit_bias_vcc, 0, 0, 0, 0},
    {DTYPE_VCC_PUT, LCDKIT_VCC_LCD_VSN_NAME,   &lcdkit_vsn_vcc,  0, 0, 0, 0},
    {DTYPE_VCC_PUT, LCDKIT_VCC_LCD_VSP_NAME,   &lcdkit_vsp_vcc,  0, 0, 0, 0},
};

static struct vcc_desc lcdkit_scharger_bias_enable_cmds[] =
{
    /* vcc enable */
    {DTYPE_VCC_ENABLE, LCDKIT_VCC_LCDBIAS_NAME,   &lcdkit_bias_vcc, 0, 0, WAIT_TYPE_MS, 5},
    {DTYPE_VCC_ENABLE, LCDKIT_VCC_LCD_VSP_NAME,   &lcdkit_vsp_vcc,  0, 0, WAIT_TYPE_MS, 5},
    {DTYPE_VCC_ENABLE, LCDKIT_VCC_LCD_VSN_NAME,   &lcdkit_vsn_vcc,  0, 0, WAIT_TYPE_MS, 5},
};

static struct vcc_desc lcdkit_scharger_bias_disable_cmds[] =
{
    /* vcc disable */
    {DTYPE_VCC_DISABLE, LCDKIT_VCC_LCD_VSN_NAME,   &lcdkit_vsn_vcc,  0, 0, WAIT_TYPE_MS, 5},
    {DTYPE_VCC_DISABLE, LCDKIT_VCC_LCD_VSP_NAME,   &lcdkit_vsp_vcc,  0, 0, WAIT_TYPE_MS, 5},
    {DTYPE_VCC_DISABLE, LCDKIT_VCC_LCDBIAS_NAME,   &lcdkit_bias_vcc, 0, 0, WAIT_TYPE_MS, 1},
};

static struct vcc_desc lcdkit_scharger_bl_enable_cmds[] =
{
    /* backlight enable */
    {DTYPE_VCC_ENABLE, LCDKIT_VCC_BACKLIGHT_NAME, &lcdkit_bl_vcc,   0, 0, WAIT_TYPE_MS, 10},
};

static struct vcc_desc lcdkit_scharger_bl_disable_cmds[] =
{
    /* backlight disable */
    {DTYPE_VCC_DISABLE, LCDKIT_VCC_BACKLIGHT_NAME, &lcdkit_bl_vcc,  0, 0, WAIT_TYPE_MS, 1},
};

/*******************************************************************************
** LCD VCC
*/
#define LCDKIT_VCC_LCDIO_NAME       "lcdio-vcc"
#define LCDKIT_VCC_LCDANALOG_NAME   "lcdanalog-vcc"

static struct regulator* lcdkit_vcc_lcdio;
static struct regulator* lcdkit_vcc_lcdanalog;

static struct vcc_desc lcdkit_io_vcc_init_cmds[] =
{
    /* vcc get */
    {DTYPE_VCC_GET, LCDKIT_VCC_LCDIO_NAME, &lcdkit_vcc_lcdio, 0, 0, WAIT_TYPE_MS, 0},
    /* io set voltage */
    {DTYPE_VCC_SET_VOLTAGE, LCDKIT_VCC_LCDIO_NAME, &lcdkit_vcc_lcdio, 1800000, 1800000, WAIT_TYPE_MS, 0},
};

static struct vcc_desc lcdkit_vci_init_cmds[] =
{
    /* vcc get */
    {DTYPE_VCC_GET, LCDKIT_VCC_LCDANALOG_NAME, &lcdkit_vcc_lcdanalog, 0, 0, WAIT_TYPE_MS, 0},
    /* vcc set voltage */
    {DTYPE_VCC_SET_VOLTAGE, LCDKIT_VCC_LCDANALOG_NAME, &lcdkit_vcc_lcdanalog, 2800000, 2800000, WAIT_TYPE_MS, 0},
};

static struct vcc_desc lcdkit_vcc_finit_cmds[] =
{
    /* vcc put */
    {DTYPE_VCC_PUT, LCDKIT_VCC_LCDIO_NAME, &lcdkit_vcc_lcdio, 0, 0, WAIT_TYPE_MS, 0},
    {DTYPE_VCC_PUT, LCDKIT_VCC_LCDANALOG_NAME, &lcdkit_vcc_lcdanalog, 0, 0, WAIT_TYPE_MS, 0},
};

static struct vcc_desc lcdkit_io_vcc_enable_cmds[] =
{
    /* vcc enable */
    {DTYPE_VCC_ENABLE, LCDKIT_VCC_LCDIO_NAME, &lcdkit_vcc_lcdio, 0, 0, WAIT_TYPE_MS, 0},
};

static struct vcc_desc lcdkit_regulator_vci_enable_cmds[] =
{
    /* vcc enable */
    {DTYPE_VCC_ENABLE, LCDKIT_VCC_LCDANALOG_NAME, &lcdkit_vcc_lcdanalog, 0, 0, WAIT_TYPE_MS, 0},
};

static struct vcc_desc lcdkit_io_vcc_disable_cmds[] =
{
    /* vcc disable */
    {DTYPE_VCC_DISABLE, LCDKIT_VCC_LCDIO_NAME, &lcdkit_vcc_lcdio, 0, 0, WAIT_TYPE_MS, 0},
};

static struct vcc_desc lcdkit_regulator_vci_disable_cmds[] =
{
    /* vcc disable */
    {DTYPE_VCC_DISABLE, LCDKIT_VCC_LCDANALOG_NAME, &lcdkit_vcc_lcdanalog, 0, 0, WAIT_TYPE_MS, 0},
};

/*******************************************************************************
** LCD IOMUX
*/
static struct pinctrl_data pctrl;

static struct pinctrl_cmd_desc lcdkit_pinctrl_init_cmds[] =
{
    {DTYPE_PINCTRL_GET, &pctrl, 0},
    {DTYPE_PINCTRL_STATE_GET, &pctrl, DTYPE_PINCTRL_STATE_DEFAULT},
    {DTYPE_PINCTRL_STATE_GET, &pctrl, DTYPE_PINCTRL_STATE_IDLE},
};

static struct pinctrl_cmd_desc lcdkit_pinctrl_normal_cmds[] =
{
    {DTYPE_PINCTRL_SET, &pctrl, DTYPE_PINCTRL_STATE_DEFAULT},
};

static struct pinctrl_cmd_desc lcdkit_pinctrl_low_cmds[] =
{
    {DTYPE_PINCTRL_SET, &pctrl, DTYPE_PINCTRL_STATE_IDLE},
};

static struct pinctrl_cmd_desc lcdkit_pinctrl_finit_cmds[] =
{
    {DTYPE_PINCTRL_PUT, &pctrl, 0},
};


/*******************************************************************************
 ** LCD GPIO
 */

#define GPIO_LCDKIT_RESET_NAME                  "gpio_lcdkit_reset"
#define GPIO_LCDKIT_ID0_NAME	                   "gpio_lcdkit_id0"
#define GPIO_LCDKIT_ID1_NAME	                   "gpio_lcdkit_id1"
#define GPIO_LCDKIT_TE0_NAME                      "gpio_lcdkit_te0"
#define GPIO_LCDKIT_PCD_NAME	                   "gpio_lcdkit_pcd"
#define GPIO_LCDKIT_ERR_FLAG_NAME            "gpio_lcdkit_errflag"

#define GPIO_LCDKIT_VDD3                              "gpio_lcdkit_vdd3"
#define GPIO_LCDKIT_VDDR                              "gpio_lcdkit_vddr"

#define GPIO_LCDKIT_BL_ENABLE_NAME	      "gpio_lcdkit_bl_enable"
#define GPIO_LCDKIT_P5V5_ENABLE_NAME	   "gpio_lcdkit_p5v5_enable"
#define GPIO_LCDKIT_N5V5_ENABLE_NAME       "gpio_lcdkit_n5v5_enable"
#define GPIO_LCDKIT_IOVCC_NAME       "gpio_lcdkit_iovcc"
#define GPIO_LCDKIT_VCI_NAME       "gpio_lcdkit_vci"


/*******************************************************************************
**reset gpio
*/
static struct gpio_desc lcdkit_gpio_reset_request_cmds[] =
{
    /* reset */
    {
        DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_RESET_NAME, &lcdkit_info.panel_infos.gpio_lcd_reset, 0
    },
};

static struct gpio_desc lcdkit_gpio_reset_free_cmds[] =
{
    /* reset */
    {
        DTYPE_GPIO_FREE, WAIT_TYPE_US, 100,
        GPIO_LCDKIT_RESET_NAME, &lcdkit_info.panel_infos.gpio_lcd_reset, 0
    },
};

static struct gpio_desc lcdkit_gpio_reset_normal_cmds[] =
{
    /* reset */
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 15,
        GPIO_LCDKIT_RESET_NAME, &lcdkit_info.panel_infos.gpio_lcd_reset, 1
    },
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5,
        GPIO_LCDKIT_RESET_NAME, &lcdkit_info.panel_infos.gpio_lcd_reset, 0
    },
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 15,
        GPIO_LCDKIT_RESET_NAME, &lcdkit_info.panel_infos.gpio_lcd_reset, 1
    },
};

static struct gpio_desc lcdkit_gpio_reset_low_cmds[] =
{
    /* reset */
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5,
        GPIO_LCDKIT_RESET_NAME, &lcdkit_info.panel_infos.gpio_lcd_reset, 0
    },
};

/********************************************************************************
**lcd id0,id1 gpio
*/
static struct gpio_desc lcdkit_gpio_id_request_cmds[] =
{
    /*id0*/
    {
        DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_ID0_NAME, &lcdkit_info.panel_infos.gpio_lcd_id0, 0
    },
    /*id1*/
    {
        DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_ID1_NAME, &lcdkit_info.panel_infos.gpio_lcd_id1, 0
    },
};

static struct gpio_desc lcdkit_gpio_id0_low_cmds[] =
{
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_ID0_NAME, &lcdkit_info.panel_infos.gpio_lcd_id0, 0
    },
};

static struct gpio_desc lcdkit_gpio_id0_high_cmds[] =
{
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_ID0_NAME, &lcdkit_info.panel_infos.gpio_lcd_id0, 1
    },
};

static struct gpio_desc lcdkit_gpio_id1_low_cmds[] =
{
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_ID1_NAME, &lcdkit_info.panel_infos.gpio_lcd_id1, 0
    },
};

static struct gpio_desc lcdkit_gpio_id1_high_cmds[] =
{
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_ID1_NAME, &lcdkit_info.panel_infos.gpio_lcd_id1, 1
    },
};

static struct gpio_desc lcdkit_gpio_id0_input_cmds[] =
{
    {
        DTYPE_GPIO_INPUT, WAIT_TYPE_US, 100,
        GPIO_LCDKIT_ID0_NAME, &lcdkit_info.panel_infos.gpio_lcd_id0, 0
    },
};

static struct gpio_desc lcdkit_gpio_id1_input_cmds[] =
{
    {
        DTYPE_GPIO_INPUT, WAIT_TYPE_US, 100,
        GPIO_LCDKIT_ID1_NAME, &lcdkit_info.panel_infos.gpio_lcd_id1, 0
    },
};

/*************************
**vcc and bl gpio
*/
static struct gpio_desc lcdkit_bias_request_cmds[] =
{
    /*AVDD +5.5V*/
    {
        DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_P5V5_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_vsp, 0
    },
    /* AVEE_-5.5V */
    {
        DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_N5V5_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_vsn, 0
    },
};

static struct gpio_desc lcdkit_bias_enable_cmds[] =
{
    /* AVDD_5.5V */
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5,
        GPIO_LCDKIT_P5V5_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_vsp, 1
    },
    /* AVEE_-5.5V */
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 20,
        GPIO_LCDKIT_N5V5_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_vsn, 1
    },
};

static struct gpio_desc lcdkit_bias_free_cmds[] =
{
    /* AVEE_-5.5V */
    {
        DTYPE_GPIO_FREE, WAIT_TYPE_US, 50,
        GPIO_LCDKIT_N5V5_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_vsn, 0
    },
    /* AVDD_5.5V */
    {
        DTYPE_GPIO_FREE, WAIT_TYPE_US, 50,
        GPIO_LCDKIT_P5V5_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_vsp, 0
    },
};

static struct gpio_desc lcdkit_bias_disable_cmds[] =
{
    /* AVEE_-5.5V */
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 20,
        GPIO_LCDKIT_N5V5_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_vsn, 0
    },

    /* AVDD_5.5V */
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5,
        GPIO_LCDKIT_P5V5_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_vsp, 0
    },

    /* AVEE_-5.5V input */
    {
        DTYPE_GPIO_INPUT, WAIT_TYPE_MS, 5,
        GPIO_LCDKIT_N5V5_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_vsn, 0
    },
    /* AVDD_5.5V input */
    {
        DTYPE_GPIO_INPUT, WAIT_TYPE_MS, 5,
        GPIO_LCDKIT_P5V5_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_vsp, 0
    },

};

static __maybe_unused struct gpio_desc lcdkit_bl_request_cmds[] =
{
    /* backlight enable */
    {
        DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 5,
        GPIO_LCDKIT_BL_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_bl, 0
    },

};

static __maybe_unused struct gpio_desc lcdkit_bl_enable_cmds[] =
{
    /* backlight enable */
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5,
        GPIO_LCDKIT_BL_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_bl, 1
    },

};

static __maybe_unused struct gpio_desc lcdkit_bl_disable_cmds[] =
{
    /* backlight enable */
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 5,
        GPIO_LCDKIT_BL_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_bl, 0
    },

    {
        DTYPE_GPIO_INPUT, WAIT_TYPE_US, 100,
        GPIO_LCDKIT_BL_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_bl, 0
    },

};

static __maybe_unused struct gpio_desc lcdkit_bl_free_cmds[] =
{
    /* backlight enable */
    {
        DTYPE_GPIO_FREE, WAIT_TYPE_MS, 5,
        GPIO_LCDKIT_BL_ENABLE_NAME, &lcdkit_info.panel_infos.gpio_lcd_bl, 0
    },

};


/***************************
*Iovcc and vci gpio
*/
static struct gpio_desc lcdkit_iovcc_request_cmds[] =
{
    {
        DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_IOVCC_NAME, &lcdkit_info.panel_infos.gpio_lcd_iovcc, 0
    },
};

static struct gpio_desc lcdkit_vci_request_cmds[] =
{
    {
        DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_VCI_NAME, &lcdkit_info.panel_infos.gpio_lcd_vci, 0
    },
};

static struct gpio_desc lcdkit_iovcc_enable_cmds[] =
{
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_IOVCC_NAME, &lcdkit_info.panel_infos.gpio_lcd_iovcc, 1
    },
};

static struct gpio_desc lcdkit_vci_enable_cmds[] =
{
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_VCI_NAME, &lcdkit_info.panel_infos.gpio_lcd_vci, 1
    },
};

static struct gpio_desc lcdkit_iovcc_free_cmds[] =
{
    {
        DTYPE_GPIO_FREE, WAIT_TYPE_US, 50,
        GPIO_LCDKIT_IOVCC_NAME, &lcdkit_info.panel_infos.gpio_lcd_iovcc, 0
    },
};

static struct gpio_desc lcdkit_vci_free_cmds[] =
{
    {
        DTYPE_GPIO_FREE, WAIT_TYPE_US, 50,
        GPIO_LCDKIT_VCI_NAME, &lcdkit_info.panel_infos.gpio_lcd_vci, 0
    },
};

static struct gpio_desc lcdkit_iovcc_disable_cmds[] =
{
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 10,
        GPIO_LCDKIT_IOVCC_NAME, &lcdkit_info.panel_infos.gpio_lcd_iovcc, 0
    },

    {
        DTYPE_GPIO_INPUT, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_IOVCC_NAME, &lcdkit_info.panel_infos.gpio_lcd_iovcc, 0
    },
};

static struct gpio_desc lcdkit_vci_disable_cmds[] =
{
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 10,
        GPIO_LCDKIT_VCI_NAME, &lcdkit_info.panel_infos.gpio_lcd_vci, 0
    },

    {
        DTYPE_GPIO_INPUT, WAIT_TYPE_MS, 5,
        GPIO_LCDKIT_VCI_NAME, &lcdkit_info.panel_infos.gpio_lcd_vci, 0
    },
};


/*************************
*VDDR VDD3 gpio
*/
static __maybe_unused struct gpio_desc lcdkit_vdd_request_cmds[] =
{
    //VDDR
    {
        DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_VDDR, &lcdkit_info.panel_infos.gpio_lcd_vddr, 0
    },
    //vdd3
    {
        DTYPE_GPIO_REQUEST, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_VDD3, &lcdkit_info.panel_infos.gpio_lcd_vdd3, 0
    },
};

static __maybe_unused struct gpio_desc lcdkit_vdd_normal_cmds[] =
{
    //VDDR
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 15,
        GPIO_LCDKIT_VDDR, &lcdkit_info.panel_infos.gpio_lcd_vddr, 1
    },
    //vdd3
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 15,
        GPIO_LCDKIT_VDD3, &lcdkit_info.panel_infos.gpio_lcd_vdd3, 1
    },
};

static __maybe_unused struct gpio_desc lcdkit_vdd_low_cmds[] =
{
    //VDDR
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_VDDR, &lcdkit_info.panel_infos.gpio_lcd_vddr, 0
    },
    //vdd3
    {
        DTYPE_GPIO_OUTPUT, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_VDD3, &lcdkit_info.panel_infos.gpio_lcd_vdd3, 0
    },
};

static __maybe_unused struct gpio_desc lcdkit_vdd_free_cmds[] =
{
    //VDDR
    {
        DTYPE_GPIO_FREE, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_VDDR, &lcdkit_info.panel_infos.gpio_lcd_vddr, 0
    },
    //vdd3
    {
        DTYPE_GPIO_FREE, WAIT_TYPE_MS, 0,
        GPIO_LCDKIT_VDD3, &lcdkit_info.panel_infos.gpio_lcd_vdd3, 0
    },
};

/***********************************************************
*function declaration
***********************************************************/
#endif
