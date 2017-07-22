#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/mutex.h>
#include <linux/bitops.h>
#include <linux/of.h>
#include <linux/io.h>
#include <linux/semaphore.h>
#include <linux/printk.h>
#include "hisi_ddr_autofsgt_proxy_kernel.h"

/*FOR IPC*/
#include <linux/hisi/hisi_rproc.h>
#include <linux/hisi/ipc_msg.h>

/*FOR HWLOCK*/
#include  <linux/hwspinlock.h>
#include <soc_acpu_baseaddr_interface.h>
#include <soc_crgperiph_interface.h>
#include <soc_sctrl_interface.h>

#if defined (CONFIG_HI3660_DDR_AUTO_FSGT)

#undef CONFIG_HISI_DDR_AUTO_FSGT_IPC
#define CONFIG_HISI_DDR_AUTO_FSGT_HWLOCK


/*FOR HWLOCK*/
#define SCBAKDATA_MASK              (0xFFFF0000)
#define SCBAKDATA_BIT               (16 + DDR_AUTOFSGT_CLIENT_AP)
#define DDR_AUTOFSGT_LOCK_ID        (25)
#define DDR_AUTOFSGT_LOCK_TIMEOUT   (60000) /*60s*/
static struct hwspinlock *autofsgt_hwlock = 0;
static char *autofsgt_sctrl_base = 0;
static char *autofsgt_pericrg_base = 0;

static unsigned long g_ddr_autofsgt_disable_flag = 0;
static unsigned long g_ddr_autofsgt_bypass_flag = 0;
static unsigned int g_ddr_autofsgt_sw = 1;
static struct semaphore ctrl_sem;

#if defined (CONFIG_HISI_DDR_AUTO_FSGT_IPC)
int ddr_autofsgt_ipc_send(unsigned int opt_cmd)
{
	int ret = 0;
	union ipc_data msg = {0};
	union ipc_data ack = {0};
	/*send ipc*/
	(msg.cmd_mix).cmd_type = TYPE_CLK;
	(msg.cmd_mix).cmd = CMD_NOTIFY;
	(msg.cmd_mix).cmd_obj = OBJ_DDR;
	(msg.cmd_mix).cmd_src = OBJ_AP;
	(msg.cmd_mix).cmd_para[0] = DDR_AUTOFSGT_CLIENT_AP;
	(msg.cmd_mix).cmd_para[1] = opt_cmd;

	ret = RPROC_SYNC_SEND(HISI_RPROC_LPM3_MBX27,
						  (rproc_msg_t *)&msg,
						  (rproc_msg_len_t)2,
						  (rproc_msg_t *)&ack,
						  (rproc_msg_len_t)2);

	if (ret) {
		pr_err("[%s] send data err:[0x%x][0x%x]\n", __func__, msg.data[0], msg.data[1]);
		return -EINVAL;
	}

	if (ack.data[1]) {
		pr_err("[%s] recv err:[0x%x][0x%x]\n", __func__, ack.data[0], ack.data[1]);
		return -EINVAL;
	}

	return 0;

}
#endif

#if defined (CONFIG_HISI_DDR_AUTO_FSGT_HWLOCK)
int ddr_autofsgt_bypass(int enable)
{
	if (enable) {
		writel(0x40000000, SOC_CRGPERIPH_PEREN11_ADDR(autofsgt_pericrg_base));
	} else {
		writel(0x40000000, SOC_CRGPERIPH_PERDIS11_ADDR(autofsgt_pericrg_base));
	}

	return 0;
}
/*lint -save -e732 -e826 -e722 -e713*/
int ddr_autofsgt_hwlock_opt(unsigned int opt_cmd)
{
	unsigned int regval = 0;

	switch (opt_cmd) {
	case DDR_AUTOFSGT_LOGIC_EN:

		if (0 == hwspin_lock_timeout(autofsgt_hwlock, DDR_AUTOFSGT_LOCK_TIMEOUT)) {
			regval = readl(SOC_SCTRL_SCBAKDATA7_ADDR(autofsgt_sctrl_base));
			clear_bit(SCBAKDATA_BIT, (unsigned long *)&regval);
			writel(regval, SOC_SCTRL_SCBAKDATA7_ADDR(autofsgt_sctrl_base));

			if (!(regval & SCBAKDATA_MASK)) {
				ddr_autofsgt_bypass(0);
			}

			hwspin_unlock(autofsgt_hwlock);
		} else {
			while (1);
		}

		break;

	case DDR_AUTOFSGT_LOGIC_DIS:

		if (0 == hwspin_lock_timeout(autofsgt_hwlock, DDR_AUTOFSGT_LOCK_TIMEOUT)) {
			regval = readl(SOC_SCTRL_SCBAKDATA7_ADDR(autofsgt_sctrl_base));
			set_bit(SCBAKDATA_BIT, (unsigned long *)&regval);
			writel(regval, SOC_SCTRL_SCBAKDATA7_ADDR(autofsgt_sctrl_base));
			ddr_autofsgt_bypass(1);
			hwspin_unlock(autofsgt_hwlock);
		} else {
			while (1);
		}

		break;
	default:
		return -EINVAL;

	}

	return 0;
}

