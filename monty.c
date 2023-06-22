#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Add this line to include string.h

void monty_execute(char *line)
{
    if (strlen(line) <= 1)
        return;

    char *opcode = strtok(line, " \t\n");
    char *arg = strtok(NULL, " \t\n");

    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL} // Add a sentinel element to mark the end of the array
    };

    int i;
    void (*opcode_func)(stack_t **, unsigned int);

    for (i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            opcode_func = instructions[i].f;
            opcode_func(&stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

