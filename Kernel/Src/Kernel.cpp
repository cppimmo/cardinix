#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "CompJunk/GCCJunk.h"
#include "Kernel/Vga.h"
#include "Kernel/Kernel.h"
#include "Kernel/Terminal.h"

#include <stdio.h>

/* #if defined(__i386__)
#error "w"
#endif */

Terminal term("tty1", 80, 25);

void Write(const char *str)
{
	term.Write(str);
}

static void KernelStartMessage()
{
	using vga::VGA_COLOR;
	term.SetColor(VGA_COLOR::VGA_RED, VGA_COLOR::VGA_BLACK);
	// https://www.oocities.org/spunk1111/birds.htm
	term.Write(",'~.-..__  _...._\n");
    term.Write(" `, '.-  ``      `'.\n");
	term.Write("   `,        _.--.,_`\\\n");
	term.Write("     \\     `'--.\\o)/`/'.\n");
	term.Write("     '._       `\".-'.__\\\n");
	term.Write("jgs    '.        ;-..-'\n");
	term.Write("           `\"\"--.,_/\n");
	term.SetColor(VGA_COLOR::VGA_WHITE, VGA_COLOR::VGA_BLACK);
}

extern "C" void KernelMain(void)
{
	vga::Init();
	
	// TerminalWrite pWrite = &Terminal::Write;
	set_kernel_terminal_func(Write);
	KernelStartMessage();
	term.Write("Hello World, Welcome to Cardinal OS!\n");
	
	return;
}

