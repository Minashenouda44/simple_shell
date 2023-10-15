#include "shell.h"

/**
 * checkBuiltIn - a function that checkCommand is BuiltIn Command or not
 * @arguments: arguments
 * Return: 0 on success
 */
int checkBuiltIn(char **arguments)
{
	unsigned int i = 0;
	char *builtIn[] = {"exit", "env", "cd", NULL};

	for (i = 0; builtIn[i]; i++)
	{
		if (_strcmp(arguments[0], builtIn[i]) == 0)
			return (1);
	}

	return (0);
}

/**
 * handleBuiltIn - a function that handle shell BuiltIn Commands
 * @arguments: arguments
 * @argv: arguments vector
 * @status: execution statues
 * @errIndeX: error number
 * Return: void
 */

void handleBuiltIn(char **arguments, char **argv, int status, int errIndeX)
{

	if (_strcmp(arguments[0], "exit") == 0)
		handleExit(arguments, argv, status, errIndeX);

	else if (_strcmp(arguments[0], "env") == 0)
	{
		free2DArrayMemory(arguments);
		handleEnv(environ);
	}

	else if (_strcmp(arguments[0], "cd") == 0)
		handleCd(arguments, argv, status, errIndeX);

	else
		handleError(argv[0], arguments[0], errIndeX);
}

/**
 * handleExit - a function that handle shell exit command
 * @arguments: arguments
 * @argv: arguments vector
 * @status: execution statues
 * @errIndeX: error number
 * Return: void
 */

void handleExit(char **arguments, char **argv, int status, int errIndeX)
{
	(void)argv;
	(void)errIndeX;

	free2DArrayMemory(arguments);
	exit(status);
}

/**
 * handleEnv - a function that handle shell env command
 * @environ: environ
 * Return: void
 */

void handleEnv(char **environ)
{
	unsigned int i = 0;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * handleCd - a function that handle shell cd command
 * @arguments: arguments
 * @argv: arguments vector
 * @status: execution statues
 * @errIndeX: error number
 * Return: void
 */

void handleCd(char **arguments, char **argv, int status, int errIndeX)
{
	char *cwdDir = NULL;
	char *newDir = NULL;

	(void)status;

	if (arguments[1] == NULL)
		newDir = getEnv("HOME");
	else if (_strcmp(arguments[1], "-") == 0)
	{
		newDir = getEnv("OLDPWD");
		write(STDOUT_FILENO, newDir, _strlen(newDir));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
		newDir = arguments[1];

	cwdDir = getcwd(NULL, 0);

	if (chdir(newDir) == 0)
	{
		setenv("PWD", newDir, 1);
		setenv("OLDPWD", cwdDir, 1);
	}
	else
	{
		handleCdError(argv[0], arguments[0], arguments[1], errIndeX);
		free2DArrayMemory(arguments);
		free1DArrayMemory(newDir);
		return;
	}
	free1DArrayMemory(newDir);
	free1DArrayMemory(cwdDir);
	free2DArrayMemory(arguments);
}
