# Kernel Makefile last updated: 08/04/21
CC=i686-elf-g++
CC_ASM=i686-elf-as

CPPFLAGS?=
LDFLAGS?=
LIBS?=

INCLUDE_DIR=Include
SRC_DIR=Src
LIBC=../Libc
LIBCPP=../Libcpp

CPPFLAGS:=$(CPPFLAGS) -ffreestanding -O2 -g -Wall -Wextra -fno-exceptions -fno-rtti -fno-builtin \
	-I$(INCLUDE_DIR) -I$(LIBC)/Include -I$(LIBCPP)/Include \
	-D__IS_CARDINAL_KERNEL
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -L$(LIBC) -lc -static -L$(LIBCPP) -lcpp -static -lgcc -nostdlib

# Make this configurable
ARCHDIR=Arch/i386

include $(ARCHDIR)/make.config

CPPFLAGS:=$(CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)
LDFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS)

KERNEL_OBJS=\
	$(KERNEL_ARCH_OBJS) \
	$(SRC_DIR)/Kernel.o \
	$(SRC_DIR)/Terminal.o \
	$(SRC_DIR)/Vga.o

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
.SUFFIXES: .o .cpp .S

all: cardinal.bin

# cardinal: boot.o crti.o crtn.o Kernel.o Terminal.o Vga.o
#	$(CC) -T $(LNK_SCRIPT) -o $(BIN) -ffreestanding -O2 -nostdlib \
#	-nodefaultlibs -nolibc \
#	/boot.o $(BOOT_DIR)/crti.o $(BOOT_DIR)/crtn.o \
#	Kernel.o Terminal.o Vga.o -lgcc $(LIBS)

cardinal.bin: $(OBJS) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CPPFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot cardinal.bin

$(ARCHDIR)/crtbegin.o $(ARCHDIR)/crtend.o:
OBJ=`$(CC) $(CPPFLAGS) $(LDFLAGS) -print-file-name=$(@F)` && cp "$$OBJ" $@

.cpp.o:
	$(CC) -MD -c $< -o $@ -std=c++20 $(CPPFLAGS)

.S.o:
	$(CC) -MD -c $< -o $@ $(CPPFLAGS)

debug:
	echo $(CRTBEGIN_OBJ) \
	echo $(CRTEND_OBJ)

#boot.o:
#	$(CC_ASM) $(BOOT_DIR)/boot.S -o $(BOOT_DIR)/boot.o

#crti.o:
#	$(CC_ASM) $(BOOT_DIR)/crti.S -o $(BOOT_DIR)/crti.o

#crtn.o:
#	$(CC_ASM) $(BOOT_DIR)/crtn.S -o $(BOOT_DIR)/crtn.o

#Kernel.o: $(SRC_DIR)/Kernel.cpp $(SRC_DIR)/Kernel.h \
#	$(SRC_DIR)/Terminal.h $(SRC_DIR)/Vga.h
#	$(CC) -c $(SRC_DIR)/Kernel.cpp $(FLAGS)

#Terminal.o: $(SRC_DIR)/Terminal.cpp $(SRC_DIR)/Terminal.h \
#	$(SRC_DIR)/Vga.h
#	$(CC) -c $(SRC_DIR)/Terminal.cpp $(FLAGS)

# Vga.o: $(SRC_DIR)/Vga.cpp $(SRC_DIR)/Vga.h
# 	$(CC) -c $(SRC_DIR)/Vga.cpp $(FLAGS)

clean:
	rm -f cardinal.bin
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d

-include $(OBJS:.o=.d)
#.PHONY: all clean
