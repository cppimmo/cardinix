#ifndef __VT_TERMINAL_H__
#define __VT_TERMINAL_H__

#include <stdint.h>
#include <stddef.h>

#include "vga.h"

#define VT_ESCAPE_NEWLINE '\n'
#define VT_ESCAPE_HTAB '\t'
#define VT_ESCAPE_BACK '\b'
#define VT_ESCAPE_CARRIAGE_RETURN '\r'
#define VT_ESCAPE_BELL '\a'
#define VT_ESCAPE_VTAB '\v'

void VT_Initialize(void);
void VT_PutChar(char character);
void VT_Write(const char *str, size_t len);
void VT_WriteString(const char *str);
void VT_SetTabWidth(int width);

// should this be a base class?
/* class Terminal
{
public:
	using CharIndex = size_t;
	enum struct State
	{
		SUCCESS = 0,
		FAIL = 1,
	};
	enum struct SpecialChar : unsigned char
	{
	    NEWLINE = '\n', // newline
		HTAB = '\t', // horizontal tab
		BACK = '\b', // backspace
		CRETURN = '\r', // carriage
		BELL = '\a', // bell
		VTAB = '\v', // vertical tab
	};
public:
	Terminal(const char *name, size_t rowsize, size_t colsize);
	virtual ~Terminal() = default;

	void Write(const char *str);
	void WriteLine(const char *str);
	void ClearLine(size_t lineNo);
	bool Show(); // return is shown?
	bool Hide(); // return was hidden?
	char *GetName() const noexcept;
	size_t GetRow() const noexcept;
	size_t GetColumn() const noexcept;
	void SetBlinking(const bool value) noexcept;
	void SetUnderline(const bool value) noexcept;
	std::pair<vga::VGA_COLOR, vga::VGA_COLOR>
	void GetColor() const noexcept;
	void SetColor(const vga::VGA_COLOR fg,
				  const vga::VGA_COLOR bg = vga::VGA_COLOR::VGA_BLACK) noexcept;
private:
	void PutChar(char c);
	void PutString(const char *str, size_t length);
	void PutEntryAt(char c, size_t x, size_t y);
private:
	size_t row;
	size_t column;
	uint8_t color;
	uint16_t *buffer;
	bool isBlinking;
	bool isUnderline;
	size_t tabWidth;
	char name[5];
	bool isActive;
};

using TerminalWrite = void (Terminal::*)(const char*);
*/
/*namespace terminal
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
}*/

#endif // TERMINAL_H
