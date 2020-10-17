//
// Created by Azzak Omega on 10/17/20.
//

#include "cc_str.h"
#include "jobs.h"
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

int 	bg(const char **av)
{
	/*
	size_t		index;

	index = g_jobs.last_job_index;
	if (av[1])
		index = atoi(av[1]);
	if (remove_job_by_index(index))
		putendl("no such job to remove");
	else
	{
		putnbr(index);
		putendl(" job successfully removed");
	}
	 */
	putendl("bg builtin");
	return (0);
}

int 	fg(const char **av)
{
	//add_job_to_list(25, 14);
	putendl("fg builtin");
	return (0);
}
