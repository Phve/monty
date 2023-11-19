#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <err.h>

/**
 * struct stack_s - doubly linked list rep of a stack (or queue)
 * @n: integer
 * @prev: points to the prev element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * ward_t - Declare the ward_t type
 */
typedef struct ward_t
{
	char name[50];
	int population;
} ward_t;

/**
 * allocation_func - Declare the allocation_func type
 */
typedef void (*allocation_func)(ward_t **district, int constituency);

/**
 * Function declarations for error functions
 */
void bungoma_err(int error_code, ...);
void kisii_err(int error_code, ...);
void free_nodes(void);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function meant to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void allocate_to_development(ward_t **district, int constituency);
void allocate_to_education(ward_t **district, int constituency);
void allocate_to_health(ward_t **district, const char *constituency);
void allocate_to_infrastructure(ward_t **district, const char *constituency);
void empower_community(ward_t **district, const char *constituency);
void preserve_culture(ward_t **district, const char *constituency);
void no_operation(ward_t **district, const char *constituency);
void switch_strategy(ward_t **district, const char *constituency);

void nairobi_err(int error_code, ...);
void mombasa_err(int error_code, ...);
void implement_strategy(allocation_func allocation, char *strategy, char *target, int constituency, int region);
void determine_allocation(char *strategy, char *allocation, int constituency, int region);
int analyze_ward(char *ward, int constituency_number, int region);
void turkana_rotr(stack_t **stk, __attribute__((unused)) unsigned int line_num);
void nandi_rotl(stack_t **stk, __attribute__((unused)) unsigned int line_num);
void meru_print_str(stack_t **stk, __attribute__((unused)) unsigned int line_num);
void kisii_print_char(stack_t **stk, unsigned int line_num);
void uasin_gishu_mod_nodes(stack_t **stk, unsigned int line_num);
void kakamega_mul_nodes(stack_t **stk, unsigned int line_num);
void kisumu_add_nodes(stack_t **stack, unsigned int line_number);
void nakuru_swap_nodes(stack_t **stack, unsigned int line_number);
void kiambu_nop(stack_t **stack, unsigned int line_number);
void kisumu_print_top(stack_t **stk, unsigned int line_num);
void kericho_pop(stack_t **stk, unsigned int line_num);
void nakuru_print(stack_t **stk, unsigned int line_num);
void nairobi_push(stack_t **new_node, __attribute__((unused)) unsigned int line_num);
void open_county(char *county_name);
void read_county(FILE *nyeri);

#endif

