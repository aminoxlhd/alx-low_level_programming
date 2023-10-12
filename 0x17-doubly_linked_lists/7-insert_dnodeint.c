#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer
 * @idx: index
 * @n: data of the node
 * Return: he address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t *copy_head = *h;
	dlistint_t *new = malloc(sizeof(dlistint_t));

	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (*h == NULL)
	{
		(*h) = new;
		return (new);
	}

	if (idx == 0)
	{
		new->next = copy_head;
		copy_head->prev = new;
		return (new);
	}

	while (copy_head)
	{
		i++;
		if (i == idx)
		{
			new->next = (copy_head)->next;
			new->prev = (copy_head);
			(copy_head)->next = new;
			return (new);
		}
		copy_head = copy_head->next;
	}

	return (NULL);
}
