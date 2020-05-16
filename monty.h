#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#define MAX 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

instruction_t ops_f[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};
/**
 * struct data_t - opcode and its argument
 * @op: the opcode
 * @arg: argument
 *
 *Description: opcode and its argument
 */
typedef struct data_t
{
	char *op;
	int arg;
} data_t;

size_t pall(const stack_t *h);
stack_t *push(stack_t **head, const int n);
int eval(char *s, int n);
void _free(data_t *h);
void run_op(data_t data, stack_t **head);
void parse(char *buffer, unsigned int ln);



#endif
