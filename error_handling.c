#include "main.h"
#include <stdarg.h>

static int cnt;
/**
 * _itoa - convert integer to string
 * @num: the integer
 * Return: the string
*/
char *_itoa(int num)
{
	int i = 0, j = 0, k = 0;
	char *str = NULL;

	str = malloc(sizeof(char) * 1024);
	if (str == NULL)
		return (NULL);
	if (num == 0)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		return (str);
	}
	while (num)
	{
		j = num % 10;
		num = num / 10;
		str[i] = j + '0';
		i++;
	}
	str[i] = '\0';
	i--;
	while (k < i)
	{
		j = str[i];
		str[i] = str[k];
		str[k] = j;
		k++;
		i--;
	}
	return (str);
}
/**
 * increment_cnt - increment the counter
 * @signum: the signal number
 * Return: void
*/
void increment_cnt(int signum)
{
	UNUSED(signum);
	cnt++;
}
/**
 * print_error - print the error message
 * @sz: the number of arguments
 * @...: the arguments
*/
void print_error(int sz, ...)
{
	char *cnt_str = _itoa(cnt);
	va_list args;
	char *arg = NULL;
	int i = 0;

	write(STDERR_FILENO, "./hsh: ", 7);
	write(STDERR_FILENO, cnt_str, _strlen(cnt_str));
	write(STDERR_FILENO, ": ", 2);
	va_start(args, sz);
	while (i < sz)
	{
		arg = va_arg(args, char *);
		write(STDERR_FILENO, arg, _strlen(arg));
		i++;
	}
	va_end(args);
	free(cnt_str);
}
