#include "main.h"

/**
 *_printf - printf clone
 *@format: pointer to character string
 *Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int len;
	char *s;
	char c;

	len = 0;

	va_list args;

	va_start(args, format);
	while (*format)
	{
	if (*format == '%')
	{
	format++;
	if (*format == 'c')
	{
	c = (char)va_arg(args, int);
	putchar(c);
	len++;
	}
	else if (*format == 's')
	{
	s = va_arg(args, char *);
	while (*s)
	{
	putchar(*s);
	s++;
	len++;
	}
	}
	else if (*format == '%')
	{
	putchar('%');
	len++;
	}
	}
	else
	{
	putchar(*format);
	len++;
	}
	format++;
	}
	va_end(args);
	return (len);
}
