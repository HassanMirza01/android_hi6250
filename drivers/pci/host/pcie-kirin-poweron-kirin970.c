#include "pcie-kirin.h"
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/stat.h>

/*lint -e438 -e550 -e715 -e732 -e747 -e750 -e838 -esym(438,*) -esym(550,*) -esym(715,*) -esym(732,*) -esym(747,*) -esym(750,*) -esym(838,*) */

#define CHIP_TYPE_ES 1
#define ECO 1
#define ECO_TEST 2
#define SRAM_SIZE 0x10000 //4096*16

#define CRGPERIHPH_PEREN7 0x420
#define CRGPERIHPH_PERRSTDIS0 0x64
#define CRGPERIHPH_PERRSTDIS3 0x88
#define CRGPERIPH_CLKDIV21 0xfc
#define CRGPERIPH_CLKDIV26 0x700
#define CRGPERIPH_PCIECTRL0 0x800
#define CRGPERIPH_PCIECTRL1 0x804
#define CRGPERIPH_PEREN12 0x470
#define CRGPERIPH_PERDIS12 0x474

#define IP_PRST_PCIE_PHY (0x1 << 27)

#define SCTRL_SCISODIS 0x44
#define PCIE0PHYISODIS (0x1 << 5)

#define ES_SOC_PCIE0PHY_ADDR 0xfc040000
#define ES_SOC_PCIEPHY_CTRL16 0x40
#define ES_SOC_PCIEPHY_CTRL17 0x44
#define ES_SOC_PCIEPHY_STAT16 0x440

#define ES_SC_PCIEPHY_CTRL16_MASK 0xFC000003
#define ES_SC_PCIEPHY_CTRL17_MASK 0xFC000000

#define PCIEPLL_REFDIV (0x1 << 2)
#define PCIEPLL_FBDIV (0x9c << 8)
#define PCIEPLL_POSTDIV1 (0x6 << 20)
#define PCIEPLL_POSTDIV2 (0x5 << 23)
#define PCIEPLL_CFG_VLD (0x1 << 25)
#define PCIEPLL_INT_MOD (0x0 << 24)
#define PCIEPLL_FRACDIV (0x400000 << 0)

#define GT_PCLK_PCIE_PHY (0x1 << 9)
#define GT_CLK_PCIE_HP (0x1 << 15)
#define GT_CLK_PCIE_DEBOUNCE (0x1 << 12)
#define GT_CLK_PCIE1_HP (0x1 << 19)
#define GT_CLK_PCIE1_DEBOUNCE (0x1 << 16)

/*define ie,oe cfg*/
#define IO_IE_POLAR (0x1 << 29)
#define IO_IE_EN_SOFT (0x1 << 28)
#define IO_IE_EN_HARD_BYPASS (0x1 << 27)
#define IO_OE_EN_HARD_BYPASS (0x1 << 11)
#define IO_HARD_CTRL_DEBOUNCE_BYPASS (0x1 << 10)
#define IO_OE_POLAR (0x1 << 9)
#define IO_OE_GT_MODE (0x2 << 7)
#define IO_OE_EN_SOFT (0x1 << 6)
#define DEBOUNCE_WAITCFG_IN (0xf << 20)
#define DEBOUNCE_WAITCFG_OUT (0xf << 13)

int g_phy_apb_init = 0;

static int kirin_pcie_gpio_cfg(struct kirin_pcie *pcie, int pull_up)
{
	u32 val;

	if (pull_up) {
		if (pcie->dtsinfo.board_type == BOARD_FPGA) {
			val = kirin_elb_readl(pcie, SOC_PCIECTRL_CTRL12_ADDR);
			val |= PERST_FUN_SEC;
			val |= PERST_ASSERT_EN;
			kirin_elb_writel(pcie, val, SOC_PCIECTRL_CTRL12_ADDR);
		} else {
			if (gpio_direction_output((unsigned int)pcie->gpio_id_reset, 1)) {
			        PCIE_PR_ERR("can't set reset_gpio direction input");
			        return -1;
			}
		}
	} else {
		if (pcie->dtsinfo.board_type == BOARD_FPGA) {
			val = kirin_elb_readl(pcie, SOC_PCIECTRL_CTRL12_ADDR);
			val |= PERST_FUN_SEC;
			val &= ~PERST_ASSERT_EN;
			kirin_elb_writel(pcie, val, SOC_PCIECTRL_CTRL12_ADDR);
		} else {
			if (gpio_direction_output((unsigned int)pcie->gpio_id_reset, 0) ){
			        PCIE_PR_ERR("can't set reset_gpio direction input");
			        return -1;
			}
		}
	}

	return 0;
}

