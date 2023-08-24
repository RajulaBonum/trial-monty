#include "monty.h"

/** Program to pop */

void pop(stack_t **stack, unsigned int line_number)
{
	int value;
	if (*stack == NULL)
	{
		fprintf(stderr, "L %u: can't pop an empty stack\n", line_number);
		return (EXIT_FAILURE);
	}
	stack_t *temp = NULL;
	temp = *stack;

	while (temp != NULL)
	{
		temp = temp->next;
	}
	free(temp);
}
