#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdint.h>
#include <stddef.h>
#include "vga.hxx"

namespace terminal
{
	using CharIndex = size_t;

	namespace 
	{
		size_t terminal_row = 0;
		size_t terminal_column = 0;
		uint8_t terminal_color = 0;
		uint16_t *terminal_buffer = nullptr;
		bool isblinking;
		bool isunderline;
		constexpr size_t tabwidth = 4;
	}

	enum struct TERM_STATE
	{
    	INIT_FAIL = 0,
    	INIT_SUCCESS = 1,
	};

	enum struct ESC_CHAR : unsigned char
	{
		ESC_NEWLINE = '\n',
		ESC_HTAB = '\t',
		ESC_BACK = '\b',
		ESC_RETURN = '\r', // carriage
		ESC_BELL = '\a',
		ESC_VTAB = '\v',
	};

	[[nodiscard]] TERM_STATE init();

	void write(const char* str, size_t size);
	void writestr(const char *data);
	void putentryat(char c, const vga::VGA_COLOR color, size_t x, size_t y);
	void putchar(char c);
	void clearline(size_t lineno);

	[[nodiscard]] vga::VGA_COLOR term_get_fg_color() noexcept;
	void term_set_fg_color(const vga::VGA_COLOR &color) noexcept;
	[[nodiscard]] vga::VGA_COLOR term_get_fg_color() noexcept;
	void term_set_bg_color(const vga::VGA_COLOR &color) noexcept;
	void setcolor(const vga::VGA_COLOR fgcolor, 
		const vga::VGA_COLOR bgcolor = vga::VGA_COLOR::VGA_BLACK) noexcept;
	void setblinking(const bool value) noexcept;
	void setunderline(const bool value) noexcept;
}

#endif // TERMINAL_H
