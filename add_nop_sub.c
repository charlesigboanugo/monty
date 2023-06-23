#include "monty.h"

/**
* add_f - adds the top two elements of the stack.
* @stack: pointer to the top of the stack
* @line_num: line of the instruction executed
*
* Return: void
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
* nop_f - doesn’t do anything
* @stack: pointer to the top of the stack
* @line_num: line of the instruction executed
*
* Return: void
*/
void nop_f(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}

/**
* sub_f - subtracts the top element of the stack from the second
* top element of the stack
* @stack: pointer to the top of the stack
* @line_num: line of the instruction executed
*
* Return: void
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
