# Kernel Makefile last updated: 08/04/21
CC=i686-elf-gcc
CC_ASM=i686-elf-as

CFLAGS?=
CPPFLAGS?=
LDFLAGS?=
LIBS?=

INCLUDE_DIR=include
SRC_DIR=src
LIBC=../libc

CFLAGS:=$(CFLAGS) -ffreestanding -O2 -g -Wall -Wextra -fno-exceptions -fno-rtti -fno-builtin
CPPFLAGS:=$(CPPFLAGS) -D__IS_CARDINAL_KERNEL -I$(INCLUDE_DIR) \
	-I$(LIBC)/include
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -L$(LIBC) -lc -static -lgcc -nostdlib

# Make this configurable
ARCHDIR=arch/i386

include $(ARCHDIR)/make.config

CPPFLAGS:=$(CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)
LDFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS)

KERNEL_OBJS=\
	$(KERNEL_ARCH_OBJS) \
	$(SRC_DIR)/kernel.o \
	$(SRC_DIR)/terminal.o \
	$(SRC_DIR)/vga.o

CRTBEGIN_OBJ:=$(shell $(CC) $(CPPFLAGS) $(LDFLAGS) -print-file-name=crtbegin.o)

CRTEND_OBJ:=$(shell $(CC) $(CPPFLAGS) $(LDFLAGS) -print-file-name=crtend.o)

OBJS=\
	$(ARCHDIR)/crti.o \
	$(ARCHDIR)/crtbegin.o \
	$(KERNEL_OBJS) \
	$(ARCHDIR)/crtend.o \
	$(ARCHDIR)/crtn.o

LINK_LIST=\
	$(LDFLAGS) \
	$(ARCHDIR)/crti.o \
	$(ARCHDIR/crtbegin.o \
	$(KERNEL_OBJS) \
	$(LIBS) \
	$(ARCHDIR)/crtend.o \
	$(ARCHDIR)/crtn.o

.PHONY: all clean
.SUFFIXES: .o .c .S

all: cardinal.bin

cardinal.bin: $(OBJS) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CPPFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot cardinal.bin

$(ARCHDIR)/crtbegin.o $(ARCHDIR)/crtend.o:
OBJ=`$(CC) $(CPPFLAGS) $(LDFLAGS) -print-file-name=$(@F)` && cp "$$OBJ" $@

.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS) $(CPPFLAGS)

.S.o:
	$(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

debug:
	echo $(CRTBEGIN_OBJ) \
	echo $(CRTEND_OBJ)

clean:
	rm -f cardinal.bin
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d

-include $(OBJS:.o=.d)
#.PHONY: all clean
