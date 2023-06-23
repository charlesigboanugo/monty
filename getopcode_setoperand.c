#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_number - checks to see if input is a number
 * @s: input to check for numberhood
 * Return: 1 if it is a number, 0 if not
 */

int is_number(char *s)
{
	int i;

	i = 0;
	if (s[i] == '-')
		i++;
	if (s[i] == '\0' || s[i] == ' ')
		return (0);
	while (*(s + i) != '\0' && *(s + i) != ' ')
	{
		if (*(s + i) >= '0' && *(s + i) <= '9')
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

/**
* opcode_req_arg - checks if an instruction (opcode) requires an operand
* @opcode: the instruction
*
* Return: 1 if it requires otherwise 0
*/
int opcode_req_arg(char *opcode)
{
	if (strcmp(opcode, "push") == 0)
		return (1);
	return (0);
}

/**
* get_opcode - finds an opcode from a line read from a monty file
* @line_buf: buffer where the line is stored
* @inst: contains all posssible instructions (opcode)
* @line_num: the line number of the monty file
*
* Return: the opcode if valid else NULL
*/
char *get_opcode(char *line_buf, instruction_t *inst, unsigned int line_num)
{
	unsigned int i;
	char *opcode = NULL, *nxchar;

	for (i = 0; i < 17; i++)
	{
		if (strstr(line_buf, inst[i].opcode) == line_buf)
		{
			nxchar = line_buf + strlen(inst[i].opcode);
			if (*nxchar == ' ' || *nxchar == '\0')
			{
				opcode = inst[i].opcode;
				break;
			}
		}
	}
	if (opcode)
	{
		if (opcode_req_arg(opcode))
		{
			if (set_operand(nxchar, line_num) == NULL)
				return (NULL);
		}
		return (opcode);
	}
	fprintf(stderr, "L%u: unknown instruction ", line_num);
	while (*line_buf != ' ' && *line_buf != '\0')
	{
		fprintf(stderr, "%c", *line_buf);
		line_buf++;
	}
	fprintf(stderr, "\n");
	return (NULL);
}

/**
* set_operand - gets and sets the operand of an instruction needing one
* @nxchar: pointer to the next character after the instruction
* @line_num: the line number of the monty file
*
* Return: address where the operand is stored else NULL
*/
int *set_operand(char *nxchar, unsigned int line_num)
{
	if (*nxchar == ' ')
	{
		while (*nxchar == ' ')
			nxchar++;
		if (is_number(nxchar))
		{
			operand = atoi(nxchar);
			return (&operand);
		}
	}
	print_err("usage: push integer", line_num);
	return (NULL);
}
