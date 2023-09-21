#include "main.h"
/**
 * print2 - prints users command
 *
 */
void print2(void)
{
	while (1)
	{
		char *line = NULL, *env[] = {NULL};
		size_t len = 0;
		ssize_t read;
		int status;
		pid_t child_pid;

		printf("#cisfun$ ");
		fflush(stdout);
		read = custom_getline(&line, &len);
		if (read == -1)
		{
			perror("getline");
			continue;
		}
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (strlen(line) == 0)
		{
			free(line);
			continue;
		}
		child_pid = fork();
		if (child_pid == -1)
			perror("fork");
		else if (child_pid == 0)
		{
			parse_and_execute_command(line, env);
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
		free(line);
	}
}
