#include "main.h"
/**
 * printf_char -prints char
 * @val: arguments 
 * Return: return 1
 */
{
	int printf-char(va_list val)
		char str;
	str = va_arg(val, int);
	_putchar(str);
	return(1);
}
