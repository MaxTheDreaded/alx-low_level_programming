#include "main.h"

/**
 * error_msg - prints error messages
 * @err: error number
 * @file: file name
 */
void error_msg(int err, char *file)
{
switch (err)
{
case 97:
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
case 98:
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
exit(98);
case 99:
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
exit(99);
case 100:
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", err);
exit(100);
}
}

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
fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_to == -1)
{
close(fd_from);
error_msg(100, NULL);
}
r = read(fd_from, buf, 1024);
if (r == -1)
{
close(fd_from);
close(fd_to);
error_msg(98, (char *)file_from);
}
while (r > 0)
{
w = write(fd_to, buf, r);
if (w == -1)
{
close(fd_from);
close(fd_to);
error_msg(99, (char *)file_to);
}
r = read(fd_from, buf, 1024);
if (r == -1)
{
close(fd_from);
close(fd_to);
error_msg(98, (char *)file_from);
}
}
if (close(fd_from) == -1)
error_msg(100, NULL);
if (close(fd_to) == -1)
error_msg(100, NULL);

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
int c;

if (argc != 3)
error_msg(97, NULL);

c = copier(argv[1], argv[2]);
if (c == -1)
{
error_msg(98, argv[1]);
error_msg(99, argv[2]);
}

return (0);
}
