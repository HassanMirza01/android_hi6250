/************************************************************
*
* Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
* FileName: switch_fsa9685.c
* Author: lixiuna(00213837)       Version : 0.1      Date:  2013-11-06
*
* This software is licensed under the terms of the GNU General Public
* License version 2, as published by the Free Software Foundation, and
* may be copied, distributed, and modified under those terms.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
*  Description:    .c file for switch chip
*  Version:
*  Function List:
*  History:
*  <author>  <time>   <version >   <desc>
***********************************************************/

#include <linux/i2c.h>
#include <linux/delay.h>
#include <linux/gpio.h>
#include <linux/timer.h>
#include <linux/param.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/workqueue.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/of_irq.h>
#include <asm/irq.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <huawei_platform/usb/switch/switch_usb.h>
#include "switch_chip.h"
#include <linux/hisi/usb/hisi_usb.h>
#ifdef CONFIG_HDMI_K3
#include <../video/k3/hdmi/k3_hdmi.h>
#endif
#ifdef CONFIG_HUAWEI_HW_DEV_DCT
#include <huawei_platform/devdetect/hw_dev_dec.h>
#endif
#include <linux/wakelock.h>
#include <huawei_platform/log/hw_log.h>
#include <chipset_common/hwusb/hw_usb_rwswitch.h>
#include <huawei_platform/usb/switch/switch_fsa9685.h>
#include <huawei_platform/power/huawei_charger.h>
#ifdef CONFIG_DIRECT_CHARGER
#include <huawei_platform/power/direct_charger.h>
#endif


struct mutex accp_detect_lock;
struct mutex accp_adaptor_reg_lock;

extern unsigned int get_boot_into_recovery_flag(void);
static int fsa9685_is_support_scp(void);
#define HWLOG_TAG switch_fsa9685
HWLOG_REGIST();

static int gpio = -1;
static struct i2c_client *this_client = NULL;
static struct work_struct   g_intb_work;
static struct delayed_work   detach_delayed_work;
static struct wake_lock usb_switch_lock;
#ifdef CONFIG_FSA9685_DEBUG_FS
static int reg_locked = 1;
static char chip_regs[0x5c+2] = { 0 };
#endif
static u32 fsa9685_usbid_enable = 1;
static u32 fsa9685_fcp_support = 0;
static u32 fsa9685_scp_support = 0;
static u32 fsa9685_mhl_detect_disable = 0;
static u32 two_switch_flag = 0;/*disable for two switch*/

static void usb_switch_wake_lock(void)
{
    if (!wake_lock_active(&usb_switch_lock)) {
        wake_lock(&usb_switch_lock);
        hwlog_info("usb switch wake lock\n");
    }
}
static void usb_switch_wake_unlock(void)
{
    if (wake_lock_active(&usb_switch_lock)) {
        wake_unlock(&usb_switch_lock);
        hwlog_info("usb switch wake unlock\n");
    }
}

int is_support_fcp(void);
static int fsa9685_write_reg(int reg, int val)
{
    int ret;
    if (NULL == this_client) {
        ret = -ERR_NO_DEV;
        hwlog_err("%s: this_client=NULL!!! ret=%d\n", __func__, ret);
        return ret;
    }
    ret = i2c_smbus_write_byte_data(this_client, reg, val);
    if (ret < 0)
        hwlog_info("%s: i2c write error!!! ret=%d\n", __func__, ret);

#ifdef CONFIG_FSA9685_DEBUG_FS
    chip_regs[reg] = val;
#endif
    return ret;
}

static int fsa9685_read_reg(int reg)
{
    int ret;
    if (NULL == this_client) {
        ret = -ERR_NO_DEV;
        hwlog_err("%s: this_client=NULL!!! ret=%d\n", __func__, ret);
        return ret;
    }
    ret = i2c_smbus_read_byte_data(this_client, reg);
    if (ret < 0)
        hwlog_info("%s: i2c read error!!! ret=%d\n", __func__, ret);

#ifdef CONFIG_FSA9685_DEBUG_FS
    chip_regs[reg] = ret;
#endif
    return ret;
}

static int fsa9685_write_reg_mask(int reg, int value,int mask)
{
    int val=0,ret=0;
    if (NULL == this_client) {
        ret = -ERR_NO_DEV;
        hwlog_err("%s: this_client=NULL!!! ret=%d\n", __func__, ret);
        return ret;
    }
    val= fsa9685_read_reg(reg);
    if(val < 0)
    {
        return val;
    }
    val &= ~mask;
    val |=value & mask;
    ret = fsa9685_write_reg(reg,val);
    return ret;
}

static int fsa9685_manual_switch(int input_select)
{
    int value = 0, ret = 0;
    if (NULL == this_client) {
        ret = -ERR_NO_DEV;
        hwlog_err("%s: this_client=NULL!!! ret=%d\n", __func__, ret);
        return ret;
    }

    hwlog_info("%s: input_select = %d", __func__, input_select);
    /* Two switch not support USB2_ID*/
    if(two_switch_flag && (FSA9685_USB2_ID_TO_IDBYPASS == input_select))
    {
        return 0;
    }
    switch (input_select){
        case FSA9685_USB1_ID_TO_IDBYPASS:
            value = REG_VAL_FSA9685_USB1_ID_TO_IDBYPASS;
            break;
        case FSA9685_USB2_ID_TO_IDBYPASS:
            value = REG_VAL_FSA9685_USB2_ID_TO_IDBYPASS;
            break;
        case FSA9685_UART_ID_TO_IDBYPASS:
            value = REG_VAL_FSA9685_UART_ID_TO_IDBYPASS;
            break;
        case FSA9685_MHL_ID_TO_CBUS:
            value = REG_VAL_FSA9685_MHL_ID_TO_CBUS;
            break;
        case FSA9685_USB1_ID_TO_VBAT:
            value = REG_VAL_FSA9685_USB1_ID_TO_VBAT;
            break;
        case FSA9685_OPEN:
        default:
            value = REG_VAL_FSA9685_OPEN;
            break;
    }

    ret = fsa9685_write_reg(FSA9685_REG_MANUAL_SW_1, value);
    if ( ret < 0 ){
        ret = -ERR_FSA9685_REG_MANUAL_SW_1;
        hwlog_err("%s: write reg FSA9685_REG_MANUAL_SW_1 error!!! ret=%d\n", __func__, ret);
        return ret;
    }

    value = fsa9685_read_reg(FSA9685_REG_CONTROL);
    if (value < 0){
        ret = -ERR_FSA9685_READ_REG_CONTROL;
        hwlog_err("%s: read FSA9685_REG_CONTROL error!!! ret=%d\n", __func__, ret);
        return ret;
    }

    value &= (~FSA9685_MANUAL_SW); // 0: manual switching
    ret = fsa9685_write_reg(FSA9685_REG_CONTROL, value);
    if ( ret < 0 ){
        ret = -ERR_FSA9685_WRITE_REG_CONTROL;
        hwlog_err("%s: write FSA9685_REG_CONTROL error!!! ret=%d\n", __func__, ret);
        return ret;
    }

    return 0;

}

static int fsa9685_manual_detach_work(void)
{
    int ret = 0;
    if (NULL == this_client){
        ret = -ERR_NO_DEV;
        hwlog_err("%s: this_client=NULL!!! ret=%d\n", __func__, ret);
        return ret;
    }

    schedule_delayed_work(&detach_delayed_work, msecs_to_jiffies(20));
    hwlog_info("%s: ------end.\n", __func__);
    return ret;
}
static void fsa9685_detach_work(struct work_struct *work)
{
    int ret;
    hwlog_info("%s: ------entry.\n", __func__);

    ret = fsa9685_read_reg(FSA9685_REG_DETACH_CONTROL);
    if ( ret < 0 ){
        hwlog_err("%s: read FSA9685_REG_DETACH_CONTROL error!!! ret=%d", __func__, ret);
        return;
    }

    ret = fsa9685_write_reg(FSA9685_REG_DETACH_CONTROL, 1);
    if ( ret < 0 ){
        hwlog_err("%s: write FSA9685_REG_DETACH_CONTROL error!!! ret=%d", __func__, ret);
        return;
    }

    hwlog_info("%s: ------end.\n", __func__);
    return;
}

static int fsa9685_dcd_timeout(bool enable_flag)
{
	int reg_val = 0;
	int ret;

	reg_val = fsa9685_read_reg(FSA9685_REG_DEVICE_ID);
	/*we need 9688c 9683 except 9688 not support enable dcd time out */
	if(FSA9688_VERSION_ID == ((reg_val & FAS9685_VERSION_ID_BIT_MASK) >> FAS9685_VERSION_ID_BIT_SHIFT)){
		return -1;
	}
	ret = fsa9685_write_reg_mask(FSA9685_REG_CONTROL2,enable_flag,FSA9685_DCD_TIME_OUT_MASK);
	if(ret < 0){
		hwlog_err("%s:write fsa9688c DCD enable_flag error!!!\n",__func__);
		return -1;
	}
	hwlog_info("%s:write fsa9688c DCD enable_flag is:%d!!!\n",__func__,enable_flag);
	return 0;
}

static void fsa9685_intb_work(struct work_struct *work);
static irqreturn_t fsa9685_irq_handler(int irq, void *dev_id)
{
    int gpio_value;

    usb_switch_wake_lock();
    gpio_value = gpio_get_value(gpio);
    if(gpio_value==1)
        hwlog_err("%s: intb high when interrupt occured!!!\n", __func__);

    schedule_work(&g_intb_work);

    hwlog_info("%s: ------end. gpio_value=%d\n", __func__, gpio_value);
    return IRQ_HANDLED;
}
/****************************************************************************
  Function:     is_fcp_charger_type
  Description:  after fcp detect ok,it will show it is fcp adapter
  Input:        void
  Output:       NA
  Return:        true:fcp adapter
                false: not fcp adapter
***************************************************************************/
int is_fcp_charger_type(void)
{
    int reg_val = 0;

    if(is_support_fcp())
    {
        return false;
    }

    reg_val = fsa9685_read_reg(FSA9685_REG_DEVICE_TYPE_4);

    if(reg_val < 0)
    {
        hwlog_err("%s: read FSA9685_REG_DEVICE_TYPE_4 error!reg:%d\n", __func__,reg_val);
        return false;
    }
    if(reg_val & FSA9685_ACCP_CHARGER_DET)
    {
        return true ;
    }
    return false;
}
static enum hisi_charger_type fsa9685_get_charger_type(void)
{
    enum hisi_charger_type charger_type = CHARGER_TYPE_NONE;
    int val = 0;

    if (NULL == this_client) {
        hwlog_info("%s: this_client=NULL! charger_type set to NONE\n", __func__);
        return charger_type;
    }

    val = fsa9685_read_reg(FSA9685_REG_DEVICE_TYPE_1);
    if (val < 0)
    {
        hwlog_err("%s: read REG[%d] erro, val = %d, charger_type set to NONE\n",
                  __func__, FSA9685_REG_DEVICE_TYPE_1, val);
        return charger_type;
    }

    if (val & FSA9685_USB_DETECTED)
        charger_type = CHARGER_TYPE_SDP;
    else if(val & FSA9685_CDP_DETECTED)
        charger_type = CHARGER_TYPE_CDP;
    else if(val & FSA9685_DCP_DETECTED)
        charger_type = CHARGER_TYPE_DCP;
    else
        charger_type = CHARGER_TYPE_NONE;

    if((charger_type == CHARGER_TYPE_NONE) && is_fcp_charger_type())
    {
       charger_type = CHARGER_TYPE_DCP;/*if is fcp ,report dcp,because when we detect fcp last time ,FSA9685_REG_DEVICE_TYPE_4 will be set */
       hwlog_info("%s:update charger type by device type4, charger type is:%d\n",__func__,charger_type);
    }

