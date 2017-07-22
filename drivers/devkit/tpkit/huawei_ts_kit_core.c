/*
 * Huawei Touchscreen Driver
 *
 * Copyright (C) 2013 Huawei Device Co.Ltd
 * License terms: GNU General Public License (GPL) version 2
 *
 */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/ctype.h>
#include <linux/delay.h>
#include <linux/input/mt.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/debugfs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/regulator/consumer.h>
#include <linux/string.h>
#include <linux/of_gpio.h>
#include <linux/kthread.h>
#include <linux/uaccess.h>
#include <linux/sched/rt.h>
#include <linux/fb.h>
#include <linux/workqueue.h>
#if defined(CONFIG_FB)
#include <linux/notifier.h>
#include <linux/fb.h>
#elif defined(CONFIG_HAS_EARLYSUSPEND)
#include <linux/earlysuspend.h>
#endif
#include <huawei_ts_kit.h>
//#ifdef CONFIG_HUAWEI_HW_DEV_DCT
//#include <huawei_platform/devdetect/hw_dev_dec.h>
//#endif
//#include <linux/mfd/hisi_hi6xxx_pmic.h>
//#include <linux/hisi/hi6xxx-lcd_type.h>
#include <tpkit_platform_adapter.h>
#include <huawei_ts_kit_api.h>
#include <huawei_ts_kit_algo.h>
#if defined (CONFIG_TEE_TUI)
#include "tui.h"
#endif
#if defined (CONFIG_HUAWEI_DSM)
#include <dsm/dsm_pub.h>

#define LDO17_PHYS_ADDR		(0X93)
#define LSW50_PHYS_ADDR	(0xAC)



static struct dsm_dev dsm_tp = {
	.name = "dsm_tp",
	.device_name = "TP",
	.ic_name = "syn",	/*just for testing, waiting for the module owner revised*/
	.module_name = "NNN",
	.fops = NULL,
	.buff_size = 1024,
};

struct dsm_client *ts_dclient =NULL;
static unsigned char LDO17_status;
static unsigned char LSW50_status;
static bool chip_detfail_dsm;
#endif
#define	EDGE_WIDTH_DEFAULT	10
struct ts_kit_platform_data g_ts_kit_platform_data;
u8 g_ts_kit_log_cfg = 0;

static struct ts_cmd_node ping_cmd_buff;
static struct ts_cmd_node pang_cmd_buff;
static struct work_struct tp_init_work;
static int ts_gpio_num = 0;
struct mutex  ts_kit_easy_wake_guesure_lock;
/*external variable declare*/
extern const struct attribute_group ts_attr_group;
extern atomic_t g_ts_kit_data_report_over;
//extern int (*get_tp_gpio_num)(void);
/*global variable declare*/
volatile int g_tskit_ic_type= HYBRID;  //this type means oncell incell tddi ... in order to decide the power policy between lcd & tp
volatile int g_tskit_pt_station_flag = 0;
volatile int  not_get_special_tp_node  =0;
volatile int g_ts_kit_lcd_brightness_info = 0;

int ts_kit_get_esd_status(void)
{
	int ret = 0;

	ret = atomic_read(&g_ts_kit_platform_data.ts_esd_state);

	return ret;
}
EXPORT_SYMBOL(ts_kit_get_esd_status);

void ts_kit_clear_esd_status(void)
{
	atomic_set(&g_ts_kit_platform_data.ts_esd_state, TS_NO_ESD);
}
EXPORT_SYMBOL(ts_kit_clear_esd_status);
static void rawdata_timeout_proc_fn(struct work_struct *work);
static void tp_init_work_fn(struct work_struct *work);
int ts_kit_proc_command_directly(struct ts_cmd_node *cmd);
static int ts_get_brightness_info_cmd(void);

struct rawdata_timeout_info
{
    atomic_t idle_flag;
    struct ts_rawdata_info* info;
};
static struct delayed_work g_rawdata_proc_work;
static DECLARE_DELAYED_WORK(g_rawdata_proc_work, rawdata_timeout_proc_fn);
static struct rawdata_timeout_info g_rawdata_timeout_info =
{
    .idle_flag = ATOMIC_INIT(0),
    .info = NULL,
};

static void ts_touch_switch_cmd(void)
{
	struct ts_kit_device_data *dev
		= g_ts_kit_platform_data.chip_data;

	TS_LOG_DEBUG("+\n");
	if (dev
		&& dev->ops
		&& dev->ops->chip_touch_switch) {
		TS_LOG_INFO("chip set touch switch\n");
		dev->ops->chip_touch_switch();
	}
	TS_LOG_DEBUG("-\n");
	return ;
}

static void rawdata_timeout_proc_fn(struct work_struct *work)
{
	if (g_rawdata_timeout_info.info) {
		if ((g_rawdata_timeout_info.info)->status != TS_ACTION_UNDEF) {
			kfree(g_rawdata_timeout_info.info);
			g_rawdata_timeout_info.info = NULL;
			atomic_set(&(g_rawdata_timeout_info.idle_flag), TS_RAWDATA_IDLE);
			TS_LOG_INFO("Rawdata reading is ready\n");
		} else {
			TS_LOG_INFO("Rawdata reading is not ready\n");
			schedule_delayed_work(&g_rawdata_proc_work, msecs_to_jiffies(200));
		}
	}
}
static int seq_print_freq(struct seq_file *m, char *buf, int tx_num, int rx_num)
{
	char ii, jj;
	unsigned char *head;
	unsigned char *report_data_8;

	head = (unsigned char*)buf;

	seq_printf(m, "Calibration Image - Coarse & Fine\n");
	report_data_8 = (unsigned char*)buf;
	report_data_8++;	//point to second byte of F54 report data
	for (ii = 0; ii < rx_num; ii++)
	{
		for (jj = 0; jj < tx_num; jj++)
		{
			seq_printf(m, "%02x ", *report_data_8);

			report_data_8 +=2;

		}
		seq_printf(m, "\n");
	}

	seq_printf(m, "\nCalibration Image - Detail\n");
	report_data_8 = head;
	for (ii = 0; ii < rx_num; ii++)
	{
		for (jj = 0; jj < tx_num; jj++)
		{
			seq_printf(m, "%02x ", *report_data_8);

			report_data_8 +=2;

		}
		seq_printf(m, "\n");
	}

	seq_printf(m, "\nCalibration Noise - Coarse & Fine\n");
	report_data_8 = (unsigned char*)buf;	//point to first byte of data
	report_data_8 += (tx_num * rx_num *2 + 1);
	for (ii = 0; ii < rx_num * 2 ; ii++)
	{
		seq_printf(m, "%02x ", *report_data_8);
		report_data_8 +=2;

		if ((ii+1) % tx_num == 0 )
			seq_printf(m, "\n");
	}

	seq_printf(m, "\nCalibration Noise - Detail\n");
	report_data_8 = buf;
	report_data_8 += (tx_num * rx_num *2);
	for (ii = 0; ii < rx_num * 2; ii++)
	{
		seq_printf(m, "%02x ", *report_data_8);
		report_data_8 +=2;

		if ((ii+1) % tx_num == 0 )
			seq_printf(m, "\n");
	}

	seq_printf(m, "\nCalibration button - Coarse & Fine\n");
	report_data_8 = (unsigned char*)buf;
	report_data_8 += (tx_num * rx_num *2 + rx_num *4 + 1);
	for (ii = 0; ii < 4; ii++)
	{
		seq_printf(m, "%02x ", *report_data_8);
		report_data_8 +=2;
	}

	seq_printf(m, "\nCalibration button - Detail\n");
	report_data_8 = (unsigned char*)buf;
	report_data_8 += (tx_num * rx_num *2 + rx_num *4);
	for (ii = 0; ii < 4; ii++)
	{
		seq_printf(m, "%02x ", *report_data_8);
		report_data_8 +=2;
	}

	return 0;
}

static int calibration_proc_show(struct seq_file *m, void *v)
{
	struct ts_calibration_data_info *info = NULL;
	struct ts_cmd_node *cmd = NULL;
	int error = NO_ERR;

	if (!g_ts_kit_platform_data.chip_data->should_check_tp_calibration_info) {
		TS_LOG_ERR("No calibration data.\n");
		error = NO_ERR;
		goto out;
	}

	info = (struct ts_calibration_data_info *)kzalloc(sizeof(struct
				ts_calibration_data_info), GFP_KERNEL);
	if (!info) {
		TS_LOG_ERR("malloc failed\n");
		error = -ENOMEM;
		goto out;
	}

	cmd = (struct ts_cmd_node *)kzalloc(sizeof(struct ts_cmd_node), GFP_KERNEL);
	if (!cmd) {
		TS_LOG_ERR("malloc failed\n");
		error = -ENOMEM;
		goto out_free_info;
	}

	cmd->command = TS_READ_CALIBRATION_DATA;
	cmd->cmd_param.prv_params = (void *)info;

	if( g_ts_kit_platform_data.chip_data->is_direct_proc_cmd) {
		error = ts_kit_proc_command_directly(cmd);
	}else{
		error = ts_kit_put_one_cmd(cmd, SHORT_SYNC_TIMEOUT);
	}
	if (error) {
		TS_LOG_ERR("put cmd error :%d\n", error);
		error = -EBUSY;
		goto out_free_cmd;
	}

	seq_write(m, info->data, info->used_size);

	seq_printf(m, "\n\nCollect data for freq: 0\n\n");
	seq_print_freq(m, info->data, info->tx_num, info->rx_num);

	seq_printf(m, "\n\nCollect data for freq: 1\n\n");
	seq_print_freq(m,
			info->data
			+ info->tx_num * info->rx_num * 2	/* shift 2D */
			+ info->rx_num * 2 * 2	/* shift noise */
			+ 4 * 2,		/* shift 0D */
			info->tx_num, info->rx_num);

	seq_printf(m, "\n\nCollect data for freq: 2\n\n");
	seq_print_freq(m,
			info->data
			+ (info->tx_num * info->rx_num * 2	/* shift 2D */
			+ info->rx_num * 2 * 2	/* shift noise */
			+ 4 * 2) * 2,		/* shift 0D */
			info->tx_num, info->rx_num);

	seq_printf(m, "\n\nCollect data for interval scan\n\n");
	seq_print_freq(m, info->data+2048, info->tx_num, info->rx_num);

out_free_cmd:
	kfree(cmd);
out_free_info:
	kfree(info);
out:
	return 0;
}

void ts_kit_rotate_rawdata_abcd2cbad(int row, int column, int *data_start, int rotate_type)
{
	int *rawdatabuf_temp = NULL;
	int row_index, column_index;
	int row_size = 0;
	int column_size = 0;
	int i = 0;

	TS_LOG_INFO("\n");
	rawdatabuf_temp =
	    (int *)kzalloc(row * column * sizeof(int), GFP_KERNEL);
	if (!rawdatabuf_temp) {
		TS_LOG_ERR("Failed to alloc buffer for rawdatabuf_temp\n");
		return;
	}

	memcpy(rawdatabuf_temp, data_start, row * column * sizeof(int));
	switch (rotate_type) {
		case TS_RAWDATA_TRANS_NONE:
			break;
		case TS_RAWDATA_TRANS_ABCD2CBAD:
			/* src column to dst row*/
			row_size = column;
			column_size = row;
			for (column_index = column_size - 1; column_index >= 0; column_index--) {
				for (row_index = row_size - 1; row_index >= 0; row_index--) {
					data_start[i++] =
					    rawdatabuf_temp[row_index * column_size + column_index];
				}
			}
			break;
		case TS_RAWDATA_TRANS_ABCD2ADCB:
			/* src column to dst row*/
			row_size = column;
			column_size = row;
			for (column_index = 0; column_index < column_size; column_index++) {
				for (row_index = 0; row_index < row_size; row_index++) {
					data_start[i++] =
					    rawdatabuf_temp[row_index * column_size +
							    column_index];
				}
			}
			break;
		default:
			break;
	}
	if (rawdatabuf_temp) {
		kfree(rawdatabuf_temp);
		rawdatabuf_temp = NULL;
	}
	return;
}

