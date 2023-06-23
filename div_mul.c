#include "monty.h"

/**
* div_f - divides the second top element of the stack by
* the top element of the stack.
* @stack: pointer to the top of the stack
* @line_num: line of the instruction executed
*
* Return: void
*/
void div_f(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		print_err("can't div, stack too short", line_num);
		func_err = -1;
		return;
	}
	if ((*stack)->n == 0)
	{
		print_err("division by zero", line_num);
		func_err = -1;
		return;
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop_f(stack, line_num);
}

/**
* mul_f - multiplies the second top element of the stack with
* the top element of the stack.
* @stack: pointer to the top of the stack
* @line_num: line of the instruction executed
*
* Return: void
*/
void mul_f(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		print_err("can't mul, stack too short", line_num);
		func_err = -1;
		return;
	}
	(*stack)->next->n = (*stack)->n * (*stack)->next->n;
	pop_f(stack, line_num);
}
