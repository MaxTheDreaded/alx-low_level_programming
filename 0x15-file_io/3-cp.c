#include "main.h"

/**
 * copier - copies the content of a file to another file
 * @file_from: file to copy from
 * @file_to: file to copy to
 * Return: 1 on success, -1 on failure
 */
int copier(const char *file_from, const char *file_to)
{
int fd_from, fd_to, r, w;
char buf[1024];

fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
return (-1);

if (access(file_to, W_OK) == 0)
{
fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_to == -1)
return (-1);
}
else
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
exit(99);
}

while ((r = read(fd_from, buf, 1024)) > 0)
{
w = write(fd_to, buf, r);
if (w == -1)
return (-1);
}

if (r == -1)
return (-1);

if (close(fd_from))
return (0);
else if (!close(fd_from))
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);

if (close(fd_to))
return (0);
else if (!close(fd_to))
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);

return (1);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 97 on failure
 */
int main(int argc, char *argv[])
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
}

if (copier(argv[1], argv[2]) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);
}

return (0);
}
