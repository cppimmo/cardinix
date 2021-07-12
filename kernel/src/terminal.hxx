#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>
#include "vga.hxx"

namespace terminal
{
	using CharIndex = size_t;

	namespace 
	{
		size_t terminal_row;
		size_t terminal_column;
		VGA_COLOR terminal_color = VGA_COLOR::VGA_WHITE;
		uint16_t *terminal_buffer;
	}

	enum struct TERM_STATE
	{
    	INIT_FAIL = 0,
    	INIT_SUCCESS = 1,
	};

	[[nodiscard]] TERM_STATE init();

	void write(const char* str, size_t size);
	void writestr(const char *data);
	void putentryat(char c, const VGA_COLOR color, size_t x, size_t y)
	void putchar(char c);

	[[nodiscard]] VGA_COLOR &term_get_fg_color() noexcept;
	void term_set_fg_color(const VGA_COLOR &) noexcept;
	void setcolor(const VGA_COLOR fgcolor, 
		const VGA_COLOR bgcolor = VGA_COLOR::VGA_BLACK) noexcept;

}

#endif // TERMINAL_H
