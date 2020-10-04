//
// Created by Azzak Omega on 10/4/20.
//
#include "jobs.h"
#include "cc_str.h"
#include "cc_num.h"

static void	print_job(const t_job *job)
{
	puts("[");
	putnbr(job->id);
	puts("] ");
	puts("PID: ");
	putnbr(job->pid);
	puts(" GPID: ");
	putnbr(job->gpid);
	puts("\n");
}

void	print_jobs(void)
{
	size_t	i;
	t_job	job;

	i = 0;
	if (!g_jobs.data->size)
		putendl("no jobs"); //debug output
	else
		while (i < g_jobs.data->size)
		{
			vec_get_at(&job, g_jobs.data, i);
			print_job(&job);
			i++;
		}
}