#include "main.h"
/**
 *handle_env_command - env command
 *@env: array of environments
 *
 *
 */
void handle_env_command(char **env)
{
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
