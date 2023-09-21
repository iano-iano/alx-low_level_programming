#include "main.h"
/**
 * execute_command - execte function
 * @command:user input
 */
void execute_command(const char *command)
{
	char *args[32], *path_to_exec, *path, *token;
	int argCount = 0;

	token = strtok((char *)command, " \t\n");
	while (token != NULL && argCount < 31)
	{
		args[argCount] = token;
		argCount++;
		token = strtok(NULL, " \t\n");
	}
	args[argCount] = NULL;
	if (strchr(args[0], '/') != NULL)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		path = getenv("PATH");
		if (path == NULL)
			path = "/bin:/usr/bin"; /*Default PATH if not set*/
		path_to_exec = search_path(args[0], path);
		if (path_to_exec != NULL)
		{
			if (execve(path_to_exec, args, NULL) == -1)
			{
				perror(args[0]);
				free(path_to_exec);
				exit(EXIT_FAILURE);
			}
			free(path_to_exec);
		}
		else
			fprintf(stderr, "%s: command not found\n", args[0]);
	}
}
