#include <stdlib.h>
#include <stdio.h>

/**
* main - finds and prints the sum of the even-valued \
terms of the Fibonacci sequence, which do not exceed \
4,000,000, followed by a new line
*
* Return: 0
*/
int main(void)
{
int i;
long int a, b, c, sum;

a = 1;
b = 2;
sum = 0;
for (i = 0; i < 32; i++)
{
c = a + b;
a = b;
b = c;
if (c % 2 == 0)
sum += c;
}
printf("%ld\n", sum);
return (0);
}
