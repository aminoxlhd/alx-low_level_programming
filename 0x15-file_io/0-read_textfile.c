#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile  - reads a text file and prints it to the POSIX
 * @filename: pointer
 * @letters: number of letters
 * Return: if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *content = malloc(letters);
	ssize_t file, readContent, wroteContent;

	if (filename == NULL)
{
	return (0);
}

	file = open(filename, O_RDONLY);

	if (file == -1)
{
	return (-1);
}

	readContent = read(file, content, letters);

	wroteContent = write(STDOUT_FILENO, content, readContent);

	return (wroteContent);
	}
