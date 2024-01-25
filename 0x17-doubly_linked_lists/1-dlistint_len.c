#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list
 * @h: head of the list
 *
 * Return: the number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
size_t count = 0;
const dlistint_t *current = h;

while (current != NULL)
{
current = current->next;
count++;
}
return (count);
}
