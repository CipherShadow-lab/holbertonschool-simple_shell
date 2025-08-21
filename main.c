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
 * handle_sigint - handles hotkeys like CTRL+C
 * @sig: signal input (C) received
 *
 * Return: void
 */

void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n💀 > ", 8);
	fflush(stdout);
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

	signal(SIGINT, handle_sigint);

	is_interactive = isatty(STDIN_FILENO);
	if (is_interactive)
		print_banner();
	while (1)
	{
		if (is_interactive)
		{
			write(STDOUT_FILENO, "\n💀 > ", 8);
			fflush(stdout);
		}

		read = getline(&input, &len, stdin);
		if (read == -1)
		{
			if (is_interactive)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (input[read - 1] == '\n')
			input[read - 1] = '\0';
		line_number++;
		if (_strcmp(input, "exit") == 0)
		{
			write(STDOUT_FILENO, "OK", 2);
			free(input);
			exit(0);
		}
		handle_command(input, shell_name, line_number);
	}
	free(input);
	return (0);
}
