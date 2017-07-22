#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/debugfs.h>
#include <linux/uaccess.h>
#include <linux/of.h>

#include <linux/i2c.h>
#include <linux/delay.h>

#include "focaltech_test.h"
#include "focaltech_core.h"
#include "focaltech_dts.h"
#include "focaltech_flash.h"

int focal_get_vendor_compatible_name(
	const char *project_id,
	char *comp_name,
	size_t size)
{
	int ret = 0;

	ret = snprintf(comp_name, size,	"%s-%s", FTS_CHIP_NAME, project_id);
	if (ret >= size) {
		TS_LOG_INFO("%s:%s, ret=%d, size=%lu\n", __func__,
			"compatible_name out of range", ret, size);
		return -EINVAL;
	}

	return 0;
}

int focal_get_vendor_name_from_dts(
	const char *project_id,
	char *vendor_name,
	size_t size)
{
	int ret = 0;
	const char *producer = NULL;
	char comp_name[FTS_VENDOR_COMP_NAME_LEN] = {0};

	struct device_node *np = NULL;

	ret = focal_get_vendor_compatible_name(project_id,
		comp_name, FTS_VENDOR_COMP_NAME_LEN);
	if (ret) {
		TS_LOG_ERR("%s:get vendor compatible name fail\n", __func__);
		return ret;
	}

	TS_LOG_INFO("%s:compatible_name is: %s\n", __func__, comp_name);
	np = of_find_compatible_node(NULL, NULL, comp_name);
	if (!np) {
		TS_LOG_INFO("%s:find vendor node fail\n", __func__);
		return -ENODEV;
	}

	ret = of_property_read_string(np, "producer", &producer);
	if (!ret) {
		strncpy(vendor_name, producer, size);
	} else {
		TS_LOG_ERR("%s:find producer in dts fail, ret=%d\n",
			__func__, ret);
		return ret;
	}
	ret = of_property_read_u32(np, FTS_IC_TYPES, &g_focal_dev_data->ic_type);
	if (ret) {
		TS_LOG_ERR("%s:get ic_type fail, ret=%d\n", __func__, ret);
		return -ENODATA;
	}
	TS_LOG_INFO("%s: is: producer is :%s ,ic_type is %d \n", __func__, producer,g_focal_dev_data->ic_type);
	return 0;
}

static int focal_parse_power_config_dts(
	struct device_node *np,
	struct ts_kit_device_data *dev_data)
{
	int ret = 0;
	return 0;
}

static int focal_parse_report_config_dts(
	struct device_node *np,
	struct ts_kit_device_data *dev_data)
{
	int ret = 0;

	ret = of_property_read_u32(np, FTS_ALGO_ID, &dev_data->algo_id);
	if (ret) {
		TS_LOG_ERR("%s:get algo id failed\n", __func__);
		return -ENODATA;
	}

	ret = of_property_read_u32(np, FTS_X_MAX, &dev_data->x_max);
	if (ret) {
		TS_LOG_ERR("%s:get device x_max fail, ret=%d\n",
			__func__, ret);
		return -ENODATA;
	}

	ret = of_property_read_u32(np, FTS_Y_MAX, &dev_data->y_max);
	if (ret) {
		TS_LOG_ERR("%s:get device y_max fail, ret=%d\n",
			__func__, ret);
		return -ENODATA;
	}

	ret = of_property_read_u32(np, FTS_X_MAX_MT, &dev_data->x_max_mt);
	if (ret) {
		TS_LOG_ERR("%s:get device x_max fail, ret=%d\n",
			__func__, ret);
		return -ENODATA;
	}

	ret = of_property_read_u32(np, FTS_Y_MAX_MT, &dev_data->y_max_mt);
	if (ret) {
		TS_LOG_ERR("%s:get device y_max fail, ret=%d\n",
			__func__, ret);
		return -ENODATA;
	}

	TS_LOG_INFO("%s:%s=%d, %s=%d, %s=%d, %s=%d, %s=%d\n", __func__,
		"algo_id", dev_data->algo_id,
		"x_max", dev_data->x_max,
		"y_max", dev_data->y_max,
		"x_mt", dev_data->x_max_mt,
		"y_mt", dev_data->y_max_mt);

	return 0;
}

static void focal_of_property_read_u32_default(
	struct device_node *np,
	char *prop_name,
	u32 *out_value,
	u32 default_value)
{
	int ret = 0;

	ret = of_property_read_u32(np, prop_name, out_value);
	if (ret) {
		TS_LOG_INFO("%s:%s not set in dts, use default\n",
			__func__, prop_name);
		*out_value = default_value;
	}
}

static void focal_of_property_read_u16_default(
	struct device_node *np,
	char *prop_name,
	u16 *out_value,
	u16 default_value)
{
	int ret = 0;

	ret = of_property_read_u16(np, prop_name, out_value);
	if (ret) {
		TS_LOG_INFO("%s:%s not set in dts, use default\n",
			__func__, prop_name);
		*out_value = default_value;
	}
}


