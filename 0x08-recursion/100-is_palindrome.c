#include "main.h"

/**
 * palindrome_helper - helper function for is_palindrome
 * @s: string to check
 * @len: length of string
 *
 * Return: 1 if s is a palindrome, 0 otherwise
 */
int palindrome_helper(char *s, int len)
{
if (len <= 1)
return (1);
if (*s != *(s + len - 1))
return (0);
return (palindrome_helper(s + 1, len - 2));
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to check
 *
 * Return: 1 if s is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
int len = _strlen_recursion(s);

if (len <= 1)
return (1);
return (palindrome_helper(s, len));
}