static void kirin_pcie_iso_ctrl(struct kirin_pcie *pcie, int en_flag)
{
	if (en_flag)
		writel(pcie->dtsinfo.isoen_value, pcie->sctrl_base + pcie->dtsinfo.isoen_offset);
	else
		writel(pcie->dtsinfo.isodis_value, pcie->sctrl_base + pcie->dtsinfo.isodis_offset);
}

static int kirin_pcie_clk_ctrl(struct clk *clk, int clk_on)
{
	int ret = 0;

	if (clk_on) {
		ret = clk_prepare_enable(clk);
		if (0 != ret)
			return ret;
	} else {
		clk_disable_unprepare(clk);
	}

	return ret;
}

static void kirin_pcie_reset_ctrl(struct kirin_pcie *pcie, int reset)
{
	u32 val;

	if (reset) {
		if (pcie->rc_id == 1) {
			val = pcie->dtsinfo.phy_assert_value;
			writel(val, pcie->crg_base + pcie->dtsinfo.phy_assert_offset);
		}
		val = pcie->dtsinfo.core_assert_value;
		writel(val, pcie->crg_base + pcie->dtsinfo.core_assert_offset);
	} else {
		val = pcie->dtsinfo.core_deassert_value | pcie->dtsinfo.phy_deassert_value;
		writel(val, pcie->crg_base + pcie->dtsinfo.core_deassert_offset);
	}
}

static void kirin_pcie_natural_cfg(struct kirin_pcie *pcie)
{
	u32 val;

	/*pull up sys_aux_pwr_det in sc_pciectrl_ctrl7*/
	val = kirin_elb_readl(pcie, SOC_PCIECTRL_CTRL7_ADDR);
	val |= (0x1 << 10);
	kirin_elb_writel(pcie, val, SOC_PCIECTRL_CTRL7_ADDR);

	if (pcie->dtsinfo.ep_flag) {
		/*input*/
		val = kirin_elb_readl(pcie, SOC_PCIECTRL_CTRL12_ADDR);
		val |= (0x3 << 2);
		kirin_elb_writel(pcie, val, SOC_PCIECTRL_CTRL12_ADDR);
	} else {
		/*output, pull down*/
		val = kirin_elb_readl(pcie, SOC_PCIECTRL_CTRL12_ADDR);
		val &= ~(0x3 << 2);
		kirin_elb_writel(pcie, val, SOC_PCIECTRL_CTRL12_ADDR);
	}

	val = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL1_ADDR);
       val |= (0x1 << 17);//phy_reset
       val &= ~(0x1 << 19);//pipe_lane0_reset_n
       kirin_phy_writel(pcie, val, SOC_PCIEPHY_CTRL1_ADDR);

	 /*pull up phy0_ana_pwr_en signal */
       val = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL33_ADDR);
       val |= (0x1 << 1);
       kirin_phy_writel(pcie, val, SOC_PCIEPHY_CTRL33_ADDR);
}

