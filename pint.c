#include "monty.h"
/**
 *pint- prints the value at the top of the stack
 *@h: stack input
 *@d: package data
 */
void pint(stack_t **h, data_t *d)
{

	if (*h)
		printf("%d\n", (*h)->n);
	else
	{
		free(d->op);
		fclose(d->fd);
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", d->line);
		if (d)
			free(d);
		free_dlistint(*h);
		exit(EXIT_FAILURE);
	}
}
