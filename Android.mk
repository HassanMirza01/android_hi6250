#Android makefile to build kernel as a part of Android Build
ifeq ($(BALONG_TOPDIR),)
export BALONG_TOPDIR := $(shell pwd)/vendor/hisi
endif

export SRCHI1101=drivers/misc/hw-drv

kernel_path := kernel/linux-4.1

#ifeq ($(TARGET_PREBUILT_KERNEL),)

export OBB_PRODUCT_NAME ?= $(HISI_TARGET_PRODUCT)

ifeq ($(strip $(TARGET_BOARD_PLATFORM)), hi3650)
HISI_MODEM_DEFCONFIG := vendor/hisi/modem/config/product/$(OBB_PRODUCT_NAME)/os/acore/hi3650_modem_defconfig
endif

ifeq ($(strip $(TARGET_BOARD_PLATFORM)), hi6250)
HISI_MODEM_DEFCONFIG := vendor/hisi/modem/config/product/$(OBB_PRODUCT_NAME)/os/acore/hi6250_modem_defconfig
endif

ifeq ($(strip $(TARGET_BOARD_PLATFORM)), hi3660)
HISI_MODEM_DEFCONFIG := vendor/hisi/modem/config/product/$(OBB_PRODUCT_NAME)/os/acore/hi3660_modem_defconfig
endif

ifeq ($(strip $(TARGET_BOARD_PLATFORM)), kirin970)
HISI_MODEM_DEFCONFIG := vendor/hisi/modem/config/product/$(OBB_PRODUCT_NAME)/os/acore/kirin970_modem_defconfig
endif

ifneq ($(WITH_USERDATA_FILE_ENCRYPT), true)
KERNEL_UPDATE_PRODUCT_CONFIG_OVERRIDE += CONFIG_HISI_BLK_INLINE_CRYPTO=n
KERNEL_UPDATE_PRODUCT_CONFIG_OVERRIDE += CONFIG_F2FS_FS_ENCRYPTION=n
KERNEL_UPDATE_PRODUCT_CONFIG_OVERRIDE += CONFIG_FS_ENCRYPTION=n
KERNEL_UPDATE_PRODUCT_CONFIG_OVERRIDE += CONFIG_ENCRYPTED_KEYS=n
endif

ifeq ($(OBB_PRINT_CMD), true)
KERNEL_OUT := vendor/hisi/build/delivery/$(OBB_PRODUCT_NAME)/obj/android
else
KERNEL_OUT := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ
endif
KERNEL_CONFIG := $(KERNEL_OUT)/.config

ifeq ($(TARGET_ARM_TYPE), arm64)
KERNEL_ARCH_PREFIX := arm64
CROSS_COMPILE_PREFIX=aarch64-linux-android-
TARGET_PREBUILT_KERNEL := $(KERNEL_OUT)/arch/arm64/boot/Image.gz
else
KERNEL_ARCH_PREFIX := arm
CROSS_COMPILE_PREFIX=arm-linux-gnueabihf-
TARGET_PREBUILT_KERNEL := $(KERNEL_OUT)/arch/arm/boot/zImage
endif

ifeq ($(CFG_CONFIG_HISI_FAMA),true)
BALONG_FAMA_FLAGS := -DCONFIG_HISI_FAMA
else
BALONG_FAMA_FLAGS :=
endif

export BALONG_INC
export BALONG_FAMA_FLAGS

KERNEL_N_TARGET ?= vmlinux
UT_EXTRA_CONFIG ?=

KERNEL_ARCH_ARM_CONFIGS := $(shell pwd)/$(kernel_path)/arch/$(KERNEL_ARCH_PREFIX)/configs
KERNEL_GEN_CONFIG_FILE := hw_$(TARGET_PRODUCT)_defconfig
KERNEL_GEN_CONFIG_PATH := $(KERNEL_ARCH_ARM_CONFIGS)/$(KERNEL_GEN_CONFIG_FILE)

