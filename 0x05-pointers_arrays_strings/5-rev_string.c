#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to a string
 * Return: void
 */
void rev_string(char *s)
{
int i = 0, j = 0;
char temp;

while (s[i] != '\0')
{
i++;
}
i--;
while (i > j)
{
temp = s[i];
s[i] = s[j];
s[j] = temp;
i--;
j++;
}
}
