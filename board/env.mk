#****************************************************************************
#
# Makefile
# 
# This is a GNU make (gmake) makefile
# Author:Dive
#****************************************************************************

SRC_TOPDIR :=$(shell pwd)
SDK_TOPDIR :=$(SRC_TOPDIR)/sdk/$(arm)
INSTALL_DIR:=$(SRC_TOPDIR)/lib/$(arm)
 
ifeq ($(arm),hisi3519)
CROSS_COMPILE	:=arm-hisiv600-linux-
CCFLAGS		:=-D_HW_VER=5 -mcpu=cortex-a17.cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -mno-unaligned-access -fno-aggressive-loop-optimizations
CXXFLAGS	:=-D_HW_VER=5 -mcpu=cortex-a17.cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -mno-unaligned-access -fno-aggressive-loop-optimizations

else ifeq ($(arm),hisi3516a)
CROSS_COMPILE	:=arm-hisiv400-linux-
CCFLAGS		:=-D_HW_VER=1 -mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -mno-unaligned-access -fno-aggressive-loop-optimizations
CXXFLAGS	:=-D_HW_VER=1 -mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -mno-unaligned-access -fno-aggressive-loop-optimizations

else ifeq ($(arm),hisi3516d)
CROSS_COMPILE	:=arm-hisiv400-linux-
CCFLAGS		:=-D_HW_VER=3 -mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -mno-unaligned-access -fno-aggressive-loop-optimizations
CXXFLAGS	:=-D_HW_VER=3 -mcpu=cortex-a7 -mfloat-abi=softfp -mfpu=neon-vfpv4 -mno-unaligned-access -fno-aggressive-loop-optimizations

else ifeq ($(arm),hisi3516c)
CROSS_COMPILE	:=arm-hisiv600-linux-
CCFLAGS		:=-D_HW_VER=2 -mcpu=arm926ej-s -mno-unaligned-access -fno-aggressive-loop-optimizations
CXXFLAGS	:=-D_HW_VER=2 -mcpu=arm926ej-s -mno-unaligned-access -fno-aggressive-loop-optimizations

else ifeq ($(arm),hisi3559)
CROSS_COMPILE	:=aarch64-himix100-linux-
CCFLAGS		:=-D_HW_VER=6 -DGOAHEAD_64
CXXFLAGS	:=-D_HW_VER=6 -DGOAHEAD_64

else ifeq ($(arm),hisi3531)
CROSS_COMPILE	:=arm-hisiv200-linux-
CCFLAGS		:=-D_HW_VER=7 -Wl,-gc-sections -march=armv7-a -mcpu=cortex-a9 -mfloat-abi=softfp -mfpu=vfpv3-d16
CXXFLAGS	:=-D_HW_VER=7 -Wl,-gc-sections -march=armv7-a -mcpu=cortex-a9 -mfloat-abi=softfp -mfpu=vfpv3-d16

else ifeq ($(arm),hisi3519a)
CROSS_COMPILE	:=arm-himix200-linux-
CCFLAGS		:=-D_HW_VER=8 -DGOAHEAD_64 -mfloat-abi=softfp -mfpu=neon-vfpv4 -mcpu=cortex-a53 
CXXFLAGS	:=-D_HW_VER=8 -DGOAHEAD_64 -mfloat-abi=softfp -mfpu=neon-vfpv4 -mcpu=cortex-a53 

else ifeq ($(arm),hisi3516dv300)
CROSS_COMPILE	:=arm-himix200-linux-
CCFLAGS		:=-D_HW_VER=9 -DGOAHEAD_64 -mfloat-abi=softfp -mfpu=neon-vfpv4 -mcpu=cortex-a7
CXXFLAGS	:=-D_HW_VER=9 -DGOAHEAD_64 -mfloat-abi=softfp -mfpu=neon-vfpv4 -mcpu=cortex-a7

else
$(error make command error! choice arm of [hisi3519 hisi3516a hisi3516d hisi3516c hisi3559 hisi3531 hisi3519a hisi3516dv300])
endif

export CROSS_COMPILE
export CCFLAGS
export CXXFLAGS
export SRC_TOPDIR
export SDK_TOPDIR
export INSTALL_DIR
