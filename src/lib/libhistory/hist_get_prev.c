//
// Created by Azzak Omega on 8/23/20.
//

#include "history.h"
#include <stddef.h>

char 	*hist_get_prev(void)
{
	if (g_hist.cur_ind == 0)
		return (NULL);
	return (g_hist.commands[--g_hist.cur_ind]);
}
