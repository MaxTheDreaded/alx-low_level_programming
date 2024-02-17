#include "hash_tables.h"

/**
 * key_index - Calculates the index of a key
 * @key: The key to get the index
 * @size: The size of the array
 * Return: The index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
unsigned long int hash = hash_djb2(key);
return (hash % size);
}
