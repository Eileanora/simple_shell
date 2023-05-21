#include "main.h"

int main (int argc, char **argv)
{
	char *prompt = "MyShell> ";
	char *lineptr = NULL;
	size_t nread = 0;

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
		args = split_string(lineptr, DELIM);
		free(lineptr);
		create_process(args);
		free_array(args);
	}
	return (0);
}
