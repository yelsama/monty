#include "monty.h"

/**
 * pop - prints list elements
 * @stack: holds the pointer to the first element
 * @number: number to be stored at the node
 * Return: the new stack for the node
 */
void	pop(stack_t **stack, unsigned int number)
{
	stack_t	*tmp;
	stack_t	*new_head;

	(void)number;
	tmp = *stack;
	if (!tmp)
		return;
	new_head = tmp->next;
	if (new_head)
		new_head->prev = NULL;
	free(tmp);
	tmp = NULL;
	*stack = new_head;
}

/**
 * pop_err- check the code
 * @line: current line to execute
 * @line_no: line order in the file
 * @onboard: left part of reading
 * @fd: file descriptor of open file
 * @stack: main stack;
 */
void	pop_err(char *line, int line_no, char *onboard,
	int fd, stack_t **stack)
{
	free(line);
	if (onboard)
		free(onboard);
	close(fd);
	dlt_stack(*stack);
	fprintf(stderr, "L%d: can't pop, stack empty\n", line_no);
	exit(EXIT_FAILURE);
}
