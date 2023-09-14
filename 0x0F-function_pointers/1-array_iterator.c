#include "function_pointers.h"
#include <stdio.h>
/**
 * array_iterator - Iterates through an array
 * @array: The array to iterate through
 * @size: The number of elements in the array
 * @action: A pointer to a function that specifies the action to perform.
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
unsigned int i;
if (array == NULL || action == NULL)
return;

for (i = 0; i < size; i++)
{
action(array[i]);
}
}
