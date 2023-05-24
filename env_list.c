#include "main.h"
static envlist_t *envlist;

/**
 * get_singleton_list - get the singleton list
 *
 * Return: the singleton list
 */
envlist_t *get_singleton_list(void)
{
	if (!envlist)
		envlist = create_node(NULL);
	return (envlist);
}
/**
 * create_node - add a node to the list
 * @val: the value
 * Return: the new head of the list
*/
envlist_t *create_node(char *val)
{
	envlist_t *newnode;

	if (!val)
		return (NULL);
	newnode = malloc(sizeof(envlist_t));
	if (!newnode)
		return (NULL);
	newnode->value = malloc(sizeof(char) * (_strlen(val) + 1));
	if (!newnode->value)
	{
		free(newnode);
		return (NULL);
	}
	_strcpy(newnode->value, val);
	newnode->len = _strlen(val);
	newnode->next = NULL;
	return (newnode);
}
/**
 * strcmp_sign - compare two strings till a sign
 * @s1: the first string
 * @s2: the second string
 * @sign: the sign
 * Return: 0 if equal, 1 if not
*/
int strcmp_sign(char *s1, char *s2, char sign)
{
	int i;

	for (i = 0; s1[i] && s2[i] && s1[i] != sign && s2[i] != sign; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}
	if (s1[i] == sign && s2[i] == sign)
		return (0);
	if (s1[i] == '\0' && s2[i] == sign)
		return (0);
	return (1);
}

/**
 * print_list - print the list
 * Return: the number of nodes
*/
int print_list(void)
{
	envlist_t *temp = get_singleton_list();
	int i = 0;

	while (temp)
	{
		write(STDOUT_FILENO, temp->value, temp->len);
		write(STDOUT_FILENO, "\n", 1);
		temp = temp->next;
		i++;
	}
	return (i);
}
/**
 * free_list - free the list
*/
void free_list(void)
{
	envlist_t *temp = get_singleton_list();
	envlist_t *next;

	while (temp)
	{
		next = temp->next;
		free(temp->value);
		free(temp);
		temp = next;
	}
}
