/* cardinix, file: math.h */
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
#ifndef MATH_H
#define MATH_H

#ifdef __cplusplus
extern "C" {
#endif

#define M_PI 3.142
#define HUGE_VAL

double acos(double x);

double asin(double x);

double atan(double x);

double atan2(double y, double x);

double cos(double x);

double sin(double x);

double tan(double x);

double cosh(double x);

double sinh(double x);

double tanh(double x);

double exp(double x);

double frexp(double value, int *exp);

double ldexp(double value, int exp);

double log(double x);

double log10(double x);

double modf(double value, double *iptr);

double pow(double x, double y);

double sqrt(double x);

double ceil(double x);

double fabs(double x);

double floor(double x);

double fmod(double x, double y); 

#ifdef __cplusplus
}
#endif
#endif // MATH_H
