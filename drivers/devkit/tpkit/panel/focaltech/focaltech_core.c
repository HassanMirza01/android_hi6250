

#include "focaltech_flash.h"
#include "focaltech_core.h"
#include "focaltech_test.h"
#include "focaltech_dts.h"
#include "focaltech_test.h"
#include "focaltech_apk_node.h"
#include <linux/printk.h>

#include "../../huawei_ts_kit.h"
#include <huawei_platform/log/log_jank.h>
#if defined(CONFIG_HUAWEI_DSM)
#include <dsm/dsm_pub.h>
#endif

#define FTS_MAX_POINT_ID		0x0F
#define FTS_POINT_DATA_SIZE		6

#define TOUCH_DATA_START_ADDR		0x00

#define ADDR_X_H_POS			(3 - TOUCH_DATA_START_ADDR)
#define ADDR_X_L_POS			(4 - TOUCH_DATA_START_ADDR)
#define ADDR_Y_H_POS			(5 - TOUCH_DATA_START_ADDR)
#define ADDR_Y_L_POS			(6 - TOUCH_DATA_START_ADDR)
#define ADDR_EVENT_POS			(3 - TOUCH_DATA_START_ADDR)
#define ADDR_FINGER_ID_POS		(5 - TOUCH_DATA_START_ADDR)
#define ADDR_POINT_NUM			(2 - TOUCH_DATA_START_ADDR)
#define ADDR_XY_POS			(7 - TOUCH_DATA_START_ADDR)
#define ADDR_MISC			(8 - TOUCH_DATA_START_ADDR)
#define FTS_TOUCH_DATA_LEN		\
	(3 - TOUCH_DATA_START_ADDR + FTS_POINT_DATA_SIZE * FTS_MAX_TOUCH_POINTS)

#define U8_STR_LEN			5
#ifndef NULL
#define NULL 0
#endif

struct focal_platform_data *g_focal_pdata = NULL;
struct ts_kit_device_data *g_focal_dev_data = NULL;

unsigned char focal_roi_data[ROI_DATA_READ_LENGTH] = { 0 };//roi data buff
static int focal_wrong_touch(void);
static int focal_init_chip(void);
static int focal_fw_update_sd(void);
static int focal_before_suspend(void);
static int focal_suspend(void);
static int focal_resume(void);
static void focal_shutdown(void);
static int focal_reset_device(void);
static u8 *focal_roi_rawdata(void);
static int focal_calibrate(void);
static int focal_calibrate_wakeup_gesture(void);

#if defined(CONFIG_HUAWEI_DSM)
static int focal_rmi4_dsm_debug(void);
#endif
#if defined(HUAWEI_CHARGER_FB)
static int focal_charger_switch(struct ts_charger_info *info);
#endif

static int focal_input_config(struct input_dev *input_dev);
static int focal_palm_switch(struct ts_palm_info *info);
static int focal_glove_switch(struct ts_glove_info *info);
static int focal_get_glove_switch(u8 *glove_switch);
static int focal_set_glove_switch(u8 glove_switch);
static int focal_holster_switch(struct ts_holster_info *info);
static int focal_roi_switch(struct ts_roi_info *info);
static int focal_regs_operate(struct ts_regs_info *info);
static int focal_chip_detect(struct ts_kit_platform_data *data);
static int focal_irq_top_half(struct ts_cmd_node *cmd);
static int focal_fw_update_boot(char *file_name);
static int focal_chip_get_info(struct ts_chip_info_param *info);
static int focal_set_info_flag(struct ts_kit_device_data *info);
static int focal_after_resume(void *feature_info);
static int focal_wakeup_gesture_enable_switch(
	struct ts_wakeup_gesture_enable_info *info);
static int focal_irq_bottom_half(struct ts_cmd_node *in_cmd,
	struct ts_cmd_node *out_cmd);
static int focal_set_glove_switch(u8 glove_switch);
static int focal_set_holster_switch(u8 holster_switch);
static int focal_set_roi_switch(u8 roi_switch);
static int focal_rmi4_status_resume(void);
static int focal_get_brightness_info(void);

struct ts_device_ops ts_focal_ops = {
	.chip_detect = focal_chip_detect,
	.chip_init = focal_init_chip,
	.chip_get_brightness_info = focal_get_brightness_info,
	.chip_input_config = focal_input_config,
	.chip_irq_top_half = focal_irq_top_half,
	.chip_irq_bottom_half = focal_irq_bottom_half,
	.chip_fw_update_boot = focal_fw_update_boot,
	.chip_fw_update_sd = focal_fw_update_sd,
	.chip_get_info = focal_chip_get_info,
	.chip_get_capacitance_test_type = focal_chip_get_capacitance_test_type,
	.chip_set_info_flag = focal_set_info_flag,
	.chip_before_suspend = focal_before_suspend,
	.chip_suspend = focal_suspend,
	.chip_resume = focal_resume,
	.chip_after_resume = focal_after_resume,
	.chip_wakeup_gesture_enable_switch = focal_wakeup_gesture_enable_switch,
	.chip_get_rawdata = focal_get_raw_data,
	.chip_get_debug_data = focal_get_debug_data,
	.chip_glove_switch = focal_glove_switch,
	.chip_shutdown = focal_shutdown,
	.chip_holster_switch = focal_holster_switch,
	.chip_roi_switch = focal_roi_switch,
	.chip_roi_rawdata = focal_roi_rawdata,
	.chip_palm_switch = focal_palm_switch,
	.chip_regs_operate = focal_regs_operate,
	.chip_calibrate = focal_calibrate,
	.chip_calibrate_wakeup_gesture = focal_calibrate_wakeup_gesture,
	.chip_reset = focal_reset_device,
#if defined(HUAWEI_CHARGER_FB)
	.chip_charger_switch = focal_charger_switch,
#endif
#if defined(CONFIG_HUAWEI_DSM)
	.chip_dsm_debug = focal_rmi4_dsm_debug,
#endif
#ifdef HUAWEI_TOUCHSCREEN_TEST
	.chip_test = test_dbg_cmd_test,
#endif
	.chip_wrong_touch = focal_wrong_touch,
};

inline struct ts_kit_device_data *focal_get_device_data(void)
{
	return g_focal_dev_data;
}

inline struct focal_platform_data *focal_get_platform_data(void)
{
	return g_focal_pdata;
}

