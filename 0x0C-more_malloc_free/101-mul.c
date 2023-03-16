#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

/**
 * mul - multiplies two positive integers
 * @a: first integer in base 10
 * @b: second integer in base 10
 * Return: product of a and b
 */
int mul(unsigned long long a,unsigned long long b)
{
return (a * b);
}

/**
 * main - multiplies two positive integers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
int a, b;

if (argc != 3)
{
printf("Error\n");
return (1);
}

if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
{
printf("Error\n");
return (98);
}

if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0)
{
printf("Error\n");
return (98);
}

if (atoi(argv[1]) < -2147483648 || atoi(argv[2]) < -2147483648)
{
printf("Error\n");
return (98);
}

a = atoi(argv[1]);
b = atoi(argv[2]);
printf("%d\n", mul(a, b));
return (0);
}

