//
// Created by Azzak Omega on 10/8/20.
//
#include "jobs.h"

void	mark_job_as_running(t_job *j)
{
	t_process *p;

	p = j->first_process;
	while (p)
	{
		p->stopped = 0;
		p = p->next;
	}
	j->notified = 0;
}
