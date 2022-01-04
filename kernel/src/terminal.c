/* cardinix, file: terminal.c */
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
#include "Kernel/Terminal.h"
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include <kernel/vt_terminal.h>
#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t *const VGA_MEMORY = (uint16_t*)0xB8000;

static size_t vt_row;
static size_t vt_column;
static uint8_t vt_color;
static uint16_t *vt_buffer;

void VT_Initialize(void) {
    vt_row = 0;
    vt_column = 0;
    vt_color = VGA_EntryColor(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
    vt_buffer = VGA_MEMORY;
    for (size_t y = 0; y < VGA_HEIGHT; ++y) {
        for (size_t x = 0; x < VGA_WIDTH; ++x) {
            const size_t index = y * VGA_WIDTH + x;
            vt_buffer[index] = VGA_Entry(' ', vt_color);
        }
    }
}

void VT_SetColor(uint8_t color) {
    vt_color = color;
}

void VT_PutEntryAt(unsigned char character, uint8_t color, size_t x, size_t y) {
    const size_t index = y * VGA_WIDTH + x;
    vt_buffer[index] = VGA_Entry(character, color);
}

void VT_Scroll(int line) {
    int loop;
    char ch;
    for (loop = line * (VGA_WIDTH * 2) + 0xB8000; loop < VGA_WIDTH * 2; ++loop) {
        ch = *loop;
        *(loop - (VGA_WIDTH * 2)) = ch;
    }
}

void VT_ClearLine(void) {
    int x, *ptr;
    for (x = 0; x < VGA_WIDTH * 2; x++) {
        ptr = 0xB8000 + VGA_WIDTH * 2) * (VGA_HEIGHT - 1) + x;
        *ptr = 0;
    }
}

void VT_PutChar(char ch) {
    int line;
    unsigned char uch = ch;
    VT_PutEntryAt(uch, vt_color, vt_column, vt_row);
    if (++vt_column == VGA_WIDTH) {
        vt_column = 0;
        if (++vt_row == VGA_HEIGHT) {
            for (line = 1; line <= VGA_HEIGHT - 1; ++line) {
                VT_Scroll(line);
            }
            VT_ClearLine();
            vt_row = VGA_HEIGHT - 1;
        }
    }
}

void VT_Write(const char *str, size_t len) {
    size_t i;
    for (i = 0; i < size; ++i)
        VT_PutChar(str[i]);
}

void VT_WriteString(const char *str) {
    VT_Write(str, strlen(str));
}

