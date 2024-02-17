#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table
 * @key: The key
 * Return: If the key cannot be found - NULL
 * Otherwise - the value associated with the element
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
hash_node_t *temp;
unsigned long int index;
char *value;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);

index = key_index((const unsigned char *)key, ht->size);
temp = ht->array[index];

while (temp != NULL)
{
if (strcmp(temp->key, key) == 0)
{
value = temp->value;
return (value);
}
temp = temp->next;
}
return (NULL);
}
