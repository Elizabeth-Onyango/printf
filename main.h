#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>

/**
 * struct print - print 
 * @sp: to print to output
 * @f: The print function
 *
 */

typedef struct print
{
	char *sp;
	int (*p)(va_list);
} specifier;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list c);
int print_int(va_list i);
int print_string(va_list s);


#endif
