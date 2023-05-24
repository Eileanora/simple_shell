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
 * add_node - add a node to the list
 * @val: the value of env variable
 * Return: 1 on success, 0 on failure
*/
int add_node(char *val)
{
	envlist_t *newnode, *temp;

	newnode = create_node(val);
	if (!newnode)
		return (0);
	temp = get_singleton_list();
	if (!temp)
	{
		envlist = newnode;
		return (1);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = newnode;
	return (1);
}

/**
 * delete_node - delete a node from the list
 * @name: the name of the variable
 * Return: 1 on success, 0 on failure
*/
int delete_node(char *name)
{
	envlist_t *temp = get_singleton_list();
	envlist_t *prev = NULL;

	if (!temp)
		return (0);
	while (temp && strcmp_sign(temp->value, name, '=') != 0)
	{
		prev = temp;
		temp = temp->next;
	}
	if (!temp)
		return (0);
	if (!prev)
		envlist = temp->next;
	else
		prev->next = temp->next;
	free(temp->value);
	free(temp);
	return (1);
}