static void kirin_pcie_pll_init(struct kirin_pcie *pcie)
{
	u32 val;
	void __iomem    *phy0_base;

	if (g_phy_apb_init == 0) {
		phy0_base = ioremap(ES_SOC_PCIE0PHY_ADDR, 0x40000);
		if (!phy0_base) {
			PCIE_PR_ERR("phy0_base ioremap fail");
			return;
		}
		/*pull down phy iso*/
		writel(PCIE0PHYISODIS, pcie->sctrl_base + SCTRL_SCISODIS);
		/*CRGPERIHPH  PEREN7[9] =0x1, enable phy0_pclk*/
		writel(GT_PCLK_PCIE_PHY, pcie->crg_base + CRGPERIHPH_PEREN7);
		/*CRGPERIHPH  PERRSTDIS3[27] =0x1, deassert apb phy0*/
		writel(IP_PRST_PCIE_PHY, pcie->crg_base + CRGPERIHPH_PERRSTDIS3);

		val = readl(phy0_base + ES_SOC_PCIEPHY_CTRL16);
		val &= ES_SC_PCIEPHY_CTRL16_MASK;
		val |= (PCIEPLL_REFDIV | PCIEPLL_FBDIV | PCIEPLL_POSTDIV1 | PCIEPLL_POSTDIV2);
		writel(val, phy0_base + ES_SOC_PCIEPHY_CTRL16);

		val = readl(phy0_base + ES_SOC_PCIEPHY_CTRL17);
		val &= ES_SC_PCIEPHY_CTRL17_MASK;
		val |= (PCIEPLL_CFG_VLD | PCIEPLL_FRACDIV);
		writel(val, phy0_base + ES_SOC_PCIEPHY_CTRL17);
		iounmap(phy0_base);
	}
	g_phy_apb_init = 1;
}

static int kirin_pcie_pll_ctrl(struct kirin_pcie *pcie, int enable)
{
	u32 val;

	if (enable) {
		/*gt_clk_pciepll = 0*/
		val = kirin_phy_readl(pcie, ES_SOC_PCIEPHY_CTRL17);
		val &= ~(0x1 << 26);
		kirin_phy_writel(pcie, val, ES_SOC_PCIEPHY_CTRL17);

		/*pciepll_en = 1*/
		val = kirin_phy_readl(pcie, ES_SOC_PCIEPHY_CTRL16);
		val |= (0x1 << 0);
		kirin_phy_writel(pcie, val, ES_SOC_PCIEPHY_CTRL16);

		udelay(200);//lint !e778  !e774  !e516 !e747
		val = kirin_phy_readl(pcie, ES_SOC_PCIEPHY_STAT16);
		if (pcie->dtsinfo.board_type != BOARD_FPGA) {
			if (!(val & 0x1)) {
				PCIE_PR_ERR("wait for pll_lock timeout");
				return -1;
			}
		}
		/*pciepll_bp = 0*/
		val = kirin_phy_readl(pcie, ES_SOC_PCIEPHY_CTRL16);
		val &= ~(0x1 << 1);
		kirin_phy_writel(pcie, val, ES_SOC_PCIEPHY_CTRL16);

		/*gt_clk_pciepll = 1*/
		val = kirin_phy_readl(pcie, ES_SOC_PCIEPHY_CTRL17);
		val |= (0x1 << 26);
		kirin_phy_writel(pcie, val, ES_SOC_PCIEPHY_CTRL17);
	} else {
		/*gt_clk_pciepll = 0*/
		val = kirin_phy_readl(pcie, ES_SOC_PCIEPHY_CTRL17);
		val &= ~(0x1 << 26);
		kirin_phy_writel(pcie, val, ES_SOC_PCIEPHY_CTRL17);

		/*pciepll_en = 0*/
		val = kirin_phy_readl(pcie, ES_SOC_PCIEPHY_CTRL16);
		val &= ~(0x1 << 0);
		kirin_phy_writel(pcie, val, ES_SOC_PCIEPHY_CTRL16);

		/*pciepll_bp = 1*/
		val = kirin_phy_readl(pcie, ES_SOC_PCIEPHY_CTRL16);
		val |= (0x1 << 1);
		kirin_phy_writel(pcie, val, ES_SOC_PCIEPHY_CTRL16);

		/*gt_clk_pciepll = 1*/
		val = kirin_phy_readl(pcie, ES_SOC_PCIEPHY_CTRL17);
		val |= (0x1 << 26);
		kirin_phy_writel(pcie, val, ES_SOC_PCIEPHY_CTRL17);
	}

	 return 0;
}

