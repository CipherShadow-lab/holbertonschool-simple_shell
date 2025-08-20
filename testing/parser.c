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
	char **args; /* array of pointers to tokens/arguments */
	int array_size = 50; /* current upper limit */
	int index = 0; /* index position counter for args array */
	char *token; /* pointer to current token in input */

/* check if first character of input is a null terminator */
	if (input[0] == '\0')
	{
/* is input empty? Yes */
		return (NULL);
	}
/* is input empty? No - continue */

/* allocate memory for args array */
	args = malloc(sizeof(char *) * array_size);

/* is malloc successful? No */
	if (args == NULL)
	{
		return (NULL);
	}
/* is malloc successful? Yes - continue */

/* tokenize input */
/* store tokens in args array */
	token = strtok(input, " ");

/*loop while there are tokens & array space (reserve last slot for NULL)*/
	while (token != NULL && index < array_size - 1)
	{
        printf("DEBUG: parse_input - token[%d]: '%s'\n", index, token);
		args[index] = token;
		index++;
		token = strtok(NULL, " ");
	}

/* add NULL to end of args array */
	args[index] = NULL;

    printf("DEBUG: parse_input - total tokens: %d\n", index);
    return (args);
}
