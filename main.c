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
	char *buffer, **args;
	int line_number = 0, idx;
	instruction_t opcode[] = {{"push", push}, {"pall", pall}, {NULL, NULL}};
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * BUF_SIZE);
	while (get_opcode(av[1], &line_number, &buffer))
	{
		args = get_argument(buffer);
		idx = check_opcode(buffer, line_number, opcode);
		if (idx == -1)
			continue;
		opcode[idx].f(&stack, line_number, args);
		free(args);
	}
	free(buffer);
	free_dlistint(stack);
	return (EXIT_SUCCESS);
}