#include <stdio.h>
#include "main.h"
/**
* _atoi - converts a string to an integer
* @s: string to be converted
*
* Return: the int converted from the string
*/
int _atoi(char *s)
{
int i, d, n, len, f, digit;
i = 0;
d = 0;
n = 0;
len = 0;
f = 0;
digit = 0;
while (s[len] != '\0')
len++;
while (i < len && f == 0)
{
if (s[i] == '-')
++d;
if (s[i] >= '0' && s[i] <= '9')
{
digit = s[i] - '0';
if (d % 2)
digit = -digit;
n = n * 10 + digit;
f = 1;
if (s[i + 1] < '0' || s[i + 1] > '9')
break;
f = 0;
}
i++;
}
if (f == 0)
return (0);
return (n);
}
/**
* main - multiplies two numbers
* @argc: number of arguments
* @argv: array of arguments
*
* Return: 0 (Success), 1 (Error)
*/
int main(int argc, char *argv[])
{
int result, num1, num2;
if (argc < 3 || argc > 3)
{
printf("Error\n");
return (1);
}
 num1 = _atoi(argv[1]);
 num2 = _atoi(argv[2]);
result = num1 * num2;
printf("%d\n", result;
return (0);
}
4 - add.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
* check_num - check - string there are digit
* @str: array str
*
* Return: Always 0 (Success)
*/
int check_num(char *str)
{
/*Declaring variables*/
unsigned int count;
count = 0;
while (count < strlen(str)) /*count string*/
{
if (!isdigit(str[count])) /*check if str there are digit*/
{
return (0);
}
count++;
}
return (1);
}
/**
* main - Print the name of the program
* @argc: Count arguments
* @argv: Arguments
*
* Return: Always 0 (Success)
*/
int main(int argc, char *argv[])
{
/*Declaring variables*/
int count;
int str_to_int;
int sum = 0;
count = 1;
while (count < argc) /*Goes through the whole array*/
{
if (check_num(argv[count]))
{
str_to_int = atoi(argv[count]); /*ATOI --> convert string to int*/
sum += str_to_int;
}
/*Condition if one of the number contains symbols that are not digits*/
else
{
printf("Error\n");
return (1);
}
count++;
}
printf("%d\n", sum); /*print sum*/
return (0);
}
