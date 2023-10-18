#include "shell.h"

/**
 * splitLine - a function that split a line into tokens
 * @line: line
 *
 * Return: tokens on success
 */

char **splitLine(char *line)
{
	char *delim = " \t\n";
	char *token = NULL, **arguments = NULL;
	char *tempLine = NULL;
	unsigned int i = 0;

	if (line == NULL)
		return (NULL);

	tempLine = _strdup(line);
	if (tempLine == NULL)
	{
		free1D(line);
		return (NULL);
	}
	token = strtok(tempLine, delim);
	if (token == NULL)
	{
		free1D(tempLine), free1D(line);
		return (NULL);
	}
	arguments = malloc(sizeof(char *) * 256);
	if (arguments == NULL)
	{
		free1D(tempLine), free1D(line);
		return (NULL);
	}
	while (token)
	{
		arguments[i++] = _strdup(token);
		token = strtok(NULL, delim);
	}
	arguments[i] = NULL;

	free1D(tempLine), free1D(line);
	return (arguments);
}
