#include "main.h"

int main (int argc, char **argv)
{
	char *prompt = "MyShell> ";
	char *lineptr = NULL;
	size_t nread = 0;
	int i;
	UNUSED(argc);
	UNUSED(argv);

	while(1)
	{
		char **args;
		lineptr = NULL;
		write(1, prompt, _strlen(prompt));
		if (getline(&lineptr, &nread, stdin) == -1)
		{
			write(1, "exiting...\n", 11);
			free(lineptr);
			exit(-1);
		}
		if (_strcmp(lineptr, "exit\n") == 0)
		{
			write(1, "exiting...\n", 11);
			break;
		}

		args = split_string(lineptr, DELIM);
		free(lineptr);
		/** add args address to the linkedlist */
		create_process(args);
		for (i = 0; args[i]; i++)
		{
			free(args[i]);
		}
		free(args);

	}
	free(lineptr);
	free_list(get_singleton_list());
	return (0);
}
