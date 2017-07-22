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

#include <soc_acpu_baseaddr_interface.h>
#include <soc_crgperiph_interface.h>
#include <soc_sctrl_interface.h>


static char *autofsgt_sctrl_base = 0;
static char *autofsgt_pericrg_base = 0;

static unsigned long g_ddr_autofsgt_disable_flag = 0;
static unsigned long g_ddr_autofsgt_bypass_flag = 0;
static unsigned int g_ddr_autofsgt_sw = 1;
static struct semaphore ctrl_sem;



int ddr_autofsgt_bypass(int enable)
{
	if (enable) {
		writel(0x20002, SOC_CRGPERIPH_PEREN11_ADDR(autofsgt_pericrg_base));
	} else {
		writel(0x20000, SOC_CRGPERIPH_PERDIS11_ADDR(autofsgt_pericrg_base));
	}

	return 0;
}

int ddr_autofsgt_opt(unsigned int opt_cmd)
{
	switch (opt_cmd) {
	case DDR_AUTOFSGT_LOGIC_EN:
		ddr_autofsgt_bypass(0);
		break;

	case DDR_AUTOFSGT_LOGIC_DIS:
		ddr_autofsgt_bypass(1);
		break;
	default:
		return -EINVAL;

	}

	return 0;

}


/*s32 ddr_autofsgt_ctrl(DDR_AUTOFSGT_PROXY_CLIENT_ID client, DDR_AUTOFSGT_CMD_ID cmd)*/
int ddr_autofsgt_ctrl(unsigned int client, unsigned int cmd)
{
	int ret = 0;
	unsigned int opt_cmd = 0;

	down(&ctrl_sem);

	switch (cmd) {
	case DDR_AUTOFSGT_LOGIC_EN:
		/*no bypass*/
		opt_cmd = DDR_AUTOFSGT_LOGIC_EN;
		break;

	case DDR_AUTOFSGT_LOGIC_DIS:
		/*bypass*/
		opt_cmd = DDR_AUTOFSGT_LOGIC_DIS;
		break;
	default:
		up(&ctrl_sem);
		return -EINVAL;
	}

		ret = ddr_autofsgt_opt(opt_cmd);

		if (ret) {
			pr_err("[%s] opt_cmd err:[0x%x]\n", __func__, opt_cmd);
			up(&ctrl_sem);
			return -EINVAL;
		}

	up(&ctrl_sem);
	return 0;
}

static int __init ddr_autofsgt_proxy_init(void)
{
	sema_init(&ctrl_sem, 1);


	autofsgt_pericrg_base = (char *)ioremap((phys_addr_t)SOC_ACPU_PERI_CRG_BASE_ADDR, 0x1000);

	if (!autofsgt_pericrg_base) {
		return -ENOMEM;
	}

	return 0;
}

module_init(ddr_autofsgt_proxy_init);
