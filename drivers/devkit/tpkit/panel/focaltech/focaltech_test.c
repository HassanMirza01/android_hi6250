#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/slab.h>
#include "focaltech_test.h"
#include "focaltech_core.h"
#include "focaltech_flash.h"

#define DEVICE_MODE_ADDR		0x00
#define FTS_REG_DATA_TYPE		0x01
#define REG_TX_NUM			0x02
#define REG_RX_NUM			0x03

#define REG_CB_ADDR_H			0x18
#define REG_CB_ADDR_L			0x19

#define REG_RAW_BUF0			0x6A
#define REG_CB_BUF0			0x6E

#define REG_CLB				0x04
#define REG_8607_LCD_NOISE_FRAME  0X12
#define REG_8607_LCD_NOISE_START  0X11
#define REG_8607_LCD_NOISE_NUMBER 0X13
#define REG_8607_LCD_NOISE_VALUE   0X80
#define REG_DATA_TYPE			0x06
#define DATA_TYPE_RAW_DATA		0xAD
#define DEBUG_DETA_DIFF_DATA		0x01
#define DEBUG_DATA_RAW_DATA		0x00

#define REG_ADC_SCAN			0x0F
#define REG_ADC_SCAN_STATUS		0x10
#define REG_ADC_DATA_ADDR		0x89
#define MAX_ADC_NUM			    2047
#define MAX_ADC_NUM_FT8607	    2007

#define REG_GIP			     	0x20
#define MAX_CB_VALUE			200
#define TP_TEST_FAILED_REASON_LEN			20

#define ERROR_CODE_OK			0x00

static char tp_test_failed_reason[TP_TEST_FAILED_REASON_LEN] = { "-software_reason" };

static int  tp_cap_test_status =true;

static int focal_start_scan(void);
static int focal_chip_clb(void);
static int focal_read_raw_data(u8 data_type, u8 *raw_data, size_t size);

static int focal_read_channel_x(u8 *chl_x);
static int focal_read_channel_y(u8 *chl_y);

static int focal_get_cb_data(int offset, u8 *data, size_t data_size);
static int focal_get_adc_data(int *data, size_t size);
static int focal_get_raw_data_format(int *data, size_t size);

static void focal_print_test_data(char *msg, int row, int col, int max,
	int min, int value);

static void focal_put_test_result(struct focal_test_params *params,
	struct ts_rawdata_info *info, struct focal_test_result *test_results[],
	int size);

static int focal_alloc_test_container(struct focal_test_result **result,
	size_t data_size);
static void focal_free_test_container(struct focal_test_result *result);

static int focal_get_channel_form_ic(struct focal_test_params *params);
static int focal_init_test_prm(struct focal_platform_data *pdata,
	struct focal_test_params *params);

static int focal_raw_data_test(struct focal_test_params *params,
	struct focal_test_result **result,char test_num);
static int focal_cb_test(struct focal_test_params *params,
	struct focal_test_result **result,char test_num);
static int focal_open_test(struct focal_test_params *params,
	struct focal_test_result **result,char test_num);
static int focal_short_circuit_test(struct focal_test_params *params,
	struct focal_test_result **result,char test_num);
static int focal_enter_work(void);
static int focal_enter_factory(void);
static int focal_lcd_noise_test(struct focal_test_params *params,
	struct focal_test_result **result,char test_num);

static int focal_abs(int value);


static int focal_abs(int value)
{
	return value < 0 ? -value : value;
}

static int focal_enter_work(void)
{
	int i = 0;
	int ret = 0;
	u8 ret_val = 0;

	TS_LOG_INFO("%s: enter work\n", __func__);

	for (i = 0; i < MAX_RETRY_TIMES; i++) {
		ret = focal_read_reg(DEVICE_MODE_ADDR, &ret_val);
		if (ret) {
			TS_LOG_ERR("%s: read DEVICE_MODE_ADDR reg failed\n",
				__func__);
			return ret;
		}
		if (((ret_val >> 4) & 0x07) != DEVICE_MODE_WORK) {
			ret = focal_write_reg(DEVICE_MODE_ADDR, DEVICE_MODE_WORK);
			if (!ret) {
				msleep(50);
				continue;
			} else {
				TS_LOG_ERR("%s: change work mode failed\n",
					__func__);
				break;
			}
		} else {
			TS_LOG_INFO("%s: change work mode success\n", __func__);
			break;
		}
	}

	return ret;
}

static int focal_enter_factory(void)
{
	int i = 0;
	int ret = 0;
	u8 ret_val = 0;

	TS_LOG_INFO("%s: start change factory mode\n", __func__);
	for (i = 0; i < MAX_RETRY_TIMES; i++) {
		ret = focal_read_reg(DEVICE_MODE_ADDR, &ret_val);
		if (ret) {
			TS_LOG_ERR("%s: read DEVICE_MODE_ADDR error\n",
				__func__);
			return ret;
		}

		if (((ret_val >> 4) & 0x07) == 0x04) {
			TS_LOG_INFO("%s: change factory success\n", __func__);
			return 0;
		} else {
			ret = focal_write_reg(DEVICE_MODE_ADDR,
				DEVICE_MODE_FACTORY);
			if (!ret) {
				msleep(50);
				continue;
			} else {
				TS_LOG_ERR("%s: write reg failed\n",
					__func__);
				return ret;
			}
		}
	}

	TS_LOG_INFO("%s: end change factory mode\n", __func__);
	return ret;
}

static int focal_get_int_average(int *p, size_t len)
{
	long long sum = 0;
	size_t i = 0;

	if (!p)
		return 0;

	for (i = 0; i < len; i++)
		sum += p[i];

	if (len != 0)
		return (int)(sum / len);
	else
		return 0;
}

static int focal_get_int_min(int *p, size_t len)
{
	int min = 0;
	size_t i = 0;

	if (!p || len <= 0)
		return 0;

	min = p[0];
	for (i = 0; i < len; i++)
		min = min > p[i] ? p[i] : min;

	return min;
}

static int focal_get_int_max(int *p, size_t len)
{
	int max = 0;
	size_t i = 0;

	if (!p || len <= 0)
		return 0;

	max = p[0];
	for (i = 0; i < len; i++)
		max = max < p[i] ? p[i] : max;

	return max;
}

void focal_set_max_channel_num(struct focal_test_params *params)
{
}

bool focal_start_test_tp(
	struct focal_test_params *params,
	struct ts_rawdata_info *info)
{
	bool btest_result = true;
	char cap_test_num = 0;
	int i = 0;
	int ret = 0;
	struct focal_test_result *test_results[FTS_MAX_CAP_TEST_NUM] = {0};

