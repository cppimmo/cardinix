# libcpp Makefile last updated: 07/27/21
CC=i686-elf-g++
CFLAGS=-O2 -g -Wall -Wextra -Iinclude -std=c++20
INCLUDE_DIR=include
SRC_DIR=src
BIN=libcpp.a
SOURCES= \
	$(SRC_DIR)/utility.cpp
OBJS= \
	utility.o
ARCHIVER=ar

all: $(BIN)

libcpp.a: $(OBJS)
	$(ARCHIVER) rcs $@ $(OBJS)

utility.o: $(SRC_DIR)/utility.cpp $(INCLUDE_DIR)/utility
	$(CC) -c $(SRC_DIR)/utility.cpp $(CFLAGS)

clean:
	rm -f *.o $(BIN)

