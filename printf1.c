#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Helper function to write a single character to stdout
 * @c: The character to write
 *
 * Return: The number of characters written (1 or 0 on error)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_char - Handle the %c conversion specifier
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
int _print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * _print_string - Handle the %s conversion specifier
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
int _print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	while (*str)
	{
		if (_putchar(*str) == -1)
			return (-1);
		count++;
		str++;
	}
	return (count);
}

/**
 * _print_integer - Handle the %d and %i conversion specifiers
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
int _print_integer(va_list args)
{
	int num = va_arg(args, int);
	int num_digits = 1;
	int temp = num;
	int i;
	char buffer[12];
	int count = 0;

	if (num < 0)
	{
		if (_putchar('-') == -1)
			return (-1);
		count++;
		num = -num;
	}
	while (temp /= 10)
		num_digits++;
	snprintf(buffer, sizeof(buffer), "%d", num);

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (_putchar(buffer[i]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

/**
 * _printf - Custom implementation foor the printf function
 * @format: Character string composed of zero
 * or more format directives (Handling specific conversion specifiers)
 *
 * Return: The number of characters successfully printed
 * (Excluding null characters)
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
			if (_putchar(*traverse) == -1)
				return (-1);
			traverse++;
			count++;
		}
		if (*traverse == '\0')
			break;
		traverse++;
		switch (*traverse)
		{
			case 'c':
				count += _print_char(args);
				break;
			case 's':
				count += _print_char(args);
				break;
			case 'd':
			case 'i':
				count += _print_integer(args);
					break;
			case '%':
					if (_putchar('%') == -1)
						return (-1);
					count++;
					break;
			default:
				break;
		}
	}
	va_end(args);
	return (count);
}
