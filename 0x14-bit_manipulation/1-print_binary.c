#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: number to print
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
unsigned long int mask = 1;
int flag = 0;

mask <<= (sizeof(unsigned long int) * 8 - 1);

if (!n)
{
_putchar('0');
return;
}

while (mask)
{
if (n & mask)
flag = 1;

if (flag)
(n & mask) ? _putchar('1') : _putchar('0');

mask >>= 1;
}
}
