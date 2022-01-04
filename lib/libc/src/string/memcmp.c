/* cardinix, file: memcmp.c */
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

int
memcmp(const void *s1, const void *s2, size_t n) {
	const unsigned char *memory_a = (const unsigned char*)s1;
	const unsigned char *memory_b = (const unsigned char*)s2;
	size_t i;
	for (i = 0; i < n; ++i) {
		if (memory_a[i] < memory_b[i]) {
			return -1;
		}
		else if (memory_b[i] < memory_a[i]) {
			return 1;
		}
	}
	return 0;
}

