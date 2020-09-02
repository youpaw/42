//
// Created by Azzak Omega on 8/23/20.
//

#include "history.h"
#include <stddef.h>

char 	*hist_get_by_index(int index)
{
	if ( index == 0 || index < -g_hist.size || index > g_hist.size)
		return (NULL);
	if (index > 0)
		return (g_hist.commands[index - 1]);
	return (g_hist.commands[g_hist.size + index]);
}
