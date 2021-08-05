#include "Kernel/Terminal.h"
#include <string.h>
#include <math.h>

Terminal::Terminal(const char *name, size_t rowsize, size_t colsize)
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
	/*for (size_t i = 0; i < vga::VGA_WIDTH; ++i)
	{
		ClearLine(i);
	}*/
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

/*std::pair<vga::VGA_COLOR, vga::VGA_COLOR>*/ void Terminal::GetColor() const noexcept
{
	/*return std::pair<vga::VGA_COLOR, vga::VGA_COLOR>();*/
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

/*terminal::TERM_STATE terminal::init()
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

