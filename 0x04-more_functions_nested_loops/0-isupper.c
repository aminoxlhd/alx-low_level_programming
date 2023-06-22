#include "main.h"

/**
 * int _isupper - for uppercase character
 * Returns 1 if c is uppercase
 * Returns 0 otherwise
 */
int _isupper(int c)
{
	if ( c >= 'A' && c <= 'Z')
		return (1);

	else
		return (0);
}