static void focal_prase_delay_config_dts(
	struct device_node *np,
	struct focal_platform_data *pdata)
{
	struct focal_delay_time *delay_time = NULL;

	delay_time = pdata->delay_time;

	focal_of_property_read_u32_default(np, FTS_HARD_RESET_DELAY,
		&delay_time->hard_reset_delay, 200);

	focal_of_property_read_u32_default(np, FTS_ERASE_MIN_DELAY,
		&delay_time->erase_min_delay, 1350);

	focal_of_property_read_u32_default(np, FTS_CALC_CRC_DELAY,
		&delay_time->calc_crc_delay, 300);

	focal_of_property_read_u32_default(np, FTS_REBOOT_DELAY,
		&delay_time->reboot_delay, 200);

	focal_of_property_read_u32_default(np, FTS_ERASE_QUERY_DELAY,
		&delay_time->erase_query_delay, 50);

	focal_of_property_read_u32_default(np, FTS_WRITE_FLASH_QUERY_TIMES,
		&delay_time->write_flash_query_times, 30);

	focal_of_property_read_u32_default(np, FTS_READ_ECC_QUERY_TIMES,
		&delay_time->read_ecc_query_times, 100);

	focal_of_property_read_u32_default(np, FTS_ERASE_FLASH_QUERY_TIMES,
		&delay_time->erase_flash_query_times, 15);

	focal_of_property_read_u32_default(np, FTS_UPGRADE_LOOP_TIMES,
		&delay_time->upgrade_loop_times, 30);

	TS_LOG_INFO("%s:%s=%d, %s=%d, %s=%d, %s=%d, %s=%d\n", __func__,
		"hard_reset_delay", delay_time->hard_reset_delay,
		"reboot_delay", delay_time->reboot_delay,
		"erase_min_delay", delay_time->erase_min_delay,
		"erase_query_delay", delay_time->erase_query_delay,
		"calc_crc_delay", delay_time->calc_crc_delay);

	TS_LOG_INFO("%s:%s=%d, %s=%d, %s=%d, %s=%d", __func__,
		"erase_flash_query_times", delay_time->erase_flash_query_times,
		"read_ecc_query_times", delay_time->read_ecc_query_times,
		"write_flash_query_times", delay_time->write_flash_query_times,
		"upgrade_loop_times", delay_time->upgrade_loop_times);
}

int focal_prase_ic_config_dts(
	struct device_node *np,
	struct ts_kit_device_data *dev_data)
{


	focal_of_property_read_u32_default(np, FTS_REBOOT_DELAY,
		&dev_data->reset_delay, 200);

	focal_of_property_read_u32_default(np, FTS_SLAVE_ADDR,
		&dev_data->slave_addr, 0x38);

	TS_LOG_INFO("%s:%s=%d, %s=%d.\n", __func__,
		"reset_delay", dev_data->reset_delay,
		"slave_addr", dev_data->slave_addr);

	return 0;
}

int focal_parse_dts(
	struct device_node *np,
	struct focal_platform_data *focal_pdata)
{
	int ret = 0;

	const char *str_value = NULL;
	struct ts_glove_info *glove_info = NULL;
	struct ts_holster_info *holster_info = NULL;
	struct ts_roi_info *roi_info = NULL;
	
	struct ts_kit_device_data *dev_data = NULL;

	dev_data = focal_pdata->focal_device_data;

	ret = focal_parse_power_config_dts(np, dev_data);
	if (ret) {
		TS_LOG_ERR("%s:parse power config fail\n", __func__);
		return ret;
	}

	ret = focal_parse_report_config_dts(np, dev_data);
	if (ret) {
		TS_LOG_ERR("%s:parse report config fail\n", __func__);
		return ret;
	}

	focal_prase_delay_config_dts(np, focal_pdata);


	ret = of_property_read_u32(np, FTS_IRQ_CFG, &dev_data->irq_config);
	if (ret) {
		TS_LOG_ERR("%s:get irq config fail, ret=%d\n", __func__, ret);
		return -ENODATA;
	}

	ret = of_property_read_u32(np, FTS_IC_TYPES, &dev_data->ic_type);
	if (ret) {
		TS_LOG_ERR("%s:get ic_type fail, ret=%d\n", __func__, ret);
		return -ENODATA;
	}
	
	ret = of_property_read_u32(np, FTS_PRAM_PROJECTID_ADDR, &focal_pdata->pram_projectid_addr);
	if (ret) {
		focal_pdata->pram_projectid_addr = FTS_BOOT_PROJ_CODE_ADDR2;
		TS_LOG_INFO("%s:get pram_projectid_addr from dts failed ,use default FT8716 pram addr\n", __func__);
	}
	
	ret = of_property_read_string(np, FTS_TEST_TYPE, &str_value);
	if (ret) {
		TS_LOG_INFO("%s:get tp_test_type fail, ret=%d\n",
			__func__, ret);
		str_value = FTS_TEST_TYPE_DEFAULT;
	}

