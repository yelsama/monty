#include "main.h"

/**
 * execute_line - check the code
 * @line: current line to execute
 * @line_no: line order in the file
 * @onboard: left part of reading
 * @fd: file descriptor of open file
 * @stack: main stack;
 */
void	execute_line(char *line, int line_no, char *onboard,
	int fd, stack_t **stack)
{
	char	*tmp;
	char	*op_code = NULL;
	void	(*f)(stack_t**, unsigned int);

	tmp = line;
	while (*tmp == ' ')
		tmp++;
	if (*tmp == '\n')
		return;
	op_code = extract_op_code(line, onboard, fd, stack);
	f = get_op_code(op_code);
	free(op_code);
	if (!f)
		unknown_err(line, line_no, onboard, fd, stack);
	if (f == push)
	{
		tmp += 5;
		if (*tmp == '+' || *tmp == '-')
			tmp++;
		if (!*tmp || *tmp < '0' || *tmp > '9')
			push_err(line, line_no, onboard, fd, stack);
		else
			f(stack, atoi(tmp));
	}
	else if (f == pall)
	{
		if ((!tmp[4] || tmp[4] == ' ' || tmp[4] == '\n'))
			f(stack, 0);
		else
			unknown_err(line, line_no, onboard, fd, stack);
	}
	else
		printf("welcome to nowhere\n");
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
		if (line[0] != '\n')
			execute_line(line, ++line_no, onboard, fd, &stack);
		free(line);
		line = NULL;
		line = get_next_line(fd, &onboard);
	}
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
	int	fd;

	if (argc != 2)
		return (fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (fprintf(stderr, "Error: Can't open file %s\n",
				argv[1]), exit(EXIT_FAILURE), 1);
	do_instructions_on_file(fd);
	close(fd);
	return (0);
}
