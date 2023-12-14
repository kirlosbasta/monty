#include "monty.h"

/**
 * get_opcode - Get command from a file
 * @filename: name of the file to open
 * @line_number: number of line so far
 * @list: list of variables
 *
 * Return: 1 if there is still lines and 0 if EOF is reached
 */

int get_opcode(char *filename, int *line_number)
{
	static FILE *fp;
	char *tmp;

	if (fp == NULL)
	{
		fp = fopen(filename, "r");
		list.fp = fp;
		if (fp == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", filename);
			exit(EXIT_FAILURE);
		}
	}
	tmp = fgets(list.buffer, BUF_SIZE, fp);
	if (tmp == NULL)
	{
		return (0);
	}
	(*line_number)++;
	return (1);
}

/**
 * get_argument - seperate the line from get_opcode to arguments
 * @buffer: pointer to the line
 *
 * Return: list of arguments or NULL
 */

char **get_argument(char *buffer)
{
	char **arguments = malloc(sizeof(char *) * 3);

	if (arguments == NULL)
	{
		return (NULL);
	}
	if (strlen(buffer) > 1)
		buffer = strtok(buffer, "\n");
	arguments[0] = strtok(buffer, " ");
	arguments[1] = strtok(NULL, " ");
	if (arguments[1] != NULL)
	{
		arguments[2] = NULL;
	}
	return (arguments);
}

/**
 * check_delim -  check if a string conatin delim
 * @s: pointer to string
 * @delim: pointer to the character to search for
 *
 * Return: 1 if it contain delim and 0 if it doesn't
 */

int check_delim(char *s, char *delim)
{
	int i;

	if (s == NULL || delim == NULL)
	{
		return (0);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == *delim)
		{
			return (i);
		}
	}
	return (0);
}

/**
 * check_opcode - check if the argument are valid monty instruction
 * @list: list of variables
 * @line_num: line number
 * @opcode: list of valid opcode instructions
 *
 * Return: index of opcode in list opcode or -1 if is not opcode
 */

int  check_opcode(int line_num, instruction_t opcode[])
{
	int idx;

	if (list.args == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlistint();
		exit(EXIT_FAILURE);
	}
	for (idx = 0; opcode[idx].opcode != NULL; idx++)
	{
		if (strcmp(list.args[0], opcode[idx].opcode) == 0)
		{
			return (idx);
		}
	}
	if (list.args[0][0] != '\n')
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, list.args[0]);
		free_dlistint();
		exit(EXIT_FAILURE);
	}
	return (-1);
}
