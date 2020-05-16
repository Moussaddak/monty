#include "monty.h"
/**
 *run_op - execute operation
 *@data: package of data
 *@head: dlinked list
 */
void run_op(data_t data, stack_t **head)
{
	switch (data.op)
	{

	case "push":
		push(head, data.arg);
		break;

	case "pall":
		pall(*head);
		break;

	default:
		break;
	}
}
