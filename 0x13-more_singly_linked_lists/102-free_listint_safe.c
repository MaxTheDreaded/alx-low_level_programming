#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list, even if it has a loop
 * sets head to NULL
 * @h: double pointer to head of list
 * Return: size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
listint_t *tmp = *h, *tmp2 = *h;
size_t i = 0;

if (!h || !*h)
return (0);

while (tmp && tmp2 && tmp2->next)
{
tmp = tmp->next;
tmp2 = tmp2->next->next;
if (tmp == tmp2)
{
tmp = *h;
while (tmp != tmp2)
{
tmp = tmp->next;
tmp2 = tmp2->next;
}
tmp2 = tmp2->next;
while (tmp2 != tmp)
{
tmp2 = tmp2->next;
i++;
}
i++;
break;
}
}
while (*h)
{
tmp = *h;
*h = (*h)->next;
free(tmp);
}
*h = NULL;
return (i);
}
