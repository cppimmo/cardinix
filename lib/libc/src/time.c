/* cardinix, file: time.c */
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
#include "time.h"

#ifdef __cplusplus
extern "C"
{
#endif

char *asctime(const struct tm *timeptr)
{
	return 0;
}

clock_t clock(void)
{
	return 0;
}

char *ctime(const time_t *timer)
{
	return 0;
}

double difftime(time_t time1, time_t time2)
{
	return 0;
}

struct tm *gmtime(const time_t *timer)
{
	return 0;
}

struct tm *localtime(const time_t *timer)
{
	return 0;
}

time_t mktime(struct tm *timeptr)
{
	return 0;
}

size_t strftime(char *str, size_t maxsize, const char *format,
	const struct tm *timeptr)
{
	return 0;
}

time_t time(time_t *timer)
{
	return 0;
}

#ifdef __cplusplus
}
#endif

