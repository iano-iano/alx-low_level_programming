#include "main.h"
/**
 * execute_command8 - execte function
 * @command:command
 */
void execute_command8(const char *command)
{
	bool success = 1;
	char *args[32], *token;
	int i, argCount = 0, status;

	token = strtok((char *)command, " \t\n");
	token = strtok((char *)command, ";");
	while (token != NULL && argCount < 31)
	{
		args[argCount] = token;
		argCount++;
		token = strtok(NULL, " \t\n");
	}
	args[argCount] = NULL;
	if (argCount == 2 && strcmp(args[0], "exit") == 0)
	{
		status = atoi(args[1]);
		exit(status);
	}
	else if (argCount == 1 && strcmp(args[0], "exit") == 0)
		exit(0);
	else if (argCount == 1 && strcmp(args[0], "env") == 0)
		handle_env_command(environ);
	else if (argCount == 3 && strcmp(args[0], "setenv") == 0)
		handle_setenv_command(args[1], args[2]);
	else if (argCount == 2 && strcmp(args[0], "unsetenv") == 0)
		handle_unsetenv_command(args[1]);
	else if (argCount == 2 && strcmp(args[0], "cd") == 0)
		handle_cd_command(args);
	else if (argCount > 0)
		execute_command12(args, success);
	else if (argCount == 1 && strcmp(args[0], "alias") == 0)
		list_aliases();
	else if (argCount >= 2 && strcmp(args[0], "alias") == 0)
		define_aliases(argCount, args);
	for (i = 0; i < argCount; i++)
		args[i] = replace_variables(args[i]);
	execute_external_command(args);
}
