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
#ifndef _LIBC_TIME_H_
#define _LIBC_TIME_H_

#include <sys/cdefs.h>
#include <stddef.h>

#if !defined(NULL)
#define NULL 0
#endif /* !defined(NULL) */

#define CLK_TCK 0

typedef unsigned long long clock_t;
typedef int time_t;

struct tm {
	int tm_sec;   /* seconds after the minute [0-60] */
	int tm_min;   /* minutes after the hour [0-59] */
	int tm_hour;  /* hours since midnight [0-23] */
	int tm_mday;  /* day of the month [1-31] */
	int tm_mon;   /* months since January [0-11] */
	int tm_year;  /* years since 1900 */
	int tm_wday;  /* days since Sunday [0-6] */
	int tm_yday;  /* days since January 1 [0-365] */
	int tm_isdst; /* daylight savings time flag */
};

__BEGIN_DECLS

/* time manipulation */
clock_t clock(void);
double difftime(time_t time1, time_t time0);
time_t mktime(struct tm *timeptr);
time_t time(time_t *timer);

/* time conversion */
char *asctime(const struct tm *timeptr);
char *ctime(const time_t *timer);
struct tm *gmtime(const time_t *timer);
struct tm *localtime(const time_t *timer);
size_t strftime(char *s, size_t maxsize, const char *format, 
                const struct tm *timeptr);

__END_DECLS

#endif /* !_LIBC_TIME_H_ */
