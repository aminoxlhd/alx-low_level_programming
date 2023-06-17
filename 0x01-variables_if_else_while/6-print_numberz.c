#include <stdio.h>

/**
 * main - prints all single digit numbers of base 10 starting from 0,
 * followed by a new line, using putchar
 * Return: Always 0 (Success)
 */
int main(void)
{
	int ab;

	for (ab = 0; ab < 10; ab++)
	{
		putchar(ab);
	}
	putchar('\n');
	return (0);
}