	strncpy(dev_data->tp_test_type, str_value, TS_CAP_TEST_TYPE_LEN);

	/*
	 * 0 is cover without glass,
	 * 1 is cover with glass that need glove mode
	 * if not define in dtsi,set 0 to disable it
	 */
	focal_of_property_read_u32_default(np, FTS_COVER_FORCE_GLOVE,
		&dev_data->cover_force_glove, 0);

	glove_info = &dev_data->ts_platform_data->feature_info.glove_info;
	focal_of_property_read_u32_default(np, FTS_GLOVE_SWITCH_ADDR,
		&glove_info->glove_switch_addr, 0);

	holster_info = &dev_data->ts_platform_data->feature_info.holster_info;
	focal_of_property_read_u32_default(np, FTS_HOSTLER_SWITCH_ADDR,
		&holster_info->holster_switch_addr, 0);

	roi_info = &dev_data->ts_platform_data->feature_info.roi_info;

	focal_of_property_read_u32_default(np, FTS_ROI_SUPPORTED,
		&roi_info->roi_supported, 0);
	if(roi_info->roi_supported){
		focal_of_property_read_u32_default(np, FTS_ROI_SWITCH_ADDR,
		&roi_info->roi_control_addr, 0);
	}
	TS_LOG_INFO("%s:%s=%d, %s=%d\n", __func__,
		"irq_config", dev_data->irq_config,
		"ic_type",    dev_data->ic_type);

	TS_LOG_INFO("%s:glove_switch_addr=0x%04x,holster_switch_addr=0x%04x,\n",__func__,
		glove_info->glove_switch_addr,
		holster_info->holster_switch_addr);
	
	TS_LOG_INFO("%s: pram_projectid_addr  is  %x \n", __func__,focal_pdata->pram_projectid_addr);
	
	TS_LOG_INFO("%s:,roi_info=%d,roi_control_addr=0x%04x\n",__func__,
		roi_info->roi_supported,
		roi_info->roi_control_addr);

	return NO_ERR;
}

static void focal_prase_test_threshold(
	struct device_node *np,
	struct focal_test_threshold *threshold)
{
	focal_of_property_read_u32_default(np, DTS_RAW_DATA_MIN,
		&threshold->raw_data_min, 0);

	focal_of_property_read_u32_default(np, DTS_RAW_DATA_MAX,
		&threshold->raw_data_max, 0);

	focal_of_property_read_u32_default(np, DTS_CB_TEST_MIN,
		&threshold->cb_test_min, 0);

	focal_of_property_read_u32_default(np, DTS_CB_TEST_MAX,
		&threshold->cb_test_max, 0);

	focal_of_property_read_u32_default(np, DTS_OPEN_TEST_CB_MIN,
		&threshold->open_test_cb_min, 0);

	/* short_circuit_test */
	focal_of_property_read_u32_default(np, DTS_SHORT_CIRCUIT_RES_MIN,
		&threshold->short_circuit_min, 0);
		
	focal_of_property_read_u32_default(np, DTS_LCD_NOISE_MAX,
		&threshold->lcd_noise_max, 0);

	TS_LOG_INFO("%s:%s:%s=%d, %s=%d, %s=%d, %s=%d, %s=%d, %s=%d\n",
		__func__, "cb test thresholds",
		"raw_data_min", threshold->raw_data_min,
		"raw_data_max", threshold->raw_data_max,
		"cb_test_min",  threshold->cb_test_min,
		"cb_test_max",  threshold->cb_test_max,
		"open_test_cb_min", threshold->open_test_cb_min,
		"lcd_noise_max", threshold->lcd_noise_max,
		"short_circuit_min", threshold->short_circuit_min);
}

int focal_parse_cap_test_config(
	struct focal_platform_data *pdata,
	struct focal_test_params *params)
{
	int ret = 0;

	char comp_name[FTS_VENDOR_COMP_NAME_LEN] = {0};
	struct device_node *np = NULL;
	struct focal_platform_data *fts_pdata = focal_get_platform_data();

	if (!fts_pdata) {
		TS_LOG_ERR("%s:chip data null\n", __func__);
		return -EINVAL;
	}

	/*
	 * Deleted fts_read_project_id here, project_id has already readed 
	 * in chip_init process
	 */

	ret = focal_get_vendor_compatible_name(fts_pdata->project_id, comp_name,
		FTS_VENDOR_COMP_NAME_LEN);
	if (ret) {
		TS_LOG_ERR("%s:get compatible name fail, ret=%d\n",
			__func__, ret);
		return ret;
	}

	np = of_find_compatible_node(NULL, NULL, comp_name);
	if (!np) {
		TS_LOG_ERR("%s:find dev node faile, compatible name:%s\n",
			__func__, comp_name);
		return -ENODEV;
	}

	focal_prase_test_threshold(np, &params->threshold);

	return 0;
}

