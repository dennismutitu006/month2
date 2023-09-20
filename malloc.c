#include "shell.h"
/**
 * execute_command1 - it allocates memory and executes commands
 * @cmd: the command to be executed
 * @args: argumnets to be passed.
 */
void execute_command1(const char *cmd, char *const args[])
{
	char **new_argv = malloc(2 * sizeof(char *));

	if (new_argv == NULL)
	{
		perror("Malloc error:");
		exit(1);
	}

	new_argv[0] = (char *)cmd;
	new_argv[1] = NULL;

	if (execve(cmd, args, NULL) == -1)
	{
		perror("Exec error:");
		exit(1);
	}
free(new_argv);
}