static void focal_print_u8_array(u8 *data, u32 size)
{
	int i = 0;
	u32 str_len = 0;
	char *str_buf = NULL;
	char *str_print = NULL;

	/* every data item use 5 byte */
	str_len = U8_STR_LEN * size;

	str_buf = kzalloc(str_len + 1, GFP_KERNEL);
	if (!str_buf)
		return;

	str_print = str_buf;
	for (i = 0; i < size; i++) {

		snprintf(str_print, str_len, "0x%02X ", data[i]);
		str_print += U8_STR_LEN;
		str_len -= U8_STR_LEN;
	}

	TS_LOG_INFO("%s\n", str_buf);

	kfree(str_buf);
	str_buf = NULL;
	str_print = NULL;
}

char *focal_strncat(char *dest, char *src, size_t dest_size)
{
	size_t dest_len = 0;
	char *start_index = NULL;

	dest_len = strnlen(dest, dest_size);
	start_index = dest + dest_len;

	return strncat(&dest[dest_len], src, dest_size - dest_len - 1);
}

char *focal_strncatint(char *dest, int src, char *format, size_t dest_size)
{
	char src_str[16] = {0};

	snprintf(src_str, 16, format, src);

	return focal_strncat(dest, src_str, dest_size);
}


int focal_read(u8 *addrs, u16 addr_size, u8 *values, u16 values_size)
{
	int ret = 0;
	struct ts_bus_info *bops = NULL;

	bops = g_focal_dev_data->ts_platform_data->bops;

	ret = bops->bus_read(addrs, addr_size, values, values_size);
	if (ret) {
		TS_LOG_ERR("%s:fail, addrs:", __func__);
		focal_print_u8_array(addrs, addr_size);
	}

	return ret;
}

int focal_read_default(u8 *values, u16 values_size)
{
	return focal_read(NULL, 0, values, values_size);
}

int focal_read_reg(u8 addr, u8 *val)
{
	return focal_read(&addr, 1, val, 1);
}

int focal_write(u8 *values, u16 values_size)
{
	int ret = 0;
	struct ts_bus_info *bops = NULL;

	bops = g_focal_dev_data->ts_platform_data->bops;
	ret = bops->bus_write(values, values_size);
	if (ret) {
		TS_LOG_ERR("%s:fail, addrs:", __func__);
		focal_print_u8_array(values, values_size);
	}

	return ret;
}

int focal_write_default(u8 value)
{
	return focal_write(&value, 1);
}


int focal_write_reg(u8 addr, u8 value)
{
	u8 buf[2] = {0};

	buf[0] = addr;
	buf[1] = value;

	return focal_write(buf, sizeof(buf));
}

int focal_hardware_reset(int model)
{
	int ret = 0;
	int reset_gpio = 0;
	int reset_enable_delay = 0;

	reset_gpio = g_focal_dev_data->ts_platform_data->reset_gpio;

	ret = gpio_direction_output(reset_gpio, 1);
	if (ret) {
		TS_LOG_ERR("%s:gpio direction output to 1 fail, ret=%d\n",
				   __func__, ret);
		return ret;
	}
	msleep(1);

	ret = gpio_direction_output(reset_gpio, 0);
	if (ret) {
		TS_LOG_ERR("%s:gpio direction output to 0 fail, ret=%d\n",
				   __func__, ret);
		return ret;
	}
	msleep(1);

	ret = gpio_direction_output(reset_gpio, 1);
	if (ret) {
		TS_LOG_ERR("%s:gpio direction output to 1 fail, ret=%d\n",
				   __func__, ret);
		return ret;
	}

	switch (model) {
	case FTS_MODEL_BOOTLOADER:
		reset_enable_delay = 6;
		break;
	case FTS_MODEL_FIRST_START:
		reset_enable_delay = 240;
		break;
	case FTS_MODEL_NORMAL:
		reset_enable_delay = 120;
		break;
	default:
		reset_enable_delay = 240;
	}

	TS_LOG_INFO("%s:reset enable delay:%d\n", __func__, reset_enable_delay);
	msleep(reset_enable_delay);

	return 0;
}
/*
 * description: after finishe control reset gpio, write 0x55 to 0xfc in 6~25ms,
 *			  the ic will enter bootloader(rom boot) model
 *
 * param - focal_pdata : truct focal_platform_data
 *
 * return 0 if success, other wize return error code
 */
int focal_hardware_reset_to_rom_update_model(void)
{
	int i = 0;
	int ret = 0;
	u32 delay_time = 0;
	u32 chip_id = 0;

	delay_time = 6;
	for (i = 0; i < 10; i++) {

		if (i != 0)
			delay_time += 2;

		ret = focal_hardware_reset(FTS_MODEL_BOOTLOADER);
		if (ret < 0) {
			TS_LOG_ERR("%s:%s, ret=%d\n", __func__,
				"hardware reset to bootloader fail", ret);

			continue;
		}

		ret = focal_write_default(FTS_UPGRADE_55);
		if (ret < 0) {
			TS_LOG_ERR("%s:write command 0x55 fail, ret=%d\n",
				__func__, ret);
			continue;
		}

		ret = focal_read_chip_id_(&chip_id);
		if (ret || chip_id == 0) {
			TS_LOG_INFO("%s:chip id read fail, retry=%d\n",
				__func__, i);

			delay_time += 2;
			continue;
		} else {
			return 0;
		}
	}

	return -EINVAL;
}

int focal_hardware_reset_to_normal_model(void)
{
	return focal_hardware_reset(FTS_MODEL_NORMAL);
}

/*
 * description: after finishe control reset gpio, write 0x55 to 0xfc in 6~25ms,
 *			  the ic will enter bootloader(rom boot) model
 *
 * @param: focal_pdata - truct focal_platform_data
 *
 * return 0 if success, other wize return error code
 */
int focal_hardware_reset_to_bootloader(void)
{
	int i = 0;
	int ret = 0;
	u32 delay_time = 0;
	u32 chip_id = 0;

	delay_time = 6;
	for (i = 0; i < 10; i++) {

		if (i != 0)
			delay_time += 2;

		ret = focal_hardware_reset(FTS_MODEL_BOOTLOADER);
		if (ret < 0) {
			TS_LOG_ERR("%s:%s, ret=%d\n", __func__,
				"hardware reset to bootloader fail", ret);

			continue;
		}

		ret = focal_write_default(FTS_UPGRADE_55);
		if (ret < 0) {
			TS_LOG_ERR("%s:write command 0x55 fail, ret=%d\n",
				__func__, ret);
			continue;
		}

		ret = focal_read_chip_id_(&chip_id);
		if (ret || chip_id == 0) {
			TS_LOG_INFO("%s:chip id read fail, retry=%d\n",
				__func__, i);

			delay_time += 2;
			continue;
		} else {
			return 0;
		}
	}

	return -EINVAL;
}

