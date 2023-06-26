#include "main.h"


/**
 * print_rev - prints a string, in reverse
 * @s: string
 */
void print_rev(char *s)
{
	int a;
	int b;
	int len;

	a = 0;

	while (s[a] != '\0')
	{
		a++;
	}

	len = a;

	for (b = len - 1; b >= 0; b++)
	{
		_putchar(s[b]);
	}
	_putchar('\n');
}
