#include <stdlib.h> /* Include the standard library for malloc */
#include "main.h"   /* Include a custom header file if needed */
/**
* string_nconcat - concatenates n bytes of a string to another string
* @s1: string to append to
* @s2: string to concatenate from
* @n: number of bytes from s2 to concatenate to s1
*
* Return: pointer to the resulting string
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *s; /* Declare a pointer to hold the concatenated string */
unsigned int i = 0, j = 0, len1 = 0, len2 = 0; /* Initialize var for legnth */
/* Calculate the length of s1 */
while (s1 && s1[len1])
len1++;
/* Calculate the length of s2 */
while (s2 && s2[len2])
len2++;
/* Allocate memory for the resulting string */
if (n < len2)
s = malloc(sizeof(char) * (len1 + n + 1));
else
s = malloc(sizeof(char) * (len1 + len2 + 1));
/* Check if memory allocation was successful */
if (!s)
return (NULL);
/* Copy characters from s1 to s */
while (i < len1)
{
s[i] = s1[i];
i++;
}
/* Copy characters from s2 to s until n bytes or until the end of s2 */
while (n < len2 && i < (len1 + n))
s[i++] = s2[j++];
/* Copy characters from s2 to s if n is greater than or equal to len2 */
while (n >= len2 && i < (len1 + len2))
s[i++] = s2[j++];
/* Null-terminate the resulting string */
s[i] = '\0';
/* Return a pointer to the concatenated string */
return (s);
}

