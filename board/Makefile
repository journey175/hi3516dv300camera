
#****************************************************************************
#
# Makefile
# 
# This is a GNU make (gmake) makefile
# Author:Dive
#****************************************************************************
.PHONY:all clean distclean main const

SUBDIRS :=  src/modules/ai

SUBDIRS :=$(wildcard $(SUBDIRS))

include env.mk
all:
	@echo complie nsd module...
	@for dir in $(SUBDIRS); do $(MAKE) -C $$dir $@ ||exit 1; done; 

clean:
	@echo rm in $(SUBDIRS) of obj
	@for dir in $(SUBDIRS); do $(RM) -rf $$dir/obj/${arm} $$dir/*.a $$dir/*.so; done;
