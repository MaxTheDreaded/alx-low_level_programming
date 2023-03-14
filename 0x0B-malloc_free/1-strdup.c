#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory, \
 * which contains a copy of the string given as a parameter
 * @str: string to copy
 *
 * Return: pointer to the duplicated string, or NULL if str = NULL
 */
char *_strdup(char *str)
{
char *dup;
int i, len;

if (str == NULL)
return (NULL);

for (len = 0; str[len]; len++)
;

dup = malloc((len + 1) * sizeof(char));
if (dup == NULL)
return (NULL);

for (i = 0; i < len; i++)
dup[i] = str[i];
dup[i] = '\0';

return (dup);
}
