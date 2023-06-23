#include "monty.h"
#include <stdlib.h>

/**
* pop_f - removes the top element of the stack.
* @stack: pointer to the top of the stack
* @line_num: line of the instruction executed
*
* Return: void
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
}
