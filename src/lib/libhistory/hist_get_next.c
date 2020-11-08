//
// Created by Azzak Omega on 8/23/20.
//

#include "history.h"
#include <stddef.h>

char 	*hist_get_next(void)
{
	char	*str;

	if (g_hist.cur_ind == g_hist.commands->size - 1)
		g_hist.cur_ind++;
	if (g_hist.cur_ind == g_hist.commands->size)
		return (NULL);
	vec_get_at(&str, g_hist.commands, ++g_hist.cur_ind);
	return (str);
}
