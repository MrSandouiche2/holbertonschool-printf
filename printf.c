#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	va_list args;
	int chara_print = 0;
	char spec;
	char buffer[12];
	int len;

	if (format == NULL)
		return -1;

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

			spec = *format;

			if (spec == '%')
			{
				write(1, format, 1);
				chara_print++;
			}
			else if (spec == 'c')
			{
				char c;
				c = (char)va_arg(args, int);
				write(1, &c, 1);
				chara_print++;
			}
			else if (spec == 's')
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
			else if (spec == 'd' || spec == 'i')
			{
				int num = va_arg(args, int);
				len = sprintf(buffer, "%d", num);
				write(1, buffer, len);
				chara_print += len;
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
	return (chara_print);
}
