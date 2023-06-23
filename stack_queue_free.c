#include "monty.h"
#include <stdlib.h>

/**
*
*
*
*
*/
void free_stk(stack_t *stack)
{
	stack_t *ptr;

	if (stack != NULL)
	{
		while (stack != NULL)
		{
			ptr = stack;
			stack = stack->next;
			free(ptr);
		}
	}
}

/**
*
*
*
*
*
*/
void stack_f(stack_t **stack, unsigned int line_num)
{
	(void) line_num;
	(void) stack;
	if (format)
		format--;
}

/**
*
*
*
*
*
*/
void queue_f(stack_t **stack, unsigned int line_num)
{
	(void) line_num;
	(void) stack;
	if (!format)
		format++;
}
