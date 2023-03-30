#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to pointer to list_t
 * @str: string to add to new node
 * Return: address of new element or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
list_t *new;
unsigned int i;

new = malloc(sizeof(list_t));
if (new == NULL)
return (NULL);

for (i = 0; str[i] != '\0'; i++)
;

new->str = strdup(str);
new->len = i;
new->next = *head;
*head = new;

return (new);
}
