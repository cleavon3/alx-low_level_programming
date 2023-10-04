#include "main.h"

/**
 * create_buffer - Allocates a 1024-byte buffer.
 * @file: The name of the file for error messages.
 *
 * Return: A pointer to the newly-allocated buffer, or exits on failure.
 */
char *create_buffer(const char *file)
{
char *buffer;
buffer = malloc(1024);
if (buffer == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
exit(99);
}
return (buffer);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 *
 * Return: 1 on success, -1 on failure.
 */
int close_file(int fd)
{
int status = close(fd);
if (status == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
return (-1);
}
return (1);
}

/**
 * main - Copies the contents of one file to another.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or exits with specific codes on failure.
 */
int main(int argc, char *argv[])
{
int from_fd, to_fd, bytes_read, bytes_written;
char *buffer;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
return (97);
}
buffer = create_buffer(argv[2]);
from_fd = open(argv[1], O_RDONLY);
if (from_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't open source file %s for reading\n", argv[1]);
free(buffer);
return (98);
}
to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (to_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't open destination file %s for writing\n", argv[2]);
free(buffer);
return (99);
}
while ((bytes_read = read(from_fd, buffer, 1024)) > 0)
{
bytes_written = write(to_fd, buffer, bytes_read);
if (bytes_written == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to destination file %s\n", argv[2]);
free(buffer);
close_file(from_fd);
close_file(to_fd);
return (99);
}
}
if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from source file %s\n", argv[1]);
free(buffer);
close_file(from_fd);
close_file(to_fd);
return (98);
}
free(buffer);
if (close_file(from_fd) == -1 || close_file(to_fd) == -1)
{
return (100);
}
return (0);
}

