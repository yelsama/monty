#include "main.h"

/**
 * push - prints list elements
 * @stack: holds the pointer to the first element
 * @number: number to be stored at the node
 * Return: the new stack for the node
 */
void	push(stack_t **stack, unsigned int number)
{
	stack_t	*new_stack;

	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_stack->n = number;
	new_stack->next = *stack;
	new_stack->prev = NULL;
	if (*stack)
		(*stack)->prev = new_stack;
	*stack = new_stack;
}
