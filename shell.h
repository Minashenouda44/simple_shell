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

/* open file */
#include <fcntl.h>

/* delimeter */

/* include global variables */

extern char **environ;

/* handle inputLine */

char *readLine(void);
char **splitLine(char *Line);
char *getEnv(char *key);
char *getFullPath(char *Command);

void handleFile(char **argv);
int executeCommand(char **arguments, char **argv, int errIndeX);

int checkBuiltIn(char **arguments);
void handleBuiltIn(char **arguments, char **argv, int *status, int errIndeX);

void handleCd(char **arguments, char **argv, int *status, int errIndeX);
void handleEnv(char **arguments, char **argv, int *status, int errIndeX);
void handleExit(char **arguments, char **argv, int *status, int errIndeX);
void handleSetEnv(char **arguments, char **argv, int *status, int errIndeX);
void handleUnsetEnv(char **arguments, char **argv, int *status, int errIndeX);

void handleError(char *progName, char *Command, int errindex);
void handleCdError(char *progName, char **arguments, int errIndex);
void handleFileError(char *progName, char **arguments, int errIndex);
void handleExitError(char *progName, char **arguments, int errIndex);
/* handle built in */

/* features functions */

void free1D(char *array);
void free2D(char **array);

/* string */

int _strlen(char *s);
char *int2str(int n);
int _atoi(char *str);
char *_strdup(char *str);
int isPositive(char *str);
int _strcmp(char *s1, char *s2);
void _strrev(char *string, int len);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);

/* gcc -g -o hsh *.c shell.h */
/* gdb ./hsh */

/* cp hsh /mnt/f/alx/simpleshell/automated_checker/automated_checker */

#endif
