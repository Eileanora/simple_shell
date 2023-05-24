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
	char *oldpwd = NULL, CWD[1024];
	char *_setenv_args[4] = {"setenv", "OLDPWD", NULL, NULL};
	char *_unsetenv_args[4] = {"unsetenv", "PWD", NULL, NULL};
	/* make the default path $HOME value*/
	if (argv[1] == NULL || _strcmp(argv[1], "~") == 0)
	{
		chdir(_getenv("HOME"));
		/* write(STDOUT_FILENO, _getenv("HOME"), _strlen(_getenv("HOME"))); */
		/* write(STDOUT_FILENO, "\n", 1); */
	}
	else if (_strcmp(argv[1], "-") == 0)
	{
		oldpwd = _getenv("OLDPWD");
		if (oldpwd != NULL)
		{
			chdir(oldpwd);
			write(STDOUT_FILENO, oldpwd, _strlen(oldpwd));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
			write(STDOUT_FILENO, getcwd(CWD, 1024), _strlen(getcwd(CWD, 1024)));
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			perror("cd");
			return (1);
		}
		/* write(STDOUT_FILENO, getcwd(CWD, 1024), _strlen(getcwd(CWD, 1024))); */
		/* write(STDOUT_FILENO, "\n", 1); */
	}
	_setenv_args[2] = _getenv("PWD");
	_setenv(_setenv_args);
	_unsetenv(_unsetenv_args);
	_setenv_args[1] = "PWD";
	_setenv_args[2] = getcwd(CWD, 1024);
	_setenv(_setenv_args);

	return (1);
}
/**
 * shell_env - prints the current environment
 * @argv: arguments
 * Return: 1
*/
int shell_env(char **argv)
{
	envlist_t *temp = get_singleton_list();

	UNUSED(argv);
	while (temp != NULL)
	{
		write(STDOUT_FILENO, temp->value, temp->len);
		write(STDOUT_FILENO, "\n", 1);
		temp = temp->next;
	}
	return (1);
}
/**
 * _setenv - set an environment variable
 * @argv: arguments passed to the function
 * Return: 1 on success, 0 on failure
*/

int _setenv(char **argv)
{
	char *name, *value;
	int status;

	if (argv[1] == NULL || argv[2] == NULL)
	{
		write(STDERR_FILENO, "Invalid argument\n", 17);
		return (0);
	}
	name = argv[1], value = argv[2];
	if (!name || !value || _strchr(name, '=') != NULL)
	{
		write(STDERR_FILENO, "Invalid argument\n", 17);
		return (0);
	}
	if (array_2d_len(argv)  != 3)
	{
		write(STDERR_FILENO, "Wrong number of arguments\n", 26);
		return (0);
	}
	status = replace_node(name, value);
	return (status);
}
/* error handling needs reveiwing */
/**
 * _unsetenv - unset an environment variable
 * @argv: arguments passed to the function
 * Return: 1 on success, 0 on failure
*/
int _unsetenv(char **argv)
{
	int status;
	char *name;

	if (array_2d_len(argv) != 2)
	{
		write(STDERR_FILENO, "Wrong number of arguments\n", 26);
		return (0);
	}
	name = argv[1];
	if (!name)
	{
		write(STDERR_FILENO, "Wrong number of arguments\n", 26);
		return (0);
	}
	status = delete_node(name);
	if (status == 0)
	{
		write(STDERR_FILENO, "Error allocating memory\n", 24);
		return (0);
	}
	return (1);
}
