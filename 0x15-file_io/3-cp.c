#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"
#include <unistd.h>

/**
 * Usage: cp file_from file_to
 * @argc: number of arguments
 * Return: void
 */
int copy_files_content(const char *file_from, char *file_to);

int main(int ac, char **av)
{
	int res;

	if (ac != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", av[0]);
		exit(97);
	}

	res = copy_files_content(av[1], av[2]);
	exit(res);
}

int copy_files_content(const char *file_from, char *file_to)
{
	char *content = malloc(1024);
	int close_file_return;
	ssize_t file_from_file, file_to_file, readContent, wroteContent;

	mode_t permission;

	if (file_from == NULL)
	{
		dprintf(2, "can't write to file\n");
		return (99);
	}

	file_from_file = open(file_from, O_RDONLY);
	permission = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	file_to_file = open(file_to, O_WRONLY | O_APPEND | O_CREAT, permission);

	if (file_from_file == 1)
	{
		dprintf(2, "Error: Can't read from file %s\n", file_from);
		return (98);
	}

	if (file_to_file == -1)
	{
		dprintf(2, "Can't write to %s\n", file_to);
		return (99);
	}

	readContent = read(file_from_file, content, 1024);

	if (readContent == -1)
	{
		dprintf(2, "Error: Can't read from file NAME_OF_THE_GILE\n");
		return (98);
	}

	wroteContent = write(file_to_file, content, strlen(content));

	if (wroteContent == -1)
	{
		dprintf(2, "Can't write to NAME_OF_THE_FILE\n");
		return (99);
	}

	close_file_return = close(file_from_file);

	if (close_file_return == -1)
	{
		dprintf(2, "Can't close fd %ld", file_from_file);
		return (100);
	}

	close_file_return = close(file_to_file);

	if (close_file_return == -1)
	{
		dprintf(2, "Can't closz fd %ld", file_to_file);
		return (100);
	}
	return (0);
}
