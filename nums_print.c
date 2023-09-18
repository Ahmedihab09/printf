#include "main.h"

/**
 * nums_print - print  a long int digit by digit
 *
 * @nums: long int to be printed
 * @counter: counter to keep track of the numbers printed
 * Return: count of characters printed
 */
int nums_print(long nums, int counter)
{
	if (nums < 0)
	{
		_putchar('-');
		counter++;
		nums = nums * -1;
	}
	if (nums / 10)
	{
		counter = nums_print(nums / 10, counter);
	}
	_putchar(nums % 10 + '0');
	return (counter + 1);
}
