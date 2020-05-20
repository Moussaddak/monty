#include "monty.h"
/**
 * parse - parses line of input
 * @buffer: line of input to parse
 * @d: data package
 * @h: top of the stack
 */
void parse(char *buffer, data_t *d, stack_t **h)
{
	char delims[] = " \t\n", *token;

	token = strtok(buffer, delims);
	if (eval(token, 0))
		d->op = strdup(token);
	else if (!token)
		d->op = NULL;
	else
	{
		fclose(d->fd);
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
			d->line, token);
		if (d)
			free(d);
		free_dlistint(*h);
		exit(EXIT_FAILURE);
	}
	if (d->op)
	{
		token = strtok(NULL, delims);
		if (eval(token, 1))
		{
			d->arg = atoi(token);
		}
		else if (!strcmp(d->op, "push"))
		{
			free(d->op);
			fclose(d->fd);
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n",
				d->line);
			if (d)
				free(d);
			free_dlistint(*h);
			exit(EXIT_FAILURE);
		}
	}
	if (d->op)
		run_op(d, h);
	free(d->op);
}
