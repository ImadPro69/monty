#include "monty.h"
#include <string.h>

stack_t *stack = NULL;

void monty_execute(FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;

        char *opcode = strtok(line, " \t\n");
        if (opcode == NULL || opcode[0] == '#')
            continue;

        char *arg = strtok(NULL, " \t\n");

        int i;
        instruction_t instructions[] = {
            {"push", push},
            {"pall", pall},
            {NULL, NULL} // Add a sentinel element to mark the end of the array
        };

        for (i = 0; instructions[i].opcode != NULL; i++)
        {
            if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                instructions[i].f(&stack, line_number);
                break;
            }
        }

        if (instructions[i].opcode == NULL)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            free(line);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    monty_execute(file);

    fclose(file);
    return EXIT_SUCCESS;
}

