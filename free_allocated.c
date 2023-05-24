#include <stdlib.h>
#include "main.h"
/**
 * free_string - frees a string
 * @str: string to free
*/
void free_string(char *str)
{
	if (str)
		free(str);
}
/**
 * free_array - frees an array of strings
 * @array: array of strings
*/
void free_array(char **array)
{
	int i;

	if (array)
	{
		for (i = 0; array[i]; i++)
		{
			free(array[i]);
		}
		free(array);
	}
}
/**
 * array_2d_len - returns the length of a 2d array
 * @array: array to check
 * Return: length of the array
*/
int array_2d_len(char **array)
{
	int i;

	for (i = 0; array[i]; i++)
		;
	return (i);
}
