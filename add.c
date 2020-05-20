#include "monty.h"
/**
 *add - sum adds the top two elements of the stack..
 *@h: pointer of struct
 *@d: package data
 */
void add(stack_t **h, data_t *d)
{
	stack_t *tmp = *h;

	if (*h && (*h)->next)
	{
		*h = (*h)->next;
		(*h)->n += tmp->n;
		(*h)->prev = NULL;
		pop(&tmp, d);
	}

	else
	{
		free(d->op);
		fclose(d->fd);
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
			d->line);
		if (d)
			free(d);
		free_dlistint(*h);
		exit(EXIT_FAILURE);
	}
}
