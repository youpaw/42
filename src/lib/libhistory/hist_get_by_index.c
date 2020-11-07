//
// Created by Azzak Omega on 8/23/20.
//

#include "history.h"
#include <stddef.h>

char 	*hist_get_by_index(int index)
{
	char	*str;

	if ( index == 0 || index < -g_hist.commands->size ||
						index > g_hist.commands->size)
		return (NULL);
	if (index > 0)
	{
		vec_get_at(&str, g_hist.commands, index - 1);
		return (str);
	}
	vec_get_at(&str, g_hist.commands, g_hist.commands->size + index);
	return (str);
}
