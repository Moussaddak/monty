#include "monty.h"
/**
 *pall- print function
 *@h: input
 *@d: input
 */
void pall(stack_t **h, data_t *d __attribute__((unused)))
{
	print_dlistint(*h);
}
/**
 *print_dlistint - prints all the elements of a stack_t list
 *@h: input of type stack_t
 */
void print_dlistint(stack_t *h)
{

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
