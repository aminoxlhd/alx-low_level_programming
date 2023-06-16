#include <stdio.h>

/**
 * main - prints the alphabet in lowercase,
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ab;
	for (ab = 'a'; ab <= 'z'; ab++)
	{
		putchar(ab);
	}
		putchar('\n');
	return (0);
}
