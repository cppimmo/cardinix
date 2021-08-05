#include "Kernel/Vga.h"
#include <math.h>

void vga::Init()
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
}

