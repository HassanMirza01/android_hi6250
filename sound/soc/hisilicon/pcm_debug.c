#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/io.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include <linux/of_irq.h>
#include <linux/of_platform.h>
#include <linux/uaccess.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/soc.h>

#include "hi6210_pcm.h"

/*lint -e838 -e747 -e715 -e528 -e438 -e701 -e785 -e753 -e749*/

#ifdef CONFIG_DEBUG_FS
#include <linux/debugfs.h>
#endif


#define MAX_CMD_LEN    64
#define READ_BUF_LEN   1024
#define ERROR_PARAM    0xFF
#define ERROR_PCM_MODE 0x3

enum pcm_debug_cmd{
	PCM_DEBUG_OPEN,
	PCM_DEBUG_CLOSE,
	PCM_DEBUG_HW_PARAMS,
	PCM_DEBUG_FREE,
	PCM_DEBUG_PREPARE,
	PCM_DEBUG_TRIGGER,
	PCM_DEBUG_POINTER,
	PCM_DEBUG_CMD_TOTAL,
};

enum pcm_debug_device {
	PCM_DEBUG_DEVICE_NORMAL = 0,
	PCM_DEBUG_DEVICE_MODEM,
	PCM_DEBUG_DEVICE_FM,
	PCM_DEBUG_DEVICE_BT,
	PCM_DEBUG_DEVICE_OFFLOAD,
	PCM_DEBUG_DEVICE_HIRES,
	PCM_DEBUG_DEVICE_FAST,
	PCM_DEBUG_DEVICE_TOTAL,
};
#define TEST_ASSERT(case_name, exp) \
	if (!(exp)) {\
		pr_err("pcm_debug:[%s] - %s:%d failed\n", case_name, __func__, __LINE__); \
		return 0; \
	}

#define TEST_PASS(case_name)  pr_err("pcm_debug:[%s] - %s: pass\n", case_name, __func__);\
                              return 0;

extern struct snd_soc_platform_driver hi6210_pcm_platform;

struct pcm_debug_data {
    struct snd_pcm_substream substream[PCM_DEBUG_DEVICE_TOTAL][2];
    struct dentry*  dentry;
};

struct pcm_debug_data pcm_debug;
static const unsigned int hw_params_rates[] = {48000, 96000, 192000, 384000};

static int pcm_debug_param_is_mask(int p)
{
    return (p >= SNDRV_PCM_HW_PARAM_FIRST_MASK) &&
        (p <= SNDRV_PCM_HW_PARAM_LAST_MASK);
}

static int pcm_debug_param_is_interval(int p)
{
    return (p >= SNDRV_PCM_HW_PARAM_FIRST_INTERVAL) &&
        (p <= SNDRV_PCM_HW_PARAM_LAST_INTERVAL);
}

static struct snd_mask *pcm_debug_param_to_mask(struct snd_pcm_hw_params *p, int n)
{
    return &(p->masks[n - SNDRV_PCM_HW_PARAM_FIRST_MASK]);
}

static inline struct snd_interval *pcm_debug_param_to_interval(struct snd_pcm_hw_params *p, int n)
{
    return &(p->intervals[n - SNDRV_PCM_HW_PARAM_FIRST_INTERVAL]);
}

static void pcm_debug_param_set_int(struct snd_pcm_hw_params *p, int n, unsigned int val)
{
    if (pcm_debug_param_is_interval(n)) {
        struct snd_interval *i = pcm_debug_param_to_interval(p, n);
        i->min = val;
        i->max = val;
        i->integer = 1;
    }
}

static void pcm_debug_param_set_mask(struct snd_pcm_hw_params *p, int n, unsigned int bit)
{
    if (bit >= SNDRV_MASK_MAX)
        return;
    if (pcm_debug_param_is_mask(n)) {
        struct snd_mask *m = pcm_debug_param_to_mask(p, n);
        m->bits[0] = 0;
        m->bits[1] = 0;
        m->bits[bit >> 5] |= (1 << (bit & 31));
    }
}

static void pcm_debug_param_init(struct snd_pcm_hw_params *p)
{
    int n;

    memset(p, 0, sizeof(*p));
    for (n = SNDRV_PCM_HW_PARAM_FIRST_MASK;
         n <= SNDRV_PCM_HW_PARAM_LAST_MASK; n++) {
            struct snd_mask *m = pcm_debug_param_to_mask(p, n);
            m->bits[0] = ~0;
            m->bits[1] = ~0;
    }
    for (n = SNDRV_PCM_HW_PARAM_FIRST_INTERVAL;
         n <= SNDRV_PCM_HW_PARAM_LAST_INTERVAL; n++) {
            struct snd_interval *i = pcm_debug_param_to_interval(p, n);
            i->min = 0;
            i->max = ~0;
    }
    p->rmask = ~0U;
    p->cmask = 0;
    p->info = ~0U;
}



