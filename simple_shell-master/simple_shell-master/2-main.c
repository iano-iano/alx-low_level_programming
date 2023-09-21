#include "main.h"
/**
 *print1 - calls the execution function
 *
 */
void print1(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			perror("getline");
			continue;
		}
		if (line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}
		if (strlen(line) == 0)
		{
			continue;
		}
		command2(line);
	}
	free(line);
}
