#include <stdio.h>

/**
 * main - prints the lowercase alphabet in reverse,
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ab;

	for (ab = 'z'; ab >= 'a'; ab--)
	{
		putchar(ab);
	}
	putchar('\n');
	return (0);
}
