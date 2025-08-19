#include "shell.h"

/**
 * execute_command - forks a child process to execute a command
 * @input: array of command arguments
 * @shell_name: name of shell program
 * @line_number: command line number
 *
 * Return: void
 */

void execute_command(char **args, char *shell_name, int line_number)
{
    pid_t pid;
    int status;
    char *command_path;

    command_path = find_in_path(args[0]);

    if (command_path == NULL)
    {
        /* command not found */
        fprintf(stderr, "%s: %d: %s: not found\n", shell_name, line_number, args[0]);
        return;
    }

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        free(command_path);
        return;
    }

    if (pid == 0)
    {
        /* debug */
        printf("DEBUG: Executing command at path: %s\n", command_path);

        /* child process */
        if (execve(command_path, args, environ) == -1)
        {
            perror(args[0]);
            free(command_path);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* parent process */
        waitpid(pid, &status, 0);
        free(command_path);
    }
}

