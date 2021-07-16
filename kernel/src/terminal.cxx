#include "terminal.hxx"
#include <string.h>
#include <math.h>

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

