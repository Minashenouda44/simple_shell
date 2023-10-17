#include "shell.h"

/**
 * free1D - a function that free 1D Array Memory
 * @array: 1D Array
 * Return: void
 */

void free1D(char *array)
{
	if (array != NULL)
	{
		free(array);
		array = NULL;
	}
}

/**
 * free2D - a function that free 2D Array Memory
 * @array: 2D Array
 * Return: void
 */

void free2D(char **array)
{
	if (array != NULL)
	{
		int i = 0;

		for (i = 0; array[i]; i++)
		{
			free(array[i]);
			array[i] = NULL;
		}

		free(array);
		array = NULL;
	}
}
