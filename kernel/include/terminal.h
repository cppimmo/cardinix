#ifndef TERMINAL_H
#define TERMINAL_H

enum TERMINAL_ERROR 
{
    TERMINAL_INIT_FAIL = 0,
    TERMINAL_INIT_SUCCESS = 1,
};

int terminal_init(void);
void terminal_write(const char* str);

#endif // TERMINAL_H