static int rawdata_proc_show(struct seq_file *m, void *v)
{
	int index;
	int index1;
	int rdIndex;
	short row_size = 0;
	int range_size = 0;
	int error = NO_ERR;
	struct ts_cmd_node *cmd = NULL;
	struct ts_rawdata_info *info = NULL;

	TS_LOG_INFO("rawdata_proc_show, buffer size = %ld\n", m->size);
	if(m->size <= RAW_DATA_SIZE) {
		m->count = m->size;
		return 0;
	}

	if (atomic_read(&(g_rawdata_timeout_info.idle_flag)) == TS_RAWDATA_WORK) {
		TS_LOG_INFO("rawdata work busy\n");
		return -EBUSY;
	}
	cmd = (struct ts_cmd_node *)kzalloc(sizeof(struct ts_cmd_node), GFP_KERNEL);
	if (!cmd) {
		TS_LOG_ERR("malloc failed\n");
		error = -ENOMEM;
		goto out;
	}

	info = (struct ts_rawdata_info *)kzalloc(sizeof(struct ts_rawdata_info), GFP_KERNEL);
	if (!info) {
		TS_LOG_ERR("malloc failed\n");
		error = -ENOMEM;
		goto out;
	}

	info->used_size = 0;
	info->used_sharp_selcap_single_ended_delta_size = 0;
	info->used_sharp_selcap_touch_delta_size = 0;
	info->status = TS_ACTION_UNDEF;
	cmd->command = TS_READ_RAW_DATA;
	cmd->cmd_param.prv_params = (void *)info;

	if(g_ts_kit_platform_data.chip_data->is_direct_proc_cmd){
		error = ts_kit_proc_command_directly(cmd);
	}
	else{
		if (g_ts_kit_platform_data.chip_data->rawdata_get_timeout)
			error = ts_kit_put_one_cmd(cmd, g_ts_kit_platform_data.chip_data->rawdata_get_timeout);
		else
			error = ts_kit_put_one_cmd(cmd, SHORT_SYNC_TIMEOUT);
	}
	if (error) {
		TS_LOG_ERR("put cmd error :%d\n", error);
		if (error == -EBUSY) {
			g_rawdata_timeout_info.info = info;
			atomic_set(&(g_rawdata_timeout_info.idle_flag), TS_RAWDATA_WORK);
			schedule_delayed_work(&g_rawdata_proc_work, msecs_to_jiffies(200));
		}
		error = -EBUSY;
		goto out;
	}

	if (info->status != TS_ACTION_SUCCESS) {
		TS_LOG_ERR("read action failed\n");
		error = -EIO;
		goto out;
	}
	seq_printf(m, "%s\n", info->result);
	seq_printf(m, "*************touch data*************\n");

	if (g_ts_kit_platform_data.chip_data->rawdata_arrange_swap) {
		row_size = info->buff[1];
		range_size = info->buff[0];
	}else{
		row_size = info->buff[0];
		range_size = info->buff[1];
	}

	if (g_ts_kit_platform_data.chip_data->rawdata_arrange_type == TS_RAWDATA_TRANS_ABCD2CBAD
		|| g_ts_kit_platform_data.chip_data->rawdata_arrange_type == TS_RAWDATA_TRANS_ABCD2ADCB) {
		ts_kit_rotate_rawdata_abcd2cbad(row_size, range_size, info->buff + 2,
				g_ts_kit_platform_data.chip_data->rawdata_arrange_type);
		ts_kit_rotate_rawdata_abcd2cbad(row_size, range_size,
				info->buff + 2 + row_size * range_size, g_ts_kit_platform_data.chip_data->rawdata_arrange_type);
		row_size = info->buff[1];
		range_size = info->buff[0];
	}
	seq_printf(m, "rx: %d, tx : %d\n", row_size, range_size);
	if(g_ts_kit_platform_data.chip_data->is_parade_solution == 0){//Not Parade Solution, use default
		for (index = 0; row_size * index + 2 < info->used_size; index++) {
			if (0 == index) {
				seq_printf(m, "rawdata begin\n");	/*print the title */
			}
			for (index1 = 0; index1 < row_size; index1++) {
				seq_printf(m, "%d,", info->buff[2 + row_size * index + index1]);	/*print oneline */
			}
			/*index1 = 0;*/
			seq_printf(m, "\n ");

			if ((range_size - 1) == index) {
				seq_printf(m, "rawdata end\n");
				seq_printf(m, "noisedata begin\n");
			}
		}
		seq_printf(m, "noisedata end\n");
		if(info->used_sharp_selcap_single_ended_delta_size) {
			seq_printf(m, "selfcap touchdelta begin\n");
			for (index = 0; index < info->used_sharp_selcap_touch_delta_size; index++) {
				seq_printf(m, "%d,", info->buff[info->used_size + index]);
			}
			seq_printf(m, "\n ");
			seq_printf(m, "selfcap touchdelta end\n");
			seq_printf(m, "selfcap singleenddelta begin\n");
			for (index = 0; index < info->used_sharp_selcap_single_ended_delta_size; index++) {
				seq_printf(m, "%d,", info->buff[info->used_size +
						info->used_sharp_selcap_touch_delta_size + index]);
			}
			seq_printf(m, "\n ");
			seq_printf(m, "selfcap singleenddelta end\n");
		}
	} else {
		rdIndex = 2;
		seq_printf(m, "cm data begin\n");	/*print the title */
		for(index = 0; index < range_size; index++){
			for (index1 = 0; index1 < row_size; index1++){
				if(rdIndex < info->used_size)
					seq_printf(m, "%d,", info->buff[rdIndex++]);
				else{
					seq_printf(m, "\n ");
					goto out;
				}
			}
			seq_printf(m, "\n ");
		}
		seq_printf(m, "cm data end\n");	/*print the title */
		seq_printf(m, "mutual noise data begin\n");	/*print the title */
		for(index = 0; index < range_size; index++){
			for (index1 = 0; index1 < row_size; index1++){
				if(rdIndex < info->used_size)
					seq_printf(m, "%d,", info->buff[rdIndex++]);
				else{
					seq_printf(m, "\n ");
					goto out;
				}
			}
			seq_printf(m, "\n ");
		}
		seq_printf(m, "mutual noise data end\n");	/*print the title */
		seq_printf(m, "self noise data begin\n");	/*print the title */
		seq_printf(m, "-rx:,");
		for (index1 = 0; index1 < row_size; index1++){
			if(rdIndex < info->used_size)
				seq_printf(m, "%d,", info->buff[rdIndex++]);
			else{
				seq_printf(m, "\n ");
				goto out;
			}
		}
		seq_printf(m, "\n ");
		seq_printf(m, "-tx:,");
		for (index1 = 0; index1 < range_size; index1++){
			if(rdIndex < info->used_size)
				seq_printf(m, "%d,", info->buff[rdIndex++]);
			else{
				seq_printf(m, "\n ");
				goto out;
			}
		}
		seq_printf(m, "\n ");
		seq_printf(m, "self noise data end\n");	/*print the title */
		seq_printf(m, "cm gradient(10x real value) begin\n");	/*print the title */
		seq_printf(m, "-rx:,");
		for (index1 = 0; index1 < row_size; index1++){
			if(rdIndex < info->used_size)
				seq_printf(m, "%d,", info->buff[rdIndex++]);
			else{
				seq_printf(m, "\n ");
				goto out;
			}
		}
		seq_printf(m, "\n ");
		seq_printf(m, "-tx:,");
		for (index1 = 0; index1 < range_size; index1++){
			if(rdIndex < info->used_size)
				seq_printf(m, "%d,", info->buff[rdIndex++]);
			else{
				seq_printf(m, "\n ");
				goto out;
			}
		}
		seq_printf(m, "\n ");
		seq_printf(m, "cm gradient end\n");	/*print the title */
		seq_printf(m, "cp begin\n");	/*print the title */
		seq_printf(m, "-rx:,");
		for (index1 = 0; index1 < row_size; index1++){
			if(rdIndex < info->used_size)
				seq_printf(m, "%d,", info->buff[rdIndex++]);
			else{
				seq_printf(m, "\n ");
				goto out;
			}
		}
		seq_printf(m, "\n ");
		seq_printf(m, "-tx:,");
		for (index1 = 0; index1 < range_size; index1++){
			if(rdIndex < info->used_size)
				seq_printf(m, "%d,", info->buff[rdIndex++]);
			else{
				seq_printf(m, "\n ");
				goto out;
			}
		}
		seq_printf(m, "\n ");
		seq_printf(m, "cp end\n");	/*print the title */
		seq_printf(m, "cp delta begin\n");	/*print the title */
		seq_printf(m, "-rx:,");
		for (index1 = 0; index1 < row_size; index1++){
			if(rdIndex < info->used_size)
				seq_printf(m, "%d,", info->buff[rdIndex++]);
			else{
				seq_printf(m, "\n ");
				goto out;
			}
		}
		seq_printf(m, "\n ");
		seq_printf(m, "-tx:,");
		for (index1 = 0; index1 < range_size; index1++){
			if(rdIndex < info->used_size)
				seq_printf(m, "%d,", info->buff[rdIndex++]);
			else{
				seq_printf(m, "\n ");
				goto out;
			}
		}
		seq_printf(m, "\n ");
		seq_printf(m, "cp detlat end\n");	/*print the title */
OUT:
		seq_printf(m, "*************end data*************\n");
	}

	if(g_ts_kit_platform_data.chip_data->support_3d_func) {
		TS_LOG_INFO("print 3d data\n");
		row_size = info->buff_3d[0];
		range_size = info->buff_3d[1];
		seq_printf(m, "rx: %d, tx : %d(3d)\n", row_size, range_size);

		for (index=0; row_size*index+2 < info->used_size_3d; index++) {
			if (0 == index) {
				seq_printf(m, "rawdata begin(3d)\n");							/*print the title*/
			}
			for (index1=0; index1 < row_size; index1++) {
				seq_printf(m, "%d,", info->buff_3d[2+row_size*index+index1]);		/*print oneline*/
			}
			//index1 = 0;
			seq_printf(m, "\n ");

			if ((range_size -1) == index) {
				seq_printf(m, "rawdata end(3d)\n");
				seq_printf(m, "noisedata begin(3d)\n");
			}
		}
		seq_printf(m, "noisedata end(3d)\n");
	}

	error = NO_ERR;

out:

	if (!(atomic_read(&(g_rawdata_timeout_info.idle_flag)) == TS_RAWDATA_WORK)) {
		TS_LOG_INFO("rawdata_proc_show done:status=%d, result: %s\n", error, info->result);
		if (info) {
			kfree(info);
			info = NULL;
			g_rawdata_timeout_info.info = NULL;
		}
	} else {
		TS_LOG_ERR("rawdata_proc_show done:status=%d, timeout error!\n", error);
	}
	if (cmd) {
		kfree(cmd);
		cmd = NULL;
	}

	return error;
}
static int calibration_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, calibration_proc_show, NULL);
}

static const struct file_operations calibration_proc_fops = {
	.open		= calibration_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};
static int rawdata_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, rawdata_proc_show, NULL);
}
static const struct file_operations rawdata_proc_fops =
{
    .open     = rawdata_proc_open,
    .read     = seq_read,
    .llseek       = seq_lseek,
    .release  = single_release,
};
/*external function declare*/
extern int i2c_check_addr_busy(struct i2c_adapter* adapter, int addr);

#if defined (CONFIG_TEE_TUI)
extern int i2c_init_secos(struct i2c_adapter *adap);
extern int i2c_exit_secos(struct i2c_adapter *adap);
#endif

void ts_stop_wd_timer(struct ts_kit_platform_data* cd);
void ts_kit_thread_stop_notify(void);

int ts_i2c_write(u8* buf, u16 length);
int ts_spi_write(u8* buf, u16 length);
int ts_i2c_read(u8* reg_addr, u16 reg_len, u8* buf, u16 len);
int ts_spi_read(u8* reg_addr, u16 reg_len, u8* buf, u16 len);



static struct ts_bus_info ts_bus_i2c_info =
{
    .btype      = TS_BUS_I2C,
    .bus_write  = ts_i2c_write,
    .bus_read   = ts_i2c_read,
};

static struct ts_bus_info ts_bus_spi_info =
{
    .btype      = TS_BUS_SPI,
    .bus_write  = ts_spi_write,
    .bus_read   = ts_spi_read,
};
int ts_i2c_write(u8* buf, u16 length)
{
    int count = 0;
    int ret;

#if defined (CONFIG_TEE_TUI)
	if (g_ts_kit_platform_data.chip_data->report_tui_enable) {
		return NO_ERR;
	}
#endif
    do
    {
        ret = i2c_master_send(g_ts_kit_platform_data.client, buf, length);
        if (ret == length)
        {
            return NO_ERR;
        }
#if defined (CONFIG_HUAWEI_DSM)
	else
		g_ts_kit_platform_data.dsm_info.constraints_I2C_status = ret;
#endif
        msleep(I2C_WAIT_TIME);
    }
    while (++count < I2C_RW_TRIES);
#if defined (CONFIG_HUAWEI_DSM)
	if (!chip_detfail_dsm) {
		TS_LOG_ERR("chip write init no need dsm \n");
		return -EIO;
	}
	LDO17_status = 0;	/*hi6xxx_pmic_reg_read(LDO17_PHYS_ADDR);*/
	LSW50_status = 0;	/*hi6xxx_pmic_reg_read(LSW50_PHYS_ADDR);*/
	if (!dsm_client_ocuppy(ts_dclient)) {
		dsm_client_record(ts_dclient, "irq_gpio:%d\tvalue:%d.\n\
                      reset_gpio:%d\t value:%d.\nLDO17_status is 0x%x.\nLSW50_status is 0x%x\nI2C_status:%d.\n",\
                      g_ts_kit_platform_data.irq_gpio, gpio_get_value(g_ts_kit_platform_data.irq_gpio), \
                      g_ts_kit_platform_data.reset_gpio, gpio_get_value(g_ts_kit_platform_data.reset_gpio), \
                      LDO17_status, LSW50_status, g_ts_kit_platform_data.dsm_info.constraints_I2C_status);
		dsm_client_notify(ts_dclient, DSM_TP_I2C_RW_ERROR_NO);
	}
#endif

    TS_LOG_ERR("ts_i2c_write failed\n");
    return -EIO;
}

int ts_spi_write(u8* buf, u16 length)
{
    return NO_ERR;
}