    return charger_type;
}

/****************************************************************************
  Function:     is_usb_id_abnormal
  Description:  check whether is usb id abnormal
  Input:        void
  Output:       NA
  Return:       1 -- abnormal ; 0 -- normal
***************************************************************************/
int fsa9685_is_water_intrused(void)
{
	u8 usb_id;
	int i;

	for (i = 0; i < 5; i++) {
		usb_id = fsa9685_read_reg(FSA9685_REG_ADC);
		usb_id &= FSA9685_REG_ADC_MASK;
		hwlog_info("usb id is 0x%x\n", usb_id);
		if ((usb_id >= WATER_CHECK_MIN_ID) && (usb_id <= WATER_CHECK_MAX_ID) && (usb_id != 0x0B))
			return 1;
		msleep(100);
	}

	return 0;
}

static void fsa9685_intb_work(struct work_struct *work)
{
    int reg_ctl, reg_intrpt, reg_adc, reg_dev_type1, reg_dev_type2, reg_dev_type3, vbus_status;
    int ret = -1;
    int ret2 = 0;
    int id_valid_status = ID_VALID;
    int usb_switch_wakelock_flag = USB_SWITCH_NEED_WAKE_UNLOCK;
    static int invalid_times = 0;
    static int otg_attach = 0;
    static int pedestal_attach = 0;
    reg_intrpt = fsa9685_read_reg(FSA9685_REG_INTERRUPT);
    vbus_status = fsa9685_read_reg(FSA9685_REG_VBUS_STATUS);
    hwlog_info("%s: read FSA9685_REG_INTERRUPT. reg_intrpt=0x%x\n", __func__, reg_intrpt);
    /* if support fcp ,disable fcp interrupt */
    if(!is_support_fcp()
        &&((0xFF != fsa9685_read_reg(FSA9685_REG_ACCP_INTERRUPT_MASK1))
        ||(0xFF != fsa9685_read_reg(FSA9685_REG_ACCP_INTERRUPT_MASK2))))
    {
        hwlog_info("disable fcp interrrupt again!!\n");
        ret2 |= fsa9685_write_reg_mask(FSA9685_REG_CONTROL2, FSA9685_ACCP_OSC_ENABLE,FSA9685_ACCP_OSC_ENABLE);
        ret2 |= fsa9685_write_reg_mask(FSA9685_REG_CONTROL2, 0,FSA9685_DCD_TIME_OUT_MASK);
        ret2 |= fsa9685_write_reg(FSA9685_REG_ACCP_INTERRUPT_MASK1, 0xFF);
        ret2 |= fsa9685_write_reg(FSA9685_REG_ACCP_INTERRUPT_MASK2, 0xFF);
        hwlog_info("%s : read ACCP interrupt,reg[0x59]=0x%x,reg[0x5A]=0x%x\n",__func__,
            fsa9685_read_reg(FSA9685_REG_ACCP_INTERRUPT1), fsa9685_read_reg(FSA9685_REG_ACCP_INTERRUPT2));
        if(ret2 < 0)
        {
            hwlog_err("accp interrupt mask write failed \n");
        }
    }

    if (unlikely(reg_intrpt < 0)) {
        hwlog_err("%s: read FSA9685_REG_INTERRUPT error!!!\n", __func__);
    } else if (unlikely(reg_intrpt == 0)) {
        hwlog_err("%s: read FSA9685_REG_INTERRUPT, and no intr!!!\n", __func__);
    } else {
        if (reg_intrpt & FSA9685_ATTACH){
            hwlog_info("%s: FSA9685_ATTACH\n", __func__);
            reg_dev_type1 = fsa9685_read_reg(FSA9685_REG_DEVICE_TYPE_1);
            reg_dev_type2 = fsa9685_read_reg(FSA9685_REG_DEVICE_TYPE_2);
            reg_dev_type3 = fsa9685_read_reg(FSA9685_REG_DEVICE_TYPE_3);
            hwlog_info("%s: reg_dev_type1=0x%X, reg_dev_type2=0x%X, reg_dev_type3= 0x%X\n", __func__,
                reg_dev_type1, reg_dev_type2, reg_dev_type3);
            if (reg_dev_type1 & FSA9685_FC_USB_DETECTED) {
                hwlog_info("%s: FSA9685_FC_USB_DETECTED\n", __func__);
            }
            if (reg_dev_type1 & FSA9685_USB_DETECTED){
                hwlog_info("%s: FSA9685_USB_DETECTED\n", __func__);
                if (FSA9685_USB2_ID_TO_IDBYPASS == get_swstate_value()){
                    switch_usb2_access_through_ap();
                    hwlog_info("%s: fsa9685 switch to USB2 by setvalue\n", __func__);
                }
            }
            if (reg_dev_type1 & FSA9685_UART_DETECTED) {
                hwlog_info("%s: FSA9685_UART_DETECTED\n", __func__);
            }
            if (reg_dev_type1 & FSA9685_MHL_DETECTED) {
                if (fsa9685_mhl_detect_disable == 1) {
                    hwlog_info("%s: mhl detection is not enabled on this platform, regard as an invalid detection\n", __func__);
                    id_valid_status = ID_INVALID;
                } else {
                    hwlog_info("%s: FSA9685_MHL_DETECTED\n", __func__);
                }
            }
            if (reg_dev_type1 & FSA9685_CDP_DETECTED) {
                hwlog_info("%s: FSA9685_CDP_DETECTED\n", __func__);
            }
            if (reg_dev_type1 & FSA9685_DCP_DETECTED) {
                hwlog_info("%s: FSA9685_DCP_DETECTED\n", __func__);
                charge_type_dcp_detected_notify();
            }
            if ((reg_dev_type1 & FSA9685_USBOTG_DETECTED) && fsa9685_usbid_enable) {
                hwlog_info("%s: FSA9685_USBOTG_DETECTED\n", __func__);
                otg_attach = 1;
                usb_switch_wakelock_flag = USB_SWITCH_NEED_WAKE_LOCK;
                hisi_usb_id_change(ID_FALL_EVENT);
            }
            if (reg_dev_type1 & FSA9685_DEVICE_TYPE1_UNAVAILABLE) {
                id_valid_status = ID_INVALID;
                hwlog_info("%s: FSA9685_DEVICE_TYPE1_UNAVAILABLE_DETECTED\n", __func__);
            }
            if (reg_dev_type2 & FSA9685_JIG_UART) {
                hwlog_info("%s: FSA9685_JIG_UART\n", __func__);
            }
            if (reg_dev_type2 & FSA9685_DEVICE_TYPE2_UNAVAILABLE) {
                id_valid_status = ID_INVALID;
                hwlog_info("%s: FSA9685_DEVICE_TYPE2_UNAVAILABLE_DETECTED\n", __func__);
            }
            if (reg_dev_type3 & FSA9685_CUSTOMER_ACCESSORY7) {
                fsa9685_manual_sw(FSA9685_USB1_ID_TO_IDBYPASS);
                hwlog_info("%s:Enter FSA9685_CUSTOMER_ACCESSORY7\n", __func__);
            }
            if (reg_dev_type3 & FSA9685_CUSTOMER_ACCESSORY5) {
                hwlog_info("%s: FSA9685_CUSTOMER_ACCESSORY5, 365K\n", __func__);
                pedestal_attach = 1;
            }
            if (reg_dev_type3 & FSA9685_FM8_ACCESSORY) {
                hwlog_info("%s: FSA9685_FM8_DETECTED\n", __func__);
                fsa9685_manual_sw(FSA9685_USB1_ID_TO_IDBYPASS);
            }
            if (reg_dev_type3 & FSA9685_DEVICE_TYPE3_UNAVAILABLE) {
                id_valid_status = ID_INVALID;
                if (reg_intrpt & FSA9685_VBUS_CHANGE) {
                    fsa9685_manual_sw(FSA9685_USB1_ID_TO_IDBYPASS);
                }
                hwlog_info("%s: FSA9685_DEVICE_TYPE3_UNAVAILABLE_DETECTED\n", __func__);
            }
        }

        if (reg_intrpt & FSA9685_RESERVED_ATTACH) {
            id_valid_status = ID_INVALID;
            if (reg_intrpt & FSA9685_VBUS_CHANGE) {
                fsa9685_manual_sw(FSA9685_USB1_ID_TO_IDBYPASS);
            }
            hwlog_info("%s: FSA9685_RESERVED_ATTACH\n", __func__);
        }

        if (reg_intrpt & FSA9685_DETACH) {
            hwlog_info("%s: FSA9685_DETACH\n", __func__);
            /* check control register, if manual switch, reset to auto switch */
            reg_ctl = fsa9685_read_reg(FSA9685_REG_CONTROL);
            reg_dev_type2 = fsa9685_read_reg(FSA9685_REG_DEVICE_TYPE_2);
            hwlog_info("%s: reg_ctl=0x%x\n", __func__, reg_ctl);
            if (reg_ctl < 0){
                hwlog_err("%s: read FSA9685_REG_CONTROL error!!! reg_ctl=%d\n", __func__, reg_ctl);
                goto OUT;
            }
            if (0 == (reg_ctl & FSA9685_MANUAL_SW))
            {
                reg_ctl |= FSA9685_MANUAL_SW;
                ret = fsa9685_write_reg(FSA9685_REG_CONTROL, reg_ctl);
                if (ret < 0) {
                    hwlog_err("%s: write FSA9685_REG_CONTROL error!!!\n", __func__);
                    goto OUT;
                }
            }
            if ((otg_attach == 1) && fsa9685_usbid_enable) {
                hwlog_info("%s: FSA9685_USBOTG_DETACH\n", __func__);
                hisi_usb_id_change(ID_RISE_EVENT);
                otg_attach = 0;
            }
            if (pedestal_attach ==1) {
                hwlog_info("%s: FSA9685_CUSTOMER_ACCESSORY5_DETACH\n", __func__);
                pedestal_attach = 0;
            }
            if (reg_dev_type2 & FSA9685_JIG_UART) {
                hwlog_info("%s: FSA9685_JIG_UART\n", __func__);
            }
        }
        if (reg_intrpt & FSA9685_VBUS_CHANGE) {
            hwlog_info("%s: FSA9685_VBUS_CHANGE\n", __func__);
        }
        if (reg_intrpt & FSA9685_ADC_CHANGE) {
            reg_adc = fsa9685_read_reg(FSA9685_REG_ADC);
            hwlog_info("%s: FSA9685_ADC_CHANGE. reg_adc=%d\n", __func__, reg_adc);
            if (reg_adc < 0) {
                hwlog_err("%s: read FSA9685_ADC_CHANGE error!!! reg_adc=%d\n", __func__, reg_adc);
            }
            /* do user specific handle */
        }
    }

    if ((ID_INVALID == id_valid_status) &&
                (reg_intrpt & (FSA9685_ATTACH | FSA9685_RESERVED_ATTACH))) {
        invalid_times++;
        hwlog_info("%s: invalid time:%d reset fsa9685 work\n", __func__, invalid_times);

        if (invalid_times < MAX_DETECTION_TIMES) {
            hwlog_info("%s: start schedule delayed work\n", __func__);
            schedule_delayed_work(&detach_delayed_work, msecs_to_jiffies(0));
        } else {
            invalid_times = 0;
        }
    } else if ((ID_VALID == id_valid_status) &&
                (reg_intrpt & (FSA9685_ATTACH | FSA9685_RESERVED_ATTACH))) {
        invalid_times = 0;
    }

    if((USB_SWITCH_NEED_WAKE_UNLOCK == usb_switch_wakelock_flag) &&
            (0 == invalid_times)) {
        usb_switch_wake_unlock();
    }

OUT:
    hwlog_info("%s: ------end.\n", __func__);
    return;
}

