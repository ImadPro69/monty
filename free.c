#include "monty.h"
#include "lists.h"

/**
 * free_all - frees all allocated memory and closes the file
 * @status: exit status to be used with exit()
 */
void free_all(int status)
{
	stack_t *current = NULL;

	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}

	if (file)
		fclose(file);

	if (buffer)
		free(buffer);

	if (status == 2)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
	}

	exit(status);
}

