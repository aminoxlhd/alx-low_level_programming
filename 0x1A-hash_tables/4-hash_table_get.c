#include "hash_tables.h"

/**
 * hash_table_get - a function that retrieves a value associated with a key.
 * @ht: the hash table.
 * @key: the key.
 * Return: the value associated with the element, otherwise NULL.
 **/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	if (ht == NULL)
		return (NULL);

	if (key == NULL)
		return (NULL);

	index = key_index((const unsigned char *) key, ht->size);
			node = ht->array[index];

			while (node != NULL)
			{
				if (strcmp(key, node->key) == 0)
					return (node->value);
				node = node->next;
			}

			return (NULL);
}
