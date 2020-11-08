//
// Created by Azzak Omega on 11/7/20.
//
#include "jobs.h"
#include "cc_str.h"

void print_job_status_str(t_job *job)
{
	char	*msg;
	if (job_is_completed(job) || job_is_stopped(job))
	{
		msg = get_status_message(get_last_process_status(job->first_process));
		puts(msg);
		strdel(&msg);
	}
	else
		puts("Running\t");
}
