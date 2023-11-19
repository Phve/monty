#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * kiambu_nop - Does nothing.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void kiambu_nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * nakuru_swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void nakuru_swap_nodes(stack_t **stk, unsigned int line_num)
{
    stack_t *tmp;
    
    if (stk == NULL || *stk == NULL || (*stk)->next == NULL) {
    bungoma_err(8, line_num, "swap requires at least two elements on the stack");
    return;
    
    tmp = (*stack)->next;
    (*stack)->next = tmp->next;

    if (tmp->next != NULL)
        tmp->next->prev = *stack;

    tmp->next = *stack;
    (*stack)->prev = tmp;
    tmp->prev = NULL;
    *stack = tmp;

    (void)stk;
}

/**
 * kisumu_add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void kisumu_add_nodes(stack_t **stack, unsigned int line_number)
{
    int sum;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        bungoma_err(8, line_number, "add requires at least two elements on the stack");

    *stack = (*stack)->next;
    sum = (*stack)->n + (*stack)->prev->n;
    (*stack)->n = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * kakamega_sub_nodes - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void kakamega_sub_nodes(stack_t **stack, unsigned int line_number)
{
    int difference;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        bungoma_err(8, line_number, "sub requires at least two elements on the stack");

    *stack = (*stack)->next;
    difference = (*stack)->n - (*stack)->prev->n;
    (*stack)->n = difference;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * bungoma_div_nodes - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void bungoma_div_nodes(stack_t **stack, unsigned int line_number)
{
    int quotient;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        bungoma_err(8, line_number, "div requires at least two elements on the stack");

    if ((*stack)->n == 0)
        bungoma_err(9, line_number, "division by zero");

    *stack = (*stack)->next;
    quotient = (*stack)->n / (*stack)->prev->n;
    (*stack)->n = quotient;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

