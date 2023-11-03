#include "hash_tables.h"

/**
 * hash_table_set - function that adds an element to the hash table.
 * @ht : the hash table.
 * @key : the key.
 * @value : the value we want to add.
 * Return: 1 if succeeded, 0 otherwise
 **/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *temp_node, *new_node;
	unsigned long int index;

	if (ht == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp_node = ht->array[index];

	while (temp_node != NULL)
	{
		if (strcmp(temp_node->key, key) == 0)
		{
			if (strcmp(temp_node->value, value) != 0)
			{
				free(temp_node->value);
				temp_node->value = strdup(value);
				if (temp_node->value == NULL)
					return (0);
			}
			return (1);
		}
		temp_node = temp_node->next;
	}
	new_node = malloc(sizeof(hash_node_t *));

	new_node->key = strdup(key);
	new_node->value = strdup(value);

	if (new_node == NULL)
		return (0);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