	TS_LOG_INFO("%s: start test tp\n",  __func__);

	/*  raw data test */
	ret = focal_raw_data_test(params, &test_results[cap_test_num],cap_test_num++);

	/*  cb data test */
	ret = focal_cb_test(params, &test_results[cap_test_num],cap_test_num++);
	if(FOCAL_FT8716 == g_focal_dev_data->ic_type)
	{
		/* open test */
		ret = focal_open_test(params, &test_results[cap_test_num],cap_test_num++);
	}
	/*  short test */
	ret = focal_short_circuit_test(params, &test_results[cap_test_num],cap_test_num++);
	
	if(FOCAL_FT8607 == g_focal_dev_data->ic_type)
	{	
		/* lcd_noise test */
		ret = focal_lcd_noise_test(params, &test_results[cap_test_num],cap_test_num++);
	}
//	TS_LOG_ERR("%s:cap_test_num = %d \n", __func__,cap_test_num);
	focal_put_test_result(params, info, test_results, cap_test_num);

	for (i = 0; i < cap_test_num; i++) {
		focal_free_test_container(test_results[i]);
		test_results[i] = NULL;
	}

	return btest_result;
}

static int focal_start_scan(void)
{
	int i = 0;
	int ret = 0;
	int query_delay = 0;
	int max_query_times = 0;

	u8 reg_val = 0x00;

	ret = focal_read_reg(DEVICE_MODE_ADDR, &reg_val);
	if (ret) {
		TS_LOG_ERR("%s: read device mode fail, ret=%d\n",
			__func__, ret);
		return ret;
	}

	reg_val |= 0x80;
	ret = focal_write_reg(DEVICE_MODE_ADDR, reg_val);
	if (ret) {
		TS_LOG_ERR("%s:set device mode fail, ret=%d\n", __func__, ret);
		return ret;
	}

	query_delay = FTS_SCAN_QUERY_DELAY;
	max_query_times = FTS_SCAN_MAX_TIME / query_delay;

	msleep(query_delay);
	for (i = 0; i < max_query_times; i++) {
		ret = focal_read_reg(DEVICE_MODE_ADDR, &reg_val);
		if (ret) {
			TS_LOG_ERR("%s: read device model fail, ret=%d\n",
				__func__, ret);
			msleep(query_delay);
			continue;
		}

		if ((reg_val >> 7) != 0) {
			TS_LOG_INFO("%s:device is scan, retry=%d\n",
				__func__, i);
			msleep(query_delay);
		} else {
			TS_LOG_INFO("%s:device scan finished, retry=%d\n",
				__func__, i);
			return 0;
		}
	}

	TS_LOG_ERR("%s:device scan timeout\n", __func__);
	return -ETIMEDOUT;
}

static int focal_read_raw_data(u8 data_type, u8 *raw_data, size_t size)
{
	int i = 0;
	int ret = 0;
	int pkg_size = 0;
	int pkg_count = 0;
	int readed_count = 0;

	u8 cmd = 0;

	pkg_count = size / BYTES_PER_TIME;
	if (size % BYTES_PER_TIME != 0)
		pkg_count += 1;

	ret = focal_write_reg(FTS_REG_DATA_TYPE, data_type);
	if (ret) {
		TS_LOG_ERR("%s:write data type to ret, ret=%d\n",
			__func__, ret);
		return ret;
	}
	msleep(10);

	cmd = REG_RAW_BUF0;
	for (i = 0; i < pkg_count; i++) {
		/*
		 * compute pkg_size value
		 * if the last package is not equal to BYTES_PER_TIME,
		 * the package size will be set to (size % BYTES_PER_TIME)
		 */
		if ((size % BYTES_PER_TIME != 0) && (i + 1 == pkg_count))
			pkg_size = size % BYTES_PER_TIME;
		else
			pkg_size = BYTES_PER_TIME;

		/* first package shuold write cmd to ic */
		if (i == 0)
			ret = focal_read(&cmd, 1,	raw_data, pkg_size);
		else
			ret = focal_read_default(raw_data + readed_count,
				pkg_size);

		if (ret) {
			TS_LOG_ERR("%s:read raw data fail, ret=%d\n",
				__func__, ret);
			return ret;
		}

		readed_count += pkg_size;
	}

	return 0;
}

static int focal_get_cb_data(
	int offset,
	u8 *data,
	size_t data_size)
{
	int i = 0;
	int ret = 0;
	int pkg_size = 0;
	int pkg_count = 0;
	int readed_count = 0;
	u8 cmd[3] = {0};

	pkg_count = data_size / BYTES_PER_TIME;
	if (0 != (data_size % BYTES_PER_TIME))
		pkg_count += 1;

	cmd[0] = REG_CB_BUF0;
	for (i = 0; i < pkg_count; i++) {

		if ((i + 1 == pkg_count) && (data_size % BYTES_PER_TIME != 0))
			pkg_size = data_size % BYTES_PER_TIME;
		else
			pkg_size = BYTES_PER_TIME;

		/* addr high 8 bits */
		cmd[1] = (offset + readed_count) >> 8;
		ret = focal_write_reg(REG_CB_ADDR_H, cmd[1]);
		if (ret) {
			TS_LOG_ERR("%s:write cb addr h fail, ret=%d\n",
				__func__, ret);
			return ret;
		}

		/* addr low 8 bits */
		cmd[2] = (offset + readed_count) & 0xff;
		ret = focal_write_reg(REG_CB_ADDR_L, cmd[2]);
		if (ret) {
			TS_LOG_ERR("%s:write cb addr l fail, ret=%d\n",
				__func__, ret);
			return ret;
		}

		ret = focal_read(cmd, 1, data + readed_count, pkg_size);
		if (ret) {
			TS_LOG_ERR("%s:read cb data fail, ret=%d\n",
				__func__, ret);
			return ret;
		}

		readed_count += pkg_size;
	}

	return 0;
}

/* get panelrows */
static int focal_read_channel_x(u8 *channel_x)
{
	return focal_read_reg(REG_TX_NUM, channel_x);
}

/* get panelcols */
static int focal_read_channel_y(u8 *channel_y)
{
	return focal_read_reg(REG_RX_NUM, channel_y);
}

