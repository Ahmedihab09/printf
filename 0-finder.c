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
	else if (str == 'd')
	{
		return (&_print_d);
	}
	else if (str == 'i')
	{
		return (&_print_i);
	}
	else if (str == 'b')
	{
		return (&_print_b);
	}
	else if (str == 'u')
	{
		return (&_print_u);
	}
	else if (str == 'o')
	{
		return (&_print_o);
	}
	else if (str == 'x')
	{
		return (&_print_x);
	}
	else if (str == 'X')
	{
		return (&_print_X);
	}
	else if (str == 'p')
	{
		return (&_print_p);
	}
	else if (str == 'S')
	{
		return (&_print_S);
	}
	else if (str == 'r')
	{
		return (&_print_r);
	}

	return (0);
}

