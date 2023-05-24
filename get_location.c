#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 * Return: pointer to the value of the environment variable
 * Description: uses extern char **environ
*/

char *_getenv(char *name)
{
	int i, j, name_length;
	char *env;

	for (i = 0; __environ[i] != NULL; i++)
	{
		env = __environ[i];
		name_length = _strlen(name);

		for (j = 0; j < name_length; j++)
		{
			if (env[j] != name[j])
				break;
		}
		if (j == name_length && env[j] == '=')
		{
			return (env + j + 1);
		}
	}
	return (NULL);
}
/**
 * get_location - gets the location of a command
 * @command: command to find
 * Return: pointer to the location of the command
 * Description: uses stat to check if the command exists
 */

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buf;
	if (stat(command, &buf) == 0)
		return (command);

	path = _getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		command_length = _strlen(command);
		path_token = _strtok(path_copy, ":");

		while (path_token != NULL)
		{
			directory_length = _strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");
			if (stat(file_path, &buf) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = _strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buf) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
/**
 * _strcat - concatenates two strings
 * @dest: string to be appended to
 * @src: string to append
 * Return: pointer to the resulting string dest
 * Description: assumes dest has enough space allocated
 * for the combined string
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer to the new string or NULL if memory allocation
 * fails or str is NULL
 * Description: returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter
 * The copied string ends with a null byte
 *
 */
char *_strdup(char *str)
{
	int i, len;
	char *dup;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[len] = '\0';
	return (dup);
}
