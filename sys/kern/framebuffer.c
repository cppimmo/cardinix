#include <sys/framebuffer.h>

#define FB_MEMORY 0x000B8000

#define FB_COLUMNS 80
#define FB_ROWS 25

/* Define esacpe character codes */
#define FB_ESCAPE_

static uint8_t fbmem = (uint8_t *)FM_MEMORY;
static uint16_t cursor_pos;

static uint8_t read_at(uint32_t row, uint32_t col);
static void __write_at(uint8_t *pos, uint8_t byte);
static void write_at(uint32_t row, uint32_t col, uint8_t byte);
static void set_cursor(uint16_t pos);
static void cursor_incr(void);
static void cursor_decr(void);
static void cursor_linedown(void);
static void cursor_start(void);
static void scrollfb(void);

void
fb_putbyte(uint8_t byte)
{

}

void
fb_putstr(const char *str)
{
    /* increment position until null character */
    while (*str != '\0') {
        fb_putbyte(*str++);
    }
}

void
fb_putuint(uint32_t ui)
{

}

void
fb_putuint_hex(uint32_t ui_hex)
{
    static char *hexstr = "0123456789ABCDEF";
    unsigned char out_byte = 0;
    int i;
}

void
fb_clear(void)
{

}

void
fb_movecursor(uint16_t row, uint16_t col)
{

}

int fb_init(void)
{

    return 0;
}

