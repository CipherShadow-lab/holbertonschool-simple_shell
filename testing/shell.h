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


/* string helpers */
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);

#endif
