#include "main.h"
#include <signal.h>

int (*builtins[])(char **) = {
	&shell_exit,
	&shell_cd,
	&shell_env,
	&_setenv,
	&_unsetenv,
	&btats
};

/**
 * check_builtins - checks if the command is a builtin
 * @argv: array of strings
 * Return: 1 if the command is a builtin, -1 otherwise
*/
int check_builtins(char **argv)
{
	int i;
	char *builein_str[] = {"exit", "cd", "env", "setenv", "unsetenv", "btats"};

	for (i = 0; i < 6; i++)
		if (_strcmp(argv[0], builein_str[i]) == 0)
			return ((*builtins[i])(argv));
	return (-2);
}
/**
 * execmd - execute the command with execve
 * @args: array of strings
 * Return: void
 */
char *execmd(char **args)
{
	char *command = NULL, *actual_command = NULL;

	if (args)
	{
		command = args[0];
		actual_command = get_location(command);
		if (actual_command == NULL)
			return (NULL);
		else
			return (actual_command);
	}
	return (NULL);
}
/**
 * create_process - creates a child process
 * @args: array of strings
 * Return: void
 */
int create_process(char **args)
{
	pid_t pid, wpid;
	int status;
	char *actual_command = NULL;

	UNUSED(wpid);
	if (check_builtins(args) != -2)
		return (1);

	actual_command = execmd(args);
	if (actual_command == NULL)
	{
		print_error(2, args[0], ": not found\n");
		return (1);
	}
	pid = fork();
	if (pid == 0) /* child created successfully */
	{
		execve(actual_command, args, __environ);
		free_array(args);
		free_list();
		exit(EXIT_FAILURE);
	}
	else if (pid < 0) /* error creating the child */
	{
		perror("Error");
		write(STDERR_FILENO, "Creating child process failed\n", 31);
	}
	else /* parent process */
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	if (actual_command && actual_command != args[0])
		free(actual_command);
	return (1);
}
