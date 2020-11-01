//
// Created by Azzak Omega on 10/25/20.
//

#include "jobs.h"

static int	last_process_status(t_process *p)
{
	if (!p)
		return (0);
	while (p->next)
		p = p->next;
	return (p->status);
}

int		get_job_status(t_job *job)
{
	t_process	*p;

	if (job_is_completed(job))
	{
		p = job->first_process;
		while (p->next)
			p = p->next;
		return (p->status);
	}
	return (146);
}
