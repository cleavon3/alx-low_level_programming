#include "function_pointers.h"
/**
 * int_index - Searches for an integer in an array using a comparison function
 * @array: The array to search
 * @size: The size of the array
 * @cmp: A pointer to a function that performs the comparison
 *
 * Return: The index of the first element for which cmp returns true, or -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
int i;
if (array == NULL || size <= 0 || cmp == NULL)
return (-1);
for (i = 0; i < size; i++)
{
if (cmp(array[i]))
return (i);
}
return (-1);
}
