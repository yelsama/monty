#include "monty.h"

/**
 * pstr - prints list elements
 * @stack: holds the pointer to the first element
 * @number: number to be stored at the node
 * Return: the new stack for the node
 */
void	pstr(stack_t **stack, unsigned int number)
{
	stack_t	*tmp;
	char	c;

	(void)number;
	tmp = *stack;
	if (!tmp)
	{
		fprintf(STDOUT_FILENO, "\n");
		return;
	}
	while (tmp)
	{
		if (tmp->n < 1 || tmp->n > 127)
			break;
		fprintf(stdout, "%c\n", (char)tmp->n);
		tmp = tmp->next;
	}
	fprintf(STDOUT_FILENO, "\n");
}
