#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 * Return: If an error occurs - NULL.
 * Otherwise - a pointer to the new sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht;
unsigned long int i;

ht = malloc(sizeof(shash_table_t));
if (ht == NULL)
return (NULL);
ht->size = size;
ht->array = malloc(sizeof(shash_node_t *) * size);
if (ht->array == NULL)
return (NULL);
for (i = 0; i < size; i++)
ht->array[i] = NULL;
ht->shead = NULL;
ht->stail = NULL;
return (ht);
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @table: The sorted hash table
 * @key: The key
 * @value: The value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *table, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node;

	if (table == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, table->size);
	new_node = create_new_node(key, value);

	if (new_node == NULL)
		return (0);

	insert_node_at_i(table, new_node, index);
	update_sorted_list(table, new_node);
	return (1);
}

/**
 * create_new_node - Creates a new node
 * @key: The key
 * @value: The value
 * Return: The new node
 */
shash_node_t *create_new_node(const char *key, const char *value)
{
	shash_node_t *new_node = malloc(sizeof(shash_node_t));

	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	new_node->sprev = NULL;
	new_node->snext = NULL;
	return (new_node);
}

/**
 * insert_node_at_i - Inserts a new node at a given index
 * @t: The sorted hash table
 * @n: The new node
 * @i: The index
 */
void insert_node_at_i(shash_table_t *t, shash_node_t *n, unsigned long int i)
{
	n->next = t->array[i];
	if (t->array[i] != NULL)
		t->array[i]->sprev = n;

	t->array[i] = n;
}

/**
 * update_sorted_list - Updates the sorted list
 * @table: The sorted hash table
 * @new_node: The new node
 */
void update_sorted_list(shash_table_t *table, shash_node_t *new_node)
{
	if (table->shead == NULL)
	{
		table->shead = new_node;
		table->stail = new_node;
	}
	else
	{
		table->stail->snext = new_node;
		new_node->sprev = table->stail;
		table->stail = new_node;
	}
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: The sorted hash table
 * @key: The key
 * Return: If the key cannot be found - NULL
 * Otherwise - the value associated with the element
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
shash_node_t *temp;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);

index = key_index((const unsigned char *)key, ht->size);
temp = ht->array[index];
while (temp != NULL)
{
if (strcmp(temp->key, key) == 0)
return (temp->value);
temp = temp->next;
}
return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: The sorted hash table
 * Return: Nothing
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *temp;
unsigned long int i;

if (ht == NULL)
return;

printf("{");
for (i = 0; i < ht->size; i++)
{
temp = ht->array[i];
while (temp != NULL)
{
printf("'%s': '%s'", temp->key, temp->value);
temp = temp->next;
if (temp != NULL)
printf(", ");
}
}
printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse
 * @ht: The sorted hash table
 * Return: Nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *temp;
unsigned long int i;

if (ht == NULL)
return;

printf("{");
for (i = 0; i < ht->size; i++)
{
temp = ht->array[i];
while (temp != NULL)
{
printf("'%s': '%s'", temp->key, temp->value);
temp = temp->next;
if (temp != NULL)
printf(", ");
}
}
printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table
 * Return: Nothing
 */
void shash_table_delete(shash_table_t *ht)
{
shash_node_t *temp;

if (ht == NULL)
return;

while (ht->shead != NULL)
{
temp = ht->shead;
ht->shead = ht->shead->snext;
if (ht->shead != NULL)
ht->shead->sprev = NULL;
free(temp->key);
free(temp->value);
free(temp);
}
free(ht->array);
free(ht);
}
