#include "shell.h"

/**
 * executeCommand - a function that excute user's input line
 * @arguments: line tokens
 * @argv: arguments vector
 * @errIndex: error index number
 * Return: status
 */

int executeCommand(char **arguments, char **argv, int errIndex)
{
	pid_t exeFork;
	int status;
	char *fullCommandPath = NULL;
	(void)argv;

	fullCommandPath = getFullPath(arguments[0]);
	if (fullCommandPath == NULL)
	{
		handleError(argv[0], arguments[0], errIndex);
		free2DArrayMemory(arguments);
		return (127);
	}

	exeFork = fork();
	if (exeFork == 0)
	{
		if (execve(fullCommandPath, arguments, environ) == -1)
		{
			handleError(argv[0], arguments[0], errIndex);
			free2DArrayMemory(arguments), free1DArrayMemory(fullCommandPath);
			return (127);
		}
	}
	else if (exeFork == -1)
	{
		handleError(argv[0], arguments[0], errIndex);
		free2DArrayMemory(arguments), free1DArrayMemory(fullCommandPath);
		return (127);
	}
	else
	{
		waitpid(exeFork, &status, 0);
		free2DArrayMemory(arguments), free1DArrayMemory(fullCommandPath);
	}

	return (WEXITSTATUS(status));
}
