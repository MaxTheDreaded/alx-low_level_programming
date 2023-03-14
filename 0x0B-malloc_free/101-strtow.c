#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * strtow - splits a string into words
 * @str: string to split
 * Return: pointer to array of strings
 */
char **strtow(char *str)
{
char **s;
int i, j, k, l, m, n;

if (str == NULL || str[0] == '\0')
return (NULL);

for (i = 0; str[i] != '\0'; i++)
;
s = malloc(sizeof(char *) * (i + 1));
if (s == NULL)
return (NULL);

for (j = 0, k = 0; j < i; j++)
{
if (str[j] != ' ')
{
for (l = j; str[l] != ' ' && str[l] != '\0'; l++)
;
s[k] = malloc(sizeof(char) * (l - j + 1));
if (s[k] == NULL)
{
for (m = 0; m < k; m++)
free(s[m]);
free(s);
return (NULL);
}
for (n = 0; j < l; j++, n++)
s[k][n] = str[j];
s[k][n] = '\0';
k++;
}
}
s[k] = NULL;

return (s);
}
