#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * nairobi_push - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @line_num: Integer representing the line number of the opcode.
 */
void nairobi_push(stack_t **new_node, unsigned int line_num)
{
    stack_t *tmp;

    if (new_node == NULL || *new_node == NULL)
        bungoma_err(1, line_num);

    if (maasai_head == NULL) 
    {
    err(6, "Maasai head is NULL");
    return;
    }

    tmp = maasai_head;
    maasai_head = *new_node;
    maasai_head->next = tmp;
    tmp->prev = maasai_head;
}

/**
 * nakuru_print - Prints the nodes in the stack.
 * @stk: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Line number of the opcode.
 */
void nakuru_print(stack_t **stk, unsigned int line_num)
{
    stack_t *tmp;

    (void)line_num;

    if (stk == NULL || *stk == NULL)
        bungoma_err(2, line_num);

    tmp = *stk;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

/**
 * kericho_pop - Removes the top node from the stack.
 * @stk: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void kericho_pop(stack_t **stk, unsigned int line_num)
{
    stack_t *tmp;

    if (stk == NULL || *stk == NULL)
        bungoma_err(7, line_num);

    tmp = *stk;
    *stk = tmp->next;
    if (*stk != NULL)
        (*stk)->prev = NULL;
    free(tmp);
}

/**
 * kisumu_print_top - Prints the value of the top node in the stack.
 * @stk: Pointer to a pointer pointing to the top node of the stack.
 * @line_num: Integer representing the line number of the opcode.
 */
void kisumu_print_top(stack_t **stk, unsigned int line_num)
{
    if (stk == NULL || *stk == NULL)
        bungoma_err(6, line_num);

    printf("%d\n", (*stk)->n);
}

