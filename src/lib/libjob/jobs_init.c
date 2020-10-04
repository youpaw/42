//
// Created by Azzak Omega on 10/4/20.
//

#include "cc_vec.h"
#include "jobs.h"

t_jobs	g_jobs;

void	jobs_init(void)
{
	g_jobs.data = vec_new(10, sizeof(t_job), NULL);
	g_jobs.index = 0;
}