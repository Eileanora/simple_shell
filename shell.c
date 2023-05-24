#include "main.h"
#include <signal.h>
/**
 * signal_handler - handles the signal
 * @sig: signal number
 * Return: void
*/
void signal_handler(int sig)
{
	UNUSED(sig);
	write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * main - shell entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
*/
int main(int argc, char **argv)
{
	char *prompt = "$ ";
	size_t nread = 0;
	int status = 1;

	UNUSED(argc);
	UNUSED(argv);

	/* initialize the environment */
	do {
		char **args, *lineptr = NULL;

		if (isatty(STDIN_FILENO))
			write(1, prompt, _strlen(prompt));
		signal(SIGINT, signal_handler);
		increment_cnt(0);
		if (getline(&lineptr, &nread, stdin) == -1)
		{
			free(lineptr);
			break;
		}
		if (*lineptr == '\n')
		{
			free(lineptr);
			continue;
		}
		args = split_string(lineptr, DELIM);
		free(lineptr);
		status = create_process(args);
		free_array(args);
	} while (status);
	return (0);
}
