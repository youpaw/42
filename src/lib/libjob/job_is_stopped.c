//
// Created by youpaw on 10/11/20.
//

#include "jobs.h"

int		job_is_stopped(t_job *j)
{
	t_process *p;

	p = j->first_process;
	while (p)
	{
		if (!p->stopped)
			return (0);
		p = p->next;
	}
	return (1);
}
