#include "monty.h"

int push_value;
int top = -1;

void push(stack_t **stack, unsigned int line_number)
{
	int number;
       	number = atoi(push_value);

	if (number == 0)
	{
		fprintf(stderr,"L %u: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}
	if (stack == NULL)
	{	
		stack_t *new = NULL;
		new = malloc(sizeof(stack_t));
		new->prev = NULL;
		new->data = push_value;
		new->next = NULL;
		*stack = new;

	}
	/** add node at the end */
	stack_t *tp = NULL;
	tp = *stack;
	while (tp != NULL)
	{
		tp = tp->next;
		top++;
	}
	stack_t *new = NULL;
       	new = malloc(sizeof(stack_t));
	new->prev = tp;
	new->next = NULL;
	new->n = push_value;

}

