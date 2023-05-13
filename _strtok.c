#include "main.h"
/**
 * _strtok - tokenizes a string
 * @str: string to tokenize
 * @delim: delimiter to tokenize by
 * Return: pointer to the first character of the token, or NULL if no token
*/
char *_strtok(char *str, const char *delim)
{
	static char *lastest;
	static int end;
	char *start;

	if (str != NULL)
	{
		lastest = str;
		end = 0;
	}

	if (!lastest || !delim || lastest[end] == '\0')
		return (NULL);

	start = &lastest[end];
	while (1)
	{
		if (lastest[end] == *delim)
		{
			lastest[end++] = '\0';
			while(lastest[end] == *delim)
				end++;
			break;
		}
		if (lastest[end] == '\0')
			break;
		end++;
	}
	return (start);
}