int focal_strtolow(char *src_str, size_t size)
{
	char *str = NULL;

	if (NULL == src_str)
		return -EINVAL;

	str = src_str;
	while (*str != '\0' && size > 0) {
		if (*str >= 'A' && *str <= 'Z')
			*str += ('a' - 'A');

		str++;
		size--;
	}

	return 0;
}

static int focal_read_touch_data(struct ts_event *event_data)
{
	int i = 0;
	int ret = -1;
	u32 offset = 0;

	u8 buf[FTS_TOUCH_DATA_LEN] = { 0 };

	buf[0] = TOUCH_DATA_START_ADDR;
	ret = focal_read(buf, 1, buf, FTS_TOUCH_DATA_LEN);
	if (ret < 0) {
		TS_LOG_ERR("%s:read touchdata failed, ret=%d.\n",
			__func__, ret);
		return ret;
	}

	memset(event_data, 0, sizeof(struct ts_event));
	event_data->touch_point = 0;
	event_data->touch_point_num = buf[ADDR_POINT_NUM] & 0x0F;

	for (i = 0; i < FTS_MAX_TOUCH_POINTS; i++) {
		offset = FTS_POINT_DATA_SIZE * i;

		event_data->finger_id[i]
			= (buf[ADDR_FINGER_ID_POS + offset]) >> 4;

		if (event_data->finger_id[i] >= FTS_MAX_POINT_ID)
			break;
		else
			event_data->touch_point++;

		event_data->position_x[i] =
			(s16)(buf[ADDR_X_H_POS + offset] & 0x0F) << 8
			| (s16)(buf[ADDR_X_L_POS + offset]);

		event_data->position_y[i] =
			(s16)(buf[ADDR_Y_H_POS + offset] & 0x0F) << 8
			| (s16)(buf[ADDR_Y_L_POS + offset]);

		event_data->touch_event[i] = buf[ADDR_EVENT_POS + offset] >> 6;
		event_data->pressure[i] = (buf[ADDR_XY_POS + offset]);
		event_data->area[i] = (buf[ADDR_MISC + offset]) >> 4;

		/* check event data */
		if (event_data->touch_point_num == 0) {
			if (event_data->touch_event[i] == 0
				|| event_data->touch_event[i] == 2) {
				TS_LOG_ERR("%s:abnormal touch data from fw.\n",
					__func__);
				return -EINVAL;
			}
		}

		TS_LOG_DEBUG("%s:touch data:\n"
			"(id=%d,x=(0x%02x),y=(0x%02x)),point_num=%d,event=%d\n",
			__func__,
			event_data->finger_id[i],
			event_data->position_x[i],
			event_data->position_y[i],
			event_data->touch_point,
			event_data->touch_event[i]);
	}

	return 0;
}

static int focal_gpio_request(struct ts_kit_device_data *focal_pata)
{
	int ret = 0;

	return ret;
}

static int i2c_communicate_check(struct ts_kit_platform_data *focal_pdata)
{
	int i = 0;
	int ret = NO_ERR;
	u8 cmd = 0;
	u8 reg_val = 0;

	focal_pdata->client->addr = g_focal_dev_data->slave_addr;
	cmd = FTS_REG_CHIP_ID_H;
	for (i = 0; i < I2C_RW_TRIES; i++) {

		ret = focal_read(&cmd, 1, &reg_val, 1);
		if (ret < 0) {
			TS_LOG_ERR("%s:chip id read fail, ret=%d, i=%d\n",
				__func__, ret, i);
			msleep(50);
		} else {
			TS_LOG_INFO("%s:chip id read success, chip id:0x%X\n",
				__func__, reg_val);
			return NO_ERR;
		}
	}

	return ret;
}



static int focal_wrong_touch(void)
{
	return NO_ERR;
}

static int focal_irq_top_half(struct ts_cmd_node *cmd)
{
	cmd->command = TS_INT_PROCESS;
	return NO_ERR;
}

static int focal_read_roidata(void)
{
	u8 buf[1] = { 0 };
	int ret = -1;
	buf[0] = 0x7E; 
	unsigned char temp[2] = {0};
	TS_LOG_DEBUG("%s: Enter!\n", __func__);
	ret = focal_read( buf, 1, focal_roi_data+2,ROI_DATA_READ_LENGTH);
	if (ret < 0) {
		TS_LOG_ERR("%s  failed.\n", __func__);
		return ret;//
	}
	temp[0] = focal_roi_data[2];
	temp[1] = focal_roi_data[3];

	focal_roi_data[0] = (temp[1]>>4)&0x0f;  //index
	focal_roi_data[1] = 0;   //default is 0
	focal_roi_data[2] = temp[0]&0x3f; //rx
	focal_roi_data[3] = ((temp[1]&0x0f)<<2)  + (temp[0]>>6); //tx
	temp[3] = (focal_roi_data[2]>>4)&0x0f;
	TS_LOG_DEBUG("%s: success ,%d \n", __func__,ret);
	return ret;
}

static int focal_set_finger_number(struct ts_fingers *info,
	struct ts_event *touch_data)
{
	/*
	 * why we need this function ?
	 *         when ts kit found info->cur_finger_number is 0,
	 *     ts kit will report BTN_TOUCH UP, otherwize,
	 *     report BTN_TOUCH DOWN.
	 *         the recovery mode will use BTN_TOUCH UP
	 *     to judge if the finger have release, so we need this event.
	 *
	 * what risk at here ?
	 *         we set cur_finger_number to 0, so the ts kit will not report 
	 *     this poit, ts kit will report a BTN_TOUCH UP instead of this
	 *     point. when close FTS_REPORT_BTN_TOUCH, the last two data package
	 *     in input log is like the following two packages, we can open
	 *     FTS_REPORT_BTN_TOUCH, if only the package two is report, we can't
	 *     open FTS_REPORT_BTN_TOUCH.
	 *
	 *     [package 1]
	 *         EV_ABS       ABS_MT_PRESSURE      00000009
	 *         EV_ABS       ABS_MT_POSITION_X    00000434
	 *         EV_ABS       ABS_MT_POSITION_Y    0000075e
	 *         EV_ABS       ABS_MT_TRACKING_ID   00000000
	 *         EV_SYN       SYN_MT_REPORT        00000000
	 *         EV_SYN       SYN_REPORT           00000000
	 *
	 *     [package 2]
	 *         EV_ABS       ABS_MT_PRESSURE      00000000
	 *         EV_ABS       ABS_MT_POSITION_X    00000434
	 *         EV_ABS       ABS_MT_POSITION_Y    0000075e
	 *         EV_ABS       ABS_MT_TRACKING_ID   00000000
	 *         EV_SYN       SYN_MT_REPORT        00000000
	 *         EV_SYN       SYN_REPORT           00000000
	 *
	 * notice: the different between package 1 and package 2 is:
	 *         the value of [package 1]->ABS_MT_POSITION_X is the same as
	 *     [package 2]->ABS_MT_POSITION_X, and so do ABS_MT_POSITION_Y,
	 *     but the ABS_MT_PRESSURE of [package 1] is not 0, and the
	 *     ABS_MT_PRESSURE of [package 2] is 0
	 */

