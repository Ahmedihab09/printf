#include "main.h"
#include <stdarg.h>

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
 * _print_integer - prints an integer (d or i specifier)
 * @arlist: The va_list containing the integer to print
 * Return: The number of characters printed
 */
int _print_integer(va_list arlist)
{
	int num = va_arg(arlist, int);
	int pchars = 0;
	int temp = num;
	int num_digits = 0;

	if (num < 0)
	{
		_putchar('-');
		pchars++;
		num = -num;
	}


	if (num == 0)
	{
		_putchar('0');
		return 1;
	}



	while (temp > 0)
	{
		temp /= 10;
		num_digits++;
	}


	while (num > 0)
	{
		int digit = num % 10;
		_putchar('0' + digit);
		pchars++;
		num /= 10;
	}

	return pchars;
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
			else if (*format == 'd' || *format == 'i')
			{
				pchars += _print_integer(arlist);
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

