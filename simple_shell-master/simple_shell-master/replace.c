#include "main.h"
/**
 *replace_variables - Handle variables replacement
 *@str: string
 *Return: duplicate value
 */
char *replace_variables(char *str)
{
	char *var, *value;

	var = strstr(str, "$");
	if (var == NULL)
		return (str);
	value = getenv(var + 1);
	if (value == NULL)
		return (str);
	return (strdup(strtok(value, "\n")));
}
