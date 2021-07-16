#include "math.h"

#ifdef __cplusplus
extern "C"
{
#endif

double acos(double x)
{
	return 0.0;
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

