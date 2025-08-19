#include "shell.h"

/**
 * find_in_path - checks if a command exists & is executable
 * @command: command name (eg "/bin/ls" or "ls")
 *
 * Return: full path of command (success) NULL (fail)
 */

char *find_in_path(char *command)
{
	int counter = 0; /* counter for looping through command characters*/
	char *envpath; /* store value of PATH */
	char *envpath_copy; /* copy of value of PATH */
	char *directory; /* pointer to individual directories from PATH */
	char full_path[1000]; /* buffer for full path of command */

	/* loop through characters in command */
	while (command[counter] != '\0')
	{
		/* does the passed command contain a "/"? (Yes) */
		if (command[counter] == '/')
		{
			if (access(command, X_OK) == 0) /* does the full path to the command exist & is executable? (yes)*/
			{
				return (_strdup(command)); /* return copy of full path for executor to use & free, so original input isn't freed here (because main.c will free this later) */
			}
			else
			{
				return (NULL); /* does the full path to the command exist & is executable? (no)*/
			}
		}
		counter++;
	}
	/* does the passed command contain a "/"? (No) - continue*/
	/* get value of environment variable PATH (directories) */
	envpath = getenv("PATH");

	/* is the value of PATH NULL? (Yes) */
	if (envpath == NULL)
	{
		return (NULL);
	}
	/* make a copy of envpath to use in strtok */
	envpath_copy = _strdup(envpath);

	/* was strdup successful? (No) */
	if (envpath_copy == NULL)
	{
		return (NULL);
	}

	/* was strdup successful? (Yes) - continue */
	/* tokenise PATH copy with delim ":" */
	directory = strtok(envpath_copy, ":");

	/* loop through each PATH directory */
	while (directory != NULL)
	{
		_strcpy(full_path, directory); /* build full path - start with directory */
		_strcat(full_path, "/"); /* build full path for command - add "/" */
		_strcat(full_path, command); /* build full path for command - add command */

		if (access(full_path, X_OK) == 0) /* does command exist & is it executable? (yes) */
		{
			free (envpath_copy); /* free copy of PATH */
			return (_strdup(full_path)); /* return full path */
		}

		directory = strtok(NULL, ":"); /* move to next directory */
	}
	/* does the command exist & is it executable? (No) */
	free(envpath_copy); /* free copy of PATH */
	return (NULL);
}
