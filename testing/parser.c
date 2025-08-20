#include "shell.h"

/**
 * parse_input - tokenizes user input string
 * and stores pointers to each token in an args array
 * @input: user input string
 *
 * Return: NULL terminated args array of pointers (success) or NULL (fail)
 */

char **parse_input(char *input)
{
	char **args;
	int array_size = 50;
	int index = 0;
	char *token;

	if (input[0] == '\0')
	{
		return (NULL);
	}

	args = malloc(sizeof(char *) * array_size);

	if (args == NULL)
	{
		return (NULL);
	}

	token = strtok(input, " ");

	while (token != NULL && index < array_size - 1)
	{
		args[index] = token;
		index++;
		token = strtok(NULL, " ");
	}

	args[index] = NULL;

	return (args);
}
