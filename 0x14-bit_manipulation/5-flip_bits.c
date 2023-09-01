#include "main.h"

/**
 * flip_bits - flip to get from one number to another
 * @n: firest number
 * @m: second number
 * Return: the number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int v = n ^ m;

	int numberOfFlipBits = 0;

	while (v > 0)
	{
		numberOfFlipBits++;
		v &= (v - 1);
	}
	return (numberOfFlipBits);
}
