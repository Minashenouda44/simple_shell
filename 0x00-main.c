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

	while (1)
	{
		if (argc == 2)
		{
			handleFile(argv);
			return (0);
		}

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
			handleBuiltIn(arguments, argv, &status, errIndeX);
		else
			status = executeCommand(arguments, argv, errIndeX);
	}
}

/**
 * handleFile - a function that handle a file as a command line argument
 * @argv: argument vector
 * Return: void
 */

void handleFile(char **argv)
{
	int fd = 0;
	ssize_t nread = 0;
	char *line = NULL;
	size_t nbyte = 256;
	char **arguments = NULL;
	int status = 0;
	int errIndeX = 0;
	int checkCommand = 0;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		handleFileError(argv[0], argv, errIndeX);
		exit(127);
	}
	line = malloc(sizeof(char) * nbyte);
	nread = read(fd, line, nbyte);
	if (nread == -1)
	{
		free1D(line);
		handleFileError(argv[0], argv, errIndeX);
		exit(127);
	}
	close(fd);
	if (line == NULL)
	{
		handleFileError(argv[0], argv, errIndeX);
		close(fd);
		exit(127);
	}
	arguments = splitLine(line);
	if (arguments)
	{
		checkCommand = checkBuiltIn(arguments);

		if (checkCommand == 1)
			handleBuiltIn(arguments, argv, &status, errIndeX);
		else
			status = executeCommand(arguments, argv, errIndeX);
	}
}
