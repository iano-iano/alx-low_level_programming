#include "main.h"
/**
 *define_aliases - defines alias from user input
 *@argCount: Number of arguments
 *@args:Argument array
 */
void  define_aliases(int argCount, char **args)
{
	Alias aliases[MAX_ALIAS];
	int i, alias_index, alias_count;
	char *name, *value;

	for (i = 1; i < argCount; i++)
	{
		name = strtok(args[i], "=");
		value = strtok(NULL, "=");

		if (name != NULL && value != NULL)
		{
			/*Check if the alias already exists and update it*/
			alias_index = find_alias_index(name);
			if (alias_index != -1)
			{
				free(aliases[alias_index].value);
				aliases[alias_index].value = strdup(value);
			}
			else
			{
				/*Create a new alias*/
				if (alias_count < MAX_ALIAS)
				{
					aliases[alias_count].name = strdup(name);
					aliases[alias_count].value = strdup(value);
					alias_count++;
				}
				else
				{
					fprintf(stderr, "Alias limit reached. Cannot define more aliases.\n");
				}
			}
		}
		else
		{
			fprintf(stderr, "Invalid alias definition: %s\n", args[i]);
		}
	}
}
