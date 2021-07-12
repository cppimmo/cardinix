#ifndef STDLIB_H
#define STDLIB_H

extern "C" {

// constants
#define EXIT_FAILURE -1
#define EXIT_SUCCESS 0
#define RAND_MAX 0
#define MB_CUR_MAX 0

// function declarations
double atof(const char *str);
int atoi(const char *str);
long int atol(const char *str);
double strtod(const char *str, char **endptr);
long int strtol(const char *str, char **endptr, int base);
unsigned long int stroul();

}
#endif // STDLIB_H
