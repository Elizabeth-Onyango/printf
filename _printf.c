#include "main.h"

/**
 * _printf - printf function
 * @format: - format
 *
 * Return: output to stdio
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int output;

	va_start(arg, format);
	output = vfprintf(stdout, format, arg);
	va_end(arg);

	return (output);
}
