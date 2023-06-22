#include "monty.h"
#include <stdlib.h>

extern int func_err;
extern int size;

/**
*
*
*
*
*
*/
void pop_f(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		print_err("can't pop an empty stack", line_num);
		func_err = -1;
		return;
	}
	*stack = (*stack)->next;
	free(ptr);
	size--;
}
