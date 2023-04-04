#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to head of list
 * Return: address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *tmp = head, *tmp2 = head;

if (!head)
return (NULL);

while (tmp && tmp2 && tmp2->next)
{
tmp = tmp->next;
tmp2 = tmp2->next->next;
if (tmp == tmp2)
{
tmp = head;
while (tmp != tmp2)
{
tmp = tmp->next;
tmp2 = tmp2->next;
}
return (tmp);
}
}
return (NULL);
}
