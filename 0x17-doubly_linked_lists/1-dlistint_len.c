#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *  dlistint_len -  returns the number of elements in a linked dlistint_t list
 *  @h: the list we want to count
 *  Return: the size of the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
	}

	return (count);
}