static void kirin_pcie_phyref_gt(struct kirin_pcie *pcie, int open)
{
	u32 val;

	if (open) {
		if (pcie->rc_id == 1) {
			/*   PCIE1  */
			/*en hard gt mode*/
			val = readl(pcie->crg_base + CRGPERIPH_PCIECTRL1);
			val &= ~(0x1 << 1);
			writel(val, pcie->crg_base + CRGPERIPH_PCIECTRL1);

			/*disable soft gt mode*/
			val = readl(pcie->crg_base + CRGPERIPH_PERDIS12);
			val |= (0x1 << 18);
			writel(val, pcie->crg_base + CRGPERIPH_PERDIS12);
		} else {
			/*   PCIE0  */
			/*en hard gt mode*/
			val = readl(pcie->crg_base + CRGPERIPH_PCIECTRL0);
			val &= ~(0x1 << 1);
			writel(val, pcie->crg_base + CRGPERIPH_PCIECTRL0);

			/*disable soft gt mode*/
			val = readl(pcie->crg_base + CRGPERIPH_PERDIS12);
			val |= (0x1 << 14);
			writel(val, pcie->crg_base + CRGPERIPH_PERDIS12);
		}
	} else {
		if (pcie->rc_id == 1) {
			/*   PCIE1  */
			/*disable hard gt mode*/
			val = readl(pcie->crg_base + CRGPERIPH_PCIECTRL1);
			val |= (0x1 << 1);
			writel(val, pcie->crg_base + CRGPERIPH_PCIECTRL1);

			/*disable soft gt mode*/
			val = readl(pcie->crg_base + CRGPERIPH_PERDIS12);
			val |= (0x1 << 18);
			writel(val, pcie->crg_base + CRGPERIPH_PERDIS12);

		} else {
			/*   PCIE0  */
			/*disable hard gt mode*/
			val = readl(pcie->crg_base + CRGPERIPH_PCIECTRL0);
			val |= (0x1 << 1);
			writel(val, pcie->crg_base + CRGPERIPH_PCIECTRL0);

			/*disable soft gt mode*/
			val = readl(pcie->crg_base + CRGPERIPH_PERDIS12);
			val |= (0x1 << 14);
			writel(val, pcie->crg_base + CRGPERIPH_PERDIS12);
		}
	}
}

static void kirin_pcie_hp_debounce_gt(struct kirin_pcie *pcie, int open)
{
	u32 val;

	if (open) {
		if (pcie->rc_id == 0) {
			/*gt_clk_pcie_hp/gt_clk_pcie_debounce open*/
			val = readl(pcie->crg_base + CRGPERIPH_PEREN12);
			val |= (GT_CLK_PCIE_HP|GT_CLK_PCIE_DEBOUNCE);
			writel(val, pcie->crg_base + CRGPERIPH_PEREN12);
		} else {
			/*gt_clk_pcie1_hp/gt_clk_pcie1_debounce open*/
			val = readl(pcie->crg_base + CRGPERIPH_PEREN12);
			val |= (GT_CLK_PCIE1_HP|GT_CLK_PCIE1_DEBOUNCE);
			writel(val, pcie->crg_base + CRGPERIPH_PEREN12);
		}
	} else {
		if (pcie->rc_id == 0) {
			/*gt_clk_pcie_hp/gt_clk_pcie_debounce close*/
			val = readl(pcie->crg_base + CRGPERIPH_PERDIS12);
			val |= (GT_CLK_PCIE_HP|GT_CLK_PCIE_DEBOUNCE);
			writel(val, pcie->crg_base + CRGPERIPH_PERDIS12);
		} else {
			/*gt_clk_pcie1_hp/gt_clk_pcie1_debounce close*/
			val = readl(pcie->crg_base + CRGPERIPH_PERDIS12);
			val |= (GT_CLK_PCIE1_HP|GT_CLK_PCIE1_DEBOUNCE);
			writel(val, pcie->crg_base + CRGPERIPH_PERDIS12);
		}
	}
}


