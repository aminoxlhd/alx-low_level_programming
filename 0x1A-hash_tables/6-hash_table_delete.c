#include "hash_tables.h"

/**
 * hash_table_delete - a function that deletes a hash table.
 * @ht: the hash table.
 **/
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int index = 0;
	hash_node_t *node;

	if (ht == NULL)
		return;

	for (index = 0; index < ht->size; index++)
	{
		while (ht->array[index] != NULL)
		{
			node = ht->array[index]->next;
			free(ht->array[index]->key);
			free(ht->array[index]->value);
			free(ht->array[index]);
			ht->array[index] = node;
		}
	}
}
