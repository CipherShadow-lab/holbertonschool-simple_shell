#include "shell.h"

/**
 * handle_command - processes and directs user input from main.c
 * @input: user input string (newline already removed)
 *
 * Return: void
 */

void handle_command(char *input, char *shell_name, int line_number)
{
	char **args; /* array of tokens/arguments parsed from user input */
	int builtin_found; /* flag to indicate if command is a builtin */

	args = parse_input(input); /* parse user input */

	/* are there any tokens? (No) */
	if (args == NULL || args[0] == NULL)
	{
		/* TODO: free args array */
		return;
	}

	/* are there any tokens? (Yes) */
	/* check if built-in command */
	builtin_found = handle_builtin(args, shell_name, line_number);

	/* Is it a built-in command? (Yes) */
	if (builtin_found != 0)
	{
		/* TODO: free args array */
		return;
	}
	/* Is it a built-in command? (No) */
	/* Send to execute_command to find and execute command */
	execute_command(args, shell_name, line_number);

	/* TODO: free args array */
}
