#include "shell.h"

/**
 * parse_input - to act as the parser of user input into md and arg.
 *@input: the user input string.
 *@cmd: stores the command.
 *@args: this is an array used to store command arguments.
 */
void parse_input(char *input, char **cmd, char *args[])
{
	size_t c = 0;
	char *token;

	*cmd = strtok(input, " ");
	while ((token = strtok(NULL, " ")) != NULL)
	{
		args[c++] = token;
	}
	args[c] = NULL; /*null terminate the arguments*/
}
