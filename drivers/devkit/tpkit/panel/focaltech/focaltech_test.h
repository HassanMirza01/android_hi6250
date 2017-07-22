

#ifndef _FOCALTECH_TEST_FT8716_H_
#define _FOCALTECH_TEST_FT8716_H_

#include <linux/kernel.h>
#include <focaltech_core.h>

#define bool  unsigned char
#define BYTE  unsigned char
#define false 0
#define true  1

#define TX_NUM_MAX			30
#define RX_NUM_MAX			30
#define DEVICE_MODE_ADDR		0x00
#define DEVICE_MODE_WORK		0x00
#define DEVICE_MODE_FACTORY		0x40

#define FTS_SCAN_MAX_TIME		160
#define FTS_SCAN_QUERY_DELAY		8

#define BYTES_PER_TIME			128
#define MAX_RETRY_TIMES			3

#define FTS_RESULT_CODE_LEN		4
#define FTS_TEST_NAME_LEN		16
#define FTS_STATISTICS_DATA_LEN		32
#define FTS_DATA_TYPE_DIFF		1
#define FTS_DATA_TYPE_RAW		0
#define FTS_LCD_NOISE_TEST_FRAME_COUNT	50

#define FTS_LCD_PRE_FRAME_TIME		16
#define FTS_MAX_CAP_TEST_NUM		5

struct focal_test_threshold {
	int raw_data_min;
	int raw_data_max;

	int cb_test_min;
	int cb_test_max;

	int short_circuit_min;
	int  lcd_noise_max;
	int open_test_cb_min;
};

struct focal_test_params {
	struct focal_test_threshold threshold;

	u8 channel_x_num;
	u8 channel_y_num;
	u8 key_num;
};

struct focal_test_result {
	int result;
	int *values;
	size_t size;
	char test_name[FTS_TEST_NAME_LEN];
	char result_code[FTS_RESULT_CODE_LEN];
};

int focal_parse_cap_test_config(struct focal_platform_data *pdata,
	struct focal_test_params *params);
void focal_set_max_channel_num(struct focal_test_params *params);

bool focal_start_test_tp(struct focal_test_params *params,
	struct ts_rawdata_info *info);

int focal_get_debug_data_(int data_type, int *data, size_t size);
int focal_get_channel_num(u8 *chl_x, u8 *chl_y);

int focal_get_raw_data(struct ts_rawdata_info *info,
	struct ts_cmd_node *out_cmd);
int focal_get_debug_data(struct ts_diff_data_info *info,
	struct ts_cmd_node *out_cmd);
int focal_chip_get_capacitance_test_type(struct ts_test_type_info *info);

#endif
