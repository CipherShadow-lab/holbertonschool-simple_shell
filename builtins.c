#include "shell.h"

/**
 * print_env - function prints environment variables
 *
 * Return: void
 */

void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	printf("\n");
}


/**
 * handle_builtin - function handles exit and env commands
 * @input: user-typed input string
 * @shell_name: name of running shell
 * @line_number: line number of entered command
 *
 * Return: 1 if builtin handled, otherwise 0
 */

int handle_builtin(char **input, char *shell_name, int line_number)
{
	char cwd[1024], *path;
	int i;

	if (_strcmp(input[0], "exit") == 0)
	{
		if (input[1])
			fprintf(stderr, "%s: %d: exit: extra operand '%s'\n",
					shell_name, line_number, input[1]);
		exit(0);
	}
	else if (_strcmp(input[0], "env") == 0)
	{
		if (input[1])
		{
			fprintf(stderr, "%s: %d: env: extra operand '%s'\n",
					shell_name, line_number, input[1]);
			return (1);
		}
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		return (1);
	}
	else if (_strcmp(input[0], "cd") == 0)
	{
		if (input[1] != NULL)
			path = input[1];
		else
			path = getenv("HOME");
		if (chdir(path) != 0)
			fprintf(stderr, "%s: %d: cd: can't cd to %s\n",
					shell_name, line_number, path);
		return (1);
	}
	else if (_strcmp(input[0], "clear") == 0)
	{
		write(STDOUT_FILENO, "\033[H\033[J", 6);
		return (1);
	}
	return (0);
}
