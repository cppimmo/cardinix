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
#ifndef _LIBC_STDLIB_H_
#define _LIBC_STDLIB_H_

/* 
 * size_t, wchar_t, div_t ldiv_t
 * are defined here 
 */                 
#include <limits.h>
#include <stddef.h>
#include <sys/cdefs.h>

/* constants */
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define RAND_MAX INT_MAX 
#define MB_CUR_MAX 0

#if !defined(NULL)
#define NULL 0
#endif /* !defined(NULL) */

typedef struct {
	int quot;
	int rem;
} div_t;

typedef struct {
	long quot;
	long rem;
} ldiv_t;

__BEGIN_DECLS

/* string conversion */
double atof(const char *nptr);
int atoi(const char *nptr);
long int atol(const char *nptr);
double strtod(const char *nptr, char **endptr);
long int strtol(const char *nptr, char **endptr, int base);
unsigned long int stroul(const char *nptr, char **endptr, int base);

/* psuedo rng */
int rand(void);
void srand(unsigned int seed);

/* memory management */
void *calloc(size_t nmemb, size_t size);
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

/* environment communication */
__attribute__((__noreturn__)) void abort(void);
int atexit(void (*func)(void));
void exit(int status);
char *getenv(const char *name);
int system(const char *string);

/* searching and sorting utilities */
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size,
              int (*compar)(const void *, const void *));
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *,
           const void *));

/* integer arithmetic */
int abs(int j);
div_t div(int numer, int denom);
long int labs(long int j);
ldiv_t ldiv(long int numer, long int denom);

/* multibyte characters */
int mblen(const char *s, size_t n);
int mbtowc(wchar_t *pwc, const char *s, size_t n);
int wctomb(char *s, wchar_t wchar);
/* multibyte strings */
size_t mbstowcs(wchar_t *pwcs, const char *s, size_t n);
size_t wcstombs(char *s, const wchar_t *pwcs, size_t n);

__END_DECLS

#endif /* !_LIBC_STDLIB_H_ */
