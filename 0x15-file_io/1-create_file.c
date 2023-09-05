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
	ssize_t file, wroteContent;

	if (filename == NULL)
	{
		return (-1);
	}

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (file == -1)
	{
		return (-1);
	}

	wroteContent = write(file, text_content, strlen(text_content));

	if (wroteContent == -1)
	{
		return (-1);
	}
	return (1);
}
