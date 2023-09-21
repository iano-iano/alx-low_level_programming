#include "main.h"
/**
 * execute_command13 - execte function
 * @command:command
 */
void execute_command13(const char *command)
{
	char *args[32], *token;
	int argCount = 0;

	token = strtok((char *)command, " \t\n");
	while (token != NULL && argCount < 31)
	{
		args[argCount] = token;
		argCount++;
		token = strtok(NULL, " \t\n");
	}
	args[argCount] = NULL;
	if (argCount == 1 && strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	else if (argCount == 1 && strcmp(args[0], "env") == 0)
	{
		handle_env_command(environ);
	}
	else if (argCount == 1 && strcmp(args[0], "alias") == 0)
		list_aliases();
	else if (argCount >= 2 && strcmp(args[0], "alias") == 0)
		define_aliases(argCount, args);
	else
		execute_external_command(args);
}
