#include "monty.h"
#include <stdlib.h>

/**
* free_stk - frees a stack.
* @stack: the top of the stack
*
* Return: void
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
* stack_f - sets the format of the data to a stack (LIFO)
* @stack: pointer to the top of the stack
* @line_num: line of the instruction executed
*
* Return: void
*/
void stack_f(stack_t **stack, unsigned int line_num)
{
	(void) line_num;
	(void) stack;
	if (format)
		format--;
}

/**
* queue_f - sets the format of the data to a queue (FIFO)
* @stack: pointer to the top of the stack
* @line_num: line of the instruction executed
*
* Return: void
*/
void queue_f(stack_t **stack, unsigned int line_num)
{
	(void) line_num;
	(void) stack;
	if (!format)
		format++;
}
