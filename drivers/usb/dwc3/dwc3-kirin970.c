#include <linux/module.h>
#include <linux/of.h>
#include <linux/io.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <pmic_interface.h>
#include <linux/mfd/hisi_pmic.h>
#include "dwc3-hisi.h"

/*lint -e750 -esym(750,*)*/
/* clk module will round to 228M */
#define USB3OTG_ACLK_FREQ		229000000

#define IP_RST_USB3OTG_MISC				(1 << 7)
#define SCTRL_SCDEEPSLEEPED				0x08
#define USB_REFCLK_ISO_EN               (1 << 25)
#define PCTRL_PERI_CTRL3                0x10
#define USB_TCXO_EN						(1 << 1)
#define PERI_CTRL3_MSK_START            (16)
#define SC_CLK_USB3PHY_3MUX1_SEL        (1 << 25)

#define SC_SEL_ABB_BACKUP               (1 << 8)
#define CLKDIV_MASK_START               (16)

#define PERI_CRG_CLKDIV21               0xFC

#define GT_CLK_ABB_BACKUP               (1 << 22)
#define PERI_CRG_CLK_DIS5               0x54

#define PMC_PPLL3CTRL0                  0x048
#define PPLL3_FBDIV_START               (8)
#define PPLL3_EN                        (1 << 0)
#define PPLL3_BP                        (1 << 1)
#define PPLL3_LOCK                      (1 << 26)
#define GT_CLK_USB2PHY_REF				(1 << 19)

#define PMC_PPLL3CTRL1                  0x04C
#define PPLL3_INT_MOD                   (1 << 24)
#define GT_CLK_PPLL3                    (1 << 26)

#define PERI_CRG_CLK_EN5                0x50
#define PERI_CRG_PEREN6 0x410
#define PERI_CRG_PERDIS6 0x414
#define PERI_CRG_PERRSTEN4 0x90
#define PERI_CRG_PEREN0 0x00
#define PERI_CRG_PEREN4 0x40
#define PERI_CRG_PERRSTDIS4 0x94
#define PERI_CRG_PERDIS0 0x04

#define SC_USB3PHY_ABB_GT_EN            (1 << 15)
#define REF_SSP_EN                      (1 << 16)
/*lint -e750 +esym(750,*)*/

int hisi_usb_vbus_value(void)
{
	unsigned long base = 0;
	/*lint -e747 -e712*/
	unsigned int pmic_status0 = hisi_pmic_reg_read(PMIC_STATUS0_ADDR(base));
	/*lint +e747 +e712*/
	return !!(pmic_status0 & (1 << 1));
}

/* usb3 misc ctrl driver */
void __iomem *reg_base_usb_misc_ctrl;
static inline void set_misc_base_addr(void __iomem *base)
{
	printk(KERN_ERR "[USB.DBG]:misc base:%pK\n", base);
	reg_base_usb_misc_ctrl = base;
}

/*lint -e528 -esym(528,*)*/
static inline void __iomem *get_misc_base_addr(void)
{
	return reg_base_usb_misc_ctrl;
}
/*lint -e528 +esym(528,*)*/

/*lint -e715 -e716 -e717 -e835 -e838 -e845 -e533 -e835 -e778 -e774 -e747 -e785 -e438 -e529*/
void usb3_misc_reg_writel(u32 val, unsigned long int misc_offset)
{
	writel(val, (get_misc_base_addr() + misc_offset));
}

u32 usb3_misc_reg_readl(unsigned long int misc_offset)
{
	return  readl(get_misc_base_addr() + misc_offset);
}

void usb3_misc_reg_setbit(u32 bit, unsigned long int misc_offset)
{
	volatile uint32_t temp;
	temp = usb3_misc_reg_readl(misc_offset);
	temp |= (1u << bit);
	usb3_misc_reg_writel(temp, misc_offset);
}

void usb3_misc_reg_clrbit(u32 bit, unsigned long int misc_offset)
{
	volatile uint32_t temp;
	temp = usb3_misc_reg_readl(misc_offset);
	temp &= ~(1u << bit);
	usb3_misc_reg_writel(temp, misc_offset);
}

void usb3_misc_reg_setvalue(u32 value, unsigned long int misc_offset)
{
	volatile uint32_t temp;
	temp = usb3_misc_reg_readl(misc_offset);
	temp |= value;
	usb3_misc_reg_writel(temp, misc_offset);
}

