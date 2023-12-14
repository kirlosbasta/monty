#include "monty.h"

/**
 * add_dnodeint - Add a node to beginning of a list
 * @head: Head of the list
 * @n: inger to add
 *
 * Return: pointer to the new node or NULL
 */

stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		return (NULL);
	}
	node->n = (int) n;
	node->next = *head;
	node->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = node;
	}
	*head = node;
	return (node);
}

/**
 * add_dnodeint_end - Add a node to the end of a list
 * @head: Head of the list
 * @n: integer to add
 *
 * Return: pointer to new node or NULL
 */

stack_t *add_dnodeint_end(stack_t **head, int n)
{
	stack_t *current = *head;
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		return (NULL);
	}
	node->n = (int) n;
	node->next = NULL;
	if (*head == NULL)
	{
		node->prev = NULL;
		*head = node;
		return (node);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	node->prev = current;
	current->next = node;
	return (node);
}

/**
 * delete_dnodeint_at_index - delete at index
 * @head: Head of the list
 * @index: index
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *current = *head;
	unsigned int idx = 0;

	if (*head == NULL)
	{
		return (-1);
	}
	while (current != NULL && idx < index)
	{
		idx++;
		current = current->next;
	}
	if (current != NULL)
	{
		if (current->prev == NULL)
		{
			*head = current->next;
			if (*head != NULL)
				(*head)->prev = NULL;
			free(current);
			return (1);
		}
		else if (current->next == NULL)
		{
			current->prev->next = NULL;
			free(current);
			return (1);
		}
		else
		{
			current->next->prev = current->prev;
			current->prev->next = current->next;
			free(current);
			return (1);
		}
	}
	return (-1);
}

/**
 * free_dlistint - free double linked list
 * @list: list of variables
 *
 * Return: Nothing
 */

void free_dlistint(void)
{
	stack_t *tmp, *current = list.stack;

	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	if (list.args != NULL)
		free(list.args);
	free(list.buffer);
	fclose(list.fp);
}

