#include "main.h"

/**
 * _printf - printf clone
 * @format: pointer to character string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int len;
	va_list args;

	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (-1);
			if (*format == 'c')
				len += print_char(args);
			else if (*format == 's')
				len += print_string(args);
			else if (*format == '%')
				len += print_percent();
			else if (*format == 'd' || *format == 'i')
				len += print_int(args);
			else
			{
				_putchar('%');
				_putchar(*format);
				len += 2;
			}
		}
		else
		{
			_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
