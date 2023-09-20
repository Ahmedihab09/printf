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

<<<<<<< HEAD
    count = hex_print(ptr);

    return count;
=======
	snprintf(addressBuffer, sizeof(addressBuffer), "%p", ptr);
	count = nums_print((unsigned long)ptr, 16);
	return (count);
>>>>>>> 3d7826fdc41de4070575f5956dfab9987e7eb990
}



