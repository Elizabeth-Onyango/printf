#include "main.h"
#include <stdlib.h>

/**
 * specifiercheck - checks if there is a valid format specifier
 * @format: format specifier
 *
 * Return: pointer to valid function or NULL
 */

int (*specifiercheck(const char *format))(va_list)
{
	unsigned int i;
	specifier g[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_int},
		{NULL, NULL}
	};
	/* protect against null format specifier */
	if (!format)
		exit(99);
	for (i = 0; g[i].sp != NULL; i++)
	{
		if (*(g[i].sp) == *format)
		{
			break;

		}
	}
	return (g[i].p);
}

/**
 * _printf - prints in string
 * @format: list of argument types
 *
 * Return: number of characters in string
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0, length = 0;
	va_list ap;
	int (*p)(va_list);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]), length++;
		}
		if (!format[i])
			return (length);
	if (format[i + 1] == '%')
	{
		_putchar('%');
		i += 2,	length = length + 1;
	}
	else if (format[i + 1] == '\0')
	{
		i++;
		continue;
	}
	else
	{
		p = specifiercheck(&format[i + 1]);
	if (p == NULL)
	{
	_putchar(format[i]), _putchar(format[i + 1]);
	i += 2,	length = length + 2;
	}
	else
	{
	length = length + p(ap), i += 2;
	}}}
va_end(ap);
return (length);
}