/* Terminal::Terminal(const char *name, size_t rowsize, size_t colsize)
{
	for (size_t i = 0; i < strlen(this->name); ++i)
	{
		this->name[i] = name[i];
	}
	this->name[4] = '\0';
	
	this->row = 0;
	this->column = 0;
	this->color = vga::EntryColor(vga::VGA_COLOR::VGA_WHITE,
								   vga::VGA_COLOR::VGA_BLACK);
	this->buffer = (uint16_t*)0xB8000;
	this->isBlinking = false;
	this->isUnderline = false;
	for (size_t y = 0; y < vga::VGA_HEIGHT; ++y)
	{
		for (size_t x = 0; x < vga::VGA_WIDTH; ++x)
		{
			const size_t index = y * vga::VGA_WIDTH + x;
			this->buffer[index] = vga::Entry(' ', color, isBlinking,
											 isUnderline);
		}
	}
	
}

void Terminal::Write(const char *str)
{
	if (!isActive)
		return;
	this->PutString(str, strlen(str));
}

void Terminal::WriteLine(const char *str)
{
	this->Write(str);
	this->Write("\n");
}

void Terminal::ClearLine(size_t lineNo)
{
	uint16_t *line = nullptr;
	for (size_t col = 0; col < vga::VGA_WIDTH * 2; ++col)
	{ // set each character in column to ' '

	}
}

bool Terminal::Show()
{
	bool wasActive = isActive;
	isActive = true;
	return wasActive;
}

bool Terminal::Hide()
{
	bool wasActive = isActive;
	isActive = false;
	for (size_t i = 0; i < vga::VGA_WIDTH; ++i)
	{
		ClearLine(i);
	}
	return !isActive;
}

char *Terminal::GetName() const noexcept
{
	return const_cast<char*>(this->name);
}

size_t Terminal::GetRow() const noexcept
{
	return this->row;
}
size_t Terminal::GetColumn() const noexcept
{
	return this->column;
}

void Terminal::SetBlinking(const bool value) noexcept
{
	this->isBlinking = value;
}

void Terminal::SetUnderline(const bool value) noexcept
{
	this->isUnderline = value;
}

std::pair<vga::VGA_COLOR, vga::VGA_COLOR> void Terminal::GetColor() const noexcept
{
	return std::pair<vga::VGA_COLOR, vga::VGA_COLOR>();
}

void Terminal::SetColor(const vga::VGA_COLOR fg,
						const vga::VGA_COLOR bg) noexcept
{
	
}

void Terminal::PutChar(char c)
{
	using vga::VGA_COLOR;
	this->PutEntryAt(c, column, row);
	if (++column == vga::VGA_WIDTH)
	{
		column = 0;
		if (++row == vga::VGA_HEIGHT)
		{
			row = 0;
		}
	}
}

void Terminal::PutString(const char *str, size_t length)
{
	for (size_t i = 0; i < length; ++i)
		this->PutChar(str[i]);
}

void Terminal::PutEntryAt(char c, size_t x, size_t y)
{
	const size_t index = y * vga::VGA_WIDTH + x;
	auto do_print = [c, &index, this]()
	{
		buffer[index] = vga::Entry(c,
	        color, isBlinking, isUnderline);
	};

	const auto schar = static_cast<SpecialChar>(c);
	switch (schar)
	{
	case SpecialChar::NEWLINE:
	{
		++row;
		column = 0;
		break;
	}
	case SpecialChar::HTAB:
	{
		column += tabWidth;
		break;
	}
	case SpecialChar::BACK:
	{
		if (column >= 1)
			--column;
		break;
	}
	case SpecialChar::CRETURN:
	case SpecialChar::BELL:
	case SpecialChar::VTAB:
		break; // do nothing
	default:
		do_print();
	}
	
}

terminal::TERM_STATE terminal::init()
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga::entry_color(vga::VGA_COLOR::VGA_WHITE,
		vga::VGA_COLOR::VGA_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	isblinking = false;
	isunderline = false;
	for (size_t y = 0; y < vga::VGA_HEIGHT; ++y)
	{
		for (size_t x = 0; x < vga::VGA_WIDTH; ++x)
		{
			const size_t index = y * vga::VGA_WIDTH + x;
			terminal_buffer[index] = vga::entry(' ', terminal_color,
				isblinking, isunderline);
		}
	}
	return terminal::TERM_STATE::INIT_SUCCESS;
}

void terminal::setcolor(const vga::VGA_COLOR fgcolor,
	const vga::VGA_COLOR bgcolor) noexcept
{
	terminal_color = vga::entry_color(fgcolor, bgcolor);
}

void terminal::putentryat(char c, const vga::VGA_COLOR color, size_t x, size_t y)
{
	const size_t index = y * vga::VGA_WIDTH + x;
	auto do_print = [c, &color, &index]()
	{
		terminal_buffer[index] = vga::entry(c,
			static_cast<uint8_t>(color), isblinking, isunderline);
	};

	if (c == '\n')
	{
		++terminal_row;
		terminal_column = 0;
	}
	else
	{
		do_print();
	}
	
	const auto schar = static_cast<ESC_CHAR>(c);
	switch (schar)
	{
	case ESC_CHAR::ESC_NEWLINE:
	{
		++terminal_row;
		terminal_column = 0;
		break;
	}	
	case ESC_CHAR::ESC_HTAB:
	{
		terminal_column += tabwidth;
		break;
	}
	case ESC_CHAR::ESC_BACK:
	{
		if (terminal_column >= 1)
			--terminal_column;
		break;
	}
	default:
		do_print();
	}

}

void terminal::putchar(char c)
{
	using vga::VGA_COLOR;
	terminal::putentryat(c, static_cast<VGA_COLOR>(terminal_color),
		terminal_column, terminal_row);
	if (++terminal_column == vga::VGA_WIDTH)
	{
		terminal_column = 0;
		if (++terminal_row == vga::VGA_HEIGHT)
		{
			terminal_row = 0;
		}
	}
}

void terminal::write(const char *data, size_t size)
{
	for (size_t i = 0; i < size; ++i) 
	{
		terminal::putchar(data[i]);
	}
}

void terminal::writestr(const char *data)
{
	terminal::write(data, strlen(data));
}

void terminal::clearline(size_t lineno)
{
	uint16_t *line = nullptr;
	for (size_t col = 0; col < vga::VGA_WIDTH * 2; ++col)
	{ // set each character in column to null
		
	}
}

void terminal::setblinking(const bool value) noexcept
{
	isblinking = value;
}

void terminal::setunderline(const bool value) noexcept
{
	isunderline = value;
}
*/

