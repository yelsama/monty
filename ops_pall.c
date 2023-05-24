#include "main.h"

/**
 * pall - check the code
 * @stack: head of double linked list
 * Return: number of nodes
 */
void	pall(stack_t *stack, unsigned int number)
{
	(void)number;
	while (stack)
	{
		fprintf(stdout, "%d\n", stack->n);
		stack = stack->next;
	}
}
