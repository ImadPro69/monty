#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_s
{
    int n;
    struct stack_s *next;
} stack_t;

extern stack_t *stack;

void monty_execute(FILE *file);
void push(stack_t **stack, int value);
void pall(stack_t **stack, int line_number);
int is_number(const char *str);

#endif /* MONTY_H */