void usb3_misc_reg_clrvalue(u32 value, unsigned long int misc_offset)
{
	volatile uint32_t temp;
	temp = usb3_misc_reg_readl(misc_offset);
	temp &= value;
	usb3_misc_reg_writel(temp, misc_offset);
}

/* usb3 misc ctrl driver */

#define SET_NBITS_MASK(start, end) (((2u << ((end) - (start))) - 1) << (start))

int config_usb_phy_controller(void)
{
	volatile uint32_t temp;
	/* Release USB20 PHY out of IDDQ mode */
	usb3_misc_reg_clrbit(0u, 0x14ul);

	/* Release USB31 PHY out of  TestPowerDown mode */
	usb3_misc_reg_clrbit(23u, 0x50ul);

	/* Tell the PHY power is stable */
	usb3_misc_reg_setvalue((1u << 1) | (1u << 9) | (1u << 11), 0x54ul);


	/*
	 * config the TCA mux mode
	 * register:
	 *      -- 0x204 0x208: write immediately
	 *      -- 0x200 0x210 0x214 0x240: read-update-write
	 */

	usb3_misc_reg_writel(0xffffu, 0x208ul);
	usb3_misc_reg_writel(0x3u, 0x204ul);

	usb3_misc_reg_clrvalue(~SET_NBITS_MASK(0, 1), 0x200ul);
	usb3_misc_reg_setbit(4u, 0x210ul);

	temp = usb3_misc_reg_readl(0x214);
	temp &= ~(SET_NBITS_MASK(0, 1) | SET_NBITS_MASK(3, 4));
	temp |= (0x1 | (0x2 << 3));
	usb3_misc_reg_writel(temp, 0x214);

	usb3_misc_reg_setvalue(0x3u | (0x3u << 2), 0x240ul);

	return 0;
}

static uint32_t is_abb_clk_selected(void __iomem *sctrl_base)
{
	volatile uint32_t scdeepsleeped;

	if(!sctrl_base) {
		usb_err("sctrl_base is NULL!\n");
		return 1;
	}

	scdeepsleeped = (uint32_t)readl(SCTRL_SCDEEPSLEEPED + sctrl_base);
	if ((scdeepsleeped & (1 << 20)) == 0)
		return 1;

	return 0;
}


static int set_usb_phy_clk(struct hisi_dwc3_device *hisi_dwc3)
{
/*lint -save -e550 */
	void __iomem *pericfg_base = hisi_dwc3->pericfg_reg_base;/*lint !e438 */
	void __iomem *pctrl_base = hisi_dwc3->pctrl_reg_base;/*lint !e438 */
	void __iomem *sctrl_base = hisi_dwc3->sctrl_reg_base;
#define USB_CLK_TYPE_ABB (0xabb)
#define USB_CLK_TYPE_PAD (0x10ad)
	volatile uint32_t temp;
	int ret;
	int clk_type = USB_CLK_TYPE_ABB;

	if (is_abb_clk_selected(sctrl_base)) {
		/* usb refclk iso enable */
		writel(USB_REFCLK_ISO_EN, PERI_CRG_ISODIS + pericfg_base);

		/* enable usb_tcxo_en */
		writel(USB_TCXO_EN | (USB_TCXO_EN << PERI_CTRL3_MSK_START),
				PCTRL_PERI_CTRL3 + pctrl_base);
		ret = clk_prepare_enable(hisi_dwc3->gt_clk_usb3_tcxo_en);
		if (ret) {
			usb_err("clk_prepare_enable gt_clk_usb3_tcxo_en failed\n");
			return ret;
		}

		mdelay(10);

		/* select usbphy clk from abb */
		temp = (uint32_t)readl(pctrl_base + PCTRL_PERI_CTRL24);
		temp &= ~SC_CLK_USB3PHY_3MUX1_SEL;
		writel(temp, pctrl_base + PCTRL_PERI_CTRL24);

		usb3_misc_reg_clrbit(4, 0xa0);

		usb3_misc_reg_setvalue((SET_NBITS_MASK(3, 4)), 0x1c);
	} else {
		/* select usbphy clk from pad */
		usb3_misc_reg_setbit(12, 0x54);

		usb3_misc_reg_setbit(4, 0xa0);

		temp = usb3_misc_reg_readl(0x1c);
		temp &= ~(SET_NBITS_MASK(3, 4));
		temp |= (0x2 << 3);
		usb3_misc_reg_writel(temp, 0x1cul);

		writel(GT_CLK_USB2PHY_REF, PERI_CRG_PEREN6 + pericfg_base);
		ret = clk_prepare_enable(hisi_dwc3->gt_clk_usb2phy_ref);
		if (ret) {
			usb_err("clk_prepare_enable gt_clk_usb2phy_ref failed\n");
			return ret;
		}


		clk_type = USB_CLK_TYPE_PAD;
	}

	return clk_type;
/*lint -restore */
}

