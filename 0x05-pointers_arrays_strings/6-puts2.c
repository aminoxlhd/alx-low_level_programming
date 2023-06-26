#include "main.h"


/**
 * puts2 -  every other character of a string
 * @str : print string
 */
void puts2(char *str)
{
	int len;
	int a;

	len = 0;

	while (str[len] != '\0')
	{
		len++
	}

	for (a = 0; a < len; a += 2)
	{
		_putchar(str[a]);
	}
	_putchar('\n');
}
