//
// Created by Azzak Omega on 10/21/20.
//

#include "jobs.h"


int 	jobs(const char **av)
{
	t_job	*job;

	if ((job = g_first_job))
		while (job->next)
		{
			print_job_formatted(job, 1);
			job = job->next;
		}
	return (0);
}