static void set_gpio_if_fpga(struct hisi_dwc3_device *hisi_dwc3)
{
	if (hisi_dwc3->fpga_flag != 0) {
		if(gpio_request(15, "usb_fpga")) {
			usb_err("request gpio error!\n");
		}

		gpio_direction_output(15, 1);
		udelay(100);

		gpio_direction_output(15, 0);
		udelay(100);
	}
}

static void dwc3_release(struct hisi_dwc3_device *hisi_dwc3)
{
	int ret;
	void __iomem *pericfg_base = hisi_dwc3->pericfg_reg_base;/*lint !e529 */
	void __iomem *otg_bc_base = hisi_dwc3->otg_bc_reg_base;
	int clk_type = 0xabb;

	set_misc_base_addr(otg_bc_base);

	/* make sure at reset status */
	writel(IP_RST_USB3OTG_MISC | IP_RST_USB3OTG_32K, pericfg_base + PERI_CRG_PERRSTEN4);
	udelay(100);

	/* open hclk gate */
	writel(GT_HCLK_USB3OTG_MISC, pericfg_base + PERI_CRG_PEREN0);
	ret = clk_prepare_enable(hisi_dwc3->gt_hclk_usb3otg);
	if (ret) {
		usb_err("clk_enable gt_hclk_usb3otg failed\n");
		return;
	}

	/* open misc clk gate */
	ret = clk_prepare_enable(hisi_dwc3->gt_aclk_usb3otg);
	if (ret) {
		usb_err("clk_prepare_enable gt_aclk_usb3otg failed\n");
		return;
	}

	ret = clk_prepare_enable(hisi_dwc3->clk);
	if (ret) {
		usb_err("clk_prepare_enable clk failed\n");
		return;
	}
	writel(GT_CLK_USB3OTG_REF | GT_ACLK_USB3OTG, pericfg_base + PERI_CRG_PEREN4); /* make sure open clk */

	/* dis-reset usb misc ctrl module */
	writel(IP_RST_USB3OTG_MISC | IP_RST_USB3OTG_32K, pericfg_base + PERI_CRG_PERRSTDIS4);

	clk_type = set_usb_phy_clk(hisi_dwc3);
	if(clk_type) {
		usb_err("usb clk type:%x\n", clk_type);
	}

	config_usb_phy_controller();

	/* unreset phy */
	usb3_misc_reg_setvalue(SET_NBITS_MASK(0, 1), 0xa0);
	udelay(100);
	set_gpio_if_fpga(hisi_dwc3);

	/* unreset controller */
	usb3_misc_reg_setvalue(SET_NBITS_MASK(8, 9), 0xa0);
	udelay(100);

	/* set vbus valid */
	usb3_misc_reg_setvalue(SET_NBITS_MASK(6, 7), 0x0);
	usb3_misc_reg_setvalue(SET_NBITS_MASK(5, 6), 0xc);

	/* require to delay 10us */
	udelay(100);
}

int usb3_misc_ctrl_is_unreset(void __iomem *pericfg_base)
{
	volatile uint32_t regval;
#define PERI_CRG_PERRSTSTAT4  0x98
	regval = (uint32_t)readl(PERI_CRG_PERRSTSTAT4 + pericfg_base);
	return !((IP_RST_USB3OTG_MISC | IP_RST_USB3OTG_32K) & regval);
}

