#include "main.h"
/**
 * execute_command15 - execte function
 * @command:user input
 */
void execute_command15(const char *command)
{
	char *args[32], *token;
	int argCount = 0;

	if (command[0] == '#')
	{
		return;
	}
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
	else
		execute_external_command(args);
}
