#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
*
*
*
*
*
*/

void pall_f(stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	stack_t *ptr = *stack;

	for (; ptr != NULL; ptr = ptr->next)
		printf("%i\n", ptr->n);		
}

/**
*
*
*
*
*
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
