#include "main.h"

/**
 *_printf - printf clone
 *@format: pointer to character string
 *Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int len = 0;
	char *s;
	char c;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			c = (*format == 'c') ? (char)va_arg(args, int) : '%';
			s = (*format == 's') ? va_arg(args, char *) : NULL;
			putchar(c);
			len += (c != '%') ? 1 : 0;
			while (s && *s)
			{
				putchar(*s);
				s++;
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
