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
#include <sys/vga.h>
#include <math.h>



/* void vga::Init()
{
	vga::VGA_WIDTH = 80;
	vga::VGA_HEIGHT = 25;
}

uint8_t vga::EntryColor(VGA_COLOR fg, VGA_COLOR bg)
{
	return static_cast<uint8_t>(fg) | static_cast<uint8_t>(bg) << 4;
}

uint16_t vga::Entry(unsigned char uc, uint8_t color,
	bool blinking, bool underline)
{
	uint16_t ret = static_cast<uint16_t>(uc) |
		static_cast<uint16_t>(color) << 8;
	auto setbit = [&ret](uint16_t bit)
	{
		return ret | static_cast<uint16_t>(pow(2, bit));
	};

	if (blinking) {
		setbit(15);
	}
	if (underline) {
		setbit(0);
	}
	return ret;
} */

