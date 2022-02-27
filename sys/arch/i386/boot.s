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

/* Reserve a stack for the initial thread. */
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

/* The kernel entry point. */
.section .text
.global _start
.type _start, @function
_start:
	/* 
     * Setup the stack by pointing the esp reg to the top for C. x86 stacks grow
     * downwards.
     */
	mov $stack_top, %esp

	/* Global constructors */
	call _init

    /* Push multiboot magic number at %eax to stack
    pushl $0
    popf    

    pushl %eax
       Push multiboot addr at %ebx to stack
    pushl %ebx

       Call kinit 
    call kinit */

    /* Push multiboot magic number at %eax to stack */
    pushl $0
    popf

    pushl %eax
    /* Push multiboot addr at %ebx to stack */
    pushl %ebx
	/* Call kmain, the kernel main routine */
	call kmain

	/* 
     * Enter the infinite system loop. Steps below:
	 * 1) Disable interrupts with the cli(clear interrupt enable in eflags)
     *    instruction. Interrupts are already disabled by GRUB, but they well be
     *    enabled eventually in the kernel init and main routines for use in the
     *    operating system.
	 * 2) 
	 * 3) 
	 */
	cli
1:	hlt
	jmp 1b

/*
 * 
 */
.size _start, . - _start

