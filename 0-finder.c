#include "main.h"
/**
 * finder - select the appropriate printing function baser on the format specifier.
 * @str: The format specifier character (c, s and %)
 * Return: A function pointer to the selected printing function or NULL if invalid
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
	return (0);
}

