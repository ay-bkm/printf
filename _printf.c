#include <stdarg.h>
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character
 * Return: Success: 1, error : -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

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

/**
 * print_percent - prints '%'
 * Return: Number of characters printed
 */
int print_percent(void)
{
	_putchar('%');
	return (1);
}

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
