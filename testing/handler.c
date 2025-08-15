#include "shell.h"

/**
 * handle_command - processes and directs user input from main.c
 * @input: user input string (newline already removed)
 *
 * Return: void
 */

void handle_command(char *input)
{
	char **token_array; /* stores array of tokens parsed from user input */
	int builtin_found; /* flag to indicate if command is a builtin */

	token_array = parse_input(input); /* parse user input */

	/* are there any tokens? (No) */
	if (token_array == NULL || token_array[0] == NULL)
	{
		/* TODO: free strings in token array */
		/* TODO: free token array itself */
		return;
	}

	/* are there any tokens? (Yes) */
	/* check if built-in command */
	builtin_found = handle_builtin(token_array);

	/* Is it a built-in command? (Yes) */
	if (builtin_found != 0)
	{
		/* TODO: free strings in token array */
		/* TODO: free token array itself */
		return;
	}
	/* Is it a built-in command? (No) */
	/* Send to execute_command to find and execute command */
	execute_command(token_array);

	/* TODO: free strings in token array */
	/* TODO: free token array itself */
}
