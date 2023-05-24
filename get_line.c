#include "monty.h"

/**
 * get_left - Retrieves the remaining portion
 * @onboard: The input string.
 *
 * Return: Pointer to the remaining portion of the string,
 *         or NULL if memory allocation fails.
 */
char	*get_left(char *onboard)
{
	char	*left;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (onboard[i] != '\0' && onboard[i] != '\n')
		i++;
	if (onboard[i] == '\0')
	{
		free(onboard);
		return (NULL);
	}
	left = ft_calloc((ft_strlen(onboard) - i + 1), sizeof(char));
	if (!left)
		return (NULL);
	i++;
	while (onboard[i])
		left[c++] = onboard[i++];
	free(onboard);
	return (left);
}

/**
 * get_aline - Retrieves a line from an input string.
 * @onboard: The input string.
 *
 * Return: Pointer to the line,
 *         or NULL if memory allocation fails or no line is found.
 */
char	*get_aline(char *onboard)
{
	char	*line;
	int		i;

	i = 0;
	if (!onboard[0])
		return (NULL);
	while (onboard[i] != '\n' && onboard[i] != '\0')
		i++;
	i++;
	line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	line = ft_strcpy(line, onboard);
	return (line);
}

/**
 * get_read_new_with_old - check the code
 * @fd: The file descriptor.
 * @onboard: The existing string.
 *
 * Return: Pointer to the updated onboard string,
 */
char	*get_read_new_with_old(int fd, char *onboard)
{
	char	*block;
	int		redchar;

	block = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!block)
		return (NULL);
	redchar = (int)BUFFER_SIZE;
	while (redchar != 0 && !ft_strchr(block, '\n'))
	{
		redchar = read(fd, block, BUFFER_SIZE);
		if (block[0] == '\0')
			break;
		block[redchar] = '\0';
		onboard = ft_strjoin(onboard, block);
	}
	if (redchar == -1)
	{
		if (onboard)
			free(onboard);
		free(block);
		return (NULL);
	}
	free(block);
	return (onboard);
}

/**
 * get_next_line - Reads and retrieves the next line from a file descriptor.
 * @fd: The file descriptor.
 * @onboard: for left of string
 * Return: Pointer to the next line,
 *         or NULL if memory allocation fails or an error occurs.
 */
char	*get_next_line(int fd, char **onboard)
{
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	*onboard = get_read_new_with_old(fd, *onboard);
	if (!*onboard)
		return (NULL);
	line = get_aline(*onboard);
	*onboard = get_left(*onboard);
	return (line);
}
