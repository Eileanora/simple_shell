#include "main.h"
/**
 * shell_exit - exits the shell
 * @argv: arguments
 * Return: 0
 */
int shell_exit(char **argv)
{
	free_array(argv);
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
		chdir(getenv("HOME"));
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
