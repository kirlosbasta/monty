#include "monty.h"

info_t list = {NULL, NULL, NULL, NULL, 0};

/**
 * main - Entry to the program
 * @ac: number of arguments
 * @av: Command line arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FALIURE
 */

int main(int ac, char *av[])
{
	int line_number = 0, idx;
	instruction_t opcode[] = {{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"nop", nop}, {"sub", sub}, {"div", division},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr}, {"stack", _stack}, {"queue", _queue},
		{NULL, NULL}};

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	list.buffer = malloc(sizeof(char) * BUF_SIZE);
	while (get_opcode(av[1], &line_number))
	{
		list.args = get_argument(list.buffer);
		if (list.args[0] == NULL || list.args[0][0] == '#')
		{
			free(list.args);
			list.args = NULL;
			continue;
		}
		idx = check_opcode(line_number, opcode);
		if (idx == -1)
		{
			free(list.args);
			list.args = NULL;
			continue;
		}
		opcode[idx].f(&list.stack, line_number);
		free(list.args);
		list.args = NULL;
	}
	free_dlistint();
	return (EXIT_SUCCESS);
}
