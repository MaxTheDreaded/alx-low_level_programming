#include "main.h"

/**
* print_last_digit - print the last digit of a number
* @n: number to check
* Return: last digit of n
*/
int print_last_digit(int n)
{
int last_digit;

if (n < 0)
{
last_digit = last_digit * -1;
}
last_digit = n % 10;
_putchar('0' + last_digit);
return (last_digit);
}
