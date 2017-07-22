

#ifndef __FOCALTECH_CORE_H__
#define __FOCALTECH_CORE_H__

#include <linux/i2c.h>
#include <linux/input.h>
#include <linux/input/mt.h>
#include <linux/slab.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/regulator/consumer.h>
#include <linux/firmware.h>
#include <linux/debugfs.h>
#include <linux/mutex.h>
#include <linux/wait.h>
#include <linux/time.h>
#include <linux/workqueue.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/version.h>
#include <linux/cdev.h>
#include <linux/dma-mapping.h>
#include <huawei_platform/log/hw_log.h>
#include "../../huawei_ts_kit.h"

extern struct focal_platform_data *g_focal_pdata ;
extern  struct ts_kit_device_data *g_focal_dev_data ;

#if defined (CONFIG_HUAWEI_DSM)
extern struct dsm_client *ts_dclient;
#endif
#define FTS_MAX_TOUCH_POINTS		10
#define FTS_MODEL_NORMAL		0x00
#define FTS_MODEL_BOOTLOADER		0x01
#define FTS_MODEL_FIRST_START		0x02
#define FTS_PROJECT_ID_LEN		11
#define FTS_VENDOR_NAME_LEN		8
#define FTS_REPORT_BTN_TOUCH

#define FTS_FW_MANUAL_UPDATE_FILE_NAME	"ts/touch_screen_firmware.img"

#define FTS_VDDIO_GPIO_NAME		"ts_vddio_gpio"
#define FTS_VCI_GPIO_NAME		"ts_vci_gpio"
enum focal_ic_type {
	FOCAL_FT8716 = 0,
	FOCAL_FT8607,
};

#if defined (CONFIG_HUAWEI_DSM)
enum FW_uptate_state
{
    focal_enter_pram_model_fail = 0,
    focal_check_firmware_size_in_pram_model_fail,
    focal_auto_config_clock_fail,
    focal_enter_pram_update_model_from_pram_fail,
    focal_erasure_app_area_fail,
    focal_write_app_data_fail,
    focal_read_check_sum_fail,
    TS_UPDATE_STATE_UNDEFINE = 255,
};
#endif
struct ts_event {
	u16 position_x[FTS_MAX_TOUCH_POINTS];
	u16 position_y[FTS_MAX_TOUCH_POINTS];

	u16 pressure[FTS_MAX_TOUCH_POINTS];
	u16 area[FTS_MAX_TOUCH_POINTS];

	/* touch event: 0 -- down; 1-- up; 2 -- contact */
	u8 touch_event[FTS_MAX_TOUCH_POINTS];
	/* touch ID */
	u8 finger_id[FTS_MAX_TOUCH_POINTS];
	u8 touch_point;
	u8 touch_point_num;
	int touchs;
};

/* platform data that can be configured by extern */
struct focal_platform_data {
	struct platform_device *focal_platform_dev;
	struct focal_delay_time *delay_time;
	struct ts_kit_device_data *focal_device_data;
	unsigned int chip_id;
	struct pinctrl *pctrl;
	struct pinctrl_state *pins_default;
	struct pinctrl_state *pins_idle;
	int fw_ver;
	int vendor_id;
	unsigned int pram_projectid_addr;
	char project_id[FTS_PROJECT_ID_LEN];
	char vendor_name[FTS_VENDOR_NAME_LEN];
	struct ts_event touch_data;
};

int focal_read(u8 *addr, u16 addr_len, u8 *value, u16 values_size);
int focal_read_reg(u8 addr, u8 *val);
int focal_read_default(u8 *values, u16 values_size);
int focal_write(u8 *value, u16 values_size);
int focal_write_reg(u8 addr, u8 val);
int focal_write_default(u8 value);

int focal_hardware_reset_to_normal_model(void);
int focal_hardware_reset_to_bootloader(void);
int focal_hardware_reset_to_rom_update_model(void);

struct ts_kit_device_data *focal_get_device_data(void);
struct focal_platform_data *focal_get_platform_data(void);

char *focal_strncat(char *dest, char *src, size_t dest_size);
char *focal_strncatint(char *dest, int src, char *format, size_t dest_size);
int focal_strtolow(char *src_str, size_t size);

#endif

