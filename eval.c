#include "monty.h"
/**
 *eval - evaluate the args
 *@s: string to be evaluated
 *@n: if n = 0 >> check if s is argument, if n = 1 >> check if s is number
 *Return: 0 >> wrong entry / 1 >> correct entry
 */
int eval(char *s, int n)
{
	int i, l;
	instruction_t ops_f[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; !n && ops_f[i].opcode; i++)
	{
		if (s && !strcmp(s, ops_f[i].opcode))
		{
			return (1);/*correct entry*/
		}
	}

	if (n && s)
	{
		l = strlen(s);

		while (l--)
		{
			if (!l && s[l] == '-')
				break;
			if (s[l] > '9' || s[l] < '0')
			{
				return (0);/* entry not a number*/
			}
		}
		return (1);/* entry is a number*/
	}
	return (0);/* wrong entry */
}
