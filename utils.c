#include "main.h"

/**
 * reset_string - check the code
 * @str: file descriptor of the op code file
 * @len: length of the string
 */
void	reset_string(char **str, int len)
{
	int	i = -1;
	char *tmp = *str;

	if (!str || !*str)
		return;
	while (tmp[++i] && i < len)
		tmp[i] = 0;
}
