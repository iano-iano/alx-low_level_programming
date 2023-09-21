#include "main.h"
/**
 * command - executes users input
 * @line: the user input
 *
 */
void command(char *line)
{
		char *env[] = {NULL}, *token;
		char cmd[1024];
		int argCount = 0, status;
		char *args[] = {"/bin/ls", NULL};
		pid_t child_pid;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
		}
		else if (child_pid == 0)
		{
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
				exit(1);
			}
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
}
