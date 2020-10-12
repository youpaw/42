//
// Created by Azzak Omega on 10/4/20.
//

#include "cc_vec.h"
#include "jobs.h"
#include <unistd.h>

t_jobs	g_jobs;

void	jobs_init(void)
{
	g_jobs.data = vec_new(10, sizeof(t_job), NULL);
	g_jobs.last_job_index = 0;
	g_jobs.root_pid = getpid();
}