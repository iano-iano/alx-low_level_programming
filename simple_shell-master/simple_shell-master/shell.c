#include "main.h"
/**
 *search_path - finds path of file
 *@cmd:command
 *@path:pathfinder
 *Return: NULL
 */
char *search_path(const char *cmd, const char *path)
{
	char *path_copy, *token;
	char path_with_cmd[1024];

	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		snprintf(path_with_cmd, sizeof(path_with_cmd), "%s/%s", token, cmd);
		if (access(path_with_cmd, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(path_with_cmd));
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
