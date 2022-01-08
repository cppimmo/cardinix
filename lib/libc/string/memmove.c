/* cardinix, file: memmove.c */
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
#include <string.h>

/* n is size */
void *
memmove(void *dest, const void *src, size_t n)
{
	unsigned char *local_dest = (unsigned char*)dest;
	const unsigned char *src = (const unsigned char*)src;
	size_t i;
	if (dest < src) {
		for (i = 0; i < n; ++i)
			local_dest[i] = src[i];
	}
	else {
		for (i = n; i != 0; --i)
			local_dest[i - 1] = src[i - 1];
	}
	return dest;
}

