#include "monty.h"
/**
 *pop - removes the top element of the stack.
 *@h: pointer of struct
 *@d: package data
 *
 */
void pop(stack_t **h, data_t *d)
{
	stack_t *tmp;

	if (!*h)
	{
		free(d->op);
		fclose(d->fd);
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n",
			d->line);
		if (d)
			free(d);
		free_dlistint(*h);
		exit(EXIT_FAILURE);
	}

	if (!(*h)->next)
	{
		free_dlistint(*h);
		*h = NULL;
	}
	else
	{
		tmp = *h;
		*h = tmp->next;
		tmp->next->prev = NULL;
		free(tmp);
	}
}
