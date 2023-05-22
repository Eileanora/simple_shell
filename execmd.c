#include "main.h"
#include <signal.h>

int (*builtins[])(char **) = {
	&shell_exit,
	&shell_cd,
	&shell_env
};

/**
 * check_builtins - checks if the command is a builtin
 * @argv: array of strings
 * Return: 1 if the command is a builtin, -1 otherwise
*/
int check_builtins(char **argv)
{
	int i;
	char *builein_str[] = {"exit", "cd", "env"};

	for (i = 0; i < 3; i++)
		if (_strcmp(argv[0], builein_str[i]) == 0)
			return ((*builtins[i])(argv));
	return (-1);
}
/**
 * execmd - execute the command with execve
 * @argv: array of strings
 * Return: void
 */
void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		command = argv[0];
		actual_command = get_location(command);
		if (actual_command == NULL)
			actual_command = command;
		if (execve(actual_command, argv, NULL) == -1)
			perror("Error");
	}
}
/**
 * create_process - creates a child process
 * @argv: array of strings
 * Return: void
 */
int create_process(char **argv)
{
	pid_t pid, wpid;
	int status;

	UNUSED(wpid);
	if (check_builtins(argv) != -1)
		return (1);

	pid = fork();
	if (pid == 0) /* child created successfully */
	{
		execmd(argv);
		free_array(argv);
		free_list();
		exit(EXIT_FAILURE);
	}
	else if (pid < 0) /* error creating the child */
	{
		perror("Error");
	}
	else /* parent process */
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
