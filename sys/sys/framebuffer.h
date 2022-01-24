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
 * sys/framebuffer.h
 */
#ifndef _SYS_FRAMEBUFFER_H_
#define _SYS_FRAMEBUFFER_H_

#include <sys/io.h>
#include <stdint.h>

/* Framebuffer I/O ports */
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT    0x3D5

/* Framebuffer I/O port commands */
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND  15

/*
 * Place a single byte or string into the framebuffer respectively.
 */
void fb_putbyte(uint8_t byte);
void fb_putstr(const char *str);

/*
 * Place a decimal uint and hexidecimal uint into the framebuffer respectively.
 */
void fb_putuint(uint32_t ui);
void fb_putuint_hex(uint_32t ui_hex);

/*
 * Move the framebuffer cursor to row and col.
 */
void fb_movecursor(uint16_t row, uint16_t col);

/*
 * Clear framebuffer contents to current bg color.
 */
void fb_clear(void);

/*
 * Initialize framebuffer.
 */
int fb_init(void);

#endif /* !_SYS_FRAMEBUFFER_H_ */
