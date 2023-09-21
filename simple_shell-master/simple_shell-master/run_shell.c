#include "main.h"
/**
 * run_shell - simple shell
 *
 */
void run_shell(void)
{
	while (1)
	{
		char *line = NULL;
		size_t len = 0;
		ssize_t read;
		int status;
		pid_t child_pid;

		printf("#cisfun$ ");
		fflush(stdout);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			perror("getline");
			free(line);
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
			execute_command14(line);
			exit(EXIT_FAILURE);
		}
		else
			waitpid(child_pid, &status, 0);
		free(line);
	}
}
