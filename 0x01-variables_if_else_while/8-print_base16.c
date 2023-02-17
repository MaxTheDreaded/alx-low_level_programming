#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* main - prints all the numbers of base 16 in lowercase
* followed by a new line
* Return: Always 0 (Success)
*/
int main(void)
{
int i;
char c;
for (i = 0; i < 10; i++)
{
putchar(i + '0');
}
for (c = 'a'; c <= 'f'; c++)
{
putchar(c);
}
putchar('\n');
return (0);
}
