#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: list of arguments passed
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int pchars = 0
	va_list arlist;
	int x;

	va_start(arlist, format);

	if (format == NULL)
	{
		return (-1);
	}

	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] == '%')
		{
			x++;
			if (format[x] == 'c' || format[x] == '%' || format[x] == 's')
			{
				pchars += finder(format[x])(arlist);
			}
			else
			{
				pchars += _putchar('%');
				continue;
			}
		}
		else
		{
			pchars += _putchar(format[x]);
		}
	}

	return (pchars);
}
