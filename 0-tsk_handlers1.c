#include "main.h"
/**
 * _print_u - Print an unsigned decimal integer.
 * @arlist: A va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int _print_u(va_list arlist)
{
	unsigned int num = va_arg(arlist, unsigned int);
	char numBuffer[50];
	int count;

	snprintf(numBuffer, sizeof(numBuffer), "%u", num);
	count = sign_print(numBuffer);

	return count;
}

/**
 * _print_o - Print an octal integer.
 * @arlist: A va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int _print_o(va_list arlist)
{
	unsigned int num = va_arg(arlist, unsigned int);
	char numBuffer[50];
	int count;

	snprintf(numBuffer, sizeof(numBuffer), "%o", num);
	count = sign_print(numBuffer);

	return count;
}

/**
 * _print_x - Print a hexadecimal integer (lowercase).
 * @arlist: A va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int _print_x(va_list arlist)
{
	unsigned int num = va_arg(arlist, unsigned int);
	char numBuffer[50];
	int count;

	snprintf(numBuffer, sizeof(numBuffer), "%x", num);
	count = sign_print(numBuffer);

	return count;
}

/**
 * _print_X - Print a hexadecimal integer (uppercase).
 * @arlist: A va_list containing the integer to print.
 *
 * Return: The number of characters printed.
 */
int _print_X(va_list arlist)
{
	unsigned int num = va_arg(arlist, unsigned int);
	char numBuffer[50];
	int count;

	snprintf(numBuffer, sizeof(numBuffer), "%X", num);
	count = sign_print(numBuffer);

	return count;
}

