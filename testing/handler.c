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
    printf("DEBUG: *** ENTERED handle_command() FUNCTION ***\n");
    printf("DEBUG: In handle_command, received input: '%s'\n", input);

	char **args; /* array of tokens/arguments parsed from user input */
	int builtin_found; /* flag to indicate if command is a builtin */

    printf("DEBUG: In handle_command, received input: '%s'\n", input);

    /* Remove trailing newline from input */
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
        input[len - 1] = '\0';

	args = parse_input(input); /* parse user input */

    /* are there any tokens? (No) */
	if (args == NULL || args[0] == NULL)
	{
        printf("DEBUG: No command parsed (args is NULL or empty)\n");
		return;
	}

    size_t cmd_len = strlen(args[0]);
    if (cmd_len > 0 && args[0][cmd_len - 1] == '\n')
    args[0][cmd_len - 1] = '\0';

    printf("DEBUG: First token (args[0]): '%s'\n", args[0]);

	/* are there any tokens? (Yes) */
	/* check if built-in command */
	builtin_found = handle_builtin(args, shell_name, line_number);
    printf("DEBUG: handle_builtin returned: %d\n", builtin_found);

	/* Is it a built-in command? (Yes) */
	if (builtin_found != 0)
	{
		free(args);
		return;
	}
	/* Is it a built-in command? (No) */
	/* Does the command exist? (No) */

    printf("DEBUG: *** about to call find_in_path in handle_command()\n");

    char *full_path = find_in_path(args[0]);
    printf("DEBUG: handle_command: find_in_path('%s') returned: %s\n", args[0], full_path);
    fflush(stdout);

    if (full_path == NULL)
    {
        fprintf(stderr, "%s: %d: %s: not found\n",
                shell_name, line_number, args[0]);
    }
    else
    {
        printf("DEBUG: About to call execute_command with command_path = '%s'\n", full_path);
        fflush(stdout);
        execute_command(args, full_path, shell_name, line_number);
    }

    free(args);
}
