//
// Created by Azzak Omega on 10/21/20.
//

#include "jobs.h"
#include "cc_str.h"
#include "cc_num.h"
#include <stdio.h>

static void	print_job_formatted(const t_job *job, char spec)
{
	puts("[");
	putnbr(job->index);
	puts("] ");
	putchar(spec);
	puts("  PID: ");
	putnbr(job->pgid);
	puts("\t\t\t");
	puts(job->command);
	puts("\n");
}

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

static char	get_spec(int index, int cur_index, int last_index)
{
	if (index == cur_index)
		return ('+');
	if (index == last_index)
		return ('-');
	return (' ');
}

int 	jobs(const char **av)
{
	t_job	*job;
	int		cur_index;
	int		last_index;

	putendl("jobs:");
	cur_index = queue_get_current();
	last_index = queue_get_last();
	job = g_first_job;
	while (job)
	{
		print_job_formatted(job, get_spec(job->index, cur_index, last_index));
		job = job->next;
	}
	putendl("jobs ended");
	queue_print();
	return (0);
}

