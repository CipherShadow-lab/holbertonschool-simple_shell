#include "shell.h"

/**
 * execute_command - forks and executes commands
 * @input_command: the inputted command
 * Return: result of the command, or error message
 */

void execute_command(char **input_command)
{
	pid_t child_pid;
	char *command_path;

	/* safety checks: empty or invalid inputs */
	if (input_command == NULL || input_command[0] == NULL)
		return;
	/* new shell is created */
	child_pid = fork();
	/* in case of fork failure */
	if (child_pid == -1)
	{
		fprintf(stderr, "Fork failed\n");
	}
	/* if child process creation was successful */
	else if (child_pid == 0)
	{
		/* finds full command and stores into command path */
		command_path = find_in_path(input_command[0]);
		/* if command cannot be found */
		if (command_path == NULL)
		{
			fprintf(stderr, "./shell: %s not found\n", input_command[0]);
			free_args(input_command);
			exit(EXIT_FAILURE);
		}
		/* executes the command */
		execve(command_path, input_command, environ);
		/* if execve fails */
		fprintf(stderr, "execve failed\n");
		free_args(input_command);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
