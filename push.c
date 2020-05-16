#include "monty.h"
/**
 *push - create new elements in a dlinked list
 *@head: input of type stack_t
 *@n: input of type integer
 *Return: a new node of type stack_t
 */
stack_t *push(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		return (NULL);
	}
	else
	{
		new_node->n = n;
		new_node->next = *head;
		new_node->prev = NULL;
		if (*head)
		{
			(*head)->prev = new_node;
		}
		*head = new_node;
	}

	return (new_node);
}
