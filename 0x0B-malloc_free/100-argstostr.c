#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * argstostr - concatenates all the arguments of your program
 * @ac: argument count
 * @av: argument vector
 * Return: pointer to new string
 */
char *argstostr(int ac, char **av)
{
char *s;
int i, j, k, l;

if (ac == 0 || av == NULL)
return (NULL);

for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j] != '\0'; j++)
;
}

s = malloc(sizeof(char) * (i + j + 1));
if (s == NULL)
return (NULL);

for (k = 0; k < i; k++)
s[k] = av[k];
for (l = 0; l < j; l++)
s[k + l] = av[l];
s[k + l] = '\0';

return (s);
}
