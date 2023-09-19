#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);

int nums_print(long nums, int counter);
int (*finder(char str))(va_list arlist);
int _print_char(va_list arlist);
int _print_string(va_list arlist);
int _print_percent(void);

int _printf(const char *format, ...);

#endif /* MAIN_H */
