#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

extern int func_err;

/**
*
*
*
*
*
*/
void pstr_f(stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	stack_t *ptr = *stack;

	for (; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->n <= 0 || ptr->n > 127)
			break;
		printf("%c", (char) ptr->n);		
	}
	printf("\n");
}

/**
*
*
*
*
*
*/
void pchar_f(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		print_err("can't pchar, stack empty", line_num);
		func_err = -1;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		print_err("can't pchar, value out of range", line_num);
		func_err = -1;
		return;
	}
	printf("%c\n", (char) (*stack)->n);		
}
