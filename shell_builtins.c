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
