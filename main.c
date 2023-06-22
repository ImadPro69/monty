#include "monty.h"

/**
 * main - Entry point of the Monty interpreter
 * @argc: Argument count
 * @argv: Array of argument strings
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	init_stack();

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		parse_line(line, line_number);
	}

	free_stack();
	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}