	int i = 0;
	int index = -1;
	u8 check_result = 0;
	struct focal_platform_data *pdata = NULL;
	struct ts_event *last_data = NULL;

	pdata = focal_get_platform_data();
	last_data = &pdata->touch_data;

	/* if this point is the release point, set finger number to 0 */
#ifdef FTS_REPORT_BTN_TOUCH
	if (touch_data->touch_point == 1 && touch_data->pressure[0] == 0) {
		info->cur_finger_number = 0;

		TS_LOG_DEBUG("%s:%s=%d, %s=%d, %s=%d\n",
				__func__,
				"current finger id", touch_data->finger_id[0],
				"last count", last_data->touch_point,
				"current cound", touch_data->touch_point);
		
		for (i = 0; i < last_data->touch_point; i++) {
			TS_LOG_DEBUG("%s:last finger id:%d\n",
				__func__, last_data->finger_id[i]);
			if (last_data->finger_id[i] == touch_data->finger_id[0]) {
				index = i;
				break;
			}
		}

		if (index < 0) {
			TS_LOG_ERR("%s:touch data error, %s\n",
				__func__, "please close FTS_REPORT_BTN_TOUCH");
			return -EIO;
		}
		
		if (last_data->position_x[index] == touch_data->position_x[0]
		&& last_data->position_y[index] == touch_data->position_y[0]) {
			check_result = true;
		}

		if (!check_result) {
			TS_LOG_ERR("%s:not support BTN_TOUCH report, %s\n",
				__func__, "please close FTS_REPORT_BTN_TOUCH");
		}
	} else {
		info->cur_finger_number = touch_data->touch_point;
	}
#else
	info->cur_finger_number = touch_data->touch_point;
#endif

	memcpy(last_data, touch_data, sizeof(struct ts_event));

	return 0;
}

static int focal_irq_bottom_half(struct ts_cmd_node *in_cmd,
	struct ts_cmd_node *out_cmd)
{
	int x = 0;
	int y = 0;
	int z = 0;
	int wx = 0;
	int wy = 0;

	int i = 0;
	int ret = 0;
	int touch_count = 0;
	int roi_package_num= 0; 
	struct ts_event st_touch_data;
	struct algo_param *algo_p = NULL;
	struct ts_fingers *info = NULL;

	algo_p = &out_cmd->cmd_param.pub_params.algo_param;
	info = &algo_p->info;

	out_cmd->command = TS_INPUT_ALGO;
	algo_p->algo_order = g_focal_dev_data->algo_id;
	TS_LOG_DEBUG("%s:algo_order:%d\n", __func__, algo_p->algo_order);

	ret = focal_read_touch_data(&st_touch_data);
	if (ret)
		return ret;

	for (i = 0; i < st_touch_data.touch_point; i++) {
		x = st_touch_data.position_x[i];
		y = st_touch_data.position_y[i];
		wx = st_touch_data.area[i];
		wy = st_touch_data.area[i];
		z = st_touch_data.pressure[i];

		info->fingers[st_touch_data.finger_id[i]].status = TP_FINGER;
		info->fingers[st_touch_data.finger_id[i]].x = x;
		info->fingers[st_touch_data.finger_id[i]].y = y;
		info->fingers[st_touch_data.finger_id[i]].major = wx;
		info->fingers[st_touch_data.finger_id[i]].minor = wy;
		info->fingers[st_touch_data.finger_id[i]].pressure = z;

		touch_count++;

		TS_LOG_DEBUG("%s:%d:x = %d; y = %d; wx = %d; wy = %d\n",
			 __func__,
			 st_touch_data.finger_id[i], x, y, wx, wy);
	}
#ifdef ROI
	if(g_focal_dev_data->ts_platform_data->feature_info.roi_info.roi_switch){
		focal_read_reg(0x9c, &roi_package_num);
	}
	if(roi_package_num > 0){
		//focal_roi_data[ROI_DATA_READ_LENGTH] = roi_package_num;
		focal_read_roidata();
	}
#endif
	//info->cur_finger_number = touch_count;
	focal_set_finger_number(info, &st_touch_data);
	TS_LOG_DEBUG("%s:touch_count = %d\n", __func__, touch_count);

	return NO_ERR;
}
static int focal_get_brightness_info(void)
{
	int error = NO_ERR;
	
	
	return error ;
}

static int focal_fw_update_boot(char *file_name)
{
	return focal_firmware_auto_update(g_focal_pdata, file_name);
}

static int focal_fw_update_sd(void)
{
	int ret =0 ;
	ret =  focal_firmware_manual_update(g_focal_pdata,
		FTS_FW_MANUAL_UPDATE_FILE_NAME);
	if (ret < 0) {
		TS_LOG_ERR("Failed to update fw sd  err: %d\n",  ret);
	}
	ret = focal_rmi4_status_resume();
	if (ret < 0) {
		TS_LOG_ERR("status resume  err: %d\n",  ret);
	}
	return ret ;
}

static int focal_chip_get_info(struct ts_chip_info_param *info)
{
	size_t ic_vendor_size = 0;
	size_t fw_vendor_size = 0;

	struct focal_platform_data *focal_pdata = NULL;

	focal_pdata = focal_get_platform_data();

	ic_vendor_size = CHIP_INFO_LENGTH * 2;
	strncpy(info->ic_vendor, FTS_CHIP_NAME, ic_vendor_size);
	focal_strncat(info->ic_vendor, "-", ic_vendor_size);
	focal_strncat(info->ic_vendor, focal_pdata->project_id, ic_vendor_size);

	strncpy(info->mod_vendor, focal_pdata->vendor_name, CHIP_INFO_LENGTH);

	fw_vendor_size = CHIP_INFO_LENGTH * 2;
	snprintf(info->fw_vendor, fw_vendor_size, "%d", focal_pdata->fw_ver);

	return NO_ERR;
}

