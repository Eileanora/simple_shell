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
		envlist = create_node(NULL, NULL);
	return (envlist);
}
/**
 * create_node - add a node to the list
 * @Name: the variable
 * @Val: the value
 * Return: the new head of the list
*/
envlist_t *create_node(char *Name, char *Val)
{
	envlist_t *newnode;

	if (!Name || !Val)
		return (NULL);

	newnode = malloc(sizeof(envlist_t));
	if (!newnode)
		return (NULL);

	newnode->name = malloc(sizeof(char) * (_strlen(Name) + 1));
	newnode->value = malloc(sizeof(char) * (_strlen(Val) + 1));
	if (!newnode->value || !newnode->name)
	{
		write(STDERR_FILENO, "Error: malloc failed creating node\n", 34);
		return (NULL);
	}
	_strcpy(newnode->name, Name);
	_strcpy(newnode->value, Val);
	newnode->next = NULL;
	return (newnode);
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
		if (_strcmp(temp->name, name) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

/**
 * add_node - add a node to the list
 * @name: the variable
 * @value: the value
 * Return: 0 on success, -1 on failure
*/
int add_node(char *name, char *value)
{
	envlist_t *newnode;
	envlist_t *temp, *exist;

	exist = search_node(name);
	if (exist != NULL)
	{
		free(exist->value);
		exist->value = malloc(sizeof(char) * (_strlen(value) + 1));
		if (!exist->value)
			return (-1);
		_strcpy(exist->value, value);
		return (0);
	}
	newnode = create_node(name, value);
	if (!newnode)
		return (-1);
	temp = get_singleton_list();
	if (!temp)
	{
		envlist = newnode;
		return (0);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = newnode;
	return (0);
}

/**
 * delete_node - delete a node from the list
 * @name: the name of the variable
 * Return: 0 on success, -1 on failure
*/

int delete_node(char *name)
{
	envlist_t *temp = get_singleton_list();
	envlist_t *prev = NULL;

	if (!temp)
		return (-1);
	while (temp && _strcmp(temp->name, name))
	{
		prev = temp;
		temp = temp->next;
	}
	if (!temp)
		return (-1);
	if (!prev)
		envlist = temp->next;
	else
		prev->next = temp->next;
	free(temp->name);
	free(temp->value);
	free(temp);
	return (0);
}
