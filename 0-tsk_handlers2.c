#include "main.h"
/**
 * _print_p - Print a pointer address in hexadecimal format.
 * @arlist: A va_list containing the pointer to print.
 *
 * Return: The number of characters printed.
 */
int _print_p(va_list arlist)
{
	void *ptr = va_arg(arlist, void *);
	int count = 0;

	count = hex_print(ptr);

	return count;
}

