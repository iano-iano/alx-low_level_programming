#include "main.h"
/**
 *execute_external_command - path finder
 *@args: array of arguments
 *
 */
void execute_external_command(char *args[])
{
	char *path, *path_to_exec;

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
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
}
