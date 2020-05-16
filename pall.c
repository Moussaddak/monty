#include "monty.h"
/**
 *pall - prints all the elements of a stack_t list
 *@h: input of type stack_t
 *Return: the number of nodes
 */
size_t pall(const stack_t *h)
{
	size_t cpt_n = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		cpt_n++;
	}
	return (cpt_n);
}
