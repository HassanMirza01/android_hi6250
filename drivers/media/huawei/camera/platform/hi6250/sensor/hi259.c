 

#include <linux/module.h>
#include <linux/printk.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/rpmsg.h>
#include <linux/pinctrl/consumer.h>

#include "hwsensor.h"
#include "sensor_commom.h"
#include "hw_csi.h"

#define I2S(i) container_of(i, sensor_t, intf)

static char *sensor_dts_name = "HI259_VENDOR";
static hwsensor_vtbl_t s_hi259_vtbl;
static bool power_on_status = false;//false: power off, true:power on

int hi259_config(hwsensor_intf_t* si, void  *argp);

struct sensor_power_setting hi259_power_up_setting[] = {
    //MCAM2 IOVDD 1.80V
    {
        .seq_type = SENSOR_IOVDD,
        .data = (void*)"main-sensor-iovdd",
        .config_val = LDO_VOLTAGE_1P8V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },
    //MCAM2 AVDD 2.80V
    {
        .seq_type = SENSOR_AVDD,
        .data = (void*)"main-sensor-avdd",
        .config_val = LDO_VOLTAGE_V2P8V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 0,
    },

    //SCAM AVDD 2.80V
    {
        .seq_type = SENSOR_AVDD2,
        .data = (void*)"slave-sensor-avdd",
        .config_val = LDO_VOLTAGE_V2P8V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },

    {
        .seq_type = SENSOR_MIPI_SW,
        .config_val = SENSOR_GPIO_LOW,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },

    {
        .seq_type = SENSOR_MCLK,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 2,
    },

    {
        .seq_type = SENSOR_PWDN2,
        .config_val = SENSOR_GPIO_LOW,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 5,
    },

    {
        .seq_type = SENSOR_RST3,
        .config_val = SENSOR_GPIO_HIGH,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },
};

struct sensor_power_setting hi259_power_down_setting[] = {
    {
        .seq_type = SENSOR_RST3,
        .config_val = SENSOR_GPIO_LOW,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },
    {
        .seq_type = SENSOR_MCLK,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },

    {
        .seq_type = SENSOR_PWDN2,
        .config_val = SENSOR_GPIO_HIGH,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },
    {
        .seq_type = SENSOR_MIPI_SW,
        .config_val = SENSOR_GPIO_HIGH,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },
    //SCAM AVDD 2.80V
    {
        .seq_type = SENSOR_AVDD2,
        .data = (void*)"slave-sensor-avdd",
        .config_val = LDO_VOLTAGE_V2P8V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },
    //MCAM2 AVDD 2.80V
    {
        .seq_type = SENSOR_AVDD,
        .data = (void*)"main-sensor-avdd",
        .config_val = LDO_VOLTAGE_V2P8V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },

    //MCAM2 IOVDD 1.80V
    {
        .seq_type = SENSOR_IOVDD,
        .data = (void*)"main-sensor-iovdd",
        .config_val = LDO_VOLTAGE_1P8V,
        .sensor_index = SENSOR_INDEX_INVALID,
        .delay = 1,
    },
};

atomic_t volatile hi259_powered = ATOMIC_INIT(0);
static sensor_t s_hi259 =
{
    .intf = { .vtbl = &s_hi259_vtbl, },
    .power_setting_array = {
            .size = ARRAY_SIZE(hi259_power_up_setting),
            .power_setting = hi259_power_up_setting,
     },
    .power_down_setting_array = {
            .size = ARRAY_SIZE(hi259_power_down_setting),
            .power_setting = hi259_power_down_setting,
     },
     .p_atpowercnt = &hi259_powered,
};

static const struct of_device_id s_hi259_dt_match[] =
{
    {
        .compatible = "huawei,hi259",
        .data = &s_hi259.intf,
    },
    {
    },
};

MODULE_DEVICE_TABLE(of, s_hi259_dt_match);

static struct platform_driver s_hi259_driver =
{
    .driver =
    {
        .name = "huawei,hi259",
        .owner = THIS_MODULE,
        .of_match_table = s_hi259_dt_match,
    },
};

char const* hi259_get_name(hwsensor_intf_t* si)
{
    sensor_t* sensor = I2S(si);
    return sensor->board_info->name;
}

int hi259_power_up(hwsensor_intf_t* si)
{
    int ret = 0;
    sensor_t* sensor = NULL;
    sensor = I2S(si);
    cam_info("enter %s. index = %d name = %s", __func__, sensor->board_info->sensor_index, sensor->board_info->name);

    ret = hw_sensor_power_up_config(s_hi259.dev, sensor->board_info);
    if (0 == ret ){
        cam_info("%s. power up config success.", __func__);
    }else{
        cam_err("%s. power up config fail.", __func__);
        return ret;
    }
    if (hw_is_fpga_board()) {
        ret = do_sensor_power_on(sensor->board_info->sensor_index, sensor->board_info->name);
    } else {
        ret = hw_sensor_power_up(sensor);
    }
    if (0 == ret )
    {
        cam_info("%s. power up sensor success.", __func__);
    }
    else
    {
        cam_err("%s. power up sensor fail.", __func__);
    }
    return ret;
}

