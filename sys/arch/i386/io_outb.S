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
 *
 * arch/sys/i386/io_outb.S - write a single byte to a I/O port.
 */

/* This label should be global. */
global outb

/*
 * Write a singular byte to port.
 * stack + 8 - the data byte.
 * stack + 4 - the I/O port.
 * stack - the return address.
 */
outb:
    mov %al, 8(%esp) /* Move the data into %al */
    mov %dx, 4(%esp) /* Move the address of the port into %dx */
    out %dx, %al /* Send the data to the port */
    ret

