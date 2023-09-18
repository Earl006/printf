#include "main.h"

/**
 * is_printable - Evaluates whether a char is printable
 * @c: The Char to be evaluated
 *
 * Return: 1 if c is printable, 0 if c is not printable
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Appends ascci in hexadecimal code to buffer
 * @buffer: Array of chars
 * @a: Index where to start appending
 * @ascii_code: ASSCI CODE
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int a)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[a++] = '\\';
	buffer[a++] = 'x';

	buffer[a++] = map_to[ascii_code / 16];
	buffer[a] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies whether a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 if not
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to specified size
 * @num: Number to be casted
 * @size: Number indicating type to be casted
 *
 * Return: The casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: The casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
