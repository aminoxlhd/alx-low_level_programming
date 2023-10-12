#include "lists.h"

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *copy_head = *head;

	if (copy_head == NULL)
		return (1);

	if (index == 0)
	{
		*head = copy_head->next;
		free(copy_head);
		return (1);
	}
	while (copy_head)
	{
		if (i == index)
		{
			if (copy_head->prev != NULL)
			{
				copy_head->prev->next = copy_head->next;
			}

			if (copy_head->next != NULL)
			{
				copy_head->next->prev = copy_head->prev;
			}
			else
			{
				copy_head->prev->next = NULL;
			}
			free(copy_head);
			return (1);
		}
		i++;
		copy_head = copy_head->next;
	}
	return (-1);
}
