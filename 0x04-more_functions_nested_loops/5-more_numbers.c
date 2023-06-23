#include "main.h"

/**
 * more_numbers - prints numbers between 0 to 14
 * 10 times.
 * Return: no return.
 */
void more_numbers(void)
{
	int a;
	int ab;

	for (a = 0; a < 10; a++)
	{
		for (ab = 0; ab < 15; ab++)
		{
			if (ab >= 10)
				_putchar((ab / 10) + 48);
		}
		_putchar('\n');
	}
}
