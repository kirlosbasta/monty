#include "monty.h"

/**
 * push - Add a number to the top of stack
 * @stack: Front of the stack
 * @line_number: line number
 * @list: list of variables
 *
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number, info_t *list)
{
	int num;

	if (list->args[1] == NULL || is_digit(list->args[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", (int) line_number);
		free_dlistint(list);
		exit(EXIT_FAILURE);
	}
	num = atoi(list->args[1]);
	if (add_dnodeint(stack, num) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlistint(list);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - print all the values in the stack
 * @stack: Front of the stack
 * @line_number: line number
 * @list: list of variables
 *
 * Return: Nothing
 */

void pall(stack_t **stack, UNUSED unsigned int line_number,
			UNUSED info_t *list)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
