#include <stdio.h>
#include "main.h"

int main(void)
{
	int len;

	printf("Character specifier test:\n");
	len = _printf("Character: %c\n", 'A');
	printf("Custom _printf length: %d\n", len);
	printf("Expected output: Character: A\n\n");

	printf("String specifier test:\n");
	len = _printf("String: %s\n", "Hello, world!");
	printf("Custom _printf length: %d\n", len);
	printf("Expected output: String: Hello, world!\n\n");

	printf("Integer specifier test:\n");
	len = _printf("Integer (positive): %d\n", 12345);
	printf("Custom _printf length: %d\n", len);
	printf("Expected output: Integer (positive): 12345\n\n");

	len = _printf("Integer (negative): %i\n", -6789);
	printf("Custom _printf length: %d\n", len);
	printf("Expected output: Integer (negative): -6789\n\n");

	printf("Percentage specifier test:\n");
	len = _printf("Percentage: %%\n");
	printf("Custom _printf length: %d\n", len);
	printf("Expected output: Percentage: %%\n\n");

	printf("NULL format string test:\n");
	len = _printf(NULL);
	printf("Custom _printf length: %d\n", len);
	printf("Expected output: (No output, should return -1)\n\n");

	return (0);
}