static int focal_set_info_flag(struct ts_kit_device_data *info)
{
	return NO_ERR;
}

static int focal_before_suspend(void)
{
	return NO_ERR;
}

static int focal_suspend(void)
{
	focal_write_reg(FTS_REG_SLEEP, 0x03);
	return NO_ERR;
}
static int focal_resume(void)
{
	return NO_ERR;
}

static int focal_rmi4_status_resume(void)
{
	int retval = 0;
	struct ts_feature_info *info = &g_focal_dev_data->ts_platform_data->feature_info;

	retval =focal_set_holster_switch(info->holster_info.holster_switch);
	if (retval < 0) {
		TS_LOG_ERR("Failed to set holster switch(%d), err: %d\n",
			   info->holster_info.holster_switch, retval);
	}

	if (info->roi_info.roi_supported) {
		retval = focal_set_roi_switch(info->roi_info.roi_switch);
		if (retval < 0) {
			TS_LOG_ERR("%s, synaptics_set_roi_switch faild\n",
				   __func__);
		}
	}

	retval = focal_set_glove_switch(info->glove_info.glove_switch);
	if (retval < 0) {
		TS_LOG_ERR("Failed to set glove switch(%d), err: %d\n",
			   info->glove_info.glove_switch, retval);
	}
	TS_LOG_INFO(" glove_switch (%d), holster switch(%d), roi_switch(%d) \n",
			   info->glove_info.glove_switch,info->holster_info.holster_switch,info->roi_info.roi_switch);
	return retval;
}

static int focal_after_resume(void *feature_info)
{	
	int retval = 0;
	
	retval = focal_rmi4_status_resume();
	return retval;
}

static int focal_wakeup_gesture_enable_switch(
	struct ts_wakeup_gesture_enable_info *info)
{

	return NO_ERR;
}

static void focal_shutdown(void)
{

}

static int focal_input_config(struct input_dev *input_dev)
{
	set_bit(EV_SYN, input_dev->evbit);
	set_bit(EV_KEY, input_dev->evbit);
	set_bit(EV_ABS, input_dev->evbit);
	set_bit(BTN_TOUCH, input_dev->keybit);
	set_bit(BTN_TOOL_FINGER, input_dev->keybit);

	set_bit(TS_PALM_COVERED, input_dev->keybit);

#ifdef INPUT_PROP_DIRECT
	set_bit(INPUT_PROP_DIRECT, input_dev->propbit);
#endif

	input_set_abs_params(input_dev, ABS_X,
		0, (g_focal_dev_data->x_max - 1), 0, 0);
	input_set_abs_params(input_dev, ABS_Y,
		0, (g_focal_dev_data->y_max - 1), 0, 0);
	input_set_abs_params(input_dev, ABS_PRESSURE, 0, 255, 0, 0);
	input_set_abs_params(input_dev, ABS_MT_TRACKING_ID, 0, 10, 0, 0);

	input_set_abs_params(input_dev, ABS_MT_POSITION_X, 0,
		(g_focal_dev_data->x_max - 1), 0, 0);
	input_set_abs_params(input_dev, ABS_MT_POSITION_Y, 0,
		(g_focal_dev_data->y_max - 1), 0, 0);
	input_set_abs_params(input_dev, ABS_MT_PRESSURE, 0, 255, 0, 0);

#ifdef REPORT_2D_W
	input_set_abs_params(input_dev, ABS_MT_TOUCH_MAJOR, 0,
		MAX_ABS_MT_TOUCH_MAJOR, 0, 0);
#endif

#ifdef TYPE_B_PROTOCOL
#ifdef KERNEL_ABOVE_3_7
	/* input_mt_init_slots now has a "flags" parameter */
	input_mt_init_slots(input_dev, 10, INPUT_MT_DIRECT);
#else
	input_mt_init_slots(input_dev, 10);
#endif
#endif

	return NO_ERR;
}

static int focal_reset_device(void)
{
	return focal_hardware_reset_to_normal_model();
}

static int focal_palm_switch(struct ts_palm_info *info)
{
	return NO_ERR;
}

static int focal_glove_switch(struct ts_glove_info *info)
{
	int ret = 0;

	if (!info) {
		TS_LOG_ERR("%s:info is null\n", __func__);
		ret = -ENOMEM;
		return ret;
	}

	switch (info->op_action) {
	case TS_ACTION_READ:
		ret = focal_get_glove_switch(&info->glove_switch);
		if (ret) {
			TS_LOG_ERR("%s:get glove switch fail,ret=%d\n",
				__func__, ret);
			return ret;
		} else {
			TS_LOG_INFO("%s:glove switch=%d\n",
				__func__, info->glove_switch);
		}

		break;
	case TS_ACTION_WRITE:
		TS_LOG_INFO("%s:glove switch=%d\n",
			__func__, info->glove_switch);
		ret = focal_set_glove_switch(!!info->glove_switch);
		if (ret) {
			TS_LOG_ERR("%s:set glove switch fail, ret=%d\n",
				__func__, ret);
			return ret;
		}

		break;
	default:
		TS_LOG_ERR("%s:invalid op action:%d\n",
			__func__, info->op_action);
		return -EINVAL;
	}

	return 0;
}

static struct ts_glove_info *focal_get_glove_info(
	struct ts_kit_device_data *dev_data)
{
	return &dev_data->ts_platform_data->feature_info.glove_info;
}

static int focal_get_glove_switch(u8 *glove_switch)
{
	int ret = 0;

	u8 cmd = 0;
	u8 glove_value;
	u8 glove_enable_addr;

	struct ts_glove_info *glove_info = NULL;

	glove_info = focal_get_glove_info(g_focal_dev_data);
	glove_enable_addr = glove_info->glove_switch_addr;

	TS_LOG_INFO("%s:glove_enable_addr=%d\n", __func__, glove_enable_addr);
	if (!glove_enable_addr) {
		TS_LOG_ERR("%s:glove addr is 0, glove feature not support\n",
			__func__);
		return -ENOTSUPP;
	}

	cmd = glove_enable_addr;

	ret = focal_read_reg(cmd, &glove_value);
	if (ret) {
		TS_LOG_ERR("%s:read glove switch fail, ret=%d\n",
			__func__, ret);
		return ret;
	}

	*glove_switch = glove_value;

	TS_LOG_INFO("%s:glove value=%d\n", __func__, *glove_switch);
	return ret;
}

