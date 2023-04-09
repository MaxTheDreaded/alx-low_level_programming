#include "main.h"

/**
 * elf - checks the ELF header of a file
 * @file: file name
 * Return: 1 if ELF, 0 if not
 */
int elf(const char *file)
{
int fd, r;
unsigned char buf[4];

fd = open(file, O_RDONLY);
if (fd == -1)
return (0);
r = read(fd, buf, 4);
if (r == -1)
return (0);
if (buf[0] == 0x7f && buf[1] == 'E' && buf[2] == 'L' && buf[3] == 'F')
return (1);
return (0);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
exit(98);
}
if (elf(argv[1]) == 0)
{
dprintf(STDERR_FILENO, "Error: Not an ELF file - %s\n", argv[1]);
exit(98);
}
return (0);
}

