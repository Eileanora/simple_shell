#include "main.h"

int main (int argc, char **argv)
{
	char *prompt = "MyShell> ";
	char *lineptr = NULL;
	int i;
	UNUSED(argc);
	UNUSED(argv);

	do
	{
		char **args;
		lineptr = read_line();
		if (_strcmp(lineptr, "exit\n") == 0)
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
		free(lineptr);
	}
	while (1);
	return (0);
}
