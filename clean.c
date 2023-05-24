#include "main.h"

/**
 * dlt_stack- check the code
 * @head: head of double linked list
 * Return: nothing
 */
void	dlt_stack(stack_t *head)
{
	if (!head)
		return;
	dlt_stack(head->next);
	free(head);
	head = NULL;
}

/**
 * unknown_err- check the code
 * @line: current line to execute
 * @line_no: line order in the file
 * @onboard: left part of reading
 * @fd: file descriptor of open file
 * @stack: main stack;
 */
void	unknown_err(char *line, int line_no, char *onboard,
	int fd, stack_t **stack)
{
	char	*tmp;
	int		i = 0;
	char	*op_code = NULL;

	tmp = line;
	while (*tmp == ' ')
		tmp++;
	while (tmp[i] && tmp[i] != ' ')
		i++;
	op_code = malloc(i + 1);
	if (!op_code)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strncpy(op_code, tmp, i);
	op_code[i] = 0;
	fprintf(stderr, "L%d: unknown instruction %s\n", line_no, op_code);
	free(op_code);
	free(line);
	if (onboard)
		free(onboard);
	close(fd);
	dlt_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * push_err- check the code
 * @line: current line to execute
 * @line_no: line order in the file
 * @onboard: left part of reading
 * @fd: file descriptor of open file
 * @stack: main stack;
 */
void	push_err(char *line, int line_no, char *onboard,
	int fd, stack_t **stack)
{
	free(line);
	if (onboard)
		free(onboard);
	close(fd);
	dlt_stack(*stack);
	fprintf(stderr, "L%d: usage: push integer\n", line_no);
	exit(EXIT_FAILURE);
}
