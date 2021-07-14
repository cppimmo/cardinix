#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "compjunk/purevirt.hxx"
#include "vga.hxx"
#include "kernel.hxx"
#include "terminal.hxx"

/* #if defined(__linux__)
#error "a"
#endif

#if defined(__i386__)
#error "w"
#endif */

void kernel_start_message()
{
	using terminal::writestr, terminal::setcolor, vga::VGA_COLOR;
	setcolor(VGA_COLOR::VGA_RED, VGA_COLOR::VGA_BLACK);
	// https://www.oocities.org/spunk1111/birds.htm
	writestr(",'~.-..__  _...._\n");
    writestr(" `, '.-  ``      `'.\n");
	writestr("   `,        _.--.,_`\\\n");
	writestr("     \\     `'--.\\o)/`/'.\n");
	writestr("     '._       `\".-'.__\\\n");
	writestr("jgs    '.        ;-..-'\n");
	writestr("           `""--.,_/\n");
	setcolor(VGA_COLOR::VGA_WHITE, VGA_COLOR::VGA_BLACK);
}

extern "C" void kernel_main(void)
{
	vga::init();
	// initilize terminal
	if (const auto status = terminal::init() == terminal::TERM_STATE::INIT_FAIL)
		return;
	// print to terminal
	kernel_start_message();
	terminal::writestr("Hello World, Welcome to Cardinal OS! \n");
	
	return;
}

