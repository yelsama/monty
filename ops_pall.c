#include "main.h"

/**
 * pall - check the code
 * @stack: head of double linked list
 * Return: number of nodes
 */
void	pall(const stack_t *stack)
{
	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
