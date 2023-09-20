#include <stdio.h>
#include "main.h"
/**
 * hex_print - Custom print function to print a pointer address in hexadecimal.
 * @ptr: The pointer to print.
 *
 * Return: The number of characters printed.
 */
int hex_print(void *ptr)
{
	unsigned long address = (unsigned long)ptr;
	int count = 0;
	int hexDigits = sizeof(void *) * 2;
	int i;

	putchar('0');
	putchar('x');

	for (i = hexDigits - 1; i >= 0; i--)
	{
		int shift;
		unsigned long digit;
		char hexChar;

		shift = i * 4;
		digit = (address >> shift) & 0xF;
		hexChar = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
		putchar(hexChar);
		count++;
	}

	return (count);
}

