#include "monty.h"

/**
 * mul - prints list elements
 * @stack: holds the pointer to the first element
 * @number: number to be stored at the node
 * Return: the new stack for the node
 */
void	mul(stack_t **stack, unsigned int number)
{
	stack_t	*tmp;

	(void)number;
	tmp = *stack;
	if (!tmp || !tmp->next)
		return;
	tmp->next->n = tmp->next->n * tmp->n;
	pop(stack, number);
}

/**
 * mul_err- check the code
 * @line: current line to execute
 * @line_no: line order in the file
 * @onboard: left part of reading
 * @fd: file descriptor of open file
 * @stack: main stack;
 */
void	mul_err(char *line, int line_no, char *onboard,
	int fd, stack_t **stack)
{
	free(line);
	if (onboard)
		free(onboard);
	close(fd);
	dlt_stack(*stack);
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
	exit(EXIT_FAILURE);
}
