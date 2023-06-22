#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STACK_SIZE 1024

typedef struct {
    int stack[STACK_SIZE];
    int top;
} Stack;

void push(Stack *stack, int value) {
    if (stack->top >= STACK_SIZE) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->stack[stack->top++] = value;
}

void pall(Stack *stack) {
    int i;
    for (i = stack->top - 1; i >= 0; i--) {
        printf("%d\n", stack->stack[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    Stack stack;
    stack.top = 0;
    char opcode[5];
    int value;
    int line_number = 1;

    while (fscanf(file, "%s", opcode) == 1) {
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "Error: L%d: Usage: push <integer>\n", line_number);
                fclose(file);
                return EXIT_FAILURE;
            }
            push(&stack, value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack);
        } else {
            fprintf(stderr, "Error: L%d: Unknown opcode %s\n", line_number, opcode);
            fclose(file);
            return EXIT_FAILURE;
        }
        line_number++;
    }

    fclose(file);
    return EXIT_SUCCESS;
}

