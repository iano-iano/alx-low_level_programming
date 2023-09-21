#include "main.h"
/**
 *handle_cd_command - cd command
 *@args: array of arguments
 */
void handle_cd_command(char *args[])
{
	char *new_d;
	char current_d[1024];

	if (args[1] == NULL || strcmp(args[1], "-") == 0)
		new_d = getenv("OLDPWD");
	else
	{
		new_d = args[1];
		if (new_d == NULL || strcmp(new_d, "-") == 0)
			new_d = getenv("OLDPWD");
		if (new_d != NULL)
		{
			if (getcwd(current_d, sizeof(current_d)) == NULL)
				perror("getcwd");
			else
			{
				setenv("OLDPWD", current_d, 1);
				if (chdir(new_d) == -1)
					perror("chdir");
				else
					setenv("PWD", new_d, 1);
			}
		}
	}
}