static int focal_set_glove_switch(u8 glove_switch)
{
	int ret = 0;

	u8 cmd[2] = {0};
	u8 glove_value = 0;
	u8 glove_enable_addr = 0;


	struct ts_glove_info *glove_info = NULL;

	glove_info = focal_get_glove_info(g_focal_dev_data);
	glove_enable_addr = glove_info->glove_switch_addr;

	TS_LOG_INFO("%s:glove_enable_addr=%d\n", __func__, glove_enable_addr);
	if (!glove_enable_addr) {
		TS_LOG_ERR("%s:glove_enable_addr is 0, not support glove.\n",
			__func__);

		return -ENOTSUPP;
	}

	if (glove_switch)
		glove_value = 1;
	else
		glove_value = 0;

	cmd[0] = glove_enable_addr;
	cmd[1] = glove_value;

	ret = focal_write(cmd, 2);
	if (ret) {
		TS_LOG_ERR("%s:write glove switch fail, ret=%d\n",
			__func__, ret);
		return ret;
	}

	return 0;
}

#if defined(HUAWEI_CHARGER_FB)
static int focal_charger_switch(struct ts_charger_info *info)
{
	return NO_ERR;
}
#endif

static struct ts_holster_info *focal_get_holster_info(
	struct ts_kit_device_data *dev_data)
{
	return &dev_data->ts_platform_data->feature_info.holster_info;
}

static int focal_get_holster_switch(u8 *holster_switch)
{
	int ret = 0;

	u8 cmd = 0;
	u8 holster_value;
	u8 holster_switch_addr;

	struct ts_holster_info *holster_info = NULL;

	holster_info = focal_get_holster_info(g_focal_dev_data);
	holster_switch_addr = holster_info->holster_switch_addr;

	TS_LOG_INFO("%s:holster_switch_addr=%d\n", __func__, holster_switch_addr);
	if (!holster_switch_addr) {
		TS_LOG_ERR("%s:holster_switch_addr is 0, not support holster.\n",
			__func__);

		return -ENOTSUPP;
	}

	cmd = holster_switch_addr;

	ret = focal_read_reg(cmd, &holster_value);
	if (ret) {
		TS_LOG_ERR("%s:read holsterswitch fail, ret=%d\n",
			__func__, ret);
		return ret;
	}

	*holster_switch = holster_value;

	TS_LOG_INFO("%s: holster_value=%d\n", __func__, *holster_switch);
	return ret;
}


static int focal_set_holster_switch(u8 holster_switch)
{
	int ret = 0;

	u8 cmd[2] = {0};
	u8 holster_value = 0;
	u8 holster_switch_addr = 0;


	struct ts_holster_info *holster_info = NULL;

	holster_info = focal_get_holster_info(g_focal_dev_data);
	holster_switch_addr = holster_info->holster_switch_addr;

	TS_LOG_INFO("%s:holster_switch_addr=%d\n", __func__, holster_switch_addr);
	if (!holster_switch_addr) {
		TS_LOG_ERR("%s:holster_switch_addr is 0, not support holster.\n",
			__func__);

		return -ENOTSUPP;
	}

	if (holster_switch)
		holster_value = 1;
	else
		holster_value = 0;

	cmd[0] = holster_switch_addr;
	cmd[1] = holster_value;

	ret = focal_write(cmd, 2);
	if (ret) {
		TS_LOG_ERR("%s:write holster switch fail, ret=%d\n",
			__func__, ret);
		return ret;
	}

	return 0;
}
static int focal_holster_switch(struct ts_holster_info  *info)
{
	int ret = 0;

	if (!info) {
		TS_LOG_ERR("%s:info is null\n", __func__);
		ret = -ENOMEM;
		return ret;
	}

	switch (info->op_action) {
	case TS_ACTION_READ:
		ret = focal_get_holster_switch(&info->holster_switch);
		if (ret) {
			TS_LOG_ERR("%s:get glove switch fail,ret=%d\n",
				__func__, ret);
			return ret;
		} else {
			TS_LOG_INFO("%s:glove switch=%d\n",
				__func__, info->holster_switch);
		}

		break;
	case TS_ACTION_WRITE:
		TS_LOG_INFO("%s:glove switch=%d\n",
			__func__, info->holster_switch);
		ret = focal_set_holster_switch(!!info->holster_switch);
		if (ret) {
			TS_LOG_ERR("%s:set glove switch fail, ret=%d\n",
				__func__, ret);
			return ret;
		}

		break;
	default:
		TS_LOG_ERR("%s:invalid op action:%d\n",
			__func__, info->op_action);
		return -EINVAL;
	}

	return 0;
}

static struct ts_roi_info *focal_get_roi_info(
	struct ts_kit_device_data *dev_data)
{
	return &dev_data->ts_platform_data->feature_info.roi_info;
}
static int focal_set_roi_switch(u8 roi_switch)
{
	int ret = 0;

	u8 cmd[2] = {0};
	u8 roi_value = 0;
	u8 roi_switch_addr =0;
	struct ts_roi_info *roi_info = NULL;
#ifdef ROI
	roi_info = focal_get_roi_info(g_focal_dev_data);
	roi_switch_addr = roi_info->roi_control_addr;

	TS_LOG_INFO("%s:roi_switch_addr=%d\n", __func__, roi_switch_addr);
	if (!roi_switch_addr) {
		TS_LOG_ERR("%s:roi_switch_addr is 0, not support roi.\n",
			__func__);

		return -ENOTSUPP;
	}

	if (roi_switch)
		roi_value = 1;
	else
		roi_value = 0;

	cmd[0] = roi_switch_addr;
	cmd[1] = roi_value;

	ret = focal_write(cmd, 2);
	if (ret) {
		TS_LOG_ERR("%s:write holster switch fail, ret=%d\n",
			__func__, ret);
		return ret;
	}
#endif
	return 0;
}

