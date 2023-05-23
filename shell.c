#include "main.h"
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

	UNUSED(argc);
	UNUSED(argv);

	/* initialize the environment */
	cpy_env();
	while (1)
	{
		char **args, *lineptr = NULL;

		if (isatty(STDIN_FILENO))
			write(1, prompt, _strlen(prompt));
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
		create_process(args);
		free_array(args);
	}
	free_list();
	return (0);
}
