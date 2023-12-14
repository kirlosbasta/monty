#include "monty.h"

/**
 * add - add two element from top of the stack
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_dlistint();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - Do nothing
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void nop(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{}