#ifdef CONFIG_FSA9685_DEBUG_FS
static ssize_t dump_regs_show(struct device *dev, struct device_attribute *attr,
                char *buf)
{
    const int regaddrs[] = {0x01, 0x02, 0x03, 0x04, 0x5, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d};
    const char str[] = "0123456789abcdef";
    int i = 0, index;
    char val = 0;
    for (i=0; i<0x60; i++) {
        if ((i%3)==2)
            buf[i]=' ';
        else
            buf[i] = 'x';
    }
    buf[0x5d] = '\n';
    buf[0x5e] = 0;
    buf[0x5f] = 0;
    if ( reg_locked != 0 ) {
        for (i=0; i<ARRAY_SIZE(regaddrs); i++) {
            if (regaddrs[i] != 0x03) {
                val = fsa9685_read_reg(regaddrs[i]);
                chip_regs[regaddrs[i]] = val;
            }
        }
    }

    for (i=0; i<ARRAY_SIZE(regaddrs); i++) {
        index = regaddrs[i];
        val = chip_regs[index];
            buf[3*index] = str[(val&0xf0)>>4];
        buf[3*index+1] = str[val&0x0f];
        buf[3*index+2] = ' ';
    }

    return 0x60;
}
static DEVICE_ATTR(dump_regs, S_IRUGO, dump_regs_show, NULL);
#endif

static ssize_t jigpin_ctrl_store(struct device *dev,
                          struct device_attribute *attr, const char *buf, size_t size)
{
    int jig_val = JIG_PULL_DEFAULT_DOWN;
    int ret = 0;
    if (NULL == this_client) {
        ret = -ERR_NO_DEV;
        hwlog_err("%s: this_client=NULL!!! ret=%d\n", __func__, ret);
        return ret;
    }
    if (sscanf(buf, "%d", &jig_val) != 1) {
        hwlog_err("%s:write regs failed, invalid input!\n", __func__);
        return -1;
    }
    ret = fsa9685_write_reg_mask(FSA9685_REG_CONTROL, 0, FSA9685_MANUAL_SW);
    if (ret < 0) {
        hwlog_err("%s:write FSA9685_REG_CONTROL error!\n",__func__);
        return ret;
    }
    if (FSA9683_I2C_ADDR == this_client->addr
          || CBTL9689_I2C_ADDR == this_client->addr) {
        ret = fsa9685_write_reg_mask(FSA9685_REG_WD_CTRL,
                   FSA9685_WD_CTRL_JIG_MANUAL_EN,FSA9685_WD_CTRL_JIG_MANUAL_EN);
        if (ret < 0) {
            hwlog_err("%s:write FSA9685_REG_WD_CTRL error!!!\n", __func__);
            return ret;
        }
    }
    switch (jig_val) {
        case JIG_PULL_DEFAULT_DOWN:
            hwlog_info("%s:pull down jig pin to default state\n", __func__);
            if (FSA9683_I2C_ADDR == this_client->addr) {
                ret = fsa9685_write_reg_mask(FSA9685_REG_MANUAL_SW_2,
                            FSA9683_REG_JIG_DEFAULT_DOWN, REG_JIG_MASK);
                if (ret < 0) {
                    hwlog_err("%s:write FSA9685_REG_MANUAL_SW_2 error!\n",__func__);
                    break;
                }
            } else {
                ret = fsa9685_write_reg_mask(FSA9685_REG_MANUAL_SW_2,
                            REG_JIG_DEFAULT_DOWN, REG_JIG_MASK);
                if (ret < 0) {
                    hwlog_err("%s:write FSA9685_REG_MANUAL_SW_2 error!\n",__func__);
                    break;
                }
            }
            break;
        case JIG_PULL_UP:
            hwlog_info("%s:pull up jig pin to cut battery\n", __func__);
            if(FSA9683_I2C_ADDR == this_client->addr){
                ret = fsa9685_write_reg_mask(FSA9685_REG_MANUAL_SW_2,
                            FSA9683_REG_JIG_UP, REG_JIG_MASK);
                if (ret < 0) {
                    hwlog_err("%s:write FSA9685_REG_MANUAL_SW_2 error!\n",__func__);
                }
            }else {
                ret = fsa9685_write_reg_mask(FSA9685_REG_MANUAL_SW_2,
                            REG_JIG_UP, REG_JIG_MASK);
                if (ret < 0) {
                    hwlog_err("%s:write FSA9685_REG_MANUAL_SW_2 error!\n",__func__);
                }
            }
            break;
        default:
            hwlog_err("%s:Wrong input action!\n", __func__);
            return -1;
    }
    return 0x60;
}

static ssize_t jigpin_ctrl_show(struct device *dev, struct device_attribute *attr,
                char *buf)
{
    int manual_sw2_val;
    manual_sw2_val = fsa9685_read_reg(FSA9685_REG_MANUAL_SW_2);
    if (manual_sw2_val < 0) {
        hwlog_err("%s: read FSA9685_REG_MANUAL_SW_2 error!!! reg=%d.\n", __func__, manual_sw2_val);
    }

    return snprintf(buf, PAGE_SIZE, "%02x\n", manual_sw2_val);
}

static DEVICE_ATTR(jigpin_ctrl, S_IRUGO | S_IWUSR, jigpin_ctrl_show, jigpin_ctrl_store);

static ssize_t switchctrl_store(struct device *dev,
                          struct device_attribute *attr, const char *buf, size_t size)
{
    int action = 0;
    if (sscanf(buf, "%d", &action) != 1) {
        hwlog_err("%s:write regs failed, invalid input!\n", __func__);
        return -1;
    }
    switch (action) {
        case MANUAL_DETACH:
            hwlog_info("%s:manual_detach\n", __func__);
            fsa9685_manual_detach();
            break;
        case MANUAL_SWITCH:
            hwlog_info("%s:manual_switch\n", __func__);
            fsa9685_manual_sw(FSA9685_USB1_ID_TO_VBAT);
            break;
        default:
            hwlog_err("%s:Wrong input action!\n", __func__);
            return -1;
    }
    return 0x60;
}

static ssize_t switchctrl_show(struct device *dev, struct device_attribute *attr,
                char *buf)
{
    int device_type1 = 0, device_type2 = 0, device_type3 = 0, mode = -1, tmp = 0;
    device_type1 = fsa9685_read_reg(FSA9685_REG_DEVICE_TYPE_1);
    if (device_type1 < 0) {
        hwlog_err("%s: read FSA9685_REG_DEVICE_TYPE_1 error!!! reg=%d.\n", __func__, device_type1);
        goto read_reg_failed;
    }
    device_type2 = fsa9685_read_reg(FSA9685_REG_DEVICE_TYPE_2);
    if (device_type2 < 0) {
        hwlog_err("%s: read FSA9685_REG_DEVICE_TYPE_2 error!!! reg=%d.\n", __func__, device_type2);
        goto read_reg_failed;
    }
    device_type3 = fsa9685_read_reg(FSA9685_REG_DEVICE_TYPE_3);
    if (device_type3 < 0) {
        hwlog_err("%s: read FSA9685_REG_DEVICE_TYPE_3 error!!! reg=%d.\n", __func__, device_type3);
        goto read_reg_failed;
    }
    hwlog_info("%s:device_type1=0x%x,device_type2=0x%x,device_type3=0x%x\n", __func__,device_type1,device_type2,device_type3);
    tmp = device_type3 << 16 | device_type2 << 8 | device_type1;
    mode = 0;
    while (tmp >> mode)
        mode++;
read_reg_failed:
    return sprintf(buf, "%d\n", mode);
}

static DEVICE_ATTR(switchctrl, S_IRUGO | S_IWUSR, switchctrl_show, switchctrl_store);

