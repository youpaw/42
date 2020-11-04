//
// Created by Azzak Omega on 11/3/20.
//
#include "jobs.h"
#include "cc_str.h"

void	free_job(t_job **job)
{
	t_job	*j;

	if (!job || !(j = *job))
		return ;
	strdel(&(j->command));
	queue_remove(j->index);
	free_processes(j->first_process);
	free(j->first_process);
	free(j);
	j = NULL;
}
