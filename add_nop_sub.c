#include "monty.h"

/**
*
*
*
*
*
*/
void add_f(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		print_err("can't add, stack too short", line_num);
		func_err = -1;
		return;
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	pop_f(stack, line_num);
}

/**
*
*
*
*
*
*/
void nop_f(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}

/**
*
*
*
*
*
*/
void sub_f(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		print_err("can't sub, stack too short", line_num);
		func_err = -1;
		return;
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop_f(stack, line_num);
}

