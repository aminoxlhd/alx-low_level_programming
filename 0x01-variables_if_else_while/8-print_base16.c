#include <stdio.h>

/**
 * main - prints all the numbers of base 16 in lowercase,
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)

{
	int i;
	char ab;

	for (i = 48; i < 58; i++)
	{
		putchar(i);
	}
	for (ab = 'a'; ab <= 'f'; ab++)
	{
		putchar(ab);
	}
	putchar('\n');
	return (0);
}
