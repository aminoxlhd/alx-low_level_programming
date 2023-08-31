#include "main.h"

/**
* binary_to_uint - converts a binary number to an unsigned int
* @b: is pointing to a string of 0 and 1 chars
* Return: the converted number, or 0 if there is one or more
*/

unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int returnValue = 0;

	while (b[i] != '\0')
	{
		if (b[i] != '0' && b[i] != '1')
		{
			return (0);
		}

	returnValue =  returnValue << 1;
	returnValue = returnValue + b[i] - '0';
	i++;
	}
	return (returnValue);
}
