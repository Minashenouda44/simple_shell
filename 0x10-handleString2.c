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