int
hi259_power_down(
        hwsensor_intf_t* si)
{
    int ret = 0;
    sensor_t* sensor = NULL;
    sensor = I2S(si);
    cam_info("enter %s. index = %d name = %s", __func__, sensor->board_info->sensor_index, sensor->board_info->name);
    if (hw_is_fpga_board()) {
        ret = do_sensor_power_off(sensor->board_info->sensor_index, sensor->board_info->name);
    } else {
        ret = hw_sensor_power_down(sensor);
    }
    if (0 == ret )
    {
        cam_info("%s. power down sensor success.", __func__);
    }
    else
    {
        cam_err("%s. power down sensor fail.", __func__);
    }
    hw_sensor_power_down_config(sensor->board_info);
    return ret;
}

int hi259_csi_enable(hwsensor_intf_t* si)
{
    return 0;
}

int hi259_csi_disable(hwsensor_intf_t* si)
{
    return 0;
}

static int hi259_match_id(
        hwsensor_intf_t* si, void * data)
{
	sensor_t* sensor = I2S(si);
	struct sensor_cfg_data *cdata = (struct sensor_cfg_data *)data;
	uint32_t module_id_0 = 0;
	uint32_t module_id_1 = 0;
	struct pinctrl_state *pinctrl_def;
	struct pinctrl_state *pinctrl_idle;
	struct pinctrl *p;
	char *sensor_name [] = { "HI259_SUNNY",  "HI259_OFILM" };
	int rc = 0;

	memset(cdata->cfg.name, 0, DEVICE_NAME_SIZE);
	if (!strncmp(sensor->board_info->name, sensor_dts_name, strlen(sensor_dts_name))) {
	    p = devm_pinctrl_get(s_hi259.dev);
	    if (IS_ERR_OR_NULL(p)) {
	        cam_err("could not get pinctrl.\n");
	        rc = -1;
	        goto matchID_exit;
	    }

	    rc = gpio_request(sensor->board_info->gpios[FSIN].gpio, NULL);
	    if(rc < 0) {
	        cam_err("%s failed to request gpio[%d]", __func__, sensor->board_info->gpios[FSIN].gpio);
	        rc = -1;
	        goto matchID_exit;
	    }
	    cam_info("%s gpio[%d].", __func__, sensor->board_info->gpios[FSIN].gpio);

	    pinctrl_def = pinctrl_lookup_state(p, "default");
	    if (IS_ERR_OR_NULL(pinctrl_def)) {
	        cam_err("could not get defstate.\n");
	        rc = -1;
	        goto pinctrl_error;
	    }

	    pinctrl_idle = pinctrl_lookup_state(p, "idle");
	    if (IS_ERR_OR_NULL(pinctrl_idle)) {
	        pr_err("could not get idle defstate.\n");
	        rc = -1;
	        goto pinctrl_error;
	    }
	    /*PULL UP*/
	    rc = pinctrl_select_state(p, pinctrl_def);
	    if (rc) {
	        cam_err("could not set pins to default state.\n");
	        rc = -1;
	        goto pinctrl_error;
	    }
	    udelay(10);
	    cam_info("%s gpio[%d].", __func__, sensor->board_info->gpios[FSIN].gpio);
	    rc = gpio_direction_input(sensor->board_info->gpios[FSIN].gpio);
	    if (rc < 0) {
	        cam_err("%s failed to config gpio(%d) input.\n",__func__, sensor->board_info->gpios[FSIN].gpio);
	        rc = -1;
	        goto pinctrl_error;
	    }

	    module_id_1 = gpio_get_value(sensor->board_info->gpios[FSIN].gpio);

	    /*PULL DOWN*/
	    rc = pinctrl_select_state(p, pinctrl_idle);
	    if (rc) {
	    cam_err("could not set pins to idle state.\n");
	    rc = -1;
	    goto pinctrl_error;
	    }
	    udelay(10);
	    cam_info("%s gpio[%d].", __func__, sensor->board_info->gpios[FSIN].gpio);
	    rc = gpio_direction_input(sensor->board_info->gpios[FSIN].gpio);
	    if (rc < 0) {
	    cam_err("%s failed to config gpio(%d) input.\n",__func__, sensor->board_info->gpios[FSIN].gpio);
	    rc = -1;
	    goto pinctrl_error;
	    }
	    module_id_0 = gpio_get_value(sensor->board_info->gpios[FSIN].gpio);

	    cam_info("%s module_id_0 %d module_id_1 %d .\n",__func__, module_id_0, module_id_1);
	    if((module_id_0 == 1) && (module_id_1 == 1)){
	        //sunny module
	        strncpy(cdata->cfg.name, sensor_name[0], strlen(sensor_name[0])+1);
	        cdata->data = sensor->board_info->sensor_index;
	        rc = 0;
	    }
	    else if((module_id_0 == 0) && (module_id_1 == 0)){
	        //ofilm module
	        strncpy(cdata->cfg.name, sensor_name[1], strlen(sensor_name[1])+1);
	        cdata->data = sensor->board_info->sensor_index;
	        rc = 0;
	    }
	    else{
	        strncpy(cdata->cfg.name, sensor->board_info->name, strlen(sensor->board_info->name)+1);
	        cdata->data = sensor->board_info->sensor_index;
	        cam_err("%s failed to get the module id value.\n",__func__);
	        rc = 0;
	    }

	    gpio_free(sensor->board_info->gpios[FSIN].gpio);
	    goto matchID_exit;
	    } else {
	        strncpy(cdata->cfg.name, sensor->board_info->name, strlen(sensor->board_info->name)+1);
	        cdata->data = sensor->board_info->sensor_index;
	        rc = 0;
	        goto matchID_exit;
	    }

pinctrl_error:
	    gpio_free(sensor->board_info->gpios[FSIN].gpio);
matchID_exit:
	    if (cdata->data != SENSOR_INDEX_INVALID) {
	        hwsensor_writefile(sensor->board_info->sensor_index, cdata->cfg.name);
	        cam_info("%s, cdata->cfg.name = %s", __func__,cdata->cfg.name );
	    }

    return rc;
}

