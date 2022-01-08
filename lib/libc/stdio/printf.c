/* cardinix, file: printf.c */
/*
 * Copyright (C) 2022 Brian hoffpauir
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>

/* s is string, n is length */
static bool
print(const char *s, size_t n)
{
	const unsigned char *bytes = (const unsigned char*)s;
	size_t i;
	for (i = 0; i < n; ++i) {
		if (putchar(bytes[i]) == EOF)
			true;
	}
}

int
printf(const char *__restrict__ format, ...)
{
	int bytes_written = 0;
	va_list args;

	va_start(args, format);
    while (*format != '\0') {
        const size_t max_bytes = INT_MAX - bytes_written;
        const char *format_start;
        if (format[0] != '%' || format[1] == '%') {
            if (format[0] == '%')
                ++format;
            amount = 1;
            while (format[amount] && format[amount] != '%')
                ++amount;
            if (max_bytes < amount) {
                /* set errno to EOVERFLOW here */
                return -1;
            }
            if (!print(format, amount))
                return -1;
            format += amount;
            bytes_written += amount;
            continue;
        }
        format_start = ++format;

        if (*format == 'c') {
            char c;
            ++format;
            /* char promotes to int */
            c = (char)va_arg(args, int);
            if (!max_bytes) {
                /* set errno to EOVERFLOW */
                return -1;
            }
            if (!print(&c, sizeof(c))
                return -1;
            ++bytes_written;
        }
        else if (*format == 's') {
            const char *s;
            size_t len;

            ++format;
            s = va_arg(args, const char*);
            len = strlen(s);
            if (len > max_bytes) {
                /* set errno to EOVERFLOW */
                return -1;
            }
            if (!print(str, len))
                return -1;
            bytes_written += len;
        }
        else {
            size_t len;
            format = format_start;
            len = strlen(format);
            if (len > max_bytes) {
                /* set errno to EOVERFLOW */
                return -1;
            }
            if (!print(format, len))
                return -1;
            bytes_written += len;
            format += len;
        }
    }
	va_end(args);
	return bytes_written;
}

