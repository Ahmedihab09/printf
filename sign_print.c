#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * sign_print - Custom print function to output a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int sign_print(const char *str)
{
	int count = 0;

	while (*str)
	{
		putchar(*str);
		str++;
		count++;
	}
	return (count);
}
