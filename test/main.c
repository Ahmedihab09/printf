#include "main.h"

int main(void)
{
	int num = 12345;

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

	printf("Printf with %%d: %d\n", num);
	_printf("_printf with %%d: %d\n", num);


	return (0);


}
