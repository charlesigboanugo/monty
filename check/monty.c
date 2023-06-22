#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

extern int operand;
extern stack_t *stack;
extern unsigned int size;
static int func_err = 0;
extern int format;

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

void print_err(char *errmsg, unsigned int line_num)
{
	fprintf(stderr, "L%u: %s\n", line_num, errmsg);
}

void clean_err_exit(int file, unsigned int line_num)
{
	if (close(file) == -1)
		print_err("", line_num);
	free_stk(topstack);
	exit(EXIT_FAILURE);
}

void pushfunc(stack_t **stack, unsigned int line_num)
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

void pallfunc(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr = *stack;

	for (; ptr != NULL; ptr = ptr->next)
		printf("%i\n", ptr->n);		
}

void pintfunc(stack_t **stack, unsigned int line_num)
{
	if (*stack != NULL)
		printf("%i\n", (*stack)->n);		
	else
	{
		print_err("can't pint, stack empty", line_num);
		func_err = -1;
	}
}

void popfunc(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		print_err("can't pop, stack empty", line_num);
		func_err = -1;
		return;
	}
	*stack = (*stack)->next;
	free(ptr);
	size--;
}

void swapfunc(stack_t **stack, unsigned int line_num)
{
	int n;

	if (size < 2)
	{
		print_err("can't swap, stack too short", line_num);
		func_err = -1;
		return;
	}
	n = (*stack)->n;	
	(*stack)->n = (*stack)->next->n; 	
	(*stack)->next->n = n;
}

void addfunc(stack_t **stack, unsigned int line_num)
{
	if (size < 2)
	{
		print_err("can't add, stack too short", line_num);
		func_err = -1;
		return;
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	popfunc(stack, line_num);
}

void nopfunc(stack_t **stack, unsigned int line_num)
{
	return;
}

void subfunc(stack_t **stack, unsigned int line_num)
{
	if (size < 2)
	{
		print_err("can't sub, stack too short", line_num);
		func_err = -1;
		return;
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	popfunc(stack, line_num);
}

void divfunc(stack_t **stack, unsigned int line_num)
{
	if (size < 2)
	{
		print_err("can't div, stack too short", line_num);
		func_err = -1;
		return;
	}
	if ((*stack)->n == 0)
	{
		print_err("division by zero", line_num);
		func_err = -1;
		return;
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	popfunc(stack, line_num);
}

void mulfunc(stack_t **stack, unsigned int line_num)
{
	if (size < 2)
	{
		print_err("can't mul, stack too short", line_num);
		func_err = -1;
		return;
	}
	(*stack)->next->n = (*stack)->n * (*stack)->next->n;
	popfunc(stack, line_num);
}

void modfunc(stack_t **stack, unsigned int line_num)
{
	if (size < 2)
	{
		print_err("can't mod, stack too short", line_num);
		func_err = -1;
		return;
	}
	if ((*stack)->n == 0)
	{
		print_err("division by zero", line_num);
		func_err = -1;
		return;
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	popfunc(stack, line_num);
}

void pcharfunc(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		print_err("can't pchar, stack empty", line_num);
		func_err = -1;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		print_err("can't pchar, value out of range", line_num);
		func_err = -1;
		return;
	}
	printf("%c\n", (char) (*stack)->n);		
}

void pstrfunc(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr = *stack;

	for (; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->n <= 0 || ptr->n > 127)
			break;
		printf("%c", (char) ptr->n);		
	}
	printf("\n");
}

void rotlfunc(stack_t **stack, unsigned int line_num)
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

void rotrfunc(stack_t **stack, unsigned int line_num)
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

void stackfunc(stack_t **stack, unsigned int line_num)
{
	if (format)
		format--;
}

void queuefunc(stack_t **stack, unsigned int line_num)
{
	if (!format)
		format++;
}

int exec_instr(instruction_t *inst, char *opcode, unsigned int line_num)
{
	void (*op_func)(stack_t **stack, unsigned int line_number);
	unsigned int i;

	for (i = 0; i < 18; i++)
	{
		if (strcmp(opcode, inst[i].opcode) == 0) 
			op_func = inst[i].f;
	}
	op_func(&topstack, line_num);
	if (func_err == -1)
		return (-1);
	return (0);
}

int read_trim_line(int file, char **line, unsigned int line_num)
{
	char *ptr, byte;
	ssize_t bytes_read;
	unsigned int index = 0, line_is_comment = 0;

	ptr = malloc(sizeof(*ptr) * 99);
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-2);
	}
	*line = ptr;
	while (byte != '\n' && index < 99)
	{
		bytes_read = read(file, &byte, 1);
		if (bytes_read == -1)
		{
			print_err("", line_num);
			return (-2);
		}
		if (bytes_read == 0)
			break;
		if (byte == '#' && index == 0 && !line_is_comment)
			line_is_comment = 1;
		if (byte != ' ' && byte != '\n' && !line_is_comment)
		{
			ptr[index] = byte;
			index++;
		}	
	}
	if (index == 0)
	{
		if (bytes_read == 0)
			return (EOF);
		return (0);
	}
	ptr[index] = '\0';
	return (index);
}

char *get_opcode(char *line_buf, instruction_t *inst, unsigned int line_num)
{
	unsigned int i;

	for(i = 0; i < 18; i++)
	{
		if (strstr(line_buf, inst[i].opcode) == line_buf)
			return (inst[i].opcode);
	}
	print_err("unknown instruction", line_num);
	return (NULL);
}
int *set_operand(char *line_buf, char *opcode, unsigned int line_num)
{
	int sign = 1;
	char *wtr = NULL;

	wtr = line_buf + strlen(opcode);
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
	print_err("usage: push integer", line_num);
	return (NULL);
}
int opcode_req_arg(char *opcode)
{
	if (strcmp(opcode, "push") == 0)
		return 1;
	return (0);
}

/**
* main - an interpreter for monty bytecode file
* @ac: number of arguments
* @ac: program arguments
*
* Return: 0 if successful
*/

int main(int ac, const char **av)
{
	instruction_t inst[18] = {
		{"push", pushfunc}, {"pall", pallfunc},
		{"pint", pintfunc}, {"pop", popfunc},
		{"swap", swapfunc}, {"add", addfunc},
		{"nop", nopfunc}, {"sub", subfunc},
		{"div", divfunc}, {"mul", mulfunc},
		{"mod", modfunc}, {"sub", subfunc},
		{"pchar", pcharfunc}, {"pstr", pstrfunc},
		{"rotl", rotlfunc}, {"rotr", rotrfunc},
		{"stack", stackfunc}, {"queue", queuefunc}
	};
	int file, byte_read;
	unsigned int line_num = 1;
	char *opcode = NULL, *line = NULL;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = open(av[1], O_RDONLY);
	if (file == -1)
	{
		dprintf(STDIN_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	
	while (1)
	{
		free(line);
		byte_read = read_trim_line(file, &line, line_num);
		if (byte_read == -2)
			clean_err_exit(file, line_num);
		if (byte_read == EOF)
			break;
		if (byte_read == 0)
		{
			line_num++;
			continue;
		}
		opcode = get_opcode(line, inst, line_num);
		if (opcode == NULL)
			clean_err_exit(file, line_num);
		if (opcode_req_arg(opcode))
		{
			if (set_operand(line, opcode, line_num) == NULL)
				clean_err_exit(file, line_num);
		}
		if (exec_instr(inst, opcode, line_num) == -1)
			clean_err_exit(file, line_num);
		line_num++;
	}
	free(line);
	free_stk(topstack);
	if (close(file) == -1)
		print_err("", line_num);
	return (0);
}
