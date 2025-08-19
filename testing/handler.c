#include "shell.h"

/**
 * handle_command - processes and directs user input from main.c
 * @input: user input string (newline already removed)
 * @shell_name: name of shell program
 * @line_number: command number (used for error messages)
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
		free(args);
		return;
	}
	/* are there any tokens? (Yes) */
	/* check if built-in command */
	builtin_found = handle_builtin(args, shell_name, line_number);

	/* Is it a built-in command? (Yes) */
	if (builtin_found != 0)
	{
		free(args);
		return;
	}
	/* Is it a built-in command? (No) */
	/* Does the command exist? (No) */
	if (find_in_path(args[0]) == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n",
				shell_name, line_number, args[0]);
	}
	/* Does the command exist? (Yes) */
	/* Send to execute_command to find and execute command */
	else
	{
		execute_command(args, shell_name, line_number);

		free(args);
	}
}
