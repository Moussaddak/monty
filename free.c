#include "monty.h"
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
