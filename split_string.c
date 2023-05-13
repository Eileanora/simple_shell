#include "main.h"
/* split string */
/**
 * split_string - splits string into tokens
 * @str: string to split
 * @delim: delimiter to split string by
 * Return: pointer to array of tokens
*/
char **split_string(char *lineptr, char *delim)
{
	char *cpy_lineptr = NULL, *token = NULL;
	char **args = NULL;
	int cnt_tokens = 0, i;

	/* step 1) Dynamically allocate memory for cpy_lineptr */
	cpy_lineptr = malloc(sizeof(char) * strlen(lineptr) + 1);
	if (!cpy_lineptr)
	{
		free(cpy_lineptr);
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* step 2) copy str into cpy_lineptr */
	_strcpy(cpy_lineptr, lineptr);
	/* step 3) count number of tokens needed to allocate space for them */ 
	token = _strtok(cpy_lineptr, delim);
	while (token != NULL)
	{
		cnt_tokens++;
		token = _strtok(NULL, delim);
	}

	/* step 4) Dynamically allocate memory for args */
	args = malloc(sizeof(char *) * (cnt_tokens + 1));
	if (!args)
	{
		free(cpy_lineptr);
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* step 5) copy tokens into args */
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
	/* step 6) free cpy_lineptr */
	free(cpy_lineptr);
	return (args);
}