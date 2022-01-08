/*
 * The bootloader will look at this binary and start executing
 * at the symbol _start.
 */
ENTRY(_start)
/*
 * List sections of object files and where they will be
 * placed in the final kernel image.
 */
SECTIONS
{
	/* 
     * Begin placing sections at 1MiB, a typical location for kernels to be
     * loaded by the bootloader.
     */
	. = 1M; 

	/* align at 4KB */
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text) /* all text sections from all files */
	}

	/* Read-only data, align at 4KB */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata) /* all read-only data sections from all files */
	}

	/* Read-write data(initialized), align  at 4KB */
	.data BLOCK(4K) : ALIGN(4K)
    {
		*(.data) /* all data sections from all files */
	}

	/* Read-write data (uninitialized) and stack, align at 4KB */
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON) /* all COMMON sections from all files */
		*(.bss)   /* all bss sections from all files */
	}

	/*
     * Compiler may create more sections. Place in proper place here, should 
     * they be wanted in the final kernel.
     */
}
