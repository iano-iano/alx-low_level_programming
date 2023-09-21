#include "main.h"
/**
 * parse_and_execute_command - parses and executes input
 * @line: The command line input
 * @env: The environment variables
 */
void parse_and_execute_command(const char *line, char *env[])
{
	char cmd[1024];
	char *token;
	int argCount = 0;
	char *args[] = {"/bin/ls", NULL};

	strncpy(cmd, line, sizeof(cmd));
	token = strtok(cmd, " \t\n");
	while (token != NULL && argCount < 31)
	{
		args[argCount] = token;
		argCount++;
		token = strtok(NULL, " \t\n");
	}
	args[argCount] = NULL;
	if (execve(args[0], args, env) == -1)
	{
		perror("./prompt");
	}
}
