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

int _print_d(va_list arlist)
{
	int count;
	int pul_int = va_arg(arlist, int);

	count = nums_print(pul_int, 0);
	return (count);
}
/**
 * _print_i - Prints an integer.
 * @arlist: A va_list containing the integer to print.
 *
 * This function takes an integer from a va_list and prints it to the standard output.
 *
 * Return: The number of characters printed.
 */
int _print_i(va_list arlist)
{
        int count;
        int pul_int = va_arg(arlist, int);

        count = nums_print(pul_int, 0);
        return (count);
}
/**
 * _print_b - Prints an unsigned integer in binary representation.
 * @arlist: A va_list containing the unsigned integer to print.
 *
 * This function takes an unsigned integer from a va_list and prints its binary
 * representation to the standard output.
 *
 * Return: The number of characters printed.
 */
int _print_b(va_list arlist)
{
	unsigned int num = va_arg(arlist, unsigned int);
	int count = 0;
	int significantDigitFound = 0;
	int i;

	for (i = sizeof(num) * 8 - 1; i >= 0; i--)
	{
		int bit = (num >> i) & 1;

		if (bit == 1 || significantDigitFound)
		{
			_putchar(bit + '0');
			count++;
			significantDigitFound = 1;
		}
	}

	if (count == 0)
	{
		_putchar('0');
		count++;
	}

	return count;
}
/**
 * print_unsigned - Prints unsigned integers based on the format specifier.
 * @arlist: A va_list containing the unsigned integer to print.
 * @format: The format specifier character ('u', 'o', 'x', or 'X').
 *
 * This function determines which conversion specifier to use based on the format
 * character and calls the appropriate function to print the unsigned integer in
 * the specified representation.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list arlist, const char *format)
{
	int count = 0;

	switch (*format)
	{
	case 'u':
		count += _print_u(arlist);
		break;
	case 'o':
		count += _print_o(arlist);
		break;
	case 'x':
		count += _print_x(arlist, 0);
		break;
	case 'X':
		count += _print_x(arlist, 1);
		break;
	default:
		break;
	}

	return count;
}
/**
 * _print_u - Prints an unsigned integer in decimal representation.
 * @arlist: A va_list containing the unsigned integer to print.
 *
 * This function takes an unsigned integer from a va_list and prints its decimal
 * representation to the standard output.
 *
 * Return: The number of characters printed.
 */
int _print_u(va_list arlist)
{
	unsigned int num = va_arg(arlist, unsigned int);
	int count = 0;

	int divisor = 1;
	while (num / divisor >= 10)
	{
		divisor *= 10;
	}

	while (divisor > 0)
	{
		int digit = (num / divisor) % 10;
		_putchar(digit + '0');
		count++;
		divisor /= 10;
	}

	return count;
}
/**
 * _print_o - Prints an unsigned integer in octal representation.
 * @arlist: A va_list containing the unsigned integer to print.
 *
 * This function takes an unsigned integer from a va_list and prints its octal
 * representation to the standard output.
 *
 * Return: The number of characters printed.
 */

int _print_o(va_list arlist)
{
	unsigned int num = va_arg(arlist, unsigned int);
	int count = 0;
	int i;

	char octalBuffer[12];
	snprintf(octalBuffer, sizeof(octalBuffer), "%o", num);

	for (i = 0; octalBuffer[i] != '\0'; i++)
	{
		_putchar(octalBuffer[i]);
		count++;
	}

	return count;
}

/**
 * _print_x - Prints an unsigned integer in hexadecimal representation.
 * @arlist: A va_list containing the unsigned integer to print.
 * @uppercase: A flag indicating whether to use uppercase letters for hexadecimal (X).
 *
 * This function takes an unsigned integer from a va_list and prints its
 * hexadecimal representation to the standard output. If the `uppercase` flag is
 * set to 1, it prints uppercase letters (X), otherwise, it prints lowercase (x).
 *
 * Return: The number of characters printed.
 */
int _print_x(va_list arlist, int uppercase)
{
	unsigned int num = va_arg(arlist, unsigned int);
	int count = 0;
	int i;

	char hexBuffer[12];
	snprintf(hexBuffer, sizeof(hexBuffer), uppercase ? "%X" : "%x", num);

	for (i = 0; hexBuffer[i] != '\0'; i++)
	{
		_putchar(hexBuffer[i]);
		count++;
	}

	return count;
}


