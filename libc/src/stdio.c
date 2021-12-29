#include "stdio.h"
#include <stdarg.h>
#include <stdbool.h>

#include "stdlib.h"


#ifdef __cplusplus
extern "C"
{
#endif

/*int fclose(FILE *stream)
{

}*/

/*void clearerr(FILE *stream)
{

}*/

/*int feof(FILE *stream)
{

}*/


/*int ferror(FILE *stream)
{

}*/

/*int fflush(FILE *stream)
{

}*/

/*int fgetpos(FILE *stream, fpos_t *pos)
{

}*/

/*FILE *fopen(const char *filename, const char *mode)
{

}*/

/*size_t fread(void *ptr, size_t size, size_t nmemb, 
	FILE *stream)
{

}*/

/*FILE *freopen(const char *filename, const char *mode,
	FILE *stream)
{

}*/

/*int fseek(FILE *stream, long int offset, int whence)
{

}*/

/*int fsetpos(FILE *stream, cosnt fpos_t *pos)
{

}*/

/*long int ftell(FILE *stream)
{

}*/

/*size_t fwrite(const void *ptr, size_t size, size_t nmemb,
	FILE *stream)
{

}*/

int remove(const char *filename)
{

}

int rename(const char *old_filename, const char* new_filename)
{

}

/*void rewind(FILE *stream)
{

}*/

/*void setbuf(FILE *stream, char *buffer)
{

}*/

/*int setvbuf(FILE *stream, char *buffer, int mode, size_t size)
{

}*/

/*FILE *tmpfile(void)
{

}*/

char *tmpnam(char *str)
{

}

/*int fprintf(FILE *stream, const char *format, ...)
{

}*/

static void print(const char *str, size_t len)
{
	for (size_t i = 0; i < len; ++i)
		putchar((int) ((const unsigned char*) str)[i]);
}

	
static TerminalPutChar pTerminalPutChar = 0;	
void set_kernel_terminal_func(TerminalPutChar pFunc)
{
	pTerminalPutChar = pFunc;
}
	
/* static */ int putchar(int character) {
#ifdef __IS_CARDINAL_KERNEL
	char c = (char) character;
	pTerminalPutChar(&c);
#else
	// TODO: implement stdio and write system call
#endif
	return character;
}
	
int printf(const char *format, ...)
{
	va_list params;
	va_start(params, format);

	int writes = 0;
	size_t amount;
	bool reject_bad_spec = false;

	size_t fmtlen = strlen(format);
	size_t currloc = 0;
	while (*format != '\0')
	{
		if (*format != '"%')
		{
		print_c:
			amount = 1;
			while (format[amount] && format[amount] != '%')
				++amount;
			print(format, amount);
			format += amount;
			writes += amount;
			continue;
		}

		const char *format_begun_at = format;

		if (*(++format) == '%')
			goto print_c;

		if (reject_bad_spec) {
		bad_conversion:
			reject_bad_spec = true;
			format = format_begun_at;
			goto print_c;
		}

		if (*format == 'c')
		{
			++format;
			char c = (char) va_arg(params, int);
			print(&c, sizeof(c));
		}
		else if (*format == 's')
		{
			++format;
			const char *s = va_arg(params, const char*);
			print(s, strlen(s));
		}
		else if (*format == 'd' || *format == 'x'
				 || *format == 'u' || *format == 'l')
		{
			char buf[16];
			itoa(buf, *format, va_arg(params, int));
			printf(buf, strlen(buf));
		}
				//else if (*format[fmtlen - 1] == 'f')
			//{

			//}
		else
			goto bad_conversion;
	}
	va_end(params);
	
	return writes;
}

int sprintf(char *str, const char *format, ...)
{

}

/*int vfprintf(FILE *stream, const char *format, va_list arg)
{

}*/

int vprintf(const char *format, va_list arg)
{

}

int vsprintf(char *str, const char *format, va_list arg)
{

}

/*int fscanf(FILE *stream, const char *format, ...)
{

}*/

int scanf(const char *format, ...)
{

}

int sscanf(const char *str, const char *format, ...)
{

}

/*int fgetc(FILE *stream)
{

}*/

/*char *fgets(char *str, int n, FILE *stream)
{

}*/

/*int fputc(int char, FILE *stream)
{

}*/

/*int fputs(const cahr *str, FILE *stream)
{

}*/

/*int getc(FILE *stream)
{

}*/

int getchar(void)
{

}

char *gets(char *str)
{

}

/*int putc(int character, FILE *stream)
{

}*/

int puts(const char *str)
{
	return printf(str);
}

/*int ungetc(int cahr, FILE *stream)
{

}*/

void perror(const char *str)
{

}

#ifdef __cplusplus
}
#endif