int ts_i2c_read(u8* reg_addr, u16 reg_len, u8* buf, u16 len)
{
    int count = 0;
    int ret;
    int msg_len;
    struct i2c_msg *msg_addr = NULL;
    struct i2c_msg xfer[2];

#if defined (CONFIG_TEE_TUI)
	if (g_ts_kit_platform_data.chip_data->report_tui_enable) {
		return NO_ERR;
	}
#endif
	if (g_ts_kit_platform_data.chip_data->is_i2c_one_byte) {
		/* Read data */
		xfer[0].addr = g_ts_kit_platform_data.client->addr;
		xfer[0].flags = I2C_M_RD;
		xfer[0].len = len;
		xfer[0].buf = buf;
		do {
			ret = i2c_transfer(g_ts_kit_platform_data.client->adapter, xfer, 1);
			if (ret == 1) {
				return NO_ERR;
			}
#if defined (CONFIG_HUAWEI_DSM)
			else
				g_ts_kit_platform_data.dsm_info.constraints_I2C_status = ret;
#endif

			msleep(I2C_WAIT_TIME);
		} while (++count < I2C_RW_TRIES);
	} else {
    /*register addr*/
    xfer[0].addr = g_ts_kit_platform_data.client->addr;
    xfer[0].flags = 0;
    xfer[0].len = reg_len;
    xfer[0].buf = reg_addr;

    /* Read data */
    xfer[1].addr = g_ts_kit_platform_data.client->addr;
    xfer[1].flags = I2C_M_RD;
    xfer[1].len = len;
    xfer[1].buf = buf;

    if (reg_len > 0) {
    	msg_len = 2;
    	msg_addr = &xfer[0];
    } else {
    	msg_len = 1;
    	msg_addr = &xfer[1];
    }
    do
    {
        ret = i2c_transfer(g_ts_kit_platform_data.client->adapter, msg_addr, msg_len);
        if (ret == msg_len)
        {
            return NO_ERR;
        }
#if defined (CONFIG_HUAWEI_DSM)
	else
		g_ts_kit_platform_data.dsm_info.constraints_I2C_status = ret;
#endif
			msleep(I2C_WAIT_TIME);
		} while (++count < I2C_RW_TRIES);
    }

#if defined (CONFIG_HUAWEI_DSM)
	if (!chip_detfail_dsm) {
		TS_LOG_ERR("chip read init no need dsm \n");
		return -EIO;
	}
	LDO17_status = 0;	/*hi6xxx_pmic_reg_read(LDO17_PHYS_ADDR);*/
	LSW50_status = 0;	/*hi6xxx_pmic_reg_read(LSW50_PHYS_ADDR);*/
	if (!dsm_client_ocuppy(ts_dclient)) {
		dsm_client_record(ts_dclient, "irq_gpio:%d\tvalue:%d.\nreset_gpio:%d\t value:%d.\nLDO17_status is 0x%x.\nLSW50_status is 0x%x\nI2C_status:%d.\n", \
                      g_ts_kit_platform_data.irq_gpio, gpio_get_value(g_ts_kit_platform_data.irq_gpio),\
                      g_ts_kit_platform_data.reset_gpio, gpio_get_value(g_ts_kit_platform_data.reset_gpio), \
                     LDO17_status, LSW50_status, g_ts_kit_platform_data.dsm_info.constraints_I2C_status);
		dsm_client_notify(ts_dclient, DSM_TP_I2C_RW_ERROR_NO);
	}
#endif
    TS_LOG_ERR("ts_i2c_read failed\n");
    return -EIO;
}

int ts_spi_read(u8* reg_addr, u16 reg_len, u8* buf, u16 len)
{
    return NO_ERR;
}
static irqreturn_t ts_irq_handler(int irq, void* dev_id)
{
    int error = NO_ERR;
    struct ts_cmd_node cmd;

    wake_lock_timeout(&g_ts_kit_platform_data.ts_wake_lock, HZ);

    if (g_ts_kit_platform_data.chip_data->ops->chip_irq_top_half)
    { error = g_ts_kit_platform_data.chip_data->ops->chip_irq_top_half(&cmd); }

    if (error)//unexpected error happen, put err cmd to ts thread
    { cmd.command = TS_INT_ERR_OCCUR; }
    else
    { cmd.command = TS_INT_PROCESS; }

    disable_irq_nosync(g_ts_kit_platform_data.irq_id);

    if (ts_kit_put_one_cmd(&cmd, NO_SYNC_TIMEOUT) && (TS_UNINIT != atomic_read(&g_ts_kit_platform_data.state)))
    { enable_irq(g_ts_kit_platform_data.irq_id); }

    return IRQ_HANDLED;
}
#if defined (CONFIG_TEE_TUI)
void ts_kit_tui_secos_init(void)
{
	unsigned char ts_state = 0;
	int times = 0;

	while (times < TS_FB_LOOP_COUNTS) {
		ts_state = atomic_read(&g_ts_kit_platform_data.state);
		if ((TS_SLEEP == ts_state) || (TS_WORK_IN_SLEEP == ts_state)) {
			mdelay(TS_FB_WAIT_TIME);
			times++;
		} else {
			break;
		}
	}

	if (!g_ts_kit_platform_data.chip_data->report_tui_enable) {
		disable_irq(g_ts_kit_platform_data.irq_id);
		times = 0;
		while (times < TS_FB_LOOP_COUNTS) {
			if (!atomic_read(&g_ts_kit_data_report_over)) {
				mdelay(TS_FB_WAIT_TIME);
				times++;
			} else {
				break;
			}
		}
		i2c_init_secos(g_ts_kit_platform_data.client->adapter);
		g_ts_kit_platform_data.chip_data->report_tui_enable = true;
		TS_LOG_INFO("[tui] ts_kit_tui_secos_init: report_tui_enable is %d\n",
				g_ts_kit_platform_data.chip_data->report_tui_enable);
	}
}

void ts_kit_tui_secos_exit(void)
{
	struct ts_kit_device_data *dev = g_ts_kit_platform_data.chip_data;

	if (g_ts_kit_platform_data.chip_data->report_tui_enable) {
		i2c_exit_secos(g_ts_kit_platform_data.client->adapter);
		if (dev->ops->chip_reset)
			dev->ops->chip_reset();

		enable_irq(g_ts_kit_platform_data.irq_id);
		g_ts_kit_platform_data.chip_data->report_tui_enable = false;
		TS_LOG_INFO("ts_kit_tui_secos_exit: tui_set_flag is %d\n",
			    g_ts_kit_platform_data.chip_data->tui_set_flag);

		if (g_ts_kit_platform_data.chip_data->tui_set_flag & 0x1) {
			TS_LOG_INFO("TUI exit, do before suspend\n");
			ts_kit_power_control_notify(TS_BEFORE_SUSPEND,
						SHORT_SYNC_TIMEOUT);
		}

		if (g_ts_kit_platform_data.chip_data->tui_set_flag & 0x2) {
			TS_LOG_INFO("TUI exit, do suspend\n");
			ts_kit_power_control_notify(TS_SUSPEND_DEVICE,
						NO_SYNC_TIMEOUT);
		}

		g_ts_kit_platform_data.chip_data->tui_set_flag = 0;
		TS_LOG_INFO("ts_kit_tui_secos_exit: report_tui_enable is %d\n",
			    g_ts_kit_platform_data.chip_data->report_tui_enable);
	}
}

static int tui_tp_init(void *data, int secure)
{
	if (secure) {
		ts_kit_tui_secos_init();
	} else
		ts_kit_tui_secos_exit();
	return 0;
}

int ts_kit_tui_report_input(void *finger_data)
{
	int error = NO_ERR;
	struct ts_fingers *finger = (struct ts_fingers *)finger_data;
	struct input_dev *input_dev = g_ts_kit_platform_data.input_dev;
	int id;

	int finger_num = 0;
	TS_LOG_DEBUG("ts_tui_report_input\n");

	for (id = 0; id < TS_MAX_FINGER; id++) {

		if (finger->fingers[id].status == 0) {
			TS_LOG_DEBUG("never touch before: id is %d\n", id);
			continue;
		}

		if (finger->fingers[id].status == TS_FINGER_PRESS) {
			TS_LOG_DEBUG
			    ("down: id is %d, finger->fingers[id].pressure = %d, finger->fingers[id].x = %d, finger->fingers[id].y = %d\n",
			     id, finger->fingers[id].pressure,
			     finger->fingers[id].x, finger->fingers[id].y);
			finger_num++;

			input_report_abs(input_dev, ABS_MT_PRESSURE,
					 finger->fingers[id].pressure);
			input_report_abs(input_dev, ABS_MT_POSITION_X,
					 finger->fingers[id].x);
			input_report_abs(input_dev, ABS_MT_POSITION_Y,
					 finger->fingers[id].y);
			input_report_abs(input_dev, ABS_MT_TRACKING_ID, id);
			input_mt_sync(input_dev);

		} else if (finger->fingers[id].status == TS_FINGER_RELEASE) {
			TS_LOG_DEBUG("up: id is %d, status = %d\n", id,
				     finger->fingers[id].status);
			input_mt_sync(input_dev);
		}
	}

	input_report_key(input_dev, BTN_TOUCH, finger_num);
	input_sync(input_dev);

	return error;
}
#endif
//struct anti_false_touch_param *g_anti_false_touch_param = NULL;
void ts_kit_anti_false_touch_param_achieve(struct ts_kit_device_data *chip_data){
	int retval  = NO_ERR;
	unsigned int value = 0;
	struct anti_false_touch_param *local_param = NULL;
	struct device_node *root = g_ts_kit_platform_data.node;
	struct device_node *device = NULL;
	bool found = false;

	TS_LOG_INFO("%s +\n", __func__);
	if (NULL == chip_data){
		TS_LOG_ERR("%s anti false touch get chip data NULL\n", __func__);
		return ;
	}
	local_param = &(chip_data->anti_false_touch_param_data);
	//g_anti_false_touch_param = local_param;
	memset(local_param, 0, sizeof(struct anti_false_touch_param));

	TS_LOG_INFO("%s chip_name:%s\n", __func__, chip_data->chip_name);
	for_each_child_of_node(root, device) {	/*find the chip node*/
		if (of_device_is_compatible(device, chip_data->chip_name)) {
			found = true;
			break;
		}
	}

	if (false == found){
		TS_LOG_ERR("%s anti false touch find dts node fail\n", __func__);
		return ;
	}

	//feature_all
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_FEATURE_ALL, &value);
	if (retval) {
		local_param->feature_all = 0;
		TS_LOG_ERR("get device feature_all failed\n");
	}else{
		local_param->feature_all = value;
	}

	if (!local_param->feature_all){
		TS_LOG_INFO("product do not suppurt avert misoper, set all param to 0\n");
		return ;
	}

	//feature_resend_point
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_FEATURE_RESEND_POINT, &value);
	if (retval) {
		local_param->feature_resend_point = 0;
		TS_LOG_ERR("get device feature_resend_point failed\n");
	}else{
		local_param->feature_resend_point = value;
	}

	//feature_orit_support
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_FEATURE_ORIT_SUPPORT, &value);
	if (retval) {
		local_param->feature_orit_support = 0;
		TS_LOG_ERR("get device feature_orit_support failed\n");
	}else{
		local_param->feature_orit_support = value;
	}

	//feature_reback_bt
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_FEATURE_REBACK_BT, &value);
	if (retval) {
		local_param->feature_reback_bt = 0;
		TS_LOG_ERR("get device feature_reback_bt failed\n");
	}else{
		local_param->feature_reback_bt = value;
	}

	//lcd_width
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_LCD_WIDTH, &value);
	if (retval) {
		local_param->lcd_width = 0;
		TS_LOG_ERR("get device lcd_width failed\n");
	}else{
		local_param->lcd_width = value;
	}

	//lcd_height
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_LCD_HEIGHT, &value);
	if (retval) {
		local_param->lcd_height = 0;
		TS_LOG_ERR("get device lcd_height failed\n");
	}else{
		local_param->lcd_height = value;
	}

	//click_time_limit
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_CLICK_TIME_LIMIT, &value);
	if (retval) {
		local_param->click_time_limit = 0;
		TS_LOG_ERR("get device click_time_limit failed\n");
	}else{
		local_param->click_time_limit = value;
	}

	//click_time_bt
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_CLICK_TIME_BT, &value);
	if (retval) {
		local_param->click_time_bt = 0;
		TS_LOG_ERR("get device click_time_bt failed\n");
	}else{
		local_param->click_time_bt = value;
	}

	//edge_position
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_EDGE_POISION, &value);
	if (retval) {
		local_param->edge_position = 0;
		TS_LOG_ERR("get device edge_position failed\n");
	}else{
		local_param->edge_position = value;
	}

	//edge_postion_secondline
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_EDGE_POISION_SECONDLINE, &value);
	if (retval) {
		local_param->edge_postion_secondline = 0;
		TS_LOG_ERR("get device edge_postion_secondline failed\n");
	}else{
		local_param->edge_postion_secondline = value;
	}

	//bt_edge_x
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_BT_EDGE_X, &value);
	if (retval) {
		local_param->bt_edge_x = 0;
		TS_LOG_ERR("get device bt_edge_x failed\n");
	}else{
		local_param->bt_edge_x = value;
	}

	//bt_edge_y
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_BT_EDGE_Y, &value);
	if (retval) {
		local_param->bt_edge_y = 0;
		TS_LOG_ERR("get device bt_edge_y failed\n");
	}else{
		local_param->bt_edge_y = value;
	}

	//move_limit_x
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_MOVE_LIMIT_X, &value);
	if (retval) {
		local_param->move_limit_x = 0;
		TS_LOG_ERR("get device move_limit_x failed\n");
	}else{
		local_param->move_limit_x = value;
	}

	//move_limit_y
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_MOVE_LIMIT_Y, &value);
	if (retval) {
		local_param->move_limit_y = 0;
		TS_LOG_ERR("get device move_limit_y failed\n");
	}else{
		local_param->move_limit_y = value;
	}

	//move_limit_x_t
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_MOVE_LIMIT_X_T, &value);
	if (retval) {
		local_param->move_limit_x_t = 0;
		TS_LOG_ERR("get device move_limit_x_t failed\n");
	}else{
		local_param->move_limit_x_t = value;
	}

	//move_limit_y_t
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_MOVE_LIMIT_Y_T, &value);
	if (retval) {
		local_param->move_limit_y_t = 0;
		TS_LOG_ERR("get device move_limit_y_t failed\n");
	}else{
		local_param->move_limit_y_t = value;
	}

	//move_limit_x_bt
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_MOVE_LIMIT_X_BT, &value);
	if (retval) {
		local_param->move_limit_x_bt = 0;
		TS_LOG_ERR("get device move_limit_x_bt failed\n");
	}else{
		local_param->move_limit_x_bt = value;
	}

	//move_limit_y_bt
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_MOVE_LIMIT_Y_BT, &value);
	if (retval) {
		local_param->move_limit_y_bt = 0;
		TS_LOG_ERR("get device move_limit_y_bt failed\n");
	}else{
		local_param->move_limit_y_bt = value;
	}

	//edge_y_confirm_t
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_EDGE_Y_CONFIRM_T, &value);
	if (retval) {
		local_param->edge_y_confirm_t = 0;
		TS_LOG_ERR("get device edge_y_confirm_t failed\n");
	}else{
		local_param->edge_y_confirm_t = value;
	}

	//edge_y_dubious_t
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_EDGE_Y_DUBIOUS_T, &value);
	if (retval) {
		local_param->edge_y_dubious_t = 0;
		TS_LOG_ERR("get device edge_y_dubious_t failed\n");
	}else{
		local_param->edge_y_dubious_t = value;
	}

	//edge_y_avg_bt
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_EDGE_Y_AVG_BT, &value);
	if (retval) {
		local_param->edge_y_avg_bt = 0;
		TS_LOG_ERR("get device edge_y_avg_bt failed\n");
	}else{
		local_param->edge_y_avg_bt = value;
	}

	//edge_xy_down_bt
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_EDGE_XY_DOWN_BT, &value);
	if (retval) {
		local_param->edge_xy_down_bt = 0;
		TS_LOG_ERR("get device edge_xy_down_bt failed\n");
	}else{
		local_param->edge_xy_down_bt = value;
	}

	//edge_xy_confirm_t
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_EDGE_XY_CONFIRM_T, &value);
	if (retval) {
		local_param->edge_xy_confirm_t = 0;
		TS_LOG_ERR("get device edge_xy_confirm_t failed\n");
	}else{
		local_param->edge_xy_confirm_t = value;
	}

	//max_points_bak_num
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_MAX_POINTS_BAK_NUM, &value);
	if (retval) {
		local_param->max_points_bak_num = 0;
		TS_LOG_ERR("get device max_points_bak_num failed\n");
	}else{
		local_param->max_points_bak_num = value;
	}

	//drv_stop_width
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_DRV_STOP_WIDTH, &value);
	if (retval) {
		local_param->drv_stop_width = 0;
		TS_LOG_ERR("get device drv_stop_width failed\n");
	}else{
		local_param->drv_stop_width = value;
	}

	//sensor_x_width
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_SENSOR_X_WIDTH, &value);
	if (retval) {
		local_param->sensor_x_width = 0;
		TS_LOG_ERR("get device sensor_x_width failed\n");
	}else{
		local_param->sensor_x_width = value;
	}

	//sensor_y_width
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_SENSOR_Y_WIDTH, &value);
	if (retval) {
		local_param->sensor_y_width = 0;
		TS_LOG_ERR("get device sensor_y_width failed\n");
	}else{
		local_param->sensor_y_width = value;
	}
	/* emui5.1 support */
	//feature_sg
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_FEATURE_SG, &value);
	if (retval) {
		local_param->feature_sg = 0;
		TS_LOG_ERR("get device feature_sg failed\n");
	}else{
		local_param->feature_sg = value;
	}

	//sg_min_value
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_SG_MIN_VALUE, &value);
	if (retval) {
		local_param->sg_min_value = 0;
		TS_LOG_ERR("get device sg_min_value failed\n");
	}else{
		local_param->sg_min_value = value;
	}

	//feature_support_list
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_FEATURE_SUPPORT_LIST, &value);
	if (retval) {
		local_param->feature_support_list = 0;
		TS_LOG_ERR("get device feature_support_list failed\n");
	}else{
		local_param->feature_support_list = value;
	}

	//max_distance_dt
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_MAX_DISTANCE_DT, &value);
	if (retval) {
		local_param->max_distance_dt = 0;
		TS_LOG_ERR("get device max_distance_dt failed\n");
	}else{
		local_param->max_distance_dt = value;
	}

	//feature_big_data
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_FEATURE_BIG_DATA, &value);
	if (retval) {
		local_param->feature_big_data = 0;
		TS_LOG_ERR("get device feature_big_data failed\n");
	}else{
		local_param->feature_big_data = value;
	}

	//feature_click_inhibition
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_FEATURE_CLICK_INHIBITION, &value);
	if (retval) {
		local_param->feature_click_inhibition = 0;
		TS_LOG_ERR("get device feature_click_inhibition failed\n");
	}else{
		local_param->feature_click_inhibition = value;
	}

	//min_click_time
	retval = of_property_read_u32(device, ANTI_FALSE_TOUCH_MIN_CLICK_TIME, &value);
	if (retval) {
		local_param->min_click_time = 0;
		TS_LOG_ERR("get device min_click_time failed\n");
	}else{
		local_param->min_click_time = value;
	}
	TS_LOG_INFO("%s:"
		" feature_all:%d, feature_resend_point:%d, feature_orit_support:%d, feature_reback_bt:%d, lcd_width:%d, lcd_height:%d,"
		" click_time_limit:%d, click_time_bt:%d, edge_position:%d, edge_postion_secondline:%d, bt_edge_x:%d, bt_edge_y:%d,"
		" move_limit_x:%d, move_limit_y:%d, move_limit_x_t:%d, move_limit_y_t:%d, move_limit_x_bt:%d,"
		" move_limit_y_bt:%d, edge_y_confirm_t:%d, edge_y_dubious_t:%d, edge_y_avg_bt:%d, edge_xy_down_bt:%d, edge_xy_confirm_t:%d, max_points_bak_num:%d,"
		" drv_stop_width:%d sensor_x_width:%d, sensor_y_width:%d,"
		" feature_sg:%d, sg_min_value:%d, feature_support_list:%d, max_distance_dt:%d, feature_big_data:%d, feature_click_inhibition:%d, min_click_time:%d\n",
		__func__,
		local_param->feature_all,
		local_param->feature_resend_point,
		local_param->feature_orit_support,
		local_param->feature_reback_bt,
		local_param->lcd_width,
		local_param->lcd_height,

		local_param->click_time_limit,
		local_param->click_time_bt,
		local_param->edge_position,
		local_param->edge_postion_secondline,
		local_param->bt_edge_x,
		local_param->bt_edge_y,

		local_param->move_limit_x,
		local_param->move_limit_y,
		local_param->move_limit_x_t,
		local_param->move_limit_y_t,
		local_param->move_limit_x_bt,

		local_param->move_limit_y_bt,
		local_param->edge_y_confirm_t,
		local_param->edge_y_dubious_t,
		local_param->edge_y_avg_bt,
		local_param->edge_xy_down_bt,
		local_param->edge_xy_confirm_t,
		local_param->max_points_bak_num,

		local_param->drv_stop_width,
		local_param->sensor_x_width,
		local_param->sensor_y_width,

		local_param->feature_sg,
		local_param->sg_min_value,
		local_param->feature_support_list,
		local_param->max_distance_dt,
		local_param->feature_big_data,
		local_param->feature_click_inhibition,
		local_param->min_click_time);
}



