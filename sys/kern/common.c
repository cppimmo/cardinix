#include <sys/common.h>
#include <stdio.h>

/*
 * Caller of libk printf routine. This should instead just be defined as a
 * macro.
 */
int
kprintf(const char *format, ...)
{
    return printf(format, ...);
}

/*
 * Use if a non-fatal error occured.
 */
void
kwarning(const char *msg, const char *file, uint32_t line)
{
    (void)kprintf("WARNING:%s:%d:%s\n", file, line, msg);
}

