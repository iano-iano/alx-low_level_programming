#include "main.h"
/**
 *handle_unsetenv_command - unsetenv command
 *@name:unsetenv name
 *
 */
void handle_unsetenv_command(const char *name)
{
	if (unsetenv(name) != 0)
	{
		fprintf(stderr, "Failed to unset environment variable: %s\n", name);
	}
}
