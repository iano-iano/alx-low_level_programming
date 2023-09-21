#include "main.h"
/**
 * print_environment - Print the environment variables
 * @env: The environment variable array
 */
void print_environment(char **env)
{
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