static void kirin_pcie_oe_ctrl(struct kirin_pcie *pcie, int en_flag)
{
	u32 val;
	u32 crg_pciectrl_offset;

	if (pcie->rc_id == 0)
		crg_pciectrl_offset = CRGPERIPH_PCIECTRL0;
	else
		crg_pciectrl_offset = CRGPERIPH_PCIECTRL1;

	val = readl(pcie->crg_base + crg_pciectrl_offset);

	/*set ie cfg*/
	val |= IO_IE_EN_HARD_BYPASS;

	/*set oe cfg*/
	val &= ~IO_HARD_CTRL_DEBOUNCE_BYPASS;

	/* set phy_debounce in&out time*/
	val |= (DEBOUNCE_WAITCFG_IN | DEBOUNCE_WAITCFG_OUT);

	/*select oe_gt_mode */
	val |= IO_OE_GT_MODE;

	if (en_flag)
		val &= ~IO_OE_EN_HARD_BYPASS;
	else
		val |= IO_OE_EN_HARD_BYPASS;

	writel(val, pcie->crg_base + crg_pciectrl_offset);
}


static void kirin_pcie_ioref_gt(struct kirin_pcie *pcie, int open)
{
       u32 val;
       u32 crg_pciectrl_offset;
       u32 crg_perdis12_val;

       if (pcie->rc_id == 0) {
               crg_pciectrl_offset = CRGPERIPH_PCIECTRL0;
               crg_perdis12_val = (0x1 << 13);
       } else {
               crg_pciectrl_offset = CRGPERIPH_PCIECTRL1;
               crg_perdis12_val = (0x1 << 17);
       }

       if (open) {
               kirin_elb_writel(pcie, 0x20000070, SOC_PCIECTRL_CTRL21_ADDR);

               kirin_pcie_oe_ctrl(pcie, ENABLE);

               /*en hard gt mode*/
               val = readl(pcie->crg_base + crg_pciectrl_offset);
               val &= ~(0x1 << 0);
               writel(val, pcie->crg_base + crg_pciectrl_offset);

               /*disable soft gt mode*/
               val = readl(pcie->crg_base + CRGPERIPH_PERDIS12);
               val |= crg_perdis12_val;
               writel(val, pcie->crg_base + CRGPERIPH_PERDIS12);
       } else {
               /*disable hard gt mode*/
               val = readl(pcie->crg_base + crg_pciectrl_offset);
               val |= (0x1 << 0);
               writel(val, pcie->crg_base + crg_pciectrl_offset);

               /*disable soft gt mode*/
               val = readl(pcie->crg_base + CRGPERIPH_PERDIS12);
               val |= crg_perdis12_val;
               writel(val, pcie->crg_base + CRGPERIPH_PERDIS12);
       }
}

static void set_phy_eye_param(struct kirin_pcie *pcie)
{
	u32 eye_param;
	struct kirin_pcie_dtsinfo *dtsinfo;

	dtsinfo = &pcie->dtsinfo;

	if (dtsinfo->pcie_eye_param_ctrl2)
		kirin_phy_writel(pcie, dtsinfo->pcie_eye_param_ctrl2, SOC_PCIEPHY_CTRL2_ADDR);

	if (dtsinfo->pcie_eye_param_ctrl3)
		kirin_phy_writel(pcie, dtsinfo->pcie_eye_param_ctrl3, SOC_PCIEPHY_CTRL3_ADDR);

	eye_param = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL2_ADDR);
	PCIE_PR_INFO("pcie_eye_param_ctrl2 is 0x%x", eye_param);
	eye_param = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL3_ADDR);
	PCIE_PR_INFO("pcie_eye_param_ctrl3 is 0x%x", eye_param);
}

