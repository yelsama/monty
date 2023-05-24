#include "main.h"

/**
 * get_op_code - check the code
 * @s: operation as string
 * Return: pointer to the funcion if suitalbe
 */
void	(*get_op_code(char *s))(stack_t **, unsigned int)
{
	int	i = -1;
	instruction_t	codes[] = {{"push", push},
	{"pall", pall}
	};

	while (codes[++i].opcode)
	{
		if (strcmp(s, codes[i].opcode) == 0)
			return (codes[i].f);
	}
	return (NULL);
}

/**
 * extract_op_code - check the code
 * @line: current line to execute
 * @line_no: line order in the file
 * @onboard: left part of reading
 * @fd: file descriptor of open file
 * @stack: main stack;
 * Return: operation code as string
 */
char	*extract_op_code(char *line, int line_no, char *onboard,
		int fd, stack_t **stack)
{
	char	*tmp;
	char	*op_code = NULL;
	int		i = 0;

	tmp = line;
	while (*tmp == ' ')
		tmp++;
	while (tmp[i] && tmp[i] != ' ')
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
