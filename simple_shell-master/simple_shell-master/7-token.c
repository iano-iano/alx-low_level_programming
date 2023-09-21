#include "main.h"
/**
 * command2 - executes user's input
 * @line:user input
 *
 */
void command2(char *line)
{
	char *args[32], *env[] = {NULL}, *end;
	int argCount = 0, status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
	}
	else if (child_pid == 0)
	{
		while (*line != '\0' && argCount < 31)
		{
			while (*line == ' ' || *line == '\t')
			{
				line++;
			}
			end = strchr(line, ' ');
			if (end == NULL)
			{
				end = line + strlen(line);
			}
			args[argCount] = (char *)malloc(end - line + 1);
			strncpy(args[argCount], line, end - line);
			args[argCount][end - line] = '\0';
			argCount++;
			line = end;
		}
		args[argCount] = NULL;
		if (execve(args[0], args, env) == -1)
		{
			perror("./prompt");
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
