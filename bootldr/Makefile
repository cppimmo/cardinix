# Bootloader makefile last updated 7/12/21
CC=i686-elf-as

all: crti.o boot.o crtn.o 

crti.o:
	$(CC) crti.S -o crti.o

boot.o:
	$(CC) boot.S -o boot.o

crtn.o:
	$(CC) crtn.S -o crtn.o

clean:
	rm -f boot.o crti.o crtn.o
