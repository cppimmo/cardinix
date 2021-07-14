# Kernel Makefile last updated: 07/12/21
CC=i686-elf-g++
SRC_DIR=src
BOOT_DIR=../bootldr
LIBC=../libc
LIBCPP=../libcpp
LNK_SCRIPT=../linker.ld
FLAGS=-ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti \
	-I$(LIBC)/include -I$(LIBCPP)/include -L$(LIBC) -l$(LIBC)/libc
#SOURCES=kernel.cpp terminal.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
BIN=cardinal.bin

cardinal: kernel.o terminal.o vga.o
	$(CC) -T $(LNK_SCRIPT) -o $(BIN) -ffreestanding -O2 -nostdlib \
	$(BOOT_DIR)/boot.o kernel.o terminal.o vga.o -lgcc

kernel.o: $(SRC_DIR)/kernel.cxx $(SRC_DIR)/kernel.hxx \
	$(SRC_DIR)/terminal.hxx $(SRC_DIR)/vga.hxx
	$(CC) -c $(SRC_DIR)/kernel.cxx $(FLAGS)

terminal.o: $(SRC_DIR)/terminal.cxx $(SRC_DIR)/terminal.hxx \
	$(SRC_DIR)/vga.hxx
	$(CC) -c $(SRC_DIR)/terminal.cxx $(FLAGS)

vga.o: $(SRC_DIR)/vga.cxx $(SRC_DIR)/vga.hxx
	$(CC) -c $(SRC_DIR)/vga.cxx $(FLAGS)

clean:
	-rm -f kernel.o terminal.o vga.o $(BIN)

#.PHONY: all clean
