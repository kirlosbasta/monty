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
 * @order: set the order of pushing to stack or queue
 *
 * Description: ist of variables needed for freeing the allocated memory
 */
typedef struct info_s
{
	char *buffer;
	char **args;
	FILE *fp;
	stack_t *stack;
	int order;
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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern info_t list;

int get_opcode(char *filename, int *line_number);
int  check_opcode(int line_num, instruction_t opcode[]);
int check_delim(char *s, char *delim);
char **get_argument(char *buffer);
stack_t *add_dnodeint(stack_t **head, int n);
stack_t *add_dnodeint_end(stack_t **head, int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void free_dlistint(void);
int is_digit(char *s);
int _isalpha(int c);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void division(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, UNUSED unsigned int line_number);
void rotr(stack_t **stack, UNUSED unsigned int line_number);
void _stack(UNUSED stack_t **stack, UNUSED unsigned int line_number);
void _queue(UNUSED stack_t **stack, UNUSED unsigned int line_number);

#endif
