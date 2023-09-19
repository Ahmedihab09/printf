#include "main.h"

int main(void)
{
	printf("printing for printf\n");
	printf("peter\n");
	printf("%c\n", 'v');
	printf("%s\n", "string");
	printf("%%\n");
	
	printf("printing for _prinf\n");
	_printf("peter\n");
	_printf("%c\n", 'v');
	_printf("%s\n", "string");
	_printf("%%\n");
	return (0);
}
