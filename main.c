#include "main.h"

int	do_instructions_on_file(int fd)
{
	printf("hellow dear\n");
	return (0);
}

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
