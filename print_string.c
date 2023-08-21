#include "main.h"
/**
 * print_string - prints string
 * @args: argument list
 * Return: Number of printed characters
 */
int print_string(va_list args)
{
	va_list args;
	int len;
	char *s;

	len = 0;
	s = va_arg(args, char *);

	if (!s)
		s = "(null)";
	while (*s)
	{
		_putchar(*s);
		s++;
		len++;
	}
	return (len);
}
