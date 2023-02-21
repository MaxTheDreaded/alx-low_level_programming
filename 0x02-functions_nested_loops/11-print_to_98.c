#include "main.h"

/**
* print_to_98 - prints all natural numbers from n to 98
* @n: starting number
*
* Return: void
*/
void print_to_98(int n)
{
if (n < 98)
{
for (; n < 98; n++)
{
_putchar('n');
}
}
else
{
_putchar('n');
for (; n > 98; n--)
{
_putchar('n');
}
}
_putchar('9');
_putchar('8');
_putchar('\n');
}