/* auto clb */
static int focal_chip_clb(void)
{
	int ret = 0;
	u8 reg_data = 0;
	u8 retry_count = 50;

	/*  start auto clb */
	ret = focal_write_reg(REG_CLB, 4);
	if (ret) {
		TS_LOG_ERR("%s:write clb reg fail, ret=%d\n", __func__, ret);
		return ret;
	}
	msleep(100);

	while (retry_count--) {
		ret = focal_write_reg(DEVICE_MODE_ADDR, 0x04 << 4);
		if (ret) {
			TS_LOG_ERR("%s:write dev model reg fail, ret=%d\n",
				__func__, ret);
			return ret;
		}

		ret = focal_read_reg(0x04, &reg_data);
		if (ret) {
			TS_LOG_ERR("%s:read 0x04 reg fail, ret=%d\n",
				__func__, ret);
			return ret;
		}

		if (reg_data == 0x02)
			return 0;
		else
			msleep(100);
	}

	return -ETIMEDOUT;
}

/************************************************************************
* name: focal_get_channel_num
* brief:  get num of ch_x, ch_y and key
* input: none
* output: none
* return: comm code. code = 0x00 is ok, else fail.
***********************************************************************/
int focal_get_channel_num(u8 *channel_x, u8 *channel_y)
{
	int ret = 0;
	u8 chl_x = 0;
	u8 chl_y = 0;

	/* get channel x num */
	ret = focal_read_channel_x(&chl_x);
	if (ret) {
		TS_LOG_ERR("%s:get chennel x from ic fail, ret=%d\n",
			__func__, ret);
		return ret;
	}

	/* get channel y num */
	ret = focal_read_channel_y(&chl_y);
	if (ret) {
		TS_LOG_ERR("%s:get chennel y from ic fail, ret=%d\n",
			__func__, ret);
		return ret;
	}

	if (chl_x <= 0 || chl_x > TX_NUM_MAX) {
		TS_LOG_ERR("%s:channel x value out of range, value = %d\n",
			__func__, chl_x);
		return -EINVAL;
	}

	if (chl_y <= 0 || chl_y > RX_NUM_MAX) {
		TS_LOG_ERR("%s:channel y value out of range, value = %d\n",
			__func__, chl_y);
		return -EINVAL;
	}

	*channel_x = chl_x;
	*channel_y = chl_y;

	return 0;
}

static int focal_get_channel_form_ic(struct focal_test_params *params)
{
	int ret = 0;
	u8 chl_x = 0;
	u8 chl_y = 0;

	ret = focal_enter_factory();
	if (ret) {
		TS_LOG_ERR("%s:enter factory model fail, ret=%d\n",
			__func__, ret);
		return ret;
	}

	ret = focal_get_channel_num(&chl_x, &chl_y);
	if (ret) {
		TS_LOG_ERR("%s:get channel num fail, ret=%d\n", __func__, ret);
	} else {
		params->channel_x_num = chl_x;
		params->channel_y_num = chl_y;
		params->key_num = 0;//visual key num
		TS_LOG_INFO("%s:channel_x=%d, channel_y=%d\n,params->key_num",
			__func__, chl_x, chl_y,params->key_num);
	}

	/*
	 * Deleted fts_enter_work here, then need enter factory mode again
	 */

	return 0;
}

static int focal_alloc_test_container(
	struct focal_test_result **result,
	size_t data_size)
{

	*result = kzalloc(sizeof(struct focal_test_result), GFP_KERNEL);
	if (!*result)
		return -ENOMEM;

	(*result)->size = data_size;
	(*result)->values = kzalloc(data_size * sizeof(int), GFP_KERNEL);
	if (!((*result)->values)) {
		kfree(*result);
		*result = NULL;
		return -ENOMEM;
	}

	return 0;
}

static void focal_free_test_container(struct focal_test_result *result)
{

	if (result == NULL)
		return;

	kfree(result->values);
	kfree(result);
}

static int focal_get_raw_data_format(int *data, size_t size)
{
	int i = 0;
	int ret = 0;
	int raw_data_size = 0;

	short raw_data_value = 0;
	u8 *original_raw_data = NULL;

	raw_data_size = size * 2;
	original_raw_data = kzalloc(raw_data_size, GFP_KERNEL);
	if (!original_raw_data) {
		TS_LOG_ERR("%s:alloc mem fail\n", __func__);
		return -ENOMEM;
	}

	ret = focal_read_raw_data(DATA_TYPE_RAW_DATA, original_raw_data,
		raw_data_size);
	if (ret) {
		TS_LOG_ERR("%s:read raw data fail, ret=%d\n", __func__, ret);
		goto exit;
	}

	for (i = 0; i < size; i++) {
		raw_data_value = (original_raw_data[i * 2] << 8);
		raw_data_value |= original_raw_data[i * 2 + 1];

		data[i] = raw_data_value;
	}

exit:
	kfree(original_raw_data);
	original_raw_data = NULL;
	return ret;
}



static int focal_raw_data_test(
	struct focal_test_params *params,
	struct focal_test_result **result,char test_num)
{
	int i = 0;
	int ret = 0;
	int chl_x = 0;
	int chl_y = 0;
	int raw_data_min = 0;
	int raw_data_max = 0;
	int raw_data_size = 0;

	char result_code[FTS_RESULT_CODE_LEN] = {0};
	struct focal_test_result *test_result = NULL;

	TS_LOG_INFO("%s: test item raw data,%d\n", __func__,test_num);

	chl_x = params->channel_x_num;
	chl_y = params->channel_y_num;
	raw_data_min = params->threshold.raw_data_min;
	raw_data_max = params->threshold.raw_data_max;
	raw_data_size = chl_x * chl_y;
	
	result_code[0] = test_num+'0';
	result_code[1] = 'F'; //default result_code is failed
	result_code[2] = '\0';
	ret = focal_alloc_test_container(&test_result, raw_data_size);
	if (ret) {
		TS_LOG_ERR("%s:alloc raw data container fail, ret=%d\n",
			__func__, ret);
		*result = NULL;
		return ret;
	}

	test_result->result = true;
	strncpy(test_result->test_name, "raw_data_test", FTS_TEST_NAME_LEN - 1);

	ret = focal_enter_factory();
	if (ret) {
		TS_LOG_ERR("%s:enter factory mode fail, ret=%d\n",
			__func__, ret);
		test_result->result = false;
		goto test_finish;
	}

	/* start scanning */
	ret = focal_start_scan();
	if (ret) {
		TS_LOG_INFO("%s:scan fail, ret=%d\n", __func__, ret);
		test_result->result = false;
		goto test_finish;
	}

	for (i = 0; i < 3; i++) {
		ret = focal_get_raw_data_format(test_result->values,
			test_result->size);
		if (ret) {
			TS_LOG_ERR("%s:get raw data fail, ret=%d\n",
				__func__, ret);

			test_result->result = false;
			goto test_finish;
		}
	}

