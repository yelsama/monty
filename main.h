#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int				n;
	struct stack_s	*prev;
	struct stack_s	*next;
}	stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char	*opcode;
	void	(*f)(stack_t **stack, unsigned int line_number);
}	instruction_t;

char	*get_next_line(int fd, char **onboard);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src);
void	*ft_calloc(size_t count, size_t size);

void	dlt_stack(stack_t *head);
char	*extract_op_code(char *line, int line_no, char *onboard,
			int fd, stack_t **stack);
void	push_err(char *line, int line_no, char *onboard,
			int fd, stack_t **stack);
void	unknown_err(char *line, int line_no, char *onboard,
			int fd, stack_t **stack);

void	pall(const stack_t *stack, unsigned int number);
void	push(stack_t **stack, unsigned int number);
void	(*get_op_code(char *s))(stack_t **, unsigned int);
#endif