static int kirin_pcie_allclk_ctrl(struct kirin_pcie *pcie, int clk_on)
{
	u32 val;

	if (clk_on) {
		/*choose 100MHz clk src: Bit[8]==1 pll, Bit[8]==0 Board */
		val = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL1_ADDR);
		val &= ~(0x1 << 8);
		kirin_phy_writel(pcie, val, SOC_PCIEPHY_CTRL1_ADDR);

		if (pcie->rc_id == 0) {
			/*pull up phy_ref_use_cio_pad*/
			val = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL0_ADDR);
			val |= (0x1 << 14);
			kirin_phy_writel(pcie, val, SOC_PCIEPHY_CTRL0_ADDR);
		}

		kirin_pcie_pll_init(pcie);

		if (kirin_pcie_pll_ctrl(pcie, ENABLE)) {
			PCIE_PR_ERR("pll enable fail");
			return -1;
		}
		/*   PCIE1 div gt*/
		if (pcie->rc_id == 1) {
			/*CRGPERIPH CLKDIV21[14] = 0x1*/
			writel(0x40004000, pcie->crg_base + CRGPERIPH_CLKDIV21);

			/*CRGPERIPH CLKDIV26[8:5] = 0x0*/
			writel(0x1E00000, pcie->crg_base + CRGPERIPH_CLKDIV26);
		}
		kirin_pcie_hp_debounce_gt(pcie, ENABLE);
		kirin_pcie_phyref_gt(pcie, ENABLE);
		kirin_pcie_ioref_gt(pcie, ENABLE);

		if (kirin_pcie_clk_ctrl(pcie->pcie_aclk, ENABLE)) {
			PCIE_PR_ERR("Failed to enable pcie_aclk ");

			kirin_pcie_clk_ctrl(pcie->apb_phy_clk, DISABLE);
			kirin_pcie_clk_ctrl(pcie->apb_sys_clk, DISABLE);
			return -1;
		}
		PCIE_PR_DEBUG("aclk on Done ");

		if (kirin_pcie_clk_ctrl(pcie->pcie_aux_clk, ENABLE)) {
			PCIE_PR_ERR("Failed to enable pcie_aux_clk ");

			kirin_pcie_clk_ctrl(pcie->pcie_aclk, DISABLE);
			kirin_pcie_clk_ctrl(pcie->apb_phy_clk, DISABLE);
			kirin_pcie_clk_ctrl(pcie->apb_sys_clk, DISABLE);
			return -1;
		}
		PCIE_PR_DEBUG("auxclk on Done ");
	} else {
		if (kirin_pcie_clk_ctrl(pcie->pcie_aux_clk, DISABLE))
			return -1;

		if (kirin_pcie_clk_ctrl(pcie->pcie_aclk, DISABLE))
			return -1;

		kirin_pcie_ioref_gt(pcie, DISABLE);
		kirin_pcie_phyref_gt(pcie, DISABLE);
		kirin_pcie_hp_debounce_gt(pcie, DISABLE);
		if (pcie->rc_id == 1) {
			/*CRGPERIPH CLKDIV21[14] = 0x0*/
			writel(0x40000000, pcie->crg_base + CRGPERIPH_CLKDIV21);
		}

		if (kirin_pcie_pll_ctrl(pcie, DISABLE)) {
			PCIE_PR_ERR("pll disable fail");
			return -1;
		}
	}

	return 0;
}

