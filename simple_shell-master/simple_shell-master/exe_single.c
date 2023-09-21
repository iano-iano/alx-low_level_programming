#include "main.h"
/**
 *execute_single_command - execute a single command
 *@args:argument array
 *Return:1 success
 */
int execute_single_command(char *args[])
{
	char *path, *path_to_exec;

	if (strchr(args[0], '/') != NULL)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error");
		}
	}
	else
	{
		path = getenv("PATH");
		if (path == NULL)
		{
			path = "/bin:/usr/bin";
		}
		path_to_exec = search_path(args[0], path);
		if (path_to_exec != NULL)
		{
			if (execve(path_to_exec, args, NULL) == -1)
			{
				perror("Error");
				free(path_to_exec);
				return (0);
			}
			free(path_to_exec);
		}
		else
		{
			fprintf(stderr, "%s : command not found", args[0]);
			return (0);
		}
	}
	return (1);
}
