#include "monty.h"

/**
 * pint - check the code
 * @stack: head of double linked list
 * @number: to follow the shape
 * Return: number of nodes
 */
void	pint(stack_t **stack, unsigned int number)
{
	stack_t	*tmp = *stack;

	(void)number;
	if (tmp)
		fprintf(stdout, "%d\n", tmp->n);
}

/**
 * pint_err- check the code
 * @line: current line to execute
 * @line_no: line order in the file
 * @onboard: left part of reading
 * @fd: file descriptor of open file
 * @stack: main stack;
 */
void	pint_err(char *line, int line_no, char *onboard,
	int fd, stack_t **stack)
{
	free(line);
	if (onboard)
		free(onboard);
	close(fd);
	dlt_stack(*stack);
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
	exit(EXIT_FAILURE);
}
