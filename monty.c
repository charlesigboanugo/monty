#include "monty.h"
#include "extern.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
*
*
*/
void print_err_exit(char *errmsg1, char *errmsg2)
{
	fprintf(stderr, "%s %s\n", errmsg1, errmsg2);
	exit(EXIT_FAILURE);
}

/**
*
*
*/
void close_file(int fd)
{
	if (close(fd) == -1)
		print_err_exit("An error occured:", "can't close file");
}

/**
* main - an interpreter for monty bytecode file
* @ac: number of arguments
* @ac: program arguments
*
* Return: 0 if successful
*/

int main(int ac, char **av)
{
	stack_t *topstack = NULL;
	instruction_t inst[17] = {
		{"push", push_f}, {"pall", pall_f}, {"pint", pint_f},
		{"pop", pop_f}, {"swap", swap_f}, {"add", add_f},
		{"nop", nop_f}, {"sub", sub_f}, {"div", div_f},
		{"mul", mul_f}, {"mod", mod_f}, {"pchar", pchar_f},
		{"pstr", pstr_f}, {"rotl", rotl_f}, {"rotr", rotr_f},
		{"stack", stack_f}, {"queue", queue_f}
	};
	int file, byte_read;
	unsigned int line_num;
	char *opcode = NULL, *line = NULL;

	if (ac != 2)
		print_err_exit("USAGE:", "monty file");
	file = open(av[1], O_RDONLY);
	if (file == -1)
		print_err_exit("Error: Can't open file", av[1]);
	for (line_num = 1; 1; line_num++)
	{
		free(line);
		byte_read = read_trim_line(file, &line, line_num);
		if (byte_read == -2)
			clean_err_exit(file, topstack);
		if (byte_read == EOF)
			break;
		if (byte_read == 0)
			continue;
		opcode = get_opcode(line, inst, line_num);
		if (opcode == NULL)
			clean_err_exit(file, topstack);
		if (exec_instr(inst, &topstack, opcode, line_num) == -1)
			clean_err_exit(file, topstack);
	}
	free(line);
	free_stk(topstack);
	close_file(file);
	return (0);
}