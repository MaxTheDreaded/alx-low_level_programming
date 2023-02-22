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
unsigned long int a, b, sum, a1, a2, b1, b2;

a = 1;
b = 2;

printf("%lu, %lu, ", a, b);
for (i = 1; i < 91; i++)
{
sum = a + b;
printf("%lu, ", sum);
a = b;
b = sum;
}
a1 = a / 10000000000;
a2 = a % 10000000000;
b1 = b / 10000000000;
b2 = b % 10000000000;
for (i = 92; i < 98; i++)
{
b1 = a1 + b1;
b2 = a2 + b2;
a1 = b1 - a1;
a2 = b2 - a2;
printf("%lu", b1 + (b2 / 10000000000));
printf("%lu", b2 % 10000000000);
if (i != 97)
{
printf(", ");
}
}
printf("\n");
return (0);
}
