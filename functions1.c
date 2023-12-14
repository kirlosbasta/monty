#include "monty.h"

/**
 * is_digit - check if a string contain only digits
 * @s: pointer to string
 *
 * Return: 0 on success and 1 on failure
 */

int is_digit(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-' && i == 0)
		{
			continue;
		}
		if (s[i] < '0' || s[i] > '9')
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _isalpha - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
