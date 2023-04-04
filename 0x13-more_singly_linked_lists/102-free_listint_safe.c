#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: double pointer to head of list
 * Return: size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
listint_t *tmp = NULL;
size_t i = 0;

if (!h || !*h)
return (0);

while (*h)
{
tmp = (*h)->next;
free(*h);
*h = tmp;
i++;
}
*h = NULL;
return (i);
}
