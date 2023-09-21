#include "main.h"
/**
 *main - calls the execution function
 *
 *Return: Success value 0
 */
int main(void)
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
		command(line);
	}
	free(line);
	return (0);
}
