#include "function_pointers.h"
#include "3-calc.h"

/**
 * main_opcodes - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
int i, bytes;
char *p;

if (argc != 2)
{
printf("Error\n");
exit(1);
}
bytes = atoi(argv[1]);
if (bytes < 0)
{
printf("Error\n");
exit(2);
}
p = (char *)main;
for (i = 0; i < bytes; i++)
{
printf("%02hhx", p[i]);
if (i < bytes - 1)
printf(" ");
}
printf("\n");
return (0);
}
