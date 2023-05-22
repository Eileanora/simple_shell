#include "main.h"
/**
 * shell_exit - exits the shell
 * @argv: arguments
 * Return: 0
 */
int shell_exit(char **argv)
{
	free_array(argv);
	free_list();
	exit(EXIT_SUCCESS);
}
/**
 * shell_cd - changes the current directory
 * @argv: arguments
 * Return: 1
*/
int shell_cd(char **argv)
{
	/* make the default path $HOME value*/
	if (argv[1] == NULL)
	{
		chdir(_getenv("HOME"));
		return (1);
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			perror("Error");
		}
		return (1);
	}
	return (0);
}

int shell_env(char **argv)
{
	int i;
	char **env = __environ;

	UNUSED(argv);
	for (i = 0; env[i] != NULL; i++)
	{
		write(1, env[i], _strlen(env[i]));
		write(1, "\n", 1);
	}
	return (1);
}
/**
 * _setenv - set an environment variable
 * @name: the name of the variable
 * @value: the value of the variable
 * Return: 0 on success, -1 on failure
*/

int _setenv(char **argv)
{
	char *name = argv[1], *value = argv[2];
	envlist_t *temp = search_node(name);
	int status;

	if (!name || !value || _strchr(name, '=') != NULL)
	{
		perror("setenv");
		return (-1);
	}
	if (temp == NULL)
	{
		status = add_node(name, value);
		if (status == -1)
		{
			perror("setenv");
			return (-1);
		}
		return (0);
	}
	else
	{
		free(temp->value);
		temp->value = malloc(sizeof(char) * (_strlen(value) + 1));
		if (!temp->value)
		{
			perror("setenv");
			return (-1);
		}
		_strcpy(temp->value, value);
		return (0);
	}
}

/**
 * _unsetenv - unset an environment variable
 * @name: the name of the variable
 * Return: 0 on success, -1 on failure
*/
int _unsetenv(char **argv)
{
	int status;
	char *name = argv[1];

	if (!name)
	{
		perror("unsetenv");
		return (-1);
	}
	status = delete_node(name);
	if (status == -1)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}
