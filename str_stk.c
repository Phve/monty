#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * kisii_print_char - Prints the ASCII value.
 * @stk: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Unsigned integer representing the line number of the opcode.
 */
void kisii_print_char(stack_t **stk, unsigned int line_num)
{
    int ascii;

    if (stk == NULL || *stk == NULL)
    {
        kisii_err(11, line_num, "Print char operation requires at least one element on the stack");
        return;
    }

    ascii = (*stk)->n;
    if (ascii < 0 || ascii > 127)
    {
        kisii_err(10, line_num, "Invalid ASCII value");
        return;
    }
    printf("%c\n", ascii);
}

/**
 * meru_print_str - Prints a string.
 * @stk: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Unsigned integer representing the line number of the opcode.
 */
void meru_print_str(stack_t **stk, __attribute__((unused)) unsigned int line_num)
{
    int ascii;
    stack_t *tmp;
    int printed = 0;

    if (stk == NULL || *stk == NULL)
    {
        return;
    }

    tmp = *stk;
    while (tmp != NULL)
    {
        ascii = tmp->n;
        if (ascii <= 0 || ascii > 127)
            break;

        printf("%c", ascii);
        printed = 1;
        tmp = tmp->next;
    }

    if (printed)
        printf("\n");
}

/**
 * nandi_rotl - Rotates the first node of the stack to the bottom.
 * @stk: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Unsigned integer representing the line number of the opcode.
 */
void nandi_rotl(stack_t **stk, __attribute__((unused)) unsigned int line_num)
{
    stack_t *tmp;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        return;

    tmp = *stk;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *stk;
    (*stk)->prev = tmp;
    *stk = (*stk)->next;
    (*stk)->prev->next = NULL;
    (*stk)->prev = NULL;
}

/**
 * turkana_rotr - Rotates the last node of the stack to the top.
 * @stk: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Unsigned integer representing the line number of the opcode.
 */
void turkana_rotr(stack_t **stk, __attribute__((unused)) unsigned int line_num)
{
    stack_t *tmp;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
        return;

    tmp = *stk;

    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = *stk;
    tmp->prev->next = NULL;
    tmp->prev = NULL;
    (*stk)->prev = tmp;
    (*stk) = tmp;
}