	/* compare raw data with shreshold */
	for (i = 0; i < raw_data_size; i++) {
		if ((test_result->values[i] < raw_data_min)
			|| (test_result->values[i] > raw_data_max)) {

			test_result->result = false;
			strncpy(tp_test_failed_reason, "-panel_reason",TP_TEST_FAILED_REASON_LEN);
			focal_print_test_data("raw data test fail",
				i / chl_y,
				i % chl_y,
				raw_data_max,
				raw_data_min,
				test_result->values[i]);
		}
	}

test_finish:
	if (test_result->result) {
		result_code[1] = 'P'; //test pass
		TS_LOG_INFO("%s:raw data test pass\n", __func__);
	} else {
		TS_LOG_ERR("%s:raw data test fail\n", __func__);
	}
	tp_cap_test_status =(tp_cap_test_status && test_result->result);
	strncpy(test_result->result_code, result_code, FTS_RESULT_CODE_LEN - 1);
	*result = test_result;

	return ret;
}

static void focal_print_test_data(
	char *msg,
	int row,
	int col,
	int max,
	int min,
	int value)
{

	TS_LOG_ERR("%s:%s,data[%d, %d]=%d, range=[%d, %d]\n",
		__func__, msg, row, col, value, min, max);
}

static int focal_get_cb_data_format(int *data, size_t size)
{
	int i = 0;
	int ret = 0;
	size_t read_size = 0;

	char *cb_data = NULL;

	read_size = size;
	cb_data = kzalloc(read_size, GFP_KERNEL);
	if (!cb_data) {
		TS_LOG_ERR("%s:alloc mem fail\n", __func__);
		return -ENOMEM;
	}

	ret = focal_get_cb_data(0, cb_data, read_size);
	if (ret) {
		TS_LOG_INFO("%s: get cb data failed\n", __func__);
		goto free_cb_data;
	}

	memset(data, 0, size);
	for (i = 0; i < size; i++)
		data[i] = cb_data[i];

	ret = 0;

free_cb_data:

	kfree(cb_data);
	cb_data = NULL;

	return ret;
}

static int focal_cb_test(
	struct focal_test_params *params,
	struct focal_test_result **result,char test_num)
{
	int i = 0;
	int ret = 0;
	int chl_x = 0;
	int chl_y = 0;
	int cb_max = 0;
	int cb_min = 0;
	size_t cb_data_size = 0;

	int *cb_data = NULL;
	char result_code[FTS_RESULT_CODE_LEN] = {0};
	struct focal_test_result *test_result = NULL;

	TS_LOG_INFO("%s: cb test start\n", __func__);

	cb_min = params->threshold.cb_test_min;
	cb_max = params->threshold.cb_test_max;
	chl_x = params->channel_x_num;
	chl_y = params->channel_y_num;
	cb_data_size = chl_x * chl_y + params->key_num;
	
	result_code[0] = test_num +'0';
	result_code[1] = 'F'; //default result_code is failed
	result_code[2] = '\0';
	ret = focal_alloc_test_container(&test_result, cb_data_size);
	if (ret) {
		TS_LOG_INFO("%s:alloc mem for cb test result fail\n", __func__);
		*result = NULL;
		return ret;
	}

	test_result->result = true;
	strncpy(test_result->test_name, "cb_test", FTS_TEST_NAME_LEN - 1);

	ret = focal_enter_factory();
	if (ret) {
		TS_LOG_ERR("%s:enter factory mode fail, ret=%d\n",
			__func__, ret);
		test_result->result = false;
		goto test_finish;

	}

	ret = focal_get_cb_data_format(test_result->values, cb_data_size);
	if (ret) {
		TS_LOG_INFO("%s:get cb data fail, ret=%d\n", __func__, ret);
		test_result->result = false;
		goto test_finish;
	}

	cb_data = test_result->values;
	for (i = 0; i < cb_data_size; i++) {
		if (cb_data[i] < cb_min || cb_data[i] > cb_max) {

			test_result->result = false;
			strncpy(tp_test_failed_reason, "-panel_reason",TP_TEST_FAILED_REASON_LEN);
			focal_print_test_data("cb test failed",
				i / chl_y,
				i % chl_y,
				cb_max,
				cb_min,
				cb_data[i]);
		}
	}

test_finish:
	if (test_result->result) {
		result_code[1] = 'P'; //test pass
		TS_LOG_INFO("%s:cb test pass\n", __func__);
	} else {
		TS_LOG_ERR("%s:cb test fail!\n", __func__);
	}

	strncpy(test_result->result_code, result_code, FTS_RESULT_CODE_LEN);
	*result = test_result;
	tp_cap_test_status =(tp_cap_test_status && test_result->result);
	return ret;
}

static int focal_get_open_test_data(int *data, size_t size)
{
	int i = 0;
	int ret = 0;
	size_t read_size = 0;

	u8 reg_value = 0;
	char *cb_data = NULL;

	ret = focal_read_reg(REG_GIP, &reg_value);
	if (ret) {
		TS_LOG_ERR("%s:read gip reg fail, ret=%d\n", __func__, ret);
		return ret;
	}

	ret = focal_write_reg(REG_GIP, 0x02);
	if (ret) {
		TS_LOG_ERR("%s:write gip switch fail, ret=%d\n", __func__, ret);
		return ret;
	}
	msleep(50);

	/* auto clb */
	ret = focal_chip_clb();
	if (ret) {
		TS_LOG_ERR("%s:clb fail, ret=%d\n", __func__, ret);
		return ret;
	}

	read_size = size;
	cb_data = kzalloc(read_size, GFP_KERNEL);
	if (!cb_data) {
		TS_LOG_ERR("%s:alloc mem fail\n", __func__);
		return -ENOMEM;
	}

	ret = focal_get_cb_data(0, cb_data, read_size);
	if (ret) {
		TS_LOG_INFO("%s:get cb data fail, ret=%d\n", __func__, ret);
		goto free_cb_data;
	}

	/* reset reg */
	ret = focal_write_reg(REG_GIP, reg_value);
	if (ret) {
		TS_LOG_ERR("%s:reset gip reg fail, ret=%d\n", __func__, ret);
		goto free_cb_data;
	}

	msleep(50);

	for (i = 0; i < size; i++)
		data[i] = cb_data[i];

	ret = 0;

free_cb_data:
	kfree(cb_data);
	cb_data = NULL;

	return ret;
}

static int focal_open_test(
	struct focal_test_params *params,
	struct focal_test_result **result,char test_num)
{
	int i = 0;
	int ret = 0;
	int chl_x = 0;
	int chl_y = 0;
	size_t read_size = 0;
	int panel_data_max = 0;
	int panel_data_min = 0;

