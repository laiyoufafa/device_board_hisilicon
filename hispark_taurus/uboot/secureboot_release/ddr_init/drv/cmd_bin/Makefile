# Copyright (C) 2021 HiSilicon (Shanghai) Technologies CO., LIMITED.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

sinclude $(TOPDIR)/arch/arm/cpu/$(CPU)/config.mk       # include architecture dependend rules
################################################################################

PWD      := $(shell pwd)
OPPDIR   := $(subst $(TOPDIR),,$(PWD))

CC       := $(CROSS_COMPILE)gcc
AR       := $(CROSS_COMPILE)ar
LD       := $(CROSS_COMPILE)ld
OBJCOPY  := $(CROSS_COMPILE)objcopy
OBJDUMP  := $(CROSS_COMPILE)objdump


################################################################################
DDR_CMD     := ddr_cmd

CMD_TEXT_BASE := $(shell grep '^\#define.*DDR_TRAINING_RUN_STACK' $(TOPDIR)/drivers/ddr/hisilicon/$(SOC)/ddr_training_custom.h|awk '{print $$3}')
STACK_POINT   := $(CMD_TEXT_BASE)

COBJS       := ddr_training_uart.o ddr_training_custom.o ddr_training_cmd.o ddr_training_impl.o ddr_training_ctl.o ddr_training_console.o
DEPS        := $(COBJS:.o=.d) $(START:.o=.d)
SSRC        := ddr_training_impl.c ddr_training_ctl.c ddr_training_console.c

CFLAGS   := -Os -pipe  \
	-DCMD_TEXT_BASE=$(CMD_TEXT_BASE) -DSTACK_POINT=$(STACK_POINT) \
	-fno-builtin -ffreestanding -I./ -I$(TOPDIR)/include -I../ \
	-DDDR_TRAINING_CMD -I$(TOPDIR)/drivers/ddr/hisilicon/$(SOC)/

CFLAGS += $(PLATFORM_RELFLAGS) $(PLATFORM_CPPFLAGS)

ifeq ("$(CONFIG_ARM64)","y")
START       := cmd_entry_64.o
LDS_SCRIPT := ddr_cmd_64.lds
CFLAGS += -DCONFIG_ARM64
else
START       := cmd_entry_32.o
LDS_SCRIPT := ddr_cmd_32.lds
endif

################################################################################

LINK_FILES = $(SSRC) ddr_training_custom.c

.PHONY: $(DDR_CMD).bin
all: $(DDR_CMD).bin
	#remove soft link files
	@rm -f $(LINK_FILES) *.o *.d *.elf *.map *.srec

$(DDR_CMD).bin: $(DDR_CMD).elf
	$(OBJCOPY) -O srec $(PWD)/$(DDR_CMD).elf $(DDR_CMD).srec
	$(OBJCOPY) --gap-fill=0xff -O binary $(PWD)/$(DDR_CMD).elf $@

$(DDR_CMD).elf: $(START) $(COBJS) $(LDS_SCRIPT)
	#@echo CMD_TEXT_BASE=$(CMD_TEXT_BASE)
	$(LD) -Bstatic -T $(LDS_SCRIPT) -Ttext $(CMD_TEXT_BASE) $(START) \
		$(COBJS) $(AOBJS) -Map $(DDR_CMD).map -o $@

$(SSRC):
	rm -rf $@
	rm -rf ddr_training_custom.c
	ln -sf ../$@ $@
	ln -sf $(TOPDIR)/drivers/ddr/hisilicon/$(SOC)/ddr_training_custom.c ddr_training_custom.c

.PHONY: clean
clean:
	@rm -vf *.o *.d *.elf *.map *.srec $(LINK_FILES) $(DDR_CMD).bin

%.o : %.S
	$(CC) -D__ASSEMBLY__ $(CFLAGS) -o $@ -c $*.S

%.o : %.c
	$(CC) $(CFLAGS) -Wall -Wstrict-prototypes -fno-stack-protector \
		-o $@ -c $*.c

ifneq ("$(MAKECMDGOALS)","clean")
sinclude $(DEPS)
endif

%.d : %.c
	set -e; $(CC) $(CFLAGS) -MM $< | sed 's,$*.o:,$*.o $*.d:,g' > $@

%.d : %.S
	set -e; $(CC) $(CFLAGS) -MM $< | sed 's,$*.o:,$*.o $*.d:,g' > $@

################################################################################
