#include <stdlib.h>
#include <stdio.h>

/**
* main - prints the first 98 Fibonacci numbers, starting with 1 and 2, \
followed by a new line
*
* Return: 0
*/
int main(void)
{
int i;
unsigned long long int a, b, c;

a = 1;
b = 2;
printf("%llu, %llu, ", a, b);
for (i = 0; i < 96; i++)
{
c = a + b;
a = b;
b = c;
printf("%llu", c);
if (i < 95)
printf(", ");
}
printf("\n");
return (0);
}
