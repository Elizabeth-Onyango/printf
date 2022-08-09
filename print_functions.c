#include "main.h"

/**
 * print_int - prints integer output
 * @i: intege
 *Return: number of characters
 */

int print_int(va_list i)
{
	int p = va_arg(i, int);
	unsigned int length = 0, modulo = 1;
	/*putchar a '-' used for negative numbers*/

	if (p < 0)
	{
		_putchar('-');
		p = p * -1;
		length++;
	}
	/*to printin 1 int at a time */

	while ((p / modulo) >= 10)
	{
		modulo = modulo * 10;
	}
	while (modulo >= 1)
	{
		_putchar((p / modulo) + '0');
		p = p % modulo;
		modulo = modulo / 10;
		length++;
	}
	return (length);
}

/**
 * print_char - prints a character to stdout.
 * @c: chara
 *
 * Return: 1
 */

int print_char(va_list c)
{
	/* protect against null character */
	if (!c)
		exit(1);
	_putchar((char)va_arg(c, int));
	return (1);
}

/**
 * print_string - prints a string of characters
 * @s: string
 *
 * Return: number of char output
 */

int print_string(va_list s)
{
	int length;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (length = 0; str[length]; length++)
	{
		_putchar(str[length]);
	}
	return (length);
}
