#include "main.h"
/* write _strlen */
/**
 * _strlen - returns the length of a string
 * @s: string to check length of
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;
	if (!s)
		return (0);

	while (s[i])
		i++;
	return (i);
}
/* strcpy */
/**
 * _strcpy - copies the string pointed to by src to dest including null byte
 * @dest: pointer to destination of string
 * @src: pointer to source of string
 * Return: pointer to destination of string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (!dest || !src)
		return (NULL);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	/* null terminator */
	dest[i] = src[i];
	return (dest);
}
/* _strcmp */
/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: difference between strings
*/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
/* _strchr */
/**
 * _strchr - locates the first occurance of a character in a string
 * @s: string to search
 * @c: character to search for
 * Return: pointer to first occurence of c in s, or NULL if not found
*/
char *_strchr(char *s, char c)
{
	int i;

	if (!s)
		return (NULL);
	
	for (i = 0; s[i]; i++)
		if (s[i] == c)
			return (s + i);
	if (s[i] == '\0' && c == '\0')
		return (s + i);
	return (NULL);
}