static int focal_get_roi_switch(u8 *roi_switch)
{
	int ret = 0;

	u8 cmd = 0;
	u8 roi_value =0;
	u8 roi_switch_addr =0;

	struct ts_roi_info *roi_info = NULL;
#ifdef ROI
	roi_info = focal_get_roi_info(g_focal_dev_data);
	roi_switch_addr = roi_info->roi_control_addr;

	TS_LOG_INFO("%s:roi_switch_addr=%d\n", __func__, roi_switch_addr);
	if (!roi_switch_addr) {
		TS_LOG_ERR("%s:roi_switch_addr is 0, not support roi.\n",
			__func__);

		return -ENOTSUPP;
	}

	cmd = roi_switch_addr;

	ret = focal_read_reg(cmd, &roi_value);
	if (ret) {
		TS_LOG_ERR("%s:read roi  switch fail, ret=%d\n",
			__func__, ret);
		return ret;
	}

	*roi_switch = roi_value;

	TS_LOG_INFO("%s: roi_value=%d\n", __func__, *roi_switch);
#endif
	return ret;
}
static int focal_roi_switch(struct ts_roi_info *info)
{
	int ret = 0;
	int i=0;
#ifdef ROI
	TS_LOG_INFO("%s: Enter!\n", __func__);
	if (!info) {
		TS_LOG_ERR("%s:info is null\n", __func__);
		ret = -ENOMEM;
		return ret;
	}

	switch (info->op_action) {
	case TS_ACTION_READ:
		ret = focal_get_roi_switch(&info->roi_switch);
		if (ret) {
			TS_LOG_ERR("%s:get roi switch fail,ret=%d\n",
				__func__, ret);
			return ret;
		} else {
			TS_LOG_INFO("%s:roi switch=%d\n",
				__func__, info->roi_switch);
		}

		break;
	case TS_ACTION_WRITE:
		TS_LOG_INFO("%s:roi switch=%d\n",
			__func__, info->roi_switch);
		ret = focal_set_roi_switch(!!info->roi_switch);
		if (ret) {
			TS_LOG_ERR("%s:set roi switch fail, ret=%d\n",
				__func__, ret);
			return ret;
		}
		if(!info->roi_switch){
			for (i = 0; i < ROI_DATA_READ_LENGTH; i++) {
				focal_roi_data[i] = 0;
			}
		}

		break;
	default:
		TS_LOG_ERR("%s:invalid op action:%d\n",
			__func__, info->op_action);
		return -EINVAL;
	}
#endif
	return 0;
}

static unsigned char *focal_roi_rawdata(void)
{
#ifdef ROI
	return (unsigned char *)focal_roi_data;
#else
	return NULL;
#endif
}

static int focal_calibrate(void)
{
	return NO_ERR;
}

static int focal_calibrate_wakeup_gesture(void)
{
	return NO_ERR;
}

#if defined(CONFIG_HUAWEI_DSM)
static int focal_rmi4_dsm_debug(void)
{
	return NO_ERR;
}

#endif

static int focal_regs_operate(struct ts_regs_info *info)
{
	return NO_ERR;
}

static int focal_param_init(struct focal_platform_data *focal_pdata)
{
	int ret = 0;
	u8 fw_ver = 0;
	u8 vendor_id = 0;

	/* init project id and fw_ver and chip id */
	ret = focal_read_project_id(focal_pdata,
		focal_pdata->project_id, FTS_PROJECT_ID_LEN - 1);
	if (ret) {
		TS_LOG_ERR("%s:read project id fail, ret=%d,hope update fw to recovery!\n", __func__, ret);
//		memset(focal_pdata->project_id,0,FTS_PROJECT_ID_LEN);
		return ret;
	}

	ret = focal_read_chip_id(focal_pdata, &focal_pdata->chip_id);
	if (ret) {
		TS_LOG_ERR("%s:read chip id fail, ret=%d\n", __func__, ret);
		return ret;
	}

	ret = focal_get_vendor_name_from_dts(focal_pdata->project_id,
		focal_pdata->vendor_name, FTS_VENDOR_NAME_LEN);
	if (ret) {
		TS_LOG_ERR("%s:read vendor name fail, ret=%d\n", __func__, ret);
		return ret;
	}

	ret = focal_read_vendor_id(focal_pdata, &vendor_id);
	if (ret) {
		TS_LOG_ERR("%s:read vendor id fail, ret=%d\n", __func__, ret);
		return ret;
	} else {
		focal_pdata->vendor_id = vendor_id;
	}

	ret = focal_get_ic_firmware_version(&fw_ver);
	if (ret) {
		TS_LOG_ERR("%s:read firmware version fail, ret=%d\n",
			__func__, ret);
		return ret;
	} else {
		focal_pdata->fw_ver = fw_ver;
	}

	return 0;
}
static int focal_pinctrl_init(void)
{
	int ret = 0;

	g_focal_pdata->pctrl= devm_pinctrl_get(&g_focal_dev_data->ts_platform_data->ts_dev->dev);
	if (IS_ERR(g_focal_pdata->pctrl)) {
		TS_LOG_ERR("failed to devm pinctrl get\n");
		ret = -EINVAL;
		return ret;
	}

	g_focal_pdata->pins_default =
	    pinctrl_lookup_state(g_focal_pdata->pctrl, "default");
	if (IS_ERR(g_focal_pdata->pins_default)) {
		TS_LOG_ERR("failed to pinctrl lookup state default\n");
		ret = -EINVAL;
		goto err_pinctrl_put;
	}

	g_focal_pdata->pins_idle = pinctrl_lookup_state(g_focal_pdata->pctrl, "idle");
	if (IS_ERR(g_focal_pdata->pins_idle)) {
		TS_LOG_ERR("failed to pinctrl lookup state idle\n");
		ret = -EINVAL;
		goto err_pinctrl_put;
	}
	return 0;

err_pinctrl_put:
	devm_pinctrl_put(g_focal_pdata->pctrl);
	return ret;
}

