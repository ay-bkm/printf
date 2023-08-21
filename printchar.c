#include "main.h"
/**
 * print_char - prints a Char
 * @args: argument list
 * Return: Number of printed characters
 */
int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	_putchar(c);
	return (1);
}
