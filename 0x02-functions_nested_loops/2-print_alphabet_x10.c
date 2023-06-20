#include "main.h"


/**
 *print_alphabet_x10 -  prints 10 times the alphabet, in lowercase,
 * followed by a new line.
 */
void print_alphabet_x10(void)
{
	char ab;
	int a;

	a = 0;

	while (a < 10)
	{
		ab = 'a';
		while (ab <= 'z')
		{
			_putchar(ab);
			ab++;
		}
		_putchar('\n');
		a++;
	}
}