static int kirin_pcie_eco(struct kirin_pcie *pcie)
{
	void __iomem *checkdata;
	void __iomem *sramdata;
	char *filename = "/vendor/firmware/pciefile.v";
	struct file *fp;
	loff_t pos;
	ssize_t len;
	mm_segment_t fs;
	struct kstat stat;
	struct kirin_pcie_dtsinfo *dtsinfo;

	dtsinfo = &(pcie->dtsinfo);

	sramdata = pcie->phy_base + 0x18000 - 0x40000; //lint !e124
	checkdata = (char *)kmalloc(SRAM_SIZE, GFP_KERNEL);
	if (!checkdata) {
		PCIE_PR_ERR("alloc checkdata fail\n");
		return -1;
	}
	memset(checkdata, 0x0, SRAM_SIZE);

	fp = filp_open(filename, O_RDONLY, 0);

	if (IS_ERR(fp)) {
		fp = NULL;
		PCIE_PR_ERR("pcie file is null");
		goto FILP_OPEN_FAIL;
	}

	fs = get_fs();
	set_fs(KERNEL_DS); //lint !e501

	if (vfs_stat(filename, &stat)) {
		PCIE_PR_ERR("get eco file size fail");
		goto FILP_READ_FAIL;
	}

	if (dtsinfo->eco == ECO_TEST) {
		memset(sramdata, 0x0, 16);
		if (memcmp(sramdata, checkdata, 16) != 0) {
			PCIE_PR_ERR("sram data clear fail");
			goto FILP_READ_FAIL;
		}
	}

	pos = 0;
	len = vfs_read(fp, (char __user *)sramdata, stat.size, &pos);
	if (len < stat.size) {
		PCIE_PR_ERR("read eco file fail");
		goto FILP_READ_FAIL;
	}

	if (dtsinfo->eco == ECO_TEST) {
		if (memcmp(sramdata, checkdata, stat.size) == 0) {
			PCIE_PR_ERR("sram data all is 0, write eco file fail");
			goto FILP_READ_FAIL;
		}
	}

	set_fs(fs);
	filp_close(fp, NULL);
	kfree(checkdata);
	return 0;
FILP_READ_FAIL:
	set_fs(fs);
	filp_close(fp, NULL);
FILP_OPEN_FAIL:
	kfree(checkdata);
	return -1;
}

static int kirin_pcie_phy_init(struct kirin_pcie *pcie)
{
	u32 reg_val;
	u32 pipe_clk_stable = 0x1 << 19;
	u32 sram_init_done = 0x1 << 0;
	u32 time = 10;
	struct kirin_pcie_dtsinfo *dtsinfo;

	dtsinfo = &pcie->dtsinfo;

	if (dtsinfo->eco) {
		/*pull down phy0_sram_bypass signal, choose ECO */
		reg_val = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL40_ADDR);
		reg_val &= ~(0x1 << 0);
		kirin_phy_writel(pcie, reg_val, SOC_PCIEPHY_CTRL40_ADDR);
	} else {
		/*pull up phy0_sram_bypass signal, not choose ECO */
		reg_val = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL40_ADDR);
		reg_val |= (0x1 << 0);
		kirin_phy_writel(pcie, reg_val, SOC_PCIEPHY_CTRL40_ADDR);
	}

	/*pull down phy_test_powerdown signal */
	reg_val = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL0_ADDR);
	reg_val &= ~(0x1 << 22);
	kirin_phy_writel(pcie, reg_val, SOC_PCIEPHY_CTRL0_ADDR);

	udelay(10);//lint !e778  !e774  !e516 !e747

	if (dtsinfo->eco) {
		reg_val = kirin_phy_readl(pcie, SOC_PCIEPHY_STATE39_ADDR);
		while (!(reg_val & sram_init_done)) {
			udelay(100);//lint !e778  !e774  !e516 !e747
			if (time == 0) {
				PCIE_PR_ERR("phy0_sram_init_done fail");
				return -1;
			}
			time--;
			reg_val = kirin_phy_readl(pcie, SOC_PCIEPHY_STATE39_ADDR);
		}
		if (kirin_pcie_eco(pcie)) {
			PCIE_PR_ERR("eco init fail");
			return -1;
		}

		/*pull up phy0_sram_ext_ld_done signal, not choose ECO */
		reg_val = kirin_phy_readl(pcie, SOC_PCIEPHY_CTRL40_ADDR);
		reg_val |= (0x1 << 4);
		kirin_phy_writel(pcie, reg_val, SOC_PCIEPHY_CTRL40_ADDR);
	}

	time = 10;
	if (pcie->dtsinfo.board_type != BOARD_FPGA) {
		reg_val = kirin_phy_readl(pcie, SOC_PCIEPHY_STATE0_ADDR);
		while (reg_val & pipe_clk_stable) {
			udelay(100);//lint !e778  !e774  !e516 !e747
			if (time == 0) {
				PCIE_PR_ERR("PIPE clk is not stable");
				return -1;
			}
			time--;
			reg_val = kirin_phy_readl(pcie, SOC_PCIEPHY_STATE0_ADDR);
		}
	}
	return 0;
}