static int pcm_debug_open(char* case_name, int pcm_device, int pcm_mode)
{
    struct snd_pcm_substream* substream;
    struct snd_pcm* pcm;
    struct hi6210_runtime_data* private_data;
    struct snd_pcm_runtime* runtime;
    int ret = 0;

    pcm = kmalloc(sizeof(struct snd_pcm), GFP_KERNEL);
    TEST_ASSERT(case_name, pcm)
    memset(pcm, 0, sizeof(struct snd_pcm));

    private_data = kzalloc(sizeof(struct hi6210_runtime_data), GFP_KERNEL);
    if (!private_data) {
         pr_err("pcm_debug: pcm_debug_open kzalloc private_data error!");
         kfree(pcm);
         pcm = NULL;
         return -ENOMEM;
    }

    runtime = kzalloc(sizeof(struct snd_pcm_runtime), GFP_KERNEL);
    if (!runtime) {
         pr_err("pcm_debug: pcm_debug_open kzalloc runtime error!");
         kfree(private_data);
         private_data = NULL;
         kfree(pcm);
         pcm = NULL;
         return -ENOMEM;
    }

    runtime->private_data = private_data;
    pcm->device = pcm_device;

    substream = &pcm_debug.substream[pcm_device][pcm_mode];

    substream->pcm = pcm;
    substream->runtime = runtime;
    substream->stream = pcm_mode;
    pr_err("pcm_debug:pcm_debug_open runtime %pK; private_data %pK\n" , substream->runtime, substream->runtime->private_data);
    ret = hi6210_pcm_platform.ops->open(substream);

    TEST_ASSERT(case_name, ret == 0)

    TEST_PASS(case_name)
}

static int pcm_debug_close(char* case_name, int pcm_device, int pcm_mode)
{
    struct snd_pcm_substream* substream;
    int ret = 0;
    substream = &pcm_debug.substream[pcm_device][pcm_mode];

    ret = hi6210_pcm_platform.ops->close(substream);

    if (substream->pcm) {
        kfree(substream->pcm);
        substream->pcm = NULL;
    }

    if (substream->runtime && substream->runtime->private_data) {
        pr_err("pcm_debug:kfree private_data, %pK\n" , substream->runtime->private_data);
        substream->runtime->private_data = NULL;
    }

    if (substream->runtime) {
        pr_err("pcm_debug:kfree runtime %pK\n", substream->runtime);
        substream->runtime = NULL;
    }

    TEST_ASSERT(case_name, ret == 0)
    TEST_PASS(case_name)
}

static int pcm_debug_hw_params(char* case_name, int pcm_device, int pcm_mode, int param)
{
    struct snd_pcm_substream* substream;
    struct snd_pcm_hw_params params;
    int ret = 0;
    unsigned int rate = 48000;
    unsigned int channels = 2;
    unsigned int format = SNDRV_PCM_FORMAT_S16_LE;

    if (PCM_DEBUG_DEVICE_HIRES == pcm_device) {
        if (param < 0 || param >= (int)(sizeof(hw_params_rates)/sizeof(hw_params_rates[0]))) {
            pr_err("pcm_debug:[%s] - hw_params rate is error\n", case_name);
            return -EINVAL;
        }
        rate = hw_params_rates[param];
        format = SNDRV_PCM_FORMAT_S24_LE;
    }
    else if (SNDRV_PCM_STREAM_CAPTURE == pcm_mode) {
        if (param < 1 && param > 2) {
            pr_err("pcm_debug:[%s] - hw_params channels is error\n", case_name);
            return -EINVAL;
        }
        channels = (unsigned int)param;
    }

    pcm_debug_param_init(&params);
    pcm_debug_param_set_mask(&params, SNDRV_PCM_HW_PARAM_FORMAT, format);
    pcm_debug_param_set_int(&params, SNDRV_PCM_HW_PARAM_CHANNELS, channels);
    pcm_debug_param_set_int(&params, SNDRV_PCM_HW_PARAM_RATE, rate);

    substream = &pcm_debug.substream[pcm_device][pcm_mode];

    ret = hi6210_pcm_platform.ops->hw_params(substream, &params);

    TEST_ASSERT(case_name, ret == 0)
    TEST_PASS(case_name)
}


