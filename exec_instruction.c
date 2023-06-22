#include "monty.h"
#include <string.h>

extern int func_err;

/**
*
*
*
*
*
*
*
*/
int exec_instr(instruction_t *inst, stack_t **stack, char *opc, unsigned int ln)
{
	void (*op_func)(stack_t **stack, unsigned int line_number);
	unsigned int i;
	
	for (i = 0; i < 17; i++)
	{
		if (strcmp(opc, inst[i].opcode) == 0) 
			op_func = inst[i].f;
	}
	op_func(stack, ln);
	if (func_err == -1)
		return (-1);
	return (0);
}
