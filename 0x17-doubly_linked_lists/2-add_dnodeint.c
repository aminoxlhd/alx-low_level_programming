#include "lists.h"

/**
 * add_dnodeint -  adds a new node at the beginning
 * @head: double pointer
 * @n: data to be added
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (head == NULL)
	{
		return (NULL);
	}
	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (new);
}
