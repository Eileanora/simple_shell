#include "main.h"
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
 * replace_node - replace a node in the list
 * @name: name of the node to replace
 * @value: value to replace the node with
 * Return: 1 on success, 0 on failure
*/
int replace_node(char *name, char *value)
{
	envlist_t *exist;
	char *val, *old_val;

	val = malloc(sizeof(char) * (_strlen(value) + _strlen(name) + 2));
	if (!val)
		return (0);
	_strcpy(val, name);
	_strcat(val, "=");
	_strcat(val, value);
	exist = search_node(val);
	if (exist == NULL)
	{
		add_node(val);
		free(val);
		return (1);
	}
	old_val = exist->value;
	free(exist->value);
	exist->value = malloc(sizeof(char) * (_strlen(value) + 1));
	if (!exist->value)
	{
		exist = create_node(old_val);
		free(val);
		return (0);
	}
	/* free(old_val); */
	_strcpy(exist->value, value);
	exist->len = _strlen(value);
	free(val);
	return (1);
}
/**
 * search_node - search for a node in the list
 * @name: the name of the variable
 * Return: the node if found, NULL otherwise
*/
envlist_t *search_node(char *name)
{
	envlist_t *temp = get_singleton_list();

	while (temp)
	{
		if (strcmp_sign(temp->value, name, '=') == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
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
	if ((s1[i] == '\0' && s2[i] == sign) || (s1[i] == sign && s2[i] == '\0'))
		return (0);
	return (1);
}
