#include "monty.h"

/** Value at top of the stack */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L %u: can't pint, stack empty\n", line_number);
		return (EXIT_FAILURE);
	}
	stack_t *temp = NULL;
	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
	}
	printf("%d\n", temp->n);

}
