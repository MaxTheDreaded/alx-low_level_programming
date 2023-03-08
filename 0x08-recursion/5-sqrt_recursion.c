#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to check
 *
 * Return: natural square root of n
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
if (n == 0)
return (0);
return (sqrt_helper(n, 1));
}
