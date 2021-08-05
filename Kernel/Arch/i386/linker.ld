/* bootloader will look at this image and start executing
   at the symbol _start */
ENTRY(_start)
/* List sections of object files and where they will be
   placed in the final kernel image. */
SECTIONS
{
	/* Begin placing sections at 1MiB,
	   a typical location for kernels to be loaded
	   by the bootloader. */
	. = 1M; 

	/*  */
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
		*(.text)
	}

	/* read-only data */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	/* read-write data(initialized) */
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	/* read-write data (uninitialized) and stack */
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}

	/* compiler may create more sections.
       Place in proper place here, should they be
       wanted in the final kernel. */
}
