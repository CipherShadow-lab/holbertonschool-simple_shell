#include "shell.h"

/**
 * execute_command - forks and executes commands
 * @input_command: the inputted command
 * Return: result of the command, or error message
 */

int execute_command(char **input_command)
{
	pid_t child_pid;
	char *command_path;
	int status;

	/* safety checks: empty or invalid inputs */
	if (input_command == NULL || input_command[0] == NULL)
	{
		return (-1);
	}
	child_pid = fork(); /* new child process created */

	if (child_pid == -1) /* in case of forking failure */
	{
		perror("Fork failed");
		return (-1);
	}
	else if (child_pid == 0) /* if forking process success */
	{
		command_path = find_in_path(input_command[0]); /* searching for command */
		if (command_path == NULL) /* if command cannot be found */
		{
			fprintf(stderr, "shell: %s not found\n", input_command[0]);
			free_args(input_command);
			exit(EXIT_FAILURE);
		}
		execve(command_path, input_command, environ); /* execute the command */
		perror("execve failed"); /* if execve fails */
		free(command_path);
		free_args(input_command);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status); /* parent will wait for child */
		if (WIFEXITED(status)) /* if child exit was success, return exit code */
			return (WEXITSTATUS(status));
		else /* if child exit was failure, return -1 */
			return (-1);
	}
}
