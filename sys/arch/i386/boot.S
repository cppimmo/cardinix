/* multiboot header constants */
.set ALIGN, 1<<0 # align load modules on page boundaries
.set MEMINFO, 1<<1 # provide memory map
.set FLAGS, ALIGN | MEMINFO # this is the multiboot 'flag' field
.set MAGIC, 0x1BADB002 # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot
/* declare multiboot header that marks program as kernel */
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

/* reserve a stack for the initial thread. */
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

/* the kernel entry point. */
.section .text
.global _start
.type _start, @function
_start:
	/*  */
	mov $stack_top, %esp

	/* global constructors */
	call _init
	/* move into the kernel main routine */
	call KernelMain

	/* infinite system loop
	1)
	2)
	3)
	 */
	cli
1:	hlt
	jmp 1b

/* */
.size _start, . - _start

