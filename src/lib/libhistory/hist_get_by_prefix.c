//
// Created by Azzak Omega on 8/23/20.
//

#include "history.h"
#include "cc.h"

char	*hist_get_by_prefix(const char *prefix)
{
	int		i;
	size_t	len;
	char	*str;

	if (prefix)
	{
		len = strlen(prefix);
		i = g_hist.commands->size;
		while (--i >= 0)
		{
			vec_get_at(&str, g_hist.commands, i);
			if (strncmp(prefix, str, len) == 0)
				return (str);
		}
	}
	return (NULL);
}
