#include "shell.h"

/**
 * execute_command - executes a command by forking and calling execve
 * @args: array of arguments
 * @command_path: full path to the command library
 *
 * Return: 0 on success
 */

int execute_command(char **args, char *command_path)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		if (execve(command_path, args, environ) == -1)
		{
			perror("execve failed");
			free(command_path);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (1);
	}
	return (0);
}
