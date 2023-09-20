#include "shell.h"
/**
 * main - a simple shell.
 * Return: Always 0
 */
int main(void)
{
	pid_t childPid;
	int s;
	size_t size, len = 0;
	char *args[MAX_ARG_LENGTH], *cmd, *input = NULL;
	char *new_argv[2];

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2); /*displaying a prompt*/
		if (getline(&input, &len, stdin) == -1)
			break;/*exit the shell (EOF)*/
		size = _strlen(input);/*find the last character in input(nl)*/
		if (size > 0 && input[size - 1] == '\n')
		{
			input[size - 1] = '\0';/*replace newline character*/
		}
		parse_input(input, &cmd, args);
		/*if (_strcmp(cmd, "exit") == 0)
			break;*/
		childPid = fork();
		if (childPid == -1)
		{
			perror("Fork Error:");
			exit(1);
		}
		if (childPid == 0)
		{
			new_argv[0] = cmd;
			new_argv[1] = NULL;

			execute_command1(cmd, new_argv);
		} else
		{
			wait(&s); /*wait for the child*/
		}
	} free(input);
	return (0);
}
