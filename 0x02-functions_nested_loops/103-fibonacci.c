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
long int a, b, c, sum;

a = 0;
b = 1;
c = 0;
sum = 0;
while (c < 4000000)
{
c = a + b;
if (c % 2 == 0)
{
sum += c;
}
a = b;
b = c;
}
printf("%ld\n", sum);
return (0);
}
