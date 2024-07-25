#ifndef SPECIFIERS_H
#define SPECIFIERS_H

#include <stdarg.h>

typedef struct specifier
{
	char spec;
	int (*func)(va_list);
} specifier_t;

int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int(*get_func(char spec))(va_list)

#endif
