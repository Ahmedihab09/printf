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
	char addressBuffer[50];
	int count;

	snprintf(addressBuffer, sizeof(addressBuffer), "%p", ptr);
	count = nums_print((unsigned long)ptr, 16); // Assuming nums_print handles hexadecimal.

	return count;
}

