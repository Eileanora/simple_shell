#include "main.h"
/* split string */
/**
 * split_string - splits string into tokens
 * @lineptr: string to split
 * @delim: delimiter to split string by
 * Return: pointer to array of tokens
*/
char **split_string(char *lineptr, char *delim)
{
	char *cpy_lineptr = NULL, *token = NULL;
	char **args = NULL;
	int cnt_tokens = 0, i;

	cpy_lineptr = malloc(sizeof(char) * strlen(lineptr) + 1);
	if (!cpy_lineptr)
	{
		free(cpy_lineptr);
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	_strcpy(cpy_lineptr, lineptr);
	token = _strtok(cpy_lineptr, delim);
	while (token != NULL)
	{
		cnt_tokens++;
		token = _strtok(NULL, delim);
	}
	args = malloc(sizeof(char *) * (cnt_tokens + 1));
	if (!args)
	{
		free(cpy_lineptr);
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = _strtok(lineptr, delim);
	for (i = 0; token != NULL; i++)
	{
		args[i] = malloc(sizeof(char) * strlen(token) + 1);
		if (!args[i])
			return (NULL);
		_strcpy(args[i], token);
		token = _strtok(NULL, delim);
	}
	args[i] = '\0';
	free(cpy_lineptr);
	return (args);
}
