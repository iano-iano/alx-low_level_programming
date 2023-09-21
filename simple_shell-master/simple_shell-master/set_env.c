#include "main.h"
/**
 *handle_setenv_command - setenv command
 *@name:setenv value
 *@value:setenv value
 */
void handle_setenv_command(const char *name, const char *value)
{
	if (setenv(name, value, 1) != 0)
	{
		fprintf(stderr, "Failed to set environment variable: %s\n", name);
	}
}
