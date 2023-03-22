#include "3-calc.h"

/**
 * main - performs simple operations
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
int a, b, result;
int (*f)(int, int);

if (argc != 4)
{
printf("Error\n");
exit(98);
}

if (argv[2][1] != '\0')
{
printf("Error\n");
exit(99);
}

if (get_op_func(argv[2]) == NULL)
{
printf("Error\n");
exit(99);
}

if ((argv[2][0] == '/' || argv[2][0] == '%') && atoi(argv[3]) == 0)
{
printf("Error\n");
exit(100);
}

a = atoi(argv[1]);
b = atoi(argv[3]);
f = get_op_func(argv[2]);
result = f(a, b);
printf("%d\n", result);
return (0);
}
