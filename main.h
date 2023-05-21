#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

#define DELIM " \n\r\t\a"
#define BUFFER_SIZE 1024
#define UNUSED(x) (void)(x)
char *copy_str(char *source, char *dist, int start, int end);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strtok(char *str, char *delim);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);

char **split_string(char *str, char *delim);
char *read_line();
int create_process(char **argv);

char *copy_str(char *source, char *dist, int start, int end);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _getline(char **lineptr, size_t *n, FILE* stream);
void execmd(char **argv);

void free_string(char *str);
void free_array(char **array);

/**
typedef struct node
{
	bool is_2d_array;
	void *data;
	struct node *next;
} node_t;

node_t *get_singleton_list();
node_t *add_node(node_t *head, void *data, bool is_2d_array);
void free_list(node_t *head);
void free_nodes(node_t *head);
*/

int shell_exit(char **args);
int shell_cd(char **args);
int shell_env(char **args);

char *get_location(char *command);
char *_getenv(char *name);
#endif
