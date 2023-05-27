#include "main.h"
/**
 * btats - prints the current directory
 * @argv: arguments
 * Return: 0 on failure, 1 on success
*/
int btats(char **argv)
{
	int len = array_2d_len(argv);
	char cwd[1024];

	if (len != 1)
	{
		print_error(3, argv[0], ": too many arguments\n");
		return (0);
	}
	getcwd(cwd, 1024);
	write(STDOUT_FILENO, cwd, _strlen(cwd));
	write(STDOUT_FILENO, "\n", 1);
	return (1);
}
