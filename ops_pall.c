#include "main.h"

/**
 * pall - check the code
 * @stack: head of double linked list
 * Return: number of nodes
 */
void	pall(stack_t **stack, unsigned int number)
{
	(void)number;
	stack_t	*tmp = *stack;

	while (tmp)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}