	int *panel_data = NULL;
	char result_code[FTS_RESULT_CODE_LEN] = {0};
	struct focal_test_result *test_result = NULL;

	TS_LOG_INFO("%s:open test\n", __func__);

	chl_x = params->channel_x_num;
	chl_y = params->channel_y_num;
	read_size = chl_x * chl_y + params->key_num;
	result_code[0] = test_num + '0';
	result_code[1] = 'F'; //default result_code is failed
	result_code[2] = '\0';
	ret = focal_alloc_test_container(&test_result, read_size);
	if (ret) {
		TS_LOG_ERR("%s:alloc mem fail\n", __func__);
		*result = NULL;
		return ret;
	}

	test_result->result = true;
	strncpy(test_result->test_name, "open_test", FTS_TEST_NAME_LEN - 1);

	ret = focal_enter_factory();
	if (ret) {
		TS_LOG_ERR("%s:enter factory model fail, ret=%d\n",
			__func__, ret);
		test_result->result = false;
		goto test_finish;
	}

	ret = focal_get_open_test_data(test_result->values, read_size);
	if (ret) {
		TS_LOG_ERR("%s:get open test data fail\n", __func__);
		test_result->result = false;
		goto test_finish;
	}

	panel_data = test_result->values;
	panel_data_min = params->threshold.open_test_cb_min;
	panel_data_max = MAX_CB_VALUE;
	for (i = 0; i < test_result->size; i++) {
		if ((panel_data[i] > panel_data_max)
			|| (panel_data[i] < panel_data_min)) {

			test_result->result = false;
			strncpy(tp_test_failed_reason, "-panel_reason",TP_TEST_FAILED_REASON_LEN);
			focal_print_test_data("cb test failed",
					i / chl_y,
					i % chl_y,
					panel_data_max,
					panel_data_min,
					panel_data[i]);
		}
	}

test_finish:
	if (test_result->result) {
		result_code[1] = 'P'; //test pass
		TS_LOG_INFO("%s:open test pass!\n", __func__);
	} else {
		TS_LOG_ERR("%s: open test fail!\n", __func__);
	}

	strncpy(test_result->result_code, result_code, FTS_RESULT_CODE_LEN);
	*result = test_result;
	tp_cap_test_status =(tp_cap_test_status && test_result->result);
	return ret;
}

static int focal_get_short_circuit_data(int *data, size_t size)
{
	int i = 0;
	int ret = 0;
	int adc_data_tmp = 0;

	ret = focal_get_adc_data(data, size);
	if (ret) {
		TS_LOG_ERR("%s:get adc data fail, ret=%d\n", __func__, ret);
		return ret;
	}

	/* data check */
	for (i = 0; i < size; i++) {
		if(FOCAL_FT8607 == g_focal_dev_data->ic_type){
			if (MAX_ADC_NUM_FT8607< data[i]) {
				TS_LOG_DEBUG("%s:%s,adc_data[%d]=%d\n", __func__,
					"adc data out of range", i, data[i]);
				data[i] = MAX_ADC_NUM_FT8607;
			}
		}
		else{
			if (MAX_ADC_NUM <= data[i]) {
				TS_LOG_INFO("%s:%s,adc_data[%d]=%d\n", __func__,
					"adc data out of range", i, data[i]);
				data[i] = MAX_ADC_NUM - 1;
			}
		}
			
	}

	/* data exchange */
	for (i = 0; i < size; i++) {
		adc_data_tmp = data[i] * 100 / (MAX_ADC_NUM - data[i]);
		data[i] = adc_data_tmp;
	}

	return 0;
}

static int focal_set_lcd_noise_data_type(void)
{
	int i = 0;
	int ret = 0;
	int iLCDNoiseTestFrame = 50;//ft8607 lcd noise frame defauit num = 100

	/*write diff mode*/
	ret = focal_write_reg(REG_DATA_TYPE, 1);
	if (ret) {
		TS_LOG_ERR("%s:write reg dats read  fail, ret=%d\n", __func__, ret);
		return ret;
	}
	ret = focal_write_reg(0x01, 0xAD);//clean counter
	if (ret) {
		TS_LOG_ERR("%s:write reg dats read  fail, ret=%d\n", __func__, ret);
		return ret;
	}
	ret = focal_write_reg(REG_8607_LCD_NOISE_FRAME, iLCDNoiseTestFrame);
	if (ret) {
		TS_LOG_ERR("%s:write reg dats read  fail, ret=%d\n", __func__, ret);
		return ret;
	}
	return 0;
}

static int focal_lcd_noise_test(
	struct focal_test_params *params,
	struct focal_test_result **result,char test_num)
{
	int i = 0;
	int ret = 0;
	int chl_x = 0;
	int chl_y = 0;
	int lcd_data_size = 0;
	int lcd_noise_max =0;
	int lcd_noise_min =0;
	unsigned char lcd_value = 0;
	unsigned char	oldMode = 0;
	unsigned char status = 0xff;

	char result_code[FTS_RESULT_CODE_LEN] = {0};
	struct focal_test_result *test_result = NULL;

	TS_LOG_INFO("%s:start\n", __func__);
	
	chl_x = params->channel_x_num;
	chl_y = params->channel_y_num;
	lcd_data_size = chl_x * chl_y + params->key_num;
	result_code[0] = test_num +'0';
	result_code[1] = 'F'; //default result_code is failed
	result_code[2] = '\0';
	
	ret = focal_alloc_test_container(&test_result, lcd_data_size);
	if (ret) {
		TS_LOG_ERR("%s:alloc mem fail\n", __func__);
		*result = NULL;
		return ret;
	}
TS_LOG_INFO("%s:focal_alloc_test_container\n",__func__);
	test_result->result = true;
	strncpy(test_result->test_name,
		"lcd_noise_test", FTS_TEST_NAME_LEN - 1);

	ret = focal_enter_factory();
	if (ret) {
		TS_LOG_ERR("%s:enter factory mode fail, ret=%d\n",
			__func__, ret);
		test_result->result = false;
		goto test_finish;
	}
	TS_LOG_INFO("%s:focal_enter_factory\n",__func__);
	/*read old data type*/
	ret = focal_read_reg(REG_DATA_TYPE, &oldMode);
	if (ret) {
		TS_LOG_ERR("%s:read reg dats read  fail, ret=%d\n", __func__, ret);
		return ret;
	}
	ret = focal_set_lcd_noise_data_type();
	if (ret) {
		TS_LOG_ERR("%s:set data type  fail, ret=%d\n",
			__func__, ret);
		test_result->result = false;
		goto test_finish;
	}
	
