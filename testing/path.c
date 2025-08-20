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
	char full_path[PATH_MAX]; /* fixed-size buffer for building full_path */

	/* loop through characters in command */
	while (command[counter] != '\0')
	{
		/* does the passed command contain a "/"? (Yes) */
		if (command[counter] == '/')
		{
			if (access(command, X_OK) == 0) /* does the full path to the command exist & is executable? (yes)*/
			{
                printf("DEBUG: Command with '/' found and accessible: %s\n", command);
				return (_strdup(command)); /* return copy of full path for executor to use & free, so original input isn't freed here (because main.c will free this later) */
			}
			else
			{
                printf("DEBUG: Command with '/' not accessible: %s\n", command);
				return (NULL); /* does the full path to the command exist & is executable? (no)*/
			}
		}
		counter++;
	}
	/* does the passed command contain a "/"? (No) - continue*/
	/* get value of environment variable PATH (directories) */
	envpath = getenv("PATH");
    printf("DEBUG: find_in_path - checking command: '%s'\n", command);
    printf("DEBUG: PATH = %s\n", envpath ? envpath : "NULL");


	/* is the value of PATH NULL? (Yes) */
	if (envpath == NULL)
	{
        printf("DEBUG: PATH environment variable is NULL\n");
		return (NULL);
	}
	/* make a copy of envpath to use in strtok */
	envpath_copy = _strdup(envpath);

	/* was strdup successful? (No) */
	if (envpath_copy == NULL)
	{
        printf("DEBUG: PATH environment variable is NULL\n");
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

        printf("DEBUG: Trying path: %s\n", full_path);

		if (access(full_path, X_OK) == 0) /* does command exist & is it executable? (yes) */
		{
            printf("DEBUG: Found executable at: %s\n", full_path);
            char *result = _strdup(full_path);
			free (envpath_copy); /* free copy of PATH */
			return (result); /* return full path */
		}

		directory = strtok(NULL, ":"); /* move to next directory */
	}
    printf("DEBUG: Command not found in any PATH directories: %s\n", command);
	/* does the command exist & is it executable? (No) */
	free(envpath_copy); /* free copy of PATH */
	return (NULL);
}