int kirin_pcie_power_on(struct pcie_port *pp, int on_flag)
{
	struct kirin_pcie *pcie = to_kirin_pcie(pp);//lint !e826
	u32 reg_val;

	/*power on*/
	if (on_flag) {
		if (pcie->is_power_on == 1)
			return 0;

		/*pull down phy ISO*/
		kirin_pcie_iso_ctrl(pcie, DISABLE);
		PCIE_PR_DEBUG("iso disable Done ");

		/*enable pcie_phy_apb_pclk,pcie_ctrl_apb_pclk*/
		if (kirin_pcie_clk_ctrl(pcie->apb_phy_clk, ENABLE)) {
			PCIE_PR_ERR("Failed to enable apb_phy_clk");
			return -1;
		}

		if (kirin_pcie_clk_ctrl(pcie->apb_sys_clk, ENABLE)) {
			PCIE_PR_ERR("Failed to enable apb_sys_clk");

			kirin_pcie_clk_ctrl(pcie->apb_phy_clk, DISABLE);

			return -1;
		}

		PCIE_PR_DEBUG("pciectrl/pciephy pclk open Done ");

		/*unset module*/
		kirin_pcie_reset_ctrl(pcie, DISABLE);
		PCIE_PR_DEBUG("module unreset Done ");

		set_phy_eye_param(pcie);

		kirin_pcie_natural_cfg(pcie);
		PCIE_PR_DEBUG("natural cfg Done ");

		if (kirin_pcie_allclk_ctrl(pcie, ENABLE))
			return -1;

		if (kirin_pcie_phy_init(pcie))
			return -1;

		/*unrst EP*/
		mdelay((unsigned long)22);//lint !e778  !e774  !e516  !e747  !e845
		reg_val = kirin_elb_readl(pcie, SOC_PCIECTRL_CTRL12_ADDR);
		reg_val |= (0x1 << 2);
		kirin_elb_writel(pcie, reg_val, SOC_PCIECTRL_CTRL12_ADDR);

		kirin_pcie_gpio_cfg(pcie, ENABLE);
		mdelay((unsigned long)10);//lint !e778  !e774  !e516  !e747  !e845
		pcie->is_power_on = 1;
	} else {
		if (pcie->is_power_on == 0)
			return 0;

		kirin_pcie_gpio_cfg(pcie, DISABLE);

		mdelay((unsigned long)10);//lint !e778  !e774  !e516  !e747  !e845

		/*rst EP*/
		reg_val = kirin_elb_readl(pcie, SOC_PCIECTRL_CTRL12_ADDR);
		reg_val &= ~(0x1 << 2);
		kirin_elb_writel(pcie, reg_val, SOC_PCIECTRL_CTRL12_ADDR);

		if (kirin_pcie_allclk_ctrl(pcie, DISABLE))
			return -1;

		kirin_pcie_reset_ctrl(pcie, ENABLE);

		if (kirin_pcie_clk_ctrl(pcie->apb_sys_clk, DISABLE)) {
			return -1;
		}

		if (kirin_pcie_clk_ctrl(pcie->apb_phy_clk, DISABLE)) {
			return -1;
		}

		kirin_pcie_iso_ctrl(pcie, ENABLE);

		pcie->is_power_on = 0;
	}

	return 0;
}
/*lint -e438 -e550 -e715 -e732 -e747 -e750 -e838 +esym(438,*) +esym(550,*) +esym(715,*) +esym(732,*) +esym(747,*) +esym(750,*) +esym(838,*) */

