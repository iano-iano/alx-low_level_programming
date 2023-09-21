#include "main.h"
/**
 *find_alias_index - finding alias from mem
 *@name:name of alias
 *Return:-1 if alias not found
 */
int find_alias_index(const char *name)
{
	Alias aliases[MAX_ALIAS];
	int alias_count = 0, i;

	for (i = 0; i < alias_count; i++)
	{
		aliases[i].name = NULL;
		if (strcmp(aliases[i].name, name) == 0)
			return (i);
	}
	return (-1);
}
