#include "main.h"

int _printf(const char *format, ...);

/**
 * _printf - a function that produces output according to a format.
 * @format: list of arguments passed
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int pchars = 0;
	va_list arlist;
	char buffer[1024];
	int buf_index = 0;

	va_start(arlist, format);

	if (format == NULL)
	{
		return (-1);
	}
	while (*format)
	{
		if (*format != '%')
		{
			if (buf_index < sizeof(buffer) - 1)
			{
				buffer[buf_index++] = *format;
			}
			else
			{
				buffer[buf_index] = '\0';
				pchars += _putchar(*buffer);
				buf_index = 0;
			}
			pchars++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == 'c')
			{
				int printed = _print_char(arlist, buffer + buf_index, sizeof(buffer) - buf_index);

				pchars += printed;
				buf_index += printed;
			}
			else if (*format == 's')
			{
				int printed = _print_string(arlist, buffer + buf_index, sizeof(buffer) - buf_index);

				pchars += printed;
				buf_index += printed;
			}
			else if (*format == '%')
			{
				int printed = _print_percent(buffer + buf_index, sizeof(buffer) - buf_index);

				pchars += printed;
				buf_index += printed;
			}
		}
		format++;
	}
	if (buf_index > 0)
	{
		buffer[buf_index] = '\0';
		pchars += _putchar(*buffer);
	}
	va_end(arlist);
	return (pchars);
}

