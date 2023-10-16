#include "shell.h"

/**
 * handleError - a function that handle errors
 * @progName: program name
 * @CommandName: command name
 * @errIndex: error index number
 * Return: void
 */

void handleError(char *progName, char *CommandName, int errIndex)
{
	char *idx;
	char message[] = "not found";

	/* progName: errIndex: CommandName: notfound */
	/* ./hsh: 1: CommandName: notfound */
	/* progName = argv[0] */
	/* CommandName = arguments[0] */

	idx = int2str(errIndex);

	write(STDERR_FILENO, progName, _strlen(progName));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, CommandName, _strlen(CommandName));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, "\n", 1);

	free1DArrayMemory(idx);
}

/**
 * handleCdError - a function that handle cd errors
 * @progName: program name
 * @CmdName: command name
 * @CmdArg: command arg
 * @errIndex: error index number
 * Return: void
 */

void handleCdError(char *progName, char **arguments, int errIndex)
{
	char *idx;
	char message[] = "can't cd to ";

	/* progName: errIndex: CommandName: notfound */
	/* ./hsh: 1: CommandName: can't cd to  */
	/* progName = argv[0] */
	/* CommandName = arguments[0] */
	/* CommandArg = arguments[1] */

	idx = int2str(errIndex);

	write(STDERR_FILENO, progName, _strlen(progName));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, arguments[0], _strlen(arguments[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, arguments[1], _strlen(arguments[1]));
	write(STDERR_FILENO, "\n", 1);

	free1DArrayMemory(idx);
}

/**
 * handleFileError - a function that handle file errors
 * @progName: program name
 * @arguments: command arg
 * @errIndex: error index number
 * Return: void
 */

void handleFileError(char *progName, char **arguments, int errIndex)
{
	char *idx;
	char message[] = "Can't open ";

	/* progName: errIndex: CommandName: notfound */
	/* ./hsh: 1: CommandName: can't open  */
	/* progName = argv[0] */
	/* CommandName = arguments[0] */
	/* CommandArg = arguments[1] */

	idx = int2str(errIndex);

	write(STDERR_FILENO, progName, _strlen(progName));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, arguments[1], _strlen(arguments[1]));
	write(STDERR_FILENO, "\n", 1);

	free1DArrayMemory(idx);
}
