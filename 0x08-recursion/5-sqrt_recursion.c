#include "main.h"

/**
 * sqrt_helper - helper function for _sqrt_recursion
 * @n: number to check
 * @i: number to check
 *
 * Return: natural square root of n
 */
int sqrt_helper(int n, int i)
{
if (i * i == n)
return (i);
if (i * i > n)
return (-1);
return (sqrt_helper(n, i + 1));
}

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
