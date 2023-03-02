#include "main.h"

/**
 * print_buffer - prints a buffer
 * @b: buffer to print
 * @size: size of the buffer
 */
void print_buffer(char *b, int size)
{
int i, j, k, l = 0;

if (size <= 0)
printf("\n");
else
{
while (i < size)
{
printf("%08x: ", i);
j = 0;
while (j < 10)
{
if (i + j < size)
printf("%02x", b[i + j]);
else
printf("  ");
if (j % 2 != 0)
printf(" ");
j++;
}
printf("; ");
k = 0;
while (k < 10)
{
if (i + k < size)
{
l = b[i + k];
if (l >= 32 && l <= 126)
printf("%c", l);
else
printf(".");
}
else
printf(" ");
k++;
}
printf("\n");
i += 10;
}
}
}
