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

/**
 * pstr - print the string starting from the top of the stack
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void pstr(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *current = *stack;
	int print = 0;

	if (*stack == NULL)
	{
		printf("\n");
	}
	while (current != NULL && current->n != 0)
	{
		if (current->n < 0 || current->n > 127)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
		print++;
	}
	if (print > 0)
	{
		printf("\n");
	}
}

/**
 * rotl - move the top of the stack to the bottom
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void rotl(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *current = *stack;

	if (current != NULL && current->next != NULL)
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = *stack;
		(*stack) = (*stack)->next;
		current->next->next = NULL;
		(*stack)->prev = NULL;
	}
}

/**
 * rotr - move the bottom of the stack to the top
 * @stack: Front of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void rotr(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *current = *stack;

	if (current != NULL && current->next != NULL)
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->prev->next = NULL;
		current->prev = NULL;
		current->next = *stack;
		(*stack)->prev = current;
		(*stack) = current;
	}
}
