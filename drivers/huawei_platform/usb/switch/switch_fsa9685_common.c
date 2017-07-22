

#include "switch_fsa9685_common.h"
#include <huawei_platform/log/hw_log.h>

#define HWLOG_TAG sensorhub
HWLOG_REGIST();

struct switch_extra_ops *g_switch_ops;

int switch_extra_ops_register(struct switch_extra_ops *ops)
{
	int ret = 0;

	if (ops != NULL) {
		g_switch_ops = ops;
	} else {
		hwlog_err("charge extra ops register fail!\n");
		ret = -EPERM;
	}
	return ret;
}

int fsa9685_manual_sw(int input_select)
{
    if (NULL == g_switch_ops || NULL == g_switch_ops->manual_switch) {
		return -1;
    }
    return g_switch_ops->manual_switch(input_select);
}

int fsa9685_manual_detach(void)
{
    if (NULL == g_switch_ops || NULL == g_switch_ops->manual_detach) {
		return -1;
    }
    return g_switch_ops->manual_detach();
}

int fsa9685_dcd_timeout_enable(bool enable_flag)
{
    if (NULL == g_switch_ops || NULL == g_switch_ops->dcd_timeout_enable) {
		return -1;
    }
    return g_switch_ops->dcd_timeout_enable(enable_flag);
}