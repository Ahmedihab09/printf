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
	else if (str == 'u' || str == 'o' || str == 'x' || str == 'X')
        {
                return (&_print_unsigned);
        }

	return (0);
}
