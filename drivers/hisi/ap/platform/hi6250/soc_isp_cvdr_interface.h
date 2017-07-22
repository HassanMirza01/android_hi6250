#ifndef __SOC_ISP_CVDR_INTERFACE_H__
#define __SOC_ISP_CVDR_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#define SOC_ISP_CVDR_CVDR_CVDR_CFG_ADDR(base) ((base) + (0x0))
#define SOC_ISP_CVDR_CVDR_CVDR_DEBUG_EN_ADDR(base) ((base) + (0x4))
#define SOC_ISP_CVDR_CVDR_CVDR_DEBUG_ADDR(base) ((base) + (0x8))
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_ADDR(base) ((base) + (0xC))
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_ADDR(base) ((base) + (0x10))
#define SOC_ISP_CVDR_CVDR_OTHER_RO_ADDR(base) ((base) + (0x14))
#define SOC_ISP_CVDR_CVDR_OTHER_RW_ADDR(base) ((base) + (0x18))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_0_ADDR(base) ((base) + (0x1C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_0_ADDR(base) ((base) + (0x20))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_0_ADDR(base) ((base) + (0x24))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_0_ADDR(base) ((base) + (0x28))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_1_ADDR(base) ((base) + (0x2C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_1_ADDR(base) ((base) + (0x30))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_1_ADDR(base) ((base) + (0x34))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_1_ADDR(base) ((base) + (0x38))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_4_ADDR(base) ((base) + (0x5C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_4_ADDR(base) ((base) + (0x60))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_4_ADDR(base) ((base) + (0x64))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_4_ADDR(base) ((base) + (0x68))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_5_ADDR(base) ((base) + (0x6C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_5_ADDR(base) ((base) + (0x70))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_5_ADDR(base) ((base) + (0x74))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_5_ADDR(base) ((base) + (0x78))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_8_ADDR(base) ((base) + (0x9C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_8_ADDR(base) ((base) + (0xA0))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_8_ADDR(base) ((base) + (0xA4))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_8_ADDR(base) ((base) + (0xA8))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_9_ADDR(base) ((base) + (0xAC))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_9_ADDR(base) ((base) + (0xB0))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_9_ADDR(base) ((base) + (0xB4))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_9_ADDR(base) ((base) + (0xB8))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_14_ADDR(base) ((base) + (0xFC))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_14_ADDR(base) ((base) + (0x100))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_14_ADDR(base) ((base) + (0x104))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_14_ADDR(base) ((base) + (0x108))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_15_ADDR(base) ((base) + (0x10C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_15_ADDR(base) ((base) + (0x110))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_15_ADDR(base) ((base) + (0x114))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_15_ADDR(base) ((base) + (0x118))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_16_ADDR(base) ((base) + (0x11C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_16_ADDR(base) ((base) + (0x120))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_16_ADDR(base) ((base) + (0x124))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_16_ADDR(base) ((base) + (0x128))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_17_ADDR(base) ((base) + (0x12C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_17_ADDR(base) ((base) + (0x130))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_17_ADDR(base) ((base) + (0x134))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_17_ADDR(base) ((base) + (0x138))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_18_ADDR(base) ((base) + (0x13C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_18_ADDR(base) ((base) + (0x140))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_18_ADDR(base) ((base) + (0x144))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_18_ADDR(base) ((base) + (0x148))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_19_ADDR(base) ((base) + (0x14C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_19_ADDR(base) ((base) + (0x150))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_19_ADDR(base) ((base) + (0x154))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_19_ADDR(base) ((base) + (0x158))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_20_ADDR(base) ((base) + (0x15C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_20_ADDR(base) ((base) + (0x160))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_20_ADDR(base) ((base) + (0x164))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_20_ADDR(base) ((base) + (0x168))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_21_ADDR(base) ((base) + (0x16C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_21_ADDR(base) ((base) + (0x170))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_21_ADDR(base) ((base) + (0x174))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_21_ADDR(base) ((base) + (0x178))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_22_ADDR(base) ((base) + (0x17C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_22_ADDR(base) ((base) + (0x180))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_22_ADDR(base) ((base) + (0x184))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_22_ADDR(base) ((base) + (0x188))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_23_ADDR(base) ((base) + (0x18C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_23_ADDR(base) ((base) + (0x190))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_23_ADDR(base) ((base) + (0x194))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_23_ADDR(base) ((base) + (0x198))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_24_ADDR(base) ((base) + (0x19C))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_24_ADDR(base) ((base) + (0x1A0))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_24_ADDR(base) ((base) + (0x1A4))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_24_ADDR(base) ((base) + (0x1A8))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_25_ADDR(base) ((base) + (0x1AC))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_25_ADDR(base) ((base) + (0x1B0))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_25_ADDR(base) ((base) + (0x1B4))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_25_ADDR(base) ((base) + (0x1B8))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_26_ADDR(base) ((base) + (0x1BC))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_26_ADDR(base) ((base) + (0x1C0))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_26_ADDR(base) ((base) + (0x1C4))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_26_ADDR(base) ((base) + (0x1C8))
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_27_ADDR(base) ((base) + (0x1CC))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_27_ADDR(base) ((base) + (0x1D0))
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_27_ADDR(base) ((base) + (0x1D4))
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_27_ADDR(base) ((base) + (0x1D8))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_0_ADDR(base) ((base) + (0x400))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_1_ADDR(base) ((base) + (0x404))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_4_ADDR(base) ((base) + (0x410))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_5_ADDR(base) ((base) + (0x414))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_8_ADDR(base) ((base) + (0x420))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_9_ADDR(base) ((base) + (0x424))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_14_ADDR(base) ((base) + (0x438))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_15_ADDR(base) ((base) + (0x43C))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_16_ADDR(base) ((base) + (0x440))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_17_ADDR(base) ((base) + (0x444))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_18_ADDR(base) ((base) + (0x448))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_19_ADDR(base) ((base) + (0x44C))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_20_ADDR(base) ((base) + (0x450))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_21_ADDR(base) ((base) + (0x454))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_22_ADDR(base) ((base) + (0x458))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_23_ADDR(base) ((base) + (0x45C))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_24_ADDR(base) ((base) + (0x460))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_25_ADDR(base) ((base) + (0x464))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_26_ADDR(base) ((base) + (0x468))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_27_ADDR(base) ((base) + (0x46C))
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_0_ADDR(base) ((base) + (0x500))
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_0_ADDR(base) ((base) + (0x504))
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_0_ADDR(base) ((base) + (0x508))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_0_ADDR(base) ((base) + (0x50C))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_0_ADDR(base) ((base) + (0x510))
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_0_ADDR(base) ((base) + (0x514))
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_0_ADDR(base) ((base) + (0x51C))
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_4_ADDR(base) ((base) + (0x580))
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_4_ADDR(base) ((base) + (0x584))
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_4_ADDR(base) ((base) + (0x588))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_4_ADDR(base) ((base) + (0x58C))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_4_ADDR(base) ((base) + (0x590))
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_4_ADDR(base) ((base) + (0x594))
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_4_ADDR(base) ((base) + (0x59C))
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_5_ADDR(base) ((base) + (0x5A0))
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_5_ADDR(base) ((base) + (0x5A4))
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_5_ADDR(base) ((base) + (0x5A8))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_5_ADDR(base) ((base) + (0x5AC))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_5_ADDR(base) ((base) + (0x5B0))
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_5_ADDR(base) ((base) + (0x5B4))
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_5_ADDR(base) ((base) + (0x5BC))
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_6_ADDR(base) ((base) + (0x5C0))
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_6_ADDR(base) ((base) + (0x5C4))
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_6_ADDR(base) ((base) + (0x5C8))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_6_ADDR(base) ((base) + (0x5CC))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_6_ADDR(base) ((base) + (0x5D0))
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_6_ADDR(base) ((base) + (0x5D4))
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_6_ADDR(base) ((base) + (0x5DC))
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_7_ADDR(base) ((base) + (0x5E0))
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_7_ADDR(base) ((base) + (0x5E4))
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_7_ADDR(base) ((base) + (0x5E8))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_7_ADDR(base) ((base) + (0x5EC))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_7_ADDR(base) ((base) + (0x5F0))
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_7_ADDR(base) ((base) + (0x5F4))
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_7_ADDR(base) ((base) + (0x5FC))
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_8_ADDR(base) ((base) + (0x600))
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_8_ADDR(base) ((base) + (0x604))
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_8_ADDR(base) ((base) + (0x608))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_8_ADDR(base) ((base) + (0x60C))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_8_ADDR(base) ((base) + (0x610))
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_8_ADDR(base) ((base) + (0x614))
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_8_ADDR(base) ((base) + (0x61C))
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_9_ADDR(base) ((base) + (0x620))
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_9_ADDR(base) ((base) + (0x624))
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_9_ADDR(base) ((base) + (0x628))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_9_ADDR(base) ((base) + (0x62C))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_9_ADDR(base) ((base) + (0x630))
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_9_ADDR(base) ((base) + (0x634))
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_9_ADDR(base) ((base) + (0x63C))
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_10_ADDR(base) ((base) + (0x640))
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_10_ADDR(base) ((base) + (0x644))
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_10_ADDR(base) ((base) + (0x648))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_10_ADDR(base) ((base) + (0x64C))
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_10_ADDR(base) ((base) + (0x650))
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_10_ADDR(base) ((base) + (0x654))
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_10_ADDR(base) ((base) + (0x65C))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_0_ADDR(base) ((base) + (0x880))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_4_ADDR(base) ((base) + (0x890))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_5_ADDR(base) ((base) + (0x894))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_6_ADDR(base) ((base) + (0x898))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_7_ADDR(base) ((base) + (0x89C))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_8_ADDR(base) ((base) + (0x8A0))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_9_ADDR(base) ((base) + (0x8A4))
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_10_ADDR(base) ((base) + (0x8A8))
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_1_ADDR(base) ((base) + (0xA10))
#define SOC_ISP_CVDR_CVDR_NR_RD_DEBUG_1_ADDR(base) ((base) + (0xA14))
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_1_ADDR(base) ((base) + (0xA18))
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_2_ADDR(base) ((base) + (0xA20))
#define SOC_ISP_CVDR_CVDR_NR_RD_DEBUG_2_ADDR(base) ((base) + (0xA24))
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_2_ADDR(base) ((base) + (0xA28))
#define SOC_ISP_CVDR_CVDR_DEBUG_0_ADDR(base) ((base) + (0xB00))
#define SOC_ISP_CVDR_CVDR_DEBUG_1_ADDR(base) ((base) + (0xB04))
#define SOC_ISP_CVDR_CVDR_DEBUG_2_ADDR(base) ((base) + (0xB08))
#define SOC_ISP_CVDR_CVDR_DEBUG_3_ADDR(base) ((base) + (0xB0C))
#define SOC_ISP_CVDR_CVDR_DEBUG_4_ADDR(base) ((base) + (0xB10))
#define SOC_ISP_CVDR_CVDR_DEBUG_5_ADDR(base) ((base) + (0xB14))
#define SOC_ISP_CVDR_CVDR_DEBUG_6_ADDR(base) ((base) + (0xB18))
#define SOC_ISP_CVDR_CVDR_DEBUG_7_ADDR(base) ((base) + (0xB1C))
#define SOC_ISP_CVDR_CVDR_DEBUG_8_ADDR(base) ((base) + (0xB20))
#define SOC_ISP_CVDR_CVDR_DEBUG_9_ADDR(base) ((base) + (0xB24))
#define SOC_ISP_CVDR_CVDR_DEBUG_10_ADDR(base) ((base) + (0xB28))
#define SOC_ISP_CVDR_CVDR_DEBUG_11_ADDR(base) ((base) + (0xB2C))
#define SOC_ISP_CVDR_CVDR_DEBUG_12_ADDR(base) ((base) + (0xB30))
#define SOC_ISP_CVDR_CVDR_DEBUG_13_ADDR(base) ((base) + (0xB34))
#define SOC_ISP_CVDR_CVDR_DEBUG_14_ADDR(base) ((base) + (0xB38))
#define SOC_ISP_CVDR_CVDR_DEBUG_15_ADDR(base) ((base) + (0xB3C))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_NR_RD_1_ADDR(base) ((base) + (0xC44))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_NR_RD_2_ADDR(base) ((base) + (0xC48))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_0_ADDR(base) ((base) + (0xC80))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_1_ADDR(base) ((base) + (0xC84))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_4_ADDR(base) ((base) + (0xC90))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_5_ADDR(base) ((base) + (0xC94))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_8_ADDR(base) ((base) + (0xCA0))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_9_ADDR(base) ((base) + (0xCA4))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_14_ADDR(base) ((base) + (0xCB8))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_15_ADDR(base) ((base) + (0xCBC))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_16_ADDR(base) ((base) + (0xCC0))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_17_ADDR(base) ((base) + (0xCC4))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_18_ADDR(base) ((base) + (0xCC8))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_19_ADDR(base) ((base) + (0xCCC))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_20_ADDR(base) ((base) + (0xCD0))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_21_ADDR(base) ((base) + (0xCD4))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_22_ADDR(base) ((base) + (0xCD8))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_23_ADDR(base) ((base) + (0xCDC))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_24_ADDR(base) ((base) + (0xCE0))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_25_ADDR(base) ((base) + (0xCE4))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_26_ADDR(base) ((base) + (0xCE8))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_27_ADDR(base) ((base) + (0xCEC))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_0_ADDR(base) ((base) + (0xD80))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_4_ADDR(base) ((base) + (0xD90))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_5_ADDR(base) ((base) + (0xD94))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_6_ADDR(base) ((base) + (0xD98))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_7_ADDR(base) ((base) + (0xD9C))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_8_ADDR(base) ((base) + (0xDA0))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_9_ADDR(base) ((base) + (0xDA4))
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_10_ADDR(base) ((base) + (0xDA8))
#define SOC_ISP_CVDR_CVDR_SPARE_0_ADDR(base) ((base) + (0xE00))
#define SOC_ISP_CVDR_CVDR_SPARE_1_ADDR(base) ((base) + (0xE04))
#define SOC_ISP_CVDR_CVDR_SPARE_2_ADDR(base) ((base) + (0xE08))
#define SOC_ISP_CVDR_CVDR_SPARE_3_ADDR(base) ((base) + (0xE0C))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_0_ADDR(base) ((base) + (0xF00))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_1_ADDR(base) ((base) + (0xF04))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_4_ADDR(base) ((base) + (0xF10))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_5_ADDR(base) ((base) + (0xF14))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_8_ADDR(base) ((base) + (0xF20))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_9_ADDR(base) ((base) + (0xF24))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_14_ADDR(base) ((base) + (0xF38))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_15_ADDR(base) ((base) + (0xF3C))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_16_ADDR(base) ((base) + (0xF40))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_17_ADDR(base) ((base) + (0xF44))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_18_ADDR(base) ((base) + (0xF48))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_19_ADDR(base) ((base) + (0xF4C))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_20_ADDR(base) ((base) + (0xF50))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_21_ADDR(base) ((base) + (0xF54))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_22_ADDR(base) ((base) + (0xF58))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_23_ADDR(base) ((base) + (0xF5C))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_24_ADDR(base) ((base) + (0xF60))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_25_ADDR(base) ((base) + (0xF64))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_26_ADDR(base) ((base) + (0xF68))
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_27_ADDR(base) ((base) + (0xF6C))
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int du_write_threshold : 6;
        unsigned int reserved_0 : 2;
        unsigned int stall_srt_du_threshold : 8;
        unsigned int max_axiread_id : 5;
        unsigned int reserved_1 : 3;
        unsigned int max_axiwrite_tx : 5;
        unsigned int reserved_2 : 1;
        unsigned int force_rd_clk_on : 1;
        unsigned int force_wr_clk_on : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_CVDR_CFG_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_CVDR_CFG_du_write_threshold_START (0)