static int try_update_firmware(void)
{
    char joint_chr = '_';
    int error = NO_ERR;
    char* fw_name;
    struct ts_cmd_node cmd;

    memset(&cmd, 0, sizeof(struct ts_cmd_node));
    cmd.command = TS_FW_UPDATE_BOOT;
    fw_name = cmd.cmd_param.pub_params.firmware_info.fw_name;

    /*firmware name [product_name][ic_name][module][vendor]*/
    strncat(fw_name, g_ts_kit_platform_data.product_name, MAX_STR_LEN);
    strncat(fw_name, &joint_chr, 1);
    strncat(fw_name, g_ts_kit_platform_data.chip_data->chip_name, MAX_STR_LEN);
    strncat(fw_name, &joint_chr, 1);

    error = ts_kit_put_one_cmd(&cmd, NO_SYNC_TIMEOUT);

    return error;
}
static void ts_watchdog_work(struct work_struct* work)
{
    int error = NO_ERR;
    struct ts_cmd_node cmd;

    TS_LOG_DEBUG("ts_watchdog_work\n");
    cmd.command = TS_CHECK_STATUS;

    error = ts_kit_put_one_cmd(&cmd, NO_SYNC_TIMEOUT);
    if (error)
    {
        TS_LOG_ERR("put TS_CHECK_STATUS cmd error :%d\n", error);
    }
    return;
}
static void ts_watchdog_timer(unsigned long data)
{
    struct ts_kit_platform_data*  cd = (struct ts_kit_platform_data*)data;

    TS_LOG_DEBUG("Timer triggered\n");

    if (!cd)
    { return; }

    if (!work_pending(&cd->watchdog_work))
    { schedule_work(&cd->watchdog_work); }

    return;
}
void ts_kit_thread_stop_notify(void)
{
	struct ts_kit_device_data *dev = g_ts_kit_platform_data.chip_data;

	TS_LOG_INFO("ts thread stop called by lcd only shutdown\n");
	if(TS_UNINIT == atomic_read(&g_ts_kit_platform_data.state)) {
		TS_LOG_INFO("ts is not init");
		return;
	}

	atomic_set(&g_ts_kit_platform_data.state, TS_UNINIT);
	disable_irq(g_ts_kit_platform_data.irq_id);
	ts_stop_wd_timer(&g_ts_kit_platform_data);
	if (dev->ops->chip_shutdown)
		dev->ops->chip_shutdown();
	/*there is something wrong about system, now abandon the kthread_stop to avoid unkown bug*/
	//kthread_stop(g_ts_kit_platform_data.ts_task);
}
#if defined(HUAWEI_CHARGER_FB)
static int ts_charger_detect_cmd(enum ts_charger_state charger_state)
{
	int error = NO_ERR;
	struct ts_cmd_node *cmd = NULL;
	struct ts_charger_info *info = NULL;

	TS_LOG_INFO("%s called, charger type: %d, [0 in, other out], supported: %d\n",
	     __func__, charger_state,
	     g_ts_kit_platform_data.feature_info.charger_info.charger_supported);

	if (g_ts_kit_platform_data.feature_info.charger_info.charger_supported == 0) {
		TS_LOG_DEBUG("%s, do nothing cause charger_supported is zero\n", __func__);
		goto out;
	}

	info = &g_ts_kit_platform_data.feature_info.charger_info;
	info->op_action = TS_ACTION_WRITE;
	if (USB_PIUG_OUT == charger_state) {	/*usb plug out*/
		if (info->charger_switch == 0) {
			TS_LOG_ERR ("%s, there is no need to send cmd repeated\n",__func__);
			error = -EINVAL;
			goto out;
		}
		info->charger_switch = 0;
	} else {		/*usb plug in*/
		if (info->charger_switch == 1) {
			TS_LOG_ERR("%s, there is no need to send repeated\n",__func__);
			error = -EINVAL;
			goto out;
		}
		info->charger_switch = 1;
	}

	if (TS_WORK != atomic_read(&g_ts_kit_platform_data.state)) {
		TS_LOG_ERR("%s, can not send cmd when TP is not working in normal mode\n",__func__);
		error = -EINVAL;
		goto out;
	}

	cmd = (struct ts_cmd_node *)kzalloc(sizeof(struct ts_cmd_node),GFP_KERNEL);
	if (!cmd) {
		TS_LOG_ERR("malloc failed\n");
		error = -ENOMEM;
		goto out;
	}
	cmd->command = TS_CHARGER_SWITCH;
	cmd->cmd_param.prv_params = (void *)info;
	if (NO_ERR != ts_kit_put_one_cmd(cmd, NO_SYNC_TIMEOUT)) {
		TS_LOG_ERR("%s, put_one_cmd failed\n", __func__);
		error = -EINVAL;
		goto out;
	}

out:
	if (cmd != NULL)
		kfree(cmd);
	return error;
}

static int charger_detect_notifier_callback(struct notifier_block *self,
					    unsigned long event, void *data)
{
	enum  ts_charger_state charger_state  = USB_PIUG_IN;
	TS_LOG_INFO("%s, charger type:%ld, [0 in, other out]. charger switch supported: %d\n",
	     __func__, event, g_ts_kit_platform_data.feature_info.charger_info.charger_supported);

	if (g_ts_kit_platform_data.feature_info.charger_info.charger_supported != 0) {
		if(!event){
			charger_state  = USB_PIUG_OUT;}
		ts_charger_detect_cmd(charger_state);
	}
	return NO_ERR;
}
static void ts_kit_charger_notifier_register(void)
{
	int error;
	enum ts_charger_state charger_state = USB_PIUG_IN;
	g_ts_kit_platform_data.charger_detect_notify.notifier_call = charger_detect_notifier_callback;
	error = charger_type_notifier_register(&g_ts_kit_platform_data.charger_detect_notify);
	if (error < 0) {
		TS_LOG_ERR("%s, charger_type_notifier_register failed\n",__func__);
		g_ts_kit_platform_data.charger_detect_notify.notifier_call = NULL;
	} else {
		TS_LOG_INFO ("%s, already register charger_detect_notifier_callback\n",__func__);
		if(TS_CHARGER_TYPE_NONE == get_charger_type()){
			charger_state = USB_PIUG_OUT;
		}
		ts_charger_detect_cmd(charger_state);
	}
}
#endif

