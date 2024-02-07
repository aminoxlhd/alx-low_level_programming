#include "search_algos.h"

/**
 * jump_search - a function that searches for a value in a
 * sorted array of integers using the Jump search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: the first index where value is located
 **/
int jump_search(int *array, size_t size, int value)
{
	int j;
	size_t i;

	if (array == NULL)
		return (-1);

	j = sqrt(size);
	i = 0;
	while (array[i] < value)

	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		i = i + j;
		if (i >= size)
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", i - j, i);
	i = i - j;
	while (array[i] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		++i;
		if (i == size)
			return (-1);
	}
	if (array[i] == value)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		return (i);
	}
	return (-1);
}
