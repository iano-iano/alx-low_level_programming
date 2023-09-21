#include "main.h"
/**
 * execute_command14 - execte function
 * @command:command
 */
void execute_command14(const char *command)
{
	char *args[32], *token;
	int argCount = 0, i;

	token = strtok((char *)command, " \t\n");
	while (token != NULL && argCount < 31)
	{
		args[argCount] = token;
		argCount++;
		token = strtok(NULL, " \t\n");
	}
	args[argCount] = NULL;
	if (argCount == 1 && strcmp(args[0], "exit") == 0)
		exit(0);
	else if (argCount == 1 && strcmp(args[0], "env") == 0)
		handle_env_command(environ);
	for (i = 0; i < argCount; i++)
		args[i] = replace_variables(args[i]);
	execute_external_command(args);
}
