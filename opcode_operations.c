#include "monty.h"

/**
 * push - Add a number to the top of stack
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	int num;

	if (list.args[1] == NULL || is_digit(list.args[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", (int) line_number);
		free_dlistint();
		exit(EXIT_FAILURE);
	}
	num = atoi(list.args[1]);
	if (add_dnodeint(stack, num) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlistint();
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - print all the values in the stack
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void pall(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - print the values on top of the stack
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (list.stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_dlistint();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - remove a node from top of the stack
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_dlistint();
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	if (*stack != NULL)
		(*stack)->prev = NULL;
}

/**
 * swap - swap two element from top of the stack
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_dlistint();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
