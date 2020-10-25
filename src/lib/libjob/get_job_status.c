//
// Created by Azzak Omega on 10/25/20.
//

#include "jobs.h"

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
