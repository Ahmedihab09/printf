#include "main.h"
/**
 * finder - select the appropriate printing func. based on format specifier.
 * @str: The format specifier character (c, s and %)
 * Return: A func. pointer to the selected printing func. or NULL if invalid
 */
int (*finder(char str))(va_list arlist)
{
	if (str == 'c')
	{
		return (&_print_char);
	}
	else if (str == 's')
	{
		return (&_print_string);
	}
	else if (str == '%')
	{
		return (&_print_percent);
	}
	if (str == 'd' || str == 'i')
	{
		return (&_print_int);
	}

	return (0);
}
