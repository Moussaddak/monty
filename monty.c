#include "monty.h"
/**
 * main - entry point
 * @argc: number of args
 * @argv: filenames
 * Return: success always
 */
int main(int argc, char **argv)
{
	FILE *fd;
	char buffer[MAX];
	unsigned int line_number = 1;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr,"Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, MAX, fd) != NULL)
	{
		parse(buffer, line_number, &head);
		line_number++;
	}

	fclose(fd);
	return (EXIT_SUCCESS);
}
