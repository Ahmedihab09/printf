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
	count = hex_print(addressBuffer);

	return (count);
}

int _print_S(va_list arlist)
{
	char *str = va_arg(arlist, char *);
	int count = 0;
	int i;

	if (str == NULL)
	{
		str = "(null)";
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
		{
			putchar('\\');
			putchar('x');
			putchar((str[i] >> 4) + '0');
			putchar(((str[i] & 15) > 9 ? 'A' : '0') + (str[i] & 15));
			count += 4;
		}
		else
		{
			putchar(str[i]);
			count++;
		}
	}

	return (count);
}


