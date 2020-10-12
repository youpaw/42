//
// Created by Azzak Omega on 10/6/20.
//

#include "jobs.h"

int		is_root_process(void)
{
	if (g_jobs.root_pid == getpid())
		return (1);
	return (0);
}
