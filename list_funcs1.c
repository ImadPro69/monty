#include "monty.h"
#include "lists.h"

/**
 * push - pushes an element to the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number being executed from the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (!stack)
		return;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(EXIT_FAILURE);
	}

	new_node->n = global.data;
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the top of the stack
 * @line_number: line number being executed from the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (!stack)
		return;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number being executed from the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/* Implement more list manipulation functions here */

