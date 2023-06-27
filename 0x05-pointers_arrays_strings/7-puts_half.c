#include "main.h"


/**
 * puts_half - half of a string
 * @str: string
 */
void puts_half(char *str)
{
	int len;
	int n;
	int a;

	len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	if (len % 2 == 0)
	{
		for (a = len / 2; str[a] != '\0'; a++)
		{
			_putchar(str[a]);
		}
	}
		else if (len % 2)
		{
			for (n = (len - 1) / 2; n < len - 1;a++)
			{
				_putchar(str[n +1]);
			}
		}
		_putchar('\n');
}
