//
// Created by Azzak Omega on 8/23/20.
//

#include "history.h"
#include <stddef.h>

char 	*hist_get_last(void)
{
	if (g_hist.size < 1)
		return (NULL);
	return (g_hist.commands[g_hist.size - 1]);
}
