//
// Created by Azzak Omega on 10/8/20.
//
#include "jobs.h"

/* Mark a stopped job J as being running again.  */

void	mark_job_as_running(t_job *j)
{
	t_process *p;

	for (p = j->first_process; p; p = p->next)
		p->stopped = 0;
	j->notified = 0;
}
