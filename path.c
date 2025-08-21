#include "shell.h"

/**
 * find_in_path - checks if a command exists & is executable
 * @command: command name (eg "/bin/ls" or "ls")
 *
 * Return: full path of command (success) NULL (fail)
 */

char *find_in_path(char *command)
{
	int counter = 0;
	char *envpath, *envpath_copy, *directory, *result, full_path[PATH_MAX];

	while (command[counter] != '\0')
	{
		if (command[counter] == '/')
		{
			if (access(command, X_OK) == 0)
			{
				return (_strdup(command));
			}
			return (NULL);
		}
		counter++;
	}
	envpath = _getenv("PATH");
	if (envpath == NULL || envpath[0] == '\0')
		return (NULL);

	envpath_copy = _strdup(envpath);
	if (envpath_copy == NULL)
		return (NULL);

	directory = strtok(envpath_copy, ":");
	while (directory != NULL)
	{
		_strcpy(full_path, directory);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			result = _strdup(full_path);
			free(envpath_copy);
			return (result);
		}
		directory = strtok(NULL, ":");
	}
	free(envpath_copy);
	return (NULL);
}
