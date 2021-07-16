#include "signal.h"

#ifdef __cplusplus
extern "C"
{
#endif

void (*signal(int sig, void (*func)(int)))(int)
{

}

int raise(int sig)
{
	return 0;
}

#ifdef __cplusplus
}
#endif

