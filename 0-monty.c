#include "monty.h"

/**
 * Usage : monty file
 * No of acceptet arguments - 1, else fail.
 * File should be opened by monty, else fail.
 * Validate instructions in the file:
 * 	if invalid, stop and print line of error
 * 	if valid proceed:
 * 		malloc the instruction to a stack or queue.
 * 		go to the next instruction
 * 		repeat
 */
unsigned int line_number = 0;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		// printing error to the standard error
		//
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	// open the monty bytecode
	// open in read only mode
	//
	
	FILE *file  = fopen(argv[1], "r");
	// if file can not be opened
	if (!file)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	// initializing stack and necessary variables
	
	char buffer[1024];
	stack_t *stack = NULL;

	// Reading and processing each line from the file
	
	while (fgets(buffer, sizeof(buffer), file))
	{
		line_number++;

		// Parse opcode and argument from the buffer
		instruction_t opcodes[]
		{
			{"push", op_push}
			{"pall", op_pall}
			{"pint", op_pint}
			{"pop", op_pop}
			{"swap", op_swap}
			{"add", op_add}
			{"nop", op_nop}
		};
		char opcode_from_buffer[1024];
		// copy contents of the buffer
		strcpy(opcode_from_buffer, buffer);
		/** Also char *opcode_from_buffer = buffer */		

		//search for the opcode in the opcodes array
		int found_opcode = 0;
		for (size_t i = 0; i < sizeof(opcodes); i++)
		{
			if (strcmp(opcode_from_buffer, opcode[i].opcode) == 0)
			{
				if(strcmp(opcode_from_buffer, "push") == 0)
				{
					char *token = strtok(buffer, " ");
					token = (NULL, " ");
					if (token)
					{
						push_value = atoi(token);
						push(&stack, line_number);
						break;
					}
				}
				//call the corresponding function with stack and line number
				opcode[i].f(&stack, line_number);
				found_opcode = 1;
				break;
			}
		}

		if (!found_opcode)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode_from_buffer);
			// clean up and exit
			free(stack);
			return EXIT_FAILURE;
		}
		
	}
	// close the file and free memory
	fcose(file);
	free(stack);

	return EXIT_SUCCESS;
}

