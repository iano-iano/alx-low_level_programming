#include "main.h"
/**
 * execute_command12 - execte function
 * @args:argument array
 * @success: boolean
 */
void execute_command12(char **args, bool success)
{
	int argCount = 0;

	while (args[argCount] != NULL)
		argCount++;
	if (argCount > 0)
	{
		if (strcmp(args[argCount - 1], "&&") == 0)
		{
			args[argCount - 1] = NULL;
			if (success)
				success = execute_single_command(args);
		}
		else if (strcmp(args[argCount - 1], "||") == 0)
		{
			args[argCount - 1] = NULL;
			if (!success)
				success = execute_single_command(args);
		}
		else
			success = execute_single_command(args);
	}
}
