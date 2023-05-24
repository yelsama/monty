#include "monty.h"

/**
 * swap - prints list elements
 * @stack: holds the pointer to the first element
 * @number: number to be stored at the node
 * Return: the new stack for the node
 */
void	swap(stack_t **stack, unsigned int number)
{
	stack_t	*tmp;
	int		sp;

	(void)number;
	tmp = *stack;
	if (!tmp || tmp->next)
		return;
	sp = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = sp;
}

/**
 * swap_err- check the code
 * @line: current line to execute
 * @line_no: line order in the file
 * @onboard: left part of reading
 * @fd: file descriptor of open file
 * @stack: main stack;
 */
void	swap_err(char *line, int line_no, char *onboard,
	int fd, stack_t **stack)
{
	free(line);
	if (onboard)
		free(onboard);
	close(fd);
	dlt_stack(*stack);
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
	exit(EXIT_FAILURE);
}
