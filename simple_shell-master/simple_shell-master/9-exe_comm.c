#include "main.h"
/**
 * execute_command9 - execte function
 * @command:command
 */
void execute_command9(const char *command)
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
	else if (argCount == 3 && strcmp(args[0], "setenv") == 0)
	{
		handle_setenv_command(args[1], args[2]);
	}
	else if (argCount == 2 && strcmp(args[0], "unsetenv") == 0)
	{
		handle_unsetenv_command(args[1]);
	}
	else
		execute_external_command(args);
}
