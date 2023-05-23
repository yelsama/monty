#include "main.h"

#define BUFFER_SIZE 1024
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
 * do_instructions_on_file - check the code
 * @fd: file descriptor of the op code file
 * Return: 0 upon finsh or number of error line.
 */
int	do_instructions_on_file(int fd)
{
	stack_t	*stack;
	char	buff[BUFFER_SIZE];
	ssize_t	red_bytes = BUFFER_SIZE;

	reset_string(buff, BUFFER_SIZE);
	while (red_bytes == BUFFER_SIZE)
	{
		red_bytes = read(fd, buff, BUFFER_SIZE);
		if (red_bytes < 1)
			break;
		write(1, buff, red_bytes);
		reset_string(&buff, BUFFER_SIZE);
	}
	stack = NULL;
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
	char	*txt_cpy;

	if (argc != 2)
		return (fprintf(stderr, "USAGE: monty file\n"), EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (fprintf(stderr, "Error: Can't open file %s\n",
				argv[1]), EXIT_FAILURE);
	err_line = do_instructions_on_file(fd);
	close(fd);
	if (err_line)
		return (fprintf(stderr, "L%d: unknown instruction <opcode>\n",
				err_line), EXIT_FAILURE);
	return (err_line);
}
