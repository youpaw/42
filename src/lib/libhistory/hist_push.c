//
// Created by Azzak Omega on 8/23/20.
//

#include "history.h"
#include "cc.h"

int 	hist_push(const char *cmd)
{
	char *new;

	if (cmd)
	{
		new = strdup(cmd);
		vec_push(g_hist.commands, &new);
		hist_reset_cur_ind();
		return (0);
	}
	return (-1);
}
