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
		if (s[i] <= '0' || s[i] >= '9')
		{
			return (1);
		}
	}
	return (0);
}
