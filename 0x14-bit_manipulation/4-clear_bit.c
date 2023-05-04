#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: number to clear bit in
 * @index: index of bit to clear
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
unsigned long int mask = 1;

if (index > sizeof(unsigned long int) * 8 - 1)
return (-1);

mask <<= index;
*n &= ~mask;

return (1);
}
