#include "shell.h"

/**
 * handle_command - processes and directs user input from main.c
 * @input: user input string
 * @shell_name: name of shell program
 * @line_number: command number
 *
 * Return: void
 */

void handle_command(char *input, char *shell_name, int line_number)
{
	char **args, *full_path, *path;
	int builtin_found;
	size_t len, cmd_len;

	len = strlen(input);
	if (len > 0 && input[len - 1] == '\n')
		input[len - 1] = '\0';
	args = parse_input(input);
	if (args == NULL || args[0] == NULL)
	{
		if (args != NULL)
			free(args);
		return;
	}
	cmd_len = strlen(args[0]);
	if (cmd_len > 0 && args[0][cmd_len - 1] == '\n')
		args[0][cmd_len - 1] = '\0';

	builtin_found = handle_builtin(args, shell_name, line_number);
	if (builtin_found != 0)
	{
		free(args);
		return;
	}
	full_path = find_in_path(args[0]);
	if (full_path == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n",
				shell_name, line_number, args[0]);
		path = _getenv("PATH");
		if (path == NULL || *path == '\0')
			write(STDOUT_FILENO, "OK\n", 3);
		free(args);
		exit(127);
	}
	else
	{
		execute_command(args, full_path);
	}
	free(args);
}
