#include "monty.h"

/**
* mod_f - computes the rest of the division of the second top
* element of the stack by the top element of the stack.
* @stack: pointer to the top of the stack
* @line_num: line of the instruction executed
*
* Return: void
*/
void mod_f(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		print_err("can't mod, stack too short", line_num);
		func_err = -1;
		return;
	}
	if ((*stack)->n == 0)
	{
		print_err("division by zero", line_num);
		func_err = -1;
		return;
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop_f(stack, line_num);
}

/**
* swap_f - swaps the top two elements of the stack.
* @stack: pointer to the top of the stack
* @line_num: line of the instruction executed
*
* Return: void
*/
void swap_f(stack_t **stack, unsigned int line_num)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		print_err("can't swap, stack too short", line_num);
		func_err = -1;
		return;
	}
	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}