	ret = focal_write_reg(REG_8607_LCD_NOISE_START, 0x01);
	if (ret) {
		TS_LOG_ERR("%s:write reg dats read  fail, ret=%d\n", __func__, ret);
		return ret;
	}
	TS_LOG_DEBUG("%s:start lcd noise test\n",__func__);
	msleep(FTS_LCD_NOISE_TEST_FRAME_COUNT * FTS_LCD_PRE_FRAME_TIME);
	for ( i = 0; i < 10; i++ )
  	  {
		 ret = focal_read_reg(REG_8607_LCD_NOISE_START, &status);
		if (ret) {
			TS_LOG_ERR("%s:read reg dats read  fail, ret=%d\n", __func__, ret);
			return ret;
		}
	        if ( ERROR_CODE_OK == ret && status == 0x00  )
	        {
	            TS_LOG_INFO(" read register 0x%x, get value is:%d. \n ", REG_8607_LCD_NOISE_START, status);
	            break;
	        }
		msleep(50);
	}
	if ( i == 10 )
  	{
           test_result->result = false;
	    TS_LOG_ERR("Scan Noise Time Out!\n");
	    goto test_finish;
    	}
	TS_LOG_INFO("%s:start read raw data\n",__func__);
	for (i = 0; i < 3; i++) {
		ret = focal_get_raw_data_format(test_result->values,
			test_result->size);
		if (ret) {
			TS_LOG_ERR("%s:get raw data fail, ret=%d\n",
				__func__, ret);
			test_result->result = false;
			goto test_finish;
		}
	}
	TS_LOG_INFO("%s: read raw data  success\n",__func__);
	ret = focal_enter_work();
	if (ret) {
		TS_LOG_ERR("%s:enter work mode fail, ret=%d\n",
			__func__, ret);
		test_result->result = false;
		goto test_finish;
	}
	msleep(100);
	ret = focal_read_reg(REG_8607_LCD_NOISE_VALUE, &lcd_value);
	if (ret) {
		TS_LOG_ERR("%s :reed reg dats read  fail, ret=%d\n", __func__, ret);
		return ret;
	}
	TS_LOG_INFO("get lcd  reg value: %d\n",lcd_value);
	ret = focal_enter_factory();
	if (ret) {
		TS_LOG_ERR("%s:enter factory mode fail, ret=%d\n",
			__func__, ret);
		test_result->result = false;
		goto test_finish;
	}
//	msleep(100);
	
	ret = focal_write_reg(REG_DATA_TYPE, oldMode);
	if (ret) {
		TS_LOG_ERR("%s:write reg dats read  fail, ret=%d\n", __func__, ret);
		return ret;
	}

	for (i = 0; i < lcd_data_size; i++) {
		test_result->values[i] = focal_abs(test_result->values[i]);
	}
	
	lcd_noise_max = (params->threshold.lcd_noise_max) * lcd_value *32/100;
	/* data compare */
	for (i = 0; i < lcd_data_size; i++) {
		if ((test_result->values[i] >lcd_noise_max )||(test_result->values[i]<lcd_noise_min))
		{
			strncpy(tp_test_failed_reason, "-panel_reason",TP_TEST_FAILED_REASON_LEN);
			test_result->result = false;
			TS_LOG_ERR("%s:LCD Noise test failured,data[%d] = %d",
				__func__, i, test_result->values[i]);
		}
	}

test_finish:
	if (test_result->result) {
		result_code[1] = 'P'; //test pass
		TS_LOG_INFO("%s:lcd noise test pass\n", __func__);
	} else {
		TS_LOG_ERR("%s:lcd noise test fail\n", __func__);
	}
	strncpy(test_result->result_code, result_code, FTS_RESULT_CODE_LEN);
	*result = test_result;
	tp_cap_test_status =(tp_cap_test_status && test_result->result);
	ret = focal_write_reg(REG_DATA_TYPE, oldMode);
	if (ret) {
		TS_LOG_ERR("%s:write reg dats read  fail, ret=%d\n", __func__, ret);
		return ret;
	}
	return ret;
}

static int focal_short_circuit_test(
	struct focal_test_params *params,
	struct focal_test_result **result,char test_num)
{
	int i = 0;
	int ret = 0;
	int chl_x = 0;
	int chl_y = 0;
	int adc_data_size = 0;
	int short_data_min = 0;

	char result_code[FTS_RESULT_CODE_LEN] = {0};
	struct focal_test_result *test_result = NULL;

	TS_LOG_INFO("%s:short circuit test start\n", __func__);
	chl_x = params->channel_x_num;
	chl_y = params->channel_y_num;
	adc_data_size = chl_x * chl_y + params->key_num;
	result_code[0] = test_num + '0';
	result_code[1] = 'F'; //default result_code is failed
	result_code[2] = '\0';
	ret = focal_alloc_test_container(&test_result, adc_data_size);
	if (ret) {
		TS_LOG_ERR("%s:alloc mem fail\n", __func__);
		*result = NULL;
		return ret;
	}

	test_result->result = true;
	strncpy(test_result->test_name,
		"short_circuit_test", FTS_TEST_NAME_LEN - 1);

	ret = focal_enter_factory();
	if (ret) {
		TS_LOG_ERR("%s:enter factory mode fail, ret=%d\n",
			__func__, ret);
		test_result->result = false;
		goto test_finish;
	}

	ret = focal_get_short_circuit_data(test_result->values,
		adc_data_size);
	if (ret) {
		TS_LOG_ERR("%s:get short circuit data fail, ret=%d\n",
			__func__, ret);
		test_result->result = false;
		goto test_finish;
	}

	/* data compare */
	short_data_min = params->threshold.short_circuit_min;

	for (i = 0; i < adc_data_size; i++) {
		if (short_data_min > test_result->values[i]) {

			test_result->result = false;
			strncpy(tp_test_failed_reason, "-panel_reason",TP_TEST_FAILED_REASON_LEN);
			focal_print_test_data("short circuit test fail:",
				i / chl_y,
				i % chl_y,
				0,
				short_data_min,
				test_result->values[i]);
		}
	}

test_finish:
	if (test_result->result) {
		result_code[1] = 'P'; //test pass
		TS_LOG_INFO("%s:short circuit test pass\n", __func__);
	} else {
		TS_LOG_ERR("%s:short circuit test fail\n", __func__);
	}

	strncpy(test_result->result_code, result_code, FTS_RESULT_CODE_LEN);
	*result = test_result;
	tp_cap_test_status =(tp_cap_test_status && test_result->result);

