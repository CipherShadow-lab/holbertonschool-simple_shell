#include "shell.h"

/**
 * execute_command - executes a command by forking and calling execve
 * @args: array of arguments
 * @command_path: full path to the command library
 * @shell_name: name of shell program
 * @line_number: line number in session or script
 *
 * Return: void
 */

void execute_command(char **args, char *command_path)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		free(command_path);
		return;
	}

	if (pid == 0)
	{
		if (execve(command_path, args, environ) == -1)
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free(command_path);
	}
}
