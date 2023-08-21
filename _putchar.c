#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character
 * Return: Success: 1, error : -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
