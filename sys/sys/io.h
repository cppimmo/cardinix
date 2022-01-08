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
#ifndef _SYS_IO_H_
#define _SYS_IO_H_

/*
 * Reads a single bytes from the I/O port: port.
 * Defined in 
 */
unsigned char inb(unsigned short port);
/*
 * Sends data to the I/O port: port.
 * Defined in io.S
 */
void outb(unsigned short port, unsigned char data);

#endif /* !_SYS_IO_H_ */
