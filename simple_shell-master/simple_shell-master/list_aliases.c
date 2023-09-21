#include "main.h"
/**
 *list_aliases - lists the aliases defined
 *
 */
void list_aliases(void)
{
	Alias aliases[MAX_ALIAS];
	int alias_count = 0, i;

	for (i = 0; i < alias_count; i++)
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
}
