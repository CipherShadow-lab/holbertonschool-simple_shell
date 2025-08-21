#include "shell.h"

/**
 * handle_command - processes and directs user input from main.c
 * @input: user input string
 * @shell_name: name of shell program
 * @line_number: command number
 * @last_status: last exit status
 *
 * Return: void
 */

void handle_command(char *input, char *shell_name,
		int line_number, int *last_status)
{
	char **args, *full_path;
	int builtin_found;
	size_t len;

	len = strlen(input);
	if (len > 0 && input[len - 1] == '\n')
		input[len - 1] = '\0';

	args = parse_input(input);
	if (args == NULL || args[0] == NULL)
	{
		free_args(args);
		return;
	}

	builtin_found = handle_builtin(args, shell_name, line_number);

	if (builtin_found == 2 || builtin_found == 3)
		process_builtin_exit(builtin_found, args, *last_status);

	if (builtin_found == 1)
	{
		*last_status = 0;
		free_args(args);
		return;
	}

	full_path = find_in_path(args[0]);
	if (full_path == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n",
				shell_name, line_number, args[0]);

		*last_status = 127;
		free_args(args);
		return;
	}
	*last_status = execute_command(args, full_path);
	free(full_path);
	free_args(args);
}
