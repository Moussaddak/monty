#include "monty.h"
stack_t *head = NULL;
/**
 * main - entry point
 * @argc: number of args
 * @argv: filenames
 * Return: success always
 */
int main(int argc, char **argv)
{
	char buffer[MAX];
	data_t *data;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	data = malloc(sizeof(data_t));
	if (!data)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	data->line = 1;
	data->fd = fopen(argv[1], "r");
	if (data->fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, MAX, data->fd) != NULL)
	{
		parse(buffer, data, &head);
		data->line++;
	}
	fclose(data->fd);
	if (data)
		free(data);
	free_dlistint(head);
	return (EXIT_SUCCESS);
}
