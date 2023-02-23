#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the largest prime factor of the number 612852475143
 *
 * Return: Always 0.
 */
int main(void)
{
long int i, n;

n = 612852475143;
for (i = 2; i < n; i++)
{
if (n % i == 0)
{
n = n / i;
i = 1;
}
}
printf("%ld\n", n);
return (0);
}
