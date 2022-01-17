#ifndef _UTIL_H_
#define _UTIL_H_

#include "ccsh.h"
#include <stdargs.h>

/* Exit codes: */
#define EXIT_BAD_COMMAND 0x02
#define EXIT_BAD_ARGS 0x03

enum ccsh_logtype {
    CCSH_LOG_LOG,
    CCSH_LOG_MESSAGE,
    CCSH_LOG_ERROR,
};

int ccsh_log(enum ccsh_logtype type, ...);

#endif /* !_UTIL_H_ */
