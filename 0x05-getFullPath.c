#include "shell.h"

/**
 * getFullPath - a fuction that return the fullPath for a given Command
 * @Command: input command
 * Return: fullPath on success
 */

char *getFullPath(char *Command)
{
	struct stat st;
	char *envPathValue = NULL, *path = NULL;
	char *fullCommandPath = NULL;
	char *key = "PATH";

	if (Command == NULL)
		return (NULL);
	if (stat(Command, &st) == 0)
		return (_strdup(Command));

	envPathValue = getEnv(key);
	if (envPathValue == NULL)
		return (NULL);
	path = strtok(envPathValue, ":");
	while (path)
	{
		fullCommandPath = malloc(sizeof(char) * 1024);
		if (fullCommandPath == NULL)
		{
			free1D(envPathValue);
			return (NULL);
		}
		_strcpy(fullCommandPath, path);
		_strcat(fullCommandPath, "/");
		_strcat(fullCommandPath, Command);
		if (stat(fullCommandPath, &st) == 0)
		{
			free1D(envPathValue);
			return (fullCommandPath);
		}
		free1D(fullCommandPath);
		path = strtok(NULL, ":");
	}

	free1D(envPathValue);
	return (NULL);
}
