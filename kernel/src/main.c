#include <stddef.h>
#include <stdint.h>

#include "kernel/vga.h"
#include "kernel/terminal.h"

#include <stdio.h>

/* #if defined(__i386__)
#error "w"
#endif */

static void KernelStartMessage(void);

static void KernelStartMessage(void) {
	/* using vga::VGA_COLOR;
	term.SetColor(VGA_COLOR::VGA_RED, VGA_COLOR::VGA_BLACK);
	// https://www.oocities.org/spunk1111/birds.htm
	term.Write(",'~.-..__  _...._\n");
    term.Write(" `, '.-  ``      `'.\n");
	term.Write("   `,        _.--.,_`\\\n");
	term.Write("     \\     `'--.\\o)/`/'.\n");
	term.Write("     '._       `\".-'.__\\\n");
	term.Write("jgs    '.        ;-..-'\n");
	term.Write("           `\"\"--.,_/\n");
	term.SetColor(VGA_COLOR::VGA_WHITE, VGA_COLOR::VGA_BLACK); */
}

void KernelMain(void) {
	// vga::Init();
	
	// TerminalWrite pWrite = &Terminal::Write;
	// set_kernel_terminal_func(Write);
	// KernelStartMessage();
	// term.Write("Hello World, Welcome to Cardinal OS!\n");
	
	return;
}

