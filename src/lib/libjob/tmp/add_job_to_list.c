//
// Created by Azzak Omega on 10/4/20.
//
#include "cc_vec.h"
#include "cc_str.h"
#include "cc_num.h"
#include "jobs.h"

static void	print_add_msg(const t_job *job)
{
	puts("[");
	putnbr(g_jobs.last_job_index);
	puts("] ");
	putnbr(job->pid);
	puts("\n");
}

void		add_job_to_list(size_t pid, size_t gpid)
{
	t_job	new_job;

	if (!g_jobs.data->size)
		g_jobs.last_job_index = 0;
	g_jobs.last_job_index++;
	new_job.id = g_jobs.last_job_index;
	new_job.pid = pid;
	new_job.gpid = gpid;
	vec_push(g_jobs.data, &new_job);
	print_add_msg(&new_job);
}