#include "main.h"

/**
 * _print_char - prints a character
 * @arlist: The va_list containing the character to print
 * Return: The number of characters printed
 */
int _print_char(va_list arlist)
{
	char c = va_arg(arlist, int);

	return (_putchar(c));
}

/**
 * _print_string - prints a string
 * @arlist: The va_list containing the string to print
 * Return: The number of characters printed
 */
int _print_string(va_list arlist)
{
	char *strn = va_arg(arlist, char*);
	int strnlen = 0;

	while (strn[strnlen] != '\0')
	{
		_putchar(strn[strnlen]);
		strnlen++;
	}
	return (strnlen);
}

/**
 * _printf - a function that produces output according to a format.
 * @format: list of arguments passed
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int pchars = 0;
	va_list arlist;

	va_start(arlist, format);

	if (format == NULL)
	{
		return (-1);
	}
	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
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
				_putchar('%');
				pchars++;
			}
		}
		format++;
	}
	va_end(arlist);
	return (pchars);
}