int usb3_clk_is_open(void __iomem *pericfg_base)
{
	volatile uint32_t hclk, aclk;
	uint32_t hclk_mask = GT_HCLK_USB3OTG_MISC;
	uint32_t aclk_mask = (GT_CLK_USB3OTG_REF | GT_ACLK_USB3OTG);

#define PERI_CRG_PERSTAT0 0x0c
#define PERI_CRG_PERSTAT4 0x4c
	hclk = (uint32_t)readl(PERI_CRG_PERSTAT0 + pericfg_base);
	aclk = (uint32_t)readl(PERI_CRG_PERSTAT4 + pericfg_base);

	return (   ((aclk_mask & aclk) == aclk_mask)
		&& ((hclk_mask & hclk) == hclk_mask) );
}

int usb3_phy_controller_is_reset(void)
{
	volatile uint32_t stat;
	uint32_t bitmask = (SET_NBITS_MASK(8, 9) | SET_NBITS_MASK(0,1));

	stat = usb3_misc_reg_readl(0xa0);

	return ((bitmask & stat) == bitmask);
}

void usb3_core_wait_for_idle(void)
{
#if 0
	This func have some proble.
	volatile uint32_t temp_t;
	int i = 0;

	/* check dev_global_regs */
	temp_t = usb3_rd32(&dev_global_regs->dctl);
	temp_t &= ~USB3_DCTL_RUN_STOP_BIT;
	usb3_wr32(&dev_global_regs->dctl, temp_t);

	/* handle all pending event */
	usb3_dis_flush_eventbuf_intr(dev);

	/* timeout 1ms */
	i = 0;
	do {
		udelay(100);
		temp_t = usb3_rd32(&dev_global_regs->dsts);
		if(10 == i) {
			break;
		}
		i++;
	} while(!(temp_t & USB3_DSTS_DEV_CTRL_HLT_BIT));

	udelay(100);
#endif
}

static void dwc3_reset(struct hisi_dwc3_device *hisi_dwc3)
{
	void __iomem *pericfg_base = hisi_dwc3->pericfg_reg_base;
	void __iomem *sctrl_base = hisi_dwc3->sctrl_reg_base;
/*lint -e438 -esym(438,*)*/
/*lint -e529 -esym(529,*)*/

	if(usb3_misc_ctrl_is_unreset(pericfg_base) && usb3_clk_is_open(pericfg_base)) {
		/* set vbus valid */
		if(usb3_phy_controller_is_reset()) {
			usb3_core_wait_for_idle();
		}

		/* reset controller */
		usb3_misc_reg_clrvalue(~(SET_NBITS_MASK(8, 9)), 0xa0ul);
		usb_err("reset controller\n");

		/* reset phy */
		usb3_misc_reg_clrvalue(~(SET_NBITS_MASK(0, 1)), 0xa0ul); /*lint !e835 */
		usb_err("reset phy\n");

		if (is_abb_clk_selected(sctrl_base)) {
			/* disable usb_tcxo_en */
			writel((USB_TCXO_EN << PERI_CTRL3_MSK_START),
					pericfg_base + PCTRL_PERI_CTRL3);
			clk_disable_unprepare(hisi_dwc3->gt_clk_usb3_tcxo_en);
		} else {
			/* close phy ref clk */
			writel(GT_CLK_USB2PHY_REF, pericfg_base + PERI_CRG_PERDIS6);
			clk_disable_unprepare(hisi_dwc3->gt_clk_usb2phy_ref);
		}
	}

	/* reset usb misc ctrl module */
	writel(IP_RST_USB3OTG_MISC | IP_RST_USB3OTG_32K, pericfg_base + 0x90);

	/* close misc clk gate */
	writel(GT_CLK_USB3OTG_REF | GT_ACLK_USB3OTG, pericfg_base + 0x44);
	clk_disable_unprepare(hisi_dwc3->clk);
	clk_disable_unprepare(hisi_dwc3->gt_aclk_usb3otg);

	/* close hclk gate */
	writel(GT_HCLK_USB3OTG_MISC, pericfg_base + PERI_CRG_PERDIS0);
	clk_disable_unprepare(hisi_dwc3->gt_hclk_usb3otg);

	usb_err("close usb success\n");
}
/*lint -e438 +esym(438,*)*/
/*lint -e529 +esym(529,*)*/
static int kirin970_usb3phy_init(struct hisi_dwc3_device *hisi_dwc3)
{
	usb_dbg("+\n");
#if 0
	ret = usb3_clk_init(hisi_dwc3);
	if (ret)
		return ret;
#endif

	dwc3_release(hisi_dwc3);
#if 0
	config_femtophy_param(hisi_dwc3); /* set eye param */
#endif

	set_hisi_dwc3_power_flag(1);

	usb_dbg("-\n");

	return 0;
}

