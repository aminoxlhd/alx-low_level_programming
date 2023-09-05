#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "main.h"

void display_elf(const char *elf_filename);

int main(int ac, char **av)
{
	if (ac != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", av[0]);
		exit(-1);
	}
	display_elf(av[1]);
	return (0);
}

void display_elf(const char *elf_filename)
{
	Elf64_Ehdr *content;
	ssize_t file, readContent;
	int close_file_return;

	if (elf_filename == NULL)
	{
		return;
	}

	file = open(elf_filename, O_RDONLY);

	if (file == -1)
	{
		return;
	}

	content = malloc(sizeof(Elf64_Ehdr));

	readContent = read(file, content, sizeof(Elf64_Ehdr));

	if (readContent == -1)
	{
		printf("Error: Can't read from file %s\n", elf_filename);
		close(file);
		return;
	}

	printf("ELF Header:");

	printf(" Magic: ");

	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", content->e_ident[i]);
		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}

	printf(" Class: ");

	switch (content->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n" : content->e_ident[EI_CLASS]);
	}

	printf(" Data: ");

	switch (content->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", content->e_ident[EI_CLASS]);
	}

	printf(" Version: %d\n", content->e_ident[EI_VERSION]);

	printf(" OS/ABI: ");

	switch (content->e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalon App\n");
			break;
		default:
			printf("<unknown: %x>\n", content->e_ident[EI_OSABI]);
	}

			printf(" ABI Version: %d\n", content->e_ident[EI_ABIVERSION]);

			if (content->e_ident[EI_DATA] == ELFDATA2MSB)
			{
				content->e_type >>= 8;
			}

			printf(" type: ");

			switch (content->e_type)
			{
				case ET_NONE:
					printf("NONE (None)\n");
					break;
				case ET_REL:
					printf("REM (Relocatable file)\n");
					break;
				case ET_EXEC:
					printf("EXEC (Executable file)\n");
					break;
				case ET_DYN:
					printf("DYN (Shared object file)\n");
					break;
				case ET_CORE:
					printf("CORE (Core file)\n");
					break;
				default:
					printf("<unknown: %x>\n", content->e_type);
			}

			printf(" Entry point adress: ");

			if (content->e_ident[EI_DATA] == ELFDATA2MSB)
			{
				content->e_entry = ((content->e_entry << 8) & 0xFF00FF00) |
			  ((content->e_entry >> 8) & 0xFF00FF);
				content->e_entry = (content->e_entry << 16) | (content->e_entry >> 16);
			}
			if (content->e_ident[EI_CLASS] == ELFCLASS32)
			{
				printf("%#x\n", (unsigned int) content->e_entry);
			}
			else
			{
				printf("%#lx\n", content->e_entry);
			}

			free(content);

close_file_return = close(file);

if (close_file_return == -1)
{
	printf("Can't clode fd %s", elf_filename);
	return;
}
}
