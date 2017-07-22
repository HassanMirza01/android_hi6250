/*
 * Histarisp rpmsg client driver
 *
 * Copyright (c) 2013- Hisilicon Technologies CO., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
/*lint -e666  -e529 -e438 -e713 -e715 -e559 -e626 -e719 -e846 -e514 -e778 -e866 -e84 -e437 -esym(666,*) -esym(529,*) -esym(438,*) -esym(713,*) -esym(715,*) -esym(559,*) -esym(626,*) -esym(719,*) -esym(846,*) -esym(514,*) -esym(778,*) -esym(866,*) -esym(84,*) -esym(437,*)*/
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/scatterlist.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/cdev.h>
#include <linux/jiffies.h>
#include <linux/mutex.h>
#include <linux/wait.h>
#include <linux/skbuff.h>
#include <linux/sched.h>
#include <linux/rpmsg.h>
#include <linux/completion.h>
#include <uapi/linux/histarisp.h>
#include <linux/platform_data/remoteproc-hisi.h>
#include <linux/ion.h>
#include <linux/hisi/hisi_ion.h>

static int debug_mask = 0x3;
module_param_named(debug_mask, debug_mask, int, S_IRUGO | S_IWUSR);
static int fast_boot_rtos = 0x1;
module_param_named(fast_boot_rtos, fast_boot_rtos, int, S_IRUGO | S_IWUSR);
#define rpmsg_err(fmt, args...) \
    do {                         \
        if (debug_mask & 0x01)   \
            printk(KERN_INFO "Rpmsg HISI Err: [%s] " fmt, __func__, ##args); \
    } while (0)
#define rpmsg_info(fmt, args...)  \
    do {                         \
        if (debug_mask & 0x02)   \
            printk(KERN_INFO "Rpmsg HISI Info: [%s] " fmt, __func__, ##args);  \
    } while (0)
#define rpmsg_dbg(fmt, args...)  \
    do {                         \
        if (debug_mask & 0x04) \
            printk(KERN_INFO "Rpmsg HISI Debug: [%s] " fmt, __func__, ##args); \
    } while (0)

#define RPMSG_MSG_SIZE          (496)

enum isp_rpmsg_state {
    RPMSG_UNCONNECTED,
    RPMSG_CONNECTED,
};

struct rpmsg_hisi_service {
    struct cdev *cdev;
    struct device *dev;
    struct rpmsg_channel *rpdev;
    struct list_head list;
    struct mutex lock;
};

struct rpmsg_hisi_instance {
    struct list_head node;
    struct rpmsg_hisi_service *hisi_serv;
    struct rpmsg_endpoint *ept;
    struct sk_buff_head queue;
    struct mutex lock;
    wait_queue_head_t readq;
	struct ion_client *client;
    void *rpmsg_msg;
    u32 dst;
    int state;
};

struct cdev_info {
    struct class *rpmsg_hisi_class;
    dev_t rpmsg_hisi_dev;
    struct cdev isp_cdev;
    struct device *isp_dev;
    int minor;
    int enable_rpmsg;
};
struct hisp_rpmsgrefs_s{
    atomic_t sendin_refs;
    atomic_t sendx_refs;
    unsigned long long sendx_last;
    atomic_t recvin_refs;
    atomic_t recvx_refs;
    atomic_t recvtask_refs;
    unsigned long long recvx_last;
}hisp_rpmsgrefs;
static DEFINE_MUTEX(hisi_rpmsg_service_mutex);
static DEFINE_MUTEX(hisi_rpmsg_send_mutex);

static struct cdev_info  cdev_local;
static struct rpmsg_hisi_service *hisi_isp_serv;
static atomic_t instances;

int rpmsg_client_debug = INVALID_CLIENT;
EXPORT_SYMBOL(rpmsg_client_debug);

static unsigned long long get_hisitime(void)
{
    return hisi_getcurtime();
}

static unsigned int reg_to_s(unsigned long long ts)
{
    return do_div(ts , 1000000000);
}

static unsigned int reg_to_us(unsigned long long ts)
{
    return do_div(ts ,1000);
}

void hisp_sendin(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    atomic_inc(&dev->sendin_refs);
}

void hisp_sendx(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    atomic_inc(&dev->sendx_refs);
    dev->sendx_last = get_hisitime();
}

void hisp_recvin(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    atomic_inc(&dev->recvin_refs);
}
void hisp_recvx(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    atomic_inc(&dev->recvx_refs);
    dev->recvx_last = get_hisitime();
}

void hisp_recvtask(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    atomic_inc(&dev->recvtask_refs);
}

void hisp_rpmsgrefs_dump(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    char time_log[80] = "";
    char *ptime_log;
    ptime_log = time_log;
    print_time(dev->sendx_last, ptime_log);
    pr_info("sendin_refs.0x%x, sendx_refs.0x%x, sendx_timer.%s\n", atomic_read(&dev->sendin_refs),atomic_read(&dev->sendx_refs),ptime_log);
    print_time(dev->recvx_last, ptime_log);
    pr_info("recvin_refs.0x%x, recvx_refs.0x%x, recvtask_refs.0x%x recvx_timer.%s\n", atomic_read(&dev->recvin_refs),atomic_read(&dev->recvx_refs),atomic_read(&dev->recvtask_refs),ptime_log);
}

void hisp_rpmsgrefs_reset(void)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    hisp_rpmsgrefs_dump();
    atomic_set(&dev->sendin_refs, 0);
    atomic_set(&dev->sendx_refs, 0);
    dev->sendx_last = 0;
    atomic_set(&dev->recvin_refs, 0);
    atomic_set(&dev->recvx_refs, 0);
    atomic_set(&dev->recvtask_refs, 0);
    dev->recvx_last = 0;
}

unsigned int __weak a7_mmu_map(struct scatterlist *sgl, unsigned int size, unsigned int prot, unsigned int flag)
{
    return 0;
}
void __weak a7_mmu_unmap(unsigned int va, unsigned int size)
{
    return;
}

static void rpmsg_hisi_cb(struct rpmsg_channel *rpdev, void *data, int len,
                            void *priv, u32 src)
{
    struct rpmsg_hisi_instance *ins = priv;
    struct sk_buff *skb;
    char *skbdata;
    struct rpmsg_hdr *rpmsg_msg;

    rpmsg_dbg("Enter ...\n");

    if (ins->state != RPMSG_CONNECTED) {
        /* get the remote address through the rpmsg_hdr */
        rpmsg_msg = container_of(data, struct rpmsg_hdr, data);
        rpmsg_dbg("msg src.%u, msg dst.%u \n", rpmsg_msg->src, rpmsg_msg->dst);

        /* add instance dst and modify the instance state */
        ins->dst = rpmsg_msg->src;
        ins->state = RPMSG_CONNECTED;
    }

    skb = alloc_skb(len, GFP_KERNEL);
    if (!skb) {
        rpmsg_err("alloc_skb err: %u\n", len);
        return ;
    }

    skbdata = skb_put(skb, len);
    memcpy(skbdata, data, len);

    /* add skb to skb_queue */
    mutex_lock(&ins->lock);
    skb_queue_tail(&ins->queue, skb);
    mutex_unlock(&ins->lock);

    /* wake up any blocking processes, waiting for new data */
    wake_up_interruptible(&ins->readq);

    rpmsg_dbg("Exit ...\n");
}

static int rproc_power_up(void)
{
    int ret = 0;

    rpmsg_info("Enter...\n");
    rpmsg_client_debug = ISP_DEBUG_RPMSG_CLIENT;

    ret = hisi_rproc_select_def();
    if (ret) {
        rpmsg_err("failed hisi_rproc_select_def.\n");
        return ret;
    }

    if ((ret = hisi_isp_rproc_enable()) != 0) {
        rpmsg_err("Failed:hisi_isp_rproc_enable.%d\n", ret);
        rpmsg_client_debug = INVALID_CLIENT;
        return ret;
    }

    ret = wait_for_completion_interruptible_timeout(&channel_sync, msecs_to_jiffies(1000000));
    if (0 == ret) {
        rpmsg_err("Failed: wait_for_completion_interruptible_timeout timed out, ret.%d", ret);
        hisi_isp_rproc_disable();
        rpmsg_client_debug = INVALID_CLIENT;
        return -ETIMEDOUT;
    } else if (0 > ret) {
        rpmsg_err("Failed: Interrupted, ret.%d.\n", ret);
        hisi_isp_rproc_disable();
        rpmsg_client_debug = INVALID_CLIENT;
        return -ERESTARTSYS;
    }

    rpmsg_info("Exit...\n");
    return 0;
}

static int rpmsg_hisi_open(struct inode *inode, struct file *filp)
{
    struct rpmsg_hisi_service *hisi_serv;
    struct rpmsg_hisi_instance *ins;
    char name[64];
    int ret;

    rpmsg_info("Enter...\n");

    if ( !cdev_local.enable_rpmsg ) {
        rpmsg_err("Failed : enable_rpmsg.%d\n", cdev_local.enable_rpmsg);
        return -ENODEV;
    }

    mutex_lock(&hisi_rpmsg_service_mutex);
    if ( (ret = hisi_isp_dependent_clock_enable()) < 0 ) {
		mutex_unlock(&hisi_rpmsg_service_mutex);
        rpmsg_err("Failed: hisi_isp_dependent_clock_enable.%d\n", ret);
        return ret;
    }

    if (!atomic_read(&instances)) {
        ret = rproc_power_up();
        if (ret) {
            rpmsg_err("power up failed.\n");
			goto pwrup_failure;
        }
    }

    ins = kzalloc(sizeof(*ins), GFP_KERNEL);
    if (!ins) {
        rpmsg_err("kzalloc ins failed.\n");
        goto ins_failure;
    }

    ins->rpmsg_msg = kzalloc(RPMSG_MSG_SIZE, GFP_KERNEL);
    if (!ins->rpmsg_msg) {
        rpmsg_err("kzalloc msg failed.\n");
        goto msg_failure;
    }

    hisi_serv = hisi_isp_serv;
    ins->hisi_serv = hisi_serv;
    ins->state = RPMSG_UNCONNECTED;

    /* assign a new, unique, local address and associate instance with it */
    ins->ept = rpmsg_create_ept(hisi_serv->rpdev, rpmsg_hisi_cb, ins,
                            RPMSG_ADDR_ANY);
    if (!ins->ept) {
        rpmsg_err("create ept failed\n");
        goto ept_failure;
    }

    /* create ion client for map */
    snprintf(name, 64, "%u", task_pid_nr(current->group_leader));
    ins->client = hisi_ion_client_create(name);
    if (IS_ERR_OR_NULL(ins->client)) {
        pr_err("[%s] Failed : ion_client_create.%s\n", __func__, name);
        goto create_failure;
    }

    /* the local addr */
    rpmsg_dbg("local addr assigned: %d\n", ins->ept->addr);

    mutex_init(&ins->lock);
    skb_queue_head_init(&ins->queue);
    init_waitqueue_head(&ins->readq);

    rpmsg_dbg("hisi_serv->rpdev:src.%d, dst.%d, ept.dst.%d \n",
                    hisi_serv->rpdev->src, hisi_serv->rpdev->dst, ins->ept->rpdev->dst);

    /* associate filp with the new instance */
    filp->private_data = ins;

    mutex_lock(&hisi_serv->lock);
    list_add(&ins->node, &hisi_serv->list);
    mutex_unlock(&hisi_serv->lock);

    atomic_inc(&instances);
    rpmsg_info("instances = %d\n", atomic_read(&instances));
    mutex_unlock(&hisi_rpmsg_service_mutex);

    rpmsg_info("Exit ...\n");
    return 0;

create_failure:
    rpmsg_destroy_ept(ins->ept);
    ins->ept = NULL;
ept_failure:
    kfree(ins->rpmsg_msg);
msg_failure:
    kfree(ins);
ins_failure:
    if (!atomic_read(&instances)) {
        hisi_isp_rproc_disable();
        rpmsg_client_debug = INVALID_CLIENT;
    }
pwrup_failure:
	hisi_isp_dependent_clock_disable();
    mutex_unlock(&hisi_rpmsg_service_mutex);

    rpmsg_err("open failed.\n");
    return -ENOMEM;
}

static int rpmsg_hisi_release(struct inode *inode, struct file *filp)
{
    struct rpmsg_hisi_instance *ins = filp->private_data;
    struct rpmsg_hisi_service *hisi_serv = ins->hisi_serv;
    int ret;

    rpmsg_info("Enter ...\n");

    /* destroy ept */
    if (ins->ept) {
        rpmsg_destroy_ept(ins->ept);
        ins->ept = NULL;
    }

    if (ins->client) {
        ion_client_destroy(ins->client);
        ins->client = NULL;
    }

    mutex_lock(&hisi_serv->lock);
    list_del(&ins->node);
    mutex_unlock(&hisi_serv->lock);

    kfree(ins->rpmsg_msg);
    kfree(ins);

	mutex_lock(&hisi_rpmsg_service_mutex);
    atomic_dec(&instances);
    rpmsg_info("ins_count = %d \n", atomic_read(&instances));

    if (fast_boot_rtos) {
        if (!atomic_read(&instances)) {
	        rpmsg_info("enter rproc disable.\n");

            ret = hisi_rproc_select_idle();
            if (ret)
                rpmsg_err("failed to hisi_rproc_select_idle.\n");

	        hisi_isp_rproc_disable();
			hisi_isp_dependent_clock_disable();
	        rpmsg_client_debug = INVALID_CLIENT;
    	}
    }
    mutex_unlock(&hisi_rpmsg_service_mutex);

    rpmsg_info("Exit ...\n");
    return 0;
}

static long rpmsg_hisi_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
#define SENSOR_NAME_SIZE (64)
    struct rpmsg_hisi_instance *ins = filp->private_data;
	rpmsg_ioctl_arg_t *uhdr = NULL;
	rpmsg_ioctl_arg_t info;
    char sensor_name[SENSOR_NAME_SIZE];
	int ret = 0;

    rpmsg_info("+ cmd.0x%x\n", cmd);

    switch(cmd) {
        case HISP_GET_MAPBUFFER: {
			map_hisp_cfg_data_t *pcfg = NULL;
			map_hisp_cfg_data_t cfg;
			struct ion_handle* hdl = NULL;
			struct sg_table *table;
			struct scatterlist *sg;

			if (0 == arg) {
				pr_err("[%s] arg.0x%lx\n", __func__, arg);
				return -1;
			}
		    if ((pcfg = (void __user *)arg) == NULL) {
				pr_err("[%s] Failed : mapbuf.(0x%p = 0x%lx)\n", __func__, pcfg, arg);
				return -EINVAL;
			}

            if ((ret = copy_from_user(&cfg, pcfg, sizeof(cfg))) < 0) {
                rpmsg_err("[%s] Failed : copy_from_user.%d\n", __func__, ret);
                return -EFAULT;
            }

			pr_err("cfg  sharefd = 0x%x, size = 0x%x, prot = %x, type = 0x%x\n",
                    cfg.param.sharefd, cfg.param.size, cfg.param.prot, cfg.param.type);

			hdl = ion_import_dma_buf(ins->client, cfg.param.sharefd);
			if (IS_ERR_OR_NULL(hdl)) {
				pr_err("[%s] Failed : ion_import_dma_buf\n", __func__);
				return -1;
			}

			table = ion_sg_table(ins->client, hdl);
			sg = table->sgl;

			cfg.param.moduleaddr = a7_mmu_map(sg, cfg.param.size, cfg.param.prot, cfg.param.type);

			if ((ret = copy_to_user((void __user *)arg, (const void *)&cfg, sizeof(cfg))) < 0) {
                pr_err("[%s] Failed : copy_to_user.%d.(0x%lx, 0x%x, 0x%x)\n", __func__, ret, arg, cfg.param.moduleaddr, cfg.param.size);
                return -EFAULT;
            }
			break;
		}
        case HISP_UNMAP_BUFFER: {
			map_hisp_cfg_data_t cfg;
			map_hisp_cfg_data_t *pcfg = NULL;
            pr_info("%s: HISP_UNMAP_BUFFER.\n", __func__);
			if (0 == arg) {
				pr_err("[%s] arg.0x%lx\n", __func__, arg);
				return -1;
			}

		    if ((pcfg = (void __user *)arg) == NULL) {
				pr_err("[%s] Failed : mapbuf.(0x%p = 0x%lx)\n", __func__, pcfg, arg);
				return -EINVAL;
			}

            if ((ret = copy_from_user(&cfg, pcfg, sizeof(cfg))) < 0) {
                rpmsg_err("[%s] Failed : copy_from_user.%d\n", __func__, ret);
                return -EFAULT;
            }
            a7_mmu_unmap(cfg.param.moduleaddr, cfg.param.size);

            break;
        }
        default:
		    if ((uhdr = (void __user *)arg) == NULL) {
				pr_err("[%s] Failed : mapbuf.(0x%p = 0x%lx)\n", __func__, uhdr, arg);
				return -EINVAL;
			}

            if ((ret = copy_from_user(&info, uhdr, sizeof(info))) < 0) {
        		rpmsg_err("[%s] Failed : copy_from_user.%d\n", __func__, ret);
        		return -EFAULT;
            }


            memset(sensor_name, '\0', SENSOR_NAME_SIZE);/*lint !e747 */
            memcpy(sensor_name, info.name, ((strlen(info.name) > SENSOR_NAME_SIZE) ? SENSOR_NAME_SIZE : strlen(info.name)));/*lint !e670 */
            sensor_name[SENSOR_NAME_SIZE -1] = '\0';
            rpmsg_info("info.index = %d, info.name = %s\n", info.index, sensor_name);
            if ((ret = rpmsg_sensor_ioctl(cmd, info.index, sensor_name)) < 0) {
        		rpmsg_info("[%s] Failed : rpmsg_sensor_ioctl.%d\n", __func__, ret);
				return ret;
			}
            break;
    }

	rpmsg_info("- cmd.0x%x\n", cmd);

    return 0;
}

static ssize_t rpmsg_hisi_read(struct file *filp, char __user *buf,
                        size_t len, loff_t *offp)
{
    struct rpmsg_hisi_instance *ins = filp->private_data;
    struct sk_buff *skb;
    int use;

    rpmsg_dbg("Enter ...\n");

    if (mutex_lock_interruptible(&ins->lock))
        return -ERESTARTSYS;

    /* check if skb_queue is NULL ?*/
    if (skb_queue_empty(&ins->queue)) {
        mutex_unlock(&ins->lock);
        /* non-blocking requested ? return now */
        if (filp->f_flags & O_NONBLOCK)
            return -EAGAIN;

        /* otherwise block, and wait for data */
        if (wait_event_interruptible(ins->readq,
                            (!skb_queue_empty(&ins->queue))))
            return -ERESTARTSYS;

        if (mutex_lock_interruptible(&ins->lock))
            return -ERESTARTSYS;
    }

    skb = skb_dequeue(&ins->queue);
    if (!skb) {
        mutex_unlock(&ins->lock);
        rpmsg_err("skb_dequeue failed.\n");
        return -EIO;
    }

    mutex_unlock(&ins->lock);

    use = min((unsigned int)len, skb->len);
    if (copy_to_user(buf, skb->data, use)) {
        rpmsg_err("copy_to_user fail.\n");
        use = -EFAULT;
    }

    kfree_skb(skb);

    rpmsg_dbg("Exit ...\n");
    return use;
}

static
int rpmsg_send_single_to_connect(struct rpmsg_hisi_instance *ins, void *data, unsigned int len)
{
    struct rpmsg_hisi_service *hisi_serv = ins->hisi_serv;
    int ret;
    rpmsg_dbg("Enter...\n");

    rpmsg_dbg("%s:before single send, src.%d, dst.%d \n",
                                        __func__, ins->ept->addr, hisi_serv->rpdev->dst);

    ret = rpmsg_send_offchannel(hisi_serv->rpdev, ins->ept->addr,
            hisi_serv->rpdev->dst, data, len);
    if (ret) {
        rpmsg_err("rpmsg_send failed: %d\n", ret);
        return ret;
    }

    rpmsg_dbg("Exit...\n");
    return 0;
}

static ssize_t rpmsg_hisi_write(struct file *filp, const char __user *ubuf,
                        size_t len, loff_t *offp)
{
    struct rpmsg_hisi_instance *ins = filp->private_data;
    struct rpmsg_hisi_service *hisi_serv = ins->hisi_serv;
    void *msg_buf = ins->rpmsg_msg;
    int use, ret;

    rpmsg_dbg("Enter ...\n");

    if (ubuf == NULL)
        return -EINVAL;

    /* for now, limit msg size to 512 bytes */
    use = min((unsigned int)RPMSG_MSG_SIZE, (unsigned int)len);
    if (copy_from_user(msg_buf, ubuf, use))
        return -EMSGSIZE;

    /* if the msg is first msg, we will send it by the special function to connect*/
    if (ins->state != RPMSG_CONNECTED) {
        ret = rpmsg_send_single_to_connect(ins, msg_buf, use);
        if (ret) {
            rpmsg_err("rpmsg send single failed: %d\n", ret);
            return ret;
        }
        return use;
    }

    rpmsg_dbg("%s:before send, src.%d, dst.%d \n", __func__, ins->ept->addr, ins->dst);

    mutex_lock(&hisi_rpmsg_send_mutex);
    /* here, in debug stage, we need to do something for the msg */
    ret = rpmsg_send_offchannel(hisi_serv->rpdev, ins->ept->addr,
                        ins->dst, msg_buf, use);
    if (ret) {
        rpmsg_err("rpmsg_send failed: %d\n", ret);
        mutex_unlock(&hisi_rpmsg_send_mutex);
        return ret;
    }

    mutex_unlock(&hisi_rpmsg_send_mutex);
    rpmsg_dbg("Exit ...\n");
    return use;
}

static
unsigned int rpmsg_hisi_poll(struct file *filp, struct poll_table_struct *wait)
{
    struct rpmsg_hisi_instance *ins = filp->private_data;
    unsigned int mask = 0;

    rpmsg_dbg("Enter ...\n");
    if (mutex_lock_interruptible(&ins->lock))
        return -ERESTARTSYS;

    poll_wait(filp, &ins->readq, wait);
    if (!skb_queue_empty(&ins->queue))
        mask |= POLLIN | POLLRDNORM;

    if (true)
        mask |= POLLOUT | POLLWRNORM;

    mutex_unlock(&ins->lock);

    rpmsg_dbg("Exit ...\n");
    return mask;
}

static const struct file_operations rpmsg_hisi_fops = {
    .open           = rpmsg_hisi_open,
    .release        = rpmsg_hisi_release,
    .unlocked_ioctl = rpmsg_hisi_ioctl,
    .compat_ioctl   = rpmsg_hisi_ioctl,
    .read           = rpmsg_hisi_read,
    .write          = rpmsg_hisi_write,
    .poll           = rpmsg_hisi_poll,
    .owner          = THIS_MODULE,
};

static int rpmsg_hisi_probe(struct rpmsg_channel *rpdev)
{
    struct rpmsg_hisi_service *hisi_serv = NULL;

    hisi_serv = kzalloc(sizeof(*hisi_serv), GFP_KERNEL);
    if (!hisi_serv) {
        rpmsg_err("kzalloc failed\n");
        return -ENOMEM;
    }

    INIT_LIST_HEAD(&hisi_serv->list);
    mutex_init(&hisi_serv->lock);

    hisi_serv->cdev = &cdev_local.isp_cdev;
    hisi_serv->dev = cdev_local.isp_dev;
    hisi_isp_serv = hisi_serv;

    hisi_serv->rpdev = rpdev;

    dev_set_drvdata(&rpdev->dev, hisi_serv);

    rpmsg_info("new HISI connection srv channel: %u -> %u!\n",
                        rpdev->src, rpdev->dst);

    rpmsg_dbg("Exit ...\n");
    return 0;
}

static void rpmsg_hisi_remove(struct rpmsg_channel *rpdev)
{
    struct rpmsg_hisi_service *hisi_serv = dev_get_drvdata(&rpdev->dev);

    /* check list */

    mutex_lock(&hisi_serv->lock);
    if (list_empty(&hisi_serv->list)) {
        mutex_unlock(&hisi_serv->lock);
        kfree(hisi_serv);
        hisi_serv = NULL;

        rpmsg_info("hisi_serv->list is empty, instances = %d.\n", atomic_read(&instances));
    } else {
        mutex_unlock(&hisi_serv->lock);
        /* Maybe here need to debug, in case more exception case */
        rpmsg_err("rpmsg remove exception, instances = %d \n", atomic_read(&instances));
        WARN_ON(1);
    }

    rpmsg_info("Exit ...\n");
    return;
}

static void rpmsg_hisi_driver_cb(struct rpmsg_channel *rpdev, void *data,
                        int len, void *priv, u32 src)
{
    rpmsg_dbg("Enter ...\n");
    dev_warn(&rpdev->dev, "uhm, unexpected message\n");

    print_hex_dump(KERN_DEBUG, __func__, DUMP_PREFIX_NONE, 16, 1,
               data, len,  true);
    rpmsg_dbg("Exit ...\n");
}

static struct rpmsg_device_id rpmsg_hisi_id_table[] = {
    { .name    = "rpmsg-isp-debug" },
    { },
};
MODULE_DEVICE_TABLE(platform, rpmsg_hisi_id_table);

static struct rpmsg_driver rpmsg_hisi_driver = {
    .drv.name   = KBUILD_MODNAME,
    .drv.owner  = THIS_MODULE,
    .id_table   = rpmsg_hisi_id_table,
    .probe      = rpmsg_hisi_probe,
    .callback   = rpmsg_hisi_driver_cb,
    .remove     = rpmsg_hisi_remove,
};

static ssize_t rpmsgctrl_show(struct device *pdev, struct device_attribute *attr,
			char *buf)
{
	char *s = buf;
	s += sprintf(s, "rpmsg device %s\n", (cdev_local.enable_rpmsg == 0 ? "Disabled" : "Enabled"));
	return (s - buf);
}

static ssize_t rpmsgctrl_store(struct device *pdev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
    char *p;
    int len;

    p = memchr(buf, '\n', count);
    len = p ? p - buf : count;

	if ( !strncmp(buf, "enable", len) ) {
		cdev_local.enable_rpmsg = 1;
	} else if ( !strncmp(buf, "disable", len) ) {
		cdev_local.enable_rpmsg = 0;
	} else if ( !strncmp(buf, "dumpregs", len) ) {
        hisi_isp_boot_stat_dump();
	} else {
		printk("<Usage: > echo enable/disable > rpmsgctrl\n");
	}

	return count;
}

static ssize_t rpmsgrefs_show(struct device *pdev, struct device_attribute *attr,
                    char *buf)
{
    struct hisp_rpmsgrefs_s *dev = (struct hisp_rpmsgrefs_s *)&hisp_rpmsgrefs;
    char *s = buf;

    s += sprintf(s, "%s send.(0x%x, 0x%x, [%05u.%06u]), recv.(0x%x, 0x%x, [%05u.%06u])\n", "hisp_rpmsgrefs", atomic_read(&dev->sendin_refs),
            atomic_read(&dev->sendx_refs), reg_to_s(dev->sendx_last), reg_to_us(dev->sendx_last), atomic_read(&dev->recvin_refs),
            atomic_read(&dev->recvx_refs), reg_to_s(dev->recvx_last), reg_to_us(dev->recvx_last));
    return (s - buf);
}

static ssize_t rpmsgrefs_store(struct device *pdev, struct device_attribute *attr,
                     const char *buf, size_t count)
{
    return count;
}

static DEVICE_ATTR(rpmsgctrl, (S_IRUGO | S_IWUSR | S_IWGRP), rpmsgctrl_show, rpmsgctrl_store);
static DEVICE_ATTR(rpmsgrefs, (S_IRUGO | S_IWUSR | S_IWGRP), rpmsgrefs_show, rpmsgrefs_store);

static int __init rpmsg_hisi_init(void)
{
    int ret, major;

    rpmsg_dbg("Enter ...\n");

    cdev_local.minor = 0;
    atomic_set(&instances, 0);

    ret = alloc_chrdev_region(&cdev_local.rpmsg_hisi_dev, 0, 1,
                            KBUILD_MODNAME);
    if (ret) {
        pr_err("alloc_chrdev_region failed: %d\n", ret);
        goto out;
    }

    cdev_local.rpmsg_hisi_class = class_create(THIS_MODULE, KBUILD_MODNAME);
    if (IS_ERR(cdev_local.rpmsg_hisi_class)) {
        ret = PTR_ERR(cdev_local.rpmsg_hisi_class);
        pr_err("class_create failed: %d\n", ret);
        goto unreg_region;
    }

    major = MAJOR(cdev_local.rpmsg_hisi_dev);
    rpmsg_dbg("cdev_local.rpmsg_hisi_dev major.%u \n", (unsigned int)major);

    cdev_init(&cdev_local.isp_cdev, &rpmsg_hisi_fops);
    rpmsg_dbg("hisi_serv->cdev.%p\n", &cdev_local.isp_cdev);

    cdev_local.isp_cdev.owner = THIS_MODULE;
    ret = cdev_add(&cdev_local.isp_cdev, MKDEV(major, cdev_local.minor), 1);
    if (ret) {
        rpmsg_err("cdev_add failed: %d\n", ret);
        goto destroy_class;
    }

    cdev_local.isp_dev = device_create(cdev_local.rpmsg_hisi_class, NULL,
                                    MKDEV(major, cdev_local.minor), NULL,
                                    "rpmsg-hisi%d", cdev_local.minor);
    if (IS_ERR(cdev_local.isp_dev)) {
        ret = PTR_ERR(cdev_local.isp_dev);
        rpmsg_dbg("device_create failed: %d\n", ret);
        goto clean_cdev;
    }

	if ( device_create_file(cdev_local.isp_dev, &dev_attr_rpmsgctrl) < 0 )
		rpmsg_err("Failed : device_create_file");

	cdev_local.enable_rpmsg = 0;

    if ( device_create_file(cdev_local.isp_dev, &dev_attr_rpmsgrefs) < 0 )
        rpmsg_err("Failed : device_create_file");

    return register_rpmsg_driver(&rpmsg_hisi_driver);

clean_cdev:
    cdev_del(&cdev_local.isp_cdev);
destroy_class:
    class_destroy(cdev_local.rpmsg_hisi_class);
unreg_region:
    unregister_chrdev_region(cdev_local.rpmsg_hisi_dev, 1);
out:
    rpmsg_dbg("Exit ...\n");
    return ret;
}
module_init(rpmsg_hisi_init);

static void __exit rpmsg_hisi_exit(void)
{
    int major = MAJOR(cdev_local.rpmsg_hisi_dev);

    rpmsg_dbg("Enter ...\n");
    unregister_rpmsg_driver(&rpmsg_hisi_driver);
    device_destroy(cdev_local.rpmsg_hisi_class, MKDEV(major, cdev_local.minor));
    cdev_del(&cdev_local.isp_cdev);
    class_destroy(cdev_local.rpmsg_hisi_class);
    unregister_chrdev_region(cdev_local.rpmsg_hisi_dev, 1);
    rpmsg_dbg("Exit ...\n");
}
module_exit(rpmsg_hisi_exit);

MODULE_DESCRIPTION("HISI offloading rpmsg driver");
MODULE_LICENSE("GPL v2");
