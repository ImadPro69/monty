#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Structure for a stack node */
typedef struct stack_s
{
	int n;
	struct stack_s *next;
} stack_t;

/* Global variable for the stack */
extern stack_t *stack;

/* Function prototypes */
void push(stack_t **stack, int n);
void pall(stack_t **stack);
void pint(stack_t **stack);
void pop(stack_t **stack);
void swap(stack_t **stack);
void add(stack_t **stack);
void nop(stack_t **stack);
void free_stack(stack_t **stack);

void init_stack(void);
void parse_line(char *line, unsigned int line_number);

#endif /* MONTY_H */

