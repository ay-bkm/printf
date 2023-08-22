#include "main.h"
/**
 * print_int - prints integers with different bases
 * @args: argument list
 * Return: The length of printed integers
 */
int print_int(va_list args)
{
	int n, len, i;
	char buffer[11];

	n = va_arg(args, int);
	if (n == INT_MIN)
	{
		/* Handle the case where n is INT_MIN */
		len = _putchar('-');
		len += _putchar('2');
		n = 147483648;
	}
	else if (n < 0)
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

	sprintf(buffer, "%d", n);
	for (i = 0; buffer[i]; i++)
		len += _putchar(buffer[i]);
	return (len);
}
