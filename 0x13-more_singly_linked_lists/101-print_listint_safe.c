#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to head of list
 * Return: number of nodes in the list or exit(98) if loop is detected
 */
size_t print_listint_safe(const listint_t *head)
{
size_t i = 0;
const listint_t *first, *second;

if (!head)
return (0);

while (second && second < second->next)
{
printf("[%p] %d\n", (void *)first, first->n);
i++;
first = first->next;
second = second->next->next;
}

printf("[%p] %d\n", (void *)first, first->n);
i++;

if (second)
{
printf("-> [%p] %d\n", (void *)second, second->n);
exit(98);
}

return (i);
}