#if defined(CONFIG_FB)
static int fb_notifier_callback(struct notifier_block* self, unsigned long event, void* data)
{
    int error = NO_ERR;
    int i;
    struct fb_event* fb_event = data;
    int* blank = fb_event->data;
    unsigned char ts_state = 0;
    int times = 0;
	
    TS_LOG_INFO("tpkit fb_callback called,ic_type is %d,pt_flag is %ld,event is %d\n",g_tskit_ic_type,g_tskit_pt_station_flag,event);
    if (g_tskit_ic_type || g_tskit_pt_station_flag)
    { 
    	 TS_LOG_INFO("fb_notifier_callback do not need to do, return\n");
        return NO_ERR; 
    }

    for (i = 0 ; i < FB_MAX; i++)
    {
        if (registered_fb[i] == fb_event->info)
        {
            if (i == 0)
            {
                TS_LOG_DEBUG("Ts-index:%d, go on !\n", i);
                break;
            }
            else
            {
                TS_LOG_INFO("Ts-index:%d, exit !\n", i);
                return error;
            }
        }
    }
    TS_LOG_INFO("fb_notifier_callback, blank: %d, event:%lu, state: %d\n", *blank, event, atomic_read(&g_ts_kit_platform_data.state));
    switch (*blank)
    {
        case FB_BLANK_UNBLANK:
            /*resume device*/
            switch (event)
            {

                case FB_EARLY_EVENT_BLANK:
                    TS_LOG_DEBUG("resume: event = %lu, not care\n", event);
                    break;
                case FB_EVENT_BLANK:
                    while (1)
                    {
                        ts_state = atomic_read(&g_ts_kit_platform_data.state);
                        if ((TS_SLEEP == ts_state) || (TS_WORK_IN_SLEEP == ts_state))
                        {
                            error = ts_kit_power_control_notify(TS_RESUME_DEVICE, SHORT_SYNC_TIMEOUT);      /*touch power on*/
                            if (error)
                            { TS_LOG_ERR("ts resume device err\n"); }
                            error = ts_kit_power_control_notify(TS_AFTER_RESUME, NO_SYNC_TIMEOUT);  /*enable irq*/
                            if (error)
                            { TS_LOG_ERR("ts after resume err\n"); }
                            break;
                        }
                        else
                        {
                            msleep(TS_FB_WAIT_TIME);
                            if (times++ > TS_FB_LOOP_COUNTS)
                            {
                                times = 0;
                                TS_LOG_ERR("no resume, blank: %d, event:%lu, state: %d\n", *blank, event, ts_state);
                                break;
                            }
                        }
                        break;
                    default:
                        TS_LOG_DEBUG("resume: event = %lu, not care\n", event);
                        break;
                    }
            }
            break;
        case FB_BLANK_VSYNC_SUSPEND:
        case FB_BLANK_HSYNC_SUSPEND:
        case FB_BLANK_NORMAL:
        case FB_BLANK_POWERDOWN:
        default:
            /*suspend device*/
            switch (event)
            {
                case FB_EARLY_EVENT_BLANK:
                    while (1)
                    {
                        ts_state = atomic_read(&g_ts_kit_platform_data.state);
                        if ((TS_WORK == ts_state) || (TS_WORK_IN_SLEEP == ts_state))
                        {
                            error = ts_kit_power_control_notify(TS_BEFORE_SUSPEND, SHORT_SYNC_TIMEOUT); /*disable irq*/
                            if (error)
                            { TS_LOG_ERR("ts suspend device err\n"); }
                            break;
                        }
                        else
                        {
                            msleep(TS_FB_WAIT_TIME);
                            if (times++ > TS_FB_LOOP_COUNTS)
                            {
                                times = 0;
                                TS_LOG_ERR("no early suspend, blank: %d, event:%lu, state: %d\n", *blank, event, ts_state);
                                break;
                            }
                        }
                    }
                    break;
                case FB_EVENT_BLANK:
                    while (1)
                    {
                        ts_state = atomic_read(&g_ts_kit_platform_data.state);
                        if ((TS_WORK == ts_state) || (TS_WORK_IN_SLEEP == ts_state))
                        {
                            error = ts_kit_power_control_notify(TS_SUSPEND_DEVICE, NO_SYNC_TIMEOUT);    /*touch power off*/
                            if (error)
                            { TS_LOG_ERR("ts before suspend err\n"); }
                            break;
                        }
                        else
                        {
                            msleep(TS_FB_WAIT_TIME);
                            if (times++ > TS_FB_LOOP_COUNTS)
                            {
                                times = 0;
                                TS_LOG_ERR("no suspend, blank: %d, event:%lu, state: %d\n", *blank, event, ts_state);
                                break;
                            }
                        }
                    }
                    break;
                default:
                    TS_LOG_DEBUG("suspend: event = %lu, not care\n", event);
                    break;
            }
            break;
    }

    return NO_ERR;
}
#elif defined(CONFIG_HAS_EARLYSUSPEND)
static void ts_early_suspend(struct early_suspend* h)
{
    bool is_in_cell = g_ts_kit_platform_data.chip_data->is_in_cell;
    int error = NO_ERR;

    TS_LOG_INFO("ts early suspend, %s\n", (is_in_cell == false) ? "need suspend" : "no need suspend");

    /*for the in-cell, ts_suspend_notify called by lcd, not here*/
    if (false == is_in_cell)
    {
        error = ts_kit_power_control_notify(TS_BEFORE_SUSPEND, SHORT_SYNC_TIMEOUT);
        if (error)
        { TS_LOG_ERR("ts before suspend err\n"); }
        error = ts_kit_power_control_notify(TS_SUSPEND_DEVICE, SHORT_SYNC_TIMEOUT);
        if (error)
        { TS_LOG_ERR("ts suspend device err\n"); }
    }

    TS_LOG_INFO("ts_early_suspend done\n");
}
static void ts_late_resume(struct early_suspend* h)
{
    bool is_in_cell = g_ts_kit_platform_data.chip_data->is_in_cell;
    int error = NO_ERR;
    TS_LOG_INFO("ts late resume, %s\n", (is_in_cell == false) ? "need resume" : "no need resume");

    /*for the in-cell, ts_resume_notify called by lcd, not here*/
    if (false == is_in_cell)
    {
        error = ts_kit_power_control_notify(TS_RESUME_DEVICE, SHORT_SYNC_TIMEOUT);
        if (error)
        { TS_LOG_ERR("ts resume device err\n"); }
        error = ts_kit_power_control_notify(TS_AFTER_RESUME, SHORT_SYNC_TIMEOUT);
        if (error)
        { TS_LOG_ERR("ts after resume err\n"); }
    }
	if(g_ts_kit_platform_data.chip_data->is_direct_proc_cmd == 0)
		ts_send_holster_cmd();

    TS_LOG_INFO("ts_late_resume done\n");
}
#endif
static int get_ts_board_info(void)
{
    const char* bus_type;
    int rc;
    int error = NO_ERR;
    u32 bus_id = 0;
    u32 reset_gpio = 0;
    u32 irq_gpio = 0;

    g_ts_kit_platform_data.node = NULL;

    g_ts_kit_platform_data.node = of_find_compatible_node(NULL, NULL, TS_DEV_NAME);
    if (!g_ts_kit_platform_data.node)
    {
        TS_LOG_ERR("can't find ts module node\n");
        error = -EINVAL;
        goto out;
    }

    rc = of_property_read_string(g_ts_kit_platform_data.node, "bus_type", &bus_type);
    if (rc)
    {
        TS_LOG_ERR("bus type read failed:%d\n", rc);
        error = -EINVAL;
        goto out;
    }
    TS_LOG_INFO("bus type is:%s\n", bus_type);
	
    if (!strcmp (bus_type, "i2c"))
    {
        g_ts_kit_platform_data.bops = &ts_bus_i2c_info;
    }
    else if (!strcmp (bus_type, "spi"))
    {
        g_ts_kit_platform_data.bops = &ts_bus_spi_info;
    }
    else
    {
        TS_LOG_ERR("bus type invaild:%s\n", bus_type);
        error = -EINVAL;
	    goto out;
    }

    rc = of_property_read_u32(g_ts_kit_platform_data.node, "bus_id", &bus_id);
    if (rc)
    {
        TS_LOG_ERR("bus id read failed\n");
        error = -EINVAL;
        goto out;
    }
    g_ts_kit_platform_data.bops->bus_id = bus_id;
    TS_LOG_INFO("bus id :%d\n", bus_id);
	
    g_ts_kit_platform_data.reset_gpio = of_get_named_gpio(g_ts_kit_platform_data.node , "reset_gpio", 0);
    if (!gpio_is_valid(g_ts_kit_platform_data.reset_gpio))
    {
        TS_LOG_ERR(" ts_kit reset gpio is not valid\n");
	    error = -EINVAL;
        goto out;
    }
    g_ts_kit_platform_data.irq_gpio = of_get_named_gpio(g_ts_kit_platform_data.node , "irq_gpio", 0);
    if (!gpio_is_valid(g_ts_kit_platform_data.irq_gpio ))
    {
        TS_LOG_ERR(" ts_kit irq_gpio is not valid\n");
	    error = -EINVAL;
		goto out;
    }
    TS_LOG_INFO("bus id :%d ts_kit reset gpio is = %d ts_kit irq gpio is = %d.\n", 
		g_ts_kit_platform_data.bops->bus_id,g_ts_kit_platform_data.reset_gpio,g_ts_kit_platform_data.irq_gpio);

out:
    return error;
}
static int ts_gpio_request(void)
{
    int error = NO_ERR;

    error = gpio_request(g_ts_kit_platform_data.reset_gpio, "ts_kit_reset_gpio");
    if (error < 0)
    {
        TS_LOG_ERR("Fail request gpio:%d, ret=%d\n", g_ts_kit_platform_data.reset_gpio, error);
        return error;
    }
    error = gpio_request(g_ts_kit_platform_data.irq_gpio, "ts_kit_irq_gpio");
    if (error < 0)
    {
        TS_LOG_ERR("Fail request gpio:%d, ret=%d\n", g_ts_kit_platform_data.irq_gpio, error);
        return error;
    }
    TS_LOG_INFO("reset_gpio :%d ,irq_gpio\n", g_ts_kit_platform_data.reset_gpio,g_ts_kit_platform_data.irq_gpio);
    return error;
}
static int ts_creat_i2c_client(void)
{
    struct i2c_adapter* adapter = NULL;
    struct i2c_client* client = NULL;
    struct i2c_board_info board_info;

    memset(&board_info, 0, sizeof(struct i2c_board_info));
    strncpy(board_info.type, TS_DEV_NAME, I2C_NAME_SIZE);
    board_info.addr = I2C_DEFAULT_ADDR;
    board_info.flags = true;

    adapter = i2c_get_adapter(g_ts_kit_platform_data.bops->bus_id);
    if (!adapter)
    {
        TS_LOG_ERR("i2c_get_adapter failed\n");
        return -EIO;
    }

    client = i2c_new_device(adapter, &board_info);
    if (!client)
    {
        TS_LOG_ERR("i2c_new_device failed\n");
        return -EIO;
    }
    g_ts_kit_platform_data.client = client;
    i2c_set_clientdata(client, &g_ts_kit_platform_data);
	
#if defined (CONFIG_HUAWEI_DSM)
	if (!ts_dclient) {
		ts_dclient = dsm_register_client(&dsm_tp);
	}
#endif
    return NO_ERR;
}

static int ts_destory_i2c_client(void)
{
    TS_LOG_ERR("destory i2c device\n");
    i2c_unregister_device(g_ts_kit_platform_data.client);
    return NO_ERR;
}

static int ts_create_client(void)
{
    int error = -EINVAL;

    switch (g_ts_kit_platform_data.bops->btype)
    {
        case TS_BUS_I2C:
            TS_LOG_DEBUG("create ts's i2c device\n");
            error = ts_creat_i2c_client();
            break;
        case TS_BUS_SPI:
            TS_LOG_DEBUG("create ts's spi device\n");
            break;
        default:
            TS_LOG_ERR("unknown ts's device\n");
            break;
    }

    return error;
}

static int ts_destory_client(void)
{
    TS_LOG_ERR("destory touchscreen device\n");

    switch (g_ts_kit_platform_data.bops->btype)
    {
        case TS_BUS_I2C:
            TS_LOG_DEBUG("destory ts's i2c device\n");
            ts_destory_i2c_client();
            break;
        case TS_BUS_SPI:
            TS_LOG_DEBUG("destory ts's spi device\n");
            break;
        default:
            TS_LOG_ERR("unknown ts's device\n");
            break;
    }
    return NO_ERR;
}

static int ts_kit_parse_config(void)
{
    int error = NO_ERR;
    int rc;
    int index;
    char* tmp_buff = NULL;

    if (g_ts_kit_platform_data.node)
    {
        rc = of_property_read_string(g_ts_kit_platform_data.node, "product", (const char**)&tmp_buff);
        if (rc)
        {
            TS_LOG_ERR("product read failed:%d\n", rc);
            error = -EINVAL;
            goto out;
        }
    }

    if (!tmp_buff)
    {
        TS_LOG_ERR("tmp_buff failed\n");
        error = -EINVAL;
        goto out;
    }

    for (index = 0; tmp_buff[index] && index < strlen(tmp_buff); index++) //exchange name to lower
    { g_ts_kit_platform_data.product_name[index] = tolower(tmp_buff[index]); }

    if (index == MAX_STR_LEN)
    { g_ts_kit_platform_data.product_name[MAX_STR_LEN - 1] = '\0'; }

    TS_LOG_INFO("parse product name :%s\n", g_ts_kit_platform_data.product_name);

out:
    return error;
}
static void procfs_create(void)
{
    if (!proc_mkdir("touchscreen", NULL))
    { return; }
    proc_create("touchscreen/tp_capacitance_data", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, NULL, &rawdata_proc_fops);
    proc_create("touchscreen/tp_calibration_data", S_IRUSR | S_IWUSR |S_IRGRP | S_IROTH, NULL, &calibration_proc_fops);
    return;
}

