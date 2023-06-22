#include "monty.h"
#include <stdlib.h>

/**
*
*
*
*
*
*/
void rotl_f(stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	stack_t *ptr = *stack;
	
	if (ptr != NULL && ptr->next != NULL)
	{
		while (ptr->next->next != NULL)
			ptr = ptr->next;
		ptr->next->next = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		ptr->next->next->prev = ptr->next;
		ptr->next->next->next = NULL;
	}
}

/**
*
*
*
*
*
*/
void rotr_f(stack_t **stack, __attribute__((unused)) unsigned int line_num)
{
	stack_t *ptr = *stack;
	
	if (ptr != NULL && ptr->next != NULL)
	{
		while (ptr->next->next != NULL)
			ptr = ptr->next;
		ptr->next->next = *stack;
		(*stack)->prev = ptr->next;
		*stack = ptr->next;
		ptr->next->prev = NULL;
		ptr->next = NULL;
	}
}
