//
// Created by Azzak Omega on 10/8/20.
//

#include "jobs.h"
#include "cc_str.h"
#include <stdlib.h>


/* Notify the user about stopped or terminated jobs.
   Delete terminated jobs from the active job list.  */

void	do_job_notification(void)
{
	t_job *j, *jlast, *jnext;

	/* Update status information for child processes.  */
	update_status();
	jlast = NULL;
	for (j = g_first_job; j; j = jnext)
	{
		jnext = j->next;
		/* If all processes have completed, tell the user the job has
		   completed and delete it from the list of active jobs.  */
		if (job_is_completed(j))
		{
			//format_job_info(j, "completed");
            print_job_formatted(j, 0, JPM_DEFAULT);
			//print_job_info(j);
			if (jlast)
				jlast->next = jnext;
			else
				g_first_job = jnext;
			free_job(&j);
		}
			/* Notify the user about stopped jobs,
			   marking them so that we won’t do this more than once.  */
		else if (job_is_stopped(j) && !j->notified)
		{
			//format_job_info(j, "stopped");
            print_job_formatted(j, 0, JPM_DEFAULT);
			//print_job_info(j);
			j->notified = 1;
			jlast = j;
		}
			/* Don’t say anything about jobs that are still running.  */
		else
			jlast = j;
	}
}