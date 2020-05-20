#include "monty.h"
/**
 *swap - swaps the top two elements of the stack.
 *@h: pointer of struct
 *@d: package data
 *
 */
void swap(stack_t **h, data_t *d)
{
	int swap;


	if (*h && (*h)->next)
	{
		swap = (*h)->n;
		(*h)->n = (*h)->next->n;
		(*h)->next->n = swap;

	}
	else
	{
		free(d->op);
		fclose(d->fd);
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n",
			d->line);
		if (d)
			free(d);
		free_dlistint(*h);
		exit(EXIT_FAILURE);
	}
}
