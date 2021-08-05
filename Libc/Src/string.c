#include "string.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define STRING_TRUE 1
#define STRING_FALSE 0
#define STRING_LESS_THAN -1
#define STRING_GREATER_THAN 1

void *memchr(const void *str, int c, size_t n)
{
	unsigned char *pch = 0;
	const size_t len = strlen((const char*)str);
	for (size_t i = 0; i < n; ++i)
	{
		if (!(i > len)) // not out of range
		{
			pch = (unsigned char)&str[i];
			break;
		}
	}
	if (pch != 0)
		return pch;
	return 0;
}

int memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char *pStr1 = (const unsigned char*) str1;
	const unsigned char *pStr2 = (const unsigned char*) str2;
	for (size_t i = 0; i < n; ++i)
	{
		if (pStr1[i] < pStr2[i])
			return -1;
		else if (pStr1[i] > pStr2[i])
			return 1;
	}
	return 0;
}

void *memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *pDest = (unsigned char*) dest;
	const unsigned char *pSrc = (unsigned char*) src;
	for (size_t i = 0; i < n; ++i)
		pDest[i] = pSrc[i];
	return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
	unsigned char *pDest = (unsigned char*) dest;
	const unsigned char* pSrc = (const unsigned char*) src;
	if (dest < src)
	{
		for (size_t i = 0; i < n; ++i)
			pDest[i] = pSrc[i];
	}
	else
	{
		for (size_t i = n; i != 0; --i)
			pDest[i - 1] = pSrc[i - 1];
	}
	return dest;
}

void *memset(void *str, int c, size_t n)
{
	unsigned char *strbuf = (unsigned char*)str;
	for (size_t i = 0; i < n; ++i)
		strbuf[i] = (unsigned char) c;
	return str;
}

char *strcat(char *dest, const char *src)
{
	const size_t destlen = strlen(dest), srclen = strlen(src);
	const size_t newlen = destlen + srclen;

	return 0;
}

char *strncat(char *dest, const char *src, size_t n)
{
	// subtract n characters from src
	const size_t destlen = strlen(dest), srclen = strlen(src) - n;
	const size_t newlen = destlen + srclen;

	return 0;
}

char *strchr(const char *str, int c)
{
	char *pch = 0;
	const size_t len = strlen(str);
	for (size_t i = 0; i <= len - 1; ++i)
	{
		if (str[i] == (char)c)
		{
			pch = &str[i];
			break;
		}
	}
	if (pch != 0)
		return pch;
	return 0;
}

int strcmp(const char *str1, const char *str2)
{
	int hits = 0; // number of characters that do match
	const size_t len1 = strlen(str1), len2 = strlen(str2);
	if (len1 == len2)
	{
		for (size_t i = 0; i <= len1 - 1; ++i)
		{
			if (str1[i] == str2[i])
				++hits;
		}
		if (hits == len1)
		{
			return STRING_TRUE;
		}
	}
	else if (len1 < len2)
		return STRING_LESS_THAN;
	else if (len1 > len2)
		return STRING_GREATER_THAN;
	return STRING_FALSE;
}

int strncmp(const char *str1, const char *str2, size_t n)
{
	int hits = 0; // number of characters that do match
	// subtract n number of characters from lengths
	const size_t len1 = strlen(str1) - n, len2 = strlen(str2) - n;
	if (len1 == len2)
	{
		for (size_t i = 0; i <= len1 - 1; ++i)
		{
			if (str1[i] == str2[i])
				++hits;
		}
		if (hits == len1)
		{
			return STRING_TRUE;
		}	
	}
	else if (len1 < len2)
		return STRING_LESS_THAN;
	else if (len1 > len2)
		return STRING_GREATER_THAN;
	return STRING_FALSE;
}

int strcoll(const char *str1, const char *str2)
{ // like strcmp but dependent on locale setting?

	return 0;
}

char *strcpy(char *dest, const char *src)
{
	return 0;
}

char *strncpy(char *dest, const char *src, size_t n)
{
	return 0;
}

size_t strcspn(const char *str1, const char *str2)
{
	size_t ret = 0;
	const size_t len1 = strlen(str1), len2 = strlen(str2);
	for (size_t i = 0; i <= len1 - 1; ++i)
	{
		for (size_t j = 0; j <= len2 - 1; ++j)
		{
			if (str1[i] != str2[i])
				++ret;
			else
				break;
		}
	}
	return ret;
}

char *strerror(int errnum)
{ // describe error message produced my errno
	static const char *pErrMsgs[] = 
	{
		[0] = "",
		[1] = "",
	};
	if (errnum >= 0 && errnum < 
			(sizeof(pErrMsgs) / sizeof(pErrMsgs[0])))
	{ // prevent 
		char *pMsg = pErrMsgs[errnum];
		return pMsg;
	}
	return 0;
}

size_t strlen(const char *str)
{
	/*if (str != 0)
		return (sizeof(str)/sizeof(str[0])) - 1;
	else
		return 0;*/
	size_t len = 0;
	while (str[len])
		++len;
	return len;
}

char *strpbrk(const char *str1, const char *str2)
{
	char *pch = 0;
	const size_t len1 = strlen(str1), len2 = strlen(str2);
	for (size_t i = 0; i <= len1 - 1; ++i)
	{
		for (size_t j = 0; j <= len2 - 1; ++j)
		{
			if (str1[i] == str2[j])
			{
				pch = &str1[i];
				break;
			}
		}
	}
	if (pch != 0)
		return pch;
	return 0;
}

char *strrchr(const char *str, int c)
{
	char *pch = 0;
	const size_t len = strlen(str);
	
	for (size_t i = 0; i <= len - 1; ++i)
	{
		if (str[i] == (char)c) 
		{
			pch = &str[i];	
		} // continually replace resultant in pch until last it found
	}
	if (pch != 0)
		return pch;
	return 0;
}

size_t strspn(const char *str1, const char *str2)
{
	size_t matched = 0;
	const size_t len1 = strlen(str1), len2 = strlen(str2);
	for (size_t i = 0; i <= len1 - 1; ++i)
	{ // loop first string
		for (size_t j = 0; j <= len2 - 1; ++j)
		{ // loop through match string for each charcter in str1
			if (str1[i] == str2[j])
				++matched;
		}
	}
	return matched;
}

char *strstr(const char *haystack, const char *needle)
{
	char *pch = 0;

	

	if (pch != 0)
		return pch;
	return 0;
}

char *strtok(char *str, const char *delim)
{
	const size_t slen = strlen(str), dlen = strlen(delim);
	size_t delimiter_loc = 0;
	for (size_t i = 0; i <= slen - 1; ++i)
	{
		for (size_t j = 0; i <= dlen - 1; ++j)
		{
			delimiter_loc = i;
			// if (
		}
	}
	return 0;
}

size_t strxfrm(char *dest, const char *src, size_t n)
{
	return 0;
}

#ifdef __cplusplus
}
#endif

