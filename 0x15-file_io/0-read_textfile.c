#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters it should read and print
 *
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t r, w;
char *buf;

if (!filename)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buf = malloc(sizeof(char) * letters);
if (!buf)
return (0);

r = read(fd, buf, letters);
if (r == -1)
{
free(buf);
return (0);
}

w = write(STDOUT_FILENO, buf, r);
if (w == -1 || w != r)
{
free(buf);
return (0);
}

free(buf);
close(fd);

return (w);
}
