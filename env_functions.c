#include "main.h"
/**
 * cpy_env - copy the __environ variable into a linked list
*/
void cpy_env(void)
{
	int i = 0, status;
	char *name, *value;

	while (__environ[i])
	{
		name = _strtok(__environ[i], "=");
		value = _strtok(NULL, "=");
		status = add_node(name, value);
		if (status == -1)
		{
			perror("cpy_env");
			return;
		}
		i++;
	}
}

/**
 * _setenv - set an environment variable
 * @name: the name of the variable
 * @value: the value of the variable
 * Return: 0 on success, -1 on failure
*/

int _setenv(char *name, char *value)
{
	envlist_t *temp = search_node(name);
	int status;

	if (temp == NULL)
	{
		status = add_node(name, value);
		if (status == -1)
		{
			perror("setenv");
			return (-1);
		}
		return (0);
	}
	else
	{
		free(temp->value);
		temp->value = malloc(sizeof(char) * (_strlen(value) + 1));
		if (!temp->value)
		{
			perror("setenv");
			return (-1);
		}
		_strcpy(temp->value, value);
		return (0);
	}
}

/**
 * _unsetenv - unset an environment variable
 * @name: the name of the variable
 * Return: 0 on success, -1 on failure
*/
int _unsetenv(char *name)
{
	int status;

	status = delete_node(name);
	if (status == -1)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}
