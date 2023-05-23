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
 * free_list - free the list
 * Return: void
*/
void free_list(void)
{
	envlist_t *temp = get_singleton_list();

	while (temp)
	{
		envlist_t *next = temp->next;

		free(temp->name);
		free(temp->value);
		free(temp);
		temp = next;
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
/**
 * cpy_env - copy the __environ variable into a linked list
*/
void cpy_env(void)
{
	int i = 0, status;
	char *name, *value;

	while (__environ[i])
	{
		name = _strtok(__environ[i], "=");
		/* value = all remaining untill the end */
		value = _strtok(NULL, "\0");
		status = add_node(name, value);
		if (status == -1)
		{
			write(STDERR_FILENO, "Error: malloc failed\n", 22);
			return;
		}
		i++;
	}
}
