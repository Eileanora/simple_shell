#include "main.h"

static node_t *singleton_list = NULL;

node_t *get_singleton_list()
{
	if (singleton_list == NULL)
	{
		singleton_list = malloc(sizeof(node_t));
		singleton_list->is_2d_array = false;
		singleton_list->data = NULL;
		singleton_list->next = NULL;
	}
	return singleton_list;
}

node_t *add_node(node_t *head, void *data, bool is_2d_array)
{
	node_t *new_node = malloc(sizeof(node_t));
	new_node->is_2d_array = is_2d_array;
	new_node->data = data;
	new_node->next = head;
	return new_node;
}

void free_list(node_t *head)
{
	node_t *tmp;
	int i;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		if (tmp->is_2d_array)
		{
			char **data = (char **)tmp->data;
			for (i = 0; data[i] != NULL; i++)
				free(data[i]);
		free(data);
		}
		else
		{
		    free(tmp->data);
		}
		free(tmp);
	}
}
void free_nodes(node_t *head)
{
	node_t *tmp;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	
}