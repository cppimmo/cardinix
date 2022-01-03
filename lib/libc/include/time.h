#ifndef TIME_H
#define TIME_H

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef unsigned long long clock_t;
typedef int time_t;

#define CLOCKS_PER_SEC 0

struct tm
{
	int tm_sec; // 0 - 59
	int tm_min; // 0 - 59
	int tm_hour; // 0 - 23
	int tm_mday; // 1 - 31
	int tm_mon; // 0 - 11
	int tm_year; // since 1900
	int tm_wday; // 0 - 6
	int tm_yday; // 0 - 365
	int tm_isdst; // daylight savings
};

char *asctime(const struct tm *timeptr);
clock_t clock(void);
char *ctime(const time_t *timer);
double difftime(time_t time1, time_t time2);
struct tm *gmtime(const time_t *timer);
struct tm *localtime(const time_t *timer);
time_t mktime(struct tm *timeptr);
size_t strftime(char *str, size_t maxsize, const char *format,
	const struct tm *timeptr);
time_t time(time_t *timer);

#ifdef __cplusplus
}
#endif

#endif // TIME_H
