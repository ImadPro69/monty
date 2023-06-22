#include "monty.h"
#include "lists.h"

/**
 * get_func - selects the correct function to perform the operation
 * @opcode: operation code
 * @line_number: line number being executed from the file
 *
 * Return: pointer to the corresponding function, or NULL if not found
 */
void (*get_func(char *opcode, unsigned int line_number))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		/* Add more instructions here */
		{NULL, NULL}
	};

	int i = 0;

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (instructions[i].f);
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free_all(EXIT_FAILURE);
	return (NULL);
}

