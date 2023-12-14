#include "monty.h"

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
		{"pint", pint}, {NULL, NULL}};
	info_t list;

	list.stack = NULL;
	list.args = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	list.buffer = malloc(sizeof(char) * BUF_SIZE);
	while (get_opcode(av[1], &line_number, &list))
	{
		list.args = get_argument(list.buffer);
		idx = check_opcode(&list, line_number, opcode);
		if (idx == -1)
			continue;
		opcode[idx].f(&list.stack, line_number, &list);
		free(list.args);
		list.args = NULL;
	}
	free_dlistint(&list);
	return (EXIT_SUCCESS);
}
