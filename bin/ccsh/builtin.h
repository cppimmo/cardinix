#ifndef _BUILTIN_H_
#define _BUILTIN_H_

#include "ccsh.h"

#define CCSH_BUILTIN_SUCCESS
#define CCSH_BUILTIN_FAILURE

typedef int (*ccsh_builtin_func)(char *args[]);

extern char *builtins_name[];
extern builtins_func[];
extern size_t builtins_size;

/* Execute builtin from string. */
int ccsh_builtin_from_str(char *str);

/* Builtins: */
int ccsh_builtin_cd(char *args[]);
int ccsh_builtin_help(char *args[]);
int ccsh_builtin_exit(char *args[]);

#endif /* !_BUILTIN_H_ */
