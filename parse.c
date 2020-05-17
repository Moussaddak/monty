#include "monty.h"
/**
 * parse - parses line of input
 * @buffer: line of input to parse
 * @ln: line number being evaluated
 * @h: top of the stack
 */
void parse(char *buffer, unsigned int ln, stack_t **h)
{
	char delims[] = " \t\n", *token;
	data_t *data;

	data = malloc(sizeof(data_t));
	if (!data)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delims);
	if (eval(token, 0))
		data->op = strdup(token);
	else if (token)
	{
		printf("L%d: : unknown instruction %s\n", ln, token);
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, delims);
	if (eval(token, 1))
		data->arg = atoi(token);
	else if (data->op && !strcmp(data->op, "push"))
	{
		printf("L%d: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}
	if (data->op)
		run_op(data, h);
	_free(data);
}
