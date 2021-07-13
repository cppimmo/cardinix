#!/bin/bash

echo "Building CardinalOS...\n"

if grub-file --is-x86-multiboot kernel/cardinal.bin; then
	echo "multiboot enabled\n"
else
	echo "multiboot disabled\n" >&2
fi

if [[ ! -e "release/boot/grub" ]]; then
	mkdir -p release/boot/grub
fi
cp kernel/cardinal.bin release/boot/cardinal.bin
cp grub.cfg release/boot/grub.cfg
grub-mkrescue -o cardinal.iso release

