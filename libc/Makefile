CC=i686-elf-gcc
CFLAGS=-O2 -g -Wall -Wextra -Iinclude
INCLUDE_DIR=include
SRC_DIR=src
BIN=libc.a
SOURCES=\
	$(SRC_DIR)/math.c
OBJS=\
	$(SRC_DIR)/math.o
ARCHIVER=ar

all: $(BIN)

libc.a: $(OBJS)
	$(ARCHIVER) rcs $@ $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

%.o: %.S
	$(CC) -c $< -o $@ $(CFLAGS)

#.PHONY:
#	all clean

clean:
	rm -f *.o $(BIN)

