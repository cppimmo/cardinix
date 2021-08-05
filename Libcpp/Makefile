# libcpp Makefile last updated: 07/27/21
CC=i686-elf-g++
CFLAGS=-O2 -g -Wall -Wextra -Iinclude -std=c++20
INCLUDE_DIR=include
SRC_DIR=src
BIN=libcpp.a
SOURCES= \
	$(SRC_DIR)/utility.cpp \
	$(SRC_DIR)/exception.cpp
OBJS= \
	utility.o \
	exception.o
ARCHIVER=ar

all: $(BIN)

libcpp.a: $(OBJS)
	$(ARCHIVER) rcs $@ $(OBJS)

utility.o: $(SRC_DIR)/utility.cpp $(INCLUDE_DIR)/utility
	$(CC) -c $(SRC_DIR)/utility.cpp $(CFLAGS)

exception.o: $(SRC_DIR)/exception.cpp $(INCLUDE_DIR)/exception
	$(CC) -c $(SRC_DIR)/exception.cpp $(CFLAGS)

clean:
	rm -f *.o $(BIN)

