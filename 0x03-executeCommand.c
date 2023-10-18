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
	int i = 0;

	(void)argv;

	for (i = 0; arguments[i]; i++)
	{

		fullCommandPath = getFullPath(arguments[i]);
		if (fullCommandPath == NULL)
		{
			handleError(argv[0], arguments[i], errIndex);
			return (127);
		}

		exeFork = fork();
		if (exeFork == 0)
		{
			if (execve(fullCommandPath, arguments, environ) == -1)
			{
				handleError(argv[0], arguments[i], errIndex);
				free1D(fullCommandPath);
				return (127);
			}
		}
		else if (exeFork == -1)
		{
			handleError(argv[0], arguments[i], errIndex);
			free1D(fullCommandPath);
			return (127);
		}
		else
		{
			waitpid(exeFork, &status, 0);
			free1D(fullCommandPath);
		}
		return (WEXITSTATUS(status));
	}
	return (WEXITSTATUS(status));
}
