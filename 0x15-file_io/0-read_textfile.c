#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile  - reads a text file and prints it to the POSIX
 * @filename: pointer
 * @letters: number of letters
 * Return: if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t f_descriptor, b_read, b_written;

	f_descriptor = open(filename, O_RDONLY);

	if (f_descriptor == -1)
{
	return (0);
}

	buff = malloc(sizeof(char) * letters);

	if (buff == NULL)
{
	close(f_descriptor);
	return (0);
}

	b_read = read(f_descriptor, buff, letters);

	b_written = write(STDOUT_FILENO, buff, b_read);

	free(buff);
	close(f_descriptor);
	return (b_written);
	}
