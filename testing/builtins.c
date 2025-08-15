#include "shell.h"

/**
 * handle_builtin - function handles exit and env commands
 * @input: user-typed input
 *
 * Return: 0 on success
 */

int handle_builtin(char *input)
{
	/* performs strcmp and if both are 0 then shell will exit */
	if (_strcmp(input, "exit") == 0)
	{
		exit(0);
	}
	/* performs strcmp and if both equal 0 then print_env() is called */
	else if (_strcmp(input, "env") == 0) 
	{
		print_env();
		return (1);
	}

	return (0);
}

/**
 * print_env - function prints environment variables
 *
 * Return: void
 */

void print_env(void)
{
	int i;

	/* uses global environ and loops until NULL */
	for (i = 0; environ[i] != NULL; i++)
	{
		/* prints out environment variables followed by newline */
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
