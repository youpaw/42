//
// Created by Azzak Omega on 8/23/20.
//

#include "history.h"
#include "cc.h"

int 	hist_push(const char *cmd)
{
	char *new;

	if (cmd && g_hist.size < HIST_SIZE)
	{
		g_hist.commands[g_hist.size++] = strdup(cmd);
		return (0);
	}
	return (-1); //error or overflow
}