static int kirin970_usb3phy_shutdown(struct hisi_dwc3_device *hisi_dwc3)
{
	usb_dbg("+\n");

	set_hisi_dwc3_power_flag(0);

	dwc3_reset(hisi_dwc3);
#if 0
	usb3_clk_shutdown(hisi_dwc3);

#endif
	usb_dbg("-\n");

	return 0;
}

static int kirin970_get_dts_resource(struct hisi_dwc3_device *hisi_dwc3)
{
	struct device *dev = &hisi_dwc3->pdev->dev;
	/* get h clk handler */
	hisi_dwc3->gt_hclk_usb3otg = devm_clk_get(&hisi_dwc3->pdev->dev, "hclk_usb3otg");
	if (IS_ERR_OR_NULL(hisi_dwc3->gt_hclk_usb3otg)) {
		dev_err(dev, "get hclk_usb3otg failed\n");
		return -EINVAL;
	}

	if (is_abb_clk_selected(hisi_dwc3->sctrl_reg_base)) {
		/* get tcxo clk handler */
		hisi_dwc3->gt_clk_usb3_tcxo_en = devm_clk_get(&hisi_dwc3->pdev->dev, "clk_usb3_tcxo_en");
		if (IS_ERR_OR_NULL(hisi_dwc3->gt_clk_usb3_tcxo_en)) {
			dev_err(dev, "get clk_usb3_tcxo_en failed\n");
			return -EINVAL;
		}
	} else {
		/* get usb2phy ref clk handler */
		hisi_dwc3->gt_clk_usb2phy_ref = devm_clk_get(&hisi_dwc3->pdev->dev, "clk_usb2phy_ref");
		if (IS_ERR_OR_NULL(hisi_dwc3->gt_clk_usb2phy_ref)) {
			dev_err(dev, "get clk_usb2phy_ref failed\n");
			return -EINVAL;
		}
	}
	return 0;
}

static struct usb3_phy_ops kirin970_phy_ops = {
	.init		= kirin970_usb3phy_init,
	.shutdown	= kirin970_usb3phy_shutdown,
	.get_dts_resource = kirin970_get_dts_resource,
};

static int dwc3_kirin970_probe(struct platform_device *pdev)
{
	int ret = 0;

	ret = hisi_dwc3_probe(pdev, &kirin970_phy_ops);
	if (ret)
		usb_err("probe failed, ret=[%d]\n", ret);

	return ret;
}

static int dwc3_kirin970_remove(struct platform_device *pdev)
{
	int ret = 0;

	ret = hisi_dwc3_remove(pdev);
	if (ret)
		usb_err("hisi_dwc3_remove failed, ret=[%d]\n", ret);

	return ret;
}
#ifdef CONFIG_OF
static const struct of_device_id dwc3_kirin970_match[] = {
	{ .compatible = "hisilicon,kirin970-dwc3" },
	{},
};
MODULE_DEVICE_TABLE(of, dwc3_kirin970_match);
#else
#define dwc3_kirin970_match NULL
#endif

static struct platform_driver dwc3_kirin970_driver = {
	.probe		= dwc3_kirin970_probe,
	.remove		= dwc3_kirin970_remove,
	.driver		= {
		.name	= "usb3-kirin970",
		.of_match_table = of_match_ptr(dwc3_kirin970_match),
		.pm	= HISI_DWC3_PM_OPS,
	},
};
/*lint +e715 +e716 +e717 +e835 +e838 +e845 +e533 +e835 +e778 +e774 +e747 +e785 +e438 +e529*/
/*lint -e64 -esym(64,*)*/
/*lint -e528 -esym(528,*)*/
module_platform_driver(dwc3_kirin970_driver);
/*lint -e528 +esym(528,*)*/
/*lint -e753 -esym(753,*)*/
MODULE_LICENSE("GPL");
/*lint -e753 +esym(753,*)*/
/*lint -e64 +esym(64,*)*/
