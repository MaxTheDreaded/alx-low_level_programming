#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins to make change for an amount of
 * money.
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
int i, j, k, l, m, n, o, p, q, r, t;

if (argc != 2)
{
printf("Error\n");
return (1);
}
i = atoi(argv[1]);
j = i / 25;
k = i % 25;
l = k / 10;
m = k % 10;
n = m / 5;
o = m % 5;
p = o / 2;
q = o % 2;
r = q / 1;
t = j + l + n + p + r;
printf("%d\n", t);
return (0);
}
