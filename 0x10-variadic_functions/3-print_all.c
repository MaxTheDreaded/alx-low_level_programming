#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_char - prints a char
 * @ap: list of arguments
 * Return: void
 */
void print_char(va_list ap)
{
printf("%c", va_arg(ap, int));
}

/**
 * print_int - prints an int
 * @ap: list of arguments
 * Return: void
 */
void print_int(va_list ap)
{
printf("%d", va_arg(ap, int));
}

/**
 * print_float - prints a float
 * @ap: list of arguments
 * Return: void
 */
void print_float(va_list ap)
{
printf("%f", va_arg(ap, double));
}

/**
 * print_string - prints a string
 * @ap: list of arguments
 * Return: void
 */
void print_string(va_list ap)
{
char *str;

str = va_arg(ap, char *);
if (str == NULL)
str = "(nil)";
printf("%s", str);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * Return: void
 */
void print_all(const char * const format, ...)
{
va_list ap;
unsigned int i = 0, j;
char *str;

print_t print[] = {
{"c", print_char},
{"i", print_int},
{"f", print_float},
{"s", print_string},
{NULL, NULL}
};

va_start(ap, format);
while (format != NULL && format[i] != '\0')
{
j = 0;
while (print[j].type != NULL)
{
if (format[i] == *(print[j].type))
{
printf("%s", (i > 0) ? ", " : "");
print[j].f(ap);
break;
}
j++;
}
i++;
}
printf("\n");
va_end(ap);
}