ifneq ($(WITH_USERDATA_FILE_ENCRYPT), true)
KERNEL_M_N_CONFIG_FILE = $(TARGET_PRODUCT)_m_n_defconfig
KERNEL_M_N_CONFIG_PATH := $(KERNEL_ARCH_ARM_CONFIGS)/$(KERNEL_M_N_CONFIG_FILE)
KERNEL_TEMP_CONFIG_PATH := $(KERNEL_ARCH_ARM_CONFIGS)/temp_defconfig
endif

KERNEL_COMMON_DEFCONFIG := $(KERNEL_ARCH_ARM_CONFIGS)/$(KERNEL_DEFCONFIG)
KERNEL_PRODUCT_CONFIGS := $(shell pwd)/device/hisi/customize/config/${TARGET_ARM_TYPE}/$(TARGET_DEVICE)/${TARGET_PRODUCT}/product_config/kernel_config
KERNEL_DEBUG_CONFIGS := $(KERNEL_ARCH_ARM_CONFIGS)/eng_defconfig/$(TARGET_BOARD_PLATFORM)
KERNEL_KASAN_CONFIGS := $(KERNEL_ARCH_ARM_CONFIGS)/eng_defconfig/kasan
KERNEL_ENG_DEBUG_CONFIGS := $(KERNEL_ARCH_ARM_CONFIGS)/eng_defconfig/debug

ifeq ($(strip $(TARGET_PRODUCT)), hisi_pilot)
KERNEL_PRODUCT_CONFIGS := $(shell pwd)/device/hisi/customize/config/${TARGET_ARM_TYPE}/hi6220/${TARGET_PRODUCT}/product_config/kernel_config
endif

DTS_AUTO_GENERATE:= $(ANDROID_BUILD_TOP)/kernel/$(LINUX_VERSION)/arch/arm64/boot/dts/auto-generate
DTS_KERNEL_OUT:= $(ANDROID_BUILD_TOP)/out/target/product/$(TARGET_PRODUCT)/obj/KERNEL_OBJ/arch/arm64/boot/dts/auto-generate
define DTS_PARSE_CONFIG
@echo generating dtsi files, please wait for minutes!
@cd device/hisi/customize/build_script; ./auto_dts_gen.sh ${DTS_AUTO_GENERATE} ${DTS_KERNEL_OUT} $(LINUX_VERSION) > $(ANDROID_BUILD_TOP)/auto_dts_gen.log 2>&1
endef

HI3650_MODEM_DRV_DIR := $(shell pwd)/vendor/hisi/modem/drv/acore/kernel/drivers/hisi/modem/drv
ifeq ($(wildcard $(HI3650_MODEM_DRV_DIR)),)
$(HI3650_MODEM_DRV_DIR):
	@$(INC_PLUS)mkdir -p $(HI3650_MODEM_DRV_DIR)
	@$(INC_PLUS)touch $(HI3650_MODEM_DRV_DIR)/Makefile
	@$(INC_PLUS)touch $(HI3650_MODEM_DRV_DIR)/Kconfig
endif

HISI_PILOT_KERNEL_DIR := $(shell pwd)/$(kernel_path)/drivers/hisi_pilot/
DEPENDENCY_FILELIST := $(shell find $(ANDROID_BUILD_TOP)/device/hisi/customize/config/$(KERNEL_ARCH_PREFIX)/$(TARGET_BOARD_PLATFORM)/$(TARGET_PRODUCT)/board_config -name config.dts -type f 2>/dev/null | xargs echo)
DEPENDENCY_FILELIST += $(shell find $(ANDROID_BUILD_TOP)/device/hisi/customize/dtsi/$(KERNEL_ARCH_PREFIX)/$(TARGET_BOARD_PLATFORM) -type f 2>/dev/null | xargs echo)
GPIO_DEPENDENCY_FILELIST = $(shell find $(ANDROID_BUILD_TOP)/device/hisi/customize/config/$(KERNEL_ARCH_PREFIX)/$(TARGET_BOARD_PLATFORM)/$(TARGET_PRODUCT)/board_config -name iomux.xml -type f 2>/dev/null | xargs echo)
DEPENDENCY_FILELIST += $(GPIO_DEPENDENCY_FILELIST) $(shell find $(ANDROID_BUILD_TOP)/vendor/huawei/extra/power/batt_raw_data/data/$(TARGET_BOARD_PLATFORM) -name "*.xlsx" -type f 2>/dev/null | xargs echo)
DEPENDENCY_FILELIST += $(shell find $(ANDROID_BUILD_TOP)/vendor/huawei_platform/power/batt_raw_data/data/$(TARGET_BOARD_PLATFORM) -name "*.xlsx" -type f 2>/dev/null | xargs echo)

