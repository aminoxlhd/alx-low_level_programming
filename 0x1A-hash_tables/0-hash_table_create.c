#include "hash_tables.h"

/**
 * hash_table_create - function that creates a hash table
 * @size: the size of the hashtable.
 * Return: Returns a pointer to the newly created hash table
 **/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	ht = malloc(sizeof(hash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->array = malloc(sizeof(hash_table_t *) * size);

	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	ht->size = size;

	return (ht);
}
