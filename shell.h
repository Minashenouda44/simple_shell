#ifndef SHELL_H
#define SHELL_H

/* compliation */
/* gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* libraries 4 waitpid */

#include <sys/types.h>
#include <sys/wait.h>

/* library 4 stat */
#include <sys/stat.h>

/* delimeter */

/* include global variables */

extern char **environ;

/* handle inputLine */

char *readLine(void);
char **splitLine(char *Line);
char *getEnv(char *key);
char *getFullPath(char *Command);
int executeCommand(char **arguments, char **argv, int index);
void handleError(char *progName, char *Command, int errindex);

int checkBuiltIn(char **arguments);

/* handle built in */

void handleBuiltIn(char **arguments, char **argv, int status, int index);
void handleExit(char **arguments, char **argv, int status, int index);

void handleEnv(char **environ);

void handleCd(char **arguments, char **argv, int status, int index);

/* features functions */

void free1DArrayMemory(char *array);
void free2DArrayMemory(char **array);

/* string */

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_strdup(char *str);

void _strrev(char *string, int len);
char *int2str(int n);

/* gcc -g -o hsh *.c shell.h */
/* gdb ./hsh */

/* cp hsh /mnt/f/alx/simpleshell/automated_checker/automated_checker */

#endif
