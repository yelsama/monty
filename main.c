#include "main.h"

/**
 * do_instructions_on_file - check the code
 * @fd: file descriptor of the op code file
 * Return: 0 upon finsh or number of error line.
 */
int	do_instructions_on_file(int fd)
{
	printf("hellow dear\n");
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
		return (fprintf(stderr, "USAGE: monty file\n"), EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (fprintf(stderr, "Error: Can't open file %s\n", argv[1]), EXIT_FAILURE);
	err_line = do_instructions_on_file(fd);
	if (err_line)
		return (fprintf(stderr, "L%d: unknown instruction <opcode>\n", err_line), EXIT_FAILURE);
	return (err_line);
}
