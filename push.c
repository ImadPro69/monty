#include <stdlib.h>
#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	char *value = strtok(NULL, " \t\n");
	stack_t *new_node = malloc(sizeof(stack_t));

	if (value == NULL || !is_integer(value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(value);
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

int is_integer(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
	}

	return 1;
}

