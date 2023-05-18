#include "main.h"
/**
 * copy_str - copies a string
 * @source: source string
 * @dist: destination string
 * @start: starting index (for lineptr)
 * @end: ending index (for buffer)
 * Return: pointer to the new string
*/
char *copy_str(char *source, char *dist, int start, int end)
{
	int i = 0;

	for (i = 0; i <= end; i++)
		dist[start++] = source[i];

	dist[start] = '\0';
	return (dist);
}
/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: pointer to the newly allocated memory
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ans;
	unsigned int i, sz;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	ans  = malloc(new_size);
	if (ans == NULL)
		return (NULL);
	if (ptr == NULL)
		return (ans);


	sz = old_size < new_size ? old_size : new_size;
	for (i = 0; i < sz; i++)
		ans[i] = ((char *)ptr)[i];

	if (ptr != NULL)
		free(ptr);
	return (ans);
}
/**
 * _getline - reads an entire line from a file stream
 * @lineptr: pointer to a string to read into
 * @n: pointer to a variable holding the size of the string
 * @stream: file stream to read from
 * Return: number of bytes read, or -1 on failure
*/
int _getline(char **lineptr, size_t *n, FILE* stream)
{
	static char BUFFER[BUFFER_SIZE];
	static size_t r, line_size;
	int i;
	
	line_size = 1;
	if (*lineptr == NULL)
	{
		*lineptr = malloc(line_size);
		if (*lineptr == NULL)
			return (-1);
	}

	while (1)
	{
		r = read(fileno(stream), BUFFER, BUFFER_SIZE);
		if (r <= 0)
		{
			/* free(*lineptr); */
			return (r);
		}
		i = 0;
		while (BUFFER[i])
		{
			if (BUFFER[i] == '\n' || BUFFER[i] == EOF || i == 1023)
			{

				*lineptr = _realloc(*lineptr, line_size, line_size + i + 1);
				break;
			}
			i++;
		}
		copy_str(BUFFER, *lineptr, line_size - 1, i);
		line_size += i;
		if (r != BUFFER_SIZE)
			break;
	}

	/* (*lineptr)[line_size + 1] = '\0'; */
	*n = line_size;
	return (line_size);
}
/**
// 1 - getline function have three parameters
//     - char **lineptr: pointer to a string to read into
//     - size_t *n: pointer to a variable holding the size of the string 
// 	- on faliure -> returns -1 otherwise returns the number of bytes read
//     - FILE *stream: pointer to a file stream to read from
//     - getline returns int -> number of bytes read or -1 on failure
*/