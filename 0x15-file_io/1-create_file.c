#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/**
 * create_file - creates a file
 * @filename: is the name of the file to create
 * @text_content: is a NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure (file can not be created)
 */
int create_file(const char *filename, char *text_content)
{
	int f_description, w_result, lenght = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
	for (lenght = 0; text_content[lenght])
		{
			lenght++;
		}
	}

	f_description = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w_result = write(f_description, text_content, lenght);

	if (f_description == -1 || w_result == -1)
		return (-1);
	close(f_description);

	return (1);
}
