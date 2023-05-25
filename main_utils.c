#include "monty.h"

/**
 * extract_op_code - check the code
 * @line: current line to execute
 * @onboard: left part of reading
 * @fd: file descriptor of open file
 * @stack: main stack;
 * Return: operation code as string
 */
char	*extract_op_code(char *line, char *onboard,
		int fd, stack_t **stack)
{
	char	*tmp;
	char	*op_code = NULL;
	int		i = 0;

	tmp = line;
	while (*tmp == ' ')
		tmp++;
	while (tmp[i] && tmp[i] != ' ' && tmp[i] != '\n')
		i++;
	op_code = malloc(i + 1);
	if (!op_code)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line);
		close(fd);
		if (onboard)
			free(onboard);
		dlt_stack(*stack);
		exit(EXIT_FAILURE);
	}
	strncpy(op_code, tmp, i);
	op_code[i] = 0;
	return (op_code);
}

/**
 * get_op_code - check the code
 * @s: operation as string
 * Return: pointer to the funcion if suitalbe
 */
void	(*get_op_code(char *s))(stack_t **, unsigned int)
{
	int	i = -1;
	instruction_t	codes[] = {{"push", push},
	{"pall", pall}, {"pint", pint}, {"pop", pop},
	{"swap", swap}, {"add", add}, {"nop", nop},
	{"sub", sub}, {"div", mdiv}, {"mul", mul},
	{"mod", mod}, {"pchar", pchar}
	};

	while (codes[++i].opcode)
	{
		if (strcmp(s, codes[i].opcode) == 0)
			return (codes[i].f);
	}
	return (NULL);
}

/**
 * nop - prints list elements
 * @stack: holds the pointer to the first element
 * @number: number to be stored at the node
 * Return: the new stack for the node
 */
void	nop(stack_t **stack, unsigned int number)
{
	(void)stack;
	(void)number;
}
