#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * simple - execve function
 * 
 */
void simple(void)
{
	char *av[] = {"/bin/ls",  NULL};

	printf("Before execve\n");
	if (execve(av[0], av, NULL) == -1)
	{
		perror("Error:");
	}
	printf("After execve");
}
