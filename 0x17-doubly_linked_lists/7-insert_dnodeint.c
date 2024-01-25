#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: head of the list
 * @idx: index of the list where the new node should be added
 * @n: value of the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new;
dlistint_t *current = *h;
unsigned int i = 0;

if (idx == 0)
return (add_dnodeint(h, n));
while (current != NULL && i < idx - 1)
{
current = current->next;
i++;
}
if (current == NULL)
return (NULL);
new = malloc(sizeof(dlistint_t));
if (new == NULL)
return (NULL);
new->n = n;
new->next = current->next;
new->prev = current;
if (current->next != NULL)
current->next->prev = new;
current->next = new;
return (new);
}
