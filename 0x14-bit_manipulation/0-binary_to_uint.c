#include "main.h"

/**
* binary_to_uint - converts a binary number to an unsigned int
* @b: is pointing to a string of 0 and 1 chars
* Return: the converted number, or 0 if there is one or more
*/

unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int Value = 0;

	if (!b)
		return (0);
	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		value = 2* value + (b[i] - '0');
	}
	return (Value);
}