	return ret;
}


static int focal_adc_scan(void)
{
	int i = 0;
	int ret = 0;
	int scan_query_times = 50;

	u8 reg_val = 0;

	/* start adc sample */
	ret = focal_write_reg(REG_ADC_SCAN, 1);
	if (ret) {
		TS_LOG_ERR("%s:adc scan fail, ret=%d\n", __func__, ret);
		return ret;
	}
	msleep(50);

	for (i = 0; i < scan_query_times; i++) {
		ret = focal_read_reg(REG_ADC_SCAN_STATUS, &reg_val);
		if (!ret) {
			if (reg_val == 0) {
				TS_LOG_INFO("%s:adc scan success\n", __func__);
				return 0;
			} else {
				TS_LOG_INFO("%s:adc scan status:0x%02X\n",
					__func__, reg_val);
				msleep(50);
			}
		} else {
			return ret;
		}
	}

	TS_LOG_ERR("%s:adc scan timeout\n", __func__);
	return -ETIMEDOUT;
}

static int focal_get_adc_data(int *data, size_t size)
{
	int i = 0;
	int ret = 0;
	int pkg_size = 0;
	int pkg_count = 0;
	int readed_count = 0;
	int adc_data_size = 0;

	u8 cmd[2] = {0};
	u8 *adc_data = NULL;

	adc_data_size = size * 2;
	pkg_count = adc_data_size / BYTES_PER_TIME;
	if (adc_data_size % BYTES_PER_TIME != 0)
		pkg_count += 1;

	adc_data = kzalloc(adc_data_size, GFP_KERNEL);
	if (!adc_data) {
		TS_LOG_ERR("%s:alloc mem fail\n", __func__);
		return -ENOMEM;
	}

	ret =  focal_adc_scan();
	if (ret) {
		TS_LOG_ERR("%s:adc scan fail, ret=%d\n", __func__, ret);
		goto free_mem;
	}

	cmd[0] = REG_ADC_DATA_ADDR;
	for (i = 0; i < pkg_count; i++) {

		/* if the last package is not full, set package size */
		if ((i + 1 == pkg_count)
			&& (adc_data_size % BYTES_PER_TIME != 0)) {

			pkg_size = adc_data_size % BYTES_PER_TIME;
		} else {
			pkg_size = BYTES_PER_TIME;
		}

		/* the first package should send a command and read */
		if (i == 0) {
			ret = focal_read(cmd, 1, adc_data, pkg_size);
		} else {
			ret = focal_read_default(adc_data + readed_count,
				pkg_size);
		}

		if (ret) {
			TS_LOG_ERR("%s:read adc data fail, ret=%d\n",
				__func__, ret);
			goto free_mem;
		}

		readed_count += pkg_size;
	}

	TS_LOG_INFO("%s:readed cout=%d, size=%lu\n", __func__,
		readed_count, size);

	for (i = 0; i < size; i++)
		data[i] = (adc_data[i * 2] << 8) | adc_data[i * 2 + 1];

	TS_LOG_INFO("%s:copy data to buff finished\n", __func__);

	ret = 0;

free_mem:
	kfree(adc_data);
	adc_data = NULL;

	return ret;
}

static int focal_get_statistics_data(
	int *data, size_t data_size, char *result, size_t res_size)
{
	int avg = 0;
	int min = 0;
	int max = 0;

	if (!data) {
		TS_LOG_ERR("%s:data is null\n", __func__);
		return -ENODATA;
	}

	if (!result) {
		TS_LOG_ERR("%s:result is null\n", __func__);
		return -ENODATA;
	}

	if (data_size <= 0 || res_size <= 0) {
		TS_LOG_ERR("%s:%s, data_size=%ld, res_size=%ld\n", __func__,
			"input parameter is illega",
			data_size, res_size);
		return -EINVAL;
	}

	avg = focal_get_int_average(data, data_size);
	min = focal_get_int_min(data, data_size);
	max = focal_get_int_max(data, data_size);

	memset(result, 0, res_size);
	return snprintf(result, res_size, "[%4d,%4d,%4d]", avg, max, min);
}

static void focal_put_device_info(struct ts_rawdata_info *info)
{
	struct focal_platform_data *focal_pdata = NULL;

	focal_pdata = focal_get_platform_data();

	/* put ic data */
	focal_strncat(info->result, "-ft", TS_RAWDATA_RESULT_MAX);
	focal_strncatint(info->result, focal_pdata->chip_id, "%X",
		TS_RAWDATA_RESULT_MAX);

	focal_strncat(info->result, "-", TS_RAWDATA_RESULT_MAX);
	focal_strncat(info->result, focal_pdata->vendor_name,
		TS_RAWDATA_RESULT_MAX);

	focal_strncat(info->result, "-", TS_RAWDATA_RESULT_MAX);
	focal_strncatint(info->result, focal_pdata->fw_ver, "%d",
		TS_RAWDATA_RESULT_MAX);
}

static void focal_put_test_result(
	struct focal_test_params *params,
	struct ts_rawdata_info *info,
	struct focal_test_result *test_results[],
	int size)
{
	int i = 0;
	int j = 0;
	int buff_index = 0;
	char statistics_data[FTS_STATISTICS_DATA_LEN] = {0};

	/* put test result */
	memset(info->result, 0, TS_RAWDATA_RESULT_MAX);
	for (i = 0; i < size; i++) {

		if (!test_results[i]) {
			TS_LOG_INFO("%s:test result is null, index=%d\n",
				__func__, i);

			focal_strncat(info->result, "FF", TS_RAWDATA_RESULT_MAX);

			continue;
		}

		focal_strncat(info->result, test_results[i]->result_code,
			TS_RAWDATA_RESULT_MAX);
		if (i != size - 1)
			focal_strncat(info->result, "-", TS_RAWDATA_RESULT_MAX);
	}

	/* put statistics data */
	for (i = 0; i < size; i++) {
		if (!test_results[i]) {
			TS_LOG_INFO("%s:test result is null, index=%d\n",
				__func__, i);
			continue;
		}

		focal_get_statistics_data(test_results[i]->values,
			test_results[i]->size,
			statistics_data,
			FTS_STATISTICS_DATA_LEN);

		focal_strncat(info->result, statistics_data,
			TS_RAWDATA_RESULT_MAX);
	}

	/* put test failed reason */
	if(!tp_cap_test_status)
	{
		focal_strncat(info->result, tp_test_failed_reason,TP_TEST_FAILED_REASON_LEN);
	}
	focal_put_device_info(info);
	/* put test data */
	memset(info->buff, 0, TS_RAWDATA_BUFF_MAX);
	info->buff[buff_index++] = params->channel_x_num;
	info->buff[buff_index++] = params->channel_y_num;
	for (i = 0; i < size; i++) {

		if (!test_results[i]) {
			TS_LOG_INFO("%s:test result is null, index=%d\n",
				__func__, i);
			continue;
		}

		for (j = 0; j < test_results[i]->size; j++) {

			if (buff_index >= TS_RAWDATA_BUFF_MAX) {
				TS_LOG_INFO("%s:buff is full, len=%d\n",
					__func__, buff_index);
				break;
			}

			info->buff[buff_index++] = test_results[i]->values[j];
		}
	}

	info->used_size = buff_index;

}

