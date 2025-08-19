#include "shell.h"

/**
 * print_banner - function prints ascii banner when program runs
 *
 * Return: void
 */

void print_banner(void)
{
	printf("\033[0;31m");

	printf(" ___  ___  ________  ___  ___     \n");
	usleep(50000);
	printf("|\\  \\|\\  \\|\\   ____\\|\\  \\|\\  \\    \n");
	usleep(50000);
	printf("\\ \\  \\\\\\  \\ \\  \\___|\\ \\  \\\\\\  \\   \n");
	usleep(50000);
	printf(" \\ \\   __  \\ \\_____  \\ \\   __  \\  \n");
	usleep(50000);
	printf("  \\ \\  \\ \\  \\|____|\\  \\ \\  \\ \\  \\ \n");
	usleep(50000);
	printf("   \\ \\__\\ \\__\\____\\_\\  \\ \\__\\ \\__\\\n");
	usleep(50000);
	printf("    \\|__|\\|__|\\_________\\|__|\\|__|\n");
	usleep(50000);
	printf("             \\|_________|        \n\n");
	usleep(60000);

	printf("\033[0;31m");
	printf("         Holberton Simple Shell\n\n");

	printf("\033[0m");
}

/**
 * main - the main entry point for the simple shell program
 *
 * Return: 0 on success
 */

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;
	int is_interactive, line_number = 0;
	char *shell_name = "./hsh";

	/* isatty is either 0 (non-interactive) or 1 (interactive) */
	is_interactive = isatty(STDIN_FILENO);

	if (is_interactive) /* banner only works for interactive mode */
		print_banner();

	while (1)
	{
		/* if isatty is 1 (interactive) present prompt */
		if (is_interactive)
			write(STDOUT_FILENO, "💀 > ", 7);
            fflush(stdout);

		/* read value == typed command or script file */
		read = getline(&input, &len, stdin);

		/* if user enters CTRL+D or EOF is reached */
		if (read == -1)
		{
			if (is_interactive)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (input[read - 1] == '\n') /* checks if last char is \n */
			input[read - 1] = '\0'; /* replaces it with a null-terminator */

		line_number++;
		handle_command(input, shell_name, line_number);
	}

	free(input);
	return (0);
}
