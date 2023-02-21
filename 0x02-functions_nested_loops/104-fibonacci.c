#include <stdlib.h>
#include <stdio.h>

/**
* main - prints the first 98 Fibonacci numbers, starting with 1 and 2\
, followed by a new line
*
* Return: 0
*/
int main(void)
{
int i;
long int a, b, c;

a = 1;
b = 2;
printf("%ld, %ld, ", a, b);
for (i = 0; i < 95; i++)
{
c = a + b;
a = b;
b = c;
printf("%ld", c);
if (i < 94)
printf(", ");
}
printf("\n");
return (0);
}
