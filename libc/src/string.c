#include "string.h"

#ifdef __cplusplus
extern "C"
{
#endif

size_t strlen(const char *str)
{
	/*if (str != 0)
		return sizeof(str)/sizeof(str[0]);
	else
		return 0;*/
	size_t len = 0;
	while (str[len])
		++len;
	return len;
}

#ifdef __cplusplus
}
#endif
