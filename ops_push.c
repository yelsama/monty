#include "main.h"

/**
 * add_dnodeint - prints list elements
 * @stack: holds the pointer to the first element
 * @line_number: number to be stored at the node
 * Return: the new stack for the node
 */
void	push(stack_t **stack, unsigned int line_number)
{
	stack_t	*new_stack;

	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_stack->n = line_number;
	new_stack->next = *stack;
	new_stack->prev = NULL;
	if (*stack)
		(*stack)->prev = new_stack;
	*stack = new_stack;
}