static int focal_init_chip(void)
{
	int ret = NO_ERR;

	struct focal_platform_data *focal_pdata = NULL;
	struct focal_delay_time *delay_time = NULL;
	struct ts_kit_device_data *focal_dev_data = NULL;
	struct ts_kit_platform_data *ts_platform_data = NULL;

	focal_pdata = kzalloc(sizeof(struct focal_platform_data), GFP_KERNEL);
	if (!focal_pdata) {
		TS_LOG_ERR("%s:allocate memory for g_focal_pdata fail\n",
			__func__);
		return -ENOMEM;
	}
	memset(focal_pdata, 0, sizeof(struct focal_platform_data));
	delay_time = kzalloc(sizeof(struct focal_delay_time), GFP_KERNEL);
	if (!delay_time) {
		TS_LOG_ERR("%s:allocate memory for delay_time fail\n",
			__func__);
		ret = -ENOMEM;
		goto free_focal_pdata;
	}

	focal_pdata->delay_time = delay_time;
	g_focal_pdata = focal_pdata;
	g_focal_pdata->focal_device_data = g_focal_dev_data;
	focal_dev_data = g_focal_dev_data;

	ret = focal_parse_dts(focal_dev_data->cnode, focal_pdata);
	if (ret) {
		TS_LOG_ERR("%s:parse dts fail, ret=%d\n", __func__, ret);
		goto free_delay_time;
	}

	ts_platform_data = focal_dev_data->ts_platform_data;

	focal_pdata->focal_platform_dev = ts_platform_data->ts_dev;
	focal_dev_data->is_in_cell = true;
	focal_dev_data->easy_wakeup_info.sleep_mode = TS_POWER_OFF_MODE;
	focal_dev_data->easy_wakeup_info.easy_wakeup_gesture = false;
	focal_dev_data->easy_wakeup_info.easy_wakeup_flag = false;
	focal_dev_data->easy_wakeup_info.palm_cover_flag = false;
	focal_dev_data->easy_wakeup_info.palm_cover_control = false;
	focal_dev_data->easy_wakeup_info.off_motion_on = false;
	ts_platform_data->feature_info.holster_info.holster_switch = false;

	ret = focal_gpio_request(focal_dev_data);
	if (ret < 0) {
		TS_LOG_ERR("%s:gpio reauest fail, ret=%d\n", __func__, ret);
		goto free_delay_time;
	}
	ret = focal_apk_node_init();
	if (ret < 0) {
		TS_LOG_ERR("%s:apk_node_init error, ret=%d\n", __func__, ret);
		goto free_delay_time;
	}

	ret = focal_param_init(focal_pdata);
	if (ret) {
		TS_LOG_ERR("%s:init param fail, ret=%d\n", __func__, ret);
		goto apk_node_exit;
	}
/*
       ret = focal_pinctrl_init();
	if (ret) {
		TS_LOG_ERR("%s:focal_pinctrl_init fail, ret=%d\n", __func__, ret);
		goto apk_node_exit;
	}
       ret = pinctrl_select_state(g_focal_pdata->pctrl, g_focal_pdata->pins_default);
	if (ret < 0) {
		TS_LOG_ERR("set iomux normal error, %d\n", ret);
		goto apk_node_exit;
	}
	gpio_direction_input(g_focal_dev_data->ts_platform_data->irq_gpio);
*/
	TS_LOG_INFO("%s:init chip success.\n", __func__);
	return NO_ERR;

apk_node_exit:
	//focal_apk_node_exit();

free_delay_time:
	//kfree(focal_pdata->delay_time);
free_focal_pdata:
	//don't free focal_pdata,firmware upgrade will use this parameter
	TS_LOG_ERR("%s:focal init chip error.\n", __func__);

	return ret;
}

static int focal_chip_detect(struct ts_kit_platform_data *pdata)
{
	int ret = NO_ERR;

	g_focal_dev_data->ts_platform_data = pdata;

	if ((!pdata) &&(!pdata->ts_dev)){
		TS_LOG_ERR("%s device, ts_kit_platform_data *data or data->ts_dev is NULL \n", __func__);
		ret = -ENOMEM;
		goto exit;
	}
	g_focal_dev_data->is_i2c_one_byte = 0;
	g_focal_dev_data->is_new_oem_structure= 0;
	g_focal_dev_data->is_parade_solution= 0;
	ret = focal_prase_ic_config_dts(g_focal_dev_data->cnode, g_focal_dev_data);
	if (ret) {
		TS_LOG_ERR("%s:parse ic config dts fail, ret=%d\n",
			__func__, ret);
		goto exit;
	}
#if 0
	ret = gpio_request(g_focal_dev_data->reset_gpio, "ts_reset_gpio");
	if (ret < 0) {
		TS_LOG_ERR("%s:Fail request gpio:%d, ret=%d\n",
			__func__, g_focal_dev_data->reset_gpio, ret);
		goto exit;
	}
#endif
	ret = focal_hardware_reset(FTS_MODEL_FIRST_START);
	if (ret) {
		TS_LOG_ERR("%s:hardware reset fail, ret=%d\n",
			__func__, ret);
		return ret;
	}

	ret = i2c_communicate_check(pdata);
	if (ret < 0) {
		TS_LOG_ERR("%s:not find focal device, ret=%d\n", __func__, ret);
		goto exit_free_reset_gpio;
	} else {
		TS_LOG_INFO("%s:find focal device\n", __func__);

		strncpy(g_focal_dev_data->chip_name, FTS_CHIP_NAME, MAX_STR_LEN);
	}
	   
	
	TS_LOG_INFO("%s:focal chip detect success\n", __func__);

	return 0;

exit_free_reset_gpio:
	//gpio_free(g_focal_dev_data->reset_gpio);
exit:

	TS_LOG_INFO("%s:focal chip detect fail\n", __func__);
	return ret;
}

static int __init focal_core_module_init(void)
{
	int ret = NO_ERR;
	bool found = false;
	struct device_node *child = NULL;
	struct device_node *root = NULL;

	TS_LOG_INFO("%s: called\n", __func__);

	g_focal_dev_data =
		kzalloc(sizeof(struct ts_kit_device_data), GFP_KERNEL);
	if (NULL == g_focal_dev_data) {
		TS_LOG_ERR("%s:alloc mem for device data fail\n", __func__);
		ret = -ENOMEM;
		goto error_exit;
	}

	root = of_find_compatible_node(NULL, NULL, HUAWEI_TS_KIT);
	if (!root) {
		TS_LOG_ERR("%s:find_compatible_node error\n", __func__);
		ret = -EINVAL;
		goto error_exit;
	}

	for_each_child_of_node(root, child) {
		if (of_device_is_compatible(child, FTS_CHIP_NAME)) {
			found = true;
			break;
		}
	}

	if (!found) {
		TS_LOG_ERR("%s:device tree node not found, name=%s\n",
			__func__, FTS_CHIP_NAME);
		ret = -EINVAL;
		goto error_exit;
	}

	g_focal_dev_data->cnode = child;
	g_focal_dev_data->ops = &ts_focal_ops;
	ret = huawei_ts_chip_register(g_focal_dev_data);
	if (ret) {
		TS_LOG_ERR("%s:chip register fail, ret=%d\n", __func__, ret);
		goto error_exit;
	}

	TS_LOG_INFO("%s:success\n", __func__);
	return 0;

error_exit:
	kfree(g_focal_dev_data);
	g_focal_dev_data = NULL;
	TS_LOG_INFO("%s:fail\n", __func__);
	return ret;
}

static void __exit focal_ts_module_exit(void)
{
	kfree(g_focal_dev_data);
	g_focal_dev_data = NULL;

	return;
}

late_initcall(focal_core_module_init);
module_exit(focal_ts_module_exit);
MODULE_AUTHOR("Huawei Device Company");
MODULE_DESCRIPTION("Huawei TouchScreen Driver");
MODULE_LICENSE("GPL");
