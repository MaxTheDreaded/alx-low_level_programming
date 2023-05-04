#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number to get bit from
 * @index: index of bit to get
 *
 * Return: value of bit at index or -1 if error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
unsigned long int mask = 1;

if (index > sizeof(unsigned long int) * 8 - 1)
return (-1);

mask <<= index;

if (n & mask)
return (1);

return (0);
}
