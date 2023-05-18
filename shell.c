#include "main.h"

int main (int argc, char **argv)
{
	char *prompt = "MyShell> ";
	char *linptr = NULL;
	size_t nread = 0;
	int i;
	UNUSED(argc);
	UNUSED(argv);

	while(1)
	{
		char **args;
		write(1, prompt, _strlen(prompt));
		if (getline(&linptr, &nread, stdin) == -1)
		{
			write(1, "exiting...\n", 11);
			free(linptr);
			exit(-1);
		}
		if (_strcmp(linptr, "exit\n") == 0)
		{
			write(1, "exiting...\n", 11);
			break;
		}
		/* write(1, linptr, _strlen(linptr)); */
		args = split_string(linptr, DELIM);
		execmd(args);
		for (i = 0; args[i]; i++)
		{
		
			free(args[i]);
		}
		free(args);
	}
	free(linptr);
	return (0);
}
