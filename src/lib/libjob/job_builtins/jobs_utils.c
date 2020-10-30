//
// Created by Azzak Omega on 10/30/20.
//
#include "jobs.h"
#include "cc_str.h"
#include "cc_char.h"
#include "cc_num.h"


#include <stdio.h>

/*
** ----------------
*/
static void print_process(t_process *p)
{
	printf("      %d status=%d completed=%d stopped=%d\n", p->pid,
		   p->status, p->completed, p->stopped);
}

void	print_job_info(t_job *job)
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

/*
** ----------------
*/

static void print_job_status(t_job *job)
{
	if (job_is_completed(job))
		puts("Done\t");
	else if (job_is_stopped(job))
		puts("Stopped\t");
	else
		puts("Running\t");

}

static char	get_spec(int index, int cur_index, int last_index)
{
	if (index == cur_index)
		return ('+');
	if (index == last_index)
		return ('-');
	return (' ');
}


void	print_job_formatted(t_job *job, int is_job_builtin)
{
	if (!job)
	{
		putendl("job is NULL");
		return ;
	}
	putchar('[');
	putnbr(job->index);
	putchar(']');
	putchar(get_spec(job->index,
				  queue_get_current(is_job_builtin),
				  queue_get_last(is_job_builtin)));
	putchar(' ');
	print_job_status(job);
	puts("PID: ");
	putnbr(job->pgid);
	puts("\t");
	puts(job->command);
	puts("\n");
	print_job_info(job);
}