#define SOC_ISP_CVDR_CVDR_CVDR_CFG_du_write_threshold_END (5)
#define SOC_ISP_CVDR_CVDR_CVDR_CFG_stall_srt_du_threshold_START (8)
#define SOC_ISP_CVDR_CVDR_CVDR_CFG_stall_srt_du_threshold_END (15)
#define SOC_ISP_CVDR_CVDR_CVDR_CFG_max_axiread_id_START (16)
#define SOC_ISP_CVDR_CVDR_CVDR_CFG_max_axiread_id_END (20)
#define SOC_ISP_CVDR_CVDR_CVDR_CFG_max_axiwrite_tx_START (24)
#define SOC_ISP_CVDR_CVDR_CVDR_CFG_max_axiwrite_tx_END (28)
#define SOC_ISP_CVDR_CVDR_CVDR_CFG_force_rd_clk_on_START (30)
#define SOC_ISP_CVDR_CVDR_CVDR_CFG_force_rd_clk_on_END (30)
#define SOC_ISP_CVDR_CVDR_CVDR_CFG_force_wr_clk_on_START (31)
#define SOC_ISP_CVDR_CVDR_CVDR_CFG_force_wr_clk_on_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_peak_en : 1;
        unsigned int reserved_0 : 7;
        unsigned int rd_peak_en : 1;
        unsigned int reserved_1 : 23;
    } reg;
} SOC_ISP_CVDR_CVDR_CVDR_DEBUG_EN_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_CVDR_DEBUG_EN_wr_peak_en_START (0)
#define SOC_ISP_CVDR_CVDR_CVDR_DEBUG_EN_wr_peak_en_END (0)
#define SOC_ISP_CVDR_CVDR_CVDR_DEBUG_EN_rd_peak_en_START (8)
#define SOC_ISP_CVDR_CVDR_CVDR_DEBUG_EN_rd_peak_en_END (8)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_peak : 8;
        unsigned int rd_peak : 8;
        unsigned int reserved : 16;
    } reg;
} SOC_ISP_CVDR_CVDR_CVDR_DEBUG_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_CVDR_DEBUG_wr_peak_START (0)
#define SOC_ISP_CVDR_CVDR_CVDR_DEBUG_wr_peak_END (7)
#define SOC_ISP_CVDR_CVDR_CVDR_DEBUG_rd_peak_START (8)
#define SOC_ISP_CVDR_CVDR_CVDR_DEBUG_rd_peak_END (15)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int wr_qos_threshold_01_stop : 4;
        unsigned int wr_qos_threshold_01_start : 4;
        unsigned int wr_qos_threshold_10_stop : 4;
        unsigned int wr_qos_threshold_10_start : 4;
        unsigned int wr_qos_threshold_11_stop : 4;
        unsigned int wr_qos_threshold_11_start : 4;
        unsigned int reserved : 2;
        unsigned int wr_qos_rt_min : 2;
        unsigned int wr_qos_srt_max : 2;
        unsigned int wr_qos_sr : 2;
    } reg;
} SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_threshold_01_stop_START (0)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_threshold_01_stop_END (3)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_threshold_01_start_START (4)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_threshold_01_start_END (7)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_threshold_10_stop_START (8)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_threshold_10_stop_END (11)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_threshold_10_start_START (12)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_threshold_10_start_END (15)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_threshold_11_stop_START (16)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_threshold_11_stop_END (19)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_threshold_11_start_START (20)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_threshold_11_start_END (23)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_rt_min_START (26)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_rt_min_END (27)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_srt_max_START (28)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_srt_max_END (29)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_sr_START (30)
#define SOC_ISP_CVDR_CVDR_CVDR_WR_QOS_CFG_wr_qos_sr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int rd_qos_threshold_01_stop : 4;
        unsigned int rd_qos_threshold_01_start : 4;
        unsigned int rd_qos_threshold_10_stop : 4;
        unsigned int rd_qos_threshold_10_start : 4;
        unsigned int rd_qos_threshold_11_stop : 4;
        unsigned int rd_qos_threshold_11_start : 4;
        unsigned int reserved : 2;
        unsigned int rd_qos_rt_min : 2;
        unsigned int rd_qos_srt_max : 2;
        unsigned int rd_qos_sr : 2;
    } reg;
} SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_threshold_01_stop_START (0)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_threshold_01_stop_END (3)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_threshold_01_start_START (4)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_threshold_01_start_END (7)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_threshold_10_stop_START (8)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_threshold_10_stop_END (11)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_threshold_10_start_START (12)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_threshold_10_start_END (15)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_threshold_11_stop_START (16)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_threshold_11_stop_END (19)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_threshold_11_start_START (20)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_threshold_11_start_END (23)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_rt_min_START (26)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_rt_min_END (27)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_srt_max_START (28)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_srt_max_END (29)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_sr_START (30)
#define SOC_ISP_CVDR_CVDR_CVDR_RD_QOS_CFG_rd_qos_sr_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int other_ro : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_OTHER_RO_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_OTHER_RO_other_ro_START (0)
#define SOC_ISP_CVDR_CVDR_OTHER_RO_other_ro_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int other_rw : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_OTHER_RW_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_OTHER_RW_other_rw_START (0)
#define SOC_ISP_CVDR_CVDR_OTHER_RW_other_rw_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_0 : 4;
        unsigned int vpwr_pixel_expansion_0 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_0 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_0_vpwr_pixel_format_0_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_0_vpwr_pixel_format_0_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_0_vpwr_pixel_expansion_0_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_0_vpwr_pixel_expansion_0_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_0_vpwr_last_page_0_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_0_vpwr_last_page_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_0 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_0_vpwr_address_frame_start_0_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_0_vpwr_address_frame_start_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_0 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_0 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_0_vpwr_line_stride_0_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_0_vpwr_line_stride_0_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_0_vpwr_line_wrap_0_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_0_vpwr_line_wrap_0_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_0 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_0 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_0 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_0_vpwr_index_id0_0_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_0_vpwr_index_id0_0_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_0_vpwr_index_id1_0_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_0_vpwr_index_id1_0_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_0_vpwr_prefetch_bypass_0_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_0_vpwr_prefetch_bypass_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_1 : 4;
        unsigned int vpwr_pixel_expansion_1 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_1 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_1_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_1_vpwr_pixel_format_1_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_1_vpwr_pixel_format_1_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_1_vpwr_pixel_expansion_1_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_1_vpwr_pixel_expansion_1_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_1_vpwr_last_page_1_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_1_vpwr_last_page_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_1 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_1_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_1_vpwr_address_frame_start_1_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_1_vpwr_address_frame_start_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_1 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_1 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_1_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_1_vpwr_line_stride_1_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_1_vpwr_line_stride_1_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_1_vpwr_line_wrap_1_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_1_vpwr_line_wrap_1_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_1 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_1 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_1 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_1_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_1_vpwr_index_id0_1_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_1_vpwr_index_id0_1_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_1_vpwr_index_id1_1_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_1_vpwr_index_id1_1_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_1_vpwr_prefetch_bypass_1_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_1_vpwr_prefetch_bypass_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_4 : 4;
        unsigned int vpwr_pixel_expansion_4 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_4 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_4_vpwr_pixel_format_4_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_4_vpwr_pixel_format_4_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_4_vpwr_pixel_expansion_4_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_4_vpwr_pixel_expansion_4_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_4_vpwr_last_page_4_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_4_vpwr_last_page_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_4 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_4_vpwr_address_frame_start_4_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_4_vpwr_address_frame_start_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_4 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_4 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_4_vpwr_line_stride_4_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_4_vpwr_line_stride_4_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_4_vpwr_line_wrap_4_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_4_vpwr_line_wrap_4_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_4 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_4 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_4 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_4_vpwr_index_id0_4_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_4_vpwr_index_id0_4_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_4_vpwr_index_id1_4_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_4_vpwr_index_id1_4_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_4_vpwr_prefetch_bypass_4_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_4_vpwr_prefetch_bypass_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_5 : 4;
        unsigned int vpwr_pixel_expansion_5 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_5 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_5_vpwr_pixel_format_5_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_5_vpwr_pixel_format_5_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_5_vpwr_pixel_expansion_5_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_5_vpwr_pixel_expansion_5_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_5_vpwr_last_page_5_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_5_vpwr_last_page_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_5 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_5_vpwr_address_frame_start_5_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_5_vpwr_address_frame_start_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_5 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_5 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_5_vpwr_line_stride_5_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_5_vpwr_line_stride_5_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_5_vpwr_line_wrap_5_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_5_vpwr_line_wrap_5_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_5 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_5 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_5 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_5_vpwr_index_id0_5_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_5_vpwr_index_id0_5_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_5_vpwr_index_id1_5_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_5_vpwr_index_id1_5_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_5_vpwr_prefetch_bypass_5_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_5_vpwr_prefetch_bypass_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_8 : 4;
        unsigned int vpwr_pixel_expansion_8 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_8 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_8_vpwr_pixel_format_8_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_8_vpwr_pixel_format_8_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_8_vpwr_pixel_expansion_8_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_8_vpwr_pixel_expansion_8_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_8_vpwr_last_page_8_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_8_vpwr_last_page_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_8 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_8_vpwr_address_frame_start_8_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_8_vpwr_address_frame_start_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_8 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_8 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_8_vpwr_line_stride_8_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_8_vpwr_line_stride_8_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_8_vpwr_line_wrap_8_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_8_vpwr_line_wrap_8_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_8 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_8 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_8 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_8_vpwr_index_id0_8_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_8_vpwr_index_id0_8_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_8_vpwr_index_id1_8_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_8_vpwr_index_id1_8_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_8_vpwr_prefetch_bypass_8_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_8_vpwr_prefetch_bypass_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_9 : 4;
        unsigned int vpwr_pixel_expansion_9 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_9 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_9_vpwr_pixel_format_9_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_9_vpwr_pixel_format_9_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_9_vpwr_pixel_expansion_9_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_9_vpwr_pixel_expansion_9_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_9_vpwr_last_page_9_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_9_vpwr_last_page_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_9 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_9_vpwr_address_frame_start_9_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_9_vpwr_address_frame_start_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_9 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_9 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_9_vpwr_line_stride_9_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_9_vpwr_line_stride_9_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_9_vpwr_line_wrap_9_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_9_vpwr_line_wrap_9_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_9 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_9 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_9 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_9_vpwr_index_id0_9_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_9_vpwr_index_id0_9_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_9_vpwr_index_id1_9_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_9_vpwr_index_id1_9_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_9_vpwr_prefetch_bypass_9_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_9_vpwr_prefetch_bypass_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_14 : 4;
        unsigned int vpwr_pixel_expansion_14 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_14 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_14_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_14_vpwr_pixel_format_14_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_14_vpwr_pixel_format_14_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_14_vpwr_pixel_expansion_14_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_14_vpwr_pixel_expansion_14_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_14_vpwr_last_page_14_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_14_vpwr_last_page_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_14 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_14_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_14_vpwr_address_frame_start_14_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_14_vpwr_address_frame_start_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_14 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_14 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_14_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_14_vpwr_line_stride_14_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_14_vpwr_line_stride_14_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_14_vpwr_line_wrap_14_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_14_vpwr_line_wrap_14_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_14 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_14 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_14 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_14_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_14_vpwr_index_id0_14_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_14_vpwr_index_id0_14_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_14_vpwr_index_id1_14_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_14_vpwr_index_id1_14_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_14_vpwr_prefetch_bypass_14_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_14_vpwr_prefetch_bypass_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_15 : 4;
        unsigned int vpwr_pixel_expansion_15 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_15 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_15_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_15_vpwr_pixel_format_15_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_15_vpwr_pixel_format_15_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_15_vpwr_pixel_expansion_15_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_15_vpwr_pixel_expansion_15_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_15_vpwr_last_page_15_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_15_vpwr_last_page_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_15 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_15_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_15_vpwr_address_frame_start_15_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_15_vpwr_address_frame_start_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_15 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_15 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_15_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_15_vpwr_line_stride_15_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_15_vpwr_line_stride_15_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_15_vpwr_line_wrap_15_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_15_vpwr_line_wrap_15_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_15 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_15 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_15 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_15_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_15_vpwr_index_id0_15_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_15_vpwr_index_id0_15_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_15_vpwr_index_id1_15_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_15_vpwr_index_id1_15_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_15_vpwr_prefetch_bypass_15_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_15_vpwr_prefetch_bypass_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_16 : 4;
        unsigned int vpwr_pixel_expansion_16 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_16 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_16_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_16_vpwr_pixel_format_16_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_16_vpwr_pixel_format_16_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_16_vpwr_pixel_expansion_16_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_16_vpwr_pixel_expansion_16_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_16_vpwr_last_page_16_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_16_vpwr_last_page_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_16 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_16_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_16_vpwr_address_frame_start_16_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_16_vpwr_address_frame_start_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_16 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_16 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_16_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_16_vpwr_line_stride_16_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_16_vpwr_line_stride_16_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_16_vpwr_line_wrap_16_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_16_vpwr_line_wrap_16_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_16 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_16 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_16 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_16_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_16_vpwr_index_id0_16_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_16_vpwr_index_id0_16_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_16_vpwr_index_id1_16_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_16_vpwr_index_id1_16_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_16_vpwr_prefetch_bypass_16_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_16_vpwr_prefetch_bypass_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_17 : 4;
        unsigned int vpwr_pixel_expansion_17 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_17 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_17_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_17_vpwr_pixel_format_17_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_17_vpwr_pixel_format_17_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_17_vpwr_pixel_expansion_17_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_17_vpwr_pixel_expansion_17_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_17_vpwr_last_page_17_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_17_vpwr_last_page_17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_17 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_17_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_17_vpwr_address_frame_start_17_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_17_vpwr_address_frame_start_17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_17 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_17 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_17_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_17_vpwr_line_stride_17_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_17_vpwr_line_stride_17_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_17_vpwr_line_wrap_17_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_17_vpwr_line_wrap_17_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_17 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_17 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_17 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_17_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_17_vpwr_index_id0_17_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_17_vpwr_index_id0_17_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_17_vpwr_index_id1_17_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_17_vpwr_index_id1_17_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_17_vpwr_prefetch_bypass_17_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_17_vpwr_prefetch_bypass_17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_18 : 4;
        unsigned int vpwr_pixel_expansion_18 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_18 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_18_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_18_vpwr_pixel_format_18_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_18_vpwr_pixel_format_18_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_18_vpwr_pixel_expansion_18_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_18_vpwr_pixel_expansion_18_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_18_vpwr_last_page_18_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_18_vpwr_last_page_18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_18 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_18_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_18_vpwr_address_frame_start_18_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_18_vpwr_address_frame_start_18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_18 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_18 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_18_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_18_vpwr_line_stride_18_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_18_vpwr_line_stride_18_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_18_vpwr_line_wrap_18_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_18_vpwr_line_wrap_18_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_18 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_18 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_18 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_18_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_18_vpwr_index_id0_18_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_18_vpwr_index_id0_18_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_18_vpwr_index_id1_18_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_18_vpwr_index_id1_18_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_18_vpwr_prefetch_bypass_18_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_18_vpwr_prefetch_bypass_18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_19 : 4;
        unsigned int vpwr_pixel_expansion_19 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_19 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_19_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_19_vpwr_pixel_format_19_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_19_vpwr_pixel_format_19_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_19_vpwr_pixel_expansion_19_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_19_vpwr_pixel_expansion_19_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_19_vpwr_last_page_19_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_19_vpwr_last_page_19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_19 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_19_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_19_vpwr_address_frame_start_19_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_19_vpwr_address_frame_start_19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_19 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_19 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_19_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_19_vpwr_line_stride_19_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_19_vpwr_line_stride_19_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_19_vpwr_line_wrap_19_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_19_vpwr_line_wrap_19_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_19 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_19 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_19 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_19_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_19_vpwr_index_id0_19_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_19_vpwr_index_id0_19_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_19_vpwr_index_id1_19_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_19_vpwr_index_id1_19_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_19_vpwr_prefetch_bypass_19_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_19_vpwr_prefetch_bypass_19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_20 : 4;
        unsigned int vpwr_pixel_expansion_20 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_20 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_20_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_20_vpwr_pixel_format_20_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_20_vpwr_pixel_format_20_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_20_vpwr_pixel_expansion_20_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_20_vpwr_pixel_expansion_20_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_20_vpwr_last_page_20_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_20_vpwr_last_page_20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_20 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_20_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_20_vpwr_address_frame_start_20_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_20_vpwr_address_frame_start_20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_20 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_20 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_20_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_20_vpwr_line_stride_20_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_20_vpwr_line_stride_20_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_20_vpwr_line_wrap_20_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_20_vpwr_line_wrap_20_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_20 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_20 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_20 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_20_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_20_vpwr_index_id0_20_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_20_vpwr_index_id0_20_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_20_vpwr_index_id1_20_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_20_vpwr_index_id1_20_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_20_vpwr_prefetch_bypass_20_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_20_vpwr_prefetch_bypass_20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_21 : 4;
        unsigned int vpwr_pixel_expansion_21 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_21 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_21_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_21_vpwr_pixel_format_21_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_21_vpwr_pixel_format_21_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_21_vpwr_pixel_expansion_21_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_21_vpwr_pixel_expansion_21_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_21_vpwr_last_page_21_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_21_vpwr_last_page_21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_21 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_21_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_21_vpwr_address_frame_start_21_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_21_vpwr_address_frame_start_21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_21 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_21 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_21_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_21_vpwr_line_stride_21_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_21_vpwr_line_stride_21_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_21_vpwr_line_wrap_21_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_21_vpwr_line_wrap_21_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_21 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_21 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_21 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_21_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_21_vpwr_index_id0_21_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_21_vpwr_index_id0_21_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_21_vpwr_index_id1_21_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_21_vpwr_index_id1_21_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_21_vpwr_prefetch_bypass_21_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_21_vpwr_prefetch_bypass_21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_22 : 4;
        unsigned int vpwr_pixel_expansion_22 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_22 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_22_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_22_vpwr_pixel_format_22_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_22_vpwr_pixel_format_22_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_22_vpwr_pixel_expansion_22_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_22_vpwr_pixel_expansion_22_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_22_vpwr_last_page_22_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_22_vpwr_last_page_22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_22 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_22_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_22_vpwr_address_frame_start_22_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_22_vpwr_address_frame_start_22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_22 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_22 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_22_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_22_vpwr_line_stride_22_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_22_vpwr_line_stride_22_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_22_vpwr_line_wrap_22_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_22_vpwr_line_wrap_22_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_22 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_22 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_22 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_22_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_22_vpwr_index_id0_22_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_22_vpwr_index_id0_22_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_22_vpwr_index_id1_22_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_22_vpwr_index_id1_22_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_22_vpwr_prefetch_bypass_22_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_22_vpwr_prefetch_bypass_22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_23 : 4;
        unsigned int vpwr_pixel_expansion_23 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_23 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_23_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_23_vpwr_pixel_format_23_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_23_vpwr_pixel_format_23_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_23_vpwr_pixel_expansion_23_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_23_vpwr_pixel_expansion_23_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_23_vpwr_last_page_23_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_23_vpwr_last_page_23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_23 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_23_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_23_vpwr_address_frame_start_23_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_23_vpwr_address_frame_start_23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_23 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_23 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_23_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_23_vpwr_line_stride_23_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_23_vpwr_line_stride_23_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_23_vpwr_line_wrap_23_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_23_vpwr_line_wrap_23_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_23 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_23 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_23 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_23_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_23_vpwr_index_id0_23_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_23_vpwr_index_id0_23_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_23_vpwr_index_id1_23_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_23_vpwr_index_id1_23_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_23_vpwr_prefetch_bypass_23_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_23_vpwr_prefetch_bypass_23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_24 : 4;
        unsigned int vpwr_pixel_expansion_24 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_24 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_24_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_24_vpwr_pixel_format_24_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_24_vpwr_pixel_format_24_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_24_vpwr_pixel_expansion_24_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_24_vpwr_pixel_expansion_24_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_24_vpwr_last_page_24_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_24_vpwr_last_page_24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_24 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_24_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_24_vpwr_address_frame_start_24_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_24_vpwr_address_frame_start_24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_24 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_24 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_24_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_24_vpwr_line_stride_24_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_24_vpwr_line_stride_24_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_24_vpwr_line_wrap_24_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_24_vpwr_line_wrap_24_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_24 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_24 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_24 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_24_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_24_vpwr_index_id0_24_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_24_vpwr_index_id0_24_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_24_vpwr_index_id1_24_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_24_vpwr_index_id1_24_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_24_vpwr_prefetch_bypass_24_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_24_vpwr_prefetch_bypass_24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_25 : 4;
        unsigned int vpwr_pixel_expansion_25 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_25 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_25_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_25_vpwr_pixel_format_25_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_25_vpwr_pixel_format_25_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_25_vpwr_pixel_expansion_25_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_25_vpwr_pixel_expansion_25_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_25_vpwr_last_page_25_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_25_vpwr_last_page_25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_25 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_25_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_25_vpwr_address_frame_start_25_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_25_vpwr_address_frame_start_25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_25 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_25 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_25_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_25_vpwr_line_stride_25_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_25_vpwr_line_stride_25_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_25_vpwr_line_wrap_25_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_25_vpwr_line_wrap_25_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_25 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_25 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_25 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_25_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_25_vpwr_index_id0_25_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_25_vpwr_index_id0_25_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_25_vpwr_index_id1_25_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_25_vpwr_index_id1_25_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_25_vpwr_prefetch_bypass_25_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_25_vpwr_prefetch_bypass_25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_26 : 4;
        unsigned int vpwr_pixel_expansion_26 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_26 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_26_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_26_vpwr_pixel_format_26_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_26_vpwr_pixel_format_26_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_26_vpwr_pixel_expansion_26_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_26_vpwr_pixel_expansion_26_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_26_vpwr_last_page_26_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_26_vpwr_last_page_26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_26 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_26_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_26_vpwr_address_frame_start_26_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_26_vpwr_address_frame_start_26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_26 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_26 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_26_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_26_vpwr_line_stride_26_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_26_vpwr_line_stride_26_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_26_vpwr_line_wrap_26_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_26_vpwr_line_wrap_26_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_26 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_26 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_26 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_26_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_26_vpwr_index_id0_26_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_26_vpwr_index_id0_26_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_26_vpwr_index_id1_26_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_26_vpwr_index_id1_26_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_26_vpwr_prefetch_bypass_26_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_26_vpwr_prefetch_bypass_26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_pixel_format_27 : 4;
        unsigned int vpwr_pixel_expansion_27 : 1;
        unsigned int reserved : 10;
        unsigned int vpwr_last_page_27 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_CFG_27_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_27_vpwr_pixel_format_27_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_27_vpwr_pixel_format_27_END (3)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_27_vpwr_pixel_expansion_27_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_27_vpwr_pixel_expansion_27_END (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_27_vpwr_last_page_27_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_CFG_27_vpwr_last_page_27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vpwr_address_frame_start_27 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_27_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_27_vpwr_address_frame_start_27_START (4)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_FS_27_vpwr_address_frame_start_27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_line_stride_27 : 10;
        unsigned int reserved_0 : 5;
        unsigned int vpwr_line_wrap_27 : 14;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_27_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_27_vpwr_line_stride_27_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_27_vpwr_line_stride_27_END (9)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_27_vpwr_line_wrap_27_START (15)
#define SOC_ISP_CVDR_CVDR_VP_WR_AXI_LINE_27_vpwr_line_wrap_27_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_index_id0_27 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vpwr_index_id1_27 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vpwr_prefetch_bypass_27 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_27_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_27_vpwr_index_id0_27_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_27_vpwr_index_id0_27_END (6)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_27_vpwr_index_id1_27_START (8)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_27_vpwr_index_id1_27_END (14)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_27_vpwr_prefetch_bypass_27_START (31)
#define SOC_ISP_CVDR_CVDR_VP_WR_PREFETCH_27_vpwr_prefetch_bypass_27_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_0 : 4;
        unsigned int vpwr_access_limiter_1_0 : 4;
        unsigned int vpwr_access_limiter_2_0 : 4;
        unsigned int vpwr_access_limiter_3_0 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_0 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_0_vpwr_access_limiter_0_0_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_0_vpwr_access_limiter_0_0_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_0_vpwr_access_limiter_1_0_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_0_vpwr_access_limiter_1_0_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_0_vpwr_access_limiter_2_0_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_0_vpwr_access_limiter_2_0_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_0_vpwr_access_limiter_3_0_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_0_vpwr_access_limiter_3_0_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_0_vpwr_access_limiter_reload_0_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_0_vpwr_access_limiter_reload_0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_1 : 4;
        unsigned int vpwr_access_limiter_1_1 : 4;
        unsigned int vpwr_access_limiter_2_1 : 4;
        unsigned int vpwr_access_limiter_3_1 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_1 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_1_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_1_vpwr_access_limiter_0_1_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_1_vpwr_access_limiter_0_1_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_1_vpwr_access_limiter_1_1_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_1_vpwr_access_limiter_1_1_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_1_vpwr_access_limiter_2_1_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_1_vpwr_access_limiter_2_1_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_1_vpwr_access_limiter_3_1_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_1_vpwr_access_limiter_3_1_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_1_vpwr_access_limiter_reload_1_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_1_vpwr_access_limiter_reload_1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_4 : 4;
        unsigned int vpwr_access_limiter_1_4 : 4;
        unsigned int vpwr_access_limiter_2_4 : 4;
        unsigned int vpwr_access_limiter_3_4 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_4 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_4_vpwr_access_limiter_0_4_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_4_vpwr_access_limiter_0_4_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_4_vpwr_access_limiter_1_4_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_4_vpwr_access_limiter_1_4_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_4_vpwr_access_limiter_2_4_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_4_vpwr_access_limiter_2_4_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_4_vpwr_access_limiter_3_4_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_4_vpwr_access_limiter_3_4_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_4_vpwr_access_limiter_reload_4_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_4_vpwr_access_limiter_reload_4_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_5 : 4;
        unsigned int vpwr_access_limiter_1_5 : 4;
        unsigned int vpwr_access_limiter_2_5 : 4;
        unsigned int vpwr_access_limiter_3_5 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_5 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_5_vpwr_access_limiter_0_5_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_5_vpwr_access_limiter_0_5_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_5_vpwr_access_limiter_1_5_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_5_vpwr_access_limiter_1_5_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_5_vpwr_access_limiter_2_5_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_5_vpwr_access_limiter_2_5_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_5_vpwr_access_limiter_3_5_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_5_vpwr_access_limiter_3_5_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_5_vpwr_access_limiter_reload_5_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_5_vpwr_access_limiter_reload_5_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_8 : 4;
        unsigned int vpwr_access_limiter_1_8 : 4;
        unsigned int vpwr_access_limiter_2_8 : 4;
        unsigned int vpwr_access_limiter_3_8 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_8 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_8_vpwr_access_limiter_0_8_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_8_vpwr_access_limiter_0_8_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_8_vpwr_access_limiter_1_8_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_8_vpwr_access_limiter_1_8_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_8_vpwr_access_limiter_2_8_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_8_vpwr_access_limiter_2_8_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_8_vpwr_access_limiter_3_8_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_8_vpwr_access_limiter_3_8_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_8_vpwr_access_limiter_reload_8_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_8_vpwr_access_limiter_reload_8_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_9 : 4;
        unsigned int vpwr_access_limiter_1_9 : 4;
        unsigned int vpwr_access_limiter_2_9 : 4;
        unsigned int vpwr_access_limiter_3_9 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_9 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_9_vpwr_access_limiter_0_9_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_9_vpwr_access_limiter_0_9_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_9_vpwr_access_limiter_1_9_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_9_vpwr_access_limiter_1_9_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_9_vpwr_access_limiter_2_9_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_9_vpwr_access_limiter_2_9_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_9_vpwr_access_limiter_3_9_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_9_vpwr_access_limiter_3_9_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_9_vpwr_access_limiter_reload_9_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_9_vpwr_access_limiter_reload_9_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_14 : 4;
        unsigned int vpwr_access_limiter_1_14 : 4;
        unsigned int vpwr_access_limiter_2_14 : 4;
        unsigned int vpwr_access_limiter_3_14 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_14 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_14_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_14_vpwr_access_limiter_0_14_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_14_vpwr_access_limiter_0_14_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_14_vpwr_access_limiter_1_14_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_14_vpwr_access_limiter_1_14_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_14_vpwr_access_limiter_2_14_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_14_vpwr_access_limiter_2_14_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_14_vpwr_access_limiter_3_14_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_14_vpwr_access_limiter_3_14_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_14_vpwr_access_limiter_reload_14_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_14_vpwr_access_limiter_reload_14_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_15 : 4;
        unsigned int vpwr_access_limiter_1_15 : 4;
        unsigned int vpwr_access_limiter_2_15 : 4;
        unsigned int vpwr_access_limiter_3_15 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_15 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_15_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_15_vpwr_access_limiter_0_15_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_15_vpwr_access_limiter_0_15_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_15_vpwr_access_limiter_1_15_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_15_vpwr_access_limiter_1_15_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_15_vpwr_access_limiter_2_15_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_15_vpwr_access_limiter_2_15_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_15_vpwr_access_limiter_3_15_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_15_vpwr_access_limiter_3_15_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_15_vpwr_access_limiter_reload_15_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_15_vpwr_access_limiter_reload_15_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_16 : 4;
        unsigned int vpwr_access_limiter_1_16 : 4;
        unsigned int vpwr_access_limiter_2_16 : 4;
        unsigned int vpwr_access_limiter_3_16 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_16 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_16_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_16_vpwr_access_limiter_0_16_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_16_vpwr_access_limiter_0_16_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_16_vpwr_access_limiter_1_16_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_16_vpwr_access_limiter_1_16_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_16_vpwr_access_limiter_2_16_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_16_vpwr_access_limiter_2_16_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_16_vpwr_access_limiter_3_16_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_16_vpwr_access_limiter_3_16_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_16_vpwr_access_limiter_reload_16_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_16_vpwr_access_limiter_reload_16_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_17 : 4;
        unsigned int vpwr_access_limiter_1_17 : 4;
        unsigned int vpwr_access_limiter_2_17 : 4;
        unsigned int vpwr_access_limiter_3_17 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_17 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_17_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_17_vpwr_access_limiter_0_17_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_17_vpwr_access_limiter_0_17_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_17_vpwr_access_limiter_1_17_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_17_vpwr_access_limiter_1_17_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_17_vpwr_access_limiter_2_17_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_17_vpwr_access_limiter_2_17_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_17_vpwr_access_limiter_3_17_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_17_vpwr_access_limiter_3_17_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_17_vpwr_access_limiter_reload_17_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_17_vpwr_access_limiter_reload_17_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_18 : 4;
        unsigned int vpwr_access_limiter_1_18 : 4;
        unsigned int vpwr_access_limiter_2_18 : 4;
        unsigned int vpwr_access_limiter_3_18 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_18 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_18_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_18_vpwr_access_limiter_0_18_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_18_vpwr_access_limiter_0_18_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_18_vpwr_access_limiter_1_18_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_18_vpwr_access_limiter_1_18_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_18_vpwr_access_limiter_2_18_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_18_vpwr_access_limiter_2_18_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_18_vpwr_access_limiter_3_18_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_18_vpwr_access_limiter_3_18_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_18_vpwr_access_limiter_reload_18_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_18_vpwr_access_limiter_reload_18_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_19 : 4;
        unsigned int vpwr_access_limiter_1_19 : 4;
        unsigned int vpwr_access_limiter_2_19 : 4;
        unsigned int vpwr_access_limiter_3_19 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_19 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_19_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_19_vpwr_access_limiter_0_19_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_19_vpwr_access_limiter_0_19_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_19_vpwr_access_limiter_1_19_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_19_vpwr_access_limiter_1_19_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_19_vpwr_access_limiter_2_19_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_19_vpwr_access_limiter_2_19_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_19_vpwr_access_limiter_3_19_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_19_vpwr_access_limiter_3_19_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_19_vpwr_access_limiter_reload_19_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_19_vpwr_access_limiter_reload_19_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_20 : 4;
        unsigned int vpwr_access_limiter_1_20 : 4;
        unsigned int vpwr_access_limiter_2_20 : 4;
        unsigned int vpwr_access_limiter_3_20 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_20 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_20_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_20_vpwr_access_limiter_0_20_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_20_vpwr_access_limiter_0_20_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_20_vpwr_access_limiter_1_20_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_20_vpwr_access_limiter_1_20_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_20_vpwr_access_limiter_2_20_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_20_vpwr_access_limiter_2_20_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_20_vpwr_access_limiter_3_20_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_20_vpwr_access_limiter_3_20_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_20_vpwr_access_limiter_reload_20_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_20_vpwr_access_limiter_reload_20_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_21 : 4;
        unsigned int vpwr_access_limiter_1_21 : 4;
        unsigned int vpwr_access_limiter_2_21 : 4;
        unsigned int vpwr_access_limiter_3_21 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_21 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_21_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_21_vpwr_access_limiter_0_21_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_21_vpwr_access_limiter_0_21_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_21_vpwr_access_limiter_1_21_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_21_vpwr_access_limiter_1_21_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_21_vpwr_access_limiter_2_21_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_21_vpwr_access_limiter_2_21_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_21_vpwr_access_limiter_3_21_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_21_vpwr_access_limiter_3_21_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_21_vpwr_access_limiter_reload_21_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_21_vpwr_access_limiter_reload_21_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_22 : 4;
        unsigned int vpwr_access_limiter_1_22 : 4;
        unsigned int vpwr_access_limiter_2_22 : 4;
        unsigned int vpwr_access_limiter_3_22 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_22 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_22_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_22_vpwr_access_limiter_0_22_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_22_vpwr_access_limiter_0_22_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_22_vpwr_access_limiter_1_22_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_22_vpwr_access_limiter_1_22_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_22_vpwr_access_limiter_2_22_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_22_vpwr_access_limiter_2_22_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_22_vpwr_access_limiter_3_22_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_22_vpwr_access_limiter_3_22_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_22_vpwr_access_limiter_reload_22_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_22_vpwr_access_limiter_reload_22_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_23 : 4;
        unsigned int vpwr_access_limiter_1_23 : 4;
        unsigned int vpwr_access_limiter_2_23 : 4;
        unsigned int vpwr_access_limiter_3_23 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_23 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_23_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_23_vpwr_access_limiter_0_23_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_23_vpwr_access_limiter_0_23_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_23_vpwr_access_limiter_1_23_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_23_vpwr_access_limiter_1_23_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_23_vpwr_access_limiter_2_23_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_23_vpwr_access_limiter_2_23_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_23_vpwr_access_limiter_3_23_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_23_vpwr_access_limiter_3_23_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_23_vpwr_access_limiter_reload_23_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_23_vpwr_access_limiter_reload_23_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_24 : 4;
        unsigned int vpwr_access_limiter_1_24 : 4;
        unsigned int vpwr_access_limiter_2_24 : 4;
        unsigned int vpwr_access_limiter_3_24 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_24 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_24_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_24_vpwr_access_limiter_0_24_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_24_vpwr_access_limiter_0_24_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_24_vpwr_access_limiter_1_24_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_24_vpwr_access_limiter_1_24_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_24_vpwr_access_limiter_2_24_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_24_vpwr_access_limiter_2_24_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_24_vpwr_access_limiter_3_24_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_24_vpwr_access_limiter_3_24_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_24_vpwr_access_limiter_reload_24_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_24_vpwr_access_limiter_reload_24_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_25 : 4;
        unsigned int vpwr_access_limiter_1_25 : 4;
        unsigned int vpwr_access_limiter_2_25 : 4;
        unsigned int vpwr_access_limiter_3_25 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_25 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_25_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_25_vpwr_access_limiter_0_25_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_25_vpwr_access_limiter_0_25_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_25_vpwr_access_limiter_1_25_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_25_vpwr_access_limiter_1_25_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_25_vpwr_access_limiter_2_25_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_25_vpwr_access_limiter_2_25_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_25_vpwr_access_limiter_3_25_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_25_vpwr_access_limiter_3_25_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_25_vpwr_access_limiter_reload_25_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_25_vpwr_access_limiter_reload_25_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_26 : 4;
        unsigned int vpwr_access_limiter_1_26 : 4;
        unsigned int vpwr_access_limiter_2_26 : 4;
        unsigned int vpwr_access_limiter_3_26 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_26 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_26_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_26_vpwr_access_limiter_0_26_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_26_vpwr_access_limiter_0_26_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_26_vpwr_access_limiter_1_26_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_26_vpwr_access_limiter_1_26_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_26_vpwr_access_limiter_2_26_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_26_vpwr_access_limiter_2_26_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_26_vpwr_access_limiter_3_26_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_26_vpwr_access_limiter_3_26_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_26_vpwr_access_limiter_reload_26_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_26_vpwr_access_limiter_reload_26_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vpwr_access_limiter_0_27 : 4;
        unsigned int vpwr_access_limiter_1_27 : 4;
        unsigned int vpwr_access_limiter_2_27 : 4;
        unsigned int vpwr_access_limiter_3_27 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vpwr_access_limiter_reload_27 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_27_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_27_vpwr_access_limiter_0_27_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_27_vpwr_access_limiter_0_27_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_27_vpwr_access_limiter_1_27_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_27_vpwr_access_limiter_1_27_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_27_vpwr_access_limiter_2_27_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_27_vpwr_access_limiter_2_27_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_27_vpwr_access_limiter_3_27_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_27_vpwr_access_limiter_3_27_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_27_vpwr_access_limiter_reload_27_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_WR_27_vpwr_access_limiter_reload_27_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_pixel_format_0 : 4;
        unsigned int vprd_pixel_expansion_0 : 1;
        unsigned int vprd_allocated_du_0 : 5;
        unsigned int reserved : 5;
        unsigned int vprd_last_page_0 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_CFG_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_0_vprd_pixel_format_0_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_0_vprd_pixel_format_0_END (3)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_0_vprd_pixel_expansion_0_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_0_vprd_pixel_expansion_0_END (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_0_vprd_allocated_du_0_START (5)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_0_vprd_allocated_du_0_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_0_vprd_last_page_0_START (15)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_0_vprd_last_page_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_size_0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_horizontal_blanking_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_LWG_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_0_vprd_line_size_0_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_0_vprd_line_size_0_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_0_vprd_horizontal_blanking_0_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_0_vprd_horizontal_blanking_0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_frame_size_0 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_vertical_blanking_0 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_FHG_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_0_vprd_frame_size_0_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_0_vprd_frame_size_0_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_0_vprd_vertical_blanking_0_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_0_vprd_vertical_blanking_0_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vprd_axi_frame_start_0 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_0_vprd_axi_frame_start_0_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_0_vprd_axi_frame_start_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_stride_0 : 10;
        unsigned int reserved_0 : 6;
        unsigned int vprd_line_wrap_0 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_0_vprd_line_stride_0_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_0_vprd_line_stride_0_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_0_vprd_line_wrap_0_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_0_vprd_line_wrap_0_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_index_id0_0 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vprd_index_id1_0 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vprd_prefetch_bypass_0 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_0_vprd_index_id0_0_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_0_vprd_index_id0_0_END (6)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_0_vprd_index_id1_0_START (8)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_0_vprd_index_id1_0_END (14)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_0_vprd_prefetch_bypass_0_START (31)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_0_vprd_prefetch_bypass_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_debug_0 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_0_vp_rd_debug_0_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_0_vp_rd_debug_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_pixel_format_4 : 4;
        unsigned int vprd_pixel_expansion_4 : 1;
        unsigned int vprd_allocated_du_4 : 5;
        unsigned int reserved : 5;
        unsigned int vprd_last_page_4 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_CFG_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_4_vprd_pixel_format_4_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_4_vprd_pixel_format_4_END (3)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_4_vprd_pixel_expansion_4_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_4_vprd_pixel_expansion_4_END (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_4_vprd_allocated_du_4_START (5)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_4_vprd_allocated_du_4_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_4_vprd_last_page_4_START (15)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_4_vprd_last_page_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_size_4 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_horizontal_blanking_4 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_LWG_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_4_vprd_line_size_4_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_4_vprd_line_size_4_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_4_vprd_horizontal_blanking_4_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_4_vprd_horizontal_blanking_4_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_frame_size_4 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_vertical_blanking_4 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_FHG_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_4_vprd_frame_size_4_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_4_vprd_frame_size_4_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_4_vprd_vertical_blanking_4_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_4_vprd_vertical_blanking_4_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vprd_axi_frame_start_4 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_4_vprd_axi_frame_start_4_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_4_vprd_axi_frame_start_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_stride_4 : 10;
        unsigned int reserved_0 : 6;
        unsigned int vprd_line_wrap_4 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_4_vprd_line_stride_4_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_4_vprd_line_stride_4_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_4_vprd_line_wrap_4_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_4_vprd_line_wrap_4_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_index_id0_4 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vprd_index_id1_4 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vprd_prefetch_bypass_4 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_4_vprd_index_id0_4_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_4_vprd_index_id0_4_END (6)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_4_vprd_index_id1_4_START (8)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_4_vprd_index_id1_4_END (14)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_4_vprd_prefetch_bypass_4_START (31)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_4_vprd_prefetch_bypass_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_debug_4 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_4_vp_rd_debug_4_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_4_vp_rd_debug_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_pixel_format_5 : 4;
        unsigned int vprd_pixel_expansion_5 : 1;
        unsigned int vprd_allocated_du_5 : 5;
        unsigned int reserved : 5;
        unsigned int vprd_last_page_5 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_CFG_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_5_vprd_pixel_format_5_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_5_vprd_pixel_format_5_END (3)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_5_vprd_pixel_expansion_5_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_5_vprd_pixel_expansion_5_END (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_5_vprd_allocated_du_5_START (5)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_5_vprd_allocated_du_5_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_5_vprd_last_page_5_START (15)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_5_vprd_last_page_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_size_5 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_horizontal_blanking_5 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_LWG_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_5_vprd_line_size_5_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_5_vprd_line_size_5_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_5_vprd_horizontal_blanking_5_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_5_vprd_horizontal_blanking_5_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_frame_size_5 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_vertical_blanking_5 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_FHG_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_5_vprd_frame_size_5_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_5_vprd_frame_size_5_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_5_vprd_vertical_blanking_5_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_5_vprd_vertical_blanking_5_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vprd_axi_frame_start_5 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_5_vprd_axi_frame_start_5_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_5_vprd_axi_frame_start_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_stride_5 : 10;
        unsigned int reserved_0 : 6;
        unsigned int vprd_line_wrap_5 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_5_vprd_line_stride_5_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_5_vprd_line_stride_5_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_5_vprd_line_wrap_5_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_5_vprd_line_wrap_5_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_index_id0_5 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vprd_index_id1_5 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vprd_prefetch_bypass_5 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_5_vprd_index_id0_5_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_5_vprd_index_id0_5_END (6)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_5_vprd_index_id1_5_START (8)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_5_vprd_index_id1_5_END (14)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_5_vprd_prefetch_bypass_5_START (31)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_5_vprd_prefetch_bypass_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_debug_5 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_5_vp_rd_debug_5_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_5_vp_rd_debug_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_pixel_format_6 : 4;
        unsigned int vprd_pixel_expansion_6 : 1;
        unsigned int vprd_allocated_du_6 : 5;
        unsigned int reserved : 5;
        unsigned int vprd_last_page_6 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_CFG_6_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_6_vprd_pixel_format_6_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_6_vprd_pixel_format_6_END (3)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_6_vprd_pixel_expansion_6_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_6_vprd_pixel_expansion_6_END (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_6_vprd_allocated_du_6_START (5)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_6_vprd_allocated_du_6_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_6_vprd_last_page_6_START (15)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_6_vprd_last_page_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_size_6 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_horizontal_blanking_6 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_LWG_6_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_6_vprd_line_size_6_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_6_vprd_line_size_6_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_6_vprd_horizontal_blanking_6_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_6_vprd_horizontal_blanking_6_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_frame_size_6 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_vertical_blanking_6 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_FHG_6_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_6_vprd_frame_size_6_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_6_vprd_frame_size_6_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_6_vprd_vertical_blanking_6_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_6_vprd_vertical_blanking_6_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vprd_axi_frame_start_6 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_6_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_6_vprd_axi_frame_start_6_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_6_vprd_axi_frame_start_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_stride_6 : 10;
        unsigned int reserved_0 : 6;
        unsigned int vprd_line_wrap_6 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_6_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_6_vprd_line_stride_6_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_6_vprd_line_stride_6_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_6_vprd_line_wrap_6_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_6_vprd_line_wrap_6_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_index_id0_6 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vprd_index_id1_6 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vprd_prefetch_bypass_6 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_6_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_6_vprd_index_id0_6_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_6_vprd_index_id0_6_END (6)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_6_vprd_index_id1_6_START (8)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_6_vprd_index_id1_6_END (14)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_6_vprd_prefetch_bypass_6_START (31)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_6_vprd_prefetch_bypass_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_debug_6 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_6_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_6_vp_rd_debug_6_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_6_vp_rd_debug_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_pixel_format_7 : 4;
        unsigned int vprd_pixel_expansion_7 : 1;
        unsigned int vprd_allocated_du_7 : 5;
        unsigned int reserved : 5;
        unsigned int vprd_last_page_7 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_CFG_7_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_7_vprd_pixel_format_7_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_7_vprd_pixel_format_7_END (3)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_7_vprd_pixel_expansion_7_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_7_vprd_pixel_expansion_7_END (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_7_vprd_allocated_du_7_START (5)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_7_vprd_allocated_du_7_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_7_vprd_last_page_7_START (15)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_7_vprd_last_page_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_size_7 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_horizontal_blanking_7 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_LWG_7_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_7_vprd_line_size_7_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_7_vprd_line_size_7_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_7_vprd_horizontal_blanking_7_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_7_vprd_horizontal_blanking_7_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_frame_size_7 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_vertical_blanking_7 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_FHG_7_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_7_vprd_frame_size_7_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_7_vprd_frame_size_7_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_7_vprd_vertical_blanking_7_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_7_vprd_vertical_blanking_7_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vprd_axi_frame_start_7 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_7_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_7_vprd_axi_frame_start_7_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_7_vprd_axi_frame_start_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_stride_7 : 10;
        unsigned int reserved_0 : 6;
        unsigned int vprd_line_wrap_7 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_7_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_7_vprd_line_stride_7_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_7_vprd_line_stride_7_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_7_vprd_line_wrap_7_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_7_vprd_line_wrap_7_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_index_id0_7 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vprd_index_id1_7 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vprd_prefetch_bypass_7 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_7_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_7_vprd_index_id0_7_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_7_vprd_index_id0_7_END (6)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_7_vprd_index_id1_7_START (8)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_7_vprd_index_id1_7_END (14)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_7_vprd_prefetch_bypass_7_START (31)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_7_vprd_prefetch_bypass_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_debug_7 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_7_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_7_vp_rd_debug_7_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_7_vp_rd_debug_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_pixel_format_8 : 4;
        unsigned int vprd_pixel_expansion_8 : 1;
        unsigned int vprd_allocated_du_8 : 5;
        unsigned int reserved : 5;
        unsigned int vprd_last_page_8 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_CFG_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_8_vprd_pixel_format_8_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_8_vprd_pixel_format_8_END (3)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_8_vprd_pixel_expansion_8_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_8_vprd_pixel_expansion_8_END (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_8_vprd_allocated_du_8_START (5)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_8_vprd_allocated_du_8_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_8_vprd_last_page_8_START (15)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_8_vprd_last_page_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_size_8 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_horizontal_blanking_8 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_LWG_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_8_vprd_line_size_8_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_8_vprd_line_size_8_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_8_vprd_horizontal_blanking_8_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_8_vprd_horizontal_blanking_8_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_frame_size_8 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_vertical_blanking_8 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_FHG_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_8_vprd_frame_size_8_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_8_vprd_frame_size_8_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_8_vprd_vertical_blanking_8_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_8_vprd_vertical_blanking_8_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vprd_axi_frame_start_8 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_8_vprd_axi_frame_start_8_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_8_vprd_axi_frame_start_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_stride_8 : 10;
        unsigned int reserved_0 : 6;
        unsigned int vprd_line_wrap_8 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_8_vprd_line_stride_8_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_8_vprd_line_stride_8_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_8_vprd_line_wrap_8_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_8_vprd_line_wrap_8_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_index_id0_8 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vprd_index_id1_8 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vprd_prefetch_bypass_8 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_8_vprd_index_id0_8_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_8_vprd_index_id0_8_END (6)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_8_vprd_index_id1_8_START (8)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_8_vprd_index_id1_8_END (14)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_8_vprd_prefetch_bypass_8_START (31)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_8_vprd_prefetch_bypass_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_debug_8 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_8_vp_rd_debug_8_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_8_vp_rd_debug_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_pixel_format_9 : 4;
        unsigned int vprd_pixel_expansion_9 : 1;
        unsigned int vprd_allocated_du_9 : 5;
        unsigned int reserved : 5;
        unsigned int vprd_last_page_9 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_CFG_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_9_vprd_pixel_format_9_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_9_vprd_pixel_format_9_END (3)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_9_vprd_pixel_expansion_9_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_9_vprd_pixel_expansion_9_END (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_9_vprd_allocated_du_9_START (5)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_9_vprd_allocated_du_9_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_9_vprd_last_page_9_START (15)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_9_vprd_last_page_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_size_9 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_horizontal_blanking_9 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_LWG_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_9_vprd_line_size_9_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_9_vprd_line_size_9_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_9_vprd_horizontal_blanking_9_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_9_vprd_horizontal_blanking_9_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_frame_size_9 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_vertical_blanking_9 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_FHG_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_9_vprd_frame_size_9_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_9_vprd_frame_size_9_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_9_vprd_vertical_blanking_9_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_9_vprd_vertical_blanking_9_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vprd_axi_frame_start_9 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_9_vprd_axi_frame_start_9_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_9_vprd_axi_frame_start_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_stride_9 : 10;
        unsigned int reserved_0 : 6;
        unsigned int vprd_line_wrap_9 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_9_vprd_line_stride_9_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_9_vprd_line_stride_9_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_9_vprd_line_wrap_9_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_9_vprd_line_wrap_9_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_index_id0_9 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vprd_index_id1_9 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vprd_prefetch_bypass_9 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_9_vprd_index_id0_9_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_9_vprd_index_id0_9_END (6)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_9_vprd_index_id1_9_START (8)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_9_vprd_index_id1_9_END (14)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_9_vprd_prefetch_bypass_9_START (31)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_9_vprd_prefetch_bypass_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_debug_9 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_9_vp_rd_debug_9_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_9_vp_rd_debug_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_pixel_format_10 : 4;
        unsigned int vprd_pixel_expansion_10 : 1;
        unsigned int vprd_allocated_du_10 : 5;
        unsigned int reserved : 5;
        unsigned int vprd_last_page_10 : 17;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_CFG_10_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_10_vprd_pixel_format_10_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_10_vprd_pixel_format_10_END (3)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_10_vprd_pixel_expansion_10_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_10_vprd_pixel_expansion_10_END (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_10_vprd_allocated_du_10_START (5)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_10_vprd_allocated_du_10_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_10_vprd_last_page_10_START (15)
#define SOC_ISP_CVDR_CVDR_VP_RD_CFG_10_vprd_last_page_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_size_10 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_horizontal_blanking_10 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_LWG_10_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_10_vprd_line_size_10_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_10_vprd_line_size_10_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_10_vprd_horizontal_blanking_10_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_LWG_10_vprd_horizontal_blanking_10_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_frame_size_10 : 13;
        unsigned int reserved_0 : 3;
        unsigned int vprd_vertical_blanking_10 : 8;
        unsigned int reserved_1 : 8;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_FHG_10_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_10_vprd_frame_size_10_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_10_vprd_frame_size_10_END (12)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_10_vprd_vertical_blanking_10_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_FHG_10_vprd_vertical_blanking_10_END (23)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved : 4;
        unsigned int vprd_axi_frame_start_10 : 28;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_10_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_10_vprd_axi_frame_start_10_START (4)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_FS_10_vprd_axi_frame_start_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_line_stride_10 : 10;
        unsigned int reserved_0 : 6;
        unsigned int vprd_line_wrap_10 : 13;
        unsigned int reserved_1 : 3;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_10_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_10_vprd_line_stride_10_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_10_vprd_line_stride_10_END (9)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_10_vprd_line_wrap_10_START (16)
#define SOC_ISP_CVDR_CVDR_VP_RD_AXI_LINE_10_vprd_line_wrap_10_END (28)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_index_id0_10 : 7;
        unsigned int reserved_0 : 1;
        unsigned int vprd_index_id1_10 : 7;
        unsigned int reserved_1 : 16;
        unsigned int vprd_prefetch_bypass_10 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_10_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_10_vprd_index_id0_10_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_10_vprd_index_id0_10_END (6)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_10_vprd_index_id1_10_START (8)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_10_vprd_index_id1_10_END (14)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_10_vprd_prefetch_bypass_10_START (31)
#define SOC_ISP_CVDR_CVDR_VP_RD_PREFETCH_10_vprd_prefetch_bypass_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_debug_10 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_10_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_10_vp_rd_debug_10_START (0)
#define SOC_ISP_CVDR_CVDR_VP_RD_DEBUG_10_vp_rd_debug_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_access_limiter_0_0 : 4;
        unsigned int vprd_access_limiter_1_0 : 4;
        unsigned int vprd_access_limiter_2_0 : 4;
        unsigned int vprd_access_limiter_3_0 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vprd_access_limiter_reload_0 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_0_vprd_access_limiter_0_0_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_0_vprd_access_limiter_0_0_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_0_vprd_access_limiter_1_0_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_0_vprd_access_limiter_1_0_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_0_vprd_access_limiter_2_0_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_0_vprd_access_limiter_2_0_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_0_vprd_access_limiter_3_0_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_0_vprd_access_limiter_3_0_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_0_vprd_access_limiter_reload_0_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_0_vprd_access_limiter_reload_0_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_access_limiter_0_4 : 4;
        unsigned int vprd_access_limiter_1_4 : 4;
        unsigned int vprd_access_limiter_2_4 : 4;
        unsigned int vprd_access_limiter_3_4 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vprd_access_limiter_reload_4 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_4_vprd_access_limiter_0_4_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_4_vprd_access_limiter_0_4_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_4_vprd_access_limiter_1_4_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_4_vprd_access_limiter_1_4_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_4_vprd_access_limiter_2_4_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_4_vprd_access_limiter_2_4_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_4_vprd_access_limiter_3_4_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_4_vprd_access_limiter_3_4_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_4_vprd_access_limiter_reload_4_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_4_vprd_access_limiter_reload_4_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_access_limiter_0_5 : 4;
        unsigned int vprd_access_limiter_1_5 : 4;
        unsigned int vprd_access_limiter_2_5 : 4;
        unsigned int vprd_access_limiter_3_5 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vprd_access_limiter_reload_5 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_5_vprd_access_limiter_0_5_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_5_vprd_access_limiter_0_5_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_5_vprd_access_limiter_1_5_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_5_vprd_access_limiter_1_5_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_5_vprd_access_limiter_2_5_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_5_vprd_access_limiter_2_5_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_5_vprd_access_limiter_3_5_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_5_vprd_access_limiter_3_5_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_5_vprd_access_limiter_reload_5_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_5_vprd_access_limiter_reload_5_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_access_limiter_0_6 : 4;
        unsigned int vprd_access_limiter_1_6 : 4;
        unsigned int vprd_access_limiter_2_6 : 4;
        unsigned int vprd_access_limiter_3_6 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vprd_access_limiter_reload_6 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_6_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_6_vprd_access_limiter_0_6_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_6_vprd_access_limiter_0_6_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_6_vprd_access_limiter_1_6_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_6_vprd_access_limiter_1_6_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_6_vprd_access_limiter_2_6_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_6_vprd_access_limiter_2_6_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_6_vprd_access_limiter_3_6_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_6_vprd_access_limiter_3_6_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_6_vprd_access_limiter_reload_6_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_6_vprd_access_limiter_reload_6_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_access_limiter_0_7 : 4;
        unsigned int vprd_access_limiter_1_7 : 4;
        unsigned int vprd_access_limiter_2_7 : 4;
        unsigned int vprd_access_limiter_3_7 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vprd_access_limiter_reload_7 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_7_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_7_vprd_access_limiter_0_7_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_7_vprd_access_limiter_0_7_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_7_vprd_access_limiter_1_7_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_7_vprd_access_limiter_1_7_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_7_vprd_access_limiter_2_7_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_7_vprd_access_limiter_2_7_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_7_vprd_access_limiter_3_7_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_7_vprd_access_limiter_3_7_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_7_vprd_access_limiter_reload_7_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_7_vprd_access_limiter_reload_7_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_access_limiter_0_8 : 4;
        unsigned int vprd_access_limiter_1_8 : 4;
        unsigned int vprd_access_limiter_2_8 : 4;
        unsigned int vprd_access_limiter_3_8 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vprd_access_limiter_reload_8 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_8_vprd_access_limiter_0_8_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_8_vprd_access_limiter_0_8_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_8_vprd_access_limiter_1_8_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_8_vprd_access_limiter_1_8_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_8_vprd_access_limiter_2_8_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_8_vprd_access_limiter_2_8_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_8_vprd_access_limiter_3_8_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_8_vprd_access_limiter_3_8_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_8_vprd_access_limiter_reload_8_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_8_vprd_access_limiter_reload_8_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_access_limiter_0_9 : 4;
        unsigned int vprd_access_limiter_1_9 : 4;
        unsigned int vprd_access_limiter_2_9 : 4;
        unsigned int vprd_access_limiter_3_9 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vprd_access_limiter_reload_9 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_9_vprd_access_limiter_0_9_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_9_vprd_access_limiter_0_9_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_9_vprd_access_limiter_1_9_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_9_vprd_access_limiter_1_9_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_9_vprd_access_limiter_2_9_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_9_vprd_access_limiter_2_9_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_9_vprd_access_limiter_3_9_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_9_vprd_access_limiter_3_9_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_9_vprd_access_limiter_reload_9_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_9_vprd_access_limiter_reload_9_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vprd_access_limiter_0_10 : 4;
        unsigned int vprd_access_limiter_1_10 : 4;
        unsigned int vprd_access_limiter_2_10 : 4;
        unsigned int vprd_access_limiter_3_10 : 4;
        unsigned int reserved_0 : 8;
        unsigned int vprd_access_limiter_reload_10 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_10_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_10_vprd_access_limiter_0_10_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_10_vprd_access_limiter_0_10_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_10_vprd_access_limiter_1_10_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_10_vprd_access_limiter_1_10_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_10_vprd_access_limiter_2_10_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_10_vprd_access_limiter_2_10_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_10_vprd_access_limiter_3_10_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_10_vprd_access_limiter_3_10_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_10_vprd_access_limiter_reload_10_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_VP_RD_10_vprd_access_limiter_reload_10_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int nrrd_allocated_du_1 : 5;
        unsigned int reserved_1 : 4;
        unsigned int nr_rd_slowdown_enable_1 : 1;
        unsigned int reserved_2 : 16;
        unsigned int nrrd_enable_1 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_NR_RD_CFG_1_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_1_nrrd_allocated_du_1_START (5)
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_1_nrrd_allocated_du_1_END (9)
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_1_nr_rd_slowdown_enable_1_START (14)
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_1_nr_rd_slowdown_enable_1_END (14)
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_1_nrrd_enable_1_START (31)
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_1_nrrd_enable_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_rd_debug_1 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_NR_RD_DEBUG_1_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_NR_RD_DEBUG_1_nr_rd_debug_1_START (0)
#define SOC_ISP_CVDR_CVDR_NR_RD_DEBUG_1_nr_rd_debug_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nrrd_access_limiter_0_1 : 4;
        unsigned int nrrd_access_limiter_1_1 : 4;
        unsigned int nrrd_access_limiter_2_1 : 4;
        unsigned int nrrd_access_limiter_3_1 : 4;
        unsigned int reserved_0 : 8;
        unsigned int nrrd_access_limiter_reload_1 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_1_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_1_nrrd_access_limiter_0_1_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_1_nrrd_access_limiter_0_1_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_1_nrrd_access_limiter_1_1_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_1_nrrd_access_limiter_1_1_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_1_nrrd_access_limiter_2_1_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_1_nrrd_access_limiter_2_1_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_1_nrrd_access_limiter_3_1_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_1_nrrd_access_limiter_3_1_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_1_nrrd_access_limiter_reload_1_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_1_nrrd_access_limiter_reload_1_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int reserved_0 : 5;
        unsigned int nrrd_allocated_du_2 : 5;
        unsigned int reserved_1 : 4;
        unsigned int nr_rd_slowdown_enable_2 : 1;
        unsigned int reserved_2 : 16;
        unsigned int nrrd_enable_2 : 1;
    } reg;
} SOC_ISP_CVDR_CVDR_NR_RD_CFG_2_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_2_nrrd_allocated_du_2_START (5)
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_2_nrrd_allocated_du_2_END (9)
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_2_nr_rd_slowdown_enable_2_START (14)
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_2_nr_rd_slowdown_enable_2_END (14)
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_2_nrrd_enable_2_START (31)
#define SOC_ISP_CVDR_CVDR_NR_RD_CFG_2_nrrd_enable_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_rd_debug_2 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_NR_RD_DEBUG_2_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_NR_RD_DEBUG_2_nr_rd_debug_2_START (0)
#define SOC_ISP_CVDR_CVDR_NR_RD_DEBUG_2_nr_rd_debug_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nrrd_access_limiter_0_2 : 4;
        unsigned int nrrd_access_limiter_1_2 : 4;
        unsigned int nrrd_access_limiter_2_2 : 4;
        unsigned int nrrd_access_limiter_3_2 : 4;
        unsigned int reserved_0 : 8;
        unsigned int nrrd_access_limiter_reload_2 : 4;
        unsigned int reserved_1 : 4;
    } reg;
} SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_2_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_2_nrrd_access_limiter_0_2_START (0)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_2_nrrd_access_limiter_0_2_END (3)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_2_nrrd_access_limiter_1_2_START (4)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_2_nrrd_access_limiter_1_2_END (7)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_2_nrrd_access_limiter_2_2_START (8)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_2_nrrd_access_limiter_2_2_END (11)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_2_nrrd_access_limiter_3_2_START (12)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_2_nrrd_access_limiter_3_2_END (15)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_2_nrrd_access_limiter_reload_2_START (24)
#define SOC_ISP_CVDR_CVDR_LIMITER_NR_RD_2_nrrd_access_limiter_reload_2_END (27)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_0 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_0_debug_0_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_0_debug_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_1 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_1_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_1_debug_1_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_1_debug_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_2 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_2_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_2_debug_2_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_2_debug_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_3 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_3_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_3_debug_3_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_3_debug_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_4 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_4_debug_4_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_4_debug_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_5 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_5_debug_5_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_5_debug_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_6 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_6_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_6_debug_6_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_6_debug_6_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_7 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_7_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_7_debug_7_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_7_debug_7_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_8 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_8_debug_8_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_8_debug_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_9 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_9_debug_9_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_9_debug_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_10 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_10_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_10_debug_10_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_10_debug_10_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_11 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_11_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_11_debug_11_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_11_debug_11_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_12 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_12_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_12_debug_12_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_12_debug_12_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_13 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_13_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_13_debug_13_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_13_debug_13_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_14 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_14_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_14_debug_14_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_14_debug_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int debug_15 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_DEBUG_15_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_DEBUG_15_debug_15_START (0)
#define SOC_ISP_CVDR_CVDR_DEBUG_15_debug_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_rd_mid_1 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_NR_RD_1_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_NR_RD_1_nr_rd_mid_1_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_NR_RD_1_nr_rd_mid_1_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int nr_rd_mid_2 : 5;
        unsigned int reserved : 27;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_NR_RD_2_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_NR_RD_2_nr_rd_mid_2_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_NR_RD_2_nr_rd_mid_2_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_0 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_0 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_0_vp_wr_mid_0_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_0_vp_wr_mid_0_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_0_vp_wr_sid_0_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_0_vp_wr_sid_0_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_1 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_1 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_1_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_1_vp_wr_mid_1_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_1_vp_wr_mid_1_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_1_vp_wr_sid_1_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_1_vp_wr_sid_1_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_4 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_4 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_4_vp_wr_mid_4_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_4_vp_wr_mid_4_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_4_vp_wr_sid_4_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_4_vp_wr_sid_4_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_5 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_5 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_5_vp_wr_mid_5_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_5_vp_wr_mid_5_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_5_vp_wr_sid_5_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_5_vp_wr_sid_5_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_8 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_8 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_8_vp_wr_mid_8_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_8_vp_wr_mid_8_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_8_vp_wr_sid_8_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_8_vp_wr_sid_8_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_9 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_9 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_9_vp_wr_mid_9_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_9_vp_wr_mid_9_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_9_vp_wr_sid_9_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_9_vp_wr_sid_9_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_14 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_14 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_14_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_14_vp_wr_mid_14_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_14_vp_wr_mid_14_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_14_vp_wr_sid_14_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_14_vp_wr_sid_14_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_15 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_15 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_15_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_15_vp_wr_mid_15_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_15_vp_wr_mid_15_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_15_vp_wr_sid_15_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_15_vp_wr_sid_15_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_16 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_16 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_16_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_16_vp_wr_mid_16_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_16_vp_wr_mid_16_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_16_vp_wr_sid_16_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_16_vp_wr_sid_16_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_17 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_17 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_17_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_17_vp_wr_mid_17_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_17_vp_wr_mid_17_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_17_vp_wr_sid_17_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_17_vp_wr_sid_17_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_18 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_18 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_18_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_18_vp_wr_mid_18_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_18_vp_wr_mid_18_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_18_vp_wr_sid_18_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_18_vp_wr_sid_18_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_19 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_19 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_19_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_19_vp_wr_mid_19_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_19_vp_wr_mid_19_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_19_vp_wr_sid_19_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_19_vp_wr_sid_19_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_20 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_20 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_20_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_20_vp_wr_mid_20_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_20_vp_wr_mid_20_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_20_vp_wr_sid_20_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_20_vp_wr_sid_20_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_21 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_21 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_21_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_21_vp_wr_mid_21_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_21_vp_wr_mid_21_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_21_vp_wr_sid_21_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_21_vp_wr_sid_21_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_22 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_22 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_22_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_22_vp_wr_mid_22_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_22_vp_wr_mid_22_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_22_vp_wr_sid_22_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_22_vp_wr_sid_22_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_23 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_23 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_23_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_23_vp_wr_mid_23_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_23_vp_wr_mid_23_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_23_vp_wr_sid_23_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_23_vp_wr_sid_23_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_24 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_24 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_24_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_24_vp_wr_mid_24_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_24_vp_wr_mid_24_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_24_vp_wr_sid_24_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_24_vp_wr_sid_24_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_25 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_25 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_25_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_25_vp_wr_mid_25_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_25_vp_wr_mid_25_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_25_vp_wr_sid_25_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_25_vp_wr_sid_25_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_26 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_26 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_26_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_26_vp_wr_mid_26_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_26_vp_wr_mid_26_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_26_vp_wr_sid_26_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_26_vp_wr_sid_26_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_mid_27 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_wr_sid_27 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_27_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_27_vp_wr_mid_27_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_27_vp_wr_mid_27_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_27_vp_wr_sid_27_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_WR_27_vp_wr_sid_27_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_mid_0 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_rd_sid_0 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_0_vp_rd_mid_0_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_0_vp_rd_mid_0_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_0_vp_rd_sid_0_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_0_vp_rd_sid_0_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_mid_4 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_rd_sid_4 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_4_vp_rd_mid_4_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_4_vp_rd_mid_4_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_4_vp_rd_sid_4_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_4_vp_rd_sid_4_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_mid_5 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_rd_sid_5 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_5_vp_rd_mid_5_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_5_vp_rd_mid_5_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_5_vp_rd_sid_5_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_5_vp_rd_sid_5_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_mid_6 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_rd_sid_6 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_6_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_6_vp_rd_mid_6_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_6_vp_rd_mid_6_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_6_vp_rd_sid_6_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_6_vp_rd_sid_6_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_mid_7 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_rd_sid_7 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_7_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_7_vp_rd_mid_7_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_7_vp_rd_mid_7_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_7_vp_rd_sid_7_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_7_vp_rd_sid_7_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_mid_8 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_rd_sid_8 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_8_vp_rd_mid_8_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_8_vp_rd_mid_8_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_8_vp_rd_sid_8_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_8_vp_rd_sid_8_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_mid_9 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_rd_sid_9 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_9_vp_rd_mid_9_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_9_vp_rd_mid_9_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_9_vp_rd_sid_9_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_9_vp_rd_sid_9_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_rd_mid_10 : 5;
        unsigned int reserved_0 : 3;
        unsigned int vp_rd_sid_10 : 6;
        unsigned int reserved_1 : 18;
    } reg;
} SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_10_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_10_vp_rd_mid_10_START (0)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_10_vp_rd_mid_10_END (4)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_10_vp_rd_sid_10_START (8)
#define SOC_ISP_CVDR_CVDR_AXI_CFG_VP_RD_10_vp_rd_sid_10_END (13)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spare_0 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_SPARE_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_SPARE_0_spare_0_START (0)
#define SOC_ISP_CVDR_CVDR_SPARE_0_spare_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spare_1 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_SPARE_1_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_SPARE_1_spare_1_START (0)
#define SOC_ISP_CVDR_CVDR_SPARE_1_spare_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spare_2 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_SPARE_2_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_SPARE_2_spare_2_START (0)
#define SOC_ISP_CVDR_CVDR_SPARE_2_spare_2_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int spare_3 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_SPARE_3_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_SPARE_3_spare_3_START (0)
#define SOC_ISP_CVDR_CVDR_SPARE_3_spare_3_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_0 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_0_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_0_vp_wr_debug_0_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_0_vp_wr_debug_0_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_1 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_1_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_1_vp_wr_debug_1_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_1_vp_wr_debug_1_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_4 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_4_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_4_vp_wr_debug_4_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_4_vp_wr_debug_4_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_5 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_5_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_5_vp_wr_debug_5_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_5_vp_wr_debug_5_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_8 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_8_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_8_vp_wr_debug_8_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_8_vp_wr_debug_8_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_9 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_9_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_9_vp_wr_debug_9_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_9_vp_wr_debug_9_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_14 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_14_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_14_vp_wr_debug_14_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_14_vp_wr_debug_14_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_15 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_15_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_15_vp_wr_debug_15_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_15_vp_wr_debug_15_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_16 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_16_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_16_vp_wr_debug_16_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_16_vp_wr_debug_16_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_17 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_17_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_17_vp_wr_debug_17_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_17_vp_wr_debug_17_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_18 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_18_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_18_vp_wr_debug_18_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_18_vp_wr_debug_18_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_19 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_19_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_19_vp_wr_debug_19_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_19_vp_wr_debug_19_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_20 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_20_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_20_vp_wr_debug_20_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_20_vp_wr_debug_20_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_21 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_21_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_21_vp_wr_debug_21_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_21_vp_wr_debug_21_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_22 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_22_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_22_vp_wr_debug_22_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_22_vp_wr_debug_22_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_23 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_23_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_23_vp_wr_debug_23_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_23_vp_wr_debug_23_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_24 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_24_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_24_vp_wr_debug_24_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_24_vp_wr_debug_24_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_25 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_25_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_25_vp_wr_debug_25_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_25_vp_wr_debug_25_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_26 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_26_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_26_vp_wr_debug_26_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_26_vp_wr_debug_26_END (31)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned int value;
    struct
    {
        unsigned int vp_wr_debug_27 : 32;
    } reg;
} SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_27_UNION;
#endif
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_27_vp_wr_debug_27_START (0)
#define SOC_ISP_CVDR_CVDR_VP_WR_DEBUG_27_vp_wr_debug_27_END (31)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
