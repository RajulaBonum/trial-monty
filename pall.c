#include "monty.h"


void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	temp = *stack;
	
	if (*stack == NULL)
	{
		return;
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
