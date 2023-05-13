#include "main.h"
/**
 * _strtok - tokenizes a string
 * @str: string to tokenize
 * @delim: delimiter to tokenize by
 * Return: pointer to the first character of the token, or NULL if no token
*/
char *_strtok(char *str, char *delim)
{
	static char *lastest;
	char *start;

	if (str != NULL)
		lastest = str;

	if (!lastest || !delim || *lastest == '\0')
		return (NULL);

	while (*lastest != '\0' && _strchr(delim, *lastest))
		lastest++;

	start = lastest;

	while (*lastest != '\0' && _strchr(delim, *lastest) == NULL) /* tokenization */
		lastest++;
	
	if (*lastest != '\0')
	{
		*lastest = '\0';
		lastest++;
	}
	if (*start == '\0') /* if no token was generated */
		return (NULL);
	return (start);
}
