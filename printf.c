#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int counter = 0, i = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == 'c')
			{
				char c = va_arg(args, int);
				putchar(c);
				counter++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);
				while (*s)
				{
					putchar(*s++);
					counter++;
				}
			}
			else if (format[i] == '%')
			{
				putchar('%');
				counter++;
			}
			else
			{
				putchar('%');
				putchar(format[i]);
				counter += 2;
			}
		}
		else
		{
			putchar(format[i]);
			counter++;
		}
	}

	va_end(args);
	return (counter);
}
