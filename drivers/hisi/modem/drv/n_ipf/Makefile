-include $(srctree)/drivers/hisi/modem/config/product/$(OBB_PRODUCT_NAME)/config/balong_product_config.mk
obj-$(CONFIG_IPF_SUPPORT)           += ipf_balong.o ipf_pm.o ipf_filter.o ipf_debug.o
obj-$(CONFIG_ENABLE_TEST_CODE)   	+= ipf_balong_test.o

ifeq ($(strip $(CFG_CONFIG_MODULE_BUSSTRESS)),YES)
obj-$(CONFIG_IPF_SUPPORT) 		    += ipf_stress_test.o
endif

ifeq ($(strip $(llt_gcov)),y)
GCOV_PROFILE_ipf_balong.o := y
GCOV_PROFILE_ipf_pm.o := y
GCOV_PROFILE_ipf_filter.o := y
GCOV_PROFILE_ipf_debug.o := y
endif
