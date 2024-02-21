#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table
 * Return: Nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *temp;
	int first_pair = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp != NULL)
		{
			if (!first_pair)
			{
				printf(", ");
			}
			else
			{
				first_pair = 0;
			}
			printf("'%s': '%s'", temp->key, temp->value);
			temp = temp->next;
		}
	}
	printf("}\n");
}
