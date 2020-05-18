#include "monty.h"
/**
 *run_op - execute operation
 *@data: package of data
 *@head: top of stack
 */
void run_op(data_t *data, stack_t **head)
{
	int i = 0;
	instruction_t ops_f[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	while (data->op && ops_f[i].opcode)
	{
		if (!strcmp(data->op, ops_f[i].opcode))
		{
			ops_f[i].f(head, data);
			return;
		}
		i++;
	}
}
