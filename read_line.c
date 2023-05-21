#include "main.h"
/**
 * read_line - reads an entire line from a file stream
 * @lineptr: pointer to a string to read into
 * Return: line
*/
char *read_line()
{
	char *line;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		write(1, "exiting...\n", 11);
		free(line);
		if (!feof(stdin))
			exit(EXIT_SUCCESS);
		else
			perror("readline"), exit(EXIT_FAILURE);
	}
	return (line);
}
