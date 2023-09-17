#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - a function that produces output according to a format
 * @format: character string composed of zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *traverse;

	va_start(args, format);
	for (traverse = (char *)format; *traverse != '\0'; traverse++)
	{
	while (*traverse != '%' && *traverse != '\0')
	{
		putchar(*traverse);
		traverse++;
		count++;
	}
	if (*traverse == '\0')
		break;
	traverse++; /* skip the '%' */
	switch (*traverse)
	{
		case 'c':
			putchar(va_arg(args, int));
			count++;
			break;
		case 's':
			for (char *temp = va_arg(args, char*); *temp != '\0'; temp++)
			{
				putchar(*temp);
				count++;
			}
			break;
		case '%':
			putchar('%');
			count++;
			break;
		default:
			break;
	}
	}
	va_end(args);
	return (count);
}
