#include "monty.h"
#include <string.h>

/**
* exec_instr - executes each instruction of the monty file
* @inst: contains all possible instructions and their trigger functions
* @stk: the stack for data storage
* @opc: instruction (opcode) to be executed
* @ln: line number of instruction to be executed
*
* Return: 0 if succesful else -1
*/
int exec_instr(instruction_t *inst, stack_t **stk, char *opc, unsigned int ln)
{
	void (*op_func)(stack_t **stack, unsigned int line_number);
	unsigned int i;

	func_err = 0;
	for (i = 0; i < 17; i++)
	{
		if (strcmp(opc, inst[i].opcode) == 0)
			op_func = inst[i].f;
	}
	op_func(stk, ln);
	if (func_err == -1)
		return (-1);
	return (0);
}
