#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to head of list
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
size_t i = 0;
const listint_t *tmp = head;

if (!head)
return (98);

while (tmp)
{
printf("[%p] %d\n", (void *)tmp, tmp->n);
tmp = tmp->next;
i++;
}
return (i);
}
