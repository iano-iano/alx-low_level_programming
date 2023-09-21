#include "main.h"
/**
 * execute_command11 - execte function
 * @command:command
 */
void execute_command11(const char *command)
{
	char *args[32], *currentCommand, *commands[32], *token;
	int i, argCount = 0, commandCount = 0;

	token = strtok((char *)command, ";");
	while (token != NULL && commandCount < 32)
	{
		commands[commandCount] = token;
		commandCount++;
		token = strtok(NULL, ";");
	}
	for (i = 0; i < commandCount; i++)
	{
		currentCommand = commands[i];
		token = strtok(currentCommand, " \t\n");
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
		else
			execute_external_command(args);
	}
}