#endif


int ddr_autofsgt_opt(unsigned int opt_cmd)
{
#if defined (CONFIG_HISI_DDR_AUTO_FSGT_IPC)
	return ddr_autofsgt_ipc_send(opt_cmd);
#endif

#if defined (CONFIG_HISI_DDR_AUTO_FSGT_HWLOCK)
	return ddr_autofsgt_hwlock_opt(opt_cmd);
#endif
}


/*s32 ddr_autofsgt_ctrl(DDR_AUTOFSGT_PROXY_CLIENT_ID client, DDR_AUTOFSGT_CMD_ID cmd)*/
int ddr_autofsgt_ctrl(unsigned int client, unsigned int cmd)
{
	int ret = 0;
	unsigned int opt_cmd = 0;

	down(&ctrl_sem);

	switch (cmd) {
	case DDR_AUTOFSGT_ENABLE:
		clear_bit(client, &g_ddr_autofsgt_disable_flag);

		if (!g_ddr_autofsgt_disable_flag) {
			/*enable*/
			opt_cmd = DDR_AUTOFSGT_ENABLE;
		}

		break;

	case DDR_AUTOFSGT_DISABLE:

		if (!g_ddr_autofsgt_disable_flag) {
			/*disable*/
			opt_cmd = DDR_AUTOFSGT_DISABLE;
		}

		set_bit(client, &g_ddr_autofsgt_disable_flag);
		break;

	case DDR_AUTOFSGT_LOGIC_EN:
		clear_bit(client, &g_ddr_autofsgt_bypass_flag);

		if (!g_ddr_autofsgt_bypass_flag) {
			/*no bypass*/
			opt_cmd = DDR_AUTOFSGT_LOGIC_EN;
		}

		break;

	case DDR_AUTOFSGT_LOGIC_DIS:

		if (!g_ddr_autofsgt_bypass_flag) {
			/*bypass*/
			opt_cmd = DDR_AUTOFSGT_LOGIC_DIS;
		}

		set_bit(client, &g_ddr_autofsgt_bypass_flag);
		break;
	default:
		up(&ctrl_sem);
		return -EINVAL;
	}

	if (opt_cmd && g_ddr_autofsgt_sw) {
		ret = ddr_autofsgt_opt(opt_cmd);

		if (ret) {
			pr_err("[%s] opt_cmd err:[0x%x]\n", __func__, opt_cmd);
			up(&ctrl_sem);
			return -EINVAL;
		}
	}

	up(&ctrl_sem);
	return 0;
}
/*lint -restore*/
static int __init ddr_autofsgt_proxy_init(void)
{
	sema_init(&ctrl_sem, 1);
	g_ddr_autofsgt_sw = 1;

#if defined (CONFIG_HISI_DDR_AUTO_FSGT_HWLOCK)
	autofsgt_hwlock = hwspin_lock_request_specific(DDR_AUTOFSGT_LOCK_ID);

	if (!autofsgt_hwlock) {
		return -ENOMEM;
	}

	autofsgt_sctrl_base = (char *)ioremap((phys_addr_t)SOC_ACPU_SCTRL_BASE_ADDR, 0x1000UL);

	if (!autofsgt_sctrl_base) {
		return -ENOMEM;
	}

	autofsgt_pericrg_base = (char *)ioremap((phys_addr_t)SOC_ACPU_PERI_CRG_BASE_ADDR, 0x1000UL);

	if (!autofsgt_pericrg_base) {
		return -ENOMEM;
	}

#endif
	return 0;
}

#else

int ddr_autofsgt_ctrl(unsigned int client, unsigned int cmd)
{
	return 0;
}

static int __init ddr_autofsgt_proxy_init(void)
{
	return 0;
}

#endif

module_init(ddr_autofsgt_proxy_init);
