#include "shell.h"

/**
 * print_env - function prints environment variables
 *
 * Return: void
 */

void print_env(void)
{
    int i;

    /* uses global environ and loops until NULL */
    for (i = 0; environ[i] != NULL; i++)
    {
        /* prints out environment variables followed by a newline */
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
}

/**
 * handle_builtin - function handles exit and env commands
 * @input: user-typed input string
 *
 * Return: 1 if builtin handled, otherwise 0
 */

int handle_builtin(char **input, char *shell_name, int line_number)
{
	/* performs strcmp and if both are 0 then shell will exit */
	if (_strcmp(input[0], "exit") == 0)
	{
        if (input[1] != NULL) /* if there is an argument after exit */
        {
            fprintf(stderr, "%s: %d: %s: extra operand '%s'\n", shell_name, line_number, input[0], input[1]);
            fprintf(stderr, "Try '%s --help' for more information.\n", input[0]);
            return (2); /* return 2 for "too many arguments error */
        }

		exit(0); /* if no additional arguments then exit normally */
	}

    /* Handle "env" command */
    else if (_strcmp(input[0], "env") == 0) 
	{
        /* check if "--help" is passed as an argument */
        if (input[1] != NULL && _strcmp(input[1], "--help") == 0)
        {
            fprintf(stdout, "Usage: %s\n", input[0]);
            fprintf(stdout, "Prints the environment variables.\n");
            return 1; /* No error, just help message */
        }

        /* check if any other arguments were provided with env */
        if (input[1] != NULL)
        {
            fprintf(stderr, "%s: %d: %s: extra operand '%s'\n", shell_name, line_number, input[0], input[1]);
            fprintf(stderr, "Try '%s --help' for more information.\n", input[0]);
            return 1; 
        }
        
		print_env();
		
        return (1); /* successfully handled */
	}

	return (0);
}

