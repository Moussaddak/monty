#include "monty.h"
/**
 *eval - evaluate the args
 *@s: string to be evaluated
 *@n: if n = 0 >> check if s is argument, if n = 1 >> check if s is number
 *Return: 0 >> wrong entry / 1 >> correct entry
 */
int eval(char *s, int n)
{
	int i, len;

	for (i = 0; !n && ops_f[i].opcode; i++)
	{
		if (!strcmp(s, ops_f[i].opcode))
		{
			return (1);/*correct entry*/
		}
	}
	if (n && s)
	{
		len = strlen(s);
		while (len--)
		{
			if (s[len] > '9' || s[len] < '0')
			{
				return (0);/* entry not a number*/
			}
			else if (len == 0 && s[len] == '-')
				break;
		}
		return (1);/* entry is a number*/
	}
	return (0);/* wrong entry */
}
