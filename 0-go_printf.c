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
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;


	va_start(arlist, format);

	if (format == NULL)
	{
		return (-1);
	}

	for (x = 0; format[x] != '\0'; x++)
	{
		int (*printer)(va_list) = finder(format[x]);

		if (format[x] == '%')
		{
			x++;
			if (format[x] == 'c' || format[x] == 's' || format[x] == 'd'
				|| format[x] == 'i' || format[x] == 'b')
			{
				int len = 0;
				if (buffer_index >= BUFFER_SIZE)
				{
					pchars += write(1, buffer, buffer_index);
					buffer_index = 0;
				}

				if (printer != NULL)
				{
					len = printer(arlist);
					if (len > 0)
					{
						buffer_index += len;
						pchars += len;
					}
				}
			}
			else
			{
				if (buffer_index >= BUFFER_SIZE)
				{
					pchars += write(1, buffer, buffer_index);
					buffer_index = 0;
				}
				buffer[buffer_index++] = '%';
				buffer[buffer_index++] = format[x];
				pchars += 2;
			}
		}
		else
		{
			if (buffer_index >= BUFFER_SIZE)
			{
				pchars += write(1, buffer, buffer_index);
				buffer_index = 0;
			}
			buffer[buffer_index++] = format[x];
			pchars++;
		}
	}

	if (buffer_index > 0)
	{
		pchars += write(1, buffer, buffer_index);
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
