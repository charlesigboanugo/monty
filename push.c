#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

extern int format;
extern int operand;
extern int func_err;
extern unsigned int size;

/**
* pushfunc -
* @stack:
* @line_num:
*
* Return: void
*/
void push_f(stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	stack_t *ptr = NULL, *tmp = NULL;
	
	ptr = malloc(sizeof(*ptr));
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		func_err = -1;
		return;
	}
	ptr->n = operand;
	if (format == 0)
	{
		ptr->prev = NULL;
		if (*stack != NULL)
			(*stack)->prev = ptr;
		ptr->next = *stack;
		*stack = ptr;
	}
	else
	{
		ptr->next = NULL;
		if (*stack != NULL)
		{
			tmp = *stack;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = ptr;
		}
		else
			*stack = ptr;
		ptr->prev = tmp;
	}	
	size++;
}
