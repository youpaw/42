//
// Created by youpaw on 10/10/20.
//

#include "jobs.h"
#include "cc_mem.h"

t_job *job_new(void)
{
	t_job *job;

	job = xmalloc(sizeof(t_job));
	job->next = NULL;
	job->command = NULL;
	job->first_process = NULL;
	job->pgid = g_pgid;
	job->notified = 0;
	job->sequence = NULL;
	return (job);
}