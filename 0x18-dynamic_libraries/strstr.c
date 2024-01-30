#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: string to search
 * @needle: substring
 *
 * Return: pointer to the beginning of the located substring
 */
char *_strstr(char *haystack, char *needle)
{
for (; *haystack != '\0'; haystack++)
{
char *i = haystack, *j = needle;
while (*i == *j && *j != '\0')
{
i++;
j++;
}
if (*j == '\0')
return (haystack);
}
return (NULL);
}
