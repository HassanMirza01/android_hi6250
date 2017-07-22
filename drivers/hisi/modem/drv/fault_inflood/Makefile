ccflags-y += -I$(BALONG_TOPDIR)/modem/drv/acore/kernel/drivers/hisi/modem/drv/nvim

ifeq ($(strip $(llt_gcov)),y)
GCOV_PROFILE := y
endif

obj-y += fault_inflood_acore.o
obj-y += fault_inflood_nv_atc.o
