#include "shell.h"

/**
 * _strlen - a function that get the lenght of a string.
 * @s: string
 * Return: len
 */

int _strlen(char *s)
{
	int i = 0;
	int len = 0;

	while (s[i])
	{
		i++;
		len++;
	}

	return (len);
}

/**
 * _strcpy - a function that copies a string.
 * @src: s string
 * @dest: d string
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - a function that compares two strings.
 * @s1: 1st string
 * @s2: 2nd string
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * _strcat - a function that concatenates two strings.
 * @src: string
 * @dest: string
 * Return: dest
 */

char *_strcat(char *dest, const char *src)
{
	char *temp = NULL;

	if (dest == NULL || src == NULL)
		return (dest);

	temp = dest;

	while (*temp)
		temp++;

	while (*src)
	{
		*temp = *src;
		temp++;
		src++;
	}
	*temp = '\0';

	return (dest);
}

/**
 * _strdup - a function that duplicate a string.
 * @str: a string to duplicate
 * Return: dup
 */

char *_strdup(char *str)
{
	int i;
	int len = 0;
	char *dup = NULL;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	dup = malloc(sizeof(char) * (len + 1));
	_memset(dup, 0, sizeof(char));

	if (dup == NULL)
	{
		free(dup);
		return (NULL);
	}

	for (i = 0; i < len; i++)
		dup[i] = str[i];

	dup[len] = '\0';

	return (dup);
}
