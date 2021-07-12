#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "purevirt.hxx"
#include "kernel.hxx"
#include "terminal.hxx"

#if defined(__linux__)
#error "a"
#endif

#if defined(__i386__)
#error "w"
#endif

void kernel::main(void)
{
	// initilize terminal
	if ((const auto status = terminal::init()) == terminal::TERM_STATE::INIT_FAIL)
		return;
	// print to terminal
	terminal_writestring("Hello World\nWelcome to Cardinal OS");
	
	return;
}

