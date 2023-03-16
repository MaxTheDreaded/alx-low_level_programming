#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "main.h"

/**
 * mul - multiplies two positive integers
 * @a: first integer in base 10
 * @b: second integer in base 10
 * Return: product of a and b
 */
int mul(unsigned long a,unsigned long b)
{
int num;

num = a * b;
return (num);
}

/**
 * main - multiplies two positive integers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
unsigned long a, b;

if (argc != 3)
{
_putchar('E');
_putchar('r');
_putchar('r');
_putchar('o');
_putchar('r');
_putchar('\n');
exit(98);
}

if (argv[1] == NULL || argv[2] == NULL)
{
_putchar('E');
_putchar('r');
_putchar('r');
_putchar('o');
_putchar('r');
_putchar('\n');
exit(98);
}

if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0)
{
_putchar('E');
_putchar('r');
_putchar('r');
_putchar('o');
_putchar('r');
_putchar('\n');
exit(98);
}

if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
{
_putchar('0');
exit(0);
}

a = strtoull(argv[1], NULL, 10);
b = strtoull(argv[2], NULL, 10);
mul(a, b);
_putchar('0' + mul(a, b));
_putchar('\n');
return (0);
}
