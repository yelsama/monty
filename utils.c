#include "main.h"

/**
 * reset_string - check the code
 * @str: file descriptor of the op code file
 * @len: length of the string
 */
void	reset_string(char *str, int len)
{
	int	i = -1;

	if (!str)
		return;
	while (str[++i] && i < len)
		str[i] = 0;
}