/****************************************************************************
  Function:     fcp_adapter_reset
  Description:  reset adapter
  Input:         NA
  Output:       NA
  Return:        0: success
                -1: fail
***************************************************************************/
int fcp_adapter_reset(void)
{
   int ret = 0,val = 0;
   val = FSA9685_ACCP_MSTR_RST | FAS9685_ACCP_SENDCMD |FSA9685_ACCP_IS_ENABLE;
   ret =  fsa9685_write_reg_mask(FSA9685_REG_ACCP_CNTL, val,FAS9685_ACCP_CNTL_MASK);
   hwlog_info("%s : send fcp adapter reset %s \n",__func__,ret < 0 ? "fail": "sucess");
   return ret;
}
/****************************************************************************
  Function:     fcp_stop_charge_config
  Description:  fcp stop charge config
  Input:         NA
  Output:       NA
  Return:        0: success
                -1: fail
***************************************************************************/
static int fcp_stop_charge_config(void)
{
    //do nothing
    return 0;
}
/****************************************************************************
  Function:     switch_chip_reset
  Description:  reset fsa9688
  Input:         NA
  Output:       NA
  Return:        0: success
                -1: fail
***************************************************************************/
int switch_chip_reset(void)
{
    int ret = 0,reg_ctl = 0,gpio_value = 0;
    ret = fsa9685_write_reg(0x19, 0x89);
    if(ret < 0)
    {
        hwlog_err("reset fsa9688 failed \n");
    }
    ret = fsa9685_write_reg(FSA9685_REG_DETACH_CONTROL, 1);
    if ( ret < 0 ){
        hwlog_err("%s: write FSA9685_REG_DETACH_CONTROL error!!! ret=%d", __func__, ret);
    }

    /* disable accp interrupt */
    ret |= fsa9685_write_reg_mask(FSA9685_REG_CONTROL2, FSA9685_ACCP_OSC_ENABLE,FSA9685_ACCP_OSC_ENABLE);
    ret |= fsa9685_write_reg_mask(FSA9685_REG_CONTROL2, 0,FSA9685_DCD_TIME_OUT_MASK);
    ret |= fsa9685_write_reg(FSA9685_REG_ACCP_INTERRUPT_MASK1, 0xFF);
    ret |= fsa9685_write_reg(FSA9685_REG_ACCP_INTERRUPT_MASK2, 0xFF);
    if(ret < 0)
    {
        hwlog_err("accp interrupt mask write failed \n");
    }

    /* clear INT MASK */
    reg_ctl = fsa9685_read_reg(FSA9685_REG_CONTROL);
    if ( reg_ctl < 0 ) {
        hwlog_err("%s: read FSA9685_REG_CONTROL error!!! reg_ctl=%d.\n", __func__, reg_ctl);
        return -1;
    }
    hwlog_info("%s: read FSA9685_REG_CONTROL. reg_ctl=0x%x.\n", __func__, reg_ctl);

    reg_ctl &= (~FSA9685_INT_MASK);
    ret = fsa9685_write_reg(FSA9685_REG_CONTROL, reg_ctl);
    if ( ret < 0 ) {
        hwlog_err("%s: write FSA9685_REG_CONTROL error!!! reg_ctl=%d.\n", __func__, reg_ctl);
        return -1;
    }
    hwlog_info("%s: write FSA9685_REG_CONTROL. reg_ctl=0x%x.\n", __func__, reg_ctl);

    ret = fsa9685_write_reg(FSA9685_REG_DCD, 0x0c);
    if ( ret < 0 ) {
        hwlog_err("%s: write FSA9685_REG_DCD error!!! reg_DCD=0x%x.\n", __func__, 0x08);
        return -1;
    }
    hwlog_info("%s: write FSA9685_REG_DCD. reg_DCD=0x%x.\n", __func__, 0x0c);

    gpio_value = gpio_get_value(gpio);
    hwlog_info("%s: intb=%d after clear MASK.\n", __func__, gpio_value);

    if (gpio_value == 0) {
        schedule_work(&g_intb_work);
    }
    return 0;
}
/****************************************************************************
  Function:     fcp_cmd_transfer_check
  Description:  check cmd transfer success or fail
  Input:         NA
  Output:       NA
  Return:        0: success
                   -1: fail
***************************************************************************/
int fcp_cmd_transfer_check(void)
{
    int reg_val1 = 0,reg_val2 =0,i =0;
    /*read accp interrupt registers until value is not zero */
    do{
        msleep(10);
        reg_val1 = fsa9685_read_reg(FSA9685_REG_ACCP_INTERRUPT1);
        reg_val2 = fsa9685_read_reg(FSA9685_REG_ACCP_INTERRUPT2);
        i++;
    }while(i<5 && reg_val1== 0 && reg_val2 == 0);

    if(reg_val1== 0 && reg_val2 == 0)
    {
        hwlog_info("%s : read accp interrupt time out,total time is %d ms\n",__func__,i*10);
    }
    if(reg_val1 < 0 || reg_val2 < 0 )
    {
        hwlog_err("%s: read  error!!! reg_val1=%d,reg_val2=%d \n", __func__, reg_val1,reg_val2);
        return -1;
    }

    /*if something  changed print reg info */
    if(reg_val2 & (FAS9685_PROSTAT | FAS9685_DSDVCSTAT) )
    {
        hwlog_info("%s : ACCP state changed  ,reg[0x59]=0x%x,reg[0x5A]=0x%x\n",__func__,reg_val1,reg_val2);
    }

    /* judge if cmd transfer success */
    if((reg_val1 & FAS9685_ACK) &&(reg_val1 & FAS9685_CMDCPL)
        && !(reg_val1 & FAS9685_CRCPAR)
        && !(reg_val2 & (FAS9685_CRCRX | FAS9685_PARRX)))
    {
        return 0;
    }
    else
    {
        hwlog_err("%s : reg[0x59]=0x%x,reg[0x5A]=0x%x\n",__func__,reg_val1,reg_val2);
        return -1;
    }
}
/****************************************************************************
  Function:     fcp_protocol_restart
  Description:  disable accp protocol and enable again
  Input:         NA
  Output:       NA
  Return:        0: success
                   -1: fail
***************************************************************************/
void fcp_protocol_restart(void)
{
    int reg_val =0;
    int ret = 0;
    /* disable accp protocol */
    fsa9685_write_reg_mask(FSA9685_REG_ACCP_CNTL, 0,FAS9685_ACCP_CNTL_MASK);
    msleep(100);
    reg_val = fsa9685_read_reg(FSA9685_REG_ACCP_STATUS);
    if(FSA9688_ACCP_STATUS_SLAVE_GOOD == (reg_val & FSA9688_ACCP_STATUS_MASK))
    {
        hwlog_err("%s : disable accp enable bit failed ,accp status [0x40]=0x%x  \n",__func__,reg_val);
    }

    /* enable accp protocol */
    fsa9685_write_reg_mask(FSA9685_REG_ACCP_CNTL, FSA9685_ACCP_IS_ENABLE,FAS9685_ACCP_CNTL_MASK);
    msleep(100);
    reg_val = fsa9685_read_reg(FSA9685_REG_ACCP_STATUS);
    if(FSA9688_ACCP_STATUS_SLAVE_GOOD != (reg_val & FSA9688_ACCP_STATUS_MASK))
    {
        hwlog_err("%s : enable accp enable bit failed, accp status [0x40]=0x%x  \n",__func__,reg_val);
    }
    /* disable accp interrupt */
    ret |= fsa9685_write_reg_mask(FSA9685_REG_CONTROL2, FSA9685_ACCP_OSC_ENABLE,FSA9685_ACCP_OSC_ENABLE);
    ret |= fsa9685_write_reg(FSA9685_REG_ACCP_INTERRUPT_MASK1, 0xFF);
    ret |= fsa9685_write_reg(FSA9685_REG_ACCP_INTERRUPT_MASK2, 0xFF);
    if(ret < 0)
    {
        hwlog_err("accp interrupt mask write failed \n");
    }
    hwlog_info("%s :disable and enable accp protocol accp status  is 0x%x \n",__func__,reg_val);
}
/****************************************************************************
  Function:     accp_adapter_reg_read
  Description:  read adapter register
  Input:        reg:register's num
                val:the value of register
  Output:       NA
  Return:        0: success
                -1: fail
***************************************************************************/
int accp_adapter_reg_read(int* val, int reg)
{
    int reg_val1 = 0,reg_val2 =0;
    int i=0,ret =0;
    mutex_lock(&accp_adaptor_reg_lock);
    for(i=0;i< FCP_RETRY_MAX_TIMES;i++)
    {
        /*before send cmd, read and clear accp interrupt registers */
        reg_val1 = fsa9685_read_reg(FSA9685_REG_ACCP_INTERRUPT1);
        reg_val2 = fsa9685_read_reg(FSA9685_REG_ACCP_INTERRUPT2);

        ret |= fsa9685_write_reg(FSA9685_REG_ACCP_CMD, FCP_CMD_SBRRD);
        ret |= fsa9685_write_reg(FSA9685_REG_ACCP_ADDR, reg);
        ret |= fsa9685_write_reg_mask(FSA9685_REG_ACCP_CNTL, FSA9685_ACCP_IS_ENABLE | FAS9685_ACCP_SENDCMD,FAS9685_ACCP_CNTL_MASK);
        if(ret)
        {
            hwlog_err("%s: write error ret is %d \n",__func__,ret);
            mutex_unlock(&accp_adaptor_reg_lock);
            return -1;
        }

        /* check cmd transfer success or fail */
        if(0 ==fcp_cmd_transfer_check())
        {
            /* recived data from adapter */
            *val = fsa9685_read_reg(FSA9685_REG_ACCP_DATA);
            break;
        }

        /* if transfer failed, restart accp protocol */
        fcp_protocol_restart();
        hwlog_err("%s : adapter register read fail times=%d ,register=0x%x,data=0x%x,reg[0x59]=0x%x,reg[0x5A]=0x%x \n",__func__,i,reg,*val,reg_val1,reg_val2);
    }
    hwlog_debug("%s : adapter register retry times=%d ,register=0x%x,data=0x%x,reg[0x59]=0x%x,reg[0x5A]=0x%x \n",__func__,i,reg,*val,reg_val1,reg_val2);
    if(FCP_RETRY_MAX_TIMES == i)
    {
        hwlog_err("%s : ack error,retry %d times \n",__func__,i);
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    mutex_unlock(&accp_adaptor_reg_lock);
    return ret;
}

/****************************************************************************
  Function:     accp_adapter_reg_write
  Description:  write value into the adapter register
  Input:        reg:register's num
                val:the value of register
  Output:       NA
  Return:        0: success
                -1: fail
***************************************************************************/
int accp_adapter_reg_write(int val, int reg)
{
    int reg_val1 = 0,reg_val2 =0;
    int i = 0,ret = 0;
    mutex_lock(&accp_adaptor_reg_lock);
    for(i=0;i< FCP_RETRY_MAX_TIMES;i++)
    {
        /*before send cmd, clear accp interrupt registers */
        reg_val1 = fsa9685_read_reg(FSA9685_REG_ACCP_INTERRUPT1);
        reg_val2 = fsa9685_read_reg(FSA9685_REG_ACCP_INTERRUPT2);

        ret |=fsa9685_write_reg(FSA9685_REG_ACCP_CMD, FCP_CMD_SBRWR);
        ret |=fsa9685_write_reg(FSA9685_REG_ACCP_ADDR, reg);
        ret |=fsa9685_write_reg(FSA9685_REG_ACCP_DATA, val);
        ret |=fsa9685_write_reg_mask(FSA9685_REG_ACCP_CNTL, FSA9685_ACCP_IS_ENABLE | FAS9685_ACCP_SENDCMD,FAS9685_ACCP_CNTL_MASK);
        if(ret < 0)
        {
            hwlog_err("%s: write error ret is %d \n",__func__,ret);
            mutex_unlock(&accp_adaptor_reg_lock);
            return -1;
        }

        /* check cmd transfer success or fail */
        if(0 ==fcp_cmd_transfer_check())
        {
            break;
        }

        /* if transfer failed, restart accp protocol */
        fcp_protocol_restart();
        hwlog_err("%s : adapter register write fail times=%d ,register=0x%x,data=0x%x,reg[0x59]=0x%x,reg[0x5A]=0x%x \n",__func__,i,reg,val,reg_val1,reg_val2);
    }
    hwlog_debug("%s : adapter register retry times=%d ,register=0x%x,data=0x%x,reg[0x59]=0x%x,reg[0x5A]=0x%x \n",__func__,i,reg,val,reg_val1,reg_val2);

    if(FCP_RETRY_MAX_TIMES == i)
    {
        hwlog_err("%s : ack error,retry %d times \n",__func__,i);
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    mutex_unlock(&accp_adaptor_reg_lock);
    return ret;
}

/****************************************************************************
  Function:     acp_adapter_detect
  Description:  detect accp adapter
  Input:        NA
  Output:       NA
  Return:        0: success
                -1: other fail
                1:fcp adapter but detect fail
***************************************************************************/
int accp_adapter_detect(void)
{
    int reg_val1 = 0;
    int reg_val2 = 0;
    int i = 0;
    if(NULL == this_client)
    {
        return ACCP_ADAPTOR_DETECT_OTHER;
    }

    mutex_lock(&accp_detect_lock);
    /*check accp status*/
    reg_val1 = fsa9685_read_reg(FSA9685_REG_DEVICE_TYPE_4);
    reg_val2 = fsa9685_read_reg(FSA9685_REG_ACCP_STATUS);
    if((reg_val1 & FSA9685_ACCP_CHARGER_DET)
        && (FSA9688_ACCP_STATUS_SLAVE_GOOD == (reg_val2 & FSA9688_ACCP_STATUS_MASK )))
    {
        hwlog_info("accp adapter detect ok.\n");
        mutex_unlock(&accp_detect_lock);
        return ACCP_ADAPTOR_DETECT_SUCC;
    }

    /* enable accp */
    reg_val1 = fsa9685_read_reg(FSA9685_REG_CONTROL2);
    reg_val1 |= FSA9685_ACCP_ENABLE;
    fsa9685_write_reg(FSA9685_REG_CONTROL2, reg_val1);

    /*detect hisi acp charger*/
    for(i=0; i < ACCP_DETECT_MAX_COUT; i++)
    {
        reg_val1 = fsa9685_read_reg(FSA9685_REG_DEVICE_TYPE_4);
        reg_val2 = fsa9685_read_reg(FSA9685_REG_ACCP_STATUS);
        if((reg_val1 & FSA9685_ACCP_CHARGER_DET)
            && (FSA9688_ACCP_STATUS_SLAVE_GOOD == (reg_val2 & FSA9688_ACCP_STATUS_MASK )))
        {
            break;
        }
        msleep(ACCP_POLL_TIME);
    }
    /*clear accp interrupt*/
    hwlog_info("%s : read ACCP interrupt,reg[0x59]=0x%x,reg[0x5A]=0x%x\n",__func__,
        fsa9685_read_reg(FSA9685_REG_ACCP_INTERRUPT1), fsa9685_read_reg(FSA9685_REG_ACCP_INTERRUPT2));
    if(ACCP_DETECT_MAX_COUT == i )
    {
        mutex_unlock(&accp_detect_lock);
        hwlog_info("not accp adapter ,reg[0x%x]=0x%x,reg[0x%x]=0x%x \n",FSA9685_REG_DEVICE_TYPE_4,reg_val1,FSA9685_REG_ACCP_STATUS,reg_val2);
        if(reg_val1 & FSA9685_ACCP_CHARGER_DET)
        {
            return ACCP_ADAPTOR_DETECT_FAIL;/*accp adapter but detect fail */
        }
        return ACCP_ADAPTOR_DETECT_OTHER;/*not fcp adapter*/

    }
    hwlog_info("accp adapter detect ok,take %d ms \n",i*ACCP_POLL_TIME);
    mutex_unlock(&accp_detect_lock);
    return ACCP_ADAPTOR_DETECT_SUCC;
}
static int fcp_adapter_detect(void)
{
    int ret;
#ifdef CONFIG_DIRECT_CHARGER
    int val;
#endif
    ret = accp_adapter_detect();
    if (ACCP_ADAPTOR_DETECT_OTHER == ret)
    {
        hwlog_info("fcp adapter other detect\n");
        return FCP_ADAPTER_DETECT_OTHER;
    }
    if (ACCP_ADAPTOR_DETECT_FAIL == ret)
    {
        hwlog_info("fcp adapter detect fail\n");
        return FCP_ADAPTER_DETECT_FAIL;
    }
#ifdef CONFIG_DIRECT_CHARGER
    if (fsa9685_is_support_scp())
    {
        return FCP_ADAPTER_DETECT_SUCC;
    }
    ret = accp_adapter_reg_read(&val, SCP_ADP_TYPE);
    if(ret)
    {
        hwlog_err("%s : read SCP_ADP_TYPE fail ,ret = %d \n",__func__,ret);
        return FCP_ADAPTER_DETECT_SUCC;
    }
    return FCP_ADAPTER_DETECT_OTHER;
#else
    return FCP_ADAPTER_DETECT_SUCC;
#endif
}
/**********************************************************
*  Function:        fsa9685_reg_dump
*  Discription:     dump register for charger dsm
*  Parameters:    ptr
*  return value:   void
**********************************************************/
#define DUMP_REG_NUM 21
#define DUMP_STR_LENTH 32

struct fsa9885_reg_dump_type
{
    unsigned char reg_add[DUMP_REG_NUM];
    unsigned char reg_val[DUMP_REG_NUM];
};

void fsa9685_reg_dump(char* ptr)
{
	const unsigned char reg_dump[DUMP_REG_NUM] = {0x01, 0x02, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x40, 0x41, 0x44, 0x47, 0x48, 0x5b, 0x5c};
	int i = 0;
	int val = 0;
	char buf[DUMP_STR_LENTH] = {0};

	struct fsa9885_reg_dump_type fsa9885_reg_dump;

	for(i = 0;i < sizeof(reg_dump)/sizeof(unsigned char);i++)
	{
		val = fsa9685_read_reg(reg_dump[i]);
		if (val < 0) {
			hwlog_err("%s: fsa9685_read_reg error!!!", __func__);
			return ;
		}
		fsa9885_reg_dump.reg_val[i] = val;
		fsa9885_reg_dump.reg_add[i] = reg_dump[i];
		val = 0;
	}

	snprintf(buf,sizeof(buf),"\n");
	strncat(ptr,buf,strlen(buf));
	memset(buf, 0, DUMP_STR_LENTH);

	for(i = 0;i < DUMP_REG_NUM;i++)
	{
		snprintf(buf,sizeof(buf),"reg[0x%2x]=0x%2x\n",fsa9885_reg_dump.reg_add[i],fsa9885_reg_dump.reg_val[i]);
		strncat(ptr,buf,strlen(buf));
		memset(buf, 0, DUMP_STR_LENTH);
	}
}
/****************************************************************************
  Function:     fcp_get_adapter_output_vol
  Description:  get fcp output vol
  Input:        NA.
  Output:       fcp output vol(5V/9V/12V)
  Return:        0: success
                -1: fail
***************************************************************************/
int fcp_get_adapter_output_vol(int *vol)
{
    int num = 0;
    int output_vol = 0;
    int ret =0;
    if(NULL == this_client)
    {
        return -1;
    }

    /*get adapter vol list number,exclude 5V*/
    ret = accp_adapter_reg_read(&num, FCP_SLAVE_REG_DISCRETE_CAPABILITIES);
    /*currently,fcp only support three out vol config(5v/9v/12v)*/
    if (ret || num > 2 )
    {
        hwlog_err("%s: vout list support err, reg[0x21] = %d.\n", __func__, num);
        return -1;
    }

    /*get max out vol value*/
   ret = accp_adapter_reg_read(&output_vol, FCP_SLAVE_REG_DISCRETE_OUT_V(num));
    if(ret )
    {
        hwlog_err("%s: get max out vol value failed ,ouputvol=%d,num=%d.\n",__func__,output_vol,num);
        return -1;
    }
    *vol = output_vol;
    hwlog_info("%s: get adapter max out vol = %d,num= %d.\n", __func__, output_vol,num);
    return 0;
}


/****************************************************************************
  Function:     fcp_set_adapter_output_vol
  Description:  set fcp adapter output vol
  Input:        NA
  Output:       NA
  Return:        0: success
                -1: fail
***************************************************************************/
int fcp_set_adapter_output_vol(int *output_vol)
{
    int val = 0;
    int vol = 0;
    int ret = 0;

    if(NULL == this_client)
    {
        return -1;
    }

    /*read ID OUTI , for identify huawei adapter*/
    ret = accp_adapter_reg_read(&val, FCP_SLAVE_REG_ID_OUT0);
    if(ret < 0)
    {
        hwlog_err("%s: adapter ID OUTI read failed, ret is %d \n",__func__,ret);
        return -1;
    }
    hwlog_info("%s: id out reg[0x4] = %d.\n", __func__, val);

    /*get adapter max output vol value*/
    ret = fcp_get_adapter_output_vol(&vol);
    if(ret <0)
    {
        hwlog_err("%s: fcp get adapter output vol err.\n", __func__);
        return -1;
    }

    /* PLK only support 5V/9V */
    if(vol > FCP_OUTPUT_VOL_9V * FCP_VOL_STEP)
    {
        vol = FCP_OUTPUT_VOL_9V * FCP_VOL_STEP;
    }
    *output_vol = vol/FCP_VOL_STEP;

    /*retry if write fail */
    ret |= accp_adapter_reg_write(vol, FCP_SLAVE_REG_VOUT_CONFIG);
    ret |= accp_adapter_reg_read(&val, FCP_SLAVE_REG_VOUT_CONFIG);
    hwlog_info("%s: vout config reg[0x2c] = %d.\n", __func__, val);
    if(ret <0 ||val != vol )
    {
        hwlog_err("%s:out vol config err, reg[0x2c] = %d.\n", __func__, val);
        return -1;
    }

    ret = accp_adapter_reg_write(FCP_SLAVE_SET_VOUT, FCP_SLAVE_REG_OUTPUT_CONTROL);
    if(ret < 0)
    {
        hwlog_err("%s : enable adapter output voltage failed \n ",__func__);
        return -1;
    }
    hwlog_info("fcp adapter output vol set ok.\n");
    return 0;
}

/****************************************************************************
  Function:     fcp_get_adapter_max_power
  Description:  get fcp adpter max power
  Input:        NA.
  Output:       NA
  Return:       MAX POWER(W)
***************************************************************************/
int fcp_get_adapter_max_power(int *max_power)
{
    int reg_val = 0;
    int ret =0;
    if(NULL == this_client)
    {
        return -1;
    }

    /*read max power*/
    ret = accp_adapter_reg_read(&reg_val, FCP_SLAVE_REG_MAX_PWR);
    if(ret != 0)
    {
        hwlog_err("%s: read max power failed \n",__func__);
        return -1;
    }

    hwlog_info("%s: max power reg[0x22] = %d.\n", __func__, reg_val);
    *max_power = (reg_val >> 1);
    return 0;
}

/**********************************************************
*  Function:       fcp_get_adapter_output_current
*  Discription:    fcp get the output current from adapter max power and output vol
*  Parameters:     NA
*  return value:  input_current(MA)
**********************************************************/
int fcp_get_adapter_output_current(void)
{
    int output_current = 0;
    int output_vol = 0;
    int max_power = 0;
    int ret =0;
    if(NULL == this_client)
    {
        return -1;
    }

    ret |= fcp_get_adapter_output_vol(&output_vol);
    ret |= fcp_get_adapter_max_power(&max_power);
    if (ret != 0)
    {
        hwlog_err("%s : output current read failed \n",__func__);
        return -1;
    }
    output_current = max_power*1000/output_vol;
    hwlog_info("%s: output current = %d.\n", __func__, output_current);
    return output_current;
}

/**********************************************************
*  Function:       is_support_fcp
*  Discription:    check whether support fcp
*  Parameters:     NA
*  return value:   0:support
                  -1:not support
**********************************************************/
int is_support_fcp(void)
{
    int reg_val = 0;
    static int flag_result = -EINVAL;
    if(NULL == this_client)
    {
        return -1;
    }

    if(!fsa9685_fcp_support)
    {
        return -1;
    }

    if(flag_result != -EINVAL)
    {
        return flag_result;
    }
    reg_val = fsa9685_read_reg(FSA9685_REG_DEVICE_ID);
    if (FSA9688_VERSION_ID != ((reg_val & FAS9685_VERSION_ID_BIT_MASK) >> FAS9685_VERSION_ID_BIT_SHIFT)
        && FSA9688C_VERSION_ID != ((reg_val & FAS9685_VERSION_ID_BIT_MASK) >> FAS9685_VERSION_ID_BIT_SHIFT)){
        hwlog_err("%s:no fsa9688,no support fcp, reg[0x1]=%d.\n", __func__, reg_val);
        flag_result = -1;
    }
    else
    {
        flag_result = 0;
    }

    return flag_result;
}
/**********************************************************
*  Function:       fcp_switch_status_check
*  Discription:    when in fcp status ,it will check the reg status of 9685
*  Parameters:     NA
*  return value:   -1:status error 0:status ok
**********************************************************/
int fcp_read_switch_status(void)
{
    int reg_val1 = 0;
    /*check accp status*/
    reg_val1 = fsa9685_read_reg(FSA9685_REG_ACCP_STATUS);
    if((FSA9688_ACCP_STATUS_SLAVE_GOOD != (reg_val1 & FSA9688_ACCP_STATUS_MASK )))
    {
         return -1;
    }
    return 0;
}
/**********************************************************
*  Function:       fcp_adapter_status_check
*  Discription:    when in fcp status ,it will check adapter reg status
*  Parameters:     NA
*  return value: 0:status ok ;FCP_ADAPTER_OTEMP:over temp;FCP_ADAPTER_OCURRENT: over current;FCP_ADAPTER_OVLT: over ovl;
**********************************************************/
int fcp_read_adapter_status (void)
{
    int val = 0,ret =0;
    ret = accp_adapter_reg_read(&val, FCP_ADAPTER_STATUS);
    if(ret !=0)
    {
        hwlog_err("%s : read failed ,ret = %d \n",__func__,ret);
        return 0;
    }
    hwlog_info("val is %d \n",val);

    if( FCP_ADAPTER_OVLT == (val & FCP_ADAPTER_OVLT))
    {
       return FCP_ADAPTER_OVLT;
    }

    if( FCP_ADAPTER_OCURRENT == (val & FCP_ADAPTER_OCURRENT))
    {
        return FCP_ADAPTER_OCURRENT;
    }

    if( FCP_ADAPTER_OTEMP == (val & FCP_ADAPTER_OTEMP))
    {
        return FCP_ADAPTER_OTEMP;
    }
    return 0;
}
#ifdef CONFIG_DIRECT_CHARGER
static int fsa9685_scp_adaptor_detect(void)
{
    int ret;
    int val;
    ret = accp_adapter_detect();
    if (ACCP_ADAPTOR_DETECT_OTHER == ret)
    {
        hwlog_info("scp adapter other detect\n");
        return SCP_ADAPTOR_DETECT_OTHER;
    }
    if (ACCP_ADAPTOR_DETECT_FAIL == ret)
    {
        hwlog_info("scp adapter detect fail\n");
        return SCP_ADAPTOR_DETECT_FAIL;
    }
    ret = accp_adapter_reg_read(&val, SCP_ADP_TYPE);
    if(ret)
    {
        hwlog_err("%s : read SCP_ADP_TYPE fail ,ret = %d \n",__func__,ret);
        return SCP_ADAPTOR_DETECT_OTHER;
    }
    hwlog_info("%s : read SCP_ADP_TYPE val = %d \n",__func__,val);
    if ((val & SCP_ADP_TYPE_B_MASK) == SCP_ADP_TYPE_B)
    {
        hwlog_info("scp type B adapter detect\n ");
        ret = accp_adapter_reg_read(&val, SCP_B_ADP_TYPE);
        if (ret)
        {
            hwlog_err("%s : read SCP_B_ADP_TYPE fail ,ret = %d \n",__func__,ret);
            return SCP_ADAPTOR_DETECT_OTHER;/*not scp adapter*/
        }
        hwlog_info("%s : read SCP_B_ADP_TYPE val = %d \n",__func__,val);
        if (SCP_B_DIRECT_ADP == val)
        {
                hwlog_info("scp type B direct charge adapter detect\n ");
                return SCP_ADAPTOR_DETECT_SUCC;
        }
    }

    return SCP_ADAPTOR_DETECT_OTHER;

}
static int fsa9685_scp_output_mode_enable(int enable)
{
    int val;
    int ret;
    ret = accp_adapter_reg_read(&val, SCP_CTRL_BYTE0);
    if(ret)
    {
        hwlog_err("%s : read failed ,ret = %d \n",__func__,ret);
        return -1;
    }
    hwlog_info("[%s]val befor is %d \n", __func__, val);
    val &= ~(SCP_OUTPUT_MODE_MASK);
    val |= enable ? SCP_OUTPUT_MODE_ENABLE:SCP_OUTPUT_MODE_DISABLE;
    hwlog_info("[%s]val after is %d \n", __func__, val);
    ret = accp_adapter_reg_write(val, SCP_CTRL_BYTE0);
    if(ret < 0)
    {
        hwlog_err("%s : failed \n ",__func__);
        return -1;
    }
    return 0;
}

static int fsa9685_scp_adaptor_output_enable(int enable)
{
    int val;
    int ret;

    ret = fsa9685_scp_output_mode_enable(1);
    if(ret)
    {
        hwlog_err("%s : scp output mode enable failed ,ret = %d \n",__func__,ret);
        return -1;
    }

    ret = accp_adapter_reg_read(&val, SCP_CTRL_BYTE0);
    if(ret)
    {
        hwlog_err("%s : read failed ,ret = %d \n",__func__,ret);
        return -1;
    }
    hwlog_info("[%s]val befor is %d \n", __func__, val);
    val &= ~(SCP_OUTPUT_MASK);
    val |= enable ? SCP_OUTPUT_ENABLE:SCP_OUTPUT_DISABLE;
    hwlog_info("[%s]val after is %d \n", __func__, val);
    ret = accp_adapter_reg_write(val, SCP_CTRL_BYTE0);
    if(ret < 0)
    {
        hwlog_err("%s : failed \n ",__func__);
        return -1;
    }
    return 0;
}
static int fsa9685_adaptor_reset(int enable)
{
    int val;
    int ret;
    ret = accp_adapter_reg_read(&val, SCP_CTRL_BYTE0);
    if(ret)
    {
        hwlog_err("%s : read failed ,ret = %d \n",__func__,ret);
        return -1;
    }
    hwlog_info("[%s]val befor is %d \n", __func__, val);
    val &= ~(SCP_ADAPTOR_RESET_MASK);
    val |= enable ? SCP_ADAPTOR_RESET_ENABLE:SCP_ADAPTOR_RESET_DISABLE;
    hwlog_info("[%s]val after is %d \n", __func__, val);
    ret = accp_adapter_reg_write(val, SCP_CTRL_BYTE0);
    if(ret < 0)
    {
        hwlog_err("%s : failed \n ",__func__);
        return -1;
    }
    return 0;
}


static int  fsa9685_is_support_scp(void)
{
    if(!fsa9685_scp_support)
    {
        return -1;
    }
    return 0;
}
static int fsa9685_scp_config_iset_boundary(int iboundary)
{
    int val;
    int ret;

    /*high byte store in low address*/
    val = (iboundary >> 8) & 0xff;
    ret = accp_adapter_reg_write(val, SCP_ISET_BOUNDARY_L);
    if (ret)
        return ret;
    /*low byte store in high address*/
    val = iboundary & 0xff;
    ret |= accp_adapter_reg_write(val, SCP_ISET_BOUNDARY_H);
    if(ret < 0)
    {
        hwlog_err("%s : failed \n ",__func__);
    }
    return ret;

}
static int fsa9685_scp_config_vset_boundary(int vboundary)
{
    int val;
    int ret;

    /*high byte store in low address*/
    val = (vboundary >> 8) & 0xff;
    ret = accp_adapter_reg_write(val, SCP_VSET_BOUNDARY_L);
    if (ret)
        return ret;
    /*low byte store in high address*/
    val = vboundary & 0xff;
    ret |= accp_adapter_reg_write(val, SCP_VSET_BOUNDARY_H);
    if(ret < 0)
    {
        hwlog_err("%s : failed \n ",__func__);
    }
    return ret;

}
static int fsa9685_scp_set_adaptor_voltage(int vol)
{
    int val;
    int ret;

    val = vol - VSSET_OFFSET;
    val = val / VSSET_STEP;
    ret = accp_adapter_reg_write(val, SCP_VSSET);
    if(ret < 0)
    {
        hwlog_err("%s : failed \n ",__func__);
        return -1;
    }
    return 0;
}
static int fsa9685_scp_set_watchdog_timer(int second)
{
    int val;
    int ret;

    ret = accp_adapter_reg_read(&val, SCP_CTRL_BYTE1);
    if(ret)
    {
        hwlog_err("%s : read failed ,ret = %d \n",__func__,ret);
        return -1;
    }
    hwlog_info("[%s]val befor is %d \n", __func__, val);
    val &= ~(SCP_WATCHDOG_MASK);
    val |= (second * 2) & SCP_WATCHDOG_MASK; /*1 bit means 0.5 second*/
    hwlog_info("[%s]val after is %d \n", __func__, val);
    ret = accp_adapter_reg_write(val, SCP_CTRL_BYTE1);
    if(ret < 0)
    {
        hwlog_err("%s : failed \n ",__func__);
        return -1;
    }
    return 0;
}
static int fsa9685_scp_init(struct scp_init_data * sid)
{
    /*open 5v boost*/
    int ret;
    int val;
    ret = fsa9685_scp_output_mode_enable(sid->scp_mode_enable);
    if(ret)
        return ret;
    ret = fsa9685_scp_config_vset_boundary(sid->vset_boundary);
    if(ret)
        return ret;
    ret = fsa9685_scp_config_iset_boundary(sid->iset_boundary);
    if(ret)
        return ret;
    ret = fsa9685_scp_set_adaptor_voltage(sid->init_adaptor_voltage);
    if(ret)
        return ret;
    ret = fsa9685_scp_set_watchdog_timer(sid->watchdog_timer);
    if(ret)
        return ret;
    ret = accp_adapter_reg_read(&val, SCP_CTRL_BYTE0);
    if(ret)
        return ret;
    hwlog_info("%s : CTRL_BYTE0 = 0x%x \n ",__func__, val);
    ret = accp_adapter_reg_read(&val, SCP_CTRL_BYTE1);
    if(ret)
        return ret;
    hwlog_info("%s : CTRL_BYTE1 = 0x%x \n ",__func__, val);
    ret = accp_adapter_reg_read(&val, SCP_STATUS_BYTE0);
    if(ret)
        return ret;
    hwlog_info("%s : STATUS_BYTE0 = 0x%x \n ",__func__, val);
    ret = accp_adapter_reg_read(&val, SCP_STATUS_BYTE1);
    if(ret)
        return ret;
    hwlog_info("%s : STATUS_BYTE1 = 0x%x \n ",__func__, val);
    ret = accp_adapter_reg_read(&val, SCP_VSET_BOUNDARY_H);
    if(ret)
        return ret;
    hwlog_info("%s : VSET_BOUNDARY_H = 0x%x \n ",__func__, val);
    ret = accp_adapter_reg_read(&val, SCP_VSET_BOUNDARY_L);
    if(ret)
        return ret;
    hwlog_info("%s : VSET_BOUNDARY_L = 0x%x \n ",__func__, val);
    ret = accp_adapter_reg_read(&val, SCP_ISET_BOUNDARY_H);
    if(ret)
        return ret;
    hwlog_info("%s : ISET_BOUNDARY_H = 0x%x \n ",__func__, val);
    ret = accp_adapter_reg_read(&val, SCP_ISET_BOUNDARY_L);
    if(ret)
        return ret;
    hwlog_info("%s : ISET_BOUNDARY_L = 0x%x \n ",__func__, val);
    return ret;
}
static int fsa9685_scp_chip_reset(void)
{
    hwlog_err("%s\n",__func__);
    return switch_chip_reset();
}
static int fsa9685_scp_exit(struct direct_charge_device* di)
{
	int ret;
	ret = fsa9685_scp_output_mode_enable(0);
	switch(di->adaptor_vendor_id)
	{
		case IWATT_ADAPTER:
			ret  |= fsa9685_adaptor_reset(1);
			break;
		default:
			hwlog_info("%s:not iWatt\n",__func__);
	}
	msleep(50);
	hwlog_err("%s\n",__func__);
	ret |= fsa9685_scp_chip_reset();
	return ret;
}
static int fsa9685_scp_get_adaptor_voltage(void)
{
    int val;
    int ret;
    ret = accp_adapter_reg_read(&val, SCP_SREAD_VOUT);
    if(ret)
    {
        hwlog_err("%s : read failed ,ret = %d \n",__func__,ret);
        return -1;
    }
    val = val*SCP_SREAD_VOUT_STEP + SCP_SREAD_VOUT_OFFSET;
    hwlog_info("[%s]val is %d \n", __func__, val);
    return val;
}
static int fsa9685_scp_set_adaptor_current(int cur)
{
    int val;
    int ret;

    val = cur / ISSET_STEP;
    ret = accp_adapter_reg_write(val, SCP_ISSET);
    if(ret < 0)
    {
        hwlog_err("%s : failed \n ",__func__);
        return -1;
    }
    return 0;
}
static int fsa9685_scp_get_adaptor_current(void)
{
    int val;
    int ret;
    ret = accp_adapter_reg_read(&val, SCP_SREAD_IOUT);
    if(ret)
    {
        hwlog_err("%s : read failed ,ret = %d \n",__func__,ret);
        return -1;
    }
    val = val*SCP_SREAD_IOUT_STEP;
    hwlog_info("[%s]val is %d \n", __func__, val);
    return val;
}
static int fsa9685_scp_get_adaptor_current_set(void)
{
    int val;
    int ret;
    ret = accp_adapter_reg_read(&val, SCP_ISSET);
    if(ret)
    {
        hwlog_err("%s : read failed ,ret = %d \n",__func__,ret);
        return -1;
    }
    val = val*ISSET_STEP;
    hwlog_info("[%s]val is %d \n", __func__, val);
    return val;
}

static int fsa9685_scp_get_adaptor_max_current(void)
{
    int val;
    int ret;
    int A;
    int B;
    int rs;

    ret = accp_adapter_reg_read(&val, SCP_MAX_IOUT);
    if(ret)
    {
        hwlog_err("%s : read MAX_IOUT failed ,ret = %d \n",__func__,ret);
        return -1;
    }
    hwlog_info("[%s]max_iout reg is %d \n", __func__, val);
    A = (SCP_MAX_IOUT_A_MASK & val) >> SCP_MAX_IOUT_A_SHIFT;
    B = SCP_MAX_IOUT_B_MASK & val;
    switch (A){
        case 0:
            A = 1;
	    break;
	case 1:
            A = 10;
	    break;
	case 2:
            A = 100;
	    break;
	case 3:
            A = 1000;
	    break;
	default:
	    return -1;
    }
    rs = B*A;
    hwlog_info("[%s]MAX IOUT initial is %d \n", __func__, rs);
    ret = accp_adapter_reg_read(&val, SCP_SSTS);
    if(ret)
    {
        hwlog_err("%s : read SSTS failed ,ret = %d \n",__func__,ret);
        return -1;
    }
    hwlog_info("[%s]ssts reg is %d \n", __func__, val);
    B = (SCP_SSTS_B_MASK & val) >> SCP_SSTS_B_SHIFT;
    A = SCP_SSTS_A_MASK & val;
    if (1 == B)
    {
        rs = rs * A / 8;
    }
    hwlog_info("[%s]MAX IOUT final is %d \n", __func__, rs);
    return rs;
}

static int fsa9685_scp_get_adaptor_temp(int* temp)
{
    int val = 0;
    int ret;

    ret = accp_adapter_reg_read(&val, SCP_INSIDE_TMP);
    if(ret)
    {
        hwlog_err("%s : read failed ,ret = %d \n",__func__,ret);
        return -1;
    }
    hwlog_info("[%s]val is %d \n", __func__, val);
    *temp = val;

    return 0;
}
static int fsa9685_scp_cable_detect(void)
{
    int val;
    int ret;
    ret = accp_adapter_reg_read(&val, SCP_STATUS_BYTE0);
    if(ret)
    {
        hwlog_err("%s : read failed ,ret = %d \n",__func__,ret);
        return SCP_CABLE_DETECT_ERROR;
    }
    hwlog_info("[%s]val is %d \n", __func__, val);
    if (val & SCP_CABLE_STS_MASK)
    {
        return SCP_CABLE_DETECT_SUCC;
    }
    return SCP_CABLE_DETECT_FAIL;
}
static int fsa9685_scp_adaptor_reset(void)
{
    return fcp_adapter_reset();
}
static int fsa9685_stop_charge_config(void)
{
    return 0;
}
static int fsa9685_is_scp_charger_type(void)
{
    return is_fcp_charger_type();
}
static int fsa9685_scp_get_adaptor_status(void)
{
    return 0;
}
static int fsa9685_scp_get_adaptor_info(void* info)
{
    int ret;
    struct adaptor_info* p = (struct adaptor_info*)info;

    ret = accp_adapter_reg_read(&(p->b_adp_type), SCP_B_ADP_TYPE);
    if(ret)
        return ret;
    ret = accp_adapter_reg_read(&(p->vendor_id_h), SCP_VENDOR_ID_H);
    if(ret)
        return ret;
    ret = accp_adapter_reg_read(&(p->vendor_id_l), SCP_VENDOR_ID_L);
    if(ret)
        return ret;
    ret = accp_adapter_reg_read(&(p->module_id_h), SCP_MODULE_ID_H);
    if(ret)
        return ret;
    ret = accp_adapter_reg_read(&(p->module_id_l), SCP_MODULE_ID_L);
    if(ret)
        return ret;
    ret = accp_adapter_reg_read(&(p->serrial_no_h), SCP_SERRIAL_NO_H);
    if(ret)
        return ret;
    ret = accp_adapter_reg_read(&(p->serrial_no_l), SCP_SERRIAL_NO_L);
    if(ret)
        return ret;
    ret = accp_adapter_reg_read(&(p->pchip_id), SCP_PCHIP_ID);
    if(ret)
        return ret;
    ret = accp_adapter_reg_read(&(p->hwver), SCP_HWVER);
    if(ret)
        return ret;
    ret = accp_adapter_reg_read(&(p->fwver_h), SCP_FWVER_H);
    if(ret)
        return ret;
    ret = accp_adapter_reg_read(&(p->fwver_l), SCP_FWVER_L);

    return ret;
}
static int fsa9685_get_adapter_vendor_id(void)
{
	int val = 0;
	int ret;

	ret = accp_adapter_reg_read(&val, SCP_PCHIP_ID);
	if(ret)
	{
		hwlog_err("%s : read failed ,ret = %d \n",__func__,ret);
		return -1;
	}
	hwlog_info("[%s]val is 0x%x \n", __func__, val);
	switch (val)
	{
		case VENDOR_ID_RICHTEK:
			hwlog_info("[%s]adapter is richtek \n", __func__);
			return RICHTEK_ADAPTER;
		case VENDOR_ID_IWATT:
			hwlog_info("[%s]adapter is iwatt \n", __func__);
			return IWATT_ADAPTER;
		default:
			hwlog_info("[%s]this adaptor vendor id is not found!\n", __func__);
			return val;
	}
}
static int fsa9685_get_usb_port_leakage_current_info(void)
{
	int val = 0;
	int ret;

	ret = accp_adapter_reg_read(&val, SCP_STATUS_BYTE0);
	if(ret)
	{
		hwlog_err("%s : read failed ,ret = %d \n",__func__,ret);
		return -1;
	}
	hwlog_info("[%s]val is 0x%x \n", __func__, val);
	val &= SCP_PORT_LEAKAGE_INFO;
	val = val>>SCP_PORT_LEAKAGE_SHIFT;
	hwlog_info("[%s]val is 0x%x \n", __func__, val);
	return val;
}
static int fsa9685_scp_get_chip_status(void)
{
    return 0;
}
struct smart_charge_ops scp_fsa9685_ops = {
    .is_support_scp = fsa9685_is_support_scp,
    .scp_init = fsa9685_scp_init,
    .scp_exit = fsa9685_scp_exit,
    .scp_adaptor_detect = fsa9685_scp_adaptor_detect,
    .scp_set_adaptor_voltage = fsa9685_scp_set_adaptor_voltage,
    .scp_get_adaptor_voltage = fsa9685_scp_get_adaptor_voltage,
    .scp_set_adaptor_current = fsa9685_scp_set_adaptor_current,
    .scp_get_adaptor_current = fsa9685_scp_get_adaptor_current,
    .scp_get_adaptor_current_set = fsa9685_scp_get_adaptor_current_set,
    .scp_get_adaptor_max_current = fsa9685_scp_get_adaptor_max_current,
    .scp_adaptor_reset = fsa9685_scp_adaptor_reset,
    .scp_adaptor_output_enable = fsa9685_scp_adaptor_output_enable,
    .scp_chip_reset = fsa9685_scp_chip_reset,
    .scp_stop_charge_config = fsa9685_stop_charge_config,
    .is_scp_charger_type = fsa9685_is_scp_charger_type,
    .scp_get_adaptor_status = fsa9685_scp_get_adaptor_status,
    .scp_get_adaptor_info = fsa9685_scp_get_adaptor_info,
    .scp_get_chip_status = fsa9685_scp_get_chip_status,
    .scp_cable_detect = fsa9685_scp_cable_detect,
    .scp_get_adaptor_temp = fsa9685_scp_get_adaptor_temp,
    .scp_get_adapter_vendor_id = fsa9685_get_adapter_vendor_id,
    .scp_get_usb_port_leakage_current_info = fsa9685_get_usb_port_leakage_current_info,
};
#endif
struct fcp_adapter_device_ops fcp_fsa9688_ops = {
    .get_adapter_output_current = fcp_get_adapter_output_current,
    .set_adapter_output_vol     = fcp_set_adapter_output_vol,
    .detect_adapter             = fcp_adapter_detect,
    .is_support_fcp             = is_support_fcp,
    .switch_chip_reset          = switch_chip_reset,
    .fcp_adapter_reset          = fcp_adapter_reset,
    .stop_charge_config        = fcp_stop_charge_config,
    .is_fcp_charger_type    = is_fcp_charger_type,
    .fcp_read_adapter_status = fcp_read_adapter_status,
    .fcp_read_switch_status = fcp_read_switch_status,
    .reg_dump = fsa9685_reg_dump,
};
struct charge_switch_ops chrg_fsa9685_ops = {
	.get_charger_type = fsa9685_get_charger_type,
	.is_water_intrused = fsa9685_is_water_intrused,
};

/**********************************************************
*  Function:       fcp_mmi_show
*  Discription:    file node for mmi testing fast charge protocol
*  Parameters:     NA
*  return value:   0:success
*                  1:fail
*                  2:not support
**********************************************************/
static ssize_t fcp_mmi_show(struct device *dev,struct device_attribute *attr, char *buf)
{
    int result = FCP_TEST_FAIL;
    enum hisi_charger_type type = hisi_get_charger_type();

    /* judge whether support fcp */
    if(fcp_test_is_support())
    {
        result = FCP_NOT_SUPPORT;
        return snprintf(buf,PAGE_SIZE,"%d\n",result);
    }
    /*to avoid the usb port cutoff when CTS test*/
    if ((type == CHARGER_TYPE_SDP) || (type == CHARGER_TYPE_CDP))
    {
        result = FCP_TEST_FAIL;
        hwlog_err("fcp detect fail 1,charge type is %d \n",type);
        return snprintf(buf,PAGE_SIZE,"%d\n",result);
    }
    /* fcp adapter detect */
   if( fcp_test_detect_adapter())
    {
        /* 0:sdp 1:cdp 2:dcp 3:unknow 4:none*/
        hwlog_err("fcp detect fail 2,charge type is %d \n",fsa9685_get_charger_type());
        result = FCP_TEST_FAIL;
    }
    else
    {
        result = FCP_TEST_SUCC;
    }
    hwlog_info("%s: fcp mmi result  %d\n",__func__,result);
    return snprintf(buf,PAGE_SIZE,"%d\n",result);
}

static DEVICE_ATTR(fcp_mmi, S_IRUGO, fcp_mmi_show, NULL);

#ifdef CONFIG_OF
static const struct of_device_id switch_fsa9685_ids[] = {
	{ .compatible = "huawei,fairchild_fsa9685" },
	{ .compatible = "huawei,fairchild_fsa9683"},
	{ .compatible = "huawei,nxp_cbtl9689" },
	{ },
};
MODULE_DEVICE_TABLE(of, switch_fsa9685_ids);
#endif

static struct switch_extra_ops huawei_switch_extra_ops = {
	.manual_switch = fsa9685_manual_switch,
	.dcd_timeout_enable =  fsa9685_dcd_timeout,
	.manual_detach = fsa9685_manual_detach_work,
};

static int fsa9685_probe(
    struct i2c_client *client, const struct i2c_device_id *id)
{
    int ret = 0, reg_ctl, gpio_value, reg_vendor = -1;
    struct device_node *node = client->dev.of_node;
#ifdef CONFIG_FSA9685_DEBUG_FS
    struct class *switch_class = NULL;
    struct device * new_dev = NULL;
#endif

    hwlog_info("%s: ------entry.\n", __func__);

    if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
        hwlog_err("%s: i2c_check_functionality error!!!\n", __func__);
        ret = -ERR_NO_DEV;
        this_client = NULL;
        goto err_i2c_check_functionality;
    }
    if(this_client)
    {
        hwlog_info("%s:chip is already detected\n", __func__);
		ret = -ERR_NO_DEV;
        return ret;
    }
    else
    {
        this_client = client;
    }
    /* distingush the chip with different address */
    reg_vendor = fsa9685_read_reg(FSA9685_REG_DEVICE_ID);
    if ( reg_vendor < 0 ) {
        hwlog_err("%s: read FSA9685_REG_DEVICE_ID error!!! reg_vendor=%d.\n", __func__, reg_vendor);
        goto err_i2c_check_functionality;
    }

#ifdef CONFIG_FSA9685_DEBUG_FS
    ret = device_create_file(&client->dev, &dev_attr_dump_regs);
    if (ret < 0) {
        hwlog_err("%s: device_create_file error!!! ret=%d.\n", __func__, ret);
        ret = -ERR_SWITCH_USB_DEV_REGISTER;
        goto err_i2c_check_functionality;
    }
#endif
/*create a node for phone-off current drain test*/
    ret = device_create_file(&client->dev, &dev_attr_switchctrl);
    if (ret < 0) {
        hwlog_err("%s: device_create_file error!!! ret=%d.\n", __func__, ret);
        ret = -ERR_SWITCH_USB_DEV_REGISTER;
        goto err_get_named_gpio;
    }

    ret = device_create_file(&client->dev, &dev_attr_jigpin_ctrl);
    if (ret < 0) {
        hwlog_err("%s: device_create_file error!!! ret=%d.\n", __func__, ret);
        ret = -ERR_SWITCH_USB_DEV_REGISTER;
        goto err_create_jigpin_ctrl_failed;
    }

    mutex_init(&accp_detect_lock);
    mutex_init(&accp_adaptor_reg_lock);
    ret = device_create_file(&client->dev, &dev_attr_fcp_mmi);
    if (ret < 0) {
        hwlog_err("%s: device_create_file error!!! ret=%d.\n", __func__, ret);
        ret = -ERR_SWITCH_USB_DEV_REGISTER;
        goto err_create_fcp_mmi_failed;
    }

    switch_class = class_create(THIS_MODULE, "usb_switch");
    if (IS_ERR(switch_class)) {
        hwlog_err("%s:create switch class failed!\n", __func__);
        goto err_create_link_failed;
    }
    new_dev = device_create(switch_class, NULL, 0, NULL, "switch_ctrl");
    if (NULL == new_dev) {
        hwlog_err("%s:device create failed!\n", __func__);
        goto err_create_link_failed;
    }
    ret = sysfs_create_link(&new_dev->kobj, &client->dev.kobj, "manual_ctrl");
    if (ret < 0) {
        hwlog_err("%s:create link to switch failed!\n", __func__);
        goto err_create_link_failed;
    }
    of_property_read_u32(node, "usbid-enable", &fsa9685_usbid_enable);
    of_property_read_u32(node, "fcp_support", &fsa9685_fcp_support);
    of_property_read_u32(node, "scp_support", &fsa9685_scp_support);
    of_property_read_u32(node, "mhl_detect_disable", &fsa9685_mhl_detect_disable);
    of_property_read_u32(node, "two-switch-flag", &two_switch_flag);

/*create link end*/
    gpio = of_get_named_gpio(node, "fairchild_fsa9685,gpio-intb", 0);
    if (gpio < 0) {
        hwlog_err("%s: of_get_named_gpio error!!! ret=%d, gpio=%d.\n", __func__, ret, gpio);
        ret = -ERR_OF_GET_NAME_GPIO;
        goto err_get_named_gpio;
    }

    client->irq = gpio_to_irq(gpio);

    if (client->irq < 0) {
        hwlog_err("%s: gpio_to_irq error!!! ret=%d, gpio=%d, client->irq=%d.\n", __func__, ret, gpio, client->irq);
        ret = -ERR_GPIO_TO_IRQ;
        goto err_get_named_gpio;
    }

    ret = gpio_request(gpio, "fsa9685_int");
    if (ret < 0) {
        hwlog_err("%s: gpio_request error!!! ret=%d. gpio=%d.\n", __func__, ret, gpio);
        ret = -ERR_GPIO_REQUEST;
        goto err_get_named_gpio;
    }

    ret = gpio_direction_input(gpio);
    if (ret < 0) {
        hwlog_err("%s: gpio_direction_input error!!! ret=%d. gpio=%d.\n", __func__, ret, gpio);
        ret = -ERR_GPIO_DIRECTION_INPUT;
        goto err_gpio_direction_input;
    }

    wake_lock_init(&usb_switch_lock, WAKE_LOCK_SUSPEND, "usb_switch_wakelock");

    INIT_DELAYED_WORK(&detach_delayed_work, fsa9685_detach_work);
    ret = fsa9685_write_reg(FSA9685_REG_DETACH_CONTROL, 1);
    if ( ret < 0 ){
        hwlog_err("%s: write FSA9685_REG_DETACH_CONTROL error!!! ret=%d", __func__, ret);
    }

    ret |= fsa9685_write_reg_mask(FSA9685_REG_CONTROL2, 0,FSA9685_DCD_TIME_OUT_MASK);
    if ( ret < 0 ){
        hwlog_err("%s: write FSA9685_REG_CONTROL2 FSA9685_DCD_TIME_OUT_MASK error!!! ret=%d", __func__, ret);
    }
    /* if support fcp ,disable fcp interrupt */
    if( 0 == is_support_fcp())
    {
        ret |= fsa9685_write_reg_mask(FSA9685_REG_CONTROL2, FSA9685_ACCP_OSC_ENABLE,FSA9685_ACCP_OSC_ENABLE);
        ret |= fsa9685_write_reg(FSA9685_REG_ACCP_INTERRUPT_MASK1, 0xFF);
        ret |= fsa9685_write_reg(FSA9685_REG_ACCP_INTERRUPT_MASK2, 0xFF);
        if(ret < 0)
        {
            hwlog_err("accp interrupt mask write failed \n");
        }
    }
    /* interrupt register */
    INIT_WORK(&g_intb_work, fsa9685_intb_work);

    ret = request_irq(client->irq,
               fsa9685_irq_handler,
               IRQF_NO_SUSPEND | IRQF_TRIGGER_FALLING,
               "fsa9685_int", client);
    if (ret < 0) {
        hwlog_err("%s: request_irq error!!! ret=%d.\n", __func__, ret);
        ret = -ERR_REQUEST_THREADED_IRQ;
        goto err_gpio_direction_input;
    }
    /* clear INT MASK */
    reg_ctl = fsa9685_read_reg(FSA9685_REG_CONTROL);
    if ( reg_ctl < 0 ) {
        hwlog_err("%s: read FSA9685_REG_CONTROL error!!! reg_ctl=%d.\n", __func__, reg_ctl);
        goto err_gpio_direction_input;
    }
    hwlog_info("%s: read FSA9685_REG_CONTROL. reg_ctl=0x%x.\n", __func__, reg_ctl);

    reg_ctl &= (~FSA9685_INT_MASK);
    ret = fsa9685_write_reg(FSA9685_REG_CONTROL, reg_ctl);
    if ( ret < 0 ) {
        hwlog_err("%s: write FSA9685_REG_CONTROL error!!! reg_ctl=%d.\n", __func__, reg_ctl);
        goto err_gpio_direction_input;
    }
    hwlog_info("%s: write FSA9685_REG_CONTROL. reg_ctl=0x%x.\n", __func__, reg_ctl);

    ret = fsa9685_write_reg(FSA9685_REG_DCD, 0x0c);
    if ( ret < 0 ) {
        hwlog_err("%s: write FSA9685_REG_DCD error!!! reg_DCD=0x%x.\n", __func__, 0x08);
        goto err_gpio_direction_input;
    }
    hwlog_info("%s: write FSA9685_REG_DCD. reg_DCD=0x%x.\n", __func__, 0x0c);

    gpio_value = gpio_get_value(gpio);
    hwlog_info("%s: intb=%d after clear MASK.\n", __func__, gpio_value);

    if (gpio_value == 0) {
        schedule_work(&g_intb_work);
    }

    /* if chip support fcp ,register fcp adapter ops */
    if( 0 == is_support_fcp() && 0 ==fcp_adapter_ops_register(&fcp_fsa9688_ops))
    {
        hwlog_info(" fcp adapter ops register success!\n");
    }
#ifdef CONFIG_HUAWEI_CHARGER
    if(0 == charge_switch_ops_register(&chrg_fsa9685_ops))
    {
        hwlog_info(" charge switch ops register success!\n");
    }
#endif
#ifdef CONFIG_DIRECT_CHARGER
    /* if chip support scp ,register scp adapter ops */
    if( 0 == fsa9685_is_support_scp() && 0 ==scp_ops_register(&scp_fsa9685_ops))
    {
        hwlog_info(" scp adapter ops register success!\n");
    }
#endif

#ifdef CONFIG_HUAWEI_HW_DEV_DCT
    /* detect current device successful, set the flag as present */
    set_hw_dev_flag(DEV_I2C_USB_SWITCH);
#endif

    ret = switch_extra_ops_register(&huawei_switch_extra_ops);
    if (ret) {
    	hwlog_err("register extra switch ops failed!\n");
    }
	
    hwlog_info("%s: ------end. ret = %d.\n", __func__, ret);
    return ret;

err_gpio_direction_input:
    gpio_free(gpio);
err_create_link_failed:
    device_remove_file(&client->dev, &dev_attr_fcp_mmi);
err_create_fcp_mmi_failed:
    device_remove_file(&client->dev, &dev_attr_jigpin_ctrl);
err_create_jigpin_ctrl_failed:
    device_remove_file(&client->dev, &dev_attr_switchctrl);
err_get_named_gpio:
    device_remove_file(&client->dev, &dev_attr_dump_regs);
err_i2c_check_functionality:
    this_client = NULL;

    hwlog_err("%s: ------FAIL!!! end. ret = %d.\n", __func__, ret);
    return ret;
}

static int fsa9685_remove(struct i2c_client *client)
{
    device_remove_file(&client->dev, &dev_attr_dump_regs);
    device_remove_file(&client->dev, &dev_attr_switchctrl);
    device_remove_file(&client->dev, &dev_attr_jigpin_ctrl);
    free_irq(client->irq, client);
    gpio_free(gpio);
    return 0;
}

static const struct i2c_device_id fsa9685_i2c_id[] = {
    { "fsa9685", 0 },
    { }
};

static struct i2c_driver fsa9685_i2c_driver = {
    .driver = {
        .name = "fsa9685",
        .owner = THIS_MODULE,
        .of_match_table = of_match_ptr(switch_fsa9685_ids),
    },
    .probe    = fsa9685_probe,
    .remove   = fsa9685_remove,
    .id_table = fsa9685_i2c_id,
};

static __init int fsa9685_i2c_init(void)
{
    int ret = 0;
    hwlog_info("%s: ------entry.\n", __func__);
    ret = i2c_add_driver(&fsa9685_i2c_driver);
    if(ret)
        hwlog_err("%s: i2c_add_driver error!!!\n", __func__);

    hwlog_info("%s: ------end.\n", __func__);
    return ret;
}

static __exit void fsa9685_i2c_exit(void)
{
    i2c_del_driver(&fsa9685_i2c_driver);
}

module_init(fsa9685_i2c_init);
module_exit(fsa9685_i2c_exit);

MODULE_AUTHOR("Lixiuna<lixiuna@huawei.com>");
MODULE_DESCRIPTION("I2C bus driver for FSA9685 USB Accesory Detection Switch");
MODULE_LICENSE("GPL v2");
