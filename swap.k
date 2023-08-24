#include "monty.h"

/** swaps the top two elements of a stack */

void swap(stack_t **stack, unsigned int line_number)
{
	int value, count;

	if (top < 1)
	{
		fprintf(stderr, "L %u: can't swap, stack too short\n", line_number);
		return (EXIT_FAILURE);
	}
	
	stack_t *temp;
	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	value = temp->n;
	stack_t *temp2;
	temp2 = *stack;

	for (i = 0; i < count; i++)
	{
		temp2 = temp2->next;
	}
	value2 = temp2->n;
}
