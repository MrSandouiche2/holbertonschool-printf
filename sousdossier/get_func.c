#include "specifiers.h"
#include <unistd.h>
#include <stdio.h>

static const specifier_t specifiers[] = {
	{'c', print_char},
	{'s', print_string},
	{'d', print_int},
	{'i', print_int}};

int (*get_func(char spec))(va_list)
{
	int i;
	for (i = 0; i < sizeof(specifiers) / sizeof(specifiers[0]); i++)
	{
		if (specifiers[i].spec == spec)
		{
			return specifiers[i].func;
		}
	}
	return NULL;
}
