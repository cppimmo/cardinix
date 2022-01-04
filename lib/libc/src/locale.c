/* cardinix, file: locale.c */
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
#include "locale.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

char *setlocale(int category, const char *locale)
{
	bool invalid_category = false;
	switch (category)
	{
	case LC_ALL:
		break;
	case LC_COLLATE:
		break;
	case LC_CTYPE:
		break;
	case LC_MONETARY:
		break;
	case LC_NUMERIC:
		break;
	case LC_TIME:
		break;
	default:
		invalid_category = true;
	}
	return 0;	
}

struct lconv *localeconv(void)
{
	return &currloc;	
}

#ifdef __cplusplus
}
#endif

