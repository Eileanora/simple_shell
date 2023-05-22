#include <stdlib.h>
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
