#include <stdio.h>
#include <stdlib.h>
/**
 * main - Prints its own opcodes
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
int bytes, i;
unsigned char *arr;
if (argc != 2)
{
printf("Error\n");
return (1);
}
bytes = atoi(argv[1]);
if (bytes < 0)
{
printf("Error\n");
return (2);
}
arr = (unsigned char *)main;
for (i = 0; i < bytes; i++)
{
if (i == bytes - 1)
{
printf("%02hhx\n", arr[i]);
}
else
{
printf("%02hhx ", arr[i]);
}
}
return (0);
}
