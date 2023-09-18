#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: The char to print
 * Return: 1 (success), -1 (error)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
