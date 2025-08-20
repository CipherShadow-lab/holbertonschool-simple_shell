#include "shell.h"

void execute_command(char **args, char *command_path, char *shell_name, int line_number)
{
    pid_t pid;
    int status;

    printf("DEBUG: execute_command: forking to run '%s'\n", command_path);
    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        free(command_path);
        return;
    }

    if (pid == 0)
    {
        printf("DEBUG: args passed to execve:\n");
        for (int i = 0; args[i] != NULL; i++)
            printf("  args[%d]: '%s'\n", i, args[i]);
        // Child process
        if (execve(command_path, args, environ) == -1)
        {
            perror("execve failed");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // Parent process
        waitpid(pid, &status, 0);
        printf("DEBUG: Parent process: child finished with status %d\n", status);
        free(command_path);
    }
}

