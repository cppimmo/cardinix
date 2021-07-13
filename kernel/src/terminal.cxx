#include "terminal.hxx"
#include <string.h>



terminal::TERM_STATE terminal::init()
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR::VGA_WHITE,
		VGA_COLOR::VGA_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; ++y)
	{
		for (size_t x = 0; x < VGA_WIDTH; ++x)
		{
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
	return terminal::TERM_STATE::INIT_SUCCESS;
}

void terminal::setcolor(const VGA_COLOR fgcolor,
	const VGA_COLOR bgcolor) noexcept
{
	terminal_color = vga_entry_color(fgcolor, bgcolor);
}

void terminal::putentryat(char c, const VGA_COLOR color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	auto do_print = [c, &color, &index]()
	{
		terminal_buffer[index] = vga_entry(c,
			static_cast<uint8_t>(color));
	};

	switch (c)
	{
	case '\n':
	{
		++terminal_row;
		terminal_column = 0;
		break;
	}	
	default:
		do_print();
	}

}

void terminal::putchar(char c)
{
	terminal::putentryat(c, static_cast<VGA_COLOR>(terminal_color), terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH)
	{
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
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

 
