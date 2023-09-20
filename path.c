#include "shell.h"
/**
* execute_command -  This function handles PATH
* @command_line: Pointer to char which reads the command passed
* to the command line
*
* Return: Nothing (void return type)
*/
void execute_command(const char *command_line)
{
	char *args[3];/*This array stores a command and its arguments*/
	pid_t pid;
	int status;

	args[0] = "/bin/sh";
	args[1] = "-c";
	args[2] = (char *)command_line;
	/*Fork a new process to execute the command*/
	pid = fork();
	if (pid < 0)
		perror("fork");
	else if (pid == 0)
	{
	/*This execution block is for child process*/
	/*Execute the command using execve with PATH*/
		if (execve("/bin/sh", args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	} else
	{
		/*This execution block is for parent process*/
		/*Wait until the child process is completed*/
		wait(&status);
	}
}
/**
* main - Main function
*
* Return: 0 (Code success)
*/
int main(void)
{
	char command_line[1024];
	size_t len;

	while (1)
	{
		_printf("MyShell> ");
		if (_fgets(command_line, sizeof(command_line), STDIN_FILENO) == NULL)
			break;
		/* This removes the trailing newline character*/
		len = _strlen(command_line);
		if (len > 0 && command_line[len - 1])
			command_line[len - 1] = '\0';
		execute_command(command_line);
	}
	return (0);
}
