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

int shell_exit(char **argv)
{
    free_array(argv);
    exit(EXIT_SUCCESS);
}
/**
int (*builtins[]) (char **) = {
	    &shell_exit;
	    &shell_cd;
	    &shell_help;
};
*/

/**
 * create_process - creates a child process
 * @argv: array of strings
 * Return: void
 */
int create_process(char **argv)
{
	pid_t pid, wpid;
	int status;

	UNUSED(wpid);
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
