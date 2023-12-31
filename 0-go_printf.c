#include "main.h"
#define BUFFER_SIZE 1024

int _putchar(char c);

int _putchar_int(int n);

/**
 * _printf - a function that produces output according to a format.
 * @format: list of arguments passed
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int pchars = 0;
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
			if (format[x] == 'c' || format[x] == 's' || format[x] == 'd'
				|| format[x] == 'i' || format[x] == 'b')
			{
				pchars += finder(format[x])(arlist);
			}
			else if (format[x] == 'u')
			{
				pchars += _print_u(arlist);
			}
			else if (format[x] == 'o')
			{
				pchars += _print_o(arlist);
			}
			else if (format[x] == 'x')
			{
				pchars += _print_x(arlist);
			}
			else if (format[x] == 'X')
			{
				pchars += _print_X(arlist);
			}
			else if (format[x] == 'r')
			{
				pchars += _print_r(arlist);
			}
			else if (format[x] == 'p')
			{
				pchars += _print_p(arlist);
			}
			else if (format[x] == 'S')
			{
				pchars += _print_S(arlist);
			}
			else
			{
				pchars += _putchar('%');
				pchars += _putchar(format[x]);
			}
		}
		else
		{
			pchars += _putchar(format[x]);
		}
	}
	va_end(arlist);
	return (pchars);
}

/**
 * _putchar_int - Prints an integer to the standard output.
 * @n: The integer to be printed.
 *
 * This function takes an integer as input
 * and recursively prints its digits
 * one by one to the standard output.
 * If the integer is negative, it first
 * prints a '-' sign before printing the
 * absolute value of the integer.
 *
 * Return: The total number of characters printed, which includes the '-' sign
 *         for negative integers.
 */
int _putchar_int(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		count++;
	}
	if (n / 10)
	{
		count += _putchar_int(n / 10);
	}
	_putchar(n % 10 + '0');
	return (count + 1);
}

