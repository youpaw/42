//
// Created by Azzak Omega on 10/21/20.
//

#include "jobs.h"
#include "cc_str.h"
#include <stdio.h>

static void print_process(t_process *p)
{
	printf("  %d status=%d completed=%d stopped=%d\n", p->pid, p->status,
		   p->completed, p->stopped);
}

static void	print_job(t_job *job)
{
	t_process	*p;

	printf("%d notified=%d %s\n", job->pgid, job->notified, job->command);
	p = job->first_process;
	while (p)
	{
		print_process(p);
		p = p->next;
	}
}

int 	jobs(const char **av)
{
	t_job	*job;

	putendl("jobs:");
	job = g_first_job;
	while (job)
	{
		print_job(job);
		job = job->next;
	}
	putendl("jobs ended");
	return (0);
}

