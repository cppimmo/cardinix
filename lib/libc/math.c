/* cardinix, file: math.c */
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
#include "math.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* The majority of the library math function implementations here use the
 * GCC builtin functions. They are expanded inline and may only be used as
 * function call expressions. -fno-builtin
 */
	
double acos(double x)
{
#ifdef __GNUC__
	return __builtin_acos(x);
#else
	return 0.0;
#endif
}

double asin(double x)
{
	return 0.0;
}

double atan(double x)
{
	return 0.0;
}

double atan2(double y, double x)
{
	return 0.0;
}

double cos(double x)
{
	return 0.0;
}

double cosh(double x)
{
	return 0.0;
}

double sin(double x)
{
	return 0.0;
}

double sinh(double x)
{
	return 0.0;
}

double tanh(double x)
{
	return 0.0;
}

double exp(double x)
{
	return 0.0;
}

double frexp(double x, int *exponent)
{
	return 0.0;
}

double ldexp(double x, int exponent)
{
	return 0.0;
}

double log(double x)
{
	return 0.0;
}

double log10(double x)
{
	return 0.0;
}

double modf(double x, double *integer)
{
	return 0.0;
}

double pow(double x, double y)
{
	for (int i = 0; i < y; ++i)
		x *= x;
	return x;
}

double sqrt(double x)
{
	return 0.0;
}

double ceil(double x)
{
	return (int)x;
}

double fabs(double x)
{
	return (x < 0.0) ? -(x) : x;
}

double floor(double x)
{
	return 0.0;
}

double fmod(double x, double y)
{
	return (int)x % (int)y;
}

#ifdef __cplusplus
}
#endif

