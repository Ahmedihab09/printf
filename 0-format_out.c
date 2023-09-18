#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _print_char(va_list arlist)
{
	char c = va_arg(arlist, int);
	putchar(c);
	return 1;
}

int _print_string(va_list arlist)
{
	char *strn = va_arg(arlist, char*);
	if (strn == NULL)
	{
		fputs("(null)", stdout);
		return 6;
	}

	int strnlen = 0;
	while (strn[strnlen] != '\0')
	{
		putchar(strn[strnlen]);
		strnlen++;
	}
	return strnlen;
}

int _printf(const char *format, ...)
{
	int pchars = 0;
	va_list arlist;

	va_start(arlist, format);

	if (format == NULL)
	{
		return -1;
	}
	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			pchars++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				pchars += _print_char(arlist);
			}
			else if (*format == 's')
			{
				pchars += _print_string(arlist);
			}
			else if (*format == '%')
			{
				putchar('%');
				pchars++;
			}
		}
		format++;
	}
	va_end(arlist);
	return pchars;
}


