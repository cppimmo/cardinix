#include "ctype.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define CTYPE_TRUE 1
#define CTYPE_FALSE 0

#define CTYPE_RANGE_UPPER (c >= 0x41 && c <= 0x5A)
#define CTYPE_RANGE_LOWER (c >= 0x61 && c <= 0x7A)
#define CTYPE_RANGE_DIGIT (c >= 0x30 && c <= 0x39)
#define CTYPE_RANGE_PRINT (c >= 0x20 && c <= 0x7E)

DECLARE_CTYPE_FUNCTION(isalnum)
{
	return 0;
}

DECLARE_CTYPE_FUNCTION(isalpha)
{
	return CTYPE_RANGE_UPPER || CTYPE_RANGE_LOWER;
}

DECLARE_CTYPE_FUNCTION(iscntrl)
{
	return 0;
}

DECLARE_CTYPE_FUNCTION(isdigit)
{
	return CTYPE_RANGE_DIGIT;
}

DECLARE_CTYPE_FUNCTION(isgraph)
{
	return CTYPE_RANGE_PRINT;
}

DECLARE_CTYPE_FUNCTION(islower)
{
	return CTYPE_RANGE_LOWER;
}

DECLARE_CTYPE_FUNCTION(isprint)
{
	return CTYPE_RANGE_PRINT;
}

DECLARE_CTYPE_FUNCTION(ispunct)
{
	static const char *puncts = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{}~";
	for (size_t i = 0; puncts[i] != '\0'; ++i)
	{
		if (c == puncts[i])
			return CTYPE_TRUE;
	}
	return CTYPE_FALSE;
}

DECLARE_CTYPE_FUNCTION(isspace)
{
	return (c == 0x20);
}

DECLARE_CTYPE_FUNCTION(isupper)
{
	return CTYPE_RANGE_UPPER;
}

DECLARE_CTYPE_FUNCTION(isxdigit)
{
	if (c >= 0x30 && c <= 0x39)
	{
		return CTYPE_TRUE;
	}
	else if (c >= 0x41 && c <= 0x5A)
	{
		return CTYPE_TRUE;
	}
	else if (c >= 0x61 && c <= 0x7A)
	{
		return CTYPE_TRUE;
	}
	return CTYPE_FALSE;
}

DECLARE_CTYPE_FUNCTION(tolower)
{
	return c + 32;
}

DECLARE_CTYPE_FUNCTION(toupper)
{
	return c - 32;
}

#ifdef __cplusplus
}
#endif

