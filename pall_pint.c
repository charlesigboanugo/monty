#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
* pall_f - prints all the values on the stack, starting from
* the top of the stack
* @stack: pointer to the top of the stack
* @line_num: line of the instruction executed
*
* Return: void
*/

void pall_f(stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	stack_t *ptr = *stack;

	for (; ptr != NULL; ptr = ptr->next)
		printf("%i\n", ptr->n);
}

/**
* pint_f - prints the value at the top of the stack
* @stack: pointer to the top of the stack
* @line_num: line of the instruction executed
*
* Return: void
*/
void pint_f(stack_t **stack, unsigned int line_num)
{
	if (*stack != NULL)
		printf("%i\n", (*stack)->n);
	else
	{
		print_err("can't pint, stack empty", line_num);
		func_err = -1;
	}
}
