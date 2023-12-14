#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 256
#define UNUSED __attribute__((unused))


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct info_s - list of variables
 * @buffer: buffer
 * @args: list of arguments
 * @stack: head of the list
 * @fp: pointer to file
 *
 * Description: ist of variables needed for freeing the allocated memory
 */
typedef struct info_s
{
	char *buffer;
	char **args;
	FILE *fp;
	stack_t *stack;
} info_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, info_t *list);
} instruction_t;

extern info_t list;

int get_opcode(char *filename, int *line_number, info_t *list);
int  check_opcode(info_t *list, int line_num, instruction_t opcode[]);
int check_delim(char *s, char *delim);
char **get_argument(char *buffer);
stack_t *add_dnodeint(stack_t **head, int n);
stack_t *add_dnodeint_end(stack_t **head, int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void free_dlistint(info_t *list);
int is_digit(char *s);
void push(stack_t **stack, unsigned int line_number, info_t *list);
void pall(stack_t **stack, unsigned int line_number, info_t *list);
void pint(stack_t **stack, unsigned int line_number, info_t *list);

#endif
