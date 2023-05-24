#include "monty.h"

/**
 * pall - check the code
 * @stack: head of double linked list
 * @number: to follow the shape
 * Return: number of nodes
 */
void	pall(stack_t **stack, unsigned int number)
{
	stack_t	*tmp = *stack;

	(void)number;
	while (tmp)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}
