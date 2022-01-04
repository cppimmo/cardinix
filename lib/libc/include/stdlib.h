/* cardinix, file: stdlib.h */
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
#ifndef STDLIB_H
#define STDLIB_H

// size_t, wchar_t, div_t ldiv_t
// are defined here ||
//                  \/
#include <stddef.h>
#include <sys/cdefs.h>

#ifdef __cplusplus
extern "C" {
#endif

// constants
#define EXIT_FAILURE -1
#define EXIT_SUCCESS 0
#define RAND_MAX 0
#define MB_CUR_MAX 0

typedef struct
{
	int quot;
	int rem;
} div_t;

typedef struct
{
	long quot;
	long rem;
} ldiv_t;

// function declarations


double atof(const char *str);


char *itoa(int value, char *str, int base);


int atoi(const char *str);


long int atol(const char *str);


double strtod(const char *str, char **endptr);


long int strtol(const char *str, char **endptr, int base);


unsigned long int stroul(const char *str, char **endptr, int base);


void *calloc(size_t nitems, size_t size);


void free(void *ptr);


void *malloc(size_t size);


void *realloc(void *ptr, size_t size);


__attribute__((__noreturn__))
void abort(void);


int atexit(void (*func)(void));


void exit(int status);


char *getenv(const char *name);


int system(const char *string);


void *bsearch(const void *key, const void *base, size_t nitems,
	size_t size, int (*compar)(const void*, const void*));


void qsort(void *base, size_t nitems, size_t size,


int (*compar)(const void*, const void*));


int abs(int x);


div_t div(int number, int denom);


long int labs(long int x);


ldiv_t ldiv(long int numer, long int denom);


int rand(void);


void srand(unsigned int seed);


int mblen(const char *str, size_t n);


// what is schar_t ?
// size_t mbstowcs(schar_t *pwcs, const char *str, size_t n);


int mbstowc(wchar_t *pwc, const char *str, size_t n);


size_t wcstombs(char *str, const wchar_t *pwcs, size_t n);


int wctomb(char *str, wchar_t wchar);

#ifdef __cplusplus
}
#endif

#endif // STDLIB_H
