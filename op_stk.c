#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * kakamega_mul_nodes - Multiplies the top two elements of the stack.
 * @stk: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void kakamega_mul_nodes(stack_t **stk, unsigned int line_num)
{
    int product;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
    {
        bungoma_err(8, line_num, "mul requires at least two elements on the stack");
        return;
    }

    stack_t *temp = *stk;
    
    *stk = (*stk)->next;
    product = (*stk)->n * temp->n;
    (*stk)->n = product;
    free(temp);
}

/**
 * uasin_gishu_mod_nodes - Computes the remainder of the top two elements of the stack.
 * @stk: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void uasin_gishu_mod_nodes(stack_t **stk, unsigned int line_num)
{
    int remainder;

    if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
    {
        bungoma_err(8, line_num, "mod requires at least two elements on the stack");
        return;
    }

    if ((*stk)->n == 0)
    {
        bungoma_err(9, line_num, "division by zero");
        return;
    }

    stack_t *temp = *stk;
    *stk = (*stk)->next;
    remainder = (*stk)->n % temp->n;
    (*stk)->n = remainder;
    free(temp);
}

