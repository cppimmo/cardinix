/* cardinix, file: stdlib.c */
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
#include "stdlib.h"

/* functions marked with "should impl?"
 * are likely not definable for a non-hosted env.
 */

#ifdef __cplusplus
extern "C"
{
#endif

double atof(const char *str)
{
	return 0.0;
}

char *itoa(int value, char *str, int base)
{
	char *pBuf = str;
	char *p1, *p2;
	unsigned long ud = base;
	int divisor = 10;

	/* if %d is specified and D is minus put '-' in the head*/
	if (base == 'd' && value < 0)
	{
		*pBuf++ = '-';
		str++;
		ud = -base;
  	}
	else if (base == 'x')
		divisor = 16;

	do {
		int remainder = ud % divisor;
		*pBuf++ = (remainder < 10) ? remainder + '0' : remainder + 'a' - 10;
	} while (ud /= divisor);

	/* Terminate buf. */
	*pBuf = 0;

	/* Reverse buf */
	p1 = str;
	p2 = pBuf - 1;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		++p1;
		--p2;
	}
	return str;
}
	
int atoi(const char *str)
{
	return 0;
}

long int atol(const char *str)
{
	return 0;
}

double strtod(const char *str, char **endptr)
{
	return 0.0;
}

long int strtol(const char *str, char **endptr, int base)
{
	return 0;
}

unsigned long int strtoul(const char *str, char **endptr, int base)
{
	return 0;
}

void *calloc(size_t nitems, size_t size)
{
	return 0;
}

void free(void *ptr)
{

}

void *malloc(size_t size)
{
	return 0;
}

void *realloc(void *ptr, size_t size)
{
	return 0;
}

void abort(void)
{
#ifdef __IS_CARDINAL_
	// TODO: add proper kernel panic.
	printf("Kernel: Panic: abort()\n");
#else
	// TODO: terminate proc if by SIGABRT
	printf("abort()\n");
#endif
	while (1)
	{
		;
	}
	__builtin_unreachable();
}

int atexit(void (*func)(void))
{ // should impl?
	return 0;
}

void exit(int status)
{ // should impl?

}

char *getenv(const char *name)
{ // should impl?
	return 0;
}

int system(const char *string)
{ // should impl?
	return 0;
}

void *bsearch(const void *key, const void *base, size_t nitems,
	size_t size, int (*compar)(const void*, const void*))
{

}

void qsort(void *base, size_t nitems, size_t size,
	int (*compar)(const void*, const void*))
{

}

int abs(int x)
{
	return (x < 0) ? -(x) : x;
}

div_t div(int numer, int denom)
{
	const div_t ret = {
		.quot = numer / denom,
		.rem = numer % denom,
	};
	return ret;
}

long int labs(long int x)
{
	return (x < 0) ? -(x): x;
}

ldiv_t ldiv(long int numer, long int denom)
{
	const ldiv_t ret = {
		.quot = numer / denom,
		.rem = numer % denom,
	};
	return ret;
}

int rand(void)
{
	return 0;
}

void srand(unsigned int seed)
{

}

int mblen(const char *str, size_t n)
{
	return 0;
}

/* size_t mbstowcs(schar_t *pwcs, const cahr *str, size_t n)
{
	return 0;
} */

int mbtowc(wchar_t *pwc, const char *str, size_t n)
{
	return 0;
}

size_t wcstombs(char *str, const wchar_t *pwcs, size_t n)
{
	return 0;
}

int wctomb(char *str, wchar_t wchar)
{
	if (str == 0)
		return -1;
	return 0;
}

#ifdef __cplusplus
}
#endif

