#include "monty.h"

/**
 * the_rest - check the code
 * @f: pointer to funcion
 * @line: current line to execute
 * @line_no: line order in the file
 * @onboard: left part of reading
 * @fd: file descriptor of open file
 * @stack: main stack;
 */
void	the_rest(void	(*f)(stack_t**, unsigned int), char *line,
	int line_no, char *onboard, int fd, stack_t **stack)
{
		if (f == sub)
			if (!*stack || !(*stack)->next)
				sub_err(line, line_no, onboard, fd, stack);
		if (f == mdiv)
		{
			if (!*stack || !(*stack)->next)
				div_err1(line, line_no, onboard, fd, stack);
			if ((*stack)->n == 0)
				div_err2(line, line_no, onboard, fd, stack);
		}
		if (f == mul)
			if (!*stack || !(*stack)->next)
				mul_err(line, line_no, onboard, fd, stack);
		if (f == mod)
		{
			if (!*stack || !(*stack)->next)
				mod_err1(line, line_no, onboard, fd, stack);
			if ((*stack)->n == 0)
				mod_err2(line, line_no, onboard, fd, stack);
		}
		if (f == pchar)
		{
			if (!*stack)
				pchar_err2(line, line_no, onboard, fd, stack);
			if ((*stack)->n < 0 || (*stack)->n > 127)
				pchar_err1(line, line_no, onboard, fd, stack);
		}
}

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
	int		n = 0;
	char	*op_code = NULL;
	void	(*f)(stack_t**, unsigned int);

	tmp = line;
	while (*tmp == ' ')
		tmp++;
	if (*tmp == '\n' || *tmp == '#')
		return;
	op_code = extract_op_code(line, onboard, fd, stack);
	f = get_op_code(op_code);
	free(op_code);
	if (!f)
		unknown_err(line, line_no, onboard, fd, stack);
	if (f == push)
	{
		tmp += 4;
		while (*tmp == ' ')
			tmp++;
		n = atoi(tmp);
		if (!isdigit(*tmp))
			push_err(line, line_no, onboard, fd, stack);
	}
	if (f == pint)
		if (!*stack)
			pint_err(line, line_no, onboard, fd, stack);
	if (f == pop)
		if (!*stack)
			pop_err(line, line_no, onboard, fd, stack);
	if (f == swap)
		if (!*stack || !(*stack)->next)
			swap_err(line, line_no, onboard, fd, stack);
	if (f == add)
		if (!*stack || !(*stack)->next)
			add_err(line, line_no, onboard, fd, stack);
	the_rest(f, line, line_no, onboard, fd, stack);
	f(stack, n);
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
	char	*tmp;
	int		line_no = 0;

	line = get_next_line(fd, &onboard);
	while (line)
	{
		tmp = line;
		while (*tmp == ' ')
			tmp++;
		if (*tmp != '\n' && *tmp != '\0')
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
	int		fd;
	char	*extent;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	extent = strrchr(argv[1], '.');
	if (!extent || extent[1] != 'm' || extent[2] != '\0')
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	do_instructions_on_file(fd);
	close(fd);
	return (0);
}
