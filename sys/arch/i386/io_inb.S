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
 * sys/arch/i386/io_inb.S - inb function implementation.
 */

global inb

/*
 * inb returns a byte from the I/O port: port.
 * The top of the stack + 4 is equal to the address of the port.
 * %esp is the return address
 */
inb:
    mov %dx, 4(%esp) /* place the address of the port into %dx */
    in %al, %dx /* read a single byte from the port into %al */
    ret /* return the byte that was read */

