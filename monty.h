#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

extern stack_t *stack;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

