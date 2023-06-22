#include "monty.h"

void pall(stack_t **stack, int line_number)
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
    (void)line_number; // Unused parameter, avoid warning
}

