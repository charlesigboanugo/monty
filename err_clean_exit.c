#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* print_err - prints message without exit
* @errmsg: error message
* @line_num: line where an error occured
*
* Return: void
*/
void print_err(char *errmsg, unsigned int line_num)
{
	fprintf(stderr, "L%u: %s\n", line_num, errmsg);
}

/**
* clean_err_exit - If an error occurs it does memory cleanup before an exit
* @line: buffer where the last executed line of the monty file is stored
* @file: file descriptor to the monty file
* @stack: the storage stack
*
*/
void clean_err_exit(char *line, int file, stack_t *stack)
{
	free(line);
	free_stk(stack);
	if (close(file) == -1)
		fprintf(stderr, "An error occured during closing of file\n");
	exit(EXIT_FAILURE);
}
