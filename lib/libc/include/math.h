#ifndef MATH_H
#define MATH_H

#ifdef __cplusplus
extern "C" {
#endif

#define M_PI 3.14159265358979323846264338327


double acos(double x);


double asin(double x);


double atan(double x);


double atan2(double y, double x);

	
double cos(double x);


double cosh(double x);


double sin(double x);


double sinh(double x);


double tanh(double x);


double exp(double x);


double frexp(double x, int *exponent);


double ldexp(double x, int exponent);


double log(double x);


double log10(double x);


double modf(double x, double *integer);


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
