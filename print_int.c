#include "main.h"
/**
* print_int - prints integers
* @args: argument list
* Return: The length of printed integers
*/
int print_int(va_list args)
{
	int n, pval, len;
	unsigned int absn;

	n = va_arg(args, int);
	pval = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		absn = n * -1;
	}
	else
		absn = n;

	while (absn / pval > 9)
		pval *= 10;

	while (pval != 0)
	{
		len += _putchar('0' + absn / pval);
		absn %= pval;
		pval /= 10;
	}

	return (len);
}
