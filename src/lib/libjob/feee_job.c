//
// Created by Azzak Omega on 11/3/20.
//
#include "jobs.h"
#include "cc_str.h"

void	free_job(t_job *j)
{
	strdel(&(j->command));
	del_process(j->first_process);
	queue_remove(j->index);
	free(j->first_process);
	j->first_process = NULL;
}
