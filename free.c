#include "monty.h"
/**
 *_free - clear memory
 *@h: input data_t
 */
void _free(data_t *h)
{
	if (h->op)
	{
		free(h->op);
		h->op = NULL;
		free(h);
		h = NULL;
	}
}
/**
 *free_dlistint -  frees a stack_t list
 *@head: input of type stack_t
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
