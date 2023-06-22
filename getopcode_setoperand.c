#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

extern int operand;

/*
* opcode_req_arg -
* @opcode:
*
* Return:
*/
int opcode_req_arg(char *opcode)
{
	if (strcmp(opcode, "push") == 0)
		return (1);
	return (0);
}

/**
*
*
*
*
*
*/
char *get_opcode(char *line_buf, instruction_t *inst, unsigned int line_num)
{
	unsigned int i;
	char *opcode = NULL;

	for(i = 0; i < 17; i++)
	{
		if (strstr(line_buf, inst[i].opcode) == line_buf)
		{
			opcode = inst[i].opcode;
			break;
		}
	}
	if (opcode)
	{
		if (opcode_req_arg(opcode))
		{
			if (set_operand(line_buf, opcode, line_num) == NULL)
				return (NULL);
		}
		return (opcode);
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, line_buf);
	return (NULL);
}

/**
*
*
*
*
*
*/
int *set_operand(char *line_buf, char *opcode, unsigned int line_num)
{
	int sign = 1;
	char *wtr = NULL;

	wtr = line_buf + strlen(opcode);
	if (*wtr == ' ')
	{
		for (; *wtr != '\0'; wtr++)
		{
			if (*wtr == '-')
				sign *= -1;
			if (isdigit(*wtr))
			{
				operand =  sign * atoi(wtr);
				return (&operand);
			}
		}
	}
	print_err("usage: push integer", line_num);
	return (NULL);
}
