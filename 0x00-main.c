#include "shell.h"

/**
 * main - entry point to the simple shell alx project
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char *inputline = NULL;
	char **arguments = NULL;
	int status = 0;
	int errIndeX = 0;

	int checkCommand = 0;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		inputline = readLine();

		if (inputline == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		errIndeX++;

		arguments = splitLine(inputline);
		if (arguments == NULL)
			continue;

		checkCommand = checkBuiltIn(arguments);

		if (checkCommand == 1)
			handleBuiltIn(arguments, argv, status, errIndeX);
		else
			status = executeCommand(arguments, argv, errIndeX);
	}
}
