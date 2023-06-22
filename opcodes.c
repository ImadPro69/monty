#include "monty.h"
#include <stdlib.h>

void opcode_push(stack_t **stack, unsigned int line_number)
{
    /* Extract the integer argument */
    char *arg = strtok(NULL, " \t\n");

    /* Validate the argument */
    if (arg == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Convert the argument to an integer */
    int value = atoi(arg);

    /* Create a new stack node */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node */
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    /* Push the value onto the stack */
    if (*stack != NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}

void opcode_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    /* Print all the values on the stack */
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void free_stack(stack_t **stack)
{
    if (stack == NULL || *stack == NULL)
        return;

    stack_t *current = *stack;
    stack_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *stack = NULL;
}