ifeq ($(strip $(CFG_HISI_MINI_AP)), false)
ifneq ($(wildcard $(HISI_MODEM_DEFCONFIG)),)
APPEND_MODEM_DEFCONFIG := cat $(HISI_MODEM_DEFCONFIG) >> $(KERNEL_GEN_CONFIG_PATH)
endif
endif

ifneq ($(TARGET_BUILD_VARIANT),eng)
KERNEL_DEBUG_CONFIGFILE := $(KERNEL_COMMON_DEFCONFIG)
KERNEL_TOBECLEAN_CONFIGFILE :=
KERNEL_KASAN_CONFIGFILE :=

$(KERNEL_DEBUG_CONFIGFILE):
	echo "will not compile debug modules"

else
ifeq ($(strip $(KERNEL_DEBUG)),false)
KERNEL_DEBUG_CONFIGFILE := $(KERNEL_COMMON_DEFCONFIG)
KERNEL_TOBECLEAN_CONFIGFILE :=
KERNEL_KASAN_CONFIGFILE :=
else
KERNEL_DEBUG_CONFIGFILE :=  $(KERNEL_ARCH_ARM_CONFIGS)/hisi_$(TARGET_PRODUCT)_debug_defconfig
KERNEL_TOBECLEAN_CONFIGFILE := $(KERNEL_DEBUG_CONFIGFILE)

