#include "main.h"

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
	while (temp->next)
		temp = temp->next;
	temp->next = newnode;
	return (1);
}
/**
 * replace_node - replace a node in the list
 * @name: the name of the variable
 * @value: the value of the variable
 * Return: 1 on success, 0 on failure
 * Note: if the node doesn't exist, it will be created
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
