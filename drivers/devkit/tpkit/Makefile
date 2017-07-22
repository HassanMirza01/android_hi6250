# Makefile for the irda drivers.
#

# Each configuration option enables a list of files.

mkfile_path := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
ifeq ($(mkfile_path)/hisi_adapter/Makefile, $(wildcard $(mkfile_path)/hisi_adapter/Makefile))
obj-$(CONFIG_HUAWEI_TS_KIT) += hisi_adapter/
$(info find tpkit hisi adapter folder, include it now!)
endif

ifeq ($(mkfile_path)/qcom_adapter/Makefile, $(wildcard $(mkfile_path)/qcom_adapter/Makefile))
obj-$(CONFIG_HUAWEI_TS_KIT) += qcom_adapter/
$(info find tpkit qcom adapter folder, include it now!)
endif

obj-$(CONFIG_HUAWEI_TS_KIT)  += huawei_ts_kit_core.o
obj-$(CONFIG_HUAWEI_TS_KIT)  += huawei_ts_kit_fsnode.o
obj-$(CONFIG_HUAWEI_TS_KIT)  += huawei_ts_kit_api.o
obj-$(CONFIG_HUAWEI_TS_KIT)  += huawei_ts_kit_algo.o
obj-$(CONFIG_HUAWEI_TS_KIT)  += panel/

obj-$(CONFIG_HUAWEI_TS_KIT)  += huawei_ts_kit_csvparse.o
obj-$(CONFIG_HUAWEI_TS_KIT_TEST)  += huawei_ts_kit_test.o
obj-$(CONFIG_HUAWEI_TP_KIT_COLOR_INFO) += tp_color.o
ifeq ($(CONFIG_HUAWEI_TS_KIT_TEST),y)
EXTRA_CFLAGS += -DHUAWEI_TS_KIT_TEST
endif
EXTRA_CFLAGS += -Idrivers/hisi/tzdriver
EXTRA_CFLAGS += -Idrivers/tzdriver