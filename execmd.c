#include "main.h"
/**
 * execmd - execute the command with execve
 * @argv: array of strings
 * Return: void
 */
void execmd(char **argv){
    char *command = NULL;

    if (argv){
        /* get the command */
        command = argv[0];

        /* execute the command with execve */
        if (execve(command, argv, NULL) == -1){
            perror("Error");
        };
    }

}


int (*builtins[]) (char **) = {
	    &shell_exit,
	    &shell_cd
};

/**
 * create_process - creates a child process
 * @argv: array of strings
 * Return: void
 */
int create_process(char **argv)
{
	pid_t pid, wpid;
	int status, i;
	char *builein_str[] = {"exit", "cd"};

	UNUSED(wpid);
	for (i = 0; builein_str[i]; i++)
		if (_strcmp(argv[0], builein_str[i]) == 0)
			return ((*builtins[i])(argv));

	pid = fork();
	if (pid == 0)/* child created successfully */
	{
		execmd(argv);
		perror("Error");
		free_array(argv);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)/* error creating the child */
	{
		perror("Error");
	}
	else/* parent process */
	{
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
