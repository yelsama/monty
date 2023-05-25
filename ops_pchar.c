#include "monty.h"

/**
 * pchar - prints list elements
 * @stack: holds the pointer to the first element
 * @number: number to be stored at the node
 * Return: the new stack for the node
 */
void	pchar(stack_t **stack, unsigned int number)
{
	stack_t	*tmp;
	char	c;

	(void)number;
	tmp = *stack;
	if (!tmp)
		return;
	c = tmp->n;
	fprintf(stdout, "%c\n", c);
}

/**
 * pchar_err1- check the code
 * @line: current line to execute
 * @line_no: line order in the file
 * @onboard: left part of reading
 * @fd: file descriptor of open file
 * @stack: main stack;
 */
void	pchar_err1(char *line, int line_no, char *onboard,
	int fd, stack_t **stack)
{
	free(line);
	if (onboard)
		free(onboard);
	close(fd);
	dlt_stack(*stack);
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
	exit(EXIT_FAILURE);
}

/**
 * pchar_err2- check the code
 * @line: current line to execute
 * @line_no: line order in the file
 * @onboard: left part of reading
 * @fd: file descriptor of open file
 * @stack: main stack;
 */
void	pchar_err2(char *line, int line_no, char *onboard,
	int fd, stack_t **stack)
{
	free(line);
	if (onboard)
		free(onboard);
	close(fd);
	dlt_stack(*stack);
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
	exit(EXIT_FAILURE);
}
