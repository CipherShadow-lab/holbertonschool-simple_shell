#include "shell.h"

/**
 * clean_exit - cleans getline betfore exiting
 * @line: line to clean
 * @args: arguments
 * @status: exit status
 *
 * Return: void
 */

void clean_exit(char *line, char **args, int status)
{
	if (args)
		free_args(args);
	if (line)
		free(line);
	exit(status);
}