static int ts_kit_create_sysfs(void)
{
    int error = NO_ERR;

    TS_LOG_INFO("ts_kit_create_sysfs enter\n");
    error = sysfs_create_group(&g_ts_kit_platform_data.ts_dev->dev.kobj, &ts_attr_group);
    if (error)
    {
        TS_LOG_ERR("can't create ts's sysfs\n");
        goto err_del_platform_dev;
    }
    TS_LOG_INFO("sysfs_create_group success\n");
    procfs_create();
    TS_LOG_INFO("procfs_create success\n");
    error = sysfs_create_link(NULL, &g_ts_kit_platform_data.ts_dev->dev.kobj, "touchscreen");
    if (error)
    {
        TS_LOG_ERR("%s: Fail create link error = %d\n", __func__, error);
        goto err_free_sysfs;
    }
    goto err_out;

err_free_sysfs:
    sysfs_remove_group(&g_ts_kit_platform_data.ts_dev->dev.kobj, &ts_attr_group);
err_del_platform_dev:
    platform_device_del(g_ts_kit_platform_data.ts_dev);
err_put_platform_dev:
    platform_device_put(g_ts_kit_platform_data.ts_dev);
err_out:
    return error;
}


static int ts_kit_chip_init(void)
{
	int error = NO_ERR;
	struct ts_kit_device_data *dev = g_ts_kit_platform_data.chip_data;
	
	TS_LOG_INFO("ts_chip_init called\n");
	mutex_init(&ts_kit_easy_wake_guesure_lock);
	if(g_ts_kit_platform_data.chip_data->is_direct_proc_cmd == 0){
		if (dev->ops->chip_init) {
			error = dev->ops->chip_init();
		}
	}
	if (error) {
		TS_LOG_ERR("chip init failed\n");
	}

	return error;
}

static int ts_register_algo(void)
{
	int error = NO_ERR;
	struct ts_kit_device_data*dev = g_ts_kit_platform_data.chip_data;

	TS_LOG_INFO("register algo called\n");
	dev->algo_size = 0;
       INIT_LIST_HEAD(&dev->algo_head);
	error = ts_kit_register_algo_func(dev);

	return error;
}


static int ts_input_open(struct input_dev* dev)
{

    TS_LOG_DEBUG("input_open called:%d\n", dev->users);
    return NO_ERR;
}

static void ts_input_close(struct input_dev* dev)
{
    TS_LOG_DEBUG("input_close called:%d\n", dev->users);
}
static int ts_kit_input_device_register(void)
{
    int error = NO_ERR;
    struct input_dev* input_dev;

    input_dev = input_allocate_device();
    if (!input_dev)
    {
        TS_LOG_ERR("failed to allocate memory for input dev\n");
        error = -ENOMEM;
        goto err_out;
    }

    input_dev->name = TS_DEV_NAME;
    if (g_ts_kit_platform_data.bops->btype == TS_BUS_I2C)
    { input_dev->id.bustype = BUS_I2C; }
    else if (g_ts_kit_platform_data.bops->btype == TS_BUS_SPI)
    { input_dev->id.bustype = BUS_SPI; }
    input_dev->dev.parent = &g_ts_kit_platform_data.ts_dev->dev;
    input_dev->open = ts_input_open;
    input_dev->close = ts_input_close;
    g_ts_kit_platform_data.input_dev = input_dev;

    if (g_ts_kit_platform_data.chip_data->ops->chip_input_config) //config input for diff chip
    {
        error = g_ts_kit_platform_data.chip_data->ops->chip_input_config(g_ts_kit_platform_data.input_dev);
    }
    if (error)
    {
        goto err_free_dev;
    }

    input_set_drvdata(input_dev, &g_ts_kit_platform_data);

    error = input_register_device(input_dev);
    if (error)
    {
        TS_LOG_ERR("input dev register failed : %d\n", error);
        goto err_free_dev;
    }
    return error;
	
err_free_dev:
    input_free_device(input_dev);
err_out:
    return error;
}

static int ts_kit_pm_init(void)
{
    int error = NO_ERR;

#if defined(CONFIG_FB)
    g_ts_kit_platform_data.fb_notify.notifier_call = fb_notifier_callback;
    error = fb_register_client(&g_ts_kit_platform_data.fb_notify);
    if (error)
    {
        TS_LOG_ERR("unable to register fb_notifier: %d\n", error);
        goto err_out;
    }
#elif defined(CONFIG_HAS_EARLYSUSPEND)
    g_ts_kit_platform_data.early_suspend.level = EARLY_SUSPEND_LEVEL_BLANK_SCREEN + TS_SUSPEND_LEVEL;
    g_ts_kit_platform_data.early_suspend.suspend = ts_early_suspend;
    g_ts_kit_platform_data.early_suspend.resume = ts_late_resume;
    register_early_suspend(&g_ts_kit_platform_data.early_suspend);
#endif
    TS_LOG_INFO("ts_kit_pm_init success\n");
err_out:
    return error;
}

static int ts_kit_irq_init(void)
{
    int error = NO_ERR;
    unsigned int irq_flags;

    g_ts_kit_platform_data.irq_id = gpio_to_irq(g_ts_kit_platform_data.irq_gpio);

    switch (g_ts_kit_platform_data.chip_data->irq_config)
    {
        case TS_IRQ_LOW_LEVEL:
            irq_flags = IRQF_TRIGGER_LOW;
            break;
        case TS_IRQ_HIGH_LEVEL:
            irq_flags = IRQF_TRIGGER_HIGH;
            break;
        case TS_IRQ_RAISE_EDGE:
            irq_flags = IRQF_TRIGGER_RISING;
            break;
        case TS_IRQ_FALL_EDGE:
            irq_flags = IRQF_TRIGGER_FALLING;
            break;
        default:
            TS_LOG_ERR("ts irq_config invaild\n");
            goto err_out;
    }

    atomic_set(&g_ts_kit_platform_data.state, TS_WORK);//avoid 1st irq unable to handler

    error = request_irq(g_ts_kit_platform_data.irq_id, ts_irq_handler, irq_flags | IRQF_NO_SUSPEND, "ts", &g_ts_kit_platform_data);
    if (error)
    {
        TS_LOG_ERR("ts request_irq failed\n");
		goto err_out;
    }
    TS_LOG_INFO("ts_kit_irq_init success\n");
err_out:
    return error;
}

static void ts_get_brightness_info(void)
{
	int error = NO_ERR;
	struct ts_kit_device_data *dev = g_ts_kit_platform_data.chip_data;
	g_ts_kit_lcd_brightness_info = 0;

	TS_LOG_INFO("ts_get_brightness_info called\n");
	if(g_ts_kit_platform_data.chip_data->is_direct_proc_cmd) {
		struct ts_cmd_node cmd;
		memset(&cmd, 0, sizeof(struct ts_cmd_node));
		cmd.command = TS_READ_BRIGHTNESS_INFO;
		error = ts_kit_put_one_cmd(&cmd, NO_SYNC_TIMEOUT);
	} else {
		if (dev->ops->chip_get_brightness_info) {
			g_ts_kit_lcd_brightness_info = dev->ops->chip_get_brightness_info();
			TS_LOG_INFO("ts_get_brightness_info  brightness data:%d\n", g_ts_kit_lcd_brightness_info);
		}
	}
	return;
}

static int ts_get_brightness_info_cmd(void)
{
	struct ts_kit_device_data *dev = g_ts_kit_platform_data.chip_data;
	int rc = NO_ERR;
	g_ts_kit_lcd_brightness_info = 0;
	TS_LOG_INFO("ts_get_brightness_info_cmd called\n");

	if (dev->ops->chip_get_brightness_info) {
		if(g_ts_kit_platform_data.chip_data->is_direct_proc_cmd){
			rc = dev->ops->chip_get_brightness_info();
			if(rc > 0){
				g_ts_kit_lcd_brightness_info = rc;
				rc = NO_ERR;
			}
		} else {
			g_ts_kit_lcd_brightness_info = dev->ops->chip_get_brightness_info();
		}
		TS_LOG_INFO("ts_get_brightness_info_cmd brightness data:%d\n", g_ts_kit_lcd_brightness_info);
	}
	return rc;
}
static int ts_kit_update_firmware(void)
{
    int error = NO_ERR;
    unsigned int touch_recovery_mode = 0;
    unsigned int charge_flag = 0;
	
/*get_boot_into_recovery_flag need to be added later*/
    touch_recovery_mode = get_into_recovery_flag_adapter();
    charge_flag = get_pd_charge_flag_adapter();

    /*do not do boot fw update on recovery mode*/
    TS_LOG_INFO("touch_recovery_mode is %d, charge_flag:%u\n", touch_recovery_mode, charge_flag);
    if (!touch_recovery_mode && !charge_flag)
    {
        error = try_update_firmware();
        if (error)
        {
            TS_LOG_ERR("return fail : %d\n", error);
            goto err_out;
        }
    }
err_out:
    return error;

}

static void ts_kit_status_check_init(void)
{
    if (g_ts_kit_platform_data.chip_data->need_wd_check_status)
    {
        TS_LOG_INFO("This chip need watch dog to check status\n");
        INIT_WORK(&(g_ts_kit_platform_data.watchdog_work), ts_watchdog_work);
        setup_timer(&(g_ts_kit_platform_data.watchdog_timer), ts_watchdog_timer, (unsigned long)(&g_ts_kit_platform_data));
        ts_start_wd_timer(&g_ts_kit_platform_data);
    }
	return ;
}
static int ts_send_init_cmd(void)
{
	int error = NO_ERR;
	TS_LOG_INFO("%s Enter\n", __func__);
	if(g_ts_kit_platform_data.chip_data->is_direct_proc_cmd){
		g_ts_kit_platform_data.chip_data->is_can_device_use_int = true;
		struct ts_cmd_node cmd;
		cmd.command = TS_TP_INIT;
		error = ts_kit_put_one_cmd(&cmd, NO_SYNC_TIMEOUT);
		if (error) {
			TS_LOG_ERR("put cmd error :%d\n", error);
			error = -EBUSY;
		}
	} else {
		TS_LOG_ERR("%s, nothing to do\n", __func__);
	}
	return error;
}

static int proc_init_cmd(void){
	schedule_work(&tp_init_work);
}

static void tp_init_work_fn(struct work_struct *work){
	struct ts_cmd_node use_cmd;
	int i = TS_CMD_QUEUE_SIZE;
	struct ts_cmd_queue *q;
	unsigned long flags;
	struct ts_cmd_node *cmd = &use_cmd;
	struct ts_kit_device_data *dev = g_ts_kit_platform_data.chip_data;
	q = &g_ts_kit_platform_data.no_int_queue;
	int error = NO_ERR;
	//Call chip init
	mutex_lock(&g_ts_kit_platform_data.chip_data->device_call_lock);
	if (dev->ops->chip_init) {
		TS_LOG_INFO("%s, call chip init\n",__func__);
		error = dev->ops->chip_init();
	}
	mutex_unlock(&g_ts_kit_platform_data.chip_data->device_call_lock);
	if(error != NO_ERR){
		TS_LOG_ERR("%s,chip init fail with error:%d\n",__func__,error);
		return;
	}
	TS_LOG_INFO("%s, chip init done\n",__func__);
	while(i-->0){
		spin_lock_irqsave(&q->spin_lock, flags);
		smp_wmb();
		if (!q->cmd_count) {
			TS_LOG_DEBUG("queue is empty\n");
			spin_unlock_irqrestore(&q->spin_lock, flags);
			break;
		}
		memcpy(cmd, &q->ring_buff[q->rd_index], sizeof(struct ts_cmd_node));
		q->cmd_count--;
		q->rd_index++;
		q->rd_index %= q->queue_size;
		smp_mb();
		spin_unlock_irqrestore(&q->spin_lock, flags);
		error = ts_kit_proc_command_directly(cmd);
		if(error != NO_ERR){
			TS_LOG_INFO("%s process init cmd %d error",__func__, cmd->command);
		}
	}
}

int ts_kit_put_one_cmd_direct_sync(struct ts_cmd_node *cmd, int timeout)
{
	int error = NO_ERR;
	TS_LOG_INFO("%s Enter\n",__func__);
	if(g_ts_kit_platform_data.chip_data->is_parade_solution == 0){
		return ts_kit_put_one_cmd(cmd,timeout);
	}

	if((atomic_read(&g_ts_kit_platform_data.state) == TS_UNINIT)){
		error = -EIO;
		return error;
	}
	if((atomic_read(&g_ts_kit_platform_data.state) == TS_SLEEP)
	     || (atomic_read(&g_ts_kit_platform_data.state) == TS_WORK_IN_SLEEP)){
	     TS_LOG_INFO("%s In Sleep State\n",__func__);
		 error = -EIO;
	     return error;
	}
out:
	return error;
}
int ts_kit_put_one_cmd(struct ts_cmd_node* cmd, int timeout)
{
    int error = -EIO;
    unsigned long flags;
    struct ts_cmd_queue* q;
    struct ts_cmd_sync* sync = NULL;

    if (!cmd)
    {
        TS_LOG_ERR("find null pointer\n");
        goto out;
    }

    if (TS_UNINIT == atomic_read(&g_ts_kit_platform_data.state))
    {
        TS_LOG_ERR("ts module not initialize\n");
        goto out;
    }

    if (timeout)
    {
        sync = (struct ts_cmd_sync*)kzalloc(sizeof(struct ts_cmd_sync), GFP_KERNEL);
        if (NULL == sync)
        {
            TS_LOG_ERR("failed to kzalloc completion\n");
            error = -ENOMEM;
            goto out;
        }
        init_completion(&sync->done);
        atomic_set(&sync->timeout_flag, TS_NOT_TIMEOUT);
        cmd->sync = sync;
    }
    else
    {
        cmd->sync = NULL;
    }

	if((g_ts_kit_platform_data.chip_data->is_direct_proc_cmd) &&
		(g_ts_kit_platform_data.chip_data->is_can_device_use_int==false)){
		if(cmd->command == TS_INT_PROCESS)
			goto out; //Not use INT in the init process
		q = &g_ts_kit_platform_data.no_int_queue;
	} else {
		q = &g_ts_kit_platform_data.queue;
	}

    spin_lock_irqsave(&q->spin_lock, flags);
    smp_wmb();
    if (q->cmd_count == q->queue_size)
    {
        spin_unlock_irqrestore(&q->spin_lock, flags);
        TS_LOG_ERR("queue is full\n");
        WARN_ON(1);
        error = -EIO;
        goto free_sync;
    }
    memcpy(&q->ring_buff[q->wr_index], cmd, sizeof(struct ts_cmd_node));
    q->cmd_count++;
    q->wr_index++;
    q->wr_index %= q->queue_size;
    smp_mb();
    spin_unlock_irqrestore(&q->spin_lock, flags);
    TS_LOG_DEBUG("put one cmd :%d in ring buff\n", cmd->command);
    error = NO_ERR;
    wake_up_process(g_ts_kit_platform_data.ts_task); //wakeup process

    if (timeout && !(wait_for_completion_timeout(&sync->done, abs(timeout)*HZ)))
    {
        atomic_set(&sync->timeout_flag, TS_TIMEOUT);
        TS_LOG_ERR("wait for cmd respone timeout\n");
        error = -EBUSY;
        goto out;
    }
    smp_wmb();

free_sync:
    if (sync)
    {
        kfree(sync);
    }
out:
    return error;
}

