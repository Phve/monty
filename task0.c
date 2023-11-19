#include "monty.h"

/**
 * nairobi_err - Prints appropriate error messages determined by their error code.
 * @error_code: The error codes are the following:
 *   (1) => The user did not provide a file or provided more than one file to the program.
 *   (2) => The file provided cannot be opened or read.
 *   (3) => The file provided contains an invalid instruction.
 *   (4) => The program is unable to allocate more memory.
 *   (5) => The parameter passed to the instruction "push" is not an integer.
 *   (6) => The stack is empty for pint.
 *   (7) => The stack is empty for pop.
 *   (8) => The stack is too short for the operation.
 */
void nairobi_err(int error_code, ...)
{
    va_list args;
    char *file_name;
    int line_number;

    va_start(args, error_code);
    switch (error_code)
    {
        case 1:
            fprintf(stderr, "USAGE: monty file\n");
            break;
        case 2:
            file_name = va_arg(args, char *);
            fprintf(stderr, "Error: Cannot open file %s\n", file_name);
            break;
        case 3:
            line_number = va_arg(args, int);
            file_name = va_arg(args, char *);
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, file_name);
            break;
        case 4:
            fprintf(stderr, "Error: Memory allocation failed\n");
            break;
        case 5:
            line_number = va_arg(args, int);
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            break;
        default:
            break;
    }
    va_end(args);
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * mombasa_err - Handles errors.
 * @error_code: The error codes are the following:
 *   (6) => The stack is empty for pint.
 *   (7) => The stack is empty for pop.
 *   (8) => The stack is too short for the operation.
 *   (9) => Division by zero.
 */
void mombasa_err(int error_code, ...)
{
    va_list args;
    int line_number;
    char *operation;

    va_start(args, error_code);
    switch (error_code)
    {
        case 6:
            line_number = va_arg(args, int);
            fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
            break;
        case 7:
            line_number = va_arg(args, int);
            fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
            break;
        case 8:
            line_number = va_arg(args, int);
            operation = va_arg(args, char *);
            fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, operation);
            break;
        case 9:
            line_number = va_arg(args, int);
            fprintf(stderr, "L%d: division by zero\n", line_number);
            break;
        default:
            break;
    }
    va_end(args);
    free_nodes();
    exit(EXIT_FAILURE);
}

