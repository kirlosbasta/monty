#include "monty.h"

/**
 * mod - modul the two element from top of the stack
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_dlistint();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n != 0)
	{
		(*stack)->next->n %= (*stack)->n;
	}
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_dlistint();
		exit(EXIT_FAILURE);
	}
	pop(stack, line_number);
}

/**
 * pchar - print the character on top of the stack
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_dlistint();
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_dlistint();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}