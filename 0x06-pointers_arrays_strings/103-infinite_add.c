#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer that the function will use to store the result
 * @size_r: buffer size
 * Return: pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int i, j, k, l, m, n, o, p, q, carry;

i = j = k = l = m = n = o = p = q = carry = 0;
while (n1[i] != '\0')
i++;
while (n2[j] != '\0')
j++;
if (i > size_r || j > size_r)
return (0);
i--;
j--;
while (i >= 0 || j >= 0)
{
k = (i >= 0) ? n1[i] - '0' : 0;
l = (j >= 0) ? n2[j] - '0' : 0;
m = k + l + carry;
n = m % 10;
o = m / 10;
r[p] = n + '0';
carry = o;
p++;
i--;
j--;
}
if (carry > 0)
{
if (p >= size_r)
return (0);
r[p] = carry + '0';
p++;
}
r[p] = '\0';
for (q = 0; q < p / 2; q++)
{
k = r[q];
r[q] = r[p - q - 1];
r[p - q - 1] = k;
}
return (r);
}
