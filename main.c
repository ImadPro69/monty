#include "monty.h"
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL;
    char *line = NULL;
    size_t line_size = 0;
    unsigned int line_number = 0;

    while (getline(&line, &line_size, file) != -1)
    {
        line_number++;
        char *opcode = strtok(line, " \t\n");
        if (opcode == NULL || opcode[0] == '#')
            continue;

        int found_opcode = 0;
        instruction_t opcodes[] = {
            {"push", opcode_push},
            {"pall", opcode_pall},
            /* Add more opcodes here */
            {NULL, NULL} /* Terminator */
        };

        for (int i = 0; opcodes[i].opcode != NULL; i++)
        {
            if (strcmp(opcode, opcodes[i].opcode) == 0)
            {
                opcodes[i].f(&stack, line_number);
                found_opcode = 1;
                break;
            }
        }

        if (!found_opcode)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            fclose(file);
            free(line);
            free_stack(&stack);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    free(line);
    free_stack(&stack);
    return EXIT_SUCCESS;
}

