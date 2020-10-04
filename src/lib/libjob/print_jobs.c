//
// Created by Azzak Omega on 10/4/20.
//
#include "jobs.h"
#include "cc_str.h"
#include "cc_num.h"

void	print_job(t_job job)
{
	puts("PID: ");
	putnbr(job.job_pid);
	puts(" GPID: ");
	putnbr(job.group_pid);
	puts(" status: ");
	putnbr(job.status);
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
			print_job(job);
			i++;
		}
}