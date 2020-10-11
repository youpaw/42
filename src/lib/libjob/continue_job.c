//
// Created by Azzak Omega on 10/8/20.
//

#include "jobs.h"

/* Continue the job J.  */

void	continue_job(t_job *j, int foreground)
{
	mark_job_as_running(j);
	if (foreground)
		put_job_in_foreground(j, 1);
	else
		put_job_in_background(j, 1);
}