static int pcm_debug_free(char* case_name, int pcm_device, int pcm_mode)
{
    struct snd_pcm_substream* substream;
    int ret = 0;

    substream = &pcm_debug.substream[pcm_device][pcm_mode];

    ret = hi6210_pcm_platform.ops->hw_free(substream);

    TEST_ASSERT(case_name, ret == 0)
    TEST_PASS(case_name)
}

static int pcm_debug_prepare(char* case_name, int pcm_device, int pcm_mode)
{
    struct snd_pcm_substream* substream;
    int ret = 0;

    substream = &pcm_debug.substream[pcm_device][pcm_mode];

    ret = hi6210_pcm_platform.ops->prepare(substream);

    TEST_ASSERT(case_name, ret == 0)
    TEST_PASS(case_name)
}

static int pcm_debug_trigger(char* case_name, int pcm_device, int pcm_mode, int trigger_cmd)
{
    struct snd_pcm_substream* substream;
    int ret = 0;

    if (trigger_cmd < 0 || trigger_cmd == 2 || trigger_cmd > 7) {
        pr_err("pcm_debug: trigger param is error\n");
        return -EINVAL;
    }

    substream = &pcm_debug.substream[pcm_device][pcm_mode];

    ret = hi6210_pcm_platform.ops->trigger(substream, trigger_cmd);

    TEST_ASSERT(case_name, ret == 0)
    TEST_PASS(case_name)
}


static int pcm_debug_pointer(char* case_name, int pcm_device, int pcm_mode)
{
    struct snd_pcm_substream* substream;
    unsigned long ret = 0;
    substream = &pcm_debug.substream[pcm_device][pcm_mode];

    ret = hi6210_pcm_platform.ops->pointer(substream);

    TEST_ASSERT(case_name, ret == 0)
    TEST_PASS(case_name)
}


static ssize_t pcm_debug_read(struct file *file, char __user *user_buf,
				size_t count, loff_t *ppos)
{
    char *kn_buf = NULL;
    ssize_t byte_read = 0;

    if (NULL == user_buf) {
        pr_err("pcm_debug:input error: user_buf is NULL\n");
        return -EINVAL;
    }

    kn_buf = kmalloc((unsigned long)READ_BUF_LEN, GFP_KERNEL);
    if (NULL == kn_buf) {
        pr_err("pcm_debug:kn_buf is null\n");
        return -ENOMEM;
    }
    memset(kn_buf, 0, READ_BUF_LEN);

    byte_read  = snprintf(kn_buf, READ_BUF_LEN, "pcm debug interfaces\n");
    byte_read += snprintf(kn_buf + byte_read, (READ_BUF_LEN - strlen(kn_buf)), "echo case_name cmd pcm_device pcm_mode [param] > ...\n");
    byte_read += snprintf(kn_buf + byte_read, (READ_BUF_LEN - strlen(kn_buf)), "[cmd] 0x0:open 0x1:close 0x2:hw_params 0x3:free 0x4:prepare 0x5:trigger 0x6:pointer\n");
    byte_read += snprintf(kn_buf + byte_read, (READ_BUF_LEN - strlen(kn_buf)), "[pcm_device] 0x0:normal 0x05:hires 0x6:fast\n");
    byte_read += snprintf(kn_buf + byte_read, (READ_BUF_LEN - strlen(kn_buf)), "[pcm_mode] 0x0:playback 0x01:capture\n");
    byte_read += snprintf(kn_buf + byte_read, (READ_BUF_LEN - strlen(kn_buf)), "[param] cmd=hw_params,devices=hires and pcm_mode=playback , param: rate 0x0:48k 0x1:96k 0x2:192k\n");
    byte_read += snprintf(kn_buf + byte_read, (READ_BUF_LEN - strlen(kn_buf)), "\tcmd=hw_params and pcm_mode=capture, param: 0x1:1 channel, 0x2:2 channel\n");
    byte_read += snprintf(kn_buf + byte_read, (READ_BUF_LEN - strlen(kn_buf)), "\tcmd=trigger, param: 0x0:stop 0x1:start 0x3:pause_push 0x4:pause_release: 0x5:suspend 0x6:resume 0x7:drain\n");

    byte_read = simple_read_from_buffer(user_buf, count, ppos, kn_buf, strlen(kn_buf));

    kfree(kn_buf);
    kn_buf = NULL;

    return byte_read;
}