static int get_one_cmd(struct ts_cmd_node* cmd)
{
    unsigned long flags;
    int error = -EIO;
    struct ts_cmd_queue* q;

    if (unlikely(!cmd))
    {
        TS_LOG_ERR("find null pointer\n");
        goto out;
    }

    q = &g_ts_kit_platform_data.queue;

    spin_lock_irqsave(&q->spin_lock, flags);
    smp_wmb();
    if (!q->cmd_count)
    {
        TS_LOG_DEBUG("queue is empty\n");
        spin_unlock_irqrestore(&q->spin_lock, flags);
        goto out;
    }
    memcpy(cmd, &q->ring_buff[q->rd_index], sizeof(struct ts_cmd_node));
    q->cmd_count--;
    q->rd_index++;
    q->rd_index %= q->queue_size;
    smp_mb();
    spin_unlock_irqrestore(&q->spin_lock, flags);
    TS_LOG_DEBUG("get one cmd :%d from ring buff\n", cmd->command);
    error = NO_ERR;

out:
    return error;
}

static int ts_proc_command(struct ts_cmd_node* cmd)
{
    int error = NO_ERR;

    struct ts_cmd_sync* sync = cmd->sync;
    struct ts_cmd_node* proc_cmd = cmd;
    struct ts_cmd_node* out_cmd = &pang_cmd_buff;

    //discard timeout cmd to fix panic
    if (sync && atomic_read(&sync->timeout_flag) == TS_TIMEOUT)
    {
        kfree(sync);
        goto out;
    }

    if (!ts_cmd_need_process(proc_cmd))
    {
        TS_LOG_INFO("no need to process cmd:%d", proc_cmd->command);
        goto out;
    }

related_proc:
    out_cmd->command = TS_INVAILD_CMD;

    switch (proc_cmd->command)
    {
        case TS_INT_PROCESS:
            ts_proc_bottom_half(proc_cmd, out_cmd);
            enable_irq(g_ts_kit_platform_data.irq_id);
            break;
        case TS_INPUT_ALGO:
            ts_algo_calibrate(proc_cmd, out_cmd);
            break;
        case TS_REPORT_INPUT:
            ts_report_input(proc_cmd, out_cmd);
            break;
        case TS_POWER_CONTROL:
            ts_power_control(g_ts_kit_platform_data.irq_id, proc_cmd, out_cmd);
            break;
        case TS_FW_UPDATE_BOOT:
            disable_irq(g_ts_kit_platform_data.irq_id);
            ts_fw_update_boot(proc_cmd, out_cmd);
            enable_irq(g_ts_kit_platform_data.irq_id);
            break;
        case TS_FW_UPDATE_SD:
            disable_irq(g_ts_kit_platform_data.irq_id);
            ts_fw_update_sd(proc_cmd, out_cmd);
            enable_irq(g_ts_kit_platform_data.irq_id);
            break;
        case TS_DEBUG_DATA:
            disable_irq(g_ts_kit_platform_data.irq_id);
            ts_read_debug_data(proc_cmd, out_cmd);
            enable_irq(g_ts_kit_platform_data.irq_id);
            break;
        case TS_READ_RAW_DATA:
            disable_irq(g_ts_kit_platform_data.irq_id);
            ts_read_rawdata(proc_cmd, out_cmd);
            enable_irq(g_ts_kit_platform_data.irq_id);
            break;
	case TS_READ_CALIBRATION_DATA:
		disable_irq(g_ts_kit_platform_data.irq_id);
		ts_read_calibration_data(proc_cmd, out_cmd);
		enable_irq(g_ts_kit_platform_data.irq_id);
		break;
	case TS_GET_CALIBRATION_INFO:
		ts_get_calibration_info(proc_cmd, out_cmd);
		break;
	case TS_OEM_INFO_SWITCH:
		ts_oem_info_switch(proc_cmd, out_cmd);
		break;
        case TS_GET_CHIP_INFO:
            ts_get_chip_info(proc_cmd, out_cmd);
            break;
        case TS_SET_INFO_FLAG:
            ts_set_info_flag(proc_cmd, out_cmd);
            break;
        case TS_CALIBRATE_DEVICE:
            ts_calibrate(proc_cmd, out_cmd);
            break;
        case TS_CALIBRATE_DEVICE_LPWG:
            ts_calibrate_wakeup_gesture(proc_cmd, out_cmd);
            break;
        case TS_DSM_DEBUG:
            ts_dsm_debug(proc_cmd, out_cmd);
            break;
        case TS_GLOVE_SWITCH:
            ts_glove_switch(proc_cmd, out_cmd);
            break;
        case TS_TEST_TYPE:
            ts_get_capacitance_test_type(proc_cmd, out_cmd);
            break;
        case TS_PALM_SWITCH:
            ts_palm_switch(proc_cmd, out_cmd);
            break;
        case TS_HAND_DETECT:
            ts_hand_detect(proc_cmd, out_cmd);
            break;
        case TS_FORCE_RESET:
            disable_irq(g_ts_kit_platform_data.irq_id);
            ts_stop_wd_timer(&g_ts_kit_platform_data);
            ts_force_reset(proc_cmd, out_cmd);
            ts_start_wd_timer(&g_ts_kit_platform_data);
            enable_irq(g_ts_kit_platform_data.irq_id);
            break;
        case TS_INT_ERR_OCCUR:
            ts_stop_wd_timer(&g_ts_kit_platform_data);
            ts_int_err_process(proc_cmd, out_cmd);
            enable_irq(g_ts_kit_platform_data.irq_id);
            ts_start_wd_timer(&g_ts_kit_platform_data);
            break;
        case TS_ERR_OCCUR:
            disable_irq(g_ts_kit_platform_data.irq_id);
            ts_stop_wd_timer(&g_ts_kit_platform_data);
            ts_err_process(proc_cmd, out_cmd);
            ts_start_wd_timer(&g_ts_kit_platform_data);
            enable_irq(g_ts_kit_platform_data.irq_id);
            break;
        case TS_CHECK_STATUS:
            ts_check_status(proc_cmd, out_cmd);
            break;
        case TS_WAKEUP_GESTURE_ENABLE:
            ts_wakeup_gesture_enable_switch(proc_cmd, out_cmd);
            break;
        case TS_HOLSTER_SWITCH:
            ts_holster_switch(proc_cmd, out_cmd);
            break;
        case TS_ROI_SWITCH:
            ts_roi_switch(proc_cmd, out_cmd);
            break;
        case TS_TOUCH_WINDOW:
            ts_touch_window(proc_cmd, out_cmd);
            break;
#if defined(HUAWEI_CHARGER_FB)
	 case TS_CHARGER_SWITCH:
		ts_kit_charger_switch(proc_cmd, out_cmd);
		break;
#endif
        case TS_REGS_STORE:
            ts_chip_regs_operate(proc_cmd, out_cmd);
            break;
        case TS_TEST_CMD:
            ts_test_cmd(proc_cmd, out_cmd);
            break;
        case TS_HARDWARE_TEST:
            ts_special_hardware_test_switch(proc_cmd, out_cmd);
            break;
	case TS_READ_BRIGHTNESS_INFO:
		ts_get_brightness_info_cmd();
		break;
	case TS_TP_INIT:
		proc_init_cmd();
		break;
	case TS_TOUCH_SWITCH:
		ts_touch_switch_cmd();
		break;
        default:
            break;
    }

    TS_LOG_DEBUG("command :%d process result:%d \n", proc_cmd->command, error);

    if (out_cmd->command != TS_INVAILD_CMD)
    {
        TS_LOG_DEBUG("related command :%d  need process\n", out_cmd->command);
        swap(proc_cmd, out_cmd);//ping - pang
        goto related_proc;
    }

    if (sync)  //notify wait threads by completion
    {
        smp_mb();
        TS_LOG_DEBUG("wakeup threads in waitqueue\n");
        if (atomic_read(&sync->timeout_flag) == TS_TIMEOUT)
        {
            kfree(sync);
        }
        else
        {
            complete(&sync->done);
        }
    }

out:
    return error;
}

int ts_kit_proc_command_directly(struct ts_cmd_node *cmd)
{
	int error = NO_ERR;
	TS_LOG_INFO("%s Enter\n",__func__);
	/*Do not use cmd->sync in this func, setting it as null*/
	cmd->sync = NULL;
	if (!ts_cmd_need_process(cmd)) {
		TS_LOG_INFO("%s, no need to process cmd:%d",__func__, cmd->command);
		error = -EIO;
		goto out;
	}
	struct ts_cmd_node outcmd;
	mutex_lock(&g_ts_kit_platform_data.chip_data->device_call_lock);
	switch (cmd->command) {
		case TS_INT_PROCESS:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_INPUT_ALGO:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_REPORT_INPUT:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_POWER_CONTROL:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_FW_UPDATE_BOOT:
			error = ts_fw_update_boot(cmd, &outcmd);
			break;
		case TS_FW_UPDATE_SD:
			error = ts_fw_update_sd(cmd, &outcmd);
			break;
		case TS_DEBUG_DATA:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_READ_RAW_DATA:
			error = ts_read_rawdata(cmd, &outcmd);
			break;
		case TS_READ_CALIBRATION_DATA:
			error = ts_read_calibration_data(cmd, &outcmd);
			break;
		case TS_GET_CALIBRATION_INFO:
			error = ts_get_calibration_info(cmd, &outcmd);
			break;
		case TS_OEM_INFO_SWITCH:
			error = ts_oem_info_switch(cmd, &outcmd);
			break;
		case TS_GET_CHIP_INFO:
			error = ts_get_chip_info(cmd, &outcmd);
			break;
		case TS_SET_INFO_FLAG:
			error = ts_set_info_flag(cmd, &outcmd);
			break;
		case TS_CALIBRATE_DEVICE:
			error = ts_calibrate(cmd, &outcmd);
			break;
		case TS_CALIBRATE_DEVICE_LPWG:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_DSM_DEBUG:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_GLOVE_SWITCH:
			error = ts_glove_switch(cmd, &outcmd);
			break;
		case TS_TEST_TYPE:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_PALM_SWITCH:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_HAND_DETECT:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_FORCE_RESET:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_INT_ERR_OCCUR:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_ERR_OCCUR:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_CHECK_STATUS:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_WAKEUP_GESTURE_ENABLE:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_HOLSTER_SWITCH:
			error = ts_holster_switch(cmd, &outcmd);
			break;
		case TS_ROI_SWITCH:
			error = ts_roi_switch(cmd, &outcmd);
			break;
		case TS_TOUCH_WINDOW:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
#if defined(HUAWEI_CHARGER_FB)
		case TS_CHARGER_SWITCH:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
#endif
		case TS_REGS_STORE:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_TEST_CMD:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_HARDWARE_TEST:
			TS_LOG_ERR("%s, command %d does not support direct call!",__func__, cmd->command);
			break;
		case TS_READ_BRIGHTNESS_INFO:
			error = ts_get_brightness_info_cmd();
			break;
		case TS_TOUCH_SWITCH:
			ts_touch_switch_cmd();
			break;
		default:
			TS_LOG_ERR("%s, command %d unknown!",__func__, cmd->command);
			break;
		}
		mutex_unlock(&g_ts_kit_platform_data.chip_data->device_call_lock);
		TS_LOG_DEBUG("%s, command :%d process result:%d \n",__func__, cmd->command,
				 error);
out:
	return error;
}

