#include <stdio.h>

/**
 * main - prints the alphabet in lowercase,
 * followed by a new line, except q and e
 * Return: Aways 0 (Sucess)
 */
int main(void)
{
	char ab = 'a';

	while (ab <= 'z')
	{
		if (ab != 'e' && ab != 'q')
		{
			putchar(ab);
		}
		ab++;
	}
	putchar('\n');
	return (0);
}