static int pcm_debug_write_check_param(const char __user *user_buf, size_t count, char* case_name,
                int* cmd, int* pcm_device, int* pcm_mode, int* param)
{
    int ret = 0;
    char cmd_buf[MAX_CMD_LEN] = {0};

    if (count > MAX_CMD_LEN) {
        pr_err("pcm_debug: user buffer is too long\n");
        return -EINVAL;
    }

    if (copy_from_user(cmd_buf, user_buf, count)) {
        pr_err("pcm_debug: user buffer is not completely copied\n");
        return -EINVAL;
    }

    ret = sscanf(cmd_buf, "%s 0x%x 0x%x 0x%x 0x%x", case_name, cmd, pcm_device, pcm_mode, param); /*[false alarm]:kernel no security function snscanf*/
    if (ret != 5 && ret != 4) {
        pr_err("pcm_debug: cmd_buf sscanf error");
        return -EINVAL;
    }

    pr_err("pcm_debug:[%s] <cmd>0x%x <pcm_device>0x%x <pcm_mode>0x%x <param>0x%x", case_name, *cmd, *pcm_device, *pcm_mode, *param);
    if (PCM_DEBUG_DEVICE_HIRES == *pcm_device && SNDRV_PCM_STREAM_CAPTURE == *pcm_mode) {
        pr_err("pcm_debug:[%s] - pcm_device and pcm_mode is error\n", case_name);
        return -EINVAL;
    }

    if (SNDRV_PCM_STREAM_CAPTURE != *pcm_mode && SNDRV_PCM_STREAM_PLAYBACK != *pcm_mode) {
        pr_err("pcm_debug:[%s] - pcm_mode is error\n", case_name);
        return -EINVAL;
    }

    return 0;
}
static ssize_t pcm_debug_write(struct file *file, const char __user *user_buf,
				size_t count, loff_t *ppos)
{
    char case_name[16] = {0};
    int  cmd = PCM_DEBUG_CMD_TOTAL;
    int  pcm_device = PCM_DEBUG_DEVICE_TOTAL;
    int  pcm_mode = ERROR_PCM_MODE;
    int  param = ERROR_PARAM;
    int  ret = 0;

    ret = pcm_debug_write_check_param(user_buf, count, case_name, &cmd, &pcm_device, &pcm_mode, &param);
    if (ret < 0)
        return ret;

    switch(cmd) {
    case PCM_DEBUG_OPEN:
        ret = pcm_debug_open(case_name, pcm_device, pcm_mode);
        break;
    case PCM_DEBUG_CLOSE:
        ret = pcm_debug_close(case_name, pcm_device, pcm_mode);
        break;
    case PCM_DEBUG_HW_PARAMS:
        pcm_debug_hw_params(case_name, pcm_device, pcm_mode, param);
        break;
    case PCM_DEBUG_FREE:
        ret = pcm_debug_free(case_name, pcm_device, pcm_mode);
        break;
    case PCM_DEBUG_PREPARE:
        ret = pcm_debug_prepare(case_name, pcm_device, pcm_mode);
        break;
    case PCM_DEBUG_TRIGGER:
        ret = pcm_debug_trigger(case_name, pcm_device, pcm_mode, param);
        break;
    case PCM_DEBUG_POINTER:
        ret = pcm_debug_pointer(case_name, pcm_device, pcm_mode);
        break;
    default :
        pr_err("pcm_debug:[%s] - cmd is error\n", case_name);
        ret = -EINVAL;
        break;
    }

    if (ret < 0)
        return ret;
    else
        return (ssize_t)count;
}


#ifdef CONFIG_HISI_DEBUG_FS
static const struct file_operations pcm_debug_fops = {
    .read = pcm_debug_read,
    .write = pcm_debug_write,
};
#endif

static int __init pcm_debug_init(void)
{
#ifdef CONFIG_HISI_DEBUG_FS
    pcm_debug.dentry = debugfs_create_dir("pcm_debug", NULL);
    if (!pcm_debug.dentry) {
        pr_err("create pcm debugfs dir\n");
        return -1;
    }

    if (!debugfs_create_file("interface", 0640, pcm_debug.dentry, NULL, &pcm_debug_fops)) {
        pr_err("create pcm debugfs rw\n");
        return -1;
    }
#endif
    return 0;
}

static void __exit pcm_debug_exit(void)
{
}


module_init(pcm_debug_init); /*lint !e528*/
module_exit(pcm_debug_exit); /*lint !e528*/

MODULE_AUTHOR("ShiWanlin <shiwanlin@huawei.com>");
MODULE_DESCRIPTION("PCM DEBUG DRIVER");
MODULE_LICENSE("GPL");

