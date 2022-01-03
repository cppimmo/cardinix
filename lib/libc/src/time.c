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

