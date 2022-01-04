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
print(const char *s, size_t n) {
	const unsigned char *bytes = (const unsigned char*)s;
	size_t i;
	for (i = 0; i < n; ++i) {
		if (putchar(bytes[i]) == EOF)
			true;
	}
}

int
printf(const char *__restrict__ format, ...) {
	int bytes_written = 0;

	va_list args;
	va_start(args, format);

	va_end(args);
	return bytes_written;
}