ifeq ($(ENG_DEBUG_VERSION),true)
KERNEL_ENG_DEBUG_CONFIGFILE := $(KERNEL_ARCH_ARM_CONFIGS)/hisi_$(TARGET_PRODUCT)_eng_debug_defconfig
$(KERNEL_ENG_DEBUG_CONFIGFILE):$(KERNEL_COMMON_DEFCONFIG) $(wildcard $(KERNEL_ENG_DEBUG_CONFIGS)/*)
	touch $(KERNEL_ENG_DEBUG_CONFIGFILE)
	@$(INC_PLUS)$(ANDROID_BUILD_TOP)/device/hisi/customize/build_script/kernel-config.sh -f $(KERNEL_COMMON_DEFCONFIG) -d $(KERNEL_ENG_DEBUG_CONFIGS) -o $(KERNEL_ENG_DEBUG_CONFIGFILE)

$(KERNEL_DEBUG_CONFIGFILE):$(KERNEL_ENG_DEBUG_CONFIGFILE) $(wildcard $(KERNEL_DEBUG_CONFIGS)/*)
	touch $(KERNEL_DEBUG_CONFIGFILE)
	@$(INC_PLUS)$(ANDROID_BUILD_TOP)/device/hisi/customize/build_script/kernel-config.sh -f $(KERNEL_ENG_DEBUG_CONFIGFILE) -d $(KERNEL_DEBUG_CONFIGS) -o $(KERNEL_DEBUG_CONFIGFILE)
else
KERNEL_ENG_DEBUG_CONFIGFILE :=
ifneq ($(TARGET_SANITIZER_MODE),)
KERNEL_KASAN_CONFIGFILE := $(KERNEL_ARCH_ARM_CONFIGS)/hisi_$(TARGET_PRODUCT)_kasan_defconfig

$(KERNEL_KASAN_CONFIGFILE):$(KERNEL_COMMON_DEFCONFIG) $(wildcard $(KERNEL_KASAN_CONFIGS)/*)
	@$(INC_PLUS)$(ANDROID_BUILD_TOP)/device/hisi/customize/build_script/kernel-config.sh -f $(KERNEL_COMMON_DEFCONFIG) -d $(KERNEL_KASAN_CONFIGS) -o $(KERNEL_KASAN_CONFIGFILE)

$(KERNEL_DEBUG_CONFIGFILE):$(KERNEL_KASAN_CONFIGFILE) $(wildcard $(KERNEL_DEBUG_CONFIGS)/*)
	@$(INC_PLUS)$(ANDROID_BUILD_TOP)/device/hisi/customize/build_script/kernel-config.sh -f $(KERNEL_KASAN_CONFIGFILE) -d $(KERNEL_DEBUG_CONFIGS) -o $(KERNEL_DEBUG_CONFIGFILE)
else
KERNEL_KASAN_CONFIGFILE :=
$(KERNEL_DEBUG_CONFIGFILE):$(KERNEL_COMMON_DEFCONFIG) $(wildcard $(KERNEL_DEBUG_CONFIGS)/*)
	@$(INC_PLUS)$(ANDROID_BUILD_TOP)/device/hisi/customize/build_script/kernel-config.sh -f $(KERNEL_COMMON_DEFCONFIG) -d $(KERNEL_DEBUG_CONFIGS) -o $(KERNEL_DEBUG_CONFIGFILE)
endif
endif
endif
endif

GENERATE_DTB := $(KERNEL_OUT)/.timestamp
$(GENERATE_DTB):$(DEPENDENCY_FILELIST)
	$(DTS_PARSE_CONFIG)
	@mkdir -p $(KERNEL_OUT)
	@touch $@

ifeq ($(strip $(llt_gcov)),y)
HISI_MDRV_GCOV_DEFCONFIG := ${KERNEL_ARCH_ARM_CONFIGS}/gcov_defconfig
APPEND_MODEM_GCOV_DEFCONFIG := cat $(HISI_MDRV_GCOV_DEFCONFIG) >> $(KERNEL_GEN_CONFIG_PATH)
endif

$(KERNEL_GEN_CONFIG_PATH): $(KERNEL_DEBUG_CONFIGFILE) $(wildcard $(KERNEL_PRODUCT_CONFIGS)/*)
	$(hide) echo GENERATING $(KERNEL_GEN_CONFIG_FILE) ...
ifneq ($(WITH_USERDATA_FILE_ENCRYPT), true)
	$(INC_PLUS)$(shell $(ANDROID_BUILD_TOP)/device/hisi/customize/build_script/kernel-config.sh -f $(KERNEL_DEBUG_CONFIGFILE) -d $(KERNEL_PRODUCT_CONFIGS) -o $(KERNEL_TEMP_CONFIG_PATH))
	$(hide) echo "Overriding kernel config with '$(KERNEL_UPDATE_PRODUCT_CONFIG_OVERRIDE)'";
	$(hide) for CONFIG_UPDATE_PRODUCT_OVERRIDE in $(KERNEL_UPDATE_PRODUCT_CONFIG_OVERRIDE); do echo $$CONFIG_UPDATE_PRODUCT_OVERRIDE >> $(KERNEL_M_N_CONFIG_PATH); done;
	$(INC_PLUS)$(shell $(ANDROID_BUILD_TOP)/device/hisi/customize/build_script/kernel-config.sh -f $(KERNEL_TEMP_CONFIG_PATH) -d $(KERNEL_ARCH_ARM_CONFIGS) -p $(KERNEL_M_N_CONFIG_FILE) -o $(KERNEL_GEN_CONFIG_PATH))
	@rm -frv $(KERNEL_M_N_CONFIG_PATH)
	@rm -frv $(KERNEL_TEMP_CONFIG_PATH)
else
	$(INC_PLUS)$(shell $(ANDROID_BUILD_TOP)/device/hisi/customize/build_script/kernel-config.sh -f $(KERNEL_DEBUG_CONFIGFILE) -d $(KERNEL_PRODUCT_CONFIGS) -o $(KERNEL_GEN_CONFIG_PATH))
endif
ifdef APPEND_MODEM_DEFCONFIG
	$(APPEND_MODEM_DEFCONFIG)
endif
ifeq ($(strip $(llt_gcov)),y)
	$(shell $(APPEND_MODEM_GCOV_DEFCONFIG))
endif

kernel_modem_config : $(KERNEL_GEN_CONFIG_PATH)
	@echo $@

ifeq ($(OBB_PRINT_CMD), true)
$(KERNEL_CONFIG): MAKEFLAGS :=
$(KERNEL_CONFIG):$(KERNEL_GEN_CONFIG_PATH) $(HI3650_MODEM_DRV_DIR)
	$(INC_PLUS)mkdir -p $(KERNEL_OUT)
	$(INC_PLUS)$(MAKE) -C $(kernel_path) O=../../$(KERNEL_OUT) ARCH=$(KERNEL_ARCH_PREFIX) CROSS_COMPILE=$(CROSS_COMPILE_PREFIX) $(KERNEL_GEN_CONFIG_FILE)
else
ifeq ($(HISI_PILOT_LIBS), true)
$(KERNEL_CONFIG): $(KERNEL_GEN_CONFIG_PATH) HISI_PILOT_PREBUILD $(HI3650_MODEM_DRV_DIR)
else
$(KERNEL_CONFIG): $(KERNEL_GEN_CONFIG_PATH) $(HI3650_MODEM_DRV_DIR)
endif
	mkdir -p $(KERNEL_OUT)
	$(MAKE) -C $(kernel_path) O=../../$(KERNEL_OUT) ARCH=$(KERNEL_ARCH_PREFIX) CROSS_COMPILE=$(CROSS_COMPILE_PREFIX) $(KERNEL_GEN_CONFIG_FILE)
endif

########Auto gen lcd effect parameter#######
ifeq ($(strip $(TARGET_BOARD_PLATFORM)), hi6250)
export LCD_EFFECT_DIR := $(shell pwd)/$(KERNEL_OUT)
LCD_EFFECT_TOOLS_PATH = vendor/huawei/extra/kernel/drivers/lcd/tools
LCD_EFFECT_FILE_PATH = $(LCD_EFFECT_DIR)/drivers/huawei_platform/lcd
LCD_EFFECT_FILE := $(LCD_EFFECT_FILE_PATH)/hw_lcd_effects.h
export PERLPATH := $(shell pwd)/vendor/huawei/extra/kernel/drivers/lcd/tools
$(LCD_EFFECT_FILE):
	@$(INC_PLUS)mkdir -p $(LCD_EFFECT_FILE_PATH)
	@$(INC_PLUS)cd $(LCD_EFFECT_TOOLS_PATH);export PERL5LIB=$(PERLPATH)/localperl/lib/site_perl/5.14.2/x86_64-linux-thread-multi:$(PERLPATH)/localperl/lib/site_perl/5.14.2:$(PERLPATH)/localperl/lib/5.14.2/x86_64-linux-thread-multi:$(PERLPATH)/localperl/lib/5.14.2;\
	./localperl/bin/perl hw_panel_gen_effect_h.pl $(LCD_EFFECT_FILE_PATH)
$(TARGET_PREBUILT_KERNEL): $(LCD_EFFECT_FILE)
endif
############################################
ifeq ($(strip $(TARGET_BOARD_PLATFORM)), hi6250)
export LCDKIT_EFFECT_DIR := $(shell pwd)/$(KERNEL_OUT)
LCDKIT_EFFECT_TOOLS_PATH = vendor/huawei/extra/kernel/drivers/lcd/tools
LCDKIT_EFFECT_FILE_PATH = $(LCDKIT_EFFECT_DIR)/drivers/devkit/lcdkit/
LCDKIT_EFFECT_FILE := $(LCDKIT_EFFECT_FILE_PATH)/lcdkit_effects.h
export LCDKIT_PERLPATH := $(shell pwd)/vendor/huawei/extra/kernel/drivers/lcd/tools
$(LCDKIT_EFFECT_FILE):
	@$(INC_PLUS)mkdir -p $(LCDKIT_EFFECT_FILE_PATH)
	@$(INC_PLUS)cd $(LCDKIT_EFFECT_TOOLS_PATH);export PERL5LIB=$(LCDKIT_PERLPATH)/localperl/lib/5.14.2/x86_64-linux-thread-multi:$(LCDKIT_PERLPATH)/localperl/lib/5.14.2;\
	./localperl/bin/perl ../../../../../chipset_common/devkit/lcdkit/lcdkit_tool/lcdkitparser.pl $(strip $(TARGET_BOARD_PLATFORM)) effect $(LCDKIT_EFFECT_FILE_PATH)
$(TARGET_PREBUILT_KERNEL): $(LCDKIT_EFFECT_FILE)
endif
############################################
ifeq ($(strip $(TARGET_BOARD_PLATFORM)), hi3660)
export LCDKIT_EFFECT_DIR := $(shell pwd)/$(KERNEL_OUT)
LCDKIT_EFFECT_TOOLS_PATH = vendor/huawei/extra/kernel/drivers/lcd/tools
LCDKIT_EFFECT_FILE_PATH = $(LCDKIT_EFFECT_DIR)/drivers/devkit/lcdkit/
LCDKIT_EFFECT_FILE := $(LCDKIT_EFFECT_FILE_PATH)/lcdkit_effects.h
export LCDKIT_PERLPATH := $(shell pwd)/vendor/huawei/extra/kernel/drivers/lcd/tools
$(LCDKIT_EFFECT_FILE):
	@$(INC_PLUS)mkdir -p $(LCDKIT_EFFECT_FILE_PATH)
	@$(INC_PLUS)cd $(LCDKIT_EFFECT_TOOLS_PATH);export PERL5LIB=$(LCDKIT_PERLPATH)/localperl/lib/5.14.2/x86_64-linux-thread-multi:$(LCDKIT_PERLPATH)/localperl/lib/5.14.2;\
	./localperl/bin/perl ../../../../../chipset_common/devkit/lcdkit/lcdkit_tool/lcdkitparser.pl $(strip $(TARGET_BOARD_PLATFORM)) effect $(LCDKIT_EFFECT_FILE_PATH)
$(TARGET_PREBUILT_KERNEL): $(LCDKIT_EFFECT_FILE)
endif
############################################

GPIO_IOMUX_FILE := hisi_gpio_auto_gen.h
GPIO_LP_PATH := $(ANDROID_BUILD_TOP)/vendor/hisi/ap/kernel/include/linux/hisi
$(GPIO_IOMUX_FILE): $(GPIO_DEPENDENCY_FILELIST)
	@$(INC_PLUS)cd device/hisi/customize/build_script;perl ./gpio_complete_iomux_entry.pl $(KERNEL_ARCH_PREFIX) $(TARGET_BOARD_PLATFORM) "lp"; \
        python gen_pin_lp_config.py $(KERNEL_ARCH_PREFIX) $(TARGET_BOARD_PLATFORM) $(GPIO_LP_PATH)


ifeq ($(OBB_PRINT_CMD), true)
$(TARGET_PREBUILT_KERNEL): FORCE $(GPIO_IOMUX_FILE) | $(KERNEL_CONFIG)
	$(hide) $(MAKE) -C $(kernel_path) -j1 O=../../$(KERNEL_OUT) ARCH=$(KERNEL_ARCH_PREFIX) CROSS_COMPILE=$(CROSS_COMPILE_PREFIX) $(KERNEL_N_TARGET)
	mkdir -p $(KERNEL_OUT)/arch/arm64/boot
	touch $(TARGET_PREBUILT_KERNEL)
	@rm -frv $(KERNEL_TOBECLEAN_CONFIGFILE)
	@rm -frv $(KERNEL_KASAN_CONFIGFILE)
	@rm -frv $(KERNEL_ENG_DEBUG_CONFIGFILE)
	@rm -frv $(KERNEL_GEN_CONFIG_PATH)
else
$(TARGET_PREBUILT_KERNEL): FORCE  $(GPIO_IOMUX_FILE)  $(GENERATE_DTB) | $(KERNEL_CONFIG)
	#$(kernel_path)/scripts/copy_kernel_obj_to_out.sh $(kernel_path) $(KERNEL_OUT)
	$(MAKE) -C $(kernel_path) O=../../$(KERNEL_OUT) ARCH=$(KERNEL_ARCH_PREFIX) CROSS_COMPILE=$(CROSS_COMPILE_PREFIX)
	touch $(TARGET_PREBUILT_KERNEL)
	@rm -frv $(KERNEL_TOBECLEAN_CONFIGFILE)
	@rm -frv $(KERNEL_KASAN_CONFIGFILE)
	@rm -frv $(KERNEL_ENG_DEBUG_CONFIGFILE)
	@rm -frv $(KERNEL_GEN_CONFIG_PATH)
endif


HISI_PILOT_PREBUILD:
	$(hide) rm -rf $(kernel_path)/include/huawei_platform
	$(hide) rm -rf $(kernel_path)/include/modem
	$(hide) rm -rf $(kernel_path)/drivers/huawei_platform
	$(hide) rm -rf $(kernel_path)/drivers/huawei_platform_legacy
	$(hide) rm -rf $(kernel_path)/drivers/hisi/modem_hi6xxx
	$(hide) rm -rf $(kernel_path)/drivers/device-depend-arm64
	$(hide) cp -rf $(HISI_PILOT_TOPDIR)$(kernel_path)/include/huawei_platform $(kernel_path)/include/.
	$(hide) cp -rf $(HISI_PILOT_TOPDIR)$(kernel_path)/include/modem $(kernel_path)/include/.
	$(hide) cp -rf $(HISI_PILOT_TOPDIR)$(kernel_path)/drivers/huawei_platform $(kernel_path)/drivers/
	$(hide) cp -rf $(HISI_PILOT_TOPDIR)$(kernel_path)/drivers/huawei_platform_legacy $(kernel_path)/drivers/
	$(hide) cp -rf $(HISI_PILOT_TOPDIR)$(kernel_path)/drivers/hisi/modem_hi6xxx $(kernel_path)/drivers/hisi/.
	$(hide) cp $(HISI_PILOT_KERNEL_DIR)/Makefile.pilot $(HISI_PILOT_KERNEL_DIR)/Makefile
	$(hide) cp $(HISI_PILOT_KERNEL_DIR)/Kconfig.pilot $(HISI_PILOT_KERNEL_DIR)/Kconfig
ifeq ($(TARGET_VERSION_MODE),factory)
	$(hide) cd $(kernel_path)/drivers/; ln -s ../../../vendor/hisi_pilot/libs_factory/kernel/drivers/device-depend-arm64 device-depend-arm64
else
	$(hide) cd $(kernel_path)/drivers/; ln -s ../../../vendor/hisi_pilot/libs/kernel/drivers/device-depend-arm64 device-depend-arm64
endif

kernelconfig: $(KERNEL_GEN_CONFIG_PATH)
	mkdir -p $(KERNEL_OUT)
	$(MAKE) -C $(kernel_path) O=../../$(KERNEL_OUT) ARCH=$(KERNEL_ARCH_PREFIX) CROSS_COMPILE=$(CROSS_COMPILE_PREFIX) $(KERNEL_GEN_CONFIG_FILE) menuconfig

zImage Image:$(TARGET_PREBUILT_KERNEL)
	@mkdir -p $(dir $(INSTALLED_KERNEL_TARGET))
	@cp -fp $(TARGET_PREBUILT_KERNEL) $(INSTALLED_KERNEL_TARGET)

pclint_kernel: $(KERNEL_CONFIG)
	$(hide) $(MAKE) -C $(kernel_path) O=../../$(KERNEL_OUT) ARCH=$(KERNEL_ARCH_PREFIX) CROSS_COMPILE=$(CROSS_COMPILE_PREFIX) pc_lint_all

export BOARD_CHARGER_ENABLE_DRM
