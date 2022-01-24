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
#include <sys/kernel.h>
#include <sys/vga.h>
#include <sys/tty.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/* kinit error values */
#define KINIT_ERROR_

static int kinit(uint32_t mbaddr, uint32_t magic_num);
static void show_welcome(void);

int
kmain(uint32_t mbaddr, uint32_t magic_num)
{
    int res;
    multiboot_info_t *mbinfo = remap_multiboot_info(mbaddr);

	tty_init();
    fb_clear();

    if (magic_num != MULTIBOOT_BOOTLOADER_MAGIC) {
        tty_setcolor(COLOR_RED);
        kprintf("Invalid magic number: 0x%x\n", (unsigned int)magic_num);
        return K_DEADDEAD;
    }

    res = kinit(mbaddr, magic_num);
    if (res != 0) {
        /* switch (res) {
        } */
    }

	show_welcome();
	kprintf("Hello World, Welcome to cardinix!\n");
	return K_DEADBEEF;
}

static int
kinit(uint32_t mbaddr, uint32_t magic_num)
{

    return 0;
}

static void
show_welcome(void)
{
    tty_setcolor(vga_entry_color(VGA_COLOR_RED, VGA_COLOR_BLACK);
	/* https://www.oocities.org/spunk1111/birds.htm */
	kprintf(",'~.-..__  _...._\n");
    kprintf(" `, '.-  ``      `'.\n");
	kprintf("   `,        _.--.,_`\\\n");
	kprintf("     \\     `'--.\\o)/`/'.\n");
	kprintf("     '._       `\".-'.__\\\n");
	kprintf("jgs    '.        ;-..-'\n");
	kprintf("           `\"\"--.,_/\n");
	tty_setcolor(vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK));
}

