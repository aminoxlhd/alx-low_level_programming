#include "hash_tables.h"

/**
 * hash_table_print - a function that prints a hash table.
 * @ht : the hash table.
 **/
void hash_table_print(const hash_table_t *ht)
{
	unsigned int i, comma = 0;
	hash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			if (comma == 1)
			{
				printf(",");
				comma = 0;
			}
			printf(" '%s': '%s'", node->key, node->value);
				node = node->next;
		}
	}
	printf("}\n");
}
