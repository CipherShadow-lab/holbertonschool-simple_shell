#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

/* Extern global */
extern char **environ;


/* function prototypes */
void handle_command(char *input, char *shell_name, int line_number);
int handle_builtin(char **input, char *shell_name, int line_number);
void print_env(void);
char **parse_input(char *input);
void execute_command(char **input_command);
char *find_in_path(char *command);

/* string helpers */
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strchr(const char *s, int c);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);

#endif
