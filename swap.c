#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->prev = temp;
	(*stack)->next = temp->next;
	temp->prev = NULL;
	temp->next = *stack;
	*stack = temp;

	if ((*stack)->next != NULL)
		(*stack)->next->prev = *stack;
}

