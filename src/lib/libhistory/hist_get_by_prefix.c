//
// Created by Azzak Omega on 8/23/20.
//

#include "history.h"
#include "cc.h"

char 	*hist_get_by_prefix(const char *prefix)
{
	int i;
	size_t len;

	if (prefix)
	{
		len = strlen(prefix);
		i = g_hist.size;
		while (--i >= 0)
			if (strncmp(prefix, g_hist.commands[i], len) == 0)
				return (g_hist.commands[i]);
	}
	return (NULL);
}
