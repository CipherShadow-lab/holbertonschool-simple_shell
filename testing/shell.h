#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Extern global */
extern char **environ;


/* function prototypes */
void handle_command(char *input);
int handle_builtin(char *input);
void print_env(void);

/* string helpers */
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);

#endif
