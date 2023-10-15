#include "shell.h"

/**
 * free1DArrayMemory - a function that free 1D Array Memory
 * @array: 1D Array
 * Return: void
 */

void free1DArrayMemory(char *array)
{
	if (array)
	{
		free(array), array = NULL;
	}
}

/**
 * free2DArrayMemory - a function that free 2D Array Memory
 * @array: 2D Array
 * Return: void
 */

void free2DArrayMemory(char **array)
{
	if (array)
	{
		int i = 0;

		for (i = 0; array[i]; i++)
		{
			free(array[i]), array[i] = NULL;
		}

		free(array), array = NULL;
	}
}