/*
 *
 * param - data_type : 0:raw data, 1:diff data
 *
 */
int focal_get_debug_data_(int data_type, int *data, size_t size)
{
	int ret = 0;

	ret = focal_write_reg(REG_DATA_TYPE, data_type);
	if (ret) {
		TS_LOG_ERR("%s:write data type fail, ret=%lu\n", __func__, ret);
		goto exit;
	}

	ret = focal_start_scan();
	if (ret) {
		TS_LOG_ERR("%s:scan fail, ret=%d\n", __func__, ret);
		goto reset_data_type;
	}

	TS_LOG_ERR("%s:data size=%lu\n", __func__, size);

	ret = focal_get_raw_data_format(data, size);
	if (ret) {
		TS_LOG_ERR("%s:get debug data fail, ret=%d\n", __func__, ret);
		goto reset_data_type;
	}

reset_data_type:

	focal_write_reg(REG_DATA_TYPE, 0);
exit:

	return ret;
}

static int focal_init_test_prm(
	struct focal_platform_data *pdata,
	struct focal_test_params *params)
{
	int ret = 0;

	TS_LOG_INFO("%s: set param data called\n", __func__);

	ret = focal_get_channel_form_ic(params);
	if (ret) {
		TS_LOG_ERR("%s:get channel num fail, ret=%d\n", __func__, ret);
		return ret;
	}

	ret = focal_parse_cap_test_config(pdata, params);
	if (ret < 0) {
		TS_LOG_ERR("%s: analysis tp test data failed\n", __func__);
		return ret;
	}

	focal_set_max_channel_num(params);

	TS_LOG_INFO("%s: set param data success\n", __func__);

	return 0;
}

int focal_get_raw_data(
	struct ts_rawdata_info *info,
	struct ts_cmd_node *out_cmd)
{
	int ret = 0;
	struct focal_platform_data *pdata = NULL;
	struct focal_test_params *params = NULL;

	TS_LOG_INFO("%s:focal get rawdata called\n", __func__);

	pdata = focal_get_platform_data();

	params = kzalloc(sizeof(struct focal_test_params), GFP_KERNEL);
	if (!params) {
		TS_LOG_ERR("%s:alloc mem for params fail\n", __func__);
		ret = -ENOMEM;
		goto err_alloc_mem;
	}

	ret = focal_init_test_prm(pdata, params);
	if (ret < 0) {
		TS_LOG_ERR("%s:get param from dts fail, ret=%d", __func__, ret);
		goto free_mem;
	}

	ret = focal_enter_factory();
	if (ret) {
		TS_LOG_ERR("%s:enter factory mode fail, ret=%d\n",
			__func__, ret);
		goto free_mem;
	}

	if (true == focal_start_test_tp(params, info))
		TS_LOG_INFO("%s:tp test pass\n", __func__);
	else
		TS_LOG_ERR("%s:tp test fail, ret=%d\n", __func__, ret);

	ret = focal_enter_work();
	if (ret < 0)
		TS_LOG_ERR("%s:enter work model fail, ret=%d\n", __func__, ret);

free_mem:

	kfree(params);
	params = NULL;

err_alloc_mem:

	return ret;
}

int focal_get_debug_data(
	struct ts_diff_data_info *info,
	struct ts_cmd_node *out_cmd)
{
	int i = 0;
	int ret = 0;
	u8 chl_x = 0;
	u8 chl_y = 0;
	int used_size = 0;

	int *debug_data = NULL;
	size_t data_size = 0;

	ret = focal_enter_factory();
	if (ret) {
		TS_LOG_ERR("%s:enter factory model fail, ret=%d\n",
			__func__, ret);
		return ret;
	}

	ret = focal_get_channel_num(&chl_x, &chl_y);
	if (ret) {
		TS_LOG_ERR("%s:get channel number fail, ret=%d\n",
			__func__, ret);
		goto exit;
	}

	data_size = chl_x * chl_y;
	debug_data = kzalloc(data_size * sizeof(int), GFP_KERNEL);
	if (!debug_data) {
		TS_LOG_ERR("%s:alloc mem fail\n", __func__);
		goto exit;
	}

	switch (info->debug_type) {
	case READ_DIFF_DATA:
		TS_LOG_INFO("%s:read diff data\n", __func__);
		ret = focal_get_debug_data_(1, debug_data, data_size);
		break;
	case READ_RAW_DATA:
		TS_LOG_INFO("%s:read raw data\n", __func__);
		ret = focal_get_debug_data_(0, debug_data, data_size);
		break;
	default:
		ret = -EINVAL;
		TS_LOG_ERR("%s:debug_type mis match\n", __func__);
		break;
	}

	if (ret)
		goto free_debug_data;

	info->buff[used_size++] = chl_x;
	info->buff[used_size++] = chl_y;
	for (i = 0; i < data_size && used_size < TS_RAWDATA_BUFF_MAX; i++)
		info->buff[used_size++] = debug_data[i];

	info->used_size = used_size;

free_debug_data:
	kfree(debug_data);
	debug_data = NULL;

exit:
	focal_enter_work();
	return ret;
}

int focal_chip_get_capacitance_test_type(struct ts_test_type_info *info)
{
	int ret = 0;
	struct ts_kit_device_data *dev_data = NULL;

	dev_data = focal_get_device_data();

	if (!info) {
		TS_LOG_ERR("%s:info is Null\n", __func__);
		return -ENOMEM;
	}

	switch (info->op_action) {
	case TS_ACTION_READ:
		memcpy(info->tp_test_type,
			dev_data->tp_test_type, TS_CAP_TEST_TYPE_LEN);
		TS_LOG_INFO("%s:test_type=%s\n", __func__, info->tp_test_type);
		break;
	case TS_ACTION_WRITE:

		break;
	default:
		TS_LOG_ERR("%s:invalid op action:%d\n",
			__func__, info->op_action);
		ret = -EINVAL;
		break;
	}

	return ret;
}


