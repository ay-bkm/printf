#include "main.h"

/**
 * print_i - prints integers with different bases
 * @args: argument list
 * Return: The length of printed integers
 */
int print_i(va_list args)
{
	int n, len;
	char buffer[11];

	n = va_arg(args, int);
	if (n < 0)
	{
		_putchar('-');
		len = 1;
		n = -n;
	}
	else
		len = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	len += itoa(n, buffer, 10);
	return (len);
}