static int ts_kit_init(void)
{
    int error = NO_ERR;
    unsigned int touch_recovery_mode = 0;
    unsigned int charge_flag = 0;
    unsigned int irq_flags;
    struct input_dev* input_dev;

    atomic_set(&g_ts_kit_platform_data.state, TS_UNINIT);
    atomic_set(&g_ts_kit_platform_data.ts_esd_state, TS_NO_ESD);
    TS_LOG_INFO("ts_kit_init\n");
    g_ts_kit_platform_data.edge_wideth = EDGE_WIDTH_DEFAULT;
    g_ts_kit_platform_data.queue.rd_index = 0;
    g_ts_kit_platform_data.queue.wr_index = 0;
    g_ts_kit_platform_data.queue.cmd_count = 0;
    g_ts_kit_platform_data.queue.queue_size = TS_CMD_QUEUE_SIZE;
    spin_lock_init(&g_ts_kit_platform_data.queue.spin_lock);
    TS_LOG_DEBUG("ts init: cmd queue size : %d\n", TS_CMD_QUEUE_SIZE);
    wake_lock_init(&g_ts_kit_platform_data.ts_wake_lock, WAKE_LOCK_SUSPEND, "ts_wake_lock");
   
    error = ts_kit_parse_config();
    if (error)
    {
        TS_LOG_ERR("ts init parse config failed : %d\n", error);
        goto err_out;
    }
    TS_LOG_INFO("ts_kit_parse_config success\n");
    error = ts_kit_create_sysfs();
    if (error)
    {
        TS_LOG_ERR("ts init create sysfs failed : %d\n", error);
        goto err_out;
    }
    TS_LOG_INFO("g_tskit_ic_type is %d,g_tskit_pt_station_flag is %d \n",g_tskit_ic_type,g_tskit_pt_station_flag);    
    error = ts_kit_chip_init();
    if (error)
    {
        TS_LOG_ERR("chip init failed : %d,  try fw update again\n", error);
    }

	if(g_ts_kit_platform_data.chip_data->is_direct_proc_cmd){
		g_ts_kit_platform_data.chip_data->is_can_device_use_int = false;
		g_ts_kit_platform_data.no_int_queue.rd_index = 0;
		g_ts_kit_platform_data.no_int_queue.wr_index = 0;
		g_ts_kit_platform_data.no_int_queue.cmd_count = 0;
		g_ts_kit_platform_data.no_int_queue.queue_size = TS_CMD_QUEUE_SIZE;
		spin_lock_init(&g_ts_kit_platform_data.no_int_queue.spin_lock);
		INIT_WORK(&tp_init_work, tp_init_work_fn);
	}

/*     if (not_get_special_tp_node )
    {
        TS_LOG_ERR("get special  TP node failed not_get_special_tp_node = %d \n",not_get_special_tp_node);
	 error =not_get_special_tp_node;
        goto err_out;
    } */
#if defined (CONFIG_HUAWEI_DSM)
	chip_detfail_dsm = true;	/*true means after chip init to dsm*/
#endif
    error = ts_register_algo();
    if (error) 
    {
         TS_LOG_ERR("ts register algo failed : %d\n", error);
	     goto  err_remove_sysfs;
    }
    error = ts_kit_input_device_register();
    if (error)
    {
        TS_LOG_ERR("ts init input device register failed : %d\n", error);
        goto err_remove_sysfs;
    }
    error = ts_kit_pm_init();
    if (error)
    {
        TS_LOG_ERR("ts init pm init failed : %d\n", error);
        goto err_free_input_dev;
    }
#if defined (CONFIG_TEE_TUI)
	register_tui_driver(tui_tp_init, "tp", g_ts_kit_platform_data.chip_data->tui_data);
#endif
    error = ts_kit_irq_init();
    if (error)
    {
        TS_LOG_ERR("ts init irq_init failed : %d\n", error);
        goto err_unregister_suspend;
    }
    /*get brightness info*/
    ts_get_brightness_info();
    error = ts_kit_update_firmware();
    if (error)
    {
        TS_LOG_ERR("ts init update_firmware failed : %d\n", error);
        goto err_firmware_update;
    }
    ts_send_roi_cmd(TS_ACTION_READ, NO_SYNC_TIMEOUT);	/*roi function set as default by TP firmware */
    ts_send_init_cmd();/*Send this cmd to make sure all the cmd in the init is called*/
#if defined(HUAWEI_CHARGER_FB)
	ts_kit_charger_notifier_register();
#endif

    ts_kit_status_check_init();
    error = NO_ERR;
    TS_LOG_INFO("ts_kit_init called out\n");
    goto out;

err_firmware_update:
    free_irq(g_ts_kit_platform_data.irq_id, &g_ts_kit_platform_data);
err_unregister_suspend:
#if defined(CONFIG_FB)
    if (fb_unregister_client(&g_ts_kit_platform_data.fb_notify))
    { TS_LOG_ERR("error occurred while unregistering fb_notifier.\n"); }
#elif defined(CONFIG_HAS_EARLYSUSPEND)
    unregister_early_suspend(&g_ts_kit_platform_data.early_suspend);
#endif
err_free_input_dev:
    input_unregister_device(input_dev);
    input_free_device(input_dev);
err_remove_sysfs:
    sysfs_remove_link(NULL, "touchscreen");
    sysfs_remove_group(&g_ts_kit_platform_data.ts_dev->dev.kobj, &ts_attr_group);
    platform_device_del(g_ts_kit_platform_data.ts_dev);
    platform_device_put(g_ts_kit_platform_data.ts_dev);
err_out:
    atomic_set(&g_ts_kit_platform_data.state, TS_UNINIT);
    wake_lock_destroy(&g_ts_kit_platform_data.ts_wake_lock);
out:
    TS_LOG_INFO("ts_init, g_ts_kit_platform_data.state : %d\n", atomic_read(&g_ts_kit_platform_data.state));
    return error;
}
static void ts_ic_shutdown(void)
{
    struct ts_kit_device_data* dev = g_ts_kit_platform_data.chip_data;
    if (dev->ops->chip_shutdown)
    { dev->ops->chip_shutdown(); }
    return;
}
static void ts_kit_exit(void)
{
    atomic_set(&g_ts_kit_platform_data.state, TS_UNINIT);
    disable_irq(g_ts_kit_platform_data.irq_id);
    ts_ic_shutdown();
    free_irq(g_ts_kit_platform_data.irq_id, &g_ts_kit_platform_data);
    //sysfs_remove_group(&g_ts_kit_platform_data.ts_dev->dev.kobj, &ts_attr_group);
#if defined(CONFIG_FB)
    if (fb_unregister_client(&g_ts_kit_platform_data.fb_notify)){ 
    	    TS_LOG_ERR("error occurred while unregistering fb_notifier.\n"); 
	}
#elif defined(CONFIG_HAS_EARLYSUSPEND)
    unregister_early_suspend(&g_ts_kit_platform_data.early_suspend);
#endif
    input_unregister_device(g_ts_kit_platform_data.input_dev);
    input_free_device(g_ts_kit_platform_data.input_dev);
    sysfs_remove_link(NULL, "touchscreen");
    sysfs_remove_group(&g_ts_kit_platform_data.ts_dev->dev.kobj, &ts_attr_group);
    wake_lock_destroy(&g_ts_kit_platform_data.ts_wake_lock);
    platform_device_unregister(g_ts_kit_platform_data.ts_dev);
    ts_destory_client();
#if defined(HUAWEI_CHARGER_FB)
	if (NULL != g_ts_kit_platform_data.charger_detect_notify.notifier_call) {
		charger_type_notifier_unregister(&g_ts_kit_platform_data. charger_detect_notify);
		TS_LOG_INFO("charger_type_notifier_unregister called\n");
	}
#endif	
    memset(&g_ts_kit_platform_data, 0, sizeof(struct ts_kit_platform_data));
    TS_LOG_ERR("ts_thread exited\n");
}
static bool ts_task_continue(void)
{
    bool task_continue = true;
    unsigned long flags;
    TS_LOG_DEBUG("prepare enter idle\n");

repeat:
    if (unlikely(kthread_should_stop()))
    {
        task_continue = false;
        goto out;
    }
    spin_lock_irqsave(&g_ts_kit_platform_data.queue.spin_lock, flags);
    smp_wmb();
    if (g_ts_kit_platform_data.queue.cmd_count)
    {
        set_current_state(TASK_RUNNING);
        TS_LOG_DEBUG("ts task state to  TASK_RUNNING\n");
        goto out_unlock;
    }
    else
    {
        set_current_state(TASK_INTERRUPTIBLE);
        TS_LOG_DEBUG("ts task state to  TASK_INTERRUPTIBLE\n");
        spin_unlock_irqrestore(&g_ts_kit_platform_data.queue.spin_lock, flags);
        schedule();
        goto repeat;
    }

out_unlock:
    spin_unlock_irqrestore(&g_ts_kit_platform_data.queue.spin_lock, flags);
out:
    return task_continue;
}
static int ts_thread(void* p)
{
    static const struct sched_param param =
    {
        .sched_priority = MAX_USER_RT_PRIO / 2,
    };
    smp_wmb();
    TS_LOG_INFO("ts_thread\n");
    if (ts_kit_init())
    {
        TS_LOG_ERR("ts_init  failed\n");
	    goto  err_out;	
    }
    memset(&ping_cmd_buff, 0, sizeof(struct ts_cmd_node));
    memset(&pang_cmd_buff, 0, sizeof(struct ts_cmd_node));
    smp_mb();
    sched_setscheduler(current, SCHED_FIFO, &param);

    while (ts_task_continue())
    {
        while (!get_one_cmd(&ping_cmd_buff)) //get one command
        {
            ts_proc_command(&ping_cmd_buff);
            memset(&ping_cmd_buff, 0, sizeof(struct ts_cmd_node));
            memset(&pang_cmd_buff, 0, sizeof(struct ts_cmd_node));
        }
    }

    TS_LOG_ERR("ts thread stop\n");
    ts_kit_exit();
	
err_out:
     platform_device_unregister(g_ts_kit_platform_data.ts_dev);
     ts_destory_client();
     gpio_free(g_ts_kit_platform_data.reset_gpio);
     gpio_free (g_ts_kit_platform_data.irq_gpio);
     atomic_set(&g_ts_kit_platform_data.state, TS_UNINIT);
    return NO_ERR;
}

int  huawei_ts_chip_register(struct ts_kit_device_data* chipdata)
{
    int error = NO_ERR;
    TS_LOG_INFO("huawei_ts_chip_register called here\n");
    if (NULL == chipdata)
    {
        TS_LOG_ERR("%s chipdata is null\n", __func__);
        return  -EINVAL;
    }
    if (TS_UNREGISTER == atomic_read(&g_ts_kit_platform_data.register_flag))
    {
        if (chipdata->ops->chip_detect)
        {
            g_ts_kit_platform_data.chip_data = chipdata;
            error = chipdata->ops->chip_detect(&g_ts_kit_platform_data);
            TS_LOG_INFO(" huawei_ts_chip_register error=%d\n", error);
            if (!error)
            {
#ifdef CONFIG_HUAWEI_HW_DEV_DCT
                /* detect current device successful, set the flag as present */
                set_tp_dev_flag();
#endif
                atomic_set(&g_ts_kit_platform_data.register_flag, TS_REGISTER_DONE);
                g_ts_kit_platform_data.ts_task = kthread_create(ts_thread, &g_ts_kit_platform_data, "ts_thread:%d", 0);
                if (IS_ERR(g_ts_kit_platform_data.ts_task))
                {
                    TS_LOG_ERR("create ts_thread failed\n");
                    ts_destory_client();
                    memset(&g_ts_kit_platform_data, 0, sizeof(struct ts_kit_platform_data));
                    error = -EINVAL;
                    goto out;
                }
                /* Attention about smp_mb/rmb/wmb
                     Add these driver to avoid  data consistency problem
                     ts_thread/ts_probe/irq_handler/ts_kit_put_one_cmd/get_one_cmd
                     may run in different cpus and L1/L2 cache data consistency need
                     to conside. We use barrier to make sure data consistently*/
                smp_mb();
                wake_up_process(g_ts_kit_platform_data.ts_task);
            }
        }

    }
    else
    {
        error = -EPERM;
    }

out:
    return error;
}
static int __init huawei_ts_module_init(void)
{
    int error = NO_ERR;
    TS_LOG_INFO("huawei_ts, huawei_ts_module_init called here\n");
    memset(&g_ts_kit_platform_data, 0, sizeof(struct ts_kit_platform_data));
    atomic_set(&g_ts_kit_platform_data.register_flag, TS_UNREGISTER);

    error = get_ts_board_info();
    if (error)
    {
        TS_LOG_ERR("get bus info failed :%d\n", error);
        goto out;
    }
    error = ts_create_client();
    if (error)
    {
        TS_LOG_ERR("create device failed :%d\n", error);
        goto out;
    }
    error = ts_gpio_request();
    if (error)
    {
        TS_LOG_ERR("ts_gpio_request failed :%d\n", error);
        goto err_remove_client;
    }
    g_ts_kit_platform_data.ts_dev = platform_device_alloc("huawei_touch", -1);
    if (!g_ts_kit_platform_data.ts_dev)
    {
        TS_LOG_ERR("platform device malloc failed\n");
        error = -ENOMEM;
    	goto err_remove_gpio;
    }
    error = platform_device_add(g_ts_kit_platform_data.ts_dev);
    if (error)
    {
        TS_LOG_ERR("platform device add failed :%d\n", error);
	    goto  err_put_platform_dev;
    }
     TS_LOG_INFO("ts_init called out\n");
     goto out;

err_put_platform_dev:
	  platform_device_put(g_ts_kit_platform_data.ts_dev);
err_remove_gpio:
	gpio_free(g_ts_kit_platform_data.irq_gpio);
	gpio_free(g_ts_kit_platform_data.reset_gpio);
err_remove_client:
	 ts_destory_client();
out:
    return error;
}

static void __exit huawei_ts_module_exit(void)
{
    TS_LOG_INFO("huawei_ts, huawei_ts_module_exit called here\n");
	if (g_ts_kit_platform_data.ts_task)
		kthread_stop(g_ts_kit_platform_data.ts_task);
#if defined (CONFIG_TEE_TUI)
    unregister_tui_driver("tp");
#endif
 //gpio free;
 //destory i2c client
    return;
}

//module_init(huawei_ts_module_init);
module_init(huawei_ts_module_init);
module_exit(huawei_ts_module_exit);
EXPORT_SYMBOL(g_ts_kit_log_cfg);
EXPORT_SYMBOL(huawei_ts_chip_register);
MODULE_AUTHOR("Huawei Device Company");
MODULE_DESCRIPTION("Huawei TouchScreen Driver");
MODULE_LICENSE("GPL");