static hwsensor_vtbl_t s_hi259_vtbl =
{
    .get_name = hi259_get_name,
    .config = hi259_config,
    .power_up = hi259_power_up,
    .power_down = hi259_power_down,
    .match_id = hi259_match_id,
    .csi_enable = hi259_csi_enable,
    .csi_disable = hi259_csi_disable,
};

int hi259_config(hwsensor_intf_t* si, void  *argp)
{
    struct sensor_cfg_data *data;

    int ret =0;

	if (NULL == si || NULL == argp){
		cam_err("%s : si or argp is null", __func__);
		return -1;
	}

    data = (struct sensor_cfg_data *)argp;
    cam_debug("hi259 cfgtype = %d",data->cfgtype);
    switch(data->cfgtype){
        case SEN_CONFIG_POWER_ON:
            if(false == power_on_status){
                ret = si->vtbl->power_up(si);
                power_on_status = true;
            }
            break;
        case SEN_CONFIG_POWER_OFF:
            if(true == power_on_status){
                ret = si->vtbl->power_down(si);
                power_on_status = false;
            }
            break;
        case SEN_CONFIG_WRITE_REG:
            break;
        case SEN_CONFIG_READ_REG:
            break;
        case SEN_CONFIG_WRITE_REG_SETTINGS:
            break;
        case SEN_CONFIG_READ_REG_SETTINGS:
            break;
        case SEN_CONFIG_ENABLE_CSI:
            //ret = si->vtbl->csi_enable(si);
            break;
        case SEN_CONFIG_DISABLE_CSI:
            //ret = si->vtbl->csi_disable(si);
            break;
        case SEN_CONFIG_MATCH_ID:
            ret = si->vtbl->match_id(si,argp);
            break;
        case SEN_CONFIG_RESET_HOLD:
            cam_warn("%s cfgtype(%d) does not support", __func__, data->cfgtype);
            break;
        case SEN_CONFIG_RESET_RELEASE:
            cam_warn("%s cfgtype(%d) does not support", __func__, data->cfgtype);
            break;
        default:
            cam_err("%s cfgtype(%d) is error", __func__, data->cfgtype);
            break;
    }

    return ret;
}

static int32_t hi259_platform_probe(struct platform_device* pdev)
{
    int rc = 0;
    cam_notice("enter %s",__func__);

    if (pdev->dev.of_node) {
        rc = hw_sensor_get_dt_data(pdev, &s_hi259);
        if (rc < 0) {
            cam_err("%s failed line %d\n", __func__, __LINE__);
            goto hi259_sensor_probe_fail;
		}
    } else {
        cam_err("%s hi259 of_node is NULL.\n", __func__);
        goto hi259_sensor_probe_fail;
    }
    s_hi259.dev = &pdev->dev;
    rc = hwsensor_register(pdev, &s_hi259.intf);
    rc = rpmsg_sensor_register(pdev, (void*)&s_hi259);
hi259_sensor_probe_fail:
    return rc;
}

static int __init hi259_init_module(void)
{
    cam_info("Enter: %s", __func__);
    return platform_driver_probe(&s_hi259_driver,
            hi259_platform_probe);
}

static void __exit hi259_exit_module(void)
{
    hwsensor_unregister(&s_hi259.intf);
    platform_driver_unregister(&s_hi259_driver);
}

module_init(hi259_init_module);
module_exit(hi259_exit_module);
MODULE_DESCRIPTION("hi259");
MODULE_LICENSE("GPL v2");

