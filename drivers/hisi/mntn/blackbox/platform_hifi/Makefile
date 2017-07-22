obj-y += rdr_hisi_audio_adapter.o
obj-y += rdr_hisi_audio_codec.o
obj-y += rdr_hisi_audio_soc.o

EXTRA_CFLAGS += -Idrivers/hisi/hifi_dsp/
EXTRA_CFLAGS += -Idrivers/hisi/hi64xx_dsp/
EXTRA_CFLAGS += -Idrivers/hisi/mntn/blackbox/

ccflags-y += -I$(srctree)/drivers/hisi/tzdriver

ifeq ($(CONFIG_HIFI_IPC_3660),y)
EXTRA_CFLAGS += -DSECOS_RELOAD_HIFI
endif

EXTRA_CFLAGS += -DRDR_CODECDSP
EXTRA_CFLAGS += -DRDR_SOCHIFI
