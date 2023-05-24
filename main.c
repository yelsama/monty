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
 * execute_line - check the code
 * @line: current line to execute
 * @line_no: line order in the file
 * @onboard: left part of reading
 * @fd: file descriptor of open file
 */
void	execute_line(char *line, int line_no, char *onboard, int fd)
{
	printf("got line no %d: %s\n", line_no, line);
	void (onboard);
	void (fd);
}

/**
 * do_instructions_on_file - check the code
 * @fd: file descriptor of the op code file
 * Return: 0 upon finsh or number of error line.
 */
int	do_instructions_on_file(int fd)
{
	stack_t	*stack = NULL;
	char	*line = NULL;
	char	*onboard = NULL;
	int		line_no = 0;

	line = get_next_line(fd, &onboard);
	while (line)
	{
		execute_line(line, ++line_no, onboard, fd);
		free(line);
		line = NULL;
		line = get_next_line(fd, &onboard);
	}
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	pall(stack);
	dlt_stack(stack);
	return (0);
}

/**
 * main - check the code
 * @argc: number of argumnets
 * @argv: string array of arguments
 * Return: exit status.
 */
int	main(int argc, char **argv)
{
	int	fd, err_line;

	if (argc != 2)
		return (fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (fprintf(stderr, "Error: Can't open file %s\n",
				argv[1]), exit(EXIT_FAILURE), 1);
	err_line = do_instructions_on_file(fd);
	close(fd);
	if (err_line)
		return (fprintf(stderr, "L%d: unknown instruction <opcode>\n",
				err_line), exit(EXIT_FAILURE), 1);
	return (0);
}
