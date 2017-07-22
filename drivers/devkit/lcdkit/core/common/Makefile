obj-$(CONFIG_LCDKIT_DRIVER)	+= lcdkit_panel.o
obj-$(CONFIG_LCDKIT_DRIVER)	+= lcdkit_fb_util.o
obj-$(CONFIG_LCDKIT_DRIVER)	+= lcdkit_debug.o
obj-$(CONFIG_LCDKIT_DRIVER)	+= lcdkit_parse.o


mkfile_path := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
ifeq ($(mkfile_path)/hisi/Makefile, $(wildcard $(mkfile_path)/hisi/Makefile))
obj-$(CONFIG_LCDKIT_DRIVER) += hisi/
$(info find lcdkit hisi folder, include it now!)
endif

ifeq ($(mkfile_path)/qcom/Makefile, $(wildcard $(mkfile_path)/qcom/Makefile))
obj-$(CONFIG_LCDKIT_DRIVER) += qcom/
$(info find lcdkit qcom folder, include it now! )
endif

#for debug!!
#$(error stop! $(mkfile_path))

EXTRA_CFLAGS += -Idrivers/devkit/lcdkit/include	\
		-Idrivers/devkit/tpkit