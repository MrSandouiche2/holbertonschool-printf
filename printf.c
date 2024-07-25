#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...)
{
	int chara_print = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chara_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				chara_print++;
			}
			else if (*format == 'c')
			{
				char c;
				c = (char)va_arg(args, int);
				write(1, &c, 1);
				chara_print++;
			}
			else if (*format == 's')
			{
				char *str;
				int str_len;
				str = va_arg(args, char *);
				if (str == NULL)
				{
					str = "(null)";
				}
				str_len = 0;
				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				chara_print += str_len;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				chara_print += 2;
			}
		}
		format++;
	}

	va_end(args);
	return chara_print;
}
