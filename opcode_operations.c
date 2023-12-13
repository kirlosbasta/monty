#include "monty.h"

/**
 * push - Add a number to the top of stack
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number, char **args)
{
	int num;

	if (args[1] == NULL || is_digit(args[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", (int) line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(args[1]);
	add_dnodeint(stack, num);
}

/**
 * pall - print all the values in the stack
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void pall(stack_t **stack, UNUSED unsigned int line_number, UNUSED char **args)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
