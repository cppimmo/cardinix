/* cardinix, file: main.h */
/*
 * Copyright (C) 2022 Brian hoffpauir
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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

