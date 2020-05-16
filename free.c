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
		free(h);
	}
}
