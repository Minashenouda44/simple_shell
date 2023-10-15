#include "shell.h"

/**
 * readLine - a function that reads user's inputs from stdin or stream
 *
 *
 * Return: line on success - NULL on failure
 */

char *readLine()
{
	FILE *stream;
	char *line = NULL;
	size_t len;
	ssize_t nread;

	stream = stdin;

	nread = getline(&line, &len, stream);
	if (nread == -1)
	{
		free1DArrayMemory(line);
		return (NULL);
	}

	return (line);
}
