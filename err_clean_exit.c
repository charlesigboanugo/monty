#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
*
*
*
*
*
*/
void print_err(char *errmsg, unsigned int line_num)
{
	fprintf(stderr, "L%u: %s\n", line_num, errmsg);
}

/*
*
*
*
*
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
