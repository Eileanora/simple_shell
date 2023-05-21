#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
/**
 * get_location - gets the location of a command
 * @argv: array of strings
 * Return: pointer to the location of the command
 */

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buf;

	path = getenv("PATH");

	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buf) == 0)
			{
				free(path_copy);

				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}

		free(path_copy);

		if (stat(command, &buf) == 0)
		{
			return (command);
		}

		return (NULL);
	}

	return (NULL);
}
