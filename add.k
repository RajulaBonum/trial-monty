#include "monty.h"

/** add top two twe elements */

void add(void)
{
	int add;
	if (top < 1)
	{
		printf("L<line_number>: can't add, stack too short\n");
		return (EXIT_FAILURE);
	}
	add = stack[top] + stack[top-1];
	top = top -1;
	stack[top] = add;
}
