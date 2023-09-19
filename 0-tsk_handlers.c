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
 * Return: The number of characters printed
 */
