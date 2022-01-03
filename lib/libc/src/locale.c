#include "locale.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

char *setlocale(int category, const char *locale)
{
	bool invalid_category = false;
	switch (category)
	{
	case LC_ALL:
		break;
	case LC_COLLATE:
		break;
	case LC_CTYPE:
		break;
	case LC_MONETARY:
		break;
	case LC_NUMERIC:
		break;
	case LC_TIME:
		break;
	default:
		invalid_category = true;
	}
	return 0;	
}

struct lconv *localeconv(void)
{
	return &currloc;	
}

#ifdef __cplusplus
}
#endif

