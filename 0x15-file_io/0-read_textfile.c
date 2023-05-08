#include "main.h"

/**
 * read_textfile - reads a text file and prints
 * it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters it should read and print
 * Return: actual number of letters it could read and print
 * 0 if filename is NULL
 * 0 if write fails or does not write the expected amount of bytes
 * 0 if the file can not be opened or read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t lenr, lenw;
char *buffer;

if (filename == NULL)
return (0);

/* open */
fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

/* malloc */
buffer = malloc(sizeof(char) * letters);
if (buffer == NULL)
return (0);

/* read */
lenr = read(fd, buffer, letters);
if (lenr == -1)
{
free(buffer);
return (0);
}

/* write */
lenw = write(STDOUT_FILENO, buffer, lenr);
if (lenw == -1 || lenr != lenw)
{
free(buffer);
return (0);
}

free(buffer);
close(fd);
return (lenw);
}
