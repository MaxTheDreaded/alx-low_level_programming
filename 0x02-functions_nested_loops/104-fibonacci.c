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
unsigned long int a, b, sum;

a = 1;
b = 2;

printf("%lu", a);

for (i = 0; i < 89; i++)
{
printf(", %lu", b);
sum = a + b;
a = b;
b = sum;
}
return (0);
}
