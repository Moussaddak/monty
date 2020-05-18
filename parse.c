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
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delims);
	if (eval(token, 0))
		data->op = strdup(token);
	else if (!token)
		data->op = NULL;
	else
	{
		fprintf(stderr, "L%d: : unknown instruction %s\n", ln, token);
		exit(EXIT_FAILURE);
	}
	if (data->op)
	{
		token = strtok(NULL, delims);
		if (eval(token, 1))
		{
			data->arg = atoi(token);
		}
		else if (!strcmp(data->op, "push"))
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
	}
	if (data->op)
	{
		run_op(data, h);
	}
	_free(data);
}
