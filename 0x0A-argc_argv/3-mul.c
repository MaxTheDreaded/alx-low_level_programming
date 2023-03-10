#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the result of the multiplication, followed by a new line.
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
int i, j, k;

if (argc != 3)
{
printf("Error\n");
return (1);
}
i = atoi(argv[1]);
j = atoi(argv[2]);
k = i * j;
printf("%d\n", k);
return (0);
}
