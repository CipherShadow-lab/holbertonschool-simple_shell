#include "shell.h"

/**
 * main - the main entry point for the simple shell program
 *
 * Return: 0 on success
 */

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t = read;

	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			write(STDOUT_FILENO, "$ ", 2);

		read = getline(&input, &len, stdin);

		if (read == -1)
		{
			if (is_interactive)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (input(read - 1) == '\n')
			input(read - 1) = '\0';

		handle_command(input);
	}

	free(input);
	return (0);
}
