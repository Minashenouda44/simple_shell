#include "shell.h"

/**
 * int2str - a function that convert integer to string
 * @n: integer number
 * Return: string
 */

char *int2str(int n)
{
	int i = 0;
	char buffer[32];

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	_strrev(buffer, i);

	return (_strdup(buffer));
}

/**
 * _strrev - a function that reverse a string
 * @string: string 2 reverse
 * @len: string lenght
 * Return: void
 */

void _strrev(char *string, int len)
{
	char temp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		temp = string[start];
		string[start] = string[end];
		string[end] = temp;
		start++;
		end--;
	}
}

/**
 * _atoi - a function that convert string to integer
 * @str: string
 * Return: integer
 */

int _atoi(char *str)
{
	int i = 0;
	int number = 0;

	for (i = 0; str[i]; i++)
	{
		number *= 10;
		number += (str[i] - '0');
	}

	return (number);
}

/**
 * isPositive - afunction that check if the number or not
 * @str: string
 * Return: 0 on success
 */

int isPositive(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * _memset -  a function that fills memory with a constant byte.
 * @s: array
 * @c: constant
 * @n: integer
 * Return: s
 */

char *_memset(char *s, char c, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = c;
	}

	return (s);
}
