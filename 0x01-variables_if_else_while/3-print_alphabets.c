#include <stdio.h>

/**
 * main - prints the alphabet in lowercase, and then in uppercase,
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	int ab;

	for (ab = 'a'; ab <= 'z'; ab++)
		putchar(ab);
	for (ab = 'A'; ab <= 'Z'; ab++)
		putchar(ab);
	putchar('\n');
	return (0);
}
