#include "main.h"

/**
 * _print_char - prints a character
 * @arlist: The va_list containing the character to print
 * Return: The number of characters printed
 */
int _print_char(va_list arlist)
{
	int count;
	char pul_char = va_arg(arlist, int);

	count = _putchar(pul_char);
	return (count);
}

/**
 * _print_string - prints a string
 * @arlist: The va_list containing the string to print
 * Return: The number of characters printed
 */
int _print_string(va_list arlist)
{
	int count = 0;
	char *pntr = va_arg(arlist, char *);

	if (pntr == NULL)
	{
		pntr = "(null)";
	}
	while (*pntr)
	{
		count += _putchar(*pntr);
		pntr++;
	}

	return (count);
}
/**
 * _print_percent - prints a '%'
 * @arlist: the valist contain percent
 * Return: The number of characters printed
 */
int _print_percent(va_list arlist)
{
	(void)arlist;
	return (_putchar('%'));
}
/**
 * _print_d - Prints an integer.
 * @arlist: A va_list containing the integer to print.
 *
 * This function takes an integer from a va_list and prints it to the standard output.
 *
 * Return: The number of characters printed.
 */
int print_number(int num, int flags);

int _print_d(va_list arlist)
{
	int count;
	int pul_int = va_arg(arlist, int);

	count = print_number(pul_int, 0);
	return (count);
}

