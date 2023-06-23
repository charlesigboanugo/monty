#ifndef MONTYH
#define MONTYH
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int opcode_req_arg(char *opcode);
void add_f(stack_t **stack, unsigned int line_num);
void nop_f(stack_t **stack, unsigned int line_num);
void sub_f(stack_t **stack, unsigned int line_num);
void div_f(stack_t **stack, unsigned int line_num);
void mul_f(stack_t **stack, unsigned int line_num);
void print_err(char *errmsg, unsigned int line_num);
void clean_err_exit(char* line, int file, stack_t *stack);
int exec_instr(instruction_t *, stack_t **, char *, unsigned int);
char *get_opcode(char *line_buf, instruction_t *inst, unsigned int line_num);
int *set_operand(char *line_buf, char *opcode, unsigned int line_num);
void mod_f(stack_t **stack, unsigned int line_num);
void swap_f(stack_t **stack, unsigned int line_num);
void pall_f(stack_t **stack, unsigned int line_num);
void pint_f(stack_t **stack, unsigned int line_num);
void queue_f(stack_t **stack, unsigned int line_num);
void stack_f(stack_t **stack, unsigned int line_num);
void free_stk(stack_t *stack);
void rotr_f(stack_t **stack, unsigned int line_num);
void rotl_f(stack_t **stack, unsigned int line_num);
void pop_f(stack_t **stack, unsigned int line_num);
void pstr_f(stack_t **stack, unsigned int line_num);
void pchar_f(stack_t **stack, unsigned int line_num);
void push_f(stack_t **stack, unsigned int line_num);
int read_trim_line(int file, char **line, unsigned int line_num);
void print_err_exit(char *errmsg1, char *errmsg2);
void close_file(int fd);

extern int operand;
int operand;
extern int func_err;
int func_err;
extern int format;
int format;

#endif
