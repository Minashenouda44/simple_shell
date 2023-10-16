#include "shell.h"

/**
 * getEnv - a fuction that return the environ variable value of PATH environ
 * @key: variable key
 * Return: envPathValue on success
 */

char *getEnv(char *key)
{
	unsigned int i = 0;
	char *varKey = NULL;
	char *varValue = NULL;
	char *tempEnviron = NULL;
	char *envPathValue = NULL;

	for (i = 0; environ[i]; i++)
	{
		tempEnviron = _strdup(environ[i]);

		varKey = strtok(tempEnviron, "=");
		if (_strcmp(varKey, key) == 0)
		{
			varValue = strtok(NULL, "\n");
			envPathValue = _strdup(varValue);
			free1DArrayMemory(tempEnviron);
			return (envPathValue);
		}
		free1DArrayMemory(tempEnviron);
	}
	free1DArrayMemory(envPathValue);

	return (NULL);
}
