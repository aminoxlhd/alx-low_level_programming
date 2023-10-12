#include "lists.h"

/**
 * add_dnodeint_end -  dds a new node at the end of a dlistint_t list
 * @head: double pointer
 * @n: integer
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *copy_head = *head;

	if (*head == NULL)
	{
		new = malloc(sizeof(dlistint_t));
		new->n = n;
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (new);
	}

	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
	{
		return (NULL);
	}

	while (copy_head->next)
		copy_head = copy_head->next;

	new->n = n;
	new->next = NULL;
	copy_head->next = new;

	return (new);
}
