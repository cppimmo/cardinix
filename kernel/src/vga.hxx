#ifndef VGA_HXX
#define VGA_HXX

#include <stdint.h>
#include <stddef.h>

namespace vga { }

enum struct VGA_COLOR : uint8_t
{
	VGA_BLACK = 0,
	VGA_BLUE = 1,
	VGA_GREEN = 2,
	VGA_CYAN = 3, 
	VGA_RED = 4,
	VGA_MAGENTA = 5, 
	VGA_BROWN = 6,
	VGA_LIGHT_GREY = 7,
	VGA_DARK_GREY = 8,
	VGA_LIGHT_BLUE = 9,
	VGA_LIGHT_GREEN = 10,
	VGA_LIGHT_CYAN = 11,
	VGA_LIGHT_RED = 12,
	VGA_LIGHT_MAGENTA = 13,
	VGA_LIGHT_BROWN = 14,
	VGA_WHITE = 15,
};

constexpr size_t VGA_WIDTH = 80;
constexpr size_t VGA_HEIGHT = 25;

inline uint8_t vga_entry_color(VGA_COLOR fg, VGA_COLOR bg)
{
	return static_cast<uint8_t>(fg) | static_cast<uint8_t>(bg) << 4;
}

inline uint16_t vga_entry(unsigned char uc, uint8_t color)
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

#endif // VGA_HXX